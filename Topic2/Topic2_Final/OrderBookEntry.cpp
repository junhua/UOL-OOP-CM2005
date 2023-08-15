#include "OrderBookEntry.h"

// Constructors
OrderBookEntry::OrderBookEntry() : m_price(0.0), m_amount(0.0), m_timestamp(""), m_product(""), m_orderType(OrderType::Bid) {}

OrderBookEntry::OrderBookEntry(double price, double amount, const std::string &timestamp,
                               const std::string &product, OrderType orderType)
    : m_price(price), m_amount(amount), m_timestamp(timestamp), m_product(product), m_orderType(orderType) {}

// Accessor functions
double OrderBookEntry::getPrice() const { return m_price; }

double OrderBookEntry::getAmount() const { return m_amount; }

std::string OrderBookEntry::getTimestamp() const { return m_timestamp; }

std::string OrderBookEntry::getProduct() const { return m_product; }

OrderType OrderBookEntry::getOrderType() const { return m_orderType; }