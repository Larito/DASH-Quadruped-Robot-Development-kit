// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CONFIG__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Config_Request_requesting
{
public:
  explicit Init_Config_Request_requesting(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::Config_Request requesting(::robot_interfaces::srv::Config_Request::_requesting_type arg)
  {
    msg_.requesting = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_password
{
public:
  explicit Init_Config_Request_password(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_requesting password(::robot_interfaces::srv::Config_Request::_password_type arg)
  {
    msg_.password = std::move(arg);
    return Init_Config_Request_requesting(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_primary_language
{
public:
  explicit Init_Config_Request_primary_language(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_password primary_language(::robot_interfaces::srv::Config_Request::_primary_language_type arg)
  {
    msg_.primary_language = std::move(arg);
    return Init_Config_Request_password(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_height
{
public:
  explicit Init_Config_Request_height(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_primary_language height(::robot_interfaces::srv::Config_Request::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Config_Request_primary_language(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_weight
{
public:
  explicit Init_Config_Request_weight(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_height weight(::robot_interfaces::srv::Config_Request::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return Init_Config_Request_height(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_allergies
{
public:
  explicit Init_Config_Request_allergies(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_weight allergies(::robot_interfaces::srv::Config_Request::_allergies_type arg)
  {
    msg_.allergies = std::move(arg);
    return Init_Config_Request_weight(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_medical_notes
{
public:
  explicit Init_Config_Request_medical_notes(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_allergies medical_notes(::robot_interfaces::srv::Config_Request::_medical_notes_type arg)
  {
    msg_.medical_notes = std::move(arg);
    return Init_Config_Request_allergies(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_blood_type
{
public:
  explicit Init_Config_Request_blood_type(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_medical_notes blood_type(::robot_interfaces::srv::Config_Request::_blood_type_type arg)
  {
    msg_.blood_type = std::move(arg);
    return Init_Config_Request_medical_notes(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_age
{
public:
  explicit Init_Config_Request_age(::robot_interfaces::srv::Config_Request & msg)
  : msg_(msg)
  {}
  Init_Config_Request_blood_type age(::robot_interfaces::srv::Config_Request::_age_type arg)
  {
    msg_.age = std::move(arg);
    return Init_Config_Request_blood_type(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

class Init_Config_Request_full_name
{
public:
  Init_Config_Request_full_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Config_Request_age full_name(::robot_interfaces::srv::Config_Request::_full_name_type arg)
  {
    msg_.full_name = std::move(arg);
    return Init_Config_Request_age(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Config_Request>()
{
  return robot_interfaces::srv::builder::Init_Config_Request_full_name();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Config_Response_password
{
public:
  explicit Init_Config_Response_password(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::Config_Response password(::robot_interfaces::srv::Config_Response::_password_type arg)
  {
    msg_.password = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_primary_language
{
public:
  explicit Init_Config_Response_primary_language(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_password primary_language(::robot_interfaces::srv::Config_Response::_primary_language_type arg)
  {
    msg_.primary_language = std::move(arg);
    return Init_Config_Response_password(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_height
{
public:
  explicit Init_Config_Response_height(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_primary_language height(::robot_interfaces::srv::Config_Response::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_Config_Response_primary_language(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_weight
{
public:
  explicit Init_Config_Response_weight(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_height weight(::robot_interfaces::srv::Config_Response::_weight_type arg)
  {
    msg_.weight = std::move(arg);
    return Init_Config_Response_height(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_allergies
{
public:
  explicit Init_Config_Response_allergies(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_weight allergies(::robot_interfaces::srv::Config_Response::_allergies_type arg)
  {
    msg_.allergies = std::move(arg);
    return Init_Config_Response_weight(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_medical_notes
{
public:
  explicit Init_Config_Response_medical_notes(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_allergies medical_notes(::robot_interfaces::srv::Config_Response::_medical_notes_type arg)
  {
    msg_.medical_notes = std::move(arg);
    return Init_Config_Response_allergies(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_blood_type
{
public:
  explicit Init_Config_Response_blood_type(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_medical_notes blood_type(::robot_interfaces::srv::Config_Response::_blood_type_type arg)
  {
    msg_.blood_type = std::move(arg);
    return Init_Config_Response_medical_notes(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_age
{
public:
  explicit Init_Config_Response_age(::robot_interfaces::srv::Config_Response & msg)
  : msg_(msg)
  {}
  Init_Config_Response_blood_type age(::robot_interfaces::srv::Config_Response::_age_type arg)
  {
    msg_.age = std::move(arg);
    return Init_Config_Response_blood_type(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

class Init_Config_Response_full_name
{
public:
  Init_Config_Response_full_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Config_Response_age full_name(::robot_interfaces::srv::Config_Response::_full_name_type arg)
  {
    msg_.full_name = std::move(arg);
    return Init_Config_Response_age(msg_);
  }

private:
  ::robot_interfaces::srv::Config_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Config_Response>()
{
  return robot_interfaces::srv::builder::Init_Config_Response_full_name();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CONFIG__BUILDER_HPP_
