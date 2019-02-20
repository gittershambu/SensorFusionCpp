#ifndef _SHORT_RANGE_SENSOR_DATA_
#define _SHORT_RANGE_SENSOR_DATA_

#include "ISensor.h"
#include <memory>

namespace SensorFusion
{

class IInputAdaptor;
class RosWrapper;
class ShortRangeSensorData : public ISensor
{
public:
    ShortRangeSensorData(std::shared_ptr<IInputAdaptor> in, std::shared_ptr<RosWrapper> out);
    ~ShortRangeSensorData();
    virtual void Send();
private :
    std::shared_ptr<IInputAdaptor>      input_;
    std::shared_ptr<RosWrapper>     output_;

};

}

#endif // _SHORT_RANGE_SENSOR_DATA_
