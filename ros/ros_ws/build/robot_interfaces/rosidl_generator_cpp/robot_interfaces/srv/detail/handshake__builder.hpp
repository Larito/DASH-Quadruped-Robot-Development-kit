// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/Handshake.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/handshake__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Handshake_Request_password
{
public:
  Init_Handshake_Request_password()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::Handshake_Request password(::robot_interfaces::srv::Handshake_Request::_password_type arg)
  {
    msg_.password = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Handshake_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Handshake_Request>()
{
  return robot_interfaces::srv::builder::Init_Handshake_Request_password();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Handshake_Response_correct
{
public:
  Init_Handshake_Response_correct()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::Handshake_Response correct(::robot_interfaces::srv::Handshake_Response::_correct_type arg)
  {
    msg_.correct = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Handshake_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Handshake_Response>()
{
  return robot_interfaces::srv::builder::Init_Handshake_Response_correct();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__BUILDER_HPP_
