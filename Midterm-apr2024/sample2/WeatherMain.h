#pragma once

#include "Candlestick.h"
#include "WeatherEntries.h"
#include <numeric>
#include <algorithm>

class WeatherMain
{
public:
    WeatherMain();
    void init();
    void printMenu();
    void handleCandlestick();
    void handlePrediction();
    void plotCandlesticks(const std::vector<Candlestick> &candlesticks);
    void predictAndPlotTemperature();

private:
    WeatherEntries weatherEntries;
};