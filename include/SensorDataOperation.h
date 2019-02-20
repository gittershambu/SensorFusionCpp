#ifndef _SENSOR_DATA_OPERATION_
#define _SENSOR_DATA_OPERATION_

#include <memory>
#include <vector>
#include <list>

#include "RosSensorPointMsg.h"
#include "RosSensorMsg.h"
namespace SensorFusion
{

class SensorDataOperation
{
public:
    SensorDataOperation();
    ~SensorDataOperation();
    void SetSensorData(const std::vector<std::string>& csv_data);
    const std::list<std::unique_ptr<SensorDataMsg>>& GetSensorData()const { return sensor_data_list_; }
private:
    std::list<std::unique_ptr<SensorDataMsg>> sensor_data_list_;
    std::vector<SensorPoint> sensor_object_detected_list_data_; 
    uint32_t object_count_;
    uint64_t current_timestamp_{0};
    uint8_t single_timestamp_occurance_check_count_{0};
    static const unsigned data_size_valid = 4; 
    static const unsigned csv_timestamp_position = 3;
    static const unsigned csv_object_id_position = 0;
    static const unsigned csv_x_position = 1;
    static const unsigned csv_y_position = 2;
    static const unsigned single_timestamp_occurance_check_ = 2;
};

}

#endif // _SENSOR_DATA_OPERATION_
