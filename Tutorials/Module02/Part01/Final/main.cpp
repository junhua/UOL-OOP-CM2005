#include <iostream>

class BattleSystem {
private:
    int playerHealth;
    int enemyHealth;
    bool hasSpecialPower;
    
public:
    BattleSystem() 
        : playerHealth(100), enemyHealth(100),
          hasSpecialPower(true) {
        std::cout << "⚔️ Battle start!" << std::endl;
    }
    
    void battle() {
        // Check battle state
        if (playerHealth <= 0) {
            std::cout << "💀 Game Over!" << std::endl;
            return;
        } else if (enemyHealth <= 0) {
            std::cout << "🎉 Victory!" << std::endl;
            return;
        }
        
        // Check player status
        if (playerHealth < 20) {
            std::cout << "⚠️ Low health warning!" << std::endl;
            
            // Check for special power
            if (hasSpecialPower) {
                std::cout << "✨ Special power ready!" << std::endl;
                std::cout << "Use it to survive!" << std::endl;
            } else {
                std::cout << "🧪 Find health potion!" << std::endl;
            }
        }
        
        // Show battle status
        std::cout << "\n📊 Battle Status:" << std::endl;
        std::cout << "❤️ Player HP: " << playerHealth << std::endl;
        std::cout << "👾 Enemy HP: " << enemyHealth << std::endl;
    }
};
