// This program demonstrates basic operators in C++
#include <iostream>

int main() {
    // Initialize variables for player stats
    int health = 100;
    int damage = 20;
    int healing = 15;
    
    // Demonstrate arithmetic operators (+, -, *, /, %)
    health = health - damage;  // Take damage
    std::cout << "Health after damage: " << health << "\n";
    
    health = health + healing;  // Heal
    std::cout << "Health after healing: " << health << "\n";
    
    int totalDamage = damage * 2;  // Double damage
    std::cout << "Double damage: " << totalDamage << "\n";
    
    int damageReduction = damage / 2;  // Half damage
    std::cout << "Half damage: " << damageReduction << "\n";
    
    int remainingHealth = health % 25;  // Remainder
    std::cout << "Health remainder of 25: " << remainingHealth << "\n\n";
    
    // Demonstrate assignment operators (+=, -=, *=, /=)
    health -= 10;  // Decrease health
    std::cout << "Health after -= 10: " << health << "\n";
    
    damage += 5;   // Increase damage
    std::cout << "Damage after += 5: " << damage << "\n";
    
    healing *= 2;  // Double healing
    std::cout << "Healing after *= 2: " << healing << "\n\n";
    
    // Demonstrate comparison operators (>, <, >=, <=, ==, !=)
    bool isLowHealth = health < 50;
    bool isFullHealth = health == 100;
    bool needsHealing = health <= 70;
    
    std::cout << "Health is low: " << isLowHealth << "\n";
    std::cout << "Health is full: " << isFullHealth << "\n";
    std::cout << "Needs healing: " << needsHealing << "\n\n";
    
    // Demonstrate logical operators (&&, ||, !)
    bool canHeal = (health < 100) && (healing > 0);
    bool isDead = !health;
    bool isInDanger = (health < 30) || (damage > 50);
    
    std::cout << "Can heal: " << canHeal << "\n";
    std::cout << "Is dead: " << isDead << "\n";
    std::cout << "In danger: " << isInDanger << "\n";
    
    return 0;
}
