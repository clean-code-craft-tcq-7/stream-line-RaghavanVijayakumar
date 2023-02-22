#pragma once

#ifndef RECEIVE_BATTRERY_CHARGING_PARAMETERS
#define RECEIVE_BATTRERY_CHARGING_PARAMETERS


#include <algorithm>
#include <iostream>
#include <random>
#include <sstream>
#include <vector>

std::vector<int> batteryParameterReadingsFromString(std::string f_received_string);

bool isBatteryParameterWithinLimits(int f_varible, int f_minval, int f_max_val);

std::vector<int> separatingBatteryParameters(std::vector<int> f_battery_parameter_readings, int f_position_of_paramter,
                                             int f_number_of_parameters);

int maximumOfBatteryParameterReadings(std::vector<int> f_battery_parameter_readings);

int minimumOfBatteryParameterReadings(std::vector<int> f_battery_parameter_readings);

#endif
