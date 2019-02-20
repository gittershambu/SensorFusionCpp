///
/// KPIT
///

#ifndef _IFUSIONSTRATEGY_H_ 
#define _IFUSIONSTRATEGY_H_ 

#include "RosSensorMsg.h"

namespace SensorFusion
{

class IFusionStrategy
{
public:
    IFusionStrategy(double tolerance) : tolerance_(tolerance) {}
    virtual void  algorithm(const   std::list<SensorDataMsg>& fusion_in, 
                                    SensorDataMsg& fusion_out) = 0 ;
    virtual void  algorithm(const   std::list<SensorDataMsg>& fusion_in, 
                                std::unique_ptr<SensorDataMsg>& fusion_out)= 0;
protected:
    double tolerance_{0.5};
};

};
#endif // _IFUSIONSTRATEGY_H_ 
