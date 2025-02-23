#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 9 - Part 5: Pointers to Objects
 * Practice Exercise Starter Code
 * 
 * Task: Create a program demonstrating:
 * 1. Basic object pointers
 * 2. Dynamic object creation
 * 3. Member access
 * 4. Inheritance and polymorphism
 */

// TODO: Create Shape base class with:
// - Protected name and area members
// - Virtual destructor
// - Pure virtual calculate method
// - Virtual display method

// TODO: Create Circle derived class with:
// - Radius member
// - Constructor initialization
// - Override calculate method
// - Override display method

// TODO: Create Rectangle derived class with:
// - Width and height members
// - Constructor initialization
// - Override calculate method
// - Override display method

// TODO: Create demonstrateBasicPointers() function to show:
// - Stack object creation
// - Pointer to stack object
// - Different access methods
// - Member access syntax

// TODO: Create demonstrateDynamicObjects() function to demonstrate:
// - Single dynamic object
// - Array of objects
// - Member access
// - Proper cleanup

// TODO: Create demonstratePolymorphism() function to show:
// - Base class pointers
// - Derived class objects
// - Virtual function calls
// - Dynamic dispatch

// TODO: Create ShapeManager class to demonstrate:
// - Object pointer container
// - Dynamic object management
// - Polymorphic operations
// - Resource cleanup

int main() {
    try {
        cout << "Object Pointer Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // TODO: Call all demonstration functions
        // - Basic pointer usage
        // - Dynamic objects
        // - Polymorphism
        // - Shape management
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
