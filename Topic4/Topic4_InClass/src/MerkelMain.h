#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private: 
        OrderBook orderBook{"20200317.csv"}; // OB constructor requires a filename

        // void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        int getUserOption();
        void processUserOption(int userOption);


        std::vector<OrderBookEntry> orders;
        std::string currentTime;
}; 
