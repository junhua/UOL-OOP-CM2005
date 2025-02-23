// File: practice_starter.cpp
// Description: Practice exercises for working with C++ operators

#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Operator Practice Exercises\n";
    std::cout << "=========================\n\n";

    // Exercise 1: Shopping Cart Calculator
    std::cout << "Exercise 1: Shopping Cart Calculator\n";
    std::cout << "--------------------------------\n";
    
    // TODO: Initialize variables for:
    // 1. Two items with different prices ($24.99 and $19.99)
    // 2. Quantities for each item (2 and 3)
    // 3. Discount percentage (15%)
    // 4. Tax rate (8%)
    
    // TODO: Calculate:
    // 1. Subtotal (price * quantity for each item, then sum)
    // 2. Discount amount (subtotal * discount percentage)
    // 3. Amount after discount
    // 4. Tax amount
    // 5. Final total
    
    // TODO: Display all calculations with proper formatting
    // Hint: Use std::fixed and std::setprecision(2) for prices
    std::cout << "\n";

    // Exercise 2: Grade Calculator
    std::cout << "Exercise 2: Grade Calculator\n";
    std::cout << "--------------------------\n";
    
    // TODO: Create variables for:
    // 1. Homework score and weight (30% of final grade)
    // 2. Midterm score and weight (30% of final grade)
    // 3. Final exam score and weight (40% of final grade)
    
    // TODO: Calculate:
    // 1. Weighted average for final grade
    // 2. Determine if passed (grade >= 70.0)
    
    // TODO: Display:
    // 1. All scores and their weights
    // 2. Final calculated grade
    // 3. Pass/Fail status
    std::cout << "\n";

    // Exercise 3: Temperature Converter
    std::cout << "Exercise 3: Temperature Converter\n";
    std::cout << "------------------------------\n";
    
    // TODO: Create variables for test temperatures:
    // 1. Celsius temperature (25.0°C)
    // 2. Fahrenheit temperature (98.6°F)
    
    // TODO: Implement conversions:
    // 1. Celsius to Fahrenheit: (C × 9/5) + 32
    // 2. Fahrenheit to Celsius: (F - 32) × 5/9
    
    // TODO: Validate temperature ranges:
    // Check if temperatures are between -50°C and 50°C
    // Hint: Use logical operators to combine conditions
    
    // TODO: Display results with proper formatting
    // Show both conversions and whether they're in valid ranges
    std::cout << "\n";

    // Exercise 4: Game Score Tracker
    std::cout << "Exercise 4: Game Score Tracker\n";
    std::cout << "---------------------------\n";
    
    // TODO: Initialize game variables:
    // 1. Score (starting at 0)
    // 2. High score (1000)
    // 3. Point multiplier (1.0)
    // 4. Bonus round status (false)
    
    // TODO: Simulate game events:
    // 1. Add 100 points (use +=)
    // 2. Activate bonus round (multiplier = 2.0)
    // 3. Double current points (use *=)
    // 4. Add 150 more points
    
    // TODO: Check game conditions using logical operators:
    // 1. Check if score beat high score
    // 2. Check if player got bonus AND beat high score
    // 3. Check if player earned extra life (score >= 500 OR bonus round active)
    
    // TODO: Display all game status information
    // Show score, high score, and all condition results
    
    return 0;
}

/*
Learning Goals:
1. Practice using arithmetic operators for calculations
2. Understand operator precedence in complex calculations
3. Use comparison operators for decision making
4. Apply logical operators to combine conditions
5. Format output for better readability

Instructions:
1. Complete each exercise following the TODOs
2. Test your program after completing each exercise
3. Make sure to handle decimal numbers appropriately
4. Use proper variable types for different kinds of data
5. Compare your solution with practice_solution.cpp
*/
