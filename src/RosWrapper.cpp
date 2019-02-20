#include "RosWrapper.h"
#include "SensorData.h"

namespace SensorFusion
{
    
RosWrapper::RosWrapper()
{
}

void RosWrapper::RosInit(int argc, char** argv,const std::string & name)
{
    ros::init(argc,argv, name);
}

void RosWrapper::RosSpin()
{
  ros::spin(); 
} 

void RosWrapper::RosSpinOnce()
{
  ros::spinOnce(); 
}    
   

void RosWrapper::CreateRosHandle()
{
  node_handle_ = std::make_unique<ros::NodeHandle>();
  if(node_handle_ == nullptr)
  {
    ROS_INFO("node_handle_ is null and node name");
  }
} 

void RosWrapper::CreateRosPublisher(const std::string& topics, int queue_size)
{
if(node_handle_)
      ros_publisher_handle_  = (node_handle_)->advertise<SensorDataMsg>(topics, queue_size);
}

void RosWrapper::SetLoopRate(int loop_rate)
{
 ros_loop_rate = std::make_unique<ros::Rate>(ros::Rate(loop_rate));
}

void RosWrapper::RosPublish(const SensorDataMsg& data)
{
    //SensorDataMsg data_msg = reinterpret_cast<SensorDataMsg>(data);
    ros_publisher_handle_.publish(data);
}

void RosWrapper::CreateRosSubscriber(const std::string& topics, int queue_size,callback_function_pointer ptr)
{
    ros_subscriber_handle_ = node_handle_->subscribe(topics, queue_size, ptr);
}

void RosWrapper::RosPrintString(const std::string & print_message)
{
   ROS_INFO("RosPrintString [%s]", print_message.c_str());
}

void RosWrapper::RosPrintDouble(double print_message)
{
  ROS_INFO("RosPrintDouble [%f]", print_message);
}

void RosWrapper::RosPrintInt(int print_message)
{
  ROS_INFO("RosPrintInt [%d]", print_message);
}
  
void RosWrapper::RosPrintMessageInt(const std::string & print_message,int print_int_message)
{
   ROS_INFO("RosPrintMessageInt [%s] = [%d]", print_message,print_int_message); 
}

void RosWrapper::RosPrintMessageDouble(const std::string & print_message,double print_int_message)
{
  ROS_INFO("RosPrintMessageDouble [%s] = [%f]", print_message,print_int_message);
}

void RosWrapper::RosPrintSensorMessage(const std::list<std::unique_ptr<SensorDataMsg>>& sensor_datas)
{   
   for(auto& sensor_data : sensor_datas)
   {
    ROS_INFO("Object Count [%d]",(*sensor_data).object_count_);
    std::vector<SensorPoint> points = (*sensor_data).sensor_list_data_;
    for(auto& point : points)
    {
      ROS_INFO("Object x_position_ [%f] y_position_ [%f]", point.x_position_,point.y_position_); 
    }
   }
}

void RosWrapper::RosPrintSensorMessage(const SensorFusion::SensorDataMsg::ConstPtr& message)
{   
    ROS_INFO("Object Count [%d]",message->object_count_);
    std::vector<SensorPoint> points = message->sensor_list_data_;
    for(auto& point : points)
    {
      ROS_INFO("Object x_position_ [%f] y_position_ [%f]", point.x_position_,point.y_position_); 
    }   
}

}

