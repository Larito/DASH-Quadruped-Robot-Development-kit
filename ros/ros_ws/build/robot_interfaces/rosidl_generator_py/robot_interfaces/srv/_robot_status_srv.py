# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/RobotStatusSrv.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotStatusSrv_Request(type):
    """Metaclass of message 'RobotStatusSrv_Request'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.RobotStatusSrv_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_status_srv__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_status_srv__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_status_srv__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_status_srv__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_status_srv__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStatusSrv_Request(metaclass=Metaclass_RobotStatusSrv_Request):
    """Message class 'RobotStatusSrv_Request'."""

    __slots__ = [
        '_formality',
    ]

    _fields_and_field_types = {
        'formality': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.formality = kwargs.get('formality', bool())

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
        if self.formality != other.formality:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def formality(self):
        """Message field 'formality'."""
        return self._formality

    @formality.setter
    def formality(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'formality' field must be of type 'bool'"
        self._formality = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotStatusSrv_Response(type):
    """Metaclass of message 'RobotStatusSrv_Response'."""

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
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.RobotStatusSrv_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_status_srv__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_status_srv__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_status_srv__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_status_srv__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_status_srv__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotStatusSrv_Response(metaclass=Metaclass_RobotStatusSrv_Response):
    """Message class 'RobotStatusSrv_Response'."""

    __slots__ = [
        '_battery_level',
        '_current_mode',
    ]

    _fields_and_field_types = {
        'battery_level': 'int32',
        'current_mode': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.battery_level = kwargs.get('battery_level', int())
        self.current_mode = kwargs.get('current_mode', int())

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
        if self.battery_level != other.battery_level:
            return False
        if self.current_mode != other.current_mode:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def battery_level(self):
        """Message field 'battery_level'."""
        return self._battery_level

    @battery_level.setter
    def battery_level(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'battery_level' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'battery_level' field must be an integer in [-2147483648, 2147483647]"
        self._battery_level = value

    @builtins.property
    def current_mode(self):
        """Message field 'current_mode'."""
        return self._current_mode

    @current_mode.setter
    def current_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_mode' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'current_mode' field must be an integer in [-2147483648, 2147483647]"
        self._current_mode = value


class Metaclass_RobotStatusSrv(type):
    """Metaclass of service 'RobotStatusSrv'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robot_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robot_interfaces.srv.RobotStatusSrv')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__robot_status_srv

            from robot_interfaces.srv import _robot_status_srv
            if _robot_status_srv.Metaclass_RobotStatusSrv_Request._TYPE_SUPPORT is None:
                _robot_status_srv.Metaclass_RobotStatusSrv_Request.__import_type_support__()
            if _robot_status_srv.Metaclass_RobotStatusSrv_Response._TYPE_SUPPORT is None:
                _robot_status_srv.Metaclass_RobotStatusSrv_Response.__import_type_support__()


class RobotStatusSrv(metaclass=Metaclass_RobotStatusSrv):
    from robot_interfaces.srv._robot_status_srv import RobotStatusSrv_Request as Request
    from robot_interfaces.srv._robot_status_srv import RobotStatusSrv_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
