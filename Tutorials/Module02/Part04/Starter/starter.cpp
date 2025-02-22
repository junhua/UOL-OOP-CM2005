#include <iostream>
#include <vector>
#include <string>

class Enemy {
    public:
        std::string name;
        int health;
        int distance;
        bool hasShield;
        Enemy(std::string n, int h, int d, bool shield) : name(n), health(h), distance(d), hasShield(shield) {}
        bool isDefeated() {
            return health <=0;
        }
};

class CombatSystem {
private:
    std::vector<Enemy> enemies;
    int playerMana;
    
public:
    void targetEnemies() {
        std::cout << "\n🎯 Scanning for targets..." << std::endl;
        
        for (Enemy& enemy : enemies) {
            // Skip defeated enemies
            if (enemy.isDefeated()) {
                std::cout << "💀 Skipping defeated enemy" << std::endl;
                continue;
            }
            
            // Skip if out of range
            if (enemy.distance > 100) {
                std::cout << "❌ Enemy too far: " << enemy.distance 
                     << " units" << std::endl;
                continue;
            }
            
            // Skip if shielded and no mana
            if (enemy.hasShield && playerMana < 50) {
                std::cout << "🛡️ Need more mana for shielded enemy!" 
                     << std::endl;
                continue;
            }
            
            // Valid target found!
            std::cout << "\n✨ Target acquired!" << std::endl;
            std::cout << "⚔️ Enemy: " << enemy.name << std::endl;
            std::cout << "❤️ Health: " << enemy.health << std::endl;
            
            // Attack!
            // attackEnemy(enemy); // Placeholder for attack logic
        }
    }
};
