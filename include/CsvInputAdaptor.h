#ifndef _CSV_INPUT_ADAPTER_
#define _CSV_INPUT_ADAPTER_

#include "InputAdaptor.h"
#include <vector>


namespace SensorFusion
{


class CsvInputAdaptor : public IInputAdaptor
{
public:
    CsvInputAdaptor(const std::string& source);
    ~CsvInputAdaptor();
   

    const SensorDataOperation& parseFile() ;   
    void ParseLineWithDelimiter(const std::string& stringdata);
    //const SensorDataOperation& GetSensorDataOperation() const { return sensor_operation_;}
private:
    std::string    filename_;
    std::vector<std::string> csv_data_; 
    SensorDataOperation sensor_operation_;

};

}

#endif // _CSV_INPUT_ADAPTER_
