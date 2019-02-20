

#include "RvizVisualNode.h"
#include "RosWrapper.h"
#include "RosSensorMsg.h"
#include "RosSensorPointMsg.h"
#include "RVizDisplaySubscribe.h"



int main( int argc, char** argv )
{
  ros::init(argc, argv, "visual_sensor_fusion_node");

  SensorFusion::RVizDisplaySubscribe camera_display_instance;
  camera_display_instance.listen("CameraSensor");
  camera_display_instance.display("rviz_visual_tools_camera");

  SensorFusion::RVizDisplaySubscribe short_range_display_instance;
  short_range_display_instance.listen("ShortRangeSensor");
  short_range_display_instance.display("rviz_visual_tools_short_range");


  SensorFusion::RVizDisplaySubscribe long_range_display_instance;
  long_range_display_instance.listen("LongRangeSensor");
  long_range_display_instance.display("rviz_visual_tools_long_range");

  ros::Rate loop_rate(1);
  ros::spinOnce();
  while (ros::ok()) 
  {
    ros::spinOnce();
		loop_rate.sleep();
  }
  
return 0;
 
}
