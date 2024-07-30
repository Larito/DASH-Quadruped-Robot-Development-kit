// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/Handshake.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Handshake_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Handshake_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Handshake_Request_
{
  using Type = Handshake_Request_<ContainerAllocator>;

  explicit Handshake_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->password = "";
    }
  }

  explicit Handshake_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : password(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->password = "";
    }
  }

  // field types and members
  using _password_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _password_type password;

  // setters for named parameter idiom
  Type & set__password(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->password = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Handshake_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Handshake_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Handshake_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Handshake_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Handshake_Request
    std::shared_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Handshake_Request
    std::shared_ptr<robot_interfaces::srv::Handshake_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Handshake_Request_ & other) const
  {
    if (this->password != other.password) {
      return false;
    }
    return true;
  }
  bool operator!=(const Handshake_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Handshake_Request_

// alias to use template instance with default allocator
using Handshake_Request =
  robot_interfaces::srv::Handshake_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Handshake_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Handshake_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Handshake_Response_
{
  using Type = Handshake_Response_<ContainerAllocator>;

  explicit Handshake_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->correct = false;
    }
  }

  explicit Handshake_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->correct = false;
    }
  }

  // field types and members
  using _correct_type =
    bool;
  _correct_type correct;

  // setters for named parameter idiom
  Type & set__correct(
    const bool & _arg)
  {
    this->correct = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Handshake_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Handshake_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Handshake_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Handshake_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Handshake_Response
    std::shared_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Handshake_Response
    std::shared_ptr<robot_interfaces::srv::Handshake_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Handshake_Response_ & other) const
  {
    if (this->correct != other.correct) {
      return false;
    }
    return true;
  }
  bool operator!=(const Handshake_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Handshake_Response_

// alias to use template instance with default allocator
using Handshake_Response =
  robot_interfaces::srv::Handshake_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct Handshake
{
  using Request = robot_interfaces::srv::Handshake_Request;
  using Response = robot_interfaces::srv::Handshake_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__HANDSHAKE__STRUCT_HPP_
