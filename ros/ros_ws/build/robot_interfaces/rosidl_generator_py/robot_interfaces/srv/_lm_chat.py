# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/LMChat.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_LMChat_Request(type):
    """Metaclass of message 'LMChat_Request'."""

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
                'robot_interfaces.srv.LMChat_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__lm_chat__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__lm_chat__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__lm_chat__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__lm_chat__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__lm_chat__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LMChat_Request(metaclass=Metaclass_LMChat_Request):
    """Message class 'LMChat_Request'."""

    __slots__ = [
        '_in_msg',
    ]

    _fields_and_field_types = {
        'in_msg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.in_msg = kwargs.get('in_msg', str())

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
        if self.in_msg != other.in_msg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def in_msg(self):
        """Message field 'in_msg'."""
        return self._in_msg

    @in_msg.setter
    def in_msg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'in_msg' field must be of type 'str'"
        self._in_msg = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_LMChat_Response(type):
    """Metaclass of message 'LMChat_Response'."""

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
                'robot_interfaces.srv.LMChat_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__lm_chat__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__lm_chat__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__lm_chat__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__lm_chat__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__lm_chat__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class LMChat_Response(metaclass=Metaclass_LMChat_Response):
    """Message class 'LMChat_Response'."""

    __slots__ = [
        '_out_msg',
    ]

    _fields_and_field_types = {
        'out_msg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.out_msg = kwargs.get('out_msg', str())

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
        if self.out_msg != other.out_msg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def out_msg(self):
        """Message field 'out_msg'."""
        return self._out_msg

    @out_msg.setter
    def out_msg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'out_msg' field must be of type 'str'"
        self._out_msg = value


class Metaclass_LMChat(type):
    """Metaclass of service 'LMChat'."""

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
                'robot_interfaces.srv.LMChat')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__lm_chat

            from robot_interfaces.srv import _lm_chat
            if _lm_chat.Metaclass_LMChat_Request._TYPE_SUPPORT is None:
                _lm_chat.Metaclass_LMChat_Request.__import_type_support__()
            if _lm_chat.Metaclass_LMChat_Response._TYPE_SUPPORT is None:
                _lm_chat.Metaclass_LMChat_Response.__import_type_support__()


class LMChat(metaclass=Metaclass_LMChat):
    from robot_interfaces.srv._lm_chat import LMChat_Request as Request
    from robot_interfaces.srv._lm_chat import LMChat_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
