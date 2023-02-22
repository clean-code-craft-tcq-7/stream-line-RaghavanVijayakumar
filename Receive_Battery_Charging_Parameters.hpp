#pragma once

#ifndef RECEIVE_BATTRERY_CHARGING_PARAMETERS
#define RECEIVE_BATTRERY_CHARGING_PARAMETERS

#include <iostream>
#include <random>
#include <sstream>
#include <vector>

std::vector<int> batteryParameterReadingsFromString(std::string f_received_string);

bool isBatteryParameterWithinLimits(int f_varible, int f_minval, int f_max_val);

#endif
