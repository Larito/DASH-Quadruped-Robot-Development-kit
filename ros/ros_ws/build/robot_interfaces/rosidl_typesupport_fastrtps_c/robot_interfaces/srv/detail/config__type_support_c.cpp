// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice
#include "robot_interfaces/srv/detail/config__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robot_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robot_interfaces/srv/detail/config__struct.h"
#include "robot_interfaces/srv/detail/config__functions.h"
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

#include "rosidl_runtime_c/string.h"  // age, allergies, blood_type, full_name, height, medical_notes, password, primary_language, weight
#include "rosidl_runtime_c/string_functions.h"  // age, allergies, blood_type, full_name, height, medical_notes, password, primary_language, weight

// forward declare type support functions


using _Config_Request__ros_msg_type = robot_interfaces__srv__Config_Request;

static bool _Config_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Config_Request__ros_msg_type * ros_message = static_cast<const _Config_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: full_name
  {
    const rosidl_runtime_c__String * str = &ros_message->full_name;
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

  // Field name: age
  {
    const rosidl_runtime_c__String * str = &ros_message->age;
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

  // Field name: blood_type
  {
    const rosidl_runtime_c__String * str = &ros_message->blood_type;
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

  // Field name: medical_notes
  {
    const rosidl_runtime_c__String * str = &ros_message->medical_notes;
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

  // Field name: allergies
  {
    const rosidl_runtime_c__String * str = &ros_message->allergies;
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

  // Field name: weight
  {
    const rosidl_runtime_c__String * str = &ros_message->weight;
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

  // Field name: height
  {
    const rosidl_runtime_c__String * str = &ros_message->height;
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

  // Field name: primary_language
  {
    const rosidl_runtime_c__String * str = &ros_message->primary_language;
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

  // Field name: password
  {
    const rosidl_runtime_c__String * str = &ros_message->password;
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

  // Field name: requesting
  {
    cdr << (ros_message->requesting ? true : false);
  }

  return true;
}

static bool _Config_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Config_Request__ros_msg_type * ros_message = static_cast<_Config_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: full_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->full_name.data) {
      rosidl_runtime_c__String__init(&ros_message->full_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->full_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'full_name'\n");
      return false;
    }
  }

  // Field name: age
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->age.data) {
      rosidl_runtime_c__String__init(&ros_message->age);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->age,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'age'\n");
      return false;
    }
  }

  // Field name: blood_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->blood_type.data) {
      rosidl_runtime_c__String__init(&ros_message->blood_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->blood_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'blood_type'\n");
      return false;
    }
  }

  // Field name: medical_notes
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->medical_notes.data) {
      rosidl_runtime_c__String__init(&ros_message->medical_notes);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->medical_notes,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'medical_notes'\n");
      return false;
    }
  }

  // Field name: allergies
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->allergies.data) {
      rosidl_runtime_c__String__init(&ros_message->allergies);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->allergies,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'allergies'\n");
      return false;
    }
  }

  // Field name: weight
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->weight.data) {
      rosidl_runtime_c__String__init(&ros_message->weight);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->weight,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'weight'\n");
      return false;
    }
  }

  // Field name: height
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->height.data) {
      rosidl_runtime_c__String__init(&ros_message->height);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->height,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'height'\n");
      return false;
    }
  }

  // Field name: primary_language
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->primary_language.data) {
      rosidl_runtime_c__String__init(&ros_message->primary_language);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->primary_language,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'primary_language'\n");
      return false;
    }
  }

  // Field name: password
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->password.data) {
      rosidl_runtime_c__String__init(&ros_message->password);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->password,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'password'\n");
      return false;
    }
  }

  // Field name: requesting
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->requesting = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__Config_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Config_Request__ros_msg_type * ros_message = static_cast<const _Config_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name full_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->full_name.size + 1);
  // field.name age
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->age.size + 1);
  // field.name blood_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->blood_type.size + 1);
  // field.name medical_notes
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->medical_notes.size + 1);
  // field.name allergies
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->allergies.size + 1);
  // field.name weight
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->weight.size + 1);
  // field.name height
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->height.size + 1);
  // field.name primary_language
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->primary_language.size + 1);
  // field.name password
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->password.size + 1);
  // field.name requesting
  {
    size_t item_size = sizeof(ros_message->requesting);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Config_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__Config_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__Config_Request(
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

  // member: full_name
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
  // member: age
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
  // member: blood_type
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
  // member: medical_notes
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
  // member: allergies
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
  // member: weight
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
  // member: height
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
  // member: primary_language
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
  // member: password
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
  // member: requesting
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
    using DataType = robot_interfaces__srv__Config_Request;
    is_plain =
      (
      offsetof(DataType, requesting) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Config_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__Config_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Config_Request = {
  "robot_interfaces::srv",
  "Config_Request",
  _Config_Request__cdr_serialize,
  _Config_Request__cdr_deserialize,
  _Config_Request__get_serialized_size,
  _Config_Request__max_serialized_size
};

static rosidl_message_type_support_t _Config_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Config_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, Config_Request)() {
  return &_Config_Request__type_support;
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
// #include "robot_interfaces/srv/detail/config__struct.h"
// already included above
// #include "robot_interfaces/srv/detail/config__functions.h"
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
// #include "rosidl_runtime_c/string.h"  // age, allergies, blood_type, full_name, height, medical_notes, password, primary_language, weight
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // age, allergies, blood_type, full_name, height, medical_notes, password, primary_language, weight

// forward declare type support functions


using _Config_Response__ros_msg_type = robot_interfaces__srv__Config_Response;

static bool _Config_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Config_Response__ros_msg_type * ros_message = static_cast<const _Config_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: full_name
  {
    const rosidl_runtime_c__String * str = &ros_message->full_name;
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

  // Field name: age
  {
    const rosidl_runtime_c__String * str = &ros_message->age;
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

  // Field name: blood_type
  {
    const rosidl_runtime_c__String * str = &ros_message->blood_type;
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

  // Field name: medical_notes
  {
    const rosidl_runtime_c__String * str = &ros_message->medical_notes;
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

  // Field name: allergies
  {
    const rosidl_runtime_c__String * str = &ros_message->allergies;
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

  // Field name: weight
  {
    const rosidl_runtime_c__String * str = &ros_message->weight;
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

  // Field name: height
  {
    const rosidl_runtime_c__String * str = &ros_message->height;
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

  // Field name: primary_language
  {
    const rosidl_runtime_c__String * str = &ros_message->primary_language;
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

  // Field name: password
  {
    const rosidl_runtime_c__String * str = &ros_message->password;
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

static bool _Config_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Config_Response__ros_msg_type * ros_message = static_cast<_Config_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: full_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->full_name.data) {
      rosidl_runtime_c__String__init(&ros_message->full_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->full_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'full_name'\n");
      return false;
    }
  }

  // Field name: age
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->age.data) {
      rosidl_runtime_c__String__init(&ros_message->age);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->age,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'age'\n");
      return false;
    }
  }

  // Field name: blood_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->blood_type.data) {
      rosidl_runtime_c__String__init(&ros_message->blood_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->blood_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'blood_type'\n");
      return false;
    }
  }

  // Field name: medical_notes
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->medical_notes.data) {
      rosidl_runtime_c__String__init(&ros_message->medical_notes);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->medical_notes,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'medical_notes'\n");
      return false;
    }
  }

  // Field name: allergies
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->allergies.data) {
      rosidl_runtime_c__String__init(&ros_message->allergies);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->allergies,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'allergies'\n");
      return false;
    }
  }

  // Field name: weight
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->weight.data) {
      rosidl_runtime_c__String__init(&ros_message->weight);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->weight,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'weight'\n");
      return false;
    }
  }

  // Field name: height
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->height.data) {
      rosidl_runtime_c__String__init(&ros_message->height);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->height,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'height'\n");
      return false;
    }
  }

  // Field name: primary_language
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->primary_language.data) {
      rosidl_runtime_c__String__init(&ros_message->primary_language);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->primary_language,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'primary_language'\n");
      return false;
    }
  }

  // Field name: password
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->password.data) {
      rosidl_runtime_c__String__init(&ros_message->password);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->password,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'password'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t get_serialized_size_robot_interfaces__srv__Config_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Config_Response__ros_msg_type * ros_message = static_cast<const _Config_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name full_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->full_name.size + 1);
  // field.name age
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->age.size + 1);
  // field.name blood_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->blood_type.size + 1);
  // field.name medical_notes
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->medical_notes.size + 1);
  // field.name allergies
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->allergies.size + 1);
  // field.name weight
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->weight.size + 1);
  // field.name height
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->height.size + 1);
  // field.name primary_language
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->primary_language.size + 1);
  // field.name password
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->password.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _Config_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robot_interfaces__srv__Config_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robot_interfaces
size_t max_serialized_size_robot_interfaces__srv__Config_Response(
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

  // member: full_name
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
  // member: age
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
  // member: blood_type
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
  // member: medical_notes
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
  // member: allergies
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
  // member: weight
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
  // member: height
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
  // member: primary_language
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
  // member: password
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
    using DataType = robot_interfaces__srv__Config_Response;
    is_plain =
      (
      offsetof(DataType, password) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Config_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robot_interfaces__srv__Config_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Config_Response = {
  "robot_interfaces::srv",
  "Config_Response",
  _Config_Response__cdr_serialize,
  _Config_Response__cdr_deserialize,
  _Config_Response__get_serialized_size,
  _Config_Response__max_serialized_size
};

static rosidl_message_type_support_t _Config_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Config_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, Config_Response)() {
  return &_Config_Response__type_support;
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
#include "robot_interfaces/srv/config.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Config__callbacks = {
  "robot_interfaces::srv",
  "Config",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, Config_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, Config_Response)(),
};

static rosidl_service_type_support_t Config__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Config__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robot_interfaces, srv, Config)() {
  return &Config__handle;
}

#if defined(__cplusplus)
}
#endif
