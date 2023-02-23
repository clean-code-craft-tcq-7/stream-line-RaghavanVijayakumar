#include "Receive_Battery_Charging_Parameters.hpp"

int main()
{
  std::vector<int> battery_parameter_readings1 = { 20, 52, 2, 58, 5 };
  std::vector<int> battery_parameter_readings2 = { 10, 41, 5, 7, 48, 5 };
  int expected_output1 = 5, expected_output2 = 2;
  int range_length = 5;

  std::cout << "Moving Average for readings1: " << movingAverage(battery_parameter_readings1, range_length) << "\n";

  std::cout << "Moving Average for readings1: " << movingAverage(battery_parameter_readings2, range_length) << "\n";

  return 0;
}