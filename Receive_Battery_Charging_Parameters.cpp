#include "Receive_Battery_Charging_Parameters.hpp"

std::vector<int> batteryParameterReadingsFromString(std::string f_received_string)
{
  std::stringstream received_string_stream;
  // std::string f_received_string = " Sending Battery/Charging parameters: 10 V, 20 A Sending Battery/Charging
  // parameters: 41 V, 52 A";

  // store the string to string stream
  received_string_stream << f_received_string;

  // declare vector
  std::vector<int> battery_parameter_readings;

  std::string temporary_string;
  int number;
  while (!received_string_stream.eof())
  {
    // for getting each word in the string
    received_string_stream >> temporary_string;

    // check for integers
    if (std::stringstream(temporary_string) >> number)
    {
      // if it is an integer value will be pushed to the vector
      battery_parameter_readings.push_back(number);
    }
  }
  return battery_parameter_readings;
}

bool isBatteryParameterWithinLimits(int f_variable, int f_minval, int f_max_val)
{
  if (f_variable < f_minval || f_variable > f_max_val)
  {
    return false;
  }
  else
  {
    return true;
  }
}
