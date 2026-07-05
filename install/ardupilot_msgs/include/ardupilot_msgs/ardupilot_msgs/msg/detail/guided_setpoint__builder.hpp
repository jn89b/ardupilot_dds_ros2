// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ardupilot_msgs:msg/GuidedSetpoint.idl
// generated code does not contain a copyright notice

#ifndef ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__BUILDER_HPP_
#define ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ardupilot_msgs/msg/detail/guided_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ardupilot_msgs
{

namespace msg
{

namespace builder
{

class Init_GuidedSetpoint_climb_rate_mps
{
public:
  explicit Init_GuidedSetpoint_climb_rate_mps(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  ::ardupilot_msgs::msg::GuidedSetpoint climb_rate_mps(::ardupilot_msgs::msg::GuidedSetpoint::_climb_rate_mps_type arg)
  {
    msg_.climb_rate_mps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_altitude_m
{
public:
  explicit Init_GuidedSetpoint_altitude_m(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_climb_rate_mps altitude_m(::ardupilot_msgs::msg::GuidedSetpoint::_altitude_m_type arg)
  {
    msg_.altitude_m = std::move(arg);
    return Init_GuidedSetpoint_climb_rate_mps(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_altitude_frame
{
public:
  explicit Init_GuidedSetpoint_altitude_frame(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_altitude_m altitude_frame(::ardupilot_msgs::msg::GuidedSetpoint::_altitude_frame_type arg)
  {
    msg_.altitude_frame = std::move(arg);
    return Init_GuidedSetpoint_altitude_m(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_set_altitude
{
public:
  explicit Init_GuidedSetpoint_set_altitude(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_altitude_frame set_altitude(::ardupilot_msgs::msg::GuidedSetpoint::_set_altitude_type arg)
  {
    msg_.set_altitude = std::move(arg);
    return Init_GuidedSetpoint_altitude_frame(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_airspeed_accel_mps2
{
public:
  explicit Init_GuidedSetpoint_airspeed_accel_mps2(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_set_altitude airspeed_accel_mps2(::ardupilot_msgs::msg::GuidedSetpoint::_airspeed_accel_mps2_type arg)
  {
    msg_.airspeed_accel_mps2 = std::move(arg);
    return Init_GuidedSetpoint_set_altitude(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_airspeed_mps
{
public:
  explicit Init_GuidedSetpoint_airspeed_mps(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_airspeed_accel_mps2 airspeed_mps(::ardupilot_msgs::msg::GuidedSetpoint::_airspeed_mps_type arg)
  {
    msg_.airspeed_mps = std::move(arg);
    return Init_GuidedSetpoint_airspeed_accel_mps2(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_set_airspeed
{
public:
  explicit Init_GuidedSetpoint_set_airspeed(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_airspeed_mps set_airspeed(::ardupilot_msgs::msg::GuidedSetpoint::_set_airspeed_type arg)
  {
    msg_.set_airspeed = std::move(arg);
    return Init_GuidedSetpoint_airspeed_mps(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_heading_accel_limit_mss
{
public:
  explicit Init_GuidedSetpoint_heading_accel_limit_mss(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_set_airspeed heading_accel_limit_mss(::ardupilot_msgs::msg::GuidedSetpoint::_heading_accel_limit_mss_type arg)
  {
    msg_.heading_accel_limit_mss = std::move(arg);
    return Init_GuidedSetpoint_set_airspeed(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_heading_deg
{
public:
  explicit Init_GuidedSetpoint_heading_deg(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_heading_accel_limit_mss heading_deg(::ardupilot_msgs::msg::GuidedSetpoint::_heading_deg_type arg)
  {
    msg_.heading_deg = std::move(arg);
    return Init_GuidedSetpoint_heading_accel_limit_mss(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_heading_type
{
public:
  explicit Init_GuidedSetpoint_heading_type(::ardupilot_msgs::msg::GuidedSetpoint & msg)
  : msg_(msg)
  {}
  Init_GuidedSetpoint_heading_deg heading_type(::ardupilot_msgs::msg::GuidedSetpoint::_heading_type_type arg)
  {
    msg_.heading_type = std::move(arg);
    return Init_GuidedSetpoint_heading_deg(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

class Init_GuidedSetpoint_set_heading
{
public:
  Init_GuidedSetpoint_set_heading()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GuidedSetpoint_heading_type set_heading(::ardupilot_msgs::msg::GuidedSetpoint::_set_heading_type arg)
  {
    msg_.set_heading = std::move(arg);
    return Init_GuidedSetpoint_heading_type(msg_);
  }

private:
  ::ardupilot_msgs::msg::GuidedSetpoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ardupilot_msgs::msg::GuidedSetpoint>()
{
  return ardupilot_msgs::msg::builder::Init_GuidedSetpoint_set_heading();
}

}  // namespace ardupilot_msgs

#endif  // ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__BUILDER_HPP_
