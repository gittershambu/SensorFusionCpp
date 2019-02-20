#ifndef _INTERFACE_SENSOR_
#define _INTERFACE_SENSOR_


namespace SensorFusion
{


class ISensor
{
public:
    ISensor();
    virtual ~ISensor() {}
    virtual void Send() = 0;
};


}

#endif // _INTERFACE_SENSOR_
