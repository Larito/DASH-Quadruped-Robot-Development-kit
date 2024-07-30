// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/RobotStatusSrv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/robot_status_srv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotStatusSrv_Request_formality
{
public:
  Init_RobotStatusSrv_Request_formality()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RobotStatusSrv_Request formality(::robot_interfaces::srv::RobotStatusSrv_Request::_formality_type arg)
  {
    msg_.formality = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RobotStatusSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RobotStatusSrv_Request>()
{
  return robot_interfaces::srv::builder::Init_RobotStatusSrv_Request_formality();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RobotStatusSrv_Response_current_mode
{
public:
  explicit Init_RobotStatusSrv_Response_current_mode(::robot_interfaces::srv::RobotStatusSrv_Response & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::RobotStatusSrv_Response current_mode(::robot_interfaces::srv::RobotStatusSrv_Response::_current_mode_type arg)
  {
    msg_.current_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RobotStatusSrv_Response msg_;
};

class Init_RobotStatusSrv_Response_battery_level
{
public:
  Init_RobotStatusSrv_Response_battery_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatusSrv_Response_current_mode battery_level(::robot_interfaces::srv::RobotStatusSrv_Response::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_RobotStatusSrv_Response_current_mode(msg_);
  }

private:
  ::robot_interfaces::srv::RobotStatusSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RobotStatusSrv_Response>()
{
  return robot_interfaces::srv::builder::Init_RobotStatusSrv_Response_battery_level();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__BUILDER_HPP_
