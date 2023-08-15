#pragma once

#include "OrderBookEntry.h"
#include <vector>
class CSVReader
{
public:
    CSVReader();
    static std::vector<OrderBookEntry> readCSV(std::string csvFile);

private:
    static std::vector<std::string> tokenize(std::string csvLine, char sep);
    static OrderBookEntry stringToOBE(std::vector<std::string> strings);
};