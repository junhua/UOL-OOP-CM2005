#pragma once
#include "Candlestick.h"
#include "WeatherEntry.h"
#include "WeatherEntries.h"
#include <vector>
#include <string>


class Utility
{
public:
    static std::vector<Candlestick> computeCandlestick(WeatherEntries entries);
    static std::string ccToString(CountryCode cc);
    static CountryCode stringToCC(std::string cc);
    static WeatherEntries readCSV(std::string filename);
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static WeatherEntry stringsToWeatherEntry(std::vector<std::string> tokens);
    static std::vector<std::pair<int, double>> predictTemperature(const WeatherEntries &entries, const std::string &country, int yearsAhead);
    static void plotTemperatureLineChart(const std::vector<std::pair<int, double>> &historicalData, const std::vector<std::pair<int, double>> &predictedData);
};