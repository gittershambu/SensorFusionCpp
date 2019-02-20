#ifndef _SENSOR_FUSION_NODE_
#define _SENSOR_FUSION_NODE_

#include "ISensor.h"
#include <memory>

namespace SensorFusion
{

class IExecuteSensorFusion;
class IInputAdaptor;
class RosWrapper;
class IFusionStrategy;

class SensorFusionNode
{
public:
    SensorFusionNode();
// protected: 
    std::shared_ptr<IExecuteSensorFusion> fusion_;
    std::shared_ptr<IFusionStrategy>      algo_;

};

}

#endif // _SENSOR_FUSION_NODE_
