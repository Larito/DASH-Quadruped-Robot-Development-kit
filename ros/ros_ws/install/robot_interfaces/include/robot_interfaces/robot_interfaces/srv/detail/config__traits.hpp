// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CONFIG__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Config_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: full_name
  {
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << ", ";
  }

  // member: age
  {
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
    out << ", ";
  }

  // member: blood_type
  {
    out << "blood_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blood_type, out);
    out << ", ";
  }

  // member: medical_notes
  {
    out << "medical_notes: ";
    rosidl_generator_traits::value_to_yaml(msg.medical_notes, out);
    out << ", ";
  }

  // member: allergies
  {
    out << "allergies: ";
    rosidl_generator_traits::value_to_yaml(msg.allergies, out);
    out << ", ";
  }

  // member: weight
  {
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: primary_language
  {
    out << "primary_language: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_language, out);
    out << ", ";
  }

  // member: password
  {
    out << "password: ";
    rosidl_generator_traits::value_to_yaml(msg.password, out);
    out << ", ";
  }

  // member: requesting
  {
    out << "requesting: ";
    rosidl_generator_traits::value_to_yaml(msg.requesting, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Config_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: full_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << "\n";
  }

  // member: age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
    out << "\n";
  }

  // member: blood_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blood_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blood_type, out);
    out << "\n";
  }

  // member: medical_notes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "medical_notes: ";
    rosidl_generator_traits::value_to_yaml(msg.medical_notes, out);
    out << "\n";
  }

  // member: allergies
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "allergies: ";
    rosidl_generator_traits::value_to_yaml(msg.allergies, out);
    out << "\n";
  }

  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: primary_language
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "primary_language: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_language, out);
    out << "\n";
  }

  // member: password
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "password: ";
    rosidl_generator_traits::value_to_yaml(msg.password, out);
    out << "\n";
  }

  // member: requesting
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "requesting: ";
    rosidl_generator_traits::value_to_yaml(msg.requesting, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Config_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::Config_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::Config_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::Config_Request>()
{
  return "robot_interfaces::srv::Config_Request";
}

template<>
inline const char * name<robot_interfaces::srv::Config_Request>()
{
  return "robot_interfaces/srv/Config_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::Config_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::Config_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::Config_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Config_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: full_name
  {
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << ", ";
  }

  // member: age
  {
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
    out << ", ";
  }

  // member: blood_type
  {
    out << "blood_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blood_type, out);
    out << ", ";
  }

  // member: medical_notes
  {
    out << "medical_notes: ";
    rosidl_generator_traits::value_to_yaml(msg.medical_notes, out);
    out << ", ";
  }

  // member: allergies
  {
    out << "allergies: ";
    rosidl_generator_traits::value_to_yaml(msg.allergies, out);
    out << ", ";
  }

  // member: weight
  {
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: primary_language
  {
    out << "primary_language: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_language, out);
    out << ", ";
  }

  // member: password
  {
    out << "password: ";
    rosidl_generator_traits::value_to_yaml(msg.password, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Config_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: full_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "full_name: ";
    rosidl_generator_traits::value_to_yaml(msg.full_name, out);
    out << "\n";
  }

  // member: age
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "age: ";
    rosidl_generator_traits::value_to_yaml(msg.age, out);
    out << "\n";
  }

  // member: blood_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blood_type: ";
    rosidl_generator_traits::value_to_yaml(msg.blood_type, out);
    out << "\n";
  }

  // member: medical_notes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "medical_notes: ";
    rosidl_generator_traits::value_to_yaml(msg.medical_notes, out);
    out << "\n";
  }

  // member: allergies
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "allergies: ";
    rosidl_generator_traits::value_to_yaml(msg.allergies, out);
    out << "\n";
  }

  // member: weight
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "weight: ";
    rosidl_generator_traits::value_to_yaml(msg.weight, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: primary_language
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "primary_language: ";
    rosidl_generator_traits::value_to_yaml(msg.primary_language, out);
    out << "\n";
  }

  // member: password
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "password: ";
    rosidl_generator_traits::value_to_yaml(msg.password, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Config_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::Config_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::Config_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::Config_Response>()
{
  return "robot_interfaces::srv::Config_Response";
}

template<>
inline const char * name<robot_interfaces::srv::Config_Response>()
{
  return "robot_interfaces/srv/Config_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::Config_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_interfaces::srv::Config_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_interfaces::srv::Config_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::Config>()
{
  return "robot_interfaces::srv::Config";
}

template<>
inline const char * name<robot_interfaces::srv::Config>()
{
  return "robot_interfaces/srv/Config";
}

template<>
struct has_fixed_size<robot_interfaces::srv::Config>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::Config_Request>::value &&
    has_fixed_size<robot_interfaces::srv::Config_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::Config>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::Config_Request>::value &&
    has_bounded_size<robot_interfaces::srv::Config_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::Config>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::Config_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::Config_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CONFIG__TRAITS_HPP_
