// This program demonstrates different variable types in C++
#include <iostream>

int main() {
    std::cout << "=== Variable Types Demo ===\n\n";

    // Declare and initialize variables of different types
    int playerLevel = 5;           // Whole number
    float playerHealth = 100.0f;   // Decimal number
    char playerRank = 'A';         // Single character
    bool isGameOver = false;       // True/false value
    
    // Display initial values
    std::cout << "Player Stats:\n";
    std::cout << "Level: " << playerLevel << "\n";
    std::cout << "Health: " << playerHealth << "\n";
    std::cout << "Rank: " << playerRank << "\n";
    std::cout << "Game Over: " << (isGameOver ? "Yes" : "No") << "\n\n";
    
    // Perform calculations and update values
    playerLevel = playerLevel + 1;      // Increment level
    playerHealth = playerHealth * 1.5f;  // Increase health by 50%
    playerRank = 'S';                   // Change rank
    isGameOver = true;                  // End game
    
    // Display updated values
    std::cout << "Updated Stats:\n";
    std::cout << "Level: " << playerLevel << "\n";
    std::cout << "Health: " << playerHealth << "\n";
    std::cout << "Rank: " << playerRank << "\n";
    std::cout << "Game Over: " << (isGameOver ? "Yes" : "No") << "\n";
    
    return 0;
}
