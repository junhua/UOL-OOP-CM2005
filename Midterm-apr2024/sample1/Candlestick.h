#pragma once
#include "WeatherData.h"

class Candlestick
{
public:
    Candlestick(const Date &date, double open, double high, double low, double close);
    Date getDate() const;
    double getOpen() const;
    double getHigh() const;
    double getLow() const;
    double getClose() const;

private:
    Date date;
    double open, high, low, close;
};
