#pragma once
#include <vector>
#include <string>

class Date
{
public:
    Date(int year, int month, int day);
    Date(const std::string &dateString);
    std::string toString() const;
    bool operator<(const Date &other) const;
    int getYear() const;

private:
    int year, month, day;
};

class WeatherData
{
public:
    WeatherData(const Date &date, const std::vector<double> &temperatures);
    Date getDate() const;
    double getTemperature(const std::string &country) const;

private:
    Date date;
    std::vector<double> temperatures;
    static const std::vector<std::string> countryList;
};

