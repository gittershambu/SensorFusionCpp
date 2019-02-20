///
/// KPIT
///

#include "DemoExecuteSensorFusion.h"
#include "RosWrapper.h"
 


namespace SensorFusion
{
 void DemoExecuteSensorFusion::PrepareData(std::string sensor_name, const SensorDataMsg& msg) 
 {
      sensor_data_[sensor_name].push_back(msg);
 }

void DemoExecuteSensorFusion::PreFusion( int time_stampe) 
{
    // publish to Ros
}

void DemoExecuteSensorFusion::PostFusion( int time_stampe) 
{
  std::unique_ptr<SensorDataMsg> s = std::make_unique<SensorDataMsg>(fusion_output_.timestamp_,fusion_output_.object_count_,
  fusion_output_.sensor_list_data_);
  ros_output_->RosPrintSensorMessage(std::move(s));
  ros_output_->RosPublish(*s);
  //out_.send() ;
}

}