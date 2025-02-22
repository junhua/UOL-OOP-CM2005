#include <iostream>

class Player {
private:
    int health;
    int mana;
    bool hasShield;
    
public:
    Player() : health(100), mana(100), hasShield(true) {
        std::cout << "🎮 Player ready!" << std::endl;
    }
    
    void checkStatus() {
        // Simple health check
        if (health < 20) {
            std::cout << "❌ Low health warning!" << std::endl;
            std::cout << "❤️ Health: " << health << "/100" << std::endl;
        }
        
        // Check if can cast spells
        if (mana >= 50) {
            std::cout << "✨ Magic ready!" << std::endl;
        }
        
        // Check defense
        if (hasShield) {
            std::cout << "🛡️ Shield active" << std::endl;
        }
    }
};
