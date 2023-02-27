#include "Receive_Battery_Charging_Parameters.hpp"

int main()
{
  std::vector<int> battery_parameter_readings = { 20, 52, 2,  58, 5,  10, 41, 5, 7, 48, 5,  1, 5,
                                                  6,  45, 10, 20, 41, 52, 5,  2, 7, 58, 48, 5 };

  int range_length = 5;

  std::cout << "Moving Average for readings: " << movingAverage(battery_parameter_readings, range_length) << "\n";

  return 0;
}