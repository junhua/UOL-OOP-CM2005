#pragma once
#include "WeatherEntry.h"
#include <vector>

class WeatherEntries
{
public:
    WeatherEntries() {}
    WeatherEntries(std::vector<WeatherEntry> entries) : entries(entries) {}
    std::vector<WeatherEntry> entries;
};