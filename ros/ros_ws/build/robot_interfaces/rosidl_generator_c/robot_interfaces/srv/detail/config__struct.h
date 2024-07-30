// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'full_name'
// Member 'age'
// Member 'blood_type'
// Member 'medical_notes'
// Member 'allergies'
// Member 'weight'
// Member 'height'
// Member 'primary_language'
// Member 'password'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Config in the package robot_interfaces.
typedef struct robot_interfaces__srv__Config_Request
{
  rosidl_runtime_c__String full_name;
  rosidl_runtime_c__String age;
  rosidl_runtime_c__String blood_type;
  rosidl_runtime_c__String medical_notes;
  rosidl_runtime_c__String allergies;
  rosidl_runtime_c__String weight;
  rosidl_runtime_c__String height;
  rosidl_runtime_c__String primary_language;
  rosidl_runtime_c__String password;
  bool requesting;
} robot_interfaces__srv__Config_Request;

// Struct for a sequence of robot_interfaces__srv__Config_Request.
typedef struct robot_interfaces__srv__Config_Request__Sequence
{
  robot_interfaces__srv__Config_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__Config_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'full_name'
// Member 'age'
// Member 'blood_type'
// Member 'medical_notes'
// Member 'allergies'
// Member 'weight'
// Member 'height'
// Member 'primary_language'
// Member 'password'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Config in the package robot_interfaces.
typedef struct robot_interfaces__srv__Config_Response
{
  rosidl_runtime_c__String full_name;
  rosidl_runtime_c__String age;
  rosidl_runtime_c__String blood_type;
  rosidl_runtime_c__String medical_notes;
  rosidl_runtime_c__String allergies;
  rosidl_runtime_c__String weight;
  rosidl_runtime_c__String height;
  rosidl_runtime_c__String primary_language;
  rosidl_runtime_c__String password;
} robot_interfaces__srv__Config_Response;

// Struct for a sequence of robot_interfaces__srv__Config_Response.
typedef struct robot_interfaces__srv__Config_Response__Sequence
{
  robot_interfaces__srv__Config_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__Config_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_H_
