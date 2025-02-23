/**
 * Part 04: Input and Output - Final Implementation
 * 
 * This program demonstrates:
 * 1. Basic input/output operations
 * 2. Input validation techniques
 * 3. Output formatting
 * 4. Working with different data types
 * 5. Error handling
 */

#include <iostream>
#include <string>
#include <iomanip>  // For output formatting
#include <limits>   // For numeric limits

// Function to clear input buffer and handle invalid input
void clearInputBuffer() {
    std::cin.clear();  // Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    // Set up initial output formatting
    std::cout << std::fixed;  // Use fixed-point notation
    
    // Program header with formatting
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character
    std::cout << std::setw(30) << "C++ Input/Output Demo" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character

    // 1. Basic string input with getline
    std::string fullName;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);

    // 2. Numeric input with validation
    int age;
    while(true) {
        std::cout << "Enter your age: ";
        if(std::cin >> age && age > 0 && age < 150) {
            break;  // Valid input received
        }
        std::cout << "Invalid age. Please enter a number between 1 and 150.\n";
        clearInputBuffer();
    }
    clearInputBuffer();  // Clear buffer for next input

    // 3. Floating point input with validation
    double height;
    while(true) {
        std::cout << "Enter your height in meters: ";
        if(std::cin >> height && height > 0 && height < 3) {
            break;  // Valid input received
        }
        std::cout << "Invalid height. Please enter a number between 0 and 3.\n";
        clearInputBuffer();
    }

    // 4. Display information with formatting
    std::cout << "\nUser Information:\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character
    
    // Name with left alignment
    std::cout << std::left << std::setw(15) << "Name:" << fullName << std::endl;
    
    // Age with right alignment
    std::cout << std::left << std::setw(15) << "Age:" << age << " years" << std::endl;
    
    // Height with precision
    std::cout << std::left << std::setw(15) << "Height:" 
              << std::setprecision(2) << height << " meters" << std::endl;

    // 5. Demonstrate different number formats
    double pi = 3.14159265359;
    std::cout << "\nNumber Formatting Examples:\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character
    
    // Fixed notation
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Fixed (2):      " << pi << std::endl;
    
    // Scientific notation
    std::cout << std::scientific;
    std::cout << "Scientific:     " << pi << std::endl;
    
    // More decimal places
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Fixed (6):      " << pi << std::endl;

    // 6. Create a formatted table
    std::cout << "\nFormatted Table Example:\n";
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character
    
    // Table headers
    std::cout << std::left
              << std::setw(10) << "Number"
              << std::setw(15) << "Square"
              << std::setw(15) << "Cube"
              << std::endl;
    
    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');  // Reset fill character
    
    // Table data
    for(int i = 1; i <= 5; i++) {
        std::cout << std::left
                  << std::setw(10) << i
                  << std::setw(15) << (i * i)
                  << std::setw(15) << (i * i * i)
                  << std::endl;
    }

    return 0;
}

/*
Key Concepts Demonstrated:

1. Input Operations
   - Basic cin usage
   - getline for strings
   - Input validation
   - Buffer clearing
   - Error handling

2. Output Operations
   - Basic cout usage
   - Output formatting
   - Field width control
   - Alignment options
   - Fill characters

3. Formatting
   - Fixed notation
   - Scientific notation
   - Precision control
   - Field width
   - Alignment
   - Custom separators

4. Best Practices
   - Always validate input
   - Clear input buffer
   - Handle error cases
   - Format for readability
   - Use appropriate precision
   - Provide user feedback
*/
