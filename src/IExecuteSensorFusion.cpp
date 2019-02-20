#include "IExecuteSensorFusion.h"
#include <iostream>
#include "IFusionStrategy.h"


namespace SensorFusion
{

IExecuteSensorFusion::IExecuteSensorFusion()
{
    sensor_data_["Camera"]= std::list<SensorDataMsg>();
    sensor_data_["ShortRangeSensor"]=std::list<SensorDataMsg>() ;
    sensor_data_["LongRangeSensor"]=std::list<SensorDataMsg>() ;
    fusion_output1 = std::make_unique<SensorDataMsg>();

}

void IExecuteSensorFusion::Process(const std::string& sensor_name, const SensorDataMsg& msg)
{
    // std::cout<<sensor_name <<":\t" << msg.timestamp_ << std::endl;
    PrepareData(sensor_name, msg);
    auto time_stamp =  GetSynchronizedTimeStamp();
    // std::cout << "timestamp " << time_stamp << std::endl;
    if (time_stamp >= 0)
    {
        PreFusion(time_stamp);
        SynchronizeSensorDataMsg(time_stamp);
        Fuse(time_stamp);
        RemoveSensorDataMsg(time_stamp);
        PostFusion(time_stamp);
        sync_time_stamp_ = time_stamp;
    }
}


void  IExecuteSensorFusion::PrepareData(std::string sensor_name, const SensorDataMsg& msg)
{
    sensor_data_[sensor_name].push_back(msg);
}

int  IExecuteSensorFusion::GetLatestTimeStamp(const std::string& sensor_name)
{
    if (sensor_data_.count( sensor_name ) == 0)
        return -1;
    else if (sensor_data_[sensor_name].size()== 0)
        return -1;
    else
    {
        return sensor_data_[sensor_name].back().timestamp_;
    }
}

int  IExecuteSensorFusion::GetEarliestTimeStamp(const std::string& sensor_name)
{
    if (sensor_data_.count( sensor_name ) == 0)
        return -1;
    else if (sensor_data_[sensor_name].size()== 0)
        return -1;
    else
    {
        return sensor_data_[sensor_name].front().timestamp_;
    }
}


int IExecuteSensorFusion::GetSynchronizedTimeStamp()
{
    auto t1 = GetEarliestTimeStamp("Camera");
    auto t2 = GetLatestTimeStamp("ShortRangeSensor");
    auto t3 = GetLatestTimeStamp("LongRangeSensor");
    // std::cout<<"t1=" << t1 << ";t2=" << t2 << "t3=" << t3 << std::endl;
    return (t1<= t2 && t1 <= t3) ? t1 : -1 ;
}


void IExecuteSensorFusion::RemoveSensorDataMsg(int time_stamp)
{
    for( auto&& [sensor_type, msg_list] : sensor_data_ )
        msg_list.remove_if([time_stamp](SensorDataMsg& n){ return n.timestamp_ <= time_stamp; });
}

void IExecuteSensorFusion::SynchronizeSensorDataMsg( int time_stamp)
{
    for( auto&& [sensor_name, msg_list] : sensor_data_ )
    {
        for (auto it = msg_list.begin(); it != msg_list.end(); it++)
        {
            if (it->timestamp_ == time_stamp)
                if (sensor_name == "Camera")
                {
                    fusion_input_.push_front(*it);
                }
                else
                {
                    fusion_input_.push_back(*it);
                }

        }
    }
    return;
}

void IExecuteSensorFusion::Fuse(int time_stamp)
{
    algo_->algorithm(fusion_input_, fusion_output_);
    algo_->algorithm(fusion_input_, fusion_output1);
}

}