// File: basic_programs_starter.cpp
// Description: Learn how to create complete programs with real-world examples

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

// TODO: Implement the clearInputBuffer function
// This function should:
// 1. Clear any error flags on cin
// 2. Ignore any remaining characters in the input buffer
// Hint: Use std::cin.clear() and std::cin.ignore()

// TODO: Implement the getValidInteger function
// Parameters:
// - prompt: Message to display when asking for input
// - min: Minimum acceptable value
// - max: Maximum acceptable value
// The function should:
// 1. Display the prompt
// 2. Get integer input from user
// 3. Validate input is within range
// 4. Handle invalid input (non-numbers)
// 5. Keep asking until valid input is received
// 6. Return the valid number

// TODO: Implement the formatCurrency function
// Parameters:
// - amount: The amount to format
// The function should:
// 1. Format the amount with 2 decimal places
// 2. Add a dollar sign
// 3. Return the formatted string
// Hint: Use stringstream and std::fixed

// TODO: Implement the calculateTotal function
// Parameters:
// - price: Item price
// - quantity: Number of items
// - taxRate: Tax rate (e.g., 0.08 for 8%)
// The function should:
// 1. Calculate subtotal (price * quantity)
// 2. Calculate tax amount
// 3. Return total (subtotal + tax)

int main() {
    std::cout << "Basic Programs Demo\n";
    std::cout << "==================\n\n";

    // Restaurant Order System Example
    std::cout << "Restaurant Order System\n";
    std::cout << "----------------------\n";
    
    // TODO: Get customer information
    // 1. Declare a string variable for customer name
    // 2. Prompt for and read the customer's name
    // Hint: Use std::getline for names with spaces
    
    // TODO: Initialize order variables
    // 1. Create arrays for menu items and prices
    // 2. Define constants for tax rate
    // 3. Create a vector to store quantities
    // Hint: Look at the menu items and prices in the final version
    
    // TODO: Implement the order loop
    // 1. Display the menu
    // 2. Get valid choice from user
    // 3. Get valid quantity if item selected
    // 4. Update order quantities
    // 5. Continue until user chooses to finish
    // Hint: Use a while loop and the getValidInteger function
    
    // TODO: Calculate and display receipt
    // 1. Show customer name
    // 2. List all ordered items with quantities and subtotals
    // 3. Show subtotal, tax, and final total
    // Hint: Use the formatCurrency function
    
    // Temperature Monitoring Example
    std::cout << "\nTemperature Monitoring\n";
    std::cout << "---------------------\n";
    
    // TODO: Implement temperature monitoring
    // 1. Define number of readings to take
    // 2. Create vector to store temperatures
    // 3. Get temperature readings from user
    // 4. Calculate average, highest, and lowest temperatures
    // 5. Display statistics
    // 6. Show warnings for extreme temperatures
    // Hint: Use a for loop to collect readings
    
    return 0;
}

/*
Learning Goals:
1. Understand how to structure a complete program
2. Practice implementing input validation
3. Learn to use functions for code organization
4. Handle different data types appropriately
5. Format output for better user experience

Instructions:
1. Follow the TODOs in order
2. Test each function as you implement it
3. Use constants for fixed values
4. Handle edge cases and invalid input
5. Compare your implementation with basic_programs.cpp
*/
