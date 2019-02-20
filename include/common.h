#ifndef _COMMON_PATH_INCLUDE_HEADER_
#define _COMMON_PATH_INCLUDE_HEADER_

#include <string>

namespace SensorFusion
{
const std::string relative_test_path    = "src/sensor_fusion/test/testdata/";
const std::string& camera_csv_path      = relative_test_path + "onepoint.csv";
const std::string& long_range_csv_path  = relative_test_path + "onepoint.csv";
const std::string& short_range_csv_path = relative_test_path + "onepoint.csv";;
}

#endif //_COMMON_HEADER_
