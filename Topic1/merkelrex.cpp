#include <iostream>

// headers
void printMenu();
int getUserOption();
void processUserOption(int userOption);
void printHelp();
void printExchangeStats();
void printOffer();
void printBid();
void printWallet();
void continueProgram();

// implementations
void printMenu()
{
    // 1. print help
    std::cout << "1: Print help" << std::endl;
    // 2. print exchange stats
    std::cout << "2: Print exchange stats." << std::endl;
    // 3. make an offer
    std::cout << "3: Make an offer." << std::endl;
    // 4. make a bid
    std::cout << "4: Make a bid." << std::endl;
    // 5. print wallet
    std::cout << "5: Print wallet." << std::endl;
    // 6. continue
    std::cout << "6: Continue." << std::endl;
}

int getUserOption()
{
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose option " << userOption << std::endl;

    return userOption;
}

void printHelp()
{
    std::cout << "Help" << std::endl;
}

void printExchangeStats()
{
    std::cout << "Exchange stats" << std::endl;
}

void printOffer()
{
    std::cout << "Make an offer" << std::endl;
}

void printBid()
{
    std::cout << "Make a bid" << std::endl;
}

void printWallet()
{
    std::cout << "Print wallet" << std::endl;
}

void continueProgram()
{
    std::cout << "Continue" << std::endl;
}

void processUserOption(int userOption)
{
    if (userOption == 1)
    {
        printHelp();
    }
    else if (userOption == 2)
    {
        printExchangeStats();
    }
    else if (userOption == 3)
    {
        printOffer();
    }
    else if (userOption == 4)
    {
        printBid();
    }
    else if (userOption == 5)
    {
        printWallet();
    }
    else if (userOption == 6)
    {
        continueProgram();
    }
    else
    {
        std::cout << "Invalid option" << std::endl;
    }
}

int main()
{
    while (true)
    {
        printMenu();
        int userOption = getUserOption();
        processUserOption(userOption);
    }
    return 0;
}