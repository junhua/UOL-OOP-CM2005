#include <iostream>
#include <string>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class BattleSimulator {
private:
    // Player stats
    std::string name = "Hero";
    int health = 100;
    int mana = 100;
    int attack = 15;
    bool hasShield = true;
    
    // Enemy stats
    std::string enemyType;
    int enemyHealth;
    int enemyAttack;
    
    // Battle stats
    int roundCount = 0;
    int damageDealt = 0;
    int damageTaken = 0;
    
public:
    void startBattle() {
        // Seed random number generator
        std::srand(std::time(0));
        
        // Setup enemy
        setupEnemy();
        
        std::cout << "\n⚔️ BATTLE START! ⚔️\n";
        std::cout << name << " VS " << enemyType << std::endl;
        
        // Battle loop
        while (true) {
            roundCount++;
            std::cout << "\n=== ROUND " << roundCount << " ===\n";
            
            // Show status
            showStatus();
            
            // Player turn
            if (!playerTurn()) {
                break;  // Player fled
            }
            
            // Check victory
            if (enemyHealth <= 0) {
                std::cout << "\n🎉 VICTORY!\n";
                std::cout << "Enemy defeated!" << std::endl;
                break;
            }
            
            // Enemy turn
            enemyTurn();
            
            // Check defeat
            if (health <= 0) {
                std::cout << "\n💀 DEFEAT!\n";
                std::cout << "You were defeated..." << std::endl;
                break;
            }
        }
        
        // Show battle stats
        showBattleStats();
    }
    
private:
    void setupEnemy() {
        // Random enemy type
        int type = std::rand() % 3;
        switch (type) {
            case 0:
                enemyType = "🐉 Dragon";
                enemyHealth = 120;
                enemyAttack = 20;
                break;
            case 1:
                enemyType = "💀 Skeleton";
                enemyHealth = 80;
                enemyAttack = 15;
                break;
            case 2:
                enemyType = "🧟 Zombie";
                enemyHealth = 100;
                enemyAttack = 10;
                break;
        }
    }
    
    void showStatus() {
        std::cout << "\n📊 BATTLE STATUS:\n";
        std::cout << "❤️ Your HP: " << health << "/100\n";
        std::cout << "✨ Your MP: " << mana << "/100\n";
        std::cout << "🛡️ Shield: " << (hasShield ? "Yes" : "No") 
             << std::endl;
        std::cout << "\n👾 Enemy HP: " << enemyHealth << std::endl;
    }
    
    bool playerTurn() {
        std::cout << "\n🎮 YOUR TURN!\n";
        std::cout << "1. ⚔️ Attack\n";
        std::cout << "2. 🔮 Magic Attack (30 MP)\n";
        std::cout << "3. 🛡️ Defend\n";
        std::cout << "4. 🏃 Run Away\n";
        
        int choice;
        std::cout << "Choice (1-4): ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: { // Normal attack
                
                int damage = attack + (std::rand() % 10);
                std::cout << "\n⚔️ You attack!\n";
                std::cout << "💥 Dealt " << damage 
                     << " damage!" << std::endl;
                enemyHealth -= damage;
                damageDealt += damage;
                
                break;
            }
            case 2: { // Magic attack
                if (mana >= 30) {
                    int damage = attack * 2;
                    std::cout << "\n✨ Magic attack!\n";
                    std::cout << "💥 Dealt " << damage 
                         << " damage!" << std::endl;
                    enemyHealth -= damage;
                    damageDealt += damage;
                    mana -= 30;
                } else {
                    std::cout << "❌ Not enough mana!" << std::endl;
                }
                break;
            }    
            case 3: { // Defend
                std::cout << "\n🛡️ Defense ready!\n";
                hasShield = true;
                break;
            }    
            case 4: { // Run
                if (std::rand() % 2 == 0) {
                    std::cout << "\n🏃 Escaped successfully!\n";
                    return false;
                } else {
                    std::cout << "\n❌ Couldn't escape!\n";
                }
                break;
            }    
            default:
                std::cout << "❌ Invalid choice!" << std::endl;
                return true;
        }
        
        return true;
    }
    
    void enemyTurn() {
        std::cout << "\n👾 ENEMY TURN!\n";
        
        // Calculate damage
        int damage = enemyAttack + (std::rand() % 5);
        
        // Check shield
        if (hasShield) {
            damage /= 2;
            std::cout << "🛡️ Shield reduced damage!" << std::endl;
            hasShield = false;
        }
        
        // Apply damage
        health -= damage;
        damageTaken += damage;
        std::cout << "💥 Took " << damage << " damage!" << std::endl;
        
        // Regenerate mana
        mana = std::min(100, mana + 10);
    }
    
    void showBattleStats() {
        std::cout << "\n📊 BATTLE STATS:\n";
        std::cout << "⚔️ Rounds: " << roundCount << std::endl;
        std::cout << "💥 Damage dealt: " << damageDealt << std::endl;
        std::cout << "💔 Damage taken: " << damageTaken << std::endl;
        
        // Show rating
        std::cout << "\n🏆 RATING: ";
        if (damageDealt > damageTaken * 2) {
            std::cout << "S Rank! Perfect!" << std::endl;
        } else if (damageDealt > damageTaken) {
            std::cout << "A Rank! Great!" << std::endl;
        } else {
            std::cout << "B Rank! Good try!" << std::endl;
        }
    }
};
