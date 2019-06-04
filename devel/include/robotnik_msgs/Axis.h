// Generated by gencpp from file robotnik_msgs/Axis.msg
// DO NOT EDIT!


#ifndef ROBOTNIK_MSGS_MESSAGE_AXIS_H
#define ROBOTNIK_MSGS_MESSAGE_AXIS_H


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
struct Axis_
{
  typedef Axis_<ContainerAllocator> Type;

  Axis_()
    : pan(0.0)
    , tilt(0.0)
    , zoom(0.0)
    , focus(0.0)
    , brightness(0.0)
    , iris(0.0)
    , autofocus(false)
    , autoiris(false)  {
    }
  Axis_(const ContainerAllocator& _alloc)
    : pan(0.0)
    , tilt(0.0)
    , zoom(0.0)
    , focus(0.0)
    , brightness(0.0)
    , iris(0.0)
    , autofocus(false)
    , autoiris(false)  {
  (void)_alloc;
    }



   typedef float _pan_type;
  _pan_type pan;

   typedef float _tilt_type;
  _tilt_type tilt;

   typedef float _zoom_type;
  _zoom_type zoom;

   typedef float _focus_type;
  _focus_type focus;

   typedef float _brightness_type;
  _brightness_type brightness;

   typedef float _iris_type;
  _iris_type iris;

   typedef uint8_t _autofocus_type;
  _autofocus_type autofocus;

   typedef uint8_t _autoiris_type;
  _autoiris_type autoiris;





  typedef boost::shared_ptr< ::robotnik_msgs::Axis_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotnik_msgs::Axis_<ContainerAllocator> const> ConstPtr;

}; // struct Axis_

typedef ::robotnik_msgs::Axis_<std::allocator<void> > Axis;

typedef boost::shared_ptr< ::robotnik_msgs::Axis > AxisPtr;
typedef boost::shared_ptr< ::robotnik_msgs::Axis const> AxisConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotnik_msgs::Axis_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotnik_msgs::Axis_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::robotnik_msgs::Axis_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotnik_msgs::Axis_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::Axis_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotnik_msgs::Axis_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::Axis_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotnik_msgs::Axis_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotnik_msgs::Axis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e5a99fe291a5635d3f85f17b629d8088";
  }

  static const char* value(const ::robotnik_msgs::Axis_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe5a99fe291a5635dULL;
  static const uint64_t static_value2 = 0x3f85f17b629d8088ULL;
};

template<class ContainerAllocator>
struct DataType< ::robotnik_msgs::Axis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotnik_msgs/Axis";
  }

  static const char* value(const ::robotnik_msgs::Axis_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotnik_msgs::Axis_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 pan\n\
float32 tilt\n\
float32 zoom\n\
float32 focus\n\
float32 brightness\n\
float32 iris\n\
bool autofocus\n\
bool autoiris\n\
";
  }

  static const char* value(const ::robotnik_msgs::Axis_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotnik_msgs::Axis_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pan);
      stream.next(m.tilt);
      stream.next(m.zoom);
      stream.next(m.focus);
      stream.next(m.brightness);
      stream.next(m.iris);
      stream.next(m.autofocus);
      stream.next(m.autoiris);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Axis_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotnik_msgs::Axis_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotnik_msgs::Axis_<ContainerAllocator>& v)
  {
    s << indent << "pan: ";
    Printer<float>::stream(s, indent + "  ", v.pan);
    s << indent << "tilt: ";
    Printer<float>::stream(s, indent + "  ", v.tilt);
    s << indent << "zoom: ";
    Printer<float>::stream(s, indent + "  ", v.zoom);
    s << indent << "focus: ";
    Printer<float>::stream(s, indent + "  ", v.focus);
    s << indent << "brightness: ";
    Printer<float>::stream(s, indent + "  ", v.brightness);
    s << indent << "iris: ";
    Printer<float>::stream(s, indent + "  ", v.iris);
    s << indent << "autofocus: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.autofocus);
    s << indent << "autoiris: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.autoiris);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTNIK_MSGS_MESSAGE_AXIS_H
