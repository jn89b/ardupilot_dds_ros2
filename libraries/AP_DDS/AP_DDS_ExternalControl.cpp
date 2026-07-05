#include "AP_DDS_config.h"

#if AP_DDS_ENABLED

#include "AP_DDS_ExternalControl.h"
#include "AP_DDS_Frames.h"
#include <AP_AHRS/AP_AHRS.h>

#include <GCS_MAVLink/GCS.h>

#include <AP_ExternalControl/AP_ExternalControl.h>

bool AP_DDS_External_Control::handle_global_position_control(ardupilot_msgs_msg_GlobalPosition& cmd_pos)
{
    auto *external_control = AP::externalcontrol();
    if (external_control == nullptr) {
        return false;
    }

    if (strcmp(cmd_pos.header.frame_id, MAP_FRAME) == 0) {
        // Narrow the altitude
        const int32_t alt_cm  = static_cast<int32_t>(cmd_pos.altitude * 100);

        Location::AltFrame alt_frame;
        if (!convert_alt_frame(cmd_pos.coordinate_frame, alt_frame)) {
            return false;
        }

        constexpr uint32_t MASK_POS_IGNORE =
            GlobalPosition::IGNORE_LATITUDE |
            GlobalPosition::IGNORE_LONGITUDE |
            GlobalPosition::IGNORE_ALTITUDE;

        if (!(cmd_pos.type_mask & MASK_POS_IGNORE)) {
            Location loc(cmd_pos.latitude * 1E7, cmd_pos.longitude * 1E7, alt_cm, alt_frame);
            if (!external_control->set_global_position(loc)) {
                return false; // Don't try sending other commands if this fails
            }
        }

        // TODO add velocity and accel handling

        return true;
    }

    return false;
}

bool AP_DDS_External_Control::handle_velocity_control(geometry_msgs_msg_TwistStamped& cmd_vel)
{
    auto *external_control = AP::externalcontrol();
    if (external_control == nullptr) {
        return false;
    }

    if (strcmp(cmd_vel.header.frame_id, BASE_LINK_FRAME_ID) == 0) {
        // Convert commands from body frame (x-forward, y-left, z-up) to NED.
        Vector3f linear_velocity;
        Vector3f linear_velocity_base_link {
            float(cmd_vel.twist.linear.x),
            float(cmd_vel.twist.linear.y),
            float(-cmd_vel.twist.linear.z) };

        if (isnan(linear_velocity_base_link.y) && isnan(linear_velocity_base_link.z)) {
            // Assume it's an airspeed command so ignore the angular data.
            // While MAV_CMD_GUIDED_CHANGE_SPEED supports commands of ground speed and airspeed,
            // ROS users likely care more about airspeed control for a low level velocity control interface like this.
            return external_control->set_airspeed(linear_velocity_base_link.x);
        }

        const float yaw_rate = -cmd_vel.twist.angular.z;

        auto &ahrs = AP::ahrs();
        linear_velocity = ahrs.body_to_earth(linear_velocity_base_link);
        return external_control->set_linear_velocity_and_yaw_rate(linear_velocity, yaw_rate);
    }

    else if (strcmp(cmd_vel.header.frame_id, MAP_FRAME) == 0) {
        // Convert commands from ENU to NED frame
        Vector3f linear_velocity {
            float(cmd_vel.twist.linear.y),
            float(cmd_vel.twist.linear.x),
            float(-cmd_vel.twist.linear.z) };
        const float yaw_rate = -cmd_vel.twist.angular.z;
        return external_control->set_linear_velocity_and_yaw_rate(linear_velocity, yaw_rate);
    }

    return false;
}

