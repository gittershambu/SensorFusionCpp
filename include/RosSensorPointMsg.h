

#ifndef SENSOR_FUSION_MESSAGE_SENSORPOINT_H
#define SENSOR_FUSION_MESSAGE_SENSORPOINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include "SensorPoint.h"

namespace SensorFusion
{


typedef ::SensorFusion::SensorPoint_<std::allocator<void> > SensorPoint;

typedef boost::shared_ptr< ::SensorFusion::SensorPoint > SensorPointPtr;
typedef boost::shared_ptr< ::SensorFusion::SensorPoint const> SensorPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::SensorFusion::SensorPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::SensorFusion::SensorPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace sensor_fusion

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_fusion': ['/home/shruti/Projects/rosworkspace/src/sensor_fusion/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::SensorFusion::SensorPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::SensorFusion::SensorPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::SensorFusion::SensorPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::SensorFusion::SensorPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::SensorFusion::SensorPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::SensorFusion::SensorPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::SensorFusion::SensorPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3781ee6e00079a6ac4781d7c0fbef882";
  }

  static const char* value(const ::SensorFusion::SensorPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3781ee6e00079a6aULL;
  static const uint64_t static_value2 = 0xc4781d7c0fbef882ULL;
};

template<class ContainerAllocator>
struct DataType< ::SensorFusion::SensorPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "SensorFusion/SensorPoint";
  }

  static const char* value(const ::SensorFusion::SensorPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::SensorFusion::SensorPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint64 object_id_\n\
float64 x_position_\n\
float64 y_position_  \n\
";
  }

  static const char* value(const ::SensorFusion::SensorPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::SensorFusion::SensorPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.object_id_);
      stream.next(m.x_position_);
      stream.next(m.y_position_);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SensorPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::SensorFusion::SensorPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::SensorFusion::SensorPoint_<ContainerAllocator>& v)
  {
    s << indent << "object_id_: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.object_id_);
    s << indent << "x_position_: ";
    Printer<double>::stream(s, indent + "  ", v.x_position_);
    s << indent << "y_position_: ";
    Printer<double>::stream(s, indent + "  ", v.y_position_);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SENSOR_FUSION_MESSAGE_SENSORPOINT_H
