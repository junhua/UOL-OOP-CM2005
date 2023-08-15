#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price,
                               double _amount,
                               std::string _timestamp,
                               std::string _product,
                               OrderBookType _orderType)
    : price(_price),
      amount(_amount),
      timestamp(_timestamp),
      product(_product),
      orderType(_orderType)
{
}

OrderBookType OrderBookEntry::stringToOrderType(std::string type)
{
  if (type == "bid")
  {
    return OrderBookType::bid;
  }
  else if (type == "ask")
  {
    return OrderBookType::ask;
  }
  else
  {
    return OrderBookType::unknown;
  }
}