#ifndef _SENSOR_POINT_
#define _SENSOR_POINT_

#include <boost/shared_ptr.hpp>

//Since ROS based message used , this class has public data member 
namespace SensorFusion
{

template <class ContainerAllocator>
class SensorPoint_
{
public:
  

  SensorPoint_()
    : object_id_(0)
    , x_position_(0.0)
    , y_position_(0.0)  {
    }

  SensorPoint_(uint64_t object_id,double x_position,double y_position)
    : object_id_(object_id)
    , x_position_(x_position)
    , y_position_(y_position)  {
    }

  SensorPoint_(const ContainerAllocator& _alloc)
    : object_id_(0)
    , x_position_(0.0)
    , y_position_(0.0)  {
  (void)_alloc;
    }



   uint64_t object_id_;

    double x_position_;

    double y_position_;




  typedef SensorPoint_<ContainerAllocator> Type;
  typedef boost::shared_ptr< ::SensorFusion::SensorPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::SensorFusion::SensorPoint_<ContainerAllocator> const> ConstPtr;

}; // class SensorPoint_

}

#endif // _SENSOR_POINT_
