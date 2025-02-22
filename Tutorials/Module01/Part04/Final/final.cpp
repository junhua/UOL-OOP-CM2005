// This program demonstrates input and output in C++
#include <iostream>
#include <string>

int main() {
    // Variables to store user input
    std::string playerName;
    int playerAge;
    double playerScore;
    
    // Display welcome message
    std::cout << "=== Character Creator ===\n\n";
    
    // Get player name using getline
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    
    // Get player age using cin
    std::cout << "Enter your age: ";
    std::cin >> playerAge;
    
    // Get player score using cin
    std::cout << "Enter your score: ";
    std::cin >> playerScore;
    
    // Display all information
    std::cout << "\nPlayer Information:\n";
    std::cout << "Name: " << playerName << "\n";
    std::cout << "Age: " << playerAge << "\n";
    std::cout << "Score: " << playerScore << "\n";
    
    return 0;
}
