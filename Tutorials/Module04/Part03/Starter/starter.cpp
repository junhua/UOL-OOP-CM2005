#include <iostream>
#include <string>
#include <cstdlib> // For random numbers

class CharacterStats {
private:
    static const int STAT_COUNT = 6; // TODO: Explain the purpose of 'static const' here.  It means the value is constant and shared by all instances of the class.
    std::string statNames[STAT_COUNT] = {
        "Health", "Mana", "Attack", 
        "Defense", "Speed", "Luck"
    }; // TODO: Explain why we use parallel arrays here.  It's to associate names with the stat values at the corresponding index.
    int stats[STAT_COUNT];  // Array of stat values // TODO: Explain that this is a fixed-size array.
    
public:
    CharacterStats() {
        // Initialize all stats to base value
        for (int i = 0; i < STAT_COUNT; i++) { // TODO: Explain how the loop initializes the array.  It iterates through each index.
            stats[i] = 10;  // Base stat value
        }
        std::cout << "🎮 Created new character!" << std::endl;
    }
    
    // Safe stat access
    bool getStat(const std::string& name, int& value) const {
        for (int i = 0; i < STAT_COUNT; i++) { // TODO: Explain how the loop iterates through the array. It checks each element one by one.
            if (statNames[i] == name) {
                value = stats[i]; // TODO: Explain array element access using index 'i'.  stats[i] accesses the element at index 'i' in the 'stats' array.
                return true;
            }
        }
        std::cout << "❌ Unknown stat: " << name << std::endl;
        return false;
    }
    
    // Safe stat modification
    bool modifyStat(const std::string& name, int amount) {
        for (int i = 0; i < STAT_COUNT; i++) { // TODO: Explain how the loop iterates through the array. It checks each element one by one.
            if (statNames[i] == name) {
                stats[i] += amount; // TODO: Explain array element access using index 'i'. stats[i] accesses the element at index 'i' in the 'stats' array.
                std::cout << "📈 " << name << " " 
                     << (amount >= 0 ? "increased" : "decreased")
                     << " by " << abs(amount) 
                     << " to " << stats[i] << std::endl;
                return true;
            }
        }
        std::cout << "❌ Unknown stat: " << name << std::endl;
        return false;
    }
    
    // Show all stats
    void showStats() const {
        std::cout << "\n📊 Character Stats:" << std::endl;
        for (int i = 0; i < STAT_COUNT; i++) { // TODO: Explain how the loop iterates through the array. It checks each element one by one.
            std::cout << statNames[i] << ": " 
                 << stats[i] << std::endl; // TODO: Explain array element access using index 'i'.  statNames[i] and stats[i] access elements at the same index.
        }
    }
    
    // Level up (increase all stats)
    void levelUp() {
        std::cout << "\n🌟 Level Up!" << std::endl;
        for (int i = 0; i < STAT_COUNT; i++) { // TODO: Explain how the loop iterates through the array. It checks each element one by one.
            int increase = rand() % 5 + 1;  // 1-5
            stats[i] += increase; // TODO: Explain array element access using index 'i'.  stats[i] accesses the element at index 'i'.
            std::cout << "📈 " << statNames[i] 
                 << " +" << increase << std::endl;
        }
    }
};

int main() {
    std::cout << "Starting game! 🎮\n" << std::endl;
    
    // Create character
    CharacterStats hero;
    hero.showStats();
    
    // Modify some stats
    hero.modifyStat("Attack", 5);    // Valid
    hero.modifyStat("Defense", -2);   // Valid
    hero.modifyStat("Strength", 10);  // Invalid
    
    // Check a stat
    int value;
    if (hero.getStat("Health", value)) {
        std::cout << "\n❤️ Current Health: " << value << std::endl;
    }
    
    // Level up!
    hero.levelUp();
    hero.showStats();
    
    return 0;
}
