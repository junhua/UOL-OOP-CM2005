#include <iostream>
#include <string>

int main() {
    // Game title
    std::cout << "\n=== Character Creator ===\n\n";
    
    // Get character details
    std::string heroName;
    std::string heroClass;
    
    std::cout << "Enter hero name: ";
    std::getline(std::cin, heroName);
    
    std::cout << "\nChoose your class:\n";
    std::cout << "1. Warrior ⚔️\n";
    std::cout << "2. Mage 🔮\n";
    std::cout << "3. Archer 🏹\n";
    std::cout << "Your choice (1-3): ";
    
    int classChoice;
    std::cin >> classChoice;
    
    // Set class based on choice
    switch (classChoice) {
        case 1: heroClass = "Warrior"; break;
        case 2: heroClass = "Mage"; break;
        case 3: heroClass = "Archer"; break;
        default: heroClass = "Adventurer";
    }
    
    // Show character card
    std::cout << "\n=== Character Card ===\n";
    std::cout << "🎯 Name: " << heroName << "\n";
    std::cout << "✨ Class: " << heroClass << "\n";
    std::cout << "❤️ Health: 100\n";
    std::cout << "⚡ Energy: 100\n";
    std::cout << "====================\n";
    
    return 0;  // Character created!
}
