#include "WeatherData.h"
#include <sstream>
#include <iomanip>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

Date::Date(const std::string &dateString)
{
    std::istringstream ss(dateString);
    char delimiter;
    ss >> year >> delimiter >> month >> delimiter >> day;
}

std::string Date::toString() const
{
    std::ostringstream ss;
    ss << year << "-" << std::setfill('0') << std::setw(2) << month << "-" << std::setw(2) << day;
    return ss.str();
}

bool Date::operator<(const Date &other) const
{
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

int Date::getYear() const
{
    return year;
}

const std::vector<std::string> WeatherData::countryList = {
    "AT", "BE", "BG", "CH", "CZ", "DE", "DK", "EE", "ES", "FI", "FR", "GB", "GR", "HR", "HU",
    "IE", "IT", "LT", "LU", "LV", "NL", "NO", "PL", "PT", "RO", "SE", "SI", "SK"};