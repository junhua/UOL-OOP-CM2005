#include <iostream>
using namespace std;

/**
 * Module 3 - Part 6: Scope of Variables
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Global variables accessible everywhere
 * 2. Local variables limited to their scope
 * 3. Static variables that maintain state
 * 4. Parameter scope in functions
 * 5. Variable shadowing and resolution
 */

// Global variables
int globalCounter = 0;
string globalMessage = "Hello from global!";

// Function using static variable to maintain state
void countCalls() {
    static int calls = 0;  // Initialized only once
    calls++;  // Value persists between calls
    cout << "This function has been called " << calls << " times" << endl;
}

// Function demonstrating parameter and local scope
void processValue(int value) {  // Parameter scope
    int localValue = value * 2;  // Local scope
    globalCounter++;  // Accessing global
    
    cout << "Parameter value: " << value << endl;
    cout << "Local value: " << localValue << endl;
    cout << "Global counter: " << globalCounter << endl;
}

// Function demonstrating variable shadowing
void demonstrateShadowing() {
    string globalMessage = "Hello from local!";  // Shadows global
    
    cout << "Local message: " << globalMessage << endl;
    cout << "Global message: " << ::globalMessage << endl;  // Access global with ::
}

int main() {
    // Test static variable
    cout << "Testing static variable:" << endl;
    for (int i = 0; i < 3; i++) {
        countCalls();  // Each call increments static counter
    }
    
    // Test parameter and local scope
    cout << "\nTesting parameter and local scope:" << endl;
    processValue(5);   // Creates new parameter and local variables
    processValue(10);  // Creates new instances again
    
    // Test variable shadowing
    cout << "\nTesting variable shadowing:" << endl;
    demonstrateShadowing();  // Shows local vs global access
    
    // Demonstrate block scope
    cout << "\nTesting block scope:" << endl;
    {
        int blockVar = 100;  // Only exists in this block
        cout << "Inside block: " << blockVar << endl;
    }  // blockVar is destroyed here
    // cout << blockVar;  // Would cause error - out of scope
    
    // Show final global counter
    cout << "\nFinal global counter: " << globalCounter << endl;
    
    return 0;
}
