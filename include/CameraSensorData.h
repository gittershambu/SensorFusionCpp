#ifndef _CAMERA_SENSOR_DATA_
#define _CAMERA_SENSOR_DATA_

#include "ISensor.h"
#include <memory>

namespace SensorFusion
{

class IInputAdaptor;
class RosWrapper;
class CameraSensorData : public ISensor
{
public:
    CameraSensorData(std::shared_ptr<IInputAdaptor>  in, std::shared_ptr<RosWrapper> out);
    ~CameraSensorData();
    virtual void Send();
private :
    std::shared_ptr<IInputAdaptor>  input_;
    std::shared_ptr<RosWrapper>    output_;

};

}

#endif // _CAMERA_SENSOR_DATA_
