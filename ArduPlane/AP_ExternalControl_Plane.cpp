/*
  external control library for plane
 */


#include "AP_ExternalControl_Plane.h"
#if AP_EXTERNAL_CONTROL_ENABLED

#include "Plane.h"
#include <GCS_MAVLink/GCS.h>

/*
  Sets the target global position for a loiter point.
*/
bool AP_ExternalControl_Plane::set_global_position(const Location& loc)
{

    // set_target_location already checks if plane is ready for external control.
    // It doesn't check if flying or armed, just that it's in guided mode.
    return plane.set_target_location(loc);
}

/*
  Sets the target airspeed.
*/
bool AP_ExternalControl_Plane::set_airspeed(const float airspeed)
{
#if AP_PLANE_OFFBOARD_GUIDED_SLEW_ENABLED
    // The command is only valid in guided mode.
    if (plane.control_mode != &plane.mode_guided) {
        return false;
    }

    // Assume the user wanted maximum acceleration.
    const float acc_instant = 0.0;
    return plane.mode_guided.handle_change_airspeed(airspeed, acc_instant);
#else 
  return false;
#endif
}

  bool AP_ExternalControl_Plane::set_guided_airspeed(const float airspeed, const float acceleration)
  {
  #if AP_PLANE_OFFBOARD_GUIDED_SLEW_ENABLED
    if (plane.control_mode != &plane.mode_guided) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided airspeed ignored: not in GUIDED");
      return false;
    }

    if (!plane.mode_guided.handle_change_airspeed(airspeed, acceleration)) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING,
              "DDS guided airspeed failed: v=%.2f accel=%.2f",
              double(airspeed),
              double(acceleration));
      return false;
    }

    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "DDS guided airspeed accepted: v=%.2f", double(airspeed));
    return true;
  #else
    return false;
  #endif
  }

  bool AP_ExternalControl_Plane::set_guided_altitude(const float altitude, const uint8_t frame, const float climb_rate)
  {
  #if AP_PLANE_OFFBOARD_GUIDED_SLEW_ENABLED
    if (plane.control_mode != &plane.mode_guided) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided altitude ignored: not in GUIDED");
      return false;
    }

    // Match MAV_CMD_GUIDED_CHANGE_ALTITUDE default and unsafe value handling.
    if (is_equal(altitude, -1.0f) || is_equal(altitude, 0.0f)) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided altitude invalid: alt=%.2f", double(altitude));
      return false;
    }

    Location::AltFrame new_target_alt_frame;
    switch (frame) {
    case MAV_FRAME_GLOBAL_INT:
      new_target_alt_frame = Location::AltFrame::ABSOLUTE;
      break;
    case MAV_FRAME_GLOBAL_RELATIVE_ALT_INT:
      new_target_alt_frame = Location::AltFrame::ABOVE_HOME;
      break;
    case MAV_FRAME_GLOBAL_TERRAIN_ALT_INT:
      new_target_alt_frame = Location::AltFrame::ABOVE_TERRAIN;
      break;
    default:
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided altitude invalid frame: %u", unsigned(frame));
      return false;
    }

    // Keep the frame in guided state to preserve MAVLink logging semantics.
    plane.guided_state.target_mav_frame = frame;

    const int32_t new_target_alt_cm = altitude * 100;
    plane.guided_state.target_location.set_alt_cm(new_target_alt_cm, new_target_alt_frame);
    plane.guided_state.target_alt_time_ms = AP_HAL::millis();

    // climb_rate follows MAVLink param3 semantics, 0 means maximum rate.
    if (is_zero(climb_rate)) {
      plane.guided_state.target_alt_rate = 1000.0f;
    } else {
      plane.guided_state.target_alt_rate = fabsf(climb_rate);
    }

    GCS_SEND_TEXT(MAV_SEVERITY_INFO,
            "DDS guided altitude accepted: frame=%u alt=%.2f rate=%.2f",
            unsigned(frame),
            double(altitude),
            double(climb_rate));

    return true;
  #else
    return false;
  #endif
  }

  bool AP_ExternalControl_Plane::set_guided_heading(const uint8_t heading_type, const float heading, const float heading_accel_limit)
  {
  #if AP_PLANE_OFFBOARD_GUIDED_SLEW_ENABLED
    if (plane.control_mode != &plane.mode_guided) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided heading ignored: not in GUIDED");
      return false;
    }

    if (heading < 0.0f || heading >= 360.0f) {
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided heading invalid: hdg=%.2f", double(heading));
      return false;
    }

    switch (heading_type) {
    case HEADING_TYPE_COURSE_OVER_GROUND:
      plane.guided_state.target_heading_type = GUIDED_HEADING_COG;
      plane.prev_WP_loc = plane.current_loc;
      break;
    case HEADING_TYPE_HEADING:
      plane.guided_state.target_heading_type = GUIDED_HEADING_HEADING;
      break;
    case HEADING_TYPE_DEFAULT:
      plane.guided_state.target_heading_type = GUIDED_HEADING_NONE;
      GCS_SEND_TEXT(MAV_SEVERITY_INFO, "DDS guided heading cleared");
      return true;
    default:
      GCS_SEND_TEXT(MAV_SEVERITY_WARNING, "DDS guided heading invalid type: %u", unsigned(heading_type));
      return false;
    }

    plane.g2.guidedHeading.reset_I();
    plane.guided_state.target_heading = radians(wrap_180(heading));
    plane.guided_state.target_heading_accel_limit = MAX(heading_accel_limit, 0.05f);
    plane.guided_state.target_heading_time_ms = AP_HAL::millis();

    GCS_SEND_TEXT(MAV_SEVERITY_INFO,
            "DDS guided heading accepted: type=%u hdg=%.2f",
            unsigned(heading_type),
            double(heading));

    return true;
  #else
    return false;
  #endif
  }

#endif // AP_EXTERNAL_CONTROL_ENABLED
