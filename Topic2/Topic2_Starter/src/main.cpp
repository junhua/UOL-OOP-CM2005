#include <iostream>
enum class OrderType
{
    Bid,
    Ask
};

void printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;

    std::cout << "============== " << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks good. " << std::endl;
}

void enterOffer()
{
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty. " << std::endl;
}

void gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
}

int getUserOption()
{
    int userOption;

    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1) // bad input
    {
        printHelp();
    }
    if (userOption == 2) // bad input
    {
        printMarketStats();
    }
    if (userOption == 3) // bad input
    {
        enterOffer();
    }
    if (userOption == 4) // bad input
    {
        enterBid();
    }
    if (userOption == 5) // bad input
    {
        printWallet();
    }
    if (userOption == 6) // bad input
    {
        gotoNextTimeframe();
    }
}

class OrderBookEntry
{
public:
    double price;
    double amount;
    std::string timeframe;
    std::string product;
    OrderType orderType;

    OrderBookEntry(){};

    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timeframe,
                   std::string _product,
                   OrderType _orderType)
        : price(_price),
          amount(_amount),
          timeframe(_timeframe),
          product(_product),
          orderType(_orderType) {}
};

int main()
{
    OrderBookEntry order1;
    order1.price = 5000.01;
    order1.amount = 1.0;
    order1.timeframe = "2020-01-01 00:00:00";
    order1.product = "ETH/BTC";
    order1.orderType = OrderType::Bid;

    // Using constructor 2
    OrderBookEntry order2(5030.01, 1.0, "2020-01-02 01:50:10", "ETH/BTC", OrderType::Ask);

    std::vector<OrderBookEntry> orderBook;
    orderBook.push_back(order1);
    orderBook.push_back(order2);

    // 2020/03/17 17:01:24.884492,ETH/BTC,bid,0.021873,1.
    orderBook.push_back(
        OrderBookEntry(0.021873,
                       1.0,
                       "2020/03/17 17:01:24.884492",
                       "ETH/BTC",
                       OrderType::Bid));

    // for (std::size_t i = 0; i < orderBook.size(); ++i)
    // {
    //     std::cout << "Price: " << orderBook[i].price << std::endl;
    // }

    // The for-each way
    for (const OrderBookEntry &entry : orderBook)
    {
        std::cout << "Price: " << entry.price << std::endl;
    }

    // while (true)
    // {
    //     printMenu();
    //     int userOption = getUserOption();
    //     processUserOption(userOption);
    // }
    return 0;
}
