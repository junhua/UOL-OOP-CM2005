#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 8 - Part 2: Virtual Functions
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Virtual function implementation
 * 2. Runtime polymorphism
 * 3. Pure virtual methods
 * 4. Memory management
 */

// Base character class
class Character {
protected:
    string name;
    int health;
    int power;
    
public:
    Character(string n, int h, int p)
        : name(n), health(h), power(p) {
        cout << "Creating character: " << name << endl;
    }
    
    virtual ~Character() {
        cout << "Destroying character: " << name << endl;
    }
    
    // Virtual methods with default implementation
    virtual void attack() const {
        cout << name << " performs a basic attack" << endl;
    }
    
    virtual void defend() const {
        cout << name << " takes a defensive stance" << endl;
    }
    
    virtual void specialMove() const = 0;  // Pure virtual
    
    virtual void displayStats() const {
        cout << "\nCharacter Stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Power: " << power << endl;
    }
    
    // Non-virtual methods
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getPower() const { return power; }
};

class Warrior : public Character {
private:
    string weaponType;
    
public:
    Warrior(string name, string weapon)
        : Character(name, 100, 80), weaponType(weapon) {
        cout << "Equipping warrior with " << weaponType << endl;
    }
    
    void attack() const override {
        cout << name << " swings " << weaponType << " with force!" << endl;
    }
    
    void defend() const override {
        cout << name << " raises shield and takes defensive stance" << endl;
    }
    
    void specialMove() const override {
        cout << name << " performs WHIRLWIND ATTACK with " << weaponType << "!" << endl;
        cout << "Deals massive area damage!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Weapon: " << weaponType << endl;
    }
};

class Mage : public Character {
private:
    vector<string> spells;
    
public:
    Mage(string name)
        : Character(name, 70, 100) {
        spells = {"Fireball", "Ice Shard", "Lightning Bolt"};
        cout << "Preparing mage spellbook" << endl;
    }
    
    void attack() const override {
        cout << name << " casts a magic missile!" << endl;
    }
    
    void defend() const override {
        cout << name << " creates a magical barrier" << endl;
    }
    
    void specialMove() const override {
        cout << name << " unleashes ARCANE BARRAGE!" << endl;
        cout << "Channels magical energy to devastate enemies!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Spells: ";
        for (const auto& spell : spells) {
            cout << spell << " ";
        }
        cout << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    
public:
    Rogue(string name, int stealth)
        : Character(name, 80, 90), stealthLevel(stealth) {
        cout << "Sharpening rogue daggers" << endl;
    }
    
    void attack() const override {
        cout << name << " strikes from the shadows!" << endl;
    }
    
    void defend() const override {
        cout << name << " dodges and rolls away" << endl;
    }
    
    void specialMove() const override {
        cout << name << " performs ASSASSINATE from stealth!" << endl;
        cout << "Deals critical damage from the shadows!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
    }
};

class BattleSystem {
private:
    vector<Character*> characters;
    
public:
    ~BattleSystem() {
        cout << "Cleaning up battle system..." << endl;
        for (Character* character : characters) {
            delete character;
        }
    }
    
    void addCharacter(Character* character) {
        characters.push_back(character);
        cout << "Added " << character->getName() << " to battle" << endl;
    }
    
    void simulateBattle() const {
        cout << "\nBattle Simulation:" << endl;
        cout << string(50, '=') << endl;
        
        for (const Character* character : characters) {
            cout << "\n" << character->getName() << "'s turn:" << endl;
            cout << string(20, '-') << endl;
            
            character->displayStats();
            character->attack();
            character->defend();
            character->specialMove();
        }
    }
};

int main() {
    try {
        // Create battle system
        BattleSystem battle;
        
        // Add different character types
        cout << "\nCreating characters:" << endl;
        cout << string(50, '-') << endl;
        
        battle.addCharacter(new Warrior("Conan", "Greatsword"));
        battle.addCharacter(new Mage("Gandalf"));
        battle.addCharacter(new Rogue("Ezio", 95));
        
        // Simulate battle
        battle.simulateBattle();
        
        cout << "\nBattle completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
