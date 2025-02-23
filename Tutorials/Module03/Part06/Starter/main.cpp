#include <iostream>
using namespace std;

/**
 * Module 3 - Part 6: Scope of Variables
 * Practice Exercise Starter Code
 * 
 * Task: Create a program that demonstrates different variable scopes:
 * 1. Global variables
 * 2. Local variables
 * 3. Static variables
 * 4. Parameter scope
 * 5. Variable shadowing
 */

// TODO: Add global variables for:
// - A counter
// - A message string

// TODO: Implement countCalls function that:
// - Uses a static variable to count calls
// - Prints number of times it's been called

// TODO: Implement processValue function that:
// - Takes an integer parameter
// - Creates a local variable
// - Updates global counter
// - Prints all values

// TODO: Implement demonstrateShadowing function that:
// - Creates local variable with same name as global
// - Shows how to access both local and global versions

int main() {
    // Test static variable
    cout << "Testing static variable:" << endl;
    // TODO: Call countCalls multiple times
    
    // Test parameter and local scope
    cout << "\nTesting parameter and local scope:" << endl;
    // TODO: Call processValue with different values
    
    // Test variable shadowing
    cout << "\nTesting variable shadowing:" << endl;
    // TODO: Call demonstrateShadowing
    
    // Demonstrate block scope
    cout << "\nTesting block scope:" << endl;
    // TODO: Create a block with local variable
    
    return 0;
}
