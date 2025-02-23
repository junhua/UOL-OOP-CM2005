#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 8 - Part 2: Virtual Functions
 * Practice Exercise Starter Code
 * 
 * Task: Create a game character system demonstrating:
 * 1. Base character class with virtual methods
 * 2. Different character types
 * 3. Common and specific behaviors
 * 4. Runtime method selection
 */

// TODO: Create Character base class with:
// - Protected members for name, health, power
// - Constructor to initialize members
// - Virtual destructor
// - Virtual methods for attack() and defend()
// - Pure virtual method for specialMove()
// - Virtual displayStats() with default implementation
// - Non-virtual getters

// TODO: Create Warrior class that:
// - Inherits from Character
// - Adds weaponType member
// - Overrides all virtual methods
// - Implements weapon-based attacks

// TODO: Create Mage class that:
// - Inherits from Character
// - Adds spells collection
// - Overrides all virtual methods
// - Implements spell-based attacks

// TODO: Create Rogue class that:
// - Inherits from Character
// - Adds stealthLevel member
// - Overrides all virtual methods
// - Implements stealth-based attacks

// TODO: Create BattleSystem class to:
// - Manage collection of characters
// - Add characters to battle
// - Simulate battle with all characters
// - Clean up properly

int main() {
    try {
        // TODO: Create battle system
        
        // TODO: Add different character types
        // - Warrior with weapon
        // - Mage with spells
        // - Rogue with stealth
        
        // TODO: Simulate battle
        // - Show stats
        // - Perform actions
        // - Demonstrate polymorphism
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
