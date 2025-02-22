// Module 09 - Part 01: Introduction to Pointers
// This tutorial demonstrates:
// 1. What are pointers and memory addresses
// 2. Declaring and initializing pointers
// 3. Dereferencing pointers
// 4. Null pointers and pointer safety

#include <iostream>
#include <string>

class GameCharacter {
public:
    std::string name;
    int health;

    GameCharacter(std::string n, int h) : name(n), health(h) {
        std::cout << "Creating character: " << name << std::endl;
    }

    void showStats() {
        std::cout << "Name: " << name << ", Health: " << health << std::endl;
    }
};

int main() {
    // Declare a GameCharacter object
    GameCharacter hero("Hero", 100);

    // Declare a pointer to the GameCharacter object
    GameCharacter* heroPtr = &hero;

    // Print the GameCharacter object's value
    std::cout << "Hero's name: " << hero.name << std::endl;

    // Print the GameCharacter object's memory address
    std::cout << "Hero's memory address: " << &hero << std::endl;

    // Print the pointer's value (which should be the GameCharacter's address)
    std::cout << "heroPtr's value: " << heroPtr << std::endl;

    // Print the value that the pointer points to (dereferencing)
    std::cout << "Value pointed to by heroPtr: " << heroPtr->name << ", " << heroPtr->health << std::endl;

    // Modify the GameCharacter object through the pointer
    heroPtr->health = 150;
    std::cout << "Modified health through pointer:\n";
    heroPtr->showStats();

    // Demonstrate null pointer safety
    GameCharacter* nullPtr = nullptr;
    if (nullPtr != nullptr) {
        nullPtr->showStats(); // This will not execute
    } else {
        std::cout << "nullPtr is null, so it is not dereferenced.\n";
    }

    return 0;
}
