#pragma once
#include <string>
#include <map>

enum class CountryCode
{
    AT,BE,BG,CH,CZ,DE,DK,EE,ES,FI,FR,GB,GR,HR,HU,IE,IT,LT,LU,LV,NL,NO,PL,PT,RO,SE,SI,SK,UNKNOWN
};

class WeatherEntry
{
public:
    std::string utc_timestamp;
    std::map<CountryCode, double> tempMap;

    WeatherEntry() {}
    WeatherEntry(std::string timestamp, std::map<CountryCode, double> temps)
        : utc_timestamp(timestamp), tempMap(temps) {}
};

