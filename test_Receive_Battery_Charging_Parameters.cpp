#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "Receive_Battery_Charging_Parameters.hpp"

TEST_CASE("Test case for Received Battery paramter within limits")
{
    float min_val = 0.0;
    float max_val = 95.0;

    std::vector<float> temperature_reading = {0.0, 45.1, 45.0, 10.1, 3.0, 7.5, 8.7, 23.4, 56.8, 3.2,
                                              3, 20.0, 80.1, 80.0, 56.0, 45.8, 9.1, 23.7, 10.5, 60.2,
                                              45.0, 10.1, 3.0, 7.5, 73.5, 80.1, 80.0, 56.0, 45.8, 90.4,
                                              10.1, 3.0, 7.5, 8.7, 23.4, 4.2, 30.5, 18.5, 56.2, 62.4,
                                              45.8, 9.1, 23.7, 7.3, 34.4, 35.8, 45.8, 52.6, 17.5, 23.6};

    for (int iterator = 0; iterator < static_cast<int>(temperature_reading.size()); iterator++)
    {
        REQUIRE(isBatteryParameterWithinLimits(temperature_reading.at(iterator), min_val, max_val) == true);
    }
}
TEST_CASE("Test case for string to vector")
{
}

TEST_CASE("Test case for checking number of Received Battery paramter")
{
}

TEST_CASE("Test case for max in given set of Battery paramters")
{
}

TEST_CASE("Test case for min in given set of Battery paramters")
{
}

TEST_CASE("Test case Moving Average ")
{
}
