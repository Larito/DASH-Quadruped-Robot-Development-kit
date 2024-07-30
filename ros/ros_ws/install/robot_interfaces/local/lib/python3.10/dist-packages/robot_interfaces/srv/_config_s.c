// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robot_interfaces/srv/detail/config__struct.h"
#include "robot_interfaces/srv/detail/config__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__srv__config__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[44];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robot_interfaces.srv._config.Config_Request", full_classname_dest, 43) == 0);
  }
  robot_interfaces__srv__Config_Request * ros_message = _ros_message;
  {  // full_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "full_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->full_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // age
    PyObject * field = PyObject_GetAttrString(_pymsg, "age");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->age, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // blood_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "blood_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->blood_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // medical_notes
    PyObject * field = PyObject_GetAttrString(_pymsg, "medical_notes");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->medical_notes, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // allergies
    PyObject * field = PyObject_GetAttrString(_pymsg, "allergies");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->allergies, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "weight");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->weight, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->height, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // primary_language
    PyObject * field = PyObject_GetAttrString(_pymsg, "primary_language");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->primary_language, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // password
    PyObject * field = PyObject_GetAttrString(_pymsg, "password");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->password, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // requesting
    PyObject * field = PyObject_GetAttrString(_pymsg, "requesting");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->requesting = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__srv__config__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Config_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.srv._config");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Config_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__srv__Config_Request * ros_message = (robot_interfaces__srv__Config_Request *)raw_ros_message;
  {  // full_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->full_name.data,
      strlen(ros_message->full_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "full_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // age
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->age.data,
      strlen(ros_message->age.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "age", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blood_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->blood_type.data,
      strlen(ros_message->blood_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "blood_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // medical_notes
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->medical_notes.data,
      strlen(ros_message->medical_notes.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "medical_notes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // allergies
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->allergies.data,
      strlen(ros_message->allergies.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "allergies", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // weight
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->weight.data,
      strlen(ros_message->weight.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->height.data,
      strlen(ros_message->height.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // primary_language
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->primary_language.data,
      strlen(ros_message->primary_language.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "primary_language", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // password
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->password.data,
      strlen(ros_message->password.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "password", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // requesting
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->requesting ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "requesting", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "robot_interfaces/srv/detail/config__struct.h"
// already included above
// #include "robot_interfaces/srv/detail/config__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_interfaces__srv__config__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robot_interfaces.srv._config.Config_Response", full_classname_dest, 44) == 0);
  }
  robot_interfaces__srv__Config_Response * ros_message = _ros_message;
  {  // full_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "full_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->full_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // age
    PyObject * field = PyObject_GetAttrString(_pymsg, "age");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->age, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // blood_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "blood_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->blood_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // medical_notes
    PyObject * field = PyObject_GetAttrString(_pymsg, "medical_notes");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->medical_notes, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // allergies
    PyObject * field = PyObject_GetAttrString(_pymsg, "allergies");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->allergies, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // weight
    PyObject * field = PyObject_GetAttrString(_pymsg, "weight");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->weight, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->height, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // primary_language
    PyObject * field = PyObject_GetAttrString(_pymsg, "primary_language");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->primary_language, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // password
    PyObject * field = PyObject_GetAttrString(_pymsg, "password");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->password, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_interfaces__srv__config__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Config_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_interfaces.srv._config");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Config_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_interfaces__srv__Config_Response * ros_message = (robot_interfaces__srv__Config_Response *)raw_ros_message;
  {  // full_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->full_name.data,
      strlen(ros_message->full_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "full_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // age
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->age.data,
      strlen(ros_message->age.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "age", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // blood_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->blood_type.data,
      strlen(ros_message->blood_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "blood_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // medical_notes
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->medical_notes.data,
      strlen(ros_message->medical_notes.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "medical_notes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // allergies
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->allergies.data,
      strlen(ros_message->allergies.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "allergies", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // weight
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->weight.data,
      strlen(ros_message->weight.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "weight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->height.data,
      strlen(ros_message->height.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // primary_language
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->primary_language.data,
      strlen(ros_message->primary_language.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "primary_language", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // password
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->password.data,
      strlen(ros_message->password.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "password", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
