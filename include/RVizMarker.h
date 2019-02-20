#ifndef _RVIZ_MARKER_H_
#define _RVIZ_MARKER_H_

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <sensor_msgs/Range.h>

namespace SensorFusion
{

class RVizMarker
{
public:
RVizMarker() {}
~RVizMarker() {}
const visualization_msgs::Marker& ResetMarker(const std::string& frame_id , const std::string& shape_namespace);
const visualization_msgs::Marker& CreateCubeMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position);
const visualization_msgs::Marker& CreateCylinderMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position);
const visualization_msgs::Marker& CreateSphereMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position);
const visualization_msgs::Marker& CreateTextMarker(const std::string& frame_id , const std::string& shape_namespace,const std::string& text_show);
void SetColor(double red,double blue,double green,double alpha);
void SetPosition(double x,double y);

private:
visualization_msgs::Marker draw_reset_marker_;
visualization_msgs::Marker draw_cube_marker_;
visualization_msgs::Marker draw_cylinder_marker_;
visualization_msgs::Marker draw_sphere_marker_;
visualization_msgs::Marker draw_textmarker_;
double red_;
double blue_;
double green_;
double alpha_;
static int count_camera;
static int count_short_range;
static int count_long_range;
double x_position_;
double y_position_;

};

}

#endif //_RVIZ_MARKER_H_