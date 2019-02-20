#include "SlowFusionStrategy.h"
#include <iostream>
#include <iterator>
#include <math.h>

namespace SensorFusion
{
static void ResetSensorDataMsg(SensorDataMsg &msg)
{
        msg.object_count_ = 0;
        msg.timestamp_ = -1;
        msg.sensor_list_data_.clear();
}

static double GetDistance(const SensorPoint &p1, const SensorPoint &p2)
{
        return sqrt((p1.x_position_ - p2.x_position_) * (p1.x_position_ - p2.x_position_) +
                    (p1.y_position_ - p2.y_position_) * (p1.y_position_ - p2.y_position_));
}

// input assumption: the first element of list is the main sensor data (from camera)
void SlowFusionStrategy::algorithm(const std::list<SensorDataMsg> &fusion_in,
                                   SensorDataMsg &fusion_out)
{
        ResetSensorDataMsg(fusion_out);
        auto main_sensor_data_msg = fusion_in.front();
        auto iter = fusion_in.begin();

        // init output
        if (fusion_in.size() <= 1)
                return;

        for (auto i = 0; i < main_sensor_data_msg.object_count_; i++)
        {
                auto selected_main_sensor_point_index = -1;
                auto selected_ref_sensor_point_index = -1;
                double min_distance = tolerance_;
                auto selected_iter = iter;
                for (std::advance(iter, 1) /*second element in list*/; iter != fusion_in.end(); ++iter)
                {
                        for (auto j = 0; j < iter->object_count_; j++)
                        {
                                auto distance = GetDistance(main_sensor_data_msg.sensor_list_data_[i], iter->sensor_list_data_[j]);
                                if (distance <= min_distance)
                                {
                                        selected_main_sensor_point_index = i;
                                        selected_ref_sensor_point_index = j;
                                        selected_iter = iter;
                                        min_distance = distance;
                                }
                        }
                }
                if (selected_main_sensor_point_index >= 0) // sensor point machted
                {
                        fusion_out.object_count_++;
                        fusion_out.sensor_list_data_.push_back(main_sensor_data_msg.sensor_list_data_[selected_main_sensor_point_index]);
                }
        }
        if (fusion_out.object_count_ > 0)
                fusion_out.timestamp_ = main_sensor_data_msg.timestamp_;
        return;
}

void  SlowFusionStrategy::algorithm(const   std::list<SensorDataMsg>& fusion_in, 
                                std::unique_ptr<SensorDataMsg>& fusion_out)
{

}

} // namespace SensorFusion