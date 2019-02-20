#ifndef _LONG_RANGE_SENSOR_DATA_
#define _LONG_RANGE_SENSOR_DATA_

#include "ISensor.h"
#include <memory>

namespace SensorFusion
{

class IInputAdaptor;
class RosWrapper;
class LongRangeSensorData : public ISensor
{
public:
    LongRangeSensorData(std::shared_ptr<IInputAdaptor> in, std::shared_ptr<RosWrapper> out);
    ~LongRangeSensorData();
    virtual void Send();
private :
    std::shared_ptr<IInputAdaptor>      input_;
    std::shared_ptr<RosWrapper>     output_;

};

}

#endif // _LONG_RANGE_SENSOR_DATA_
