#pragma once
#include "OrderBookEntry.h"
#include <string>
#include <vector>

class Candlestick
{
public:
    // properties
    std::string time, product, type;
    double high, low, open, close;

    Candlestick(std::string time, 
                std::string product, 
                std::string type, 
                double high, 
                double low, 
                double open, 
                double close);

    // task 1
    void printCandlestick();
    static void printCandlestickTable(std::vector<Candlestick> candles);

    static std::vector<Candlestick> calculateCandlesticks(
        std::vector<OrderBookEntry> entries
    );

    // Task 2 & 3
    static void printCandlestickPlot(std::vector<Candlestick> candles);

};