// File: practice_starter.cpp
// Description: Practice exercises for creating complete programs

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <sstream>

// TODO: Implement the clearInputBuffer function
// This function should:
// 1. Clear any error flags on cin
// 2. Ignore any remaining characters in the input buffer
// Hint: Use std::cin.clear() and std::cin.ignore()

// TODO: Implement the getValidDouble function
// Parameters:
// - prompt: Message to display when asking for input
// - min: Minimum acceptable value
// - max: Maximum acceptable value
// The function should:
// 1. Display the prompt
// 2. Get double input from user
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
// Hint: Use ostringstream and std::fixed

int main() {
    std::cout << "Basic Programs Practice Exercises\n";
    std::cout << "================================\n\n";

    // Exercise 1: Restaurant Order System
    std::cout << "Exercise 1: Restaurant Order System\n";
    std::cout << "--------------------------------\n";
    
    // TODO: Create the menu system
    // 1. Define arrays for menu items and prices
    // 2. Create vector for order quantities
    // 3. Set up tax rate and discount rules
    // Hint: Look at the menu items and prices in practice_solution.cpp
    
    // TODO: Implement order taking
    // 1. Display the menu with prices
    // 2. Get item choice and quantity from user
    // 3. Validate all input
    // 4. Keep taking orders until user is done
    
    // TODO: Calculate and display receipt
    // 1. Show all ordered items and quantities
    // 2. Calculate subtotal
    // 3. Apply discount if eligible
    // 4. Add tax
    // 5. Show final total
    // Hint: Use the formatCurrency function
    
    // Exercise 2: Bank Account Manager
    std::cout << "\nExercise 2: Bank Account Manager\n";
    std::cout << "-----------------------------\n";
    
    // TODO: Set up bank account
    // 1. Initialize account balance
    // 2. Create vector for transaction history
    
    // TODO: Implement banking operations
    // 1. Show current balance
    // 2. Create menu (Deposit, Withdraw, View History, Exit)
    // 3. Handle each operation with validation
    // 4. Keep track of all transactions
    // Hint: Use a loop and switch statement
    
    // Exercise 3: Temperature Monitoring System
    std::cout << "\nExercise 3: Temperature Monitoring System\n";
    std::cout << "----------------------------------\n";
    
    // TODO: Set up temperature monitoring
    // 1. Define number of readings to take
    // 2. Create vector for temperature storage
    // 3. Set temperature thresholds for alerts
    
    // TODO: Implement temperature tracking
    // 1. Get temperature readings
    // 2. Validate each reading
    // 3. Show alerts for extreme temperatures
    // 4. Calculate statistics (average, high, low)
    // 5. Display summary with alerts
    
    // Exercise 4: Student Grade Calculator
    std::cout << "\nExercise 4: Student Grade Calculator\n";
    std::cout << "-------------------------------\n";
    
    // TODO: Set up grade calculation
    // 1. Define grade weights (homework 30%, midterm 30%, final 40%)
    // 2. Get grades with validation
    // 3. Calculate weighted average
    
    // TODO: Implement grade reporting
    // 1. Calculate final grade
    // 2. Determine letter grade
    // 3. Display grade report
    // 4. Show appropriate message based on grade
    // Hint: Use if-else statements for grade ranges
    
    return 0;
}

/*
Learning Goals:
1. Create complete, interactive programs
2. Implement input validation
3. Use functions for code organization
4. Handle different data types
5. Format output for readability
6. Process and validate user input
7. Maintain program state
8. Provide user feedback

Instructions:
1. Complete each exercise following the TODOs
2. Test your program with different inputs
3. Handle edge cases and invalid input
4. Format output to be user-friendly
5. Compare your solution with practice_solution.cpp
*/
