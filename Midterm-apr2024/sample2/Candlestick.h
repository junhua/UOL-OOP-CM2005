#pragma once

#include <string>
#include <vector>
#include "WeatherEntry.h"

class Candlestick
{
public:
    Candlestick(std::pair<std::string, std::vector<double>> data, double open);

    double high, low, open, close;
    std::string date;
    CountryCode cc;
};

