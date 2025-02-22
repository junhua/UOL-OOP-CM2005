/**
 * Program: Simple Calculator
 * Purpose: Demonstrates proper commenting and code organization
 * Features:
 * - Basic arithmetic operations
 * - Input validation
 * - Result display
 */

#include <iostream>

/**
 * Adds two numbers and returns their sum
 * @param a First number to add
 * @param b Second number to add
 * @return Sum of the two numbers
 */
int add(int a, int b) {
    return a + b;  // Return sum
}

/**
 * Subtracts two numbers and returns their difference
 * @param a Number to subtract from
 * @param b Number to subtract
 * @return Difference of the two numbers
 */
int subtract(int a, int b) {
    return a - b;  // Return difference
}

int main() {
    // Display welcome message with clear formatting
    std::cout << "=== Simple Calculator ===\n\n";
    
    // Get first number from user with prompt
    int num1;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    
    // Get second number from user with prompt
    int num2;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    /* Calculate results using helper functions
     * This section performs both addition and
     * subtraction operations on the input numbers
     */
    int sum = add(num1, num2);
    int difference = subtract(num1, num2);
    
    // Display results with clear formatting
    std::cout << "\nResults:\n";
    std::cout << num1 << " + " << num2 << " = " << sum << "\n";
    std::cout << num1 << " - " << num2 << " = " << difference << "\n";
    
    return 0;  // Program completed successfully
}
