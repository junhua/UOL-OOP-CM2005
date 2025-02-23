#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 6 - Part 3: Getter and Setter Methods
 * Practice Exercise Starter Code
 * 
 * Task: Create a product inventory system with:
 * 1. Product class with validation
 * 2. Inventory management
 * 3. Price calculations
 * 4. Stock tracking
 */

// TODO: Create Product class with:
// - Private members for id, name, price, stock level, tax rate
// - Private validation methods
// - Constructor with validation
// - Getters for all properties
// - Computed getters for tax amount, total price, stock status
// - Setters with validation for price, stock, tax rate
// - Methods for stock management (add/remove)
// - Display method

// TODO: Create Inventory class with:
// - Private vector of products
// - Method to add products
// - Method to find products by ID
// - Method to display inventory

int main() {
    try {
        // TODO: Create inventory
        
        // TODO: Add products with different properties
        
        // TODO: Display initial inventory
        
        // TODO: Test stock management
        // - Add and remove stock
        // - Test invalid operations
        
        // TODO: Test price management
        // - Update prices
        // - Test invalid values
        
        // TODO: Display final inventory
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
