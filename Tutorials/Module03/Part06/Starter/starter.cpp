#include <iostream>
using namespace std;

// TODO: Declare a global variable called 'programVersion'
// This will be accessible from all functions


// TODO: Create a function 'countCalls' that:
// - Uses a static local variable to count how many times it's been called
// - Prints the current count
// This demonstrates static local variables


// TODO: Create a function 'demonstrateScope' that:
// - Takes an int parameter that shadows a global variable
// - Has a local variable that shadows the parameter
// - Shows which variable is being accessed at each point


// TODO: Create a function 'modifyGlobal' that:
// - Modifies the global programVersion
// - Shows how to explicitly access a global variable when shadowed


int main() {
    cout << "Learning about variable scope!\n\n";
    
    // TODO: Print the global programVersion
    
    
    // Test the countCalls function
    cout << "\nTesting static local variable:\n";
    // TODO: Call countCalls several times
    
    
    // Test variable shadowing
    cout << "\nTesting variable shadowing:\n";
    // TODO: Call demonstrateScope
    
    
    // Test global variable modification
    cout << "\nTesting global variable modification:\n";
    // TODO: Print global variable before and after calling modifyGlobal
    
    
    // Demonstrate block scope
    cout << "\nDemonstrating block scope:\n";
    {
        // TODO: Create a variable that shadows one from outer scope
        // Print values of both variables
    }
    // TODO: Show that block-scoped variable no longer exists
    
    return 0;
}
