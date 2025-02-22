// This tutorial demonstrates:
// 1. Basic pointer concepts
// 2. Pointer declaration and initialization
// 3. Dereferencing pointers
// 4. Pointer arithmetic

#include <iostream>
using namespace std;

// Simple game character class
class Character {
public:
    string name;
    int health;
    
    Character(string n, int h) : name(n), health(h) {}
    
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }
    
    void displayStats() {
        cout << name << " - Health: " << health << endl;
    }
};

int main() {
    // Create character
    Character hero("Hero", 100);
    
    // Basic pointer to character
    Character* heroPtr = &hero;
    
    // Array of health values
    int healthPotions[] = {20, 40, 60};
    int* potionPtr = healthPotions;
    
    // Use pointers
    heroPtr->takeDamage(30);
    heroPtr->displayStats();
    
    // Pointer arithmetic with array
    cout << "Available potions: ";
    for(int i = 0; i < 3; i++) {
        cout << *(potionPtr + i) << " ";
    }
    cout << endl;
    
    return 0;
}
