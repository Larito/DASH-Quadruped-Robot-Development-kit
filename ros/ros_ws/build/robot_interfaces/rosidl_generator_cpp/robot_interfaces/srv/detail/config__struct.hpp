// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:srv/Config.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Config_Request __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Config_Request __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Config_Request_
{
  using Type = Config_Request_<ContainerAllocator>;

  explicit Config_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_name = "";
      this->age = "";
      this->blood_type = "";
      this->medical_notes = "";
      this->allergies = "";
      this->weight = "";
      this->height = "";
      this->primary_language = "";
      this->password = "";
      this->requesting = false;
    }
  }

  explicit Config_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : full_name(_alloc),
    age(_alloc),
    blood_type(_alloc),
    medical_notes(_alloc),
    allergies(_alloc),
    weight(_alloc),
    height(_alloc),
    primary_language(_alloc),
    password(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_name = "";
      this->age = "";
      this->blood_type = "";
      this->medical_notes = "";
      this->allergies = "";
      this->weight = "";
      this->height = "";
      this->primary_language = "";
      this->password = "";
      this->requesting = false;
    }
  }

  // field types and members
  using _full_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _full_name_type full_name;
  using _age_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _age_type age;
  using _blood_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _blood_type_type blood_type;
  using _medical_notes_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _medical_notes_type medical_notes;
  using _allergies_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _allergies_type allergies;
  using _weight_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _weight_type weight;
  using _height_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _height_type height;
  using _primary_language_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _primary_language_type primary_language;
  using _password_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _password_type password;
  using _requesting_type =
    bool;
  _requesting_type requesting;

  // setters for named parameter idiom
  Type & set__full_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->full_name = _arg;
    return *this;
  }
  Type & set__age(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->age = _arg;
    return *this;
  }
  Type & set__blood_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->blood_type = _arg;
    return *this;
  }
  Type & set__medical_notes(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->medical_notes = _arg;
    return *this;
  }
  Type & set__allergies(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->allergies = _arg;
    return *this;
  }
  Type & set__weight(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->weight = _arg;
    return *this;
  }
  Type & set__height(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__primary_language(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->primary_language = _arg;
    return *this;
  }
  Type & set__password(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->password = _arg;
    return *this;
  }
  Type & set__requesting(
    const bool & _arg)
  {
    this->requesting = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Config_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Config_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Config_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Config_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Config_Request
    std::shared_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Config_Request
    std::shared_ptr<robot_interfaces::srv::Config_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Config_Request_ & other) const
  {
    if (this->full_name != other.full_name) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    if (this->blood_type != other.blood_type) {
      return false;
    }
    if (this->medical_notes != other.medical_notes) {
      return false;
    }
    if (this->allergies != other.allergies) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->primary_language != other.primary_language) {
      return false;
    }
    if (this->password != other.password) {
      return false;
    }
    if (this->requesting != other.requesting) {
      return false;
    }
    return true;
  }
  bool operator!=(const Config_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Config_Request_

// alias to use template instance with default allocator
using Config_Request =
  robot_interfaces::srv::Config_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__srv__Config_Response __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__srv__Config_Response __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Config_Response_
{
  using Type = Config_Response_<ContainerAllocator>;

  explicit Config_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_name = "";
      this->age = "";
      this->blood_type = "";
      this->medical_notes = "";
      this->allergies = "";
      this->weight = "";
      this->height = "";
      this->primary_language = "";
      this->password = "";
    }
  }

  explicit Config_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : full_name(_alloc),
    age(_alloc),
    blood_type(_alloc),
    medical_notes(_alloc),
    allergies(_alloc),
    weight(_alloc),
    height(_alloc),
    primary_language(_alloc),
    password(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->full_name = "";
      this->age = "";
      this->blood_type = "";
      this->medical_notes = "";
      this->allergies = "";
      this->weight = "";
      this->height = "";
      this->primary_language = "";
      this->password = "";
    }
  }

  // field types and members
  using _full_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _full_name_type full_name;
  using _age_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _age_type age;
  using _blood_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _blood_type_type blood_type;
  using _medical_notes_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _medical_notes_type medical_notes;
  using _allergies_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _allergies_type allergies;
  using _weight_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _weight_type weight;
  using _height_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _height_type height;
  using _primary_language_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _primary_language_type primary_language;
  using _password_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _password_type password;

  // setters for named parameter idiom
  Type & set__full_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->full_name = _arg;
    return *this;
  }
  Type & set__age(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->age = _arg;
    return *this;
  }
  Type & set__blood_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->blood_type = _arg;
    return *this;
  }
  Type & set__medical_notes(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->medical_notes = _arg;
    return *this;
  }
  Type & set__allergies(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->allergies = _arg;
    return *this;
  }
  Type & set__weight(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->weight = _arg;
    return *this;
  }
  Type & set__height(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__primary_language(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->primary_language = _arg;
    return *this;
  }
  Type & set__password(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->password = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::srv::Config_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::srv::Config_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Config_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::srv::Config_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__srv__Config_Response
    std::shared_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__srv__Config_Response
    std::shared_ptr<robot_interfaces::srv::Config_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Config_Response_ & other) const
  {
    if (this->full_name != other.full_name) {
      return false;
    }
    if (this->age != other.age) {
      return false;
    }
    if (this->blood_type != other.blood_type) {
      return false;
    }
    if (this->medical_notes != other.medical_notes) {
      return false;
    }
    if (this->allergies != other.allergies) {
      return false;
    }
    if (this->weight != other.weight) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->primary_language != other.primary_language) {
      return false;
    }
    if (this->password != other.password) {
      return false;
    }
    return true;
  }
  bool operator!=(const Config_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Config_Response_

// alias to use template instance with default allocator
using Config_Response =
  robot_interfaces::srv::Config_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robot_interfaces

namespace robot_interfaces
{

namespace srv
{

struct Config
{
  using Request = robot_interfaces::srv::Config_Request;
  using Response = robot_interfaces::srv::Config_Response;
};

}  // namespace srv

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CONFIG__STRUCT_HPP_
