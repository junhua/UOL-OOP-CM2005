// File: operators_starter.cpp
// Description: Learn about different types of operators in C++ through real-world examples

#include <iostream>
#include <iomanip>  // For output formatting

int main() {
    std::cout << "C++ Operators in Action\n";
    std::cout << "======================\n\n";

    // Arithmetic Operators - Shopping Cart Example
    std::cout << "Shopping Cart Example:\n";
    std::cout << "------------------\n";
    
    // TODO: Create variables for item price ($29.99) and quantity (3)
    // Hint: Use double for price and int for quantity
    
    // TODO: Calculate total before tax using multiplication
    // Hint: totalBeforeTax = itemPrice * quantity
    
    // TODO: Calculate tax amount (8% tax rate)
    // Hint: First create taxRate variable, then calculate taxAmount
    
    // TODO: Calculate final total by adding tax
    // Hint: Use addition operator
    
    // Set up output formatting for prices
    std::cout << std::fixed << std::setprecision(2);
    
    // TODO: Display all calculated values
    // Hint: Show item price, quantity, total before tax, tax amount, and final total
    std::cout << "\n";  // Extra line for readability

    // Assignment Operators - Score Tracking Example
    std::cout << "Score Tracking Example:\n";
    std::cout << "---------------------\n";
    
    // TODO: Initialize a score variable to 0
    
    // TODO: Use compound assignment operators to:
    // 1. Add 100 points (+=) for completing a level
    // 2. Double the score (*=) for getting a bonus
    // 3. Subtract 50 points (-=) for taking damage
    
    // TODO: Display score after each change
    std::cout << "\n";  // Extra line for readability

    // Comparison Operators - Price Comparison Example
    std::cout << "Price Comparison Example:\n";
    std::cout << "-----------------------\n";
    
    // TODO: Create variables for:
    // 1. Original price ($99.99)
    // 2. Sale price ($79.99)
    // 3. Premium threshold ($100.00)
    
    // TODO: Use comparison operators to:
    // 1. Check if item is discounted (sale price < original price)
    // 2. Check if item is premium (sale price >= premium threshold)
    
    // TODO: Display the results using std::boolalpha
    std::cout << "\n";  // Extra line for readability

    // Logical Operators - Discount Eligibility Example
    std::cout << "Discount Eligibility Example:\n";
    std::cout << "---------------------------\n";
    
    // TODO: Create boolean variables for:
    // 1. isMember (true)
    // 2. spentOver100 (false)
    // 3. isStudent (true)
    
    // TODO: Use logical operators to check:
    // 1. If customer gets member discount (AND operator)
    // 2. If customer qualifies for free shipping (OR operator)
    // 3. If customer is not eligible for discount (NOT operator)
    
    // TODO: Display all conditions and results
    std::cout << "\n";  // Extra line for readability

    // Operator Precedence - Price Calculation Example
    std::cout << "Price Calculation Example:\n";
    std::cout << "------------------------\n";
    
    // TODO: Create variables for:
    // 1. Base price ($100)
    // 2. Discount ($20)
    // 3. Tax percent (8%)
    
    // TODO: Calculate totals with different operator precedence:
    // 1. Without parentheses (multiplication before subtraction)
    // 2. With parentheses (subtraction before multiplication)
    
    // TODO: Display both results and explain the difference
    
    return 0;
}

/*
Learning Goals:
1. Understand and use arithmetic operators for calculations
2. Learn how to use compound assignment operators
3. Practice comparison operators with real-world examples
4. Apply logical operators for decision making
5. Understand operator precedence and its effects

Instructions:
1. Follow the TODOs in order
2. Read the hints carefully
3. Test your program after implementing each section
4. Compare your output with the final version
*/
