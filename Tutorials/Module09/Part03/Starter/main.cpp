#include <iostream>
#include <string>
using namespace std;

/**
 * Module 9 - Part 3: Dynamic Memory Allocation
 * Practice Exercise Starter Code
 * 
 * Task: Create a program demonstrating:
 * 1. Basic allocation/deallocation
 * 2. Array handling
 * 3. Object management
 * 4. Memory safety
 */

// TODO: Create Resource class with:
// - Name and data members
// - Dynamic array allocation in constructor
// - Proper cleanup in destructor
// - Display and modify methods
// - Memory safety checks

// TODO: Create basicAllocation() function to demonstrate:
// - Single value allocation
// - Array allocation
// - Initialization
// - Proper cleanup

// TODO: Create dynamicArrays() function to show:
// - Runtime size determination
// - Array allocation
// - Array initialization
// - Safe traversal
// - Memory cleanup

// TODO: Create objectAllocation() function to demonstrate:
// - Single object allocation
// - Array of objects
// - Object usage
// - Proper cleanup

// TODO: Create memoryLeakPrevention() function to show:
// - Bad allocation practices
// - Memory leak scenarios
// - RAII pattern
// - Exception safety

int main() {
    try {
        cout << "Dynamic Memory Management Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Call all demonstration functions
        // - Basic allocation
        // - Dynamic arrays
        // - Object allocation
        // - Memory leak prevention
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
