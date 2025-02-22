// This program demonstrates different variable types in C++
#include <iostream>

int main() {
    std::cout << "=== Variable Types Demo ===\n\n";

    // Declare and initialize variables of different types
    int playerLevel;     // For storing whole numbers
    float playerHealth;  // For storing decimal numbers
    char playerRank;     // For storing single characters
    bool isGameOver;     // For storing true/false values
    
    // TODO: Initialize your variables with appropriate values
    // Hint: playerLevel should be a whole number (e.g., 1, 5, 10)
    // Hint: playerHealth should be a decimal number (add 'f' suffix, e.g., 100.0f)
    // Hint: playerRank should be a single character in quotes (e.g., 'A', 'B', 'S')
    // Hint: isGameOver should be true or false
    
    
    // Display initial values
    std::cout << "Player Stats:\n";
    std::cout << "Level: " << playerLevel << "\n";
    std::cout << "Health: " << playerHealth << "\n";
    std::cout << "Rank: " << playerRank << "\n";
    std::cout << "Game Over: " << (isGameOver ? "Yes" : "No") << "\n\n";
    
    // TODO: Try changing values using different operations
    // Hint: Increase level by adding a number
    // Hint: Increase health by a percentage (e.g., multiply by 1.5f)
    // Hint: Change rank to a different character
    // Hint: Toggle game state to opposite value
    
    
    // TODO: Display the updated values
    // Hint: Copy the display code from above and show the new values
    
    
    return 0;
}
