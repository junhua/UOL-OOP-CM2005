#include <vector>
#include <string>
#include "Candlestick.h"

class WeatherAnalyzer
{
public:
    WeatherAnalyzer(const std::string &filename);
    std::vector<Candlestick> computeCandlesticks(const std::string &country, const std::string &timeframe);
    void plotCandlesticks(const std::vector<Candlestick> &candlesticks);
    std::vector<WeatherData> filterData(const Date &startDate, const Date &endDate, const std::string &country, double minTemp, double maxTemp);

    std::vector<std::pair<int, double>> predictTemperature(const std::string &country, const Date &startDate, int yearsAhead);
    void plotTemperatureLineChart(const std::string& country, int forecastYears);

private:
    std::vector<WeatherData> data;
};