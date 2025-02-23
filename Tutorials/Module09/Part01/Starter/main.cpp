#include <iostream>
#include <string>
using namespace std;

/**
 * Module 9 - Part 1: Introduction to Pointers
 * Practice Exercise Starter Code
 * 
 * Task: Create a program demonstrating:
 * 1. Different types of pointers
 * 2. Address operations
 * 3. Value modifications
 * 4. Pointer arithmetic
 */

// TODO: Create demonstratePointers() function to show:
// - Basic pointer declaration and initialization
// - Address-of and dereference operators
// - Value modification through pointers
// - Output original value and pointer value

// TODO: Create multiplePointers() function to demonstrate:
// - Different data type pointers (int, double, char, string)
// - Initialization with different values
// - Accessing values through pointers
// - Output all values and their addresses

// TODO: Create pointerArithmetic() function to show:
// - Array declaration and initialization
// - Pointer to array
// - Moving through array with pointer arithmetic
// - Accessing elements at different positions

// TODO: Create nullPointers() function to demonstrate:
// - Null pointer initialization
// - Null pointer checks
// - Dynamic memory allocation
// - Memory cleanup and null reset

// TODO: Create constPointers() function to show:
// - Pointer to const value
// - Const pointer to value
// - Const pointer to const value
// - Modification restrictions

int main() {
    try {
        cout << "Pointer Basics Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Call all demonstration functions
        // - Basic pointer operations
        // - Multiple data type pointers
        // - Pointer arithmetic with arrays
        // - Null pointer handling
        // - Const pointer variations
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
