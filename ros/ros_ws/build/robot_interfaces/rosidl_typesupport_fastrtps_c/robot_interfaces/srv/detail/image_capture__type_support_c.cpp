// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:srv/ImageCapture.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/srv/detail/image_capture__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/srv/detail/image_capture__struct.h"
#include "robot_interfaces/srv/detail/image_capture__functions.h"
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

#include "rosidl_runtime_c/string.h"  // command
#include "rosidl_runtime_c/string_functions.h"  // command

// forward declare type support functions


using _ImageCapture_Request__ros_msg_type = robot_interfaces__srv__ImageCapture_Request;

static bool _ImageCapture_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageCapture_Request__ros_msg_type * ros_message = static_cast<const _ImageCapture_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    const rosidl_runtime_c__String * str = &ros_message->command;
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

static bool _ImageCapture_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageCapture_Request__ros_msg_type * ros_message = static_cast<_ImageCapture_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->command.data) {
      rosidl_runtime_c__String__init(&ros_message->command);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->command,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'command'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__ImageCapture_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageCapture_Request__ros_msg_type * ros_message = static_cast<const _ImageCapture_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name command
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->command.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _ImageCapture_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__ImageCapture_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__ImageCapture_Request(
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

  // member: command
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
    using DataType = robot_interfaces__srv__ImageCapture_Request;
    is_plain =
      (
      offsetof(DataType, command) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ImageCapture_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__ImageCapture_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ImageCapture_Request = {
  "robot_interfaces::srv",
  "ImageCapture_Request",
  _ImageCapture_Request__cdr_serialize,
  _ImageCapture_Request__cdr_deserialize,
  _ImageCapture_Request__get_serialized_size,
  _ImageCapture_Request__max_serialized_size
};

static rosidl_message_type_support_t _ImageCapture_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageCapture_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, ImageCapture_Request)() {
  return &_ImageCapture_Request__type_support;
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
// #include "robot_interfaces/srv/detail/image_capture__struct.h"
// already included above
// #include "robot_interfaces/srv/detail/image_capture__functions.h"
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
// #include "rosidl_runtime_c/string.h"  // image_base64
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // image_base64

// forward declare type support functions


using _ImageCapture_Response__ros_msg_type = robot_interfaces__srv__ImageCapture_Response;

static bool _ImageCapture_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageCapture_Response__ros_msg_type * ros_message = static_cast<const _ImageCapture_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image_base64
  {
    const rosidl_runtime_c__String * str = &ros_message->image_base64;
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

static bool _ImageCapture_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageCapture_Response__ros_msg_type * ros_message = static_cast<_ImageCapture_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image_base64
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->image_base64.data) {
      rosidl_runtime_c__String__init(&ros_message->image_base64);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->image_base64,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'image_base64'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__ImageCapture_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageCapture_Response__ros_msg_type * ros_message = static_cast<const _ImageCapture_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name image_base64
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->image_base64.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _ImageCapture_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__ImageCapture_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__ImageCapture_Response(
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

  // member: image_base64
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
    using DataType = robot_interfaces__srv__ImageCapture_Response;
    is_plain =
      (
      offsetof(DataType, image_base64) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ImageCapture_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__ImageCapture_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ImageCapture_Response = {
  "robot_interfaces::srv",
  "ImageCapture_Response",
  _ImageCapture_Response__cdr_serialize,
  _ImageCapture_Response__cdr_deserialize,
  _ImageCapture_Response__get_serialized_size,
  _ImageCapture_Response__max_serialized_size
};

static rosidl_message_type_support_t _ImageCapture_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageCapture_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, ImageCapture_Response)() {
  return &_ImageCapture_Response__type_support;
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
#include "robot_interfaces/srv/image_capture.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ImageCapture__callbacks = {
  "robot_interfaces::srv",
  "ImageCapture",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, ImageCapture_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, ImageCapture_Response)(),
};

static rosidl_service_type_support_t ImageCapture__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ImageCapture__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, ImageCapture)() {
  return &ImageCapture__handle;
}

#if defined(__cplusplus)
}
#endif
