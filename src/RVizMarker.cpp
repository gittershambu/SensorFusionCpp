#include "RVizMarker.h"

namespace SensorFusion
{

int RVizMarker::count_camera = 0;
int RVizMarker::count_short_range = 0;
int RVizMarker::count_long_range = 0;

const visualization_msgs::Marker& RVizMarker::ResetMarker(const std::string& frame_id , const std::string& shape_namespace)
{ 
  draw_reset_marker_.header.frame_id = frame_id;
  draw_reset_marker_.header.stamp = ros::Time();
  draw_reset_marker_.ns = shape_namespace;
  draw_reset_marker_.action = 3;               
  draw_reset_marker_.pose.orientation.w = 1;
  return draw_reset_marker_;
}




const visualization_msgs::Marker&  RVizMarker::CreateCubeMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position)
{       
	draw_cube_marker_.header.frame_id = frame_id;
	draw_cube_marker_.header.stamp = ros::Time::now();
	draw_cube_marker_.ns = shape_namespace;
	draw_cube_marker_.id = count_camera++;
	draw_cube_marker_.type = visualization_msgs::Marker::CUBE;
	draw_cube_marker_.action = visualization_msgs::Marker::ADD;
	draw_cube_marker_.pose.position.x = x_position;
	draw_cube_marker_.pose.position.y = y_position;
	draw_cube_marker_.pose.position.z = 0;
	draw_cube_marker_.pose.orientation.x = 0.0;
	draw_cube_marker_.pose.orientation.y = 0.0;
	draw_cube_marker_.pose.orientation.z = 0.0;
	draw_cube_marker_.pose.orientation.w = 1.0;

	draw_cube_marker_.scale.x = 1.0;
	draw_cube_marker_.scale.y = 1.0;
	draw_cube_marker_.scale.z = 1.0;

	draw_cube_marker_.color.r = red_;
	draw_cube_marker_.color.g = blue_;
	draw_cube_marker_.color.b = green_;
	draw_cube_marker_.color.a = alpha_;
    draw_cube_marker_.lifetime = ros::Duration(1);
    return draw_cube_marker_;
}

const visualization_msgs::Marker& RVizMarker::CreateCylinderMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position)
{     
	draw_cylinder_marker_.header.frame_id = frame_id;
	draw_cylinder_marker_.header.stamp = ros::Time::now();

	draw_cylinder_marker_.ns = shape_namespace;
	draw_cylinder_marker_.id = count_short_range++;

	draw_cylinder_marker_.type = visualization_msgs::Marker::CYLINDER;

	draw_cylinder_marker_.action = visualization_msgs::Marker::ADD;

	draw_cylinder_marker_.pose.position.x = x_position;
	draw_cylinder_marker_.pose.position.y = y_position;
	draw_cylinder_marker_.pose.position.z = 0;
	draw_cylinder_marker_.pose.orientation.x = 0.0;
	draw_cylinder_marker_.pose.orientation.y = 0.0;
	draw_cylinder_marker_.pose.orientation.z = 0.0;
	draw_cylinder_marker_.pose.orientation.w = 1.0;

	draw_cylinder_marker_.scale.x = 1.0;
	draw_cylinder_marker_.scale.y = 1.0;
	draw_cylinder_marker_.scale.z = 1.0;

	draw_cylinder_marker_.color.r = red_;
	draw_cylinder_marker_.color.g = blue_;
	draw_cylinder_marker_.color.b = green_;
	draw_cylinder_marker_.color.a = alpha_;
    draw_cylinder_marker_.lifetime = ros::Duration(1);
    return draw_cylinder_marker_;
}


const visualization_msgs::Marker& RVizMarker::CreateSphereMarker(const std::string& frame_id , const std::string& shape_namespace,double x_position,double y_position)
{       
	draw_sphere_marker_.header.frame_id = frame_id;
	draw_sphere_marker_.header.stamp = ros::Time::now();

	draw_sphere_marker_.ns = shape_namespace;
	draw_sphere_marker_.id = count_long_range++;
	draw_sphere_marker_.type = visualization_msgs::Marker::SPHERE;

	draw_sphere_marker_.action = visualization_msgs::Marker::ADD;

	draw_sphere_marker_.pose.position.x = x_position;
	draw_sphere_marker_.pose.position.y = y_position;
	draw_sphere_marker_.pose.position.z = 0;
	draw_sphere_marker_.pose.orientation.x = 0.0;
	draw_sphere_marker_.pose.orientation.y = 0.0;
	draw_sphere_marker_.pose.orientation.z = 0.0;
	draw_sphere_marker_.pose.orientation.w = 1.0;

	draw_sphere_marker_.scale.x = 1.0;
	draw_sphere_marker_.scale.y = 1.0;
	draw_sphere_marker_.scale.z = 1.0;

	draw_sphere_marker_.color.r = red_;
	draw_sphere_marker_.color.g = blue_;
	draw_sphere_marker_.color.b = green_;
	draw_sphere_marker_.color.a = alpha_;
    draw_sphere_marker_.lifetime = ros::Duration(1);
    return draw_sphere_marker_;
}

const visualization_msgs::Marker& RVizMarker::CreateTextMarker(const std::string& frame_id , const std::string& shape_namespace,const std::string& text_show)
{   
	draw_textmarker_.header.frame_id = frame_id;
	draw_textmarker_.header.stamp = ros::Time::now();
	draw_textmarker_.ns = shape_namespace;
	draw_textmarker_.id = 0;
	draw_textmarker_.type = visualization_msgs::Marker::TEXT_VIEW_FACING;
	draw_textmarker_.action = visualization_msgs::Marker::ADD;
	draw_textmarker_.pose.position.x = 0;
	draw_textmarker_.pose.position.y = 0;
	draw_textmarker_.pose.position.z = 0;
	draw_textmarker_.pose.orientation.x = 0.0;
	draw_textmarker_.pose.orientation.y = 0.0;
	draw_textmarker_.pose.orientation.z = 0.0;
	draw_textmarker_.pose.orientation.w = 1.0;
	draw_textmarker_.scale.x = 1.0;
	draw_textmarker_.scale.y = 1.0;
	draw_textmarker_.scale.z = 1.0;
	draw_textmarker_.color.r = 0.0;
	draw_textmarker_.color.g = 1.0;
	draw_textmarker_.color.b = 1.0;
	draw_textmarker_.color.a = 1.0;
    draw_textmarker_.lifetime = ros::Duration();
    draw_textmarker_.text = text_show;
    return draw_textmarker_;
}

void RVizMarker::SetColor(double red,double blue,double green,double alpha)
{
    red_ = red;
    blue_ = blue;
    green_ = green;
    alpha_ = alpha;
}

void RVizMarker::SetPosition(double x,double y)
{
    x_position_ = x;
    y_position_ = y;
}

}