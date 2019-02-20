#include "common.h"
#include "ShortRangeSensorData.h"
#include "InputAdaptor.h"
#include "SensorData.h"
#include "RosWrapper.h"
#include "CsvInputAdaptor.h"
#include "ISensor.h"


namespace SensorFusion
{
    
ShortRangeSensorData::ShortRangeSensorData(std::shared_ptr<IInputAdaptor> in, std::shared_ptr<RosWrapper> out) : input_(in),output_(out)
{
}

ShortRangeSensorData::~ShortRangeSensorData()
{
}

void ShortRangeSensorData::Send()
{
   const std::list<std::unique_ptr<SensorDataMsg>>& sensor_datas = input_->parseFile().GetSensorData();
   for(auto& sensor_data : sensor_datas)
   {
      output_->RosPublish(*sensor_data);
      //output_->RosPrintInt((*sensor_data).timestamp_);
      output_->RosSleep();
   }
}

}


int main(int argc, char **argv)
{
  std::shared_ptr<SensorFusion::IInputAdaptor> csv_reader =  std::make_shared<SensorFusion::CsvInputAdaptor>(SensorFusion::short_range_csv_path);
  std::shared_ptr<SensorFusion::RosWrapper> ros_sender =  std::make_shared<SensorFusion::RosWrapper>();
  std::unique_ptr<SensorFusion::ISensor> long_range_sensor =  std::make_unique<SensorFusion::ShortRangeSensorData>(csv_reader, ros_sender);
  //ros_sender->RosPrintString("test");
  ros_sender->RosInit(argc, argv, "ShortRangeNodeSensor");
  ros_sender->CreateRosHandle();
  ros_sender->CreateRosPublisher("ShortRangeSensor",100);
  ros_sender->SetLoopRate(10);
  long_range_sensor->Send();
  ros_sender->RosSpin();
  return 0;
}
