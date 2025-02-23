#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Module 9 - Part 6: Function Pointers
 * Practice Exercise Starter Code
 * 
 * Task: Create a program demonstrating:
 * 1. Basic function pointers
 * 2. Callback functions
 * 3. Function pointer arrays
 * 4. Member function pointers
 */

// TODO: Create basic arithmetic functions:
// - add: returns a + b
// - subtract: returns a - b
// - multiply: returns a * b
// - divide: returns a / b (handle division by zero)

// TODO: Create function pointer type definition for arithmetic operations

// TODO: Create Calculator class with:
// - Vector of operation name/function pairs
// - Registration method
// - Operation execution method
// - Operation listing method

// TODO: Create processNumbers function to demonstrate callbacks:
// - Takes vector of numbers and operation
// - Applies operation to adjacent numbers
// - Outputs results

// TODO: Create demonstrateBasicPointers function to show:
// - Direct function calls
// - Function pointer assignment
// - Function pointer calls
// - Different calling syntaxes

// TODO: Create demonstrateCallbacks function to show:
// - Vector processing with different operations
// - Callback function usage
// - Result demonstration

// TODO: Create demonstrateFunctionArray function to show:
// - Array of function pointers
// - Operation name mapping
// - Multiple operation execution
// - Result display

// TODO: Create MathProcessor class to demonstrate member functions:
// - Value storage and operations
// - Member function implementation
// - Value access method

// TODO: Create demonstrateMemberPointers function to show:
// - Member function pointer types
// - Member function pointer array
// - Operation execution through pointers
// - Result tracking

int main() {
    try {
        cout << "Function Pointer Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Call all demonstration functions
        // - Basic pointer usage
        // - Callback demonstration
        // - Function array usage
        // - Member pointer usage
        
        // TODO: Create and use Calculator
        // - Create instance
        // - List operations
        // - Perform calculations
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
