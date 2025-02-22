// Module 09 - Part 04: Memory Leaks and How to Avoid Them
// This tutorial demonstrates:
// 1. Common scenarios that cause memory leaks
// 2. How to identify potential memory leaks
// 3. Best practices to prevent memory leaks
// 4. Using tools and techniques for memory management

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class GameCharacter {
public:
    string name;
    int* health; // Dynamic health

    GameCharacter(string n, int h) : name(n) {
        cout << "Creating character: " << name << endl;
        health = new int(h); // Allocate memory for health
    }

    ~GameCharacter() {
        cout << "Deleting character: " << name << endl;
        delete health; // Free allocated memory
    }

    void showStats() {
        cout << "Name: " << name << ", Health: " << *health << endl;
    }
};

// Scenario 1: Forgetting to delete allocated memory
void scenario1_ResourceLeak() {
    // Memory leak: enemy is allocated but never freed
    GameCharacter* enemy = new GameCharacter("Orc", 80);
    // Oops! Forgot to delete enemy;
} // Memory leak occurs when enemy goes out of scope

// Scenario 2: Conditional Leak
void scenario2_ConditionalLeak(bool condition) {
    GameCharacter* character = new GameCharacter("Hero", 100);
    if (condition) {
        cout << "Condition is true, exiting early!\n";
        return; // Memory leak if condition is true
    }
    delete character;
}

// Scenario 3: Exception Leak
void scenario3_ExceptionLeak() {
    GameCharacter* character = new GameCharacter("Mage", 60);
    try {
        cout << "Casting a spell...\n";
        throw runtime_error("Spell failed!");
        character->showStats(); // This line is skipped if exception occurs
        delete character; // This line is also skipped!
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
        delete character; // Now it's safe to delete
        throw; // Re-throw the exception
    }
}

// Scenario 4: Pointer Reassignment Leak
void scenario4_PointerReassignment() {
    GameCharacter* character1 = new GameCharacter("Warrior", 120);
    GameCharacter* character2 = new GameCharacter("Archer", 90);
    character1 = character2; // Original Warrior is lost
    cout << "Reassigned pointer, original memory is lost!\n";
    delete character2; // Only Archer is deleted, Warrior is leaked
}

int main() {
    cout << "Memory Leak Scenarios and Solutions:\n";

    cout << "\n1. Basic Resource Leak:\n";
    scenario1_ResourceLeak();

    cout << "\n2. Conditional Leak:\n";
    scenario2_ConditionalLeak(true);
    scenario2_ConditionalLeak(false);

    cout << "\n3. Exception Leak:\n";
    try {
        scenario3_ExceptionLeak();
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "\n4. Pointer Reassignment Leak:\n";
    scenario4_PointerReassignment();

    return 0;
}
