
///
/// KPIT
///

#ifndef _DEMOEXECUTESENSORFUSION_H_
#define _DEMOEXECUTESENSORFUSION_H_

#include "IExecuteSensorFusion.h"

namespace SensorFusion
{
class RosWrapper;
class DemoExecuteSensorFusion : public IExecuteSensorFusion
{
public:
    DemoExecuteSensorFusion() : IExecuteSensorFusion() {}
    virtual void PrepareData(std::string ros_topic, const SensorDataMsg& sensor_data) override;
    virtual void PreFusion(int time_stampe) override;
    virtual void PostFusion(int time_stampe) override;
    std::shared_ptr<RosWrapper>  ros_output_;
};


}

#endif // _DEMOEXECUTESENSORFUSION_H_
