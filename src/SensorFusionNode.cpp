#include "SensorFusionNode.h"
#include "SensorData.h"
#include "RosWrapper.h"
#include "CsvInputAdaptor.h"
#include "ISensor.h"
#include <memory>
#include "RosSensorMsg.h"
#include "DemoExecuteSensorFusion.h"
#include "SlowFusionStrategy.h"

      
SensorFusion::SensorFusionNode::SensorFusionNode()
{
    fusion_= std::make_shared<DemoExecuteSensorFusion>();
    algo_  = std::make_shared<SlowFusionStrategy>(0.5);
    fusion_->SetFusionStrategy(algo_);
}



std::shared_ptr<SensorFusion::RosWrapper> g_camera_ros_print; //test code it will removed later
std::shared_ptr<SensorFusion::RosWrapper> g_srr_ros_print; //test code it will removed later
std::shared_ptr<SensorFusion::RosWrapper> g_lrr_ros_print; //test code it will removed later
SensorFusion::SensorFusionNode  g_node;

void CameraSensorFusionCallback(const SensorFusion::SensorDataMsg::ConstPtr& msg)
{
  // g_camera_ros_print->RosPrintString("camera");
  //g_srr_ros_print->RosPrintSensorMessage(msg);
  g_camera_ros_print->RosPrintInt(msg->timestamp_); //test code it will removed lateralg
  g_node.fusion_->Process("Camera", *msg);
}

void ShortRangeSensorFusionCallback(const SensorFusion::SensorDataMsg::ConstPtr& msg)
{
   //g_srr_ros_print->RosPrintSensorMessage(msg);
   //g_srr_ros_print->RosPrintInt(msg->timestamp_); //test code it will removed later
  g_node.fusion_->Process("ShortRangeSensor", *msg);
}

void LongRangeSensorFusionCallback(const SensorFusion::SensorDataMsg::ConstPtr& msg)
{
   //g_srr_ros_print->RosPrintString("lrr");
   //g_srr_ros_print->RosPrintSensorMessage(msg);
   //cg_lrr_ros_print->RosPrintInt(msg->timestamp_); //test code it will removed later
   g_node.fusion_->Process("LongRangeSensor", *msg);
}


int main(int argc, char **argv)
{
  std::shared_ptr<SensorFusion::RosWrapper> ros_camera_subcribe = std::make_shared<SensorFusion::RosWrapper>();
  ros_camera_subcribe->RosInit(argc, argv, "CameraSensorFusion");
  ros_camera_subcribe->CreateRosHandle();
  ros_camera_subcribe->CreateRosSubscriber("CameraSensor",100,CameraSensorFusionCallback);

  std::shared_ptr<SensorFusion::RosWrapper> ros_short_range_subcribe = std::make_shared<SensorFusion::RosWrapper>();
  ros_short_range_subcribe->RosInit(argc, argv, "ShortRangeSensorFusion");
  ros_short_range_subcribe->CreateRosHandle();
  ros_short_range_subcribe->CreateRosSubscriber("ShortRangeSensor",100,ShortRangeSensorFusionCallback);

  std::shared_ptr<SensorFusion::RosWrapper> ros_long_range_subcribe = std::make_shared<SensorFusion::RosWrapper>();
  ros_long_range_subcribe->RosInit(argc, argv, "LongRangeSensorFusion");
  ros_long_range_subcribe->CreateRosHandle();
  ros_long_range_subcribe->CreateRosSubscriber("LongRangeSensor",100,LongRangeSensorFusionCallback);
  
  g_camera_ros_print = ros_camera_subcribe;
  g_srr_ros_print = ros_short_range_subcribe;
  g_lrr_ros_print = ros_long_range_subcribe;
  ros_camera_subcribe->RosSpin();
  ros_short_range_subcribe->RosSpin();  
  ros_long_range_subcribe->RosSpin();     
  return 0;
}
