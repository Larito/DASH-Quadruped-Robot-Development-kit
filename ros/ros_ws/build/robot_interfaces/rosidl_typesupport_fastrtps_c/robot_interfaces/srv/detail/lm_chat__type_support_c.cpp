// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:srv/LMChat.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/srv/detail/lm_chat__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/srv/detail/lm_chat__struct.h"
#include "robot_interfaces/srv/detail/lm_chat__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // in_msg
#include "rosidl_runtime_c/string_functions.h"  // in_msg

// forward declare type support functions


using _LMChat_Request__ros_msg_type = robot_interfaces__srv__LMChat_Request;

static bool _LMChat_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LMChat_Request__ros_msg_type * ros_message = static_cast<const _LMChat_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: in_msg
  {
    const rosidl_runtime_c__String * str = &ros_message->in_msg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _LMChat_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LMChat_Request__ros_msg_type * ros_message = static_cast<_LMChat_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: in_msg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->in_msg.data) {
      rosidl_runtime_c__String__init(&ros_message->in_msg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->in_msg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'in_msg'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__LMChat_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LMChat_Request__ros_msg_type * ros_message = static_cast<const _LMChat_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name in_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->in_msg.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _LMChat_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__LMChat_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__LMChat_Request(
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

  // member: in_msg
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__srv__LMChat_Request;
    is_plain =
      (
      offsetof(DataType, in_msg) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LMChat_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__LMChat_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LMChat_Request = {
  "robot_interfaces::srv",
  "LMChat_Request",
  _LMChat_Request__cdr_serialize,
  _LMChat_Request__cdr_deserialize,
  _LMChat_Request__get_serialized_size,
  _LMChat_Request__max_serialized_size
};

static rosidl_message_type_support_t _LMChat_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LMChat_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, LMChat_Request)() {
  return &_LMChat_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "robot_interfaces/srv/detail/lm_chat__struct.h"
// already included above
// #include "robot_interfaces/srv/detail/lm_chat__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // out_msg
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // out_msg

// forward declare type support functions


using _LMChat_Response__ros_msg_type = robot_interfaces__srv__LMChat_Response;

static bool _LMChat_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _LMChat_Response__ros_msg_type * ros_message = static_cast<const _LMChat_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: out_msg
  {
    const rosidl_runtime_c__String * str = &ros_message->out_msg;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _LMChat_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _LMChat_Response__ros_msg_type * ros_message = static_cast<_LMChat_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: out_msg
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->out_msg.data) {
      rosidl_runtime_c__String__init(&ros_message->out_msg);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->out_msg,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'out_msg'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__LMChat_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _LMChat_Response__ros_msg_type * ros_message = static_cast<const _LMChat_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name out_msg
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->out_msg.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _LMChat_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__LMChat_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__LMChat_Response(
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

  // member: out_msg
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robot_interfaces__srv__LMChat_Response;
    is_plain =
      (
      offsetof(DataType, out_msg) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _LMChat_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__LMChat_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_LMChat_Response = {
  "robot_interfaces::srv",
  "LMChat_Response",
  _LMChat_Response__cdr_serialize,
  _LMChat_Response__cdr_deserialize,
  _LMChat_Response__get_serialized_size,
  _LMChat_Response__max_serialized_size
};

static rosidl_message_type_support_t _LMChat_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_LMChat_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, LMChat_Response)() {
  return &_LMChat_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/srv/lm_chat.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t LMChat__callbacks = {
  "robot_interfaces::srv",
  "LMChat",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, LMChat_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, LMChat_Response)(),
};

static rosidl_service_type_support_t LMChat__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &LMChat__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, LMChat)() {
  return &LMChat__handle;
}

#if defined(__cplusplus)
}
#endif
