#include <iostream>
#include <vector>

class Enemy {
    public:
    int health;
    int damage;
    Enemy(int h, int d) : health(h), damage(d) {}
};

class WaveSystem {
private:
    int currentWave = 1;
    std::vector<Enemy> enemies;
    
public:
    void spawnWave() {
        std::cout << "\n👾 WAVE " << currentWave << " START!" << std::endl;
        
        // Spawn enemies based on wave
        int enemyCount = currentWave * 2;
        for (int i = 1; i <= enemyCount; i++) {
            std::cout << "👾 Spawning enemy " << i << "..." << std::endl;
            
            // Stronger enemies in later waves
            int health = 50 + (currentWave * 10);
            int damage = 10 + (currentWave * 2);
            
            enemies.push_back(Enemy(health, damage));
            std::cout << "⚔️ Enemy " << i << " ready!" << std::endl;
            std::cout << "❤️ Health: " << health << std::endl;
            std::cout << "💥 Damage: " << damage << std::endl;
        }
        
        std::cout << "\n🎮 Wave " << currentWave;
        std::cout << " ready! Enemies: " << enemyCount << std::endl;
        currentWave++;
    }
};
