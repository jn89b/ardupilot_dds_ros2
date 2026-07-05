// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ardupilot_msgs:msg/GuidedSetpoint.idl
// generated code does not contain a copyright notice
#include "ardupilot_msgs/msg/detail/guided_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ardupilot_msgs__msg__GuidedSetpoint__init(ardupilot_msgs__msg__GuidedSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // set_heading
  // heading_type
  // heading_deg
  // heading_accel_limit_mss
  // set_airspeed
  // airspeed_mps
  // airspeed_accel_mps2
  // set_altitude
  // altitude_frame
  // altitude_m
  // climb_rate_mps
  return true;
}

void
ardupilot_msgs__msg__GuidedSetpoint__fini(ardupilot_msgs__msg__GuidedSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // set_heading
  // heading_type
  // heading_deg
  // heading_accel_limit_mss
  // set_airspeed
  // airspeed_mps
  // airspeed_accel_mps2
  // set_altitude
  // altitude_frame
  // altitude_m
  // climb_rate_mps
}

bool
ardupilot_msgs__msg__GuidedSetpoint__are_equal(const ardupilot_msgs__msg__GuidedSetpoint * lhs, const ardupilot_msgs__msg__GuidedSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // set_heading
  if (lhs->set_heading != rhs->set_heading) {
    return false;
  }
  // heading_type
  if (lhs->heading_type != rhs->heading_type) {
    return false;
  }
  // heading_deg
  if (lhs->heading_deg != rhs->heading_deg) {
    return false;
  }
  // heading_accel_limit_mss
  if (lhs->heading_accel_limit_mss != rhs->heading_accel_limit_mss) {
    return false;
  }
  // set_airspeed
  if (lhs->set_airspeed != rhs->set_airspeed) {
    return false;
  }
  // airspeed_mps
  if (lhs->airspeed_mps != rhs->airspeed_mps) {
    return false;
  }
  // airspeed_accel_mps2
  if (lhs->airspeed_accel_mps2 != rhs->airspeed_accel_mps2) {
    return false;
  }
  // set_altitude
  if (lhs->set_altitude != rhs->set_altitude) {
    return false;
  }
  // altitude_frame
  if (lhs->altitude_frame != rhs->altitude_frame) {
    return false;
  }
  // altitude_m
  if (lhs->altitude_m != rhs->altitude_m) {
    return false;
  }
  // climb_rate_mps
  if (lhs->climb_rate_mps != rhs->climb_rate_mps) {
    return false;
  }
  return true;
}

bool
ardupilot_msgs__msg__GuidedSetpoint__copy(
  const ardupilot_msgs__msg__GuidedSetpoint * input,
  ardupilot_msgs__msg__GuidedSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // set_heading
  output->set_heading = input->set_heading;
  // heading_type
  output->heading_type = input->heading_type;
  // heading_deg
  output->heading_deg = input->heading_deg;
  // heading_accel_limit_mss
  output->heading_accel_limit_mss = input->heading_accel_limit_mss;
  // set_airspeed
  output->set_airspeed = input->set_airspeed;
  // airspeed_mps
  output->airspeed_mps = input->airspeed_mps;
  // airspeed_accel_mps2
  output->airspeed_accel_mps2 = input->airspeed_accel_mps2;
  // set_altitude
  output->set_altitude = input->set_altitude;
  // altitude_frame
  output->altitude_frame = input->altitude_frame;
  // altitude_m
  output->altitude_m = input->altitude_m;
  // climb_rate_mps
  output->climb_rate_mps = input->climb_rate_mps;
  return true;
}

ardupilot_msgs__msg__GuidedSetpoint *
ardupilot_msgs__msg__GuidedSetpoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__msg__GuidedSetpoint * msg = (ardupilot_msgs__msg__GuidedSetpoint *)allocator.allocate(sizeof(ardupilot_msgs__msg__GuidedSetpoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ardupilot_msgs__msg__GuidedSetpoint));
  bool success = ardupilot_msgs__msg__GuidedSetpoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ardupilot_msgs__msg__GuidedSetpoint__destroy(ardupilot_msgs__msg__GuidedSetpoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ardupilot_msgs__msg__GuidedSetpoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ardupilot_msgs__msg__GuidedSetpoint__Sequence__init(ardupilot_msgs__msg__GuidedSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__msg__GuidedSetpoint * data = NULL;

  if (size) {
    data = (ardupilot_msgs__msg__GuidedSetpoint *)allocator.zero_allocate(size, sizeof(ardupilot_msgs__msg__GuidedSetpoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ardupilot_msgs__msg__GuidedSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ardupilot_msgs__msg__GuidedSetpoint__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ardupilot_msgs__msg__GuidedSetpoint__Sequence__fini(ardupilot_msgs__msg__GuidedSetpoint__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ardupilot_msgs__msg__GuidedSetpoint__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ardupilot_msgs__msg__GuidedSetpoint__Sequence *
ardupilot_msgs__msg__GuidedSetpoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ardupilot_msgs__msg__GuidedSetpoint__Sequence * array = (ardupilot_msgs__msg__GuidedSetpoint__Sequence *)allocator.allocate(sizeof(ardupilot_msgs__msg__GuidedSetpoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ardupilot_msgs__msg__GuidedSetpoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ardupilot_msgs__msg__GuidedSetpoint__Sequence__destroy(ardupilot_msgs__msg__GuidedSetpoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ardupilot_msgs__msg__GuidedSetpoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ardupilot_msgs__msg__GuidedSetpoint__Sequence__are_equal(const ardupilot_msgs__msg__GuidedSetpoint__Sequence * lhs, const ardupilot_msgs__msg__GuidedSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ardupilot_msgs__msg__GuidedSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ardupilot_msgs__msg__GuidedSetpoint__Sequence__copy(
  const ardupilot_msgs__msg__GuidedSetpoint__Sequence * input,
  ardupilot_msgs__msg__GuidedSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ardupilot_msgs__msg__GuidedSetpoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ardupilot_msgs__msg__GuidedSetpoint * data =
      (ardupilot_msgs__msg__GuidedSetpoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ardupilot_msgs__msg__GuidedSetpoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ardupilot_msgs__msg__GuidedSetpoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ardupilot_msgs__msg__GuidedSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
