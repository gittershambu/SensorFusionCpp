///
/// KPIT
///
#ifndef _ADAPTOR_H_
#define _ADAPTOR_H_

#include "SensorDataOperation.h"

#include <list>
#include <string>

// inspired by Adaptor Design pattern of GOF


namespace SensorFusion
{
    

class IInputAdaptor
{
  public:
    IInputAdaptor();
    virtual ~IInputAdaptor() {}
    // virtual std::list<double> GetCurrentSensorData()= 0;
    virtual const SensorDataOperation& parseFile() = 0;
    //void SetInput(const std::string& source) { filename_ = source; }
    //std::string GetInput(){return filename_; }
};

}

#endif  //_ADAPTOR_H_