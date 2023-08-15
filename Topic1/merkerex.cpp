#include <iostream>

void printMenu() {
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats." << std::endl;
    std::cout << "3: Make an offer." << std::endl;
    std::cout << "4: Make a bid." << std::endl;
    std::cout << "5: Print wallet." << std::endl;
    std::cout << "6: Continue." << std::endl;

    std::cout << "==============" << std::endl;
    std::cout << "Type in 1-6" << std::endl;
}

int getUserOption() {
    int userOption;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void printHelp() {
    std::cout << "Help" << std::endl;
}

void printExchangeStats() {
    std::cout << "Exchange stats" << std::endl;
}

void printOffer() {
    std::cout << "Make an offer" << std::endl;
}

void printBid() {
    std::cout << "Make a bid" << std::endl;
}

void printWallet() {
    std::cout << "Print wallet" << std::endl;
}

void continueProgram() {
    std::cout << "Continue" << std::endl;
}

void processUserOption(int userOption) {
    switch (userOption) {
        case 1:
            printHelp();
            break;
        case 2:
            printExchangeStats();
            break;
        case 3:
            printOffer();
            break;
        case 4:
            printBid();
            break;
        case 5:
            printWallet();
            break;
        case 6:
            continueProgram();
            break;
        default:
            std::cout << "Invalid option" << std::endl;
    }
    std::cout << std::endl;
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