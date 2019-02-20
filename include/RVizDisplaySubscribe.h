#ifndef _RVIZ_DISPLAY_H_
#define _RVIZ_DISPLAY_H_

#include "OutputDisplay.h"
#include "RosSensorMsg.h"
#include "RosSensorPointMsg.h"

#include <ros/ros.h>
#include <ros/time.h>
#include <visualization_msgs/MarkerArray.h>
#include "RVizMarker.h"

namespace SensorFusion
{
    
class RVizDisplaySubscribe : public IOutputDisplay
{
  public:
    RVizDisplaySubscribe();
    virtual ~RVizDisplaySubscribe() {}
    virtual void listen(const std::string & topics);
    virtual void display(const std::string & topics);
    virtual void Initialize(int argc, char** argv,const std::string & name);
    void FunctionCallback(const SensorFusion::SensorDataMsg::ConstPtr& message);
    void SetColor(const std::string & topics);
    void ResetMarker();
  private:
    ros::Subscriber subscriber_;
    ros::Publisher publisher_;
    ros::NodeHandle node_handle_;
    static const int queue_size = 100;
    std::string subscribe_topic_name_;
    std::string publish_topic_name_;
    visualization_msgs::MarkerArray marker_array_;
    RVizMarker rviz_marker_;
};

}

#endif  //_RVIZ_DISPLAY_H_