// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robot_interfaces:srv/RobotStatusSrv.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/srv/detail/robot_status_srv__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robot_interfaces/srv/detail/robot_status_srv__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robot_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_serialize(
  const robot_interfaces::srv::RobotStatusSrv_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: formality
  cdr << (ros_message.formality ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robot_interfaces::srv::RobotStatusSrv_Request & ros_message)
{
  // Member: formality
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.formality = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
get_serialized_size(
  const robot_interfaces::srv::RobotStatusSrv_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: formality
  {
    size_t item_size = sizeof(ros_message.formality);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
max_serialized_size_RobotStatusSrv_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: formality
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces::srv::RobotStatusSrv_Request;
    is_plain =
      (
      offsetof(DataType, formality) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotStatusSrv_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robot_interfaces::srv::RobotStatusSrv_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotStatusSrv_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_interfaces::srv::RobotStatusSrv_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotStatusSrv_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_interfaces::srv::RobotStatusSrv_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotStatusSrv_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotStatusSrv_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotStatusSrv_Request__callbacks = {
  "robot_interfaces::srv",
  "RobotStatusSrv_Request",
  _RobotStatusSrv_Request__cdr_serialize,
  _RobotStatusSrv_Request__cdr_deserialize,
  _RobotStatusSrv_Request__get_serialized_size,
  _RobotStatusSrv_Request__max_serialized_size
};

static rosidl_message_type_support_t _RobotStatusSrv_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotStatusSrv_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::srv::RobotStatusSrv_Request>()
{
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, srv, RobotStatusSrv_Request)() {
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robot_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_serialize(
  const robot_interfaces::srv::RobotStatusSrv_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: battery_level
  cdr << ros_message.battery_level;
  // Member: current_mode
  cdr << ros_message.current_mode;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robot_interfaces::srv::RobotStatusSrv_Response & ros_message)
{
  // Member: battery_level
  cdr >> ros_message.battery_level;

  // Member: current_mode
  cdr >> ros_message.current_mode;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
get_serialized_size(
  const robot_interfaces::srv::RobotStatusSrv_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: battery_level
  {
    size_t item_size = sizeof(ros_message.battery_level);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current_mode
  {
    size_t item_size = sizeof(ros_message.current_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robot_interfaces
max_serialized_size_RobotStatusSrv_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: battery_level
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces::srv::RobotStatusSrv_Response;
    is_plain =
      (
      offsetof(DataType, current_mode) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotStatusSrv_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robot_interfaces::srv::RobotStatusSrv_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotStatusSrv_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robot_interfaces::srv::RobotStatusSrv_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotStatusSrv_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robot_interfaces::srv::RobotStatusSrv_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotStatusSrv_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotStatusSrv_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotStatusSrv_Response__callbacks = {
  "robot_interfaces::srv",
  "RobotStatusSrv_Response",
  _RobotStatusSrv_Response__cdr_serialize,
  _RobotStatusSrv_Response__cdr_deserialize,
  _RobotStatusSrv_Response__get_serialized_size,
  _RobotStatusSrv_Response__max_serialized_size
};

static rosidl_message_type_support_t _RobotStatusSrv_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotStatusSrv_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_interfaces::srv::RobotStatusSrv_Response>()
{
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, srv, RobotStatusSrv_Response)() {
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace robot_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _RobotStatusSrv__callbacks = {
  "robot_interfaces::srv",
  "RobotStatusSrv",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, srv, RobotStatusSrv_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, srv, RobotStatusSrv_Response)(),
};

static rosidl_service_type_support_t _RobotStatusSrv__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotStatusSrv__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robot_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<robot_interfaces::srv::RobotStatusSrv>()
{
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robot_interfaces, srv, RobotStatusSrv)() {
  return &robot_interfaces::srv::typesupport_fastrtps_cpp::_RobotStatusSrv__handle;
}

#ifdef __cplusplus
}
#endif
