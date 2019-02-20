#include "RVizDisplaySubscribe.h"

#include "RosWrapper.h"


namespace SensorFusion
{
    
RVizDisplaySubscribe::RVizDisplaySubscribe()
{

}

void RVizDisplaySubscribe::SetColor(const std::string & topics)
{
    //Below code is hard coded , Needs to optmizise below code
   if(topics.compare("rviz_visual_tools_camera") == 0)
   {
       rviz_marker_.SetColor(0.0f,1.0f,0.0f,1.0f);
   }
   else if(topics.compare("rviz_visual_tools_short_range") == 0)
   {
       rviz_marker_.SetColor(1.0f,0.0f,0.0f,1.0f);
   }
   else if(topics.compare("rviz_visual_tools_long_range") == 0)
   {
       rviz_marker_.SetColor(0.0f,0.0f,1.0f,1.0f);
   }
   else
   {

   }
}

void RVizDisplaySubscribe::ResetMarker()
{
     marker_array_.markers.push_back(rviz_marker_.ResetMarker("/my_frame","sensor_fusion"));
    publisher_.publish(marker_array_); 
}

void RVizDisplaySubscribe::display(const std::string & topics)
{
   publish_topic_name_ = topics;   
   publisher_ = node_handle_.advertise<visualization_msgs::MarkerArray>(publish_topic_name_, 1);  
   SetColor(topics);   
}

void RVizDisplaySubscribe::listen(const std::string & topics)
{
   subscribe_topic_name_ = topics;
   subscriber_ = node_handle_.subscribe(subscribe_topic_name_, queue_size, &RVizDisplaySubscribe::FunctionCallback,this);   
}

void RVizDisplaySubscribe::Initialize(int argc, char** argv,const std::string & name)
{
    ros::init(argc,argv, name);
}

void RVizDisplaySubscribe::FunctionCallback(const SensorFusion::SensorDataMsg::ConstPtr& message)
{
   
    ResetMarker();

    marker_array_.markers.push_back(rviz_marker_.CreateTextMarker("/my_frame","sensor_fusion","Car_Reference"));
    publisher_.publish(marker_array_); 

    ROS_INFO("Topics name %s Object Count [%d]",subscribe_topic_name_.c_str(),message->object_count_);
    std::vector<SensorFusion::SensorPoint> points = message->sensor_list_data_;
    for(auto& point : points)
    {
        ROS_INFO("Topics name %s x_position_ [%f] y_position_ [%f]", subscribe_topic_name_.c_str(),point.x_position_,point.y_position_);
        
        //Below code is hard coded , Needs to optmizise below code
        if(subscribe_topic_name_.compare("CameraSensor") == 0)
        {
            marker_array_.markers.push_back(rviz_marker_.CreateCubeMarker("/my_frame","sensor_fusion",point.x_position_,point.y_position_));
        }
        else if(subscribe_topic_name_.compare("ShortRangeSensor") == 0)
        {
             marker_array_.markers.push_back(rviz_marker_.CreateCylinderMarker("/my_frame","sensor_fusion",point.x_position_,point.y_position_));
        }
        else if(subscribe_topic_name_.compare("LongRangeSensor") == 0)
        {
             marker_array_.markers.push_back(rviz_marker_.CreateSphereMarker("/my_frame","sensor_fusion",point.x_position_,point.y_position_));
        }
        else
        {

        }
    } 

    publisher_.publish(marker_array_);  
    marker_array_.markers.clear();
}

}