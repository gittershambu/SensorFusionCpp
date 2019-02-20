#include "CsvInputAdaptor.h"
#include <algorithm>  // copy
#include <boost/tokenizer.hpp>
#include <fstream>   // fstream
#include <iostream>  // cout, endl
#include <iterator>  // ostream_operator
#include <string>
#include <vector>

namespace SensorFusion {

CsvInputAdaptor::CsvInputAdaptor(const std::string& source)
    : filename_(source), sensor_operation_() {}

CsvInputAdaptor::~CsvInputAdaptor() {}

// const SensorDataOperation& CsvInputAdaptor::parseFile() {
//   std::ifstream file(filename_);
//   std::string line;
//   while (std::getline(file, line)) {
//     ParseLineWithDelimiter(line);
//   }
//   return sensor_operation_;
// }

// void CsvInputAdaptor::ParseLineWithDelimiter(const std::string& stringdata) {
//   csv_data_.clear();
//   std::string cell_data;
//   std::stringstream split(stringdata);
//   while (getline(split, cell_data, ',')) {
//     csv_data_.push_back(cell_data);
//   }
//   sensor_operation_.SetSensorData(csv_data_);
// }

const SensorDataOperation& CsvInputAdaptor::parseFile() {
  std::string data(filename_);

  std::ifstream file(data.c_str());

  //   if (!file.is_open()) return 1;

  std::string line;

  while (getline(file, line)) {
    ParseLineWithDelimiter(line);
  }
  return sensor_operation_;
}

void CsvInputAdaptor::ParseLineWithDelimiter(const std::string& stringdata) {
  typedef boost::tokenizer<boost::escaped_list_separator<char> > Tokenizer;
  csv_data_.clear();
  std::vector<std::string> vec;
  Tokenizer tok(stringdata);
  vec.assign(tok.begin(), tok.end());

  for (auto v : vec) {
    csv_data_.push_back(v);
  }
  sensor_operation_.SetSensorData(csv_data_);
}

}  // namespace SensorFusion