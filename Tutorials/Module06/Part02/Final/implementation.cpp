// This tutorial demonstrates:
// 1. Reference basics
// 2. References vs pointers
// 3. References as parameters
// 4. References as return values

#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
    int health;
    int mana;
    
public:
    // Initialize using constructor initialization list
    Player(string n, int h, int m) 
        : name(n), health(h), mana(m) {}
    
    // Getters that return references to allow direct modification
    int& getHealth() { return health; }
    int& getMana() { return mana; }
    
    void display() {
        cout << name << " - Health: " << health 
             << ", Mana: " << mana << endl;
    }
};

class Spell {
private:
    string name;
    int manaCost;
    int healAmount;
    
public:
    Spell(string n, int m, int h) 
        : name(n), manaCost(m), healAmount(h) {}
    
    // Cast spell using references to modify original objects
    bool cast(Player& caster, Player& target) {
        // Check if caster has enough mana
        if(caster.getMana() >= manaCost) {
            // Modify stats directly through references
            caster.getMana() -= manaCost;
            target.getHealth() += healAmount;
            cout << "✨ " << name << " cast successfully!" << endl;
            return true;
        }
        cout << "❌ Not enough mana!" << endl;
        return false;
    }
};

int main() {
    // Create players
    Player healer("Healer", 100, 100);
    Player warrior("Warrior", 60, 30);
    
    // Create healing spell
    Spell healSpell("Heal", 30, 40);
    
    // Display initial stats
    cout << "Initial stats:" << endl;
    healer.display();
    warrior.display();
    cout << endl;
    
    // Cast spell (objects passed by reference)
    healSpell.cast(healer, warrior);
    
    // Display final stats
    cout << "\nFinal stats:" << endl;
    healer.display();
    warrior.display();
    
    return 0;
}