bool AP_DDS_External_Control::handle_guided_setpoint(ardupilot_msgs_msg_GuidedSetpoint &guided_setpoint)
{
    auto *external_control = AP::externalcontrol();
    if (external_control == nullptr) {
        GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided setpoint rejected: external control unavailable");
        return false;
    }

    bool requested_any = false;

    GCS_SEND_TEXT(MAV_SEVERITY_INFO,
                  "DDS guided setpoint rx h:%u a:%u z:%u",
                  unsigned(guided_setpoint.set_heading),
                  unsigned(guided_setpoint.set_airspeed),
                  unsigned(guided_setpoint.set_altitude));

    // These fields align with MAV_CMD_GUIDED_CHANGE_SPEED semantics in SI units.
    if (guided_setpoint.set_airspeed) {
        requested_any = true;

        if (isnan(guided_setpoint.airspeed_mps) || isnan(guided_setpoint.airspeed_accel_mps2)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided airspeed rejected: NaN value");
            return false;
        }

        if (!external_control->set_guided_airspeed(guided_setpoint.airspeed_mps, guided_setpoint.airspeed_accel_mps2)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING,
                          "DDS guided airspeed rejected: v=%.2f accel=%.2f",
                          double(guided_setpoint.airspeed_mps),
                          double(guided_setpoint.airspeed_accel_mps2));
            return false;
        }
    }

    // heading_deg and heading_accel_limit_mss follow MAV_CMD_GUIDED_CHANGE_HEADING units.
    if (guided_setpoint.set_heading) {
        requested_any = true;

        if (isnan(guided_setpoint.heading_deg) || isnan(guided_setpoint.heading_accel_limit_mss)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided heading rejected: NaN value");
            return false;
        }

        if (!external_control->set_guided_heading(guided_setpoint.heading_type,
                                                   guided_setpoint.heading_deg,
                                                   guided_setpoint.heading_accel_limit_mss)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING,
                          "DDS guided heading rejected: type=%u hdg=%.2f accel=%.2f",
                          unsigned(guided_setpoint.heading_type),
                          double(guided_setpoint.heading_deg),
                          double(guided_setpoint.heading_accel_limit_mss));
            return false;
        }
    }

    // altitude_m and climb_rate_mps follow MAV_CMD_GUIDED_CHANGE_ALTITUDE units.
    if (guided_setpoint.set_altitude) {
        requested_any = true;

        if (isnan(guided_setpoint.altitude_m) || isnan(guided_setpoint.climb_rate_mps)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided altitude rejected: NaN value");
            return false;
        }

        if (!external_control->set_guided_altitude(guided_setpoint.altitude_m,
                                                    guided_setpoint.altitude_frame,
                                                    guided_setpoint.climb_rate_mps)) {
            GCS_SEND_TEXT(MAV_SEVERITY_WARNING,
                          "DDS guided altitude rejected: frame=%u alt=%.2f rate=%.2f",
                          unsigned(guided_setpoint.altitude_frame),
                          double(guided_setpoint.altitude_m),
                          double(guided_setpoint.climb_rate_mps));
            return false;
        }
    }

    if (!requested_any) {
        GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided setpoint rejected: no fields requested");
    }

    return requested_any;
}

bool AP_DDS_External_Control::arm(AP_Arming::Method method, bool do_arming_checks)
{
    auto *external_control = AP::externalcontrol();
    if (external_control == nullptr) {
        return false;
    }

    return external_control->arm(method, do_arming_checks);
}

bool AP_DDS_External_Control::disarm(AP_Arming::Method method, bool do_disarm_checks)
{
    auto *external_control = AP::externalcontrol();
    if (external_control == nullptr) {
        return false;
    }

    return external_control->disarm(method, do_disarm_checks);
}

bool AP_DDS_External_Control::convert_alt_frame(const uint8_t frame_in,  Location::AltFrame& frame_out)
{

    // Specified in ROS REP-147; only some are supported.
    switch (frame_in) {
    case 5: // FRAME_GLOBAL_INT
        frame_out = Location::AltFrame::ABSOLUTE;
        break;
    case 6: // FRAME_GLOBAL_REL_ALT
        frame_out = Location::AltFrame::ABOVE_HOME;
        break;
    case 11: // FRAME_GLOBAL_TERRAIN_ALT
        frame_out = Location::AltFrame::ABOVE_TERRAIN;
        break;
    default:
        return false;
    }
    return true;
}


#endif // AP_DDS_ENABLED