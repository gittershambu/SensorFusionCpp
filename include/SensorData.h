#ifndef _SENSOR_DATA_
#define _SENSOR_DATA_

#include "SensorPoint.h"
#include "RosSensorPointMsg.h"
#include <boost/shared_ptr.hpp>
#include <vector>
#include <iostream>

//Since ROS based message used , this class has public data member 
namespace SensorFusion
{
    
template <class ContainerAllocator>
class SensorDataMsg_
{
public:
  

  SensorDataMsg_()
    : timestamp_(0)
    , object_count_(0)
    , sensor_list_data_()  {
    }

 SensorDataMsg_(uint64_t timestamp, uint32_t object_count,const std::vector<SensorPoint>& sensor_list_data)
    : timestamp_(timestamp)
    , object_count_(object_count)
    , sensor_list_data_(sensor_list_data)  {
    }

  SensorDataMsg_(const ContainerAllocator& _alloc)
    : timestamp_(0)
    , object_count_(0)
    , sensor_list_data_()  {
  (void)_alloc;
   std::cout<<"_alloc copy constructor called"<<std::endl;
    }

    SensorDataMsg_(const SensorDataMsg_& object)
    : timestamp_(object.timestamp_)
    , object_count_(object.object_count_)
    , sensor_list_data_(object.sensor_list_data_)
    {
     // new std::vector<SensorPoint>(object.sensor_list_data_.size());
     std::cout<<"copy constructor called"<<std::endl;
     
    }

    ~SensorDataMsg_() {};


   uint64_t timestamp_;

   uint32_t object_count_;

   std::vector<SensorPoint>  sensor_list_data_;

  typedef SensorDataMsg_<ContainerAllocator> Type;
  typedef boost::shared_ptr< ::SensorFusion::SensorDataMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::SensorFusion::SensorDataMsg_<ContainerAllocator> const> ConstPtr;
};

}

#endif // _SENSOR_DATA_
