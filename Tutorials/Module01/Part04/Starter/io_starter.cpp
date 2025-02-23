/**
 * Part 04: Input and Output - Starter Code
 * 
 * This program demonstrates basic input/output operations in C++
 * and provides practice with formatting and input validation.
 * 
 * Learning Objectives:
 * 1. Use cin and cout for I/O operations
 * 2. Format output for readability
 * 3. Handle different types of input
 * 4. Validate user input
 */

#include <iostream>
#include <string>
#include <iomanip>  // For output formatting
#include <limits>   // For numeric limits

int main() {
    std::cout << "C++ Input/Output Practice\n";
    std::cout << "========================\n\n";

    // TODO: Basic output
    // Hint: Use cout to print a welcome message
    // Example: std::cout << "Welcome!" << std::endl;

    
    // TODO: Basic input
    // Hint: Create variables and use cin to get user input
    // Example: std::cin >> variable;
    std::string name;
    int age;
    

    // TODO: Format and display the collected information
    // Hint: Use cout with formatting manipulators
    // Example: std::cout << std::setw(10) << "Name: " << name << std::endl;

    
    // TODO: Numeric input with validation
    // Hint: Use a while loop to validate input
    double number;
    std::cout << "\nEnter a number: ";
    // Add validation code here
    
    
    // TODO: Working with different numeric formats
    // Hint: Use fixed, scientific, and setprecision
    double pi = 3.14159265359;
    // Add formatting code here
    
    
    // TODO: Create a formatted table
    // Hint: Use setw and alignment manipulators
    std::cout << "\nFormatted Table:\n";
    // Add table formatting code here
    
    
    // TODO: Handle string input with spaces
    // Hint: Use getline after clearing the input buffer
    std::string fullName;
    // Add string input code here
    
    
    return 0;
}

/*
Instructions:
1. Complete each TODO section
2. Test the program with different inputs
3. Try to break the input validation
4. Experiment with formatting options
5. Create clear, readable output

Tips:
- Always validate user input
- Clear the input buffer when needed
- Use appropriate data types
- Format output for readability
- Handle error cases
- Provide user feedback
*/
