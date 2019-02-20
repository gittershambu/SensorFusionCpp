///
/// KPIT
///

#ifndef _SLOWFUSIONSTRATEGY_H_ 
#define _SLOWFUSIONSTRATEGY_H_ 

#include "IFusionStrategy.h"


namespace SensorFusion
{


class SlowFusionStrategy : public IFusionStrategy  
{
public:
    SlowFusionStrategy(double tolerance) :  IFusionStrategy(tolerance){}
    virtual void  algorithm(const   std::list<SensorDataMsg>& fusion_in, 
                                    SensorDataMsg& fusion_out) override;
    virtual void  algorithm(const   std::list<SensorDataMsg>& fusion_in, 
                                    std::unique_ptr<SensorDataMsg>& fusion_out) override;
};

} // SensorFusion
#endif // _SLOWFUSIONSTRATEGY_H_ 