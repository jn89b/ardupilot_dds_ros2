// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ardupilot_msgs:msg/GuidedSetpoint.idl
// generated code does not contain a copyright notice

#ifndef ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_HPP_
#define ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ardupilot_msgs__msg__GuidedSetpoint __attribute__((deprecated))
#else
# define DEPRECATED__ardupilot_msgs__msg__GuidedSetpoint __declspec(deprecated)
#endif

namespace ardupilot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GuidedSetpoint_
{
  using Type = GuidedSetpoint_<ContainerAllocator>;

  explicit GuidedSetpoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_heading = false;
      this->heading_type = 0;
      this->heading_deg = 0.0f;
      this->heading_accel_limit_mss = 0.0f;
      this->set_airspeed = false;
      this->airspeed_mps = 0.0f;
      this->airspeed_accel_mps2 = 0.0f;
      this->set_altitude = false;
      this->altitude_frame = 0;
      this->altitude_m = 0.0f;
      this->climb_rate_mps = 0.0f;
    }
  }

  explicit GuidedSetpoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_heading = false;
      this->heading_type = 0;
      this->heading_deg = 0.0f;
      this->heading_accel_limit_mss = 0.0f;
      this->set_airspeed = false;
      this->airspeed_mps = 0.0f;
      this->airspeed_accel_mps2 = 0.0f;
      this->set_altitude = false;
      this->altitude_frame = 0;
      this->altitude_m = 0.0f;
      this->climb_rate_mps = 0.0f;
    }
  }

  // field types and members
  using _set_heading_type =
    bool;
  _set_heading_type set_heading;
  using _heading_type_type =
    uint8_t;
  _heading_type_type heading_type;
  using _heading_deg_type =
    float;
  _heading_deg_type heading_deg;
  using _heading_accel_limit_mss_type =
    float;
  _heading_accel_limit_mss_type heading_accel_limit_mss;
  using _set_airspeed_type =
    bool;
  _set_airspeed_type set_airspeed;
  using _airspeed_mps_type =
    float;
  _airspeed_mps_type airspeed_mps;
  using _airspeed_accel_mps2_type =
    float;
  _airspeed_accel_mps2_type airspeed_accel_mps2;
  using _set_altitude_type =
    bool;
  _set_altitude_type set_altitude;
  using _altitude_frame_type =
    uint8_t;
  _altitude_frame_type altitude_frame;
  using _altitude_m_type =
    float;
  _altitude_m_type altitude_m;
  using _climb_rate_mps_type =
    float;
  _climb_rate_mps_type climb_rate_mps;

  // setters for named parameter idiom
  Type & set__set_heading(
    const bool & _arg)
  {
    this->set_heading = _arg;
    return *this;
  }
  Type & set__heading_type(
    const uint8_t & _arg)
  {
    this->heading_type = _arg;
    return *this;
  }
  Type & set__heading_deg(
    const float & _arg)
  {
    this->heading_deg = _arg;
    return *this;
  }
  Type & set__heading_accel_limit_mss(
    const float & _arg)
  {
    this->heading_accel_limit_mss = _arg;
    return *this;
  }
  Type & set__set_airspeed(
    const bool & _arg)
  {
    this->set_airspeed = _arg;
    return *this;
  }
  Type & set__airspeed_mps(
    const float & _arg)
  {
    this->airspeed_mps = _arg;
    return *this;
  }
  Type & set__airspeed_accel_mps2(
    const float & _arg)
  {
    this->airspeed_accel_mps2 = _arg;
    return *this;
  }
  Type & set__set_altitude(
    const bool & _arg)
  {
    this->set_altitude = _arg;
    return *this;
  }
  Type & set__altitude_frame(
    const uint8_t & _arg)
  {
    this->altitude_frame = _arg;
    return *this;
  }
  Type & set__altitude_m(
    const float & _arg)
  {
    this->altitude_m = _arg;
    return *this;
  }
  Type & set__climb_rate_mps(
    const float & _arg)
  {
    this->climb_rate_mps = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ardupilot_msgs__msg__GuidedSetpoint
    std::shared_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ardupilot_msgs__msg__GuidedSetpoint
    std::shared_ptr<ardupilot_msgs::msg::GuidedSetpoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GuidedSetpoint_ & other) const
  {
    if (this->set_heading != other.set_heading) {
      return false;
    }
    if (this->heading_type != other.heading_type) {
      return false;
    }
    if (this->heading_deg != other.heading_deg) {
      return false;
    }
    if (this->heading_accel_limit_mss != other.heading_accel_limit_mss) {
      return false;
    }
    if (this->set_airspeed != other.set_airspeed) {
      return false;
    }
    if (this->airspeed_mps != other.airspeed_mps) {
      return false;
    }
    if (this->airspeed_accel_mps2 != other.airspeed_accel_mps2) {
      return false;
    }
    if (this->set_altitude != other.set_altitude) {
      return false;
    }
    if (this->altitude_frame != other.altitude_frame) {
      return false;
    }
    if (this->altitude_m != other.altitude_m) {
      return false;
    }
    if (this->climb_rate_mps != other.climb_rate_mps) {
      return false;
    }
    return true;
  }
  bool operator!=(const GuidedSetpoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GuidedSetpoint_

// alias to use template instance with default allocator
using GuidedSetpoint =
  ardupilot_msgs::msg::GuidedSetpoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ardupilot_msgs

#endif  // ARDUPILOT_MSGS__MSG__DETAIL__GUIDED_SETPOINT__STRUCT_HPP_
