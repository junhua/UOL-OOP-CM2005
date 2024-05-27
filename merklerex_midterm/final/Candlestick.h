#pragma once
#include <vector>
#include <string>
#include "OrderBookEntry.h"

class Candlestick
{
public:
    std::string timestamp, product;
    double open, high, low, close;

    OrderBookType type;

    Candlestick(std::string timestamp, std::string product, OrderBookType type, double open, double high, double low, double close);
    std::string toString();

    // Task 1
    static std::vector<Candlestick> generateCandlesticks(std::vector<OrderBookEntry> entries);

    // Task 2
    static void plot(std::vector<Candlestick> &candles);


    // static double calculateOpen(std::vector<OrderBookEntry> &entries);
    // static double calculateClose(std::vector<OrderBookEntry> &entries);
    // static double calculateHigh(std::vector<OrderBookEntry> &entries);
    // static double calculateLow(std::vector<OrderBookEntry> &entries);



// private:
    // static double calculateAveragePrice(std::vector<OrderBookEntry> &entries);
    
};