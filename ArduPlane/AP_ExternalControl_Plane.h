
/*
  external control library for plane
 */
#pragma once

#include <AP_ExternalControl/AP_ExternalControl.h>

#if AP_EXTERNAL_CONTROL_ENABLED

#include <AP_Common/Location.h>

class AP_ExternalControl_Plane : public AP_ExternalControl {
public:
    /*
        Sets the target global position for a loiter point.
    */
    bool set_global_position(const Location& loc) override WARN_IF_UNUSED;

    /*
        Sets the target airspeed.
    */
    bool set_airspeed(const float airspeed) override WARN_IF_UNUSED;

    // Guided slew-compatible control paths using MAVLink semantics.
    bool set_guided_airspeed(const float airspeed, const float acceleration) override WARN_IF_UNUSED;
    bool set_guided_altitude(const float altitude, const uint8_t frame, const float climb_rate) override WARN_IF_UNUSED;
    bool set_guided_heading(const uint8_t heading_type, const float heading, const float heading_accel_limit) override WARN_IF_UNUSED;

};

#endif // AP_EXTERNAL_CONTROL_ENABLED
