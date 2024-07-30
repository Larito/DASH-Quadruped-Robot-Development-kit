// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/LMChat.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/lm_chat__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_LMChat_Request_in_msg
{
public:
  Init_LMChat_Request_in_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::LMChat_Request in_msg(::robot_interfaces::srv::LMChat_Request::_in_msg_type arg)
  {
    msg_.in_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::LMChat_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::LMChat_Request>()
{
  return robot_interfaces::srv::builder::Init_LMChat_Request_in_msg();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_LMChat_Response_out_msg
{
public:
  Init_LMChat_Response_out_msg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::LMChat_Response out_msg(::robot_interfaces::srv::LMChat_Response::_out_msg_type arg)
  {
    msg_.out_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::LMChat_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::LMChat_Response>()
{
  return robot_interfaces::srv::builder::Init_LMChat_Response_out_msg();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__LM_CHAT__BUILDER_HPP_
