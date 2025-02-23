#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Function to clear input buffer and handle failed input
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid number input with range validation
int getNumberInRange(int min, int max) {
    int number;
    while (true) {
        std::cout << "Enter a number between " << min << " and " << max << ": ";
        if (std::cin >> number) {
            if (number >= min && number <= max) {
                clearInputBuffer();
                return number;
            }
            std::cout << "Number must be between " << min << " and " << max << "!\n";
        } else {
            std::cout << "Invalid input! Please enter a number.\n";
            clearInputBuffer();
        }
    }
}

// Function to demonstrate basic output formatting
void demonstrateBasicOutput() {
    std::cout << "\n=== Basic Output Examples ===\n";
    std::cout << "1. Simple output: " << "Hello, World!" << std::endl;
    
    // Multiple items in one statement
    int age = 25;
    double height = 1.75;
    std::cout << "2. Multiple items: Age = " << age 
              << ", Height = " << height << "m\n";
    
    // Different number formats
    std::cout << "3. Number formatting:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "   Fixed point (2 decimals): " << 3.14159 << std::endl;
    std::cout << std::scientific;
    std::cout << "   Scientific notation: " << 3.14159 << std::endl;
    std::cout << std::fixed; // Reset to fixed
}

// Function to demonstrate table formatting
void demonstrateTableFormatting() {
    std::cout << "\n=== Table Formatting Example ===\n";
    
    // Header
    std::cout << std::left << std::setw(15) << "Product"
              << std::right << std::setw(10) << "Price"
              << std::right << std::setw(10) << "Quantity" << std::endl;
    
    // Separator
    std::cout << std::setfill('-') << std::setw(35) << "" << std::endl;
    std::cout << std::setfill(' '); // Reset fill character
    
    // Data rows
    std::cout << std::left << std::setw(15) << "Apple"
              << std::right << std::setw(10) << "$0.99"
              << std::right << std::setw(10) << "5" << std::endl;
    std::cout << std::left << std::setw(15) << "Orange"
              << std::right << std::setw(10) << "$0.75"
              << std::right << std::setw(10) << "3" << std::endl;
}

// Function to demonstrate string input handling
void demonstrateStringInput() {
    std::cout << "\n=== String Input Examples ===\n";
    
    std::string word, line;
    
    // Single word input
    std::cout << "Enter a single word: ";
    std::cin >> word;
    clearInputBuffer();
    std::cout << "You entered the word: " << word << std::endl;
    
    // Full line input
    std::cout << "Enter a full line of text: ";
    std::getline(std::cin, line);
    std::cout << "You entered the line: " << line << std::endl;
}

// Function to demonstrate a simple form with validation
void demonstrateForm() {
    std::cout << "\n=== User Information Form ===\n";
    
    // Get name (allowing spaces)
    std::string name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    
    // Get age with validation
    int age = getNumberInRange(0, 150);
    
    // Get height with validation
    double height;
    do {
        std::cout << "Enter your height in meters (e.g., 1.75): ";
        if (std::cin >> height && height > 0 && height < 3) {
            break;
        }
        std::cout << "Invalid height! Please enter a value between 0 and 3 meters.\n";
        clearInputBuffer();
    } while (true);
    
    // Display formatted results
    std::cout << "\n=== User Information Summary ===\n";
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::left << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::left << std::setw(15) << "Age:" << age << " years" << std::endl;
    std::cout << std::left << std::setw(15) << "Height:" 
              << std::fixed << std::setprecision(2) << height << " m" << std::endl;
}

int main() {
    std::cout << "C++ Input/Output Examples\n";
    std::cout << "=======================\n";
    
    // Demonstrate different aspects of I/O
    demonstrateBasicOutput();
    demonstrateTableFormatting();
    demonstrateStringInput();
    demonstrateForm();
    
    std::cout << "\nProgram completed successfully!\n";
    return 0;
}

/*
This program demonstrates:
1. Basic output formatting
2. Table creation with proper alignment
3. Different types of input handling
4. Input validation and error handling
5. Form-style user interaction
6. String input with both words and lines
7. Number input with range validation

Key concepts shown:
- Using manipulators (setw, setfill, fixed, etc.)
- Proper input buffer management
- Input validation techniques
- Structured output formatting
- Error handling for different input types

Try:
1. Enter invalid inputs to see error handling
2. Enter names with spaces to see line input handling
3. Test the range validation with numbers outside the valid range
4. Observe how the table maintains alignment with different data
*/
