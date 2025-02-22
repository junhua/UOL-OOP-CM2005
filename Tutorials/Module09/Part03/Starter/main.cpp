// Module 09 - Part 03: Dynamic Memory Allocation
// This tutorial demonstrates:
// 1. Using new and delete operators
// 2. Dynamic array allocation and deallocation
// 3. Proper memory management practices
// 4. Common pitfalls to avoid

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

    ~GameCharacter() {
        cout << "Deleting character: " << name << endl;
    }

    void showStats() {
        cout << "Name: " << name << ", Health: " << health << endl;
    }
};

// Function to demonstrate dynamic allocation of a single GameCharacter
void allocateSingleCharacter() {
    // Dynamically allocate a GameCharacter
    GameCharacter* enemy = new GameCharacter("Orc", 80);

    // Use the dynamically allocated GameCharacter
    cout << "Enemy stats:\n";
    enemy->showStats();

    // Delete the GameCharacter when done
    delete enemy;
    enemy = nullptr; // Good practice to avoid dangling pointers
}

// Function to demonstrate dynamic array allocation
void allocateCharacterArray() {
    // Define the number of enemies
    int numEnemies = 3;

    // Create a dynamic array of GameCharacter pointers
    GameCharacter** enemies = new GameCharacter*[numEnemies];

    // Initialize the array
    for (int i = 0; i < numEnemies; ++i) {
        enemies[i] = new GameCharacter("Goblin " + to_string(i + 1), 50);
    }

    // Use the array
    cout << "\nEnemies:\n";
    for (int i = 0; i < numEnemies; ++i) {
        cout << "Enemy " << i + 1 << ": ";
        enemies[i]->showStats();
    }

    // Delete the array when done
    for (int i = 0; i < numEnemies; ++i) {
        delete enemies[i];
    }
    delete[] enemies;
    enemies = nullptr;
}

// Function to demonstrate common mistakes to avoid
void demonstrateCommonMistakes() {
    // 1. Forgetting to delete allocated memory (memory leak)
    GameCharacter* leak = new GameCharacter("Leaky", 20);
    // Oops! Forgot to delete leak;

    // 2. Using delete instead of delete[] for arrays
    GameCharacter* badArray = new GameCharacter[3]{{"A", 10}, {"B", 20}, {"C", 30}};
    //delete badArray; // Wrong! Should be delete[] badArray;

    // 3. Using deleted memory (dangling pointer)
    GameCharacter* dangling = new GameCharacter("Dangling", 30);
    dangling->showStats();
    delete dangling;
    dangling = nullptr;
    //dangling->showStats(); // Crash!

    // 4. Double deletion
    GameCharacter* doubleDelete = new GameCharacter("Double", 40);
    delete doubleDelete;
    //delete doubleDelete; // Crash!
}

int main() {
    cout << "1. Single GameCharacter Allocation:\n";
    allocateSingleCharacter();

    cout << "\n2. GameCharacter Array Allocation:\n";
    allocateCharacterArray();

    cout << "\n3. Common Mistakes Demonstration:\n";
    demonstrateCommonMistakes();

    return 0;
}
