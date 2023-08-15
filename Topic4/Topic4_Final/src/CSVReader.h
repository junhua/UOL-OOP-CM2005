#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>

class CSVReader
{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    static OrderBookEntry stringsToOBE(std::string priceStr,
                                       std::string amountStr,
                                       std::string timestamp,
                                       std::string product,
                                       OrderBookType obt);

private:
    static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
};
