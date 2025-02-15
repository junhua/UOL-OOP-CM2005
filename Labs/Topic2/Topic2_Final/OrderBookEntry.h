#pragma once

#include <string>

enum class OrderType { Bid, Ask };

class OrderBookEntry
{
public:
    // Constructors
    OrderBookEntry();
    OrderBookEntry(double price, double amount, const std::string &timestamp,
                   const std::string &product, OrderType orderType);

    // Accessor functions
    double getPrice() const;
    double getAmount() const;
    std::string getTimestamp() const;
    std::string getProduct() const;
    OrderType getOrderType() const;
    

private:
    double m_price;
    double m_amount;
    std::string m_timestamp;
    std::string m_product;
    OrderType m_orderType;
};