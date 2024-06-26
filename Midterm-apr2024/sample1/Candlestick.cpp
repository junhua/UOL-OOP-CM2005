
#include "Candlestick.h"
#include "WeatherData.h"
#include <algorithm>

Candlestick::Candlestick(const Date &date, double open, double high, double low, double close)
    : date(date), open(open), high(high), low(low), close(close) {}

Date Candlestick::getDate() const { return date; }
double Candlestick::getOpen() const { return open; }
double Candlestick::getHigh() const { return high; }
double Candlestick::getLow() const { return low; }
double Candlestick::getClose() const { return close; }

WeatherData::WeatherData(const Date &date, const std::vector<double> &temperatures)
    : date(date), temperatures(temperatures) {}

Date WeatherData::getDate() const { return date; }

double WeatherData::getTemperature(const std::string &country) const
{
    auto it = std::find(countryList.begin(), countryList.end(), country);
    if (it != countryList.end())
    {
        return temperatures[std::distance(countryList.begin(), it)];
    }
    return 0.0;
}
