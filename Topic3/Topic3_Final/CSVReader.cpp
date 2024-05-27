#include "CSVReader.h"
#include "OrderBookEntry.h"
#include <fstream>
#include <iostream>

CSVReader::CSVReader() {}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;

    std::ifstream csvStream{csvFile};
    std::string line;
    std::vector<std::string> tokens;

    if (csvStream.is_open())
    {
        while (std::getline(csvStream, line))
        {
            try {
                OrderBookEntry obe = stringToOBE(tokenize(line, ','));
                entries.push_back(obe);
            } catch(std::exception& e) {
                std::cout << "Bad data" << std::endl;
                continue;
            }
        }
    }
    else
    {
        std::cout << "Unable to open file: " << csvFile << std::endl;
    }


    std::cout << "CSVReader::readCSV read " << entries.size() << " entries." << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenize(std::string csvLine, char sep)
{
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(sep, 0);
    do
    {
        end = csvLine.find_first_of(sep, start);
        if (start == csvLine.length() || start == end)
            break;
        if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);
    return tokens;
}

OrderBookEntry CSVReader::stringToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    std::string timestamp, product;
    OrderBookType type;

    if (tokens.size() != 5)
    {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Bad float! " << tokens[3] << std::endl;
        std::cout << "Bad float! " << tokens[4] << std::endl;
        throw;
    }

    return OrderBookEntry(price,
                          amount,
                          tokens[0],
                          tokens[1],
                          OrderBookEntry::stringToOrderType(tokens[2]));
}