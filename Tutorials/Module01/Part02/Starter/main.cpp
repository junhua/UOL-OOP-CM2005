// This program demonstrates basic C++ program structure
#include <iostream>  // For input/output operations
#include <string>   // For string handling

int main() {
    // Display program title
    std::cout << "\n=== Character Creator ===\n\n";
    
    // Variables to store character information
    std::string heroName;
    std::string heroClass;
    
    // Get character name
    std::cout << "Enter hero name: ";
    std::getline(std::cin, heroName);
    
    // TODO: Add class selection menu
    // Hint: Display numbered options (1-3) for Warrior, Mage, and Archer
    // Example: std::cout << "1. Warrior ⚔️\n";
    
    // TODO: Get user's choice
    // Hint: Declare an int variable and use cin to get user input
    
    // TODO: Set class based on choice using switch statement
    // Hint: Use a switch with cases 1,2,3 to set heroClass
    
    // TODO: Display character card with stats
    // Hint: Show name, class, and some basic stats like health/energy
    
    return 0;  // Program complete!
}
