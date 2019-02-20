#ifndef _OUTPUT_DISPLAY_H_
#define _OUTPUT_DISPLAY_H_

#include <string>

namespace SensorFusion
{
    

class IOutputDisplay
{
  public:
    IOutputDisplay() = default;
    virtual ~IOutputDisplay() {}
    virtual void listen(const std::string & topics) = 0;
    virtual void display(const std::string & topics) = 0;        
    virtual void Initialize(int argc, char** argv,const std::string & name) = 0;
};

}

#endif  //_OUTPUT_DISPLAY_H_