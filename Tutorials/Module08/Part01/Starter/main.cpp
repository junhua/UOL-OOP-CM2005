#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/**
 * Module 8 - Part 1: Introduction to Polymorphism
 * Practice Exercise Starter Code
 * 
 * Task: Create a drawing application demonstrating:
 * 1. Shape hierarchy with different shapes
 * 2. Common interface for all shapes
 * 3. Collection of shapes
 * 4. Polymorphic behavior
 */

// TODO: Create Shape abstract base class with:
// - Protected color member
// - Constructor and virtual destructor
// - Pure virtual methods:
//   * draw()
//   * getArea()
//   * getPerimeter()
// - Virtual displayInfo() with default implementation
// - Getter for color

// TODO: Create Circle class that:
// - Inherits from Shape
// - Adds radius member
// - Implements all virtual methods
// - Draws circle using ASCII art

// TODO: Create Rectangle class that:
// - Inherits from Shape
// - Adds width and height members
// - Implements all virtual methods
// - Draws rectangle using ASCII art

// TODO: Create Triangle class that:
// - Inherits from Shape
// - Adds base and height members
// - Implements all virtual methods
// - Draws triangle using ASCII art

// TODO: Create DrawingCanvas class to:
// - Manage collection of shapes
// - Add shapes to canvas
// - Draw all shapes
// - Show statistics

int main() {
    try {
        // TODO: Create drawing canvas
        
        // TODO: Add different shapes
        // - Circle with radius
        // - Rectangle with width and height
        // - Triangle with base and height
        
        // TODO: Draw all shapes
        
        // TODO: Show canvas statistics
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
