// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/LMChat.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'in_msg'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LMChat in the package robot_interfaces.
typedef struct robot_interfaces__srv__LMChat_Request
{
  rosidl_runtime_c__String in_msg;
} robot_interfaces__srv__LMChat_Request;

// Struct for a sequence of robot_interfaces__srv__LMChat_Request.
typedef struct robot_interfaces__srv__LMChat_Request__Sequence
{
  robot_interfaces__srv__LMChat_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__LMChat_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'out_msg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LMChat in the package robot_interfaces.
typedef struct robot_interfaces__srv__LMChat_Response
{
  rosidl_runtime_c__String out_msg;
} robot_interfaces__srv__LMChat_Response;

// Struct for a sequence of robot_interfaces__srv__LMChat_Response.
typedef struct robot_interfaces__srv__LMChat_Response__Sequence
{
  robot_interfaces__srv__LMChat_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__LMChat_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__STRUCT_H_
