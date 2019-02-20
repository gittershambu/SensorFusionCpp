#include "SensorDataOperation.h"
#include "SensorData.h"
#include <sstream>

namespace SensorFusion
{
    
  
SensorDataOperation::SensorDataOperation()
{
}

SensorDataOperation::~SensorDataOperation()
{
  sensor_object_detected_list_data_.clear();
  sensor_data_list_.clear();
}

void SensorDataOperation::SetSensorData(const std::vector<std::string>& csv_data)
{
    if(csv_data.size() == data_size_valid)
    {
     
      std::stringstream timestamp_convert(csv_data[csv_timestamp_position]);  
      uint64_t timestamp;  
      timestamp_convert >> timestamp;
      uint64_t object_id;
      std::stringstream object_id_convert(csv_data[csv_object_id_position]);
      object_id_convert>>object_id;
      double x_position;
      std::stringstream x_value_convert(csv_data[csv_x_position]);
      x_value_convert>>x_position;
      double y_position;
      std::stringstream y_value_convert(csv_data[csv_y_position]);
      y_value_convert>>y_position;
       

      SensorPoint* sensor_data_point_pointer =  new SensorPoint(object_id,x_position,y_position);
      if(timestamp == current_timestamp_)
      {
        object_count_ += 1;
        sensor_object_detected_list_data_.push_back(std::move(*sensor_data_point_pointer));
      }
      else
      {
        current_timestamp_ = timestamp;        
        single_timestamp_occurance_check_count_ += 1;       
        if(single_timestamp_occurance_check_ != single_timestamp_occurance_check_count_)
        {
           sensor_object_detected_list_data_.push_back(std::move(*sensor_data_point_pointer));           
        } 
      }

      if( single_timestamp_occurance_check_count_ % single_timestamp_occurance_check_ == 0)
      {
        std::unique_ptr<SensorDataMsg> sensor_data_pointer = std::make_unique<SensorDataMsg>(current_timestamp_,object_count_,sensor_object_detected_list_data_);     
        sensor_data_list_.push_back(std::move(sensor_data_pointer));
        sensor_object_detected_list_data_.clear();
        sensor_object_detected_list_data_.push_back(std::move(*sensor_data_point_pointer));    
        single_timestamp_occurance_check_count_ = 1;
        object_count_ = 1;
      }
   
      delete sensor_data_point_pointer;
     
    }
}
    
}

