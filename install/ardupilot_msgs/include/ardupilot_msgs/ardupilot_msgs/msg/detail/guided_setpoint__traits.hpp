// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ardupilot_msgs:msg/GuidedSetpoint.idl
// generated code does not contain a copyright notice

#ifndef ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__TRAITS_HPP_
#define ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ardupilot_msgs/msg/detail/guided_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ardupilot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GuidedSetpoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: set_heading
  {
    out << "set_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.set_heading, out);
    out << ", ";
  }

  // member: heading_type
  {
    out << "heading_type: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_type, out);
    out << ", ";
  }

  // member: heading_deg
  {
    out << "heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_deg, out);
    out << ", ";
  }

  // member: heading_accel_limit_mss
  {
    out << "heading_accel_limit_mss: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_accel_limit_mss, out);
    out << ", ";
  }

  // member: set_airspeed
  {
    out << "set_airspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.set_airspeed, out);
    out << ", ";
  }

  // member: airspeed_mps
  {
    out << "airspeed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_mps, out);
    out << ", ";
  }

  // member: airspeed_accel_mps2
  {
    out << "airspeed_accel_mps2: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_accel_mps2, out);
    out << ", ";
  }

  // member: set_altitude
  {
    out << "set_altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.set_altitude, out);
    out << ", ";
  }

  // member: altitude_frame
  {
    out << "altitude_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_frame, out);
    out << ", ";
  }

  // member: altitude_m
  {
    out << "altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_m, out);
    out << ", ";
  }

  // member: climb_rate_mps
  {
    out << "climb_rate_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.climb_rate_mps, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GuidedSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: set_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.set_heading, out);
    out << "\n";
  }

  // member: heading_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_type: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_type, out);
    out << "\n";
  }

  // member: heading_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_deg, out);
    out << "\n";
  }

  // member: heading_accel_limit_mss
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_accel_limit_mss: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_accel_limit_mss, out);
    out << "\n";
  }

  // member: set_airspeed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_airspeed: ";
    rosidl_generator_traits::value_to_yaml(msg.set_airspeed, out);
    out << "\n";
  }

  // member: airspeed_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "airspeed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_mps, out);
    out << "\n";
  }

  // member: airspeed_accel_mps2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "airspeed_accel_mps2: ";
    rosidl_generator_traits::value_to_yaml(msg.airspeed_accel_mps2, out);
    out << "\n";
  }

  // member: set_altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.set_altitude, out);
    out << "\n";
  }

  // member: altitude_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_frame: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_frame, out);
    out << "\n";
  }

  // member: altitude_m
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude_m: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude_m, out);
    out << "\n";
  }

  // member: climb_rate_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "climb_rate_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.climb_rate_mps, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GuidedSetpoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ardupilot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ardupilot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ardupilot_msgs::msg::GuidedSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  ardupilot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ardupilot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const ardupilot_msgs::msg::GuidedSetpoint & msg)
{
  return ardupilot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ardupilot_msgs::msg::GuidedSetpoint>()
{
  return "ardupilot_msgs::msg::GuidedSetpoint";
}

template<>
inline const char * name<ardupilot_msgs::msg::GuidedSetpoint>()
{
  return "ardupilot_msgs/msg/GuidedSetpoint";
}

template<>
struct has_fixed_size<ardupilot_msgs::msg::GuidedSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ardupilot_msgs::msg::GuidedSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ardupilot_msgs::msg::GuidedSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__TRAITS_HPP_
