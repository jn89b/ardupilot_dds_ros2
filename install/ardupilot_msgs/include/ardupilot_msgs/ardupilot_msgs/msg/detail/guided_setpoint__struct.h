// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ardupilot_msgs:msg/GuidedSetpoint.idl
// generated code does not contain a copyright notice

#ifndef ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_H_
#define ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GuidedSetpoint in the package ardupilot_msgs.
/**
  * This topic publishes Plane guided setpoints in a single command.
  * Use set_heading, set_airspeed, and set_altitude to control which
  * fields are applied on the vehicle.
 */
typedef struct ardupilot_msgs__msg__GuidedSetpoint
{
  /// Heading control.
  /// heading_type:
  ///   0 = clear heading tracking
  ///   1 = course over ground
  ///   2 = maintain vehicle heading
  bool set_heading;
  uint8_t heading_type;
  float heading_deg;
  float heading_accel_limit_mss;
  /// Airspeed control.
  bool set_airspeed;
  float airspeed_mps;
  float airspeed_accel_mps2;
  /// Altitude control.
  bool set_altitude;
  uint8_t altitude_frame;
  float altitude_m;
  float climb_rate_mps;
} ardupilot_msgs__msg__GuidedSetpoint;

// Struct for a sequence of ardupilot_msgs__msg__GuidedSetpoint.
typedef struct ardupilot_msgs__msg__GuidedSetpoint__Sequence
{
  ardupilot_msgs__msg__GuidedSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ardupilot_msgs__msg__GuidedSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_H_
