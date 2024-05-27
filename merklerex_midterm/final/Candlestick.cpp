#include "Candlestick.h"
#include <iostream>
#include <map>
#include <vector>

#include "OrderBookEntry.h"
#include "OrderBook.h"

Candlestick::Candlestick(std::string timestamp, std::string product, OrderBookType type, double open, double high, double low, double close)
    : timestamp(timestamp), product(product), type(type), open(open), high(high), low(low), close(close) {}

// void Candlestick::printCandlestick()
// {
//     std::cout << timestamp << " \t "
//               << product << " \t "
//               << open << " \t "
//               << high << " \t "
//               << low << " \t "
//               << close << std::endl;
// }

// double Candlestick::calculateAveragePrice(std::vector<OrderBookEntry> &entries)
// {
//     double totalValue, totalAmount;
//     for (OrderBookEntry &entry : entries)
//     {
//         totalValue += entry.price * entry.amount;
//         totalAmount += entry.amount;
//     }
//     return totalValue / totalAmount;
// }

// double Candlestick::calculateOpen(std::vector<OrderBookEntry> &entries)
// {
//     return calculateAveragePrice(entries);
// }

// double Candlestick::calculateClose(std::vector<OrderBookEntry> &entries)
// {
//     return calculateAveragePrice(entries);
// }

// double Candlestick::calculateHigh(std::vector<OrderBookEntry> &entries)
// {
//     double high = entries[0].price;
//     for (OrderBookEntry &entry : entries)
//     {
//         if (entry.price > high)
//         {
//             high = entry.price;
//         }
//     }
//     return high;
// }

// double Candlestick::calculateLow(std::vector<OrderBookEntry> &entries)
// {
//     double low = entries[0].price;
//     for (OrderBookEntry &entry : entries)
//     {
//         if (entry.price < low)
//         {
//             low = entry.price;
//         }
//     }
//     return low;
// }

// Task 1
std::vector<Candlestick> Candlestick::generateCandlesticks(std::vector<OrderBookEntry> entries)
{
    std::vector<Candlestick> candlesticks;
    std::map<std::string, std::vector<OrderBookEntry>> candlestickEntries;

    candlestickEntries[entries[0].timestamp + entries[0].product + OrderBookEntry::obtToString(entries[0].orderType)] = {entries[0]};

    for (OrderBookEntry &entry : entries)
    {
        std::string key = entry.timestamp + entry.product + OrderBookEntry::obtToString(entry.orderType);
        candlestickEntries[key].push_back(entry);
    }

    double open, close, high, low, totalValue, totalAmount;

    std::string firstTimestamp = entries[0].timestamp;

    std::string timestamp, product;
    OrderBookType type;

    for (auto &[key, entries] : candlestickEntries)
    {
        timestamp = entries[0].timestamp;
        product = entries[0].product;
        type = entries[0].orderType;

        high = low = entries[0].price;
        totalValue = totalAmount = 0.;

        for (OrderBookEntry &entry : entries)
        {
            totalValue += entry.price * entry.amount;
            totalAmount += entry.amount;
            high = std::max(high, entry.price);
            low = std::min(low, entry.price);
        }

        if (timestamp == firstTimestamp)
        {
            printf("firstTimestamp: %s\n", firstTimestamp.c_str());
            open = totalValue / totalAmount;
        }
        else
        {
            close = totalValue / totalAmount; // Calculate 'close' for the current candlestick
            candlesticks.push_back(Candlestick{timestamp, product, type, open, high, low, close});
            open = close;
        }
    }

    return candlesticks;
}

// Task 2
void Candlestick::plot(std::vector<Candlestick> & candles)
{

    // get highest and lowest price
    double highestPrice = candles[0].high;
    double lowestPrice = candles[0].low;

    for (Candlestick &candle : candles)
    {
        if (candle.high > highestPrice)
        {
            highestPrice = candle.high;
        }
        if (candle.low < lowestPrice)
        {
            lowestPrice = candle.low;
        }
    }

    // get y range
    int steps = 100;
    double yRange = highestPrice - lowestPrice;
    double stepSize = yRange / steps;
    std::string line;
    for (double y = highestPrice; y > lowestPrice; y -= stepSize)
    {

        // print y axis
        std::cout << y << "\t";

        // print candles (as an example, we only print first 10 candles)
        int maxSize = candles.size() < 10 ? candles.size() : 10;

        for (int x = 0; x < maxSize; x++)
        {
            // beyond candle range, print space
            if (y > candles[x].high || y < candles[x].low)
            {
                std::cout << "       ";
            }
            // within candle range, print body or wick
            else
            {
                if (y > candles[x].open && y > candles[x].close) // wick above
                {
                    std::cout << "   |   ";
                }
                else if (y < candles[x].open && y < candles[x].close) // wick below
                {
                    std::cout << "   |   ";
                }
                else // body
                {
                    if (candles[x].close > candles[x].open)
                    {
                        std::cout << "  +++  ";
                    }
                    else
                    {
                        std::cout << "  ---  ";
                    }
                }
            }
        }
        std::cout << std::endl;
    }
}



std::string Candlestick::toString()
{
    return timestamp + " \t " +
           product + " \t " +
           OrderBookEntry::obtToString(type) + " \t " +
           std::to_string(high) + " \t " +
           std::to_string(low) + " \t " +
           std::to_string(open) + " \t " +
           std::to_string(close);
}