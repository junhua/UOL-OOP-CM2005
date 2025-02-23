#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

/**
 * Module 9 - Part 4: Memory Leaks
 * Practice Exercise Starter Code
 * 
 * Task: Create a program demonstrating:
 * 1. Common leak scenarios
 * 2. Proper cleanup practices
 * 3. RAII pattern
 * 4. Smart pointer usage
 */

// TODO: Create Resource class with:
// - Name and data members
// - Dynamic array allocation
// - Proper cleanup
// - Display method

// TODO: Create demonstrateLeaks() function to show:
// - Lost pointer scenario
// - Missing delete scenario
// - Exception leak scenario
// - Memory leak patterns

// TODO: Create demonstrateRAII() function to demonstrate:
// - Automatic cleanup
// - Exception safety
// - Scope-based management
// - Resource handling

// TODO: Create demonstrateSmartPointers() function to show:
// - unique_ptr usage
// - shared_ptr usage
// - weak_ptr usage
// - Reference counting

// TODO: Create ResourceManager class to demonstrate:
// - Smart pointer container
// - Automatic resource management
// - Safe resource access
// - Memory leak prevention

int main() {
    try {
        cout << "Memory Leak Prevention Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Call all demonstration functions
        // - Memory leak examples
        // - RAII demonstration
        // - Smart pointer usage
        // - Resource management
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
