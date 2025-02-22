// This program demonstrates basic operators in C++
#include <iostream>

int main() {
    // Initialize variables for player stats
    int health = 100;
    int damage = 20;
    int healing = 15;
    
    std::cout << "=== Operator Demo ===\n\n";
    std::cout << "Initial Stats:\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Damage: " << damage << "\n";
    std::cout << "Healing: " << healing << "\n\n";
    
    // TODO: Use arithmetic operators (+, -, *, /, %)
    // Hint: Calculate remaining health after taking damage (health - damage)
    // Hint: Calculate total damage for a combo attack (damage * 2)
    // Hint: Calculate damage reduction (damage / 2)
    // Hint: Use modulus to check if health is divisible by healing (health % healing)
    
    
    // TODO: Use assignment operators (+=, -=, *=, /=)
    // Hint: Reduce health when hit (health -= damage)
    // Hint: Increase damage for power up (damage *= 2)
    // Hint: Apply healing over time (health += healing)
    
    
    // TODO: Use comparison operators (>, <, >=, <=, ==, !=)
    // Hint: Check if health is low (health < 50)
    // Hint: Check if damage is lethal (damage >= health)
    // Hint: Check if healing is needed (health != 100)
    // Store results in bool variables and display them
    
    
    // TODO: Use logical operators (&&, ||, !)
    // Hint: Check if player needs healing AND has healing available
    // Hint: Check if player is in danger (low health OR high damage)
    // Hint: Check if player is NOT at full health
    // Store results in bool variables and display them
    
    
    return 0;
}
