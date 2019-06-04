// Generated by gencpp from file robotnik_msgs/enable_disableRequest.msg
// DO NOT EDIT!


#ifndef ROBOTNIK_MSGS_MESSAGE_ENABLE_DISABLEREQUEST_H
#define ROBOTNIK_MSGS_MESSAGE_ENABLE_DISABLEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotnik_msgs
{
template <class ContainerAllocator>
struct enable_disableRequest_
{
  typedef enable_disableRequest_<ContainerAllocator> Type;

  enable_disableRequest_()
    : value(false)  {
    }
  enable_disableRequest_(const ContainerAllocator& _alloc)
    : value(false)  {
  (void)_alloc;
    }



   typedef uint8_t _value_type;
  _value_type value;





  typedef boost::shared_ptr< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> const> ConstPtr;

}; // struct enable_disableRequest_

typedef ::robotnik_msgs::enable_disableRequest_<std::allocator<void> > enable_disableRequest;

typedef boost::shared_ptr< ::robotnik_msgs::enable_disableRequest > enable_disableRequestPtr;
typedef boost::shared_ptr< ::robotnik_msgs::enable_disableRequest const> enable_disableRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotnik_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'robotnik_msgs': ['/home/afavier/osmosis_ws/src/robotnik_msgs/msg', '/home/afavier/osmosis_ws/devel/share/robotnik_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e431d687bf4b2c65fbd94b12ae0cb5d9";
  }

  static const char* value(const ::robotnik_msgs::enable_disableRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe431d687bf4b2c65ULL;
  static const uint64_t static_value2 = 0xfbd94b12ae0cb5d9ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotnik_msgs/enable_disableRequest";
  }

  static const char* value(const ::robotnik_msgs::enable_disableRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool value\n\
";
  }

  static const char* value(const ::robotnik_msgs::enable_disableRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.value);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct enable_disableRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotnik_msgs::enable_disableRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotnik_msgs::enable_disableRequest_<ContainerAllocator>& v)
  {
    s << indent << "value: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.value);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTNIK_MSGS_MESSAGE_ENABLE_DISABLEREQUEST_H
