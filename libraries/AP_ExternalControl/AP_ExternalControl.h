/*
  external control library for MAVLink, DDS and scripting
 */

#pragma once

#include "AP_ExternalControl_config.h"

#if AP_EXTERNAL_CONTROL_ENABLED

#include <AP_Arming/AP_Arming.h>
#include <AP_Common/Location.h>
#include <AP_Math/AP_Math.h>

class AP_ExternalControl
{
public:

    AP_ExternalControl();

    /*
        Sets the target airspeed.
    */
    virtual bool set_airspeed(const float airspeed) WARN_IF_UNUSED {
        return false;
    }

    /*
        Sets the guided target airspeed and acceleration [m/s, m/s^2].
        Acceleration set to 0 means use maximum acceleration.
    */
    virtual bool set_guided_airspeed(const float airspeed, const float acceleration) WARN_IF_UNUSED {
        return false;
    }

    /*
        Sets guided target altitude and vertical rate [m, m/s] with a MAVLink
        compatible coordinate frame.
    */
    virtual bool set_guided_altitude(const float altitude, const uint8_t frame, const float climb_rate) WARN_IF_UNUSED {
        return false;
    }

    /*
        Sets guided heading control with MAVLink compatible heading type.
        heading is in degrees [0, 360).
    */
    virtual bool set_guided_heading(const uint8_t heading_type, const float heading, const float heading_accel_limit) WARN_IF_UNUSED {
        return false;
    }

    /*
      Set linear velocity and yaw rate. Pass NaN for yaw_rate_rads to not control yaw.
      Velocity is in earth frame, NED [m/s].
      Yaw is in earth frame, NED [rad/s].
     */
    virtual bool set_linear_velocity_and_yaw_rate(const Vector3f &linear_velocity_ned_ms, float yaw_rate_rads) WARN_IF_UNUSED {
        return false;
    }

    /*
        Sets the target global position with standard guided mode behavior.
    */
    virtual bool set_global_position(const Location& loc) WARN_IF_UNUSED {
        return false;
    }

    /*
        Arm the vehicle
    */
    virtual bool arm(AP_Arming::Method method, bool do_arming_checks) WARN_IF_UNUSED;

    /*
        Disarm the vehicle
    */
    virtual bool disarm(AP_Arming::Method method, bool do_disarm_checks) WARN_IF_UNUSED;

    static AP_ExternalControl *get_singleton(void) WARN_IF_UNUSED {
        return singleton;
    }
protected:
    ~AP_ExternalControl() {}

private:
    static AP_ExternalControl *singleton;
};


namespace AP
{
AP_ExternalControl *externalcontrol();
};

#endif // AP_EXTERNAL_CONTROL_ENABLED
