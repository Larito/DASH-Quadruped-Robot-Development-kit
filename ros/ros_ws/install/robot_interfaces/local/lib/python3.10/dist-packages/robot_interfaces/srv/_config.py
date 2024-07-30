# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robot_interfaces:srv/Config.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Config_Request(type):
    """Metaclass of message 'Config_Request'."""

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
                'robot_interfaces.srv.Config_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__config__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__config__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__config__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__config__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__config__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Config_Request(metaclass=Metaclass_Config_Request):
    """Message class 'Config_Request'."""

    __slots__ = [
        '_full_name',
        '_age',
        '_blood_type',
        '_medical_notes',
        '_allergies',
        '_weight',
        '_height',
        '_primary_language',
        '_password',
        '_requesting',
    ]

    _fields_and_field_types = {
        'full_name': 'string',
        'age': 'string',
        'blood_type': 'string',
        'medical_notes': 'string',
        'allergies': 'string',
        'weight': 'string',
        'height': 'string',
        'primary_language': 'string',
        'password': 'string',
        'requesting': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.full_name = kwargs.get('full_name', str())
        self.age = kwargs.get('age', str())
        self.blood_type = kwargs.get('blood_type', str())
        self.medical_notes = kwargs.get('medical_notes', str())
        self.allergies = kwargs.get('allergies', str())
        self.weight = kwargs.get('weight', str())
        self.height = kwargs.get('height', str())
        self.primary_language = kwargs.get('primary_language', str())
        self.password = kwargs.get('password', str())
        self.requesting = kwargs.get('requesting', bool())

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
        if self.full_name != other.full_name:
            return False
        if self.age != other.age:
            return False
        if self.blood_type != other.blood_type:
            return False
        if self.medical_notes != other.medical_notes:
            return False
        if self.allergies != other.allergies:
            return False
        if self.weight != other.weight:
            return False
        if self.height != other.height:
            return False
        if self.primary_language != other.primary_language:
            return False
        if self.password != other.password:
            return False
        if self.requesting != other.requesting:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def full_name(self):
        """Message field 'full_name'."""
        return self._full_name

    @full_name.setter
    def full_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'full_name' field must be of type 'str'"
        self._full_name = value

    @builtins.property
    def age(self):
        """Message field 'age'."""
        return self._age

    @age.setter
    def age(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'age' field must be of type 'str'"
        self._age = value

    @builtins.property
    def blood_type(self):
        """Message field 'blood_type'."""
        return self._blood_type

    @blood_type.setter
    def blood_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'blood_type' field must be of type 'str'"
        self._blood_type = value

    @builtins.property
    def medical_notes(self):
        """Message field 'medical_notes'."""
        return self._medical_notes

    @medical_notes.setter
    def medical_notes(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'medical_notes' field must be of type 'str'"
        self._medical_notes = value

    @builtins.property
    def allergies(self):
        """Message field 'allergies'."""
        return self._allergies

    @allergies.setter
    def allergies(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'allergies' field must be of type 'str'"
        self._allergies = value

    @builtins.property
    def weight(self):
        """Message field 'weight'."""
        return self._weight

    @weight.setter
    def weight(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'weight' field must be of type 'str'"
        self._weight = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'height' field must be of type 'str'"
        self._height = value

    @builtins.property
    def primary_language(self):
        """Message field 'primary_language'."""
        return self._primary_language

    @primary_language.setter
    def primary_language(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'primary_language' field must be of type 'str'"
        self._primary_language = value

    @builtins.property
    def password(self):
        """Message field 'password'."""
        return self._password

    @password.setter
    def password(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'password' field must be of type 'str'"
        self._password = value

    @builtins.property
    def requesting(self):
        """Message field 'requesting'."""
        return self._requesting

    @requesting.setter
    def requesting(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'requesting' field must be of type 'bool'"
        self._requesting = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Config_Response(type):
    """Metaclass of message 'Config_Response'."""

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
                'robot_interfaces.srv.Config_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__config__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__config__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__config__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__config__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__config__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Config_Response(metaclass=Metaclass_Config_Response):
    """Message class 'Config_Response'."""

    __slots__ = [
        '_full_name',
        '_age',
        '_blood_type',
        '_medical_notes',
        '_allergies',
        '_weight',
        '_height',
        '_primary_language',
        '_password',
    ]

    _fields_and_field_types = {
        'full_name': 'string',
        'age': 'string',
        'blood_type': 'string',
        'medical_notes': 'string',
        'allergies': 'string',
        'weight': 'string',
        'height': 'string',
        'primary_language': 'string',
        'password': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.full_name = kwargs.get('full_name', str())
        self.age = kwargs.get('age', str())
        self.blood_type = kwargs.get('blood_type', str())
        self.medical_notes = kwargs.get('medical_notes', str())
        self.allergies = kwargs.get('allergies', str())
        self.weight = kwargs.get('weight', str())
        self.height = kwargs.get('height', str())
        self.primary_language = kwargs.get('primary_language', str())
        self.password = kwargs.get('password', str())

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
        if self.full_name != other.full_name:
            return False
        if self.age != other.age:
            return False
        if self.blood_type != other.blood_type:
            return False
        if self.medical_notes != other.medical_notes:
            return False
        if self.allergies != other.allergies:
            return False
        if self.weight != other.weight:
            return False
        if self.height != other.height:
            return False
        if self.primary_language != other.primary_language:
            return False
        if self.password != other.password:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def full_name(self):
        """Message field 'full_name'."""
        return self._full_name

    @full_name.setter
    def full_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'full_name' field must be of type 'str'"
        self._full_name = value

    @builtins.property
    def age(self):
        """Message field 'age'."""
        return self._age

    @age.setter
    def age(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'age' field must be of type 'str'"
        self._age = value

    @builtins.property
    def blood_type(self):
        """Message field 'blood_type'."""
        return self._blood_type

    @blood_type.setter
    def blood_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'blood_type' field must be of type 'str'"
        self._blood_type = value

    @builtins.property
    def medical_notes(self):
        """Message field 'medical_notes'."""
        return self._medical_notes

    @medical_notes.setter
    def medical_notes(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'medical_notes' field must be of type 'str'"
        self._medical_notes = value

    @builtins.property
    def allergies(self):
        """Message field 'allergies'."""
        return self._allergies

    @allergies.setter
    def allergies(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'allergies' field must be of type 'str'"
        self._allergies = value

    @builtins.property
    def weight(self):
        """Message field 'weight'."""
        return self._weight

    @weight.setter
    def weight(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'weight' field must be of type 'str'"
        self._weight = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'height' field must be of type 'str'"
        self._height = value

    @builtins.property
    def primary_language(self):
        """Message field 'primary_language'."""
        return self._primary_language

    @primary_language.setter
    def primary_language(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'primary_language' field must be of type 'str'"
        self._primary_language = value

    @builtins.property
    def password(self):
        """Message field 'password'."""
        return self._password

    @password.setter
    def password(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'password' field must be of type 'str'"
        self._password = value


class Metaclass_Config(type):
    """Metaclass of service 'Config'."""

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
                'robot_interfaces.srv.Config')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__config

            from robot_interfaces.srv import _config
            if _config.Metaclass_Config_Request._TYPE_SUPPORT is None:
                _config.Metaclass_Config_Request.__import_type_support__()
            if _config.Metaclass_Config_Response._TYPE_SUPPORT is None:
                _config.Metaclass_Config_Response.__import_type_support__()


class Config(metaclass=Metaclass_Config):
    from robot_interfaces.srv._config import Config_Request as Request
    from robot_interfaces.srv._config import Config_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
