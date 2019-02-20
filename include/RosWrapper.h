#ifndef _ROS_WRAPPER_
#define _ROS_WRAPPER_

#include <ros/ros.h>
#include <ros/time.h>
#include <string>
#include <std_msgs/String.h>
#include <memory>
#include "RosSensorMsg.h"

typedef void (*callback_function_pointer)(const SensorFusion::SensorDataMsg::ConstPtr& msg);
namespace SensorFusion
{

class SensorData;
class RosWrapper
{
public:
    RosWrapper();
    ~RosWrapper() {}
    
    void RosInit(int argc, char** argv,const std::string & name);
    void RosSpin();  
    void RosSpinOnce();   
    void CreateRosHandle();
    void CreateRosPublisher(const std::string& topics, int queue_size);
    void SetLoopRate(int loop_rate);
    void RosSleep() { ros_loop_rate->sleep(); }
    void RosPublish(const SensorDataMsg& data);
    void CreateRosSubscriber(const std::string& topics, int queue_size,callback_function_pointer ptr);
    void RosPrintString(const std::string & print_message);
    void RosPrintDouble(double  print_message);
    void RosPrintInt(int print_message);
    void RosPrintMessageInt(const std::string & print_message,int print_int_message);
    void RosPrintMessageDouble(const std::string & print_message,double print_int_message);
    void RosPrintSensorMessage(const std::list<std::unique_ptr<SensorDataMsg>>& sensor_datas);
    void RosPrintSensorMessage(const SensorFusion::SensorDataMsg::ConstPtr& message);
    const std::unique_ptr<ros::NodeHandle>&  GetRosHandle() const { return node_handle_;}
private:
    std::unique_ptr<ros::NodeHandle> node_handle_;
    ros::Publisher ros_publisher_handle_;
    std::unique_ptr<ros::Rate> ros_loop_rate;
    ros::Subscriber ros_subscriber_handle_;

};

}

#endif // _ROS_WRAPPER_
