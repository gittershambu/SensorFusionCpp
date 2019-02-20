///
/// KPIT
///

#ifndef _IEXECUTESENSORFUSION_H_
#define _IEXECUTESENSORFUSION_H_

#include <string>
#include <memory>
#include "RosSensorMsg.h"

namespace SensorFusion
{
class IFusionStrategy;

// inspired by Design Pattern Template of GOF
class IExecuteSensorFusion
{
public:
    IExecuteSensorFusion();
    void Process(const std::string& sensor_name, const SensorDataMsg& msg);
    void SetFusionStrategy(std::shared_ptr<IFusionStrategy> algo)  { algo_ = algo;}
    
protected:
    std::map<std::string, std::list<SensorDataMsg> > sensor_data_;   
    std::list<SensorDataMsg>    fusion_input_;
    SensorDataMsg               fusion_output_;
    std::unique_ptr<SensorDataMsg> fusion_output1;
    int                         sync_time_stamp_{-1};   

private:
    //steps
    virtual void        PrepareData(std::string ros_topic, const SensorDataMsg& sensor_data) = 0;
    virtual void        PreFusion(int  time_stampe) = 0;
    virtual void        Fuse(int time_stampe);
    virtual void        PostFusion(int time_stampe) = 0;
    
    
    // help function
    void                RemoveSensorDataMsg(int time_stampe);  
    int                 GetSynchronizedTimeStamp(void);
    void                SynchronizeSensorDataMsg(int time_stamp);
    int                 GetLatestTimeStamp(const std::string& sensor_name);
    int                 GetEarliestTimeStamp(const std::string& sensor_name);    

    //vars  
   std::shared_ptr<IFusionStrategy> algo_;      
};

}

#endif // _IEXECUTESENSORFUSION_H_
