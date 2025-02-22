// Module 09 - Part 06: Pointers and Objects
// This tutorial demonstrates:
// 1. Object pointers and dynamic object creation
// 2. Arrow operator (->) for accessing members
// 3. Pointers to member functions
// 4. Array of objects using pointers

#include <iostream>
#include <string>
using namespace std;

class GameCharacter {
public:
    string name;
    int health;

    GameCharacter(string n, int h) : name(n), health(h) {
        cout << "Creating character: " << name << endl;
    }

    void showStats() {
        cout << "Name: " << name << ", Health: " << health << endl;
    }
};

// Function to demonstrate basic object pointer usage
void demonstrateObjectPointers() {
    // 1. Create object on stack
    GameCharacter hero("Hero", 100);

    // 2. Create pointer to object
    GameCharacter* heroPtr = &hero;

    // 3. Access members using -> operator
    cout << "Hero's name: " << heroPtr->name << endl;
    heroPtr->showStats();
}

// Function to demonstrate dynamic object creation
void demonstrateDynamicObjects() {
    // 1. Create object dynamically using new
    GameCharacter* enemy = new GameCharacter("Orc", 80);

    // 2. Use the object
    enemy->showStats();

    // 3. Delete the object
    delete enemy;
    enemy = nullptr;
}

// Function to work with array of object pointers
void demonstrateObjectArray() {
    // 1. Create array of GameCharacter pointers
    GameCharacter* party[3];

    // 2. Allocate each object
    party[0] = new GameCharacter("Warrior", 120);
    party[1] = new GameCharacter("Mage", 80);
    party[2] = new GameCharacter("Healer", 100);

    // 3. Use the objects
    cout << "Party Stats:\n";
    for (int i = 0; i < 3; i++) {
        party[i]->showStats();
    }

    // 4. Clean up memory
    for (int i = 0; i < 3; i++) {
        delete party[i];
    }
}

int main() {
    cout << "1. Basic Object Pointer Usage:" << endl;
    demonstrateObjectPointers();

    cout << "\n2. Dynamic Object Creation:" << endl;
    demonstrateDynamicObjects();

    cout << "\n3. Array of Objects:" << endl;
    demonstrateObjectArray();

    return 0;
}
