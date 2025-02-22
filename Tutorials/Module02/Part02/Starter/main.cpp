#include <iostream>

class GameMenu {
private:
    int playerHealth;
    int playerMana;
    bool hasPotion;
    
public:
    GameMenu() : playerHealth(100), playerMana(100), 
                 hasPotion(true) {
        std::cout << "🎮 Game Menu Ready!" << std::endl;
    }
    
    void showMenu() {
        std::cout << "\n=== GAME MENU ===\n";
        std::cout << "1. ⚔️ Attack\n";
        std::cout << "2. 🛡️ Defend\n";
        std::cout << "3. ✨ Cast Spell\n";
        std::cout << "4. 🧪 Use Potion\n";
        std::cout << "5. 📊 View Stats\n";
        std::cout << "6. ❌ Exit Game\n";
        std::cout << "Choose action (1-6): ";
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "\n⚔️ Attacking enemy!" << std::endl;
                std::cout << "💥 Dealt 25 damage!" << std::endl;
                break;
                
            case 2:
                std::cout << "\n🛡️ Defense mode active!" << std::endl;
                std::cout << "✨ Damage reduced by 50%" << std::endl;
                break;
                
            case 3:
                if (playerMana >= 30) {
                    std::cout << "\n✨ Casting Fireball!" << std::endl;
                    std::cout << "🔥 Dealt 50 damage!" << std::endl;
                    playerMana -= 30;
                } else {
                    std::cout << "\n❌ Not enough mana!" << std::endl;
                }
                break;
                
            case 4:
                if (hasPotion) {
                    std::cout << "\n🧪 Used health potion!" << std::endl;
                    std::cout << "❤️ Healed 50 HP!" << std::endl;
                    hasPotion = false;
                } else {
                    std::cout << "\n❌ No potions left!" << std::endl;
                }
                break;
                
            case 5:
                std::cout << "\n📊 PLAYER STATUS" << std::endl;
                std::cout << "❤️ Health: " << playerHealth << std::endl;
                std::cout << "✨ Mana: " << playerMana << std::endl;
                std::cout << "🧪 Potions: " 
                     << (hasPotion ? "Yes" : "No") << std::endl;
                break;
                
            case 6:
                std::cout << "\n👋 Thanks for playing!" << std::endl;
                break;
                
            default:
                std::cout << "\n❌ Invalid choice!" << std::endl;
                std::cout << "Try again!" << std::endl;
        }
    }
};
