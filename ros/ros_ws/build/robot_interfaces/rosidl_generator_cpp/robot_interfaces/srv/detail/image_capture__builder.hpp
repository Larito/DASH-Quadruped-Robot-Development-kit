// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/ImageCapture.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__IMAGE_CAPTURE__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__IMAGE_CAPTURE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/image_capture__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ImageCapture_Request_command
{
public:
  Init_ImageCapture_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ImageCapture_Request command(::robot_interfaces::srv::ImageCapture_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ImageCapture_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ImageCapture_Request>()
{
  return robot_interfaces::srv::builder::Init_ImageCapture_Request_command();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_ImageCapture_Response_image_base64
{
public:
  Init_ImageCapture_Response_image_base64()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::ImageCapture_Response image_base64(::robot_interfaces::srv::ImageCapture_Response::_image_base64_type arg)
  {
    msg_.image_base64 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::ImageCapture_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::ImageCapture_Response>()
{
  return robot_interfaces::srv::builder::Init_ImageCapture_Response_image_base64();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__IMAGE_CAPTURE__BUILDER_HPP_
