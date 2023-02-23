#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receive_Battery_Charging_Parameters.hpp"

TEST_CASE("Test case for Received Battery paramter within limits")
{
  float min_val = 0.0;
  float max_val = 95.0;

  std::vector<float> temperature_reading = { 0.0,  45.1, 45.0, 10.1, 3.0,  7.5,  8.7,  23.4, 56.8, 3.2,
                                             3,    20.0, 80.1, 80.0, 56.0, 45.8, 9.1,  23.7, 10.5, 60.2,
                                             45.0, 10.1, 3.0,  7.5,  73.5, 80.1, 80.0, 56.0, 45.8, 90.4,
                                             10.1, 3.0,  7.5,  8.7,  23.4, 4.2,  30.5, 18.5, 56.2, 62.4,
                                             45.8, 9.1,  23.7, 7.3,  34.4, 35.8, 45.8, 52.6, 17.5, 23.6 };

  for (int iterator = 0; iterator < static_cast<int>(temperature_reading.size()); iterator++)
  {
    REQUIRE(isBatteryParameterWithinLimits(temperature_reading.at(iterator), min_val, max_val) == true);
  }
}
TEST_CASE("Test case for string to vector")
{
  std::vector<int> expected_battery_parameter_readings = { 10, 20, 41, 52 };
  int battery_current = 95;
  std::string received_string =
      "Sending Battery/Charging parameters: 10 V, 20 A Sending Battery/Charging parameters: 41 V, 52 A";
  REQUIRE(expected_battery_parameter_readings == batteryParameterReadingsFromString(received_string));
}

TEST_CASE("Test case for checking number of Received Battery paramter")
{
}

TEST_CASE("Test case for Separating Battery Parameters")
{
  int number_of_parameters = 2;
  int position_of_paramter1{ 1 }, position_of_paramter2{ 2 };

  std::vector<int> battery_parameter_readings = { 10, 20, 41, 52, 5, 2, 7, 58, 48, 5 };
  std::vector<int> voltage_readings = { 10, 41, 5, 7, 48 };
  std::vector<int> current_readings = { 20, 52, 2, 58, 5 };
  REQUIRE(voltage_readings ==
          separatingBatteryParameters(battery_parameter_readings, position_of_paramter1, number_of_parameters));
  REQUIRE(current_readings ==
          separatingBatteryParameters(battery_parameter_readings, position_of_paramter2, number_of_parameters));
}

TEST_CASE("Test case for max & min in given set of Battery paramters")
{
  std::vector<int> voltage_readings = { 12, 1, 5, 23, 48, 32 };
  std::vector<int> current_readings = { 20, 41, 2, 46, 28, 62 };

  // Max
  REQUIRE(48 == maximumOfBatteryParameterReadings(voltage_readings));
  REQUIRE(62 == maximumOfBatteryParameterReadings(current_readings));

  // Min
  REQUIRE(1 == minimumOfBatteryParameterReadings(voltage_readings));
  REQUIRE(2 == minimumOfBatteryParameterReadings(current_readings));
}

TEST_CASE("Test case Moving Average ")
{
  std::vector<int> battery_parameter_readings1 = { 20, 52, 2, 58, 5 };
  std::vector<int> battery_parameter_readings2 = { 10, 41, 5, 7, 48, 5 };
  int expected_output1 = 0, expected_output2 = 23;
  int range_length = 5;

  REQUIRE(expected_output1 == movingAverage(battery_parameter_readings1, range_length));

  REQUIRE(expected_output2 == movingAverage(battery_parameter_readings2, range_length));
}
