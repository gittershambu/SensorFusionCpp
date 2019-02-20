#ifndef _RVIZ_VISUAL_NODE_
#define _RVIZ_VISUAL_NODE_




#include "RosSensorMsg.h"

namespace SensorFusion
{

// class RvizVisualNode
// {

// public:
//   RvizVisualNode() {}
//   RvizVisualNode(std::string&& base_frame, std::string&& marker_topic,ros::NodeHandle* nh);
//   void initialize();
//   ~RvizVisualNode() {}
//   void loadMarkerPub(bool wait_for_subscriber = false, bool latched = false);
//   bool publishMarkers(visualization_msgs::MarkerArray& markers);
//   bool publishMarker(visualization_msgs::Marker& marker);
//   bool waitForSubscriber(const ros::Publisher& pub, double wait_time = 0.5, bool blocking = false);
//   bool trigger();
//   bool loadRvizMarkers();
//   bool deleteAllMarkers();
//   void publishCameraMarker();
//   void publishCarMarker();
//   const ros::Rate& GetRate() const { return rate_; }
//   //void SensorFusionCallback(const SensorFusion::SensorDataMsg::ConstPtr& msg);
// private:
//   ros::NodeHandle* nh_;
//   ros::Publisher pub_rviz_markers_; 
//   visualization_msgs::MarkerArray markers_;
//   visualization_msgs::Marker car_reference_marker_;
//   visualization_msgs::Marker camera_marker_;
//   visualization_msgs::Marker srr_marker_;
//   visualization_msgs::Marker lrr_marker_;
//   visualization_msgs::Marker reset_marker_;
//   visualization_msgs::Marker text_marker_;
//   sensor_msgs::Range tolerance_marker_;
//   std::string marker_topic_;
//   std::string base_frame_;  
//   bool batch_publishing_enabled_ = true;
//   bool pub_rviz_markers_connected_ = false;
//   bool pub_rviz_markers_waited_ = false;
//   bool frame_locking_enabled_ = false;
//   ros::Duration marker_lifetime_;
//   ros::Rate rate_{1};
// };

}

#endif // _RVIZ_VISUAL_NODE_
