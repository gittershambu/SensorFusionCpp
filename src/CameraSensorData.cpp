#include "common.h"
#include "CameraSensorData.h"
#include "InputAdaptor.h"
#include "SensorData.h"
#include "RosWrapper.h"
#include "CsvInputAdaptor.h"
#include "ISensor.h"
#include <memory>

namespace SensorFusion
{
    
CameraSensorData::CameraSensorData(std::shared_ptr<IInputAdaptor>  in, std::shared_ptr<RosWrapper> out) : input_(in),output_(out)
{
}

CameraSensorData::~CameraSensorData()
{
}

void CameraSensorData::Send()
{
   const std::list<std::unique_ptr<SensorDataMsg>>& sensor_datas = input_->parseFile().GetSensorData();
   output_->RosPrintSensorMessage(sensor_datas);
   for(auto& sensor_data : sensor_datas)
   {
      output_->RosPublish(*sensor_data);      
      output_->RosSleep();
   }
}

}

int main(int argc, char **argv)
{
  std::shared_ptr<SensorFusion::IInputAdaptor> csv_reader =  std::make_shared<SensorFusion::CsvInputAdaptor>(SensorFusion::short_range_csv_path);
  std::shared_ptr<SensorFusion::RosWrapper> ros_sender =  std::make_shared<SensorFusion::RosWrapper>();
  std::unique_ptr<SensorFusion::ISensor> camera =  std::make_unique<SensorFusion::CameraSensorData>(csv_reader, ros_sender);
  ros_sender->RosInit(argc, argv, "CameraNodeSensor");
  ros_sender->CreateRosHandle();
  ros_sender->CreateRosPublisher("CameraSensor",100);
  ros_sender->SetLoopRate(10);
  camera->Send();
  ros_sender->RosSpin();  
  return 0;
}
