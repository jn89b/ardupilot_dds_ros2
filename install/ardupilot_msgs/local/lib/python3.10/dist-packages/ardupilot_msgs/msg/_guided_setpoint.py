# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ardupilot_msgs:msg/GuidedSetpoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GuidedSetpoint(type):
    """Metaclass of message 'GuidedSetpoint'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ardupilot_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ardupilot_msgs.msg.GuidedSetpoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__guided_setpoint
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__guided_setpoint
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__guided_setpoint
            cls._TYPE_SUPPORT = module.type_support_msg__msg__guided_setpoint
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__guided_setpoint

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GuidedSetpoint(metaclass=Metaclass_GuidedSetpoint):
    """Message class 'GuidedSetpoint'."""

    __slots__ = [
        '_set_heading',
        '_heading_type',
        '_heading_deg',
        '_heading_accel_limit_mss',
        '_set_airspeed',
        '_airspeed_mps',
        '_airspeed_accel_mps2',
        '_set_altitude',
        '_altitude_frame',
        '_altitude_m',
        '_climb_rate_mps',
    ]

    _fields_and_field_types = {
        'set_heading': 'boolean',
        'heading_type': 'uint8',
        'heading_deg': 'float',
        'heading_accel_limit_mss': 'float',
        'set_airspeed': 'boolean',
        'airspeed_mps': 'float',
        'airspeed_accel_mps2': 'float',
        'set_altitude': 'boolean',
        'altitude_frame': 'uint8',
        'altitude_m': 'float',
        'climb_rate_mps': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.set_heading = kwargs.get('set_heading', bool())
        self.heading_type = kwargs.get('heading_type', int())
        self.heading_deg = kwargs.get('heading_deg', float())
        self.heading_accel_limit_mss = kwargs.get('heading_accel_limit_mss', float())
        self.set_airspeed = kwargs.get('set_airspeed', bool())
        self.airspeed_mps = kwargs.get('airspeed_mps', float())
        self.airspeed_accel_mps2 = kwargs.get('airspeed_accel_mps2', float())
        self.set_altitude = kwargs.get('set_altitude', bool())
        self.altitude_frame = kwargs.get('altitude_frame', int())
        self.altitude_m = kwargs.get('altitude_m', float())
        self.climb_rate_mps = kwargs.get('climb_rate_mps', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.set_heading != other.set_heading:
            return False
        if self.heading_type != other.heading_type:
            return False
        if self.heading_deg != other.heading_deg:
            return False
        if self.heading_accel_limit_mss != other.heading_accel_limit_mss:
            return False
        if self.set_airspeed != other.set_airspeed:
            return False
        if self.airspeed_mps != other.airspeed_mps:
            return False
        if self.airspeed_accel_mps2 != other.airspeed_accel_mps2:
            return False
        if self.set_altitude != other.set_altitude:
            return False
        if self.altitude_frame != other.altitude_frame:
            return False
        if self.altitude_m != other.altitude_m:
            return False
        if self.climb_rate_mps != other.climb_rate_mps:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def set_heading(self):
        """Message field 'set_heading'."""
        return self._set_heading

    @set_heading.setter
    def set_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_heading' field must be of type 'bool'"
        self._set_heading = value

    @builtins.property
    def heading_type(self):
        """Message field 'heading_type'."""
        return self._heading_type

    @heading_type.setter
    def heading_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'heading_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'heading_type' field must be an unsigned integer in [0, 255]"
        self._heading_type = value

    @builtins.property
    def heading_deg(self):
        """Message field 'heading_deg'."""
        return self._heading_deg

    @heading_deg.setter
    def heading_deg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_deg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading_deg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading_deg = value

    @builtins.property
    def heading_accel_limit_mss(self):
        """Message field 'heading_accel_limit_mss'."""
        return self._heading_accel_limit_mss

    @heading_accel_limit_mss.setter
    def heading_accel_limit_mss(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_accel_limit_mss' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading_accel_limit_mss' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading_accel_limit_mss = value

    @builtins.property
    def set_airspeed(self):
        """Message field 'set_airspeed'."""
        return self._set_airspeed

    @set_airspeed.setter
    def set_airspeed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_airspeed' field must be of type 'bool'"
        self._set_airspeed = value

    @builtins.property
    def airspeed_mps(self):
        """Message field 'airspeed_mps'."""
        return self._airspeed_mps

    @airspeed_mps.setter
    def airspeed_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'airspeed_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'airspeed_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._airspeed_mps = value

    @builtins.property
    def airspeed_accel_mps2(self):
        """Message field 'airspeed_accel_mps2'."""
        return self._airspeed_accel_mps2

    @airspeed_accel_mps2.setter
    def airspeed_accel_mps2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'airspeed_accel_mps2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'airspeed_accel_mps2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._airspeed_accel_mps2 = value

    @builtins.property
    def set_altitude(self):
        """Message field 'set_altitude'."""
        return self._set_altitude

    @set_altitude.setter
    def set_altitude(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'set_altitude' field must be of type 'bool'"
        self._set_altitude = value

    @builtins.property
    def altitude_frame(self):
        """Message field 'altitude_frame'."""
        return self._altitude_frame

    @altitude_frame.setter
    def altitude_frame(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'altitude_frame' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'altitude_frame' field must be an unsigned integer in [0, 255]"
        self._altitude_frame = value

    @builtins.property
    def altitude_m(self):
        """Message field 'altitude_m'."""
        return self._altitude_m

    @altitude_m.setter
    def altitude_m(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'altitude_m' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'altitude_m' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._altitude_m = value

    @builtins.property
    def climb_rate_mps(self):
        """Message field 'climb_rate_mps'."""
        return self._climb_rate_mps

    @climb_rate_mps.setter
    def climb_rate_mps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'climb_rate_mps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'climb_rate_mps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._climb_rate_mps = value
