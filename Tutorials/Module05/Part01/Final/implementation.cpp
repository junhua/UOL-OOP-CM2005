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
    
    // Create a pointer to the hero character
    Character* heroPtr = &hero;
    
    // Initialize the array of health potion values
    int healthPotions[3] = {20, 40, 60};
    
    // Create a pointer to the health potions array
    int* potionPtr = healthPotions;
    
    // Use the hero pointer to call methods
    heroPtr->takeDamage(30);
    heroPtr->displayStats();
    
    // Use pointer arithmetic to display all potion values
    cout << "Available potions: ";
    for(int i = 0; i < 3; i++) {
        cout << *(potionPtr + i) << " ";
    }
    cout << endl;
    
    return 0;
}
