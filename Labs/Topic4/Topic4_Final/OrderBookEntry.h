#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown,
    sale
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);

    static OrderBookType stringToOrderBookType(std::string s);

    static bool compareByTimestamp(OrderBookEntry &first, OrderBookEntry &second)
    {
        return first.timestamp < second.timestamp;
    }
    static bool compareByPriceAsc(OrderBookEntry &first, OrderBookEntry &second)
    {
        return first.price < second.price;
    }
    static bool compareByPriceDesc(OrderBookEntry &first, OrderBookEntry &second)
    {
        return first.price > second.price;
    }

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
