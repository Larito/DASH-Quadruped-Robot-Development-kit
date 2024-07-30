// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/RobotStatusSrv.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotStatusSrv_Request_
{
  using Type = RobotStatusSrv_Request_<ContainerAllocator>;

  explicit RobotStatusSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formality = false;
    }
  }

  explicit RobotStatusSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->formality = false;
    }
  }

  // field types and members
  using _formality_type =
    bool;
  _formality_type formality;

  // setters for named parameter idiom
  Type & set__formality(
    const bool & _arg)
  {
    this->formality = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Request
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Request
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatusSrv_Request_ & other) const
  {
    if (this->formality != other.formality) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatusSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatusSrv_Request_

// alias to use template instance with default allocator
using RobotStatusSrv_Request =
  robot_interfaces::srv::RobotStatusSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RobotStatusSrv_Response_
{
  using Type = RobotStatusSrv_Response_<ContainerAllocator>;

  explicit RobotStatusSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_level = 0l;
      this->current_mode = 0l;
    }
  }

  explicit RobotStatusSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_level = 0l;
      this->current_mode = 0l;
    }
  }

  // field types and members
  using _battery_level_type =
    int32_t;
  _battery_level_type battery_level;
  using _current_mode_type =
    int32_t;
  _current_mode_type current_mode;

  // setters for named parameter idiom
  Type & set__battery_level(
    const int32_t & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__current_mode(
    const int32_t & _arg)
  {
    this->current_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Response
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__RobotStatusSrv_Response
    std::shared_ptr<robot_interfaces::srv::RobotStatusSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotStatusSrv_Response_ & other) const
  {
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->current_mode != other.current_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotStatusSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotStatusSrv_Response_

// alias to use template instance with default allocator
using RobotStatusSrv_Response =
  robot_interfaces::srv::RobotStatusSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct RobotStatusSrv
{
  using Request = robot_interfaces::srv::RobotStatusSrv_Request;
  using Response = robot_interfaces::srv::RobotStatusSrv_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROBOT_STATUS_SRV__STRUCT_HPP_
