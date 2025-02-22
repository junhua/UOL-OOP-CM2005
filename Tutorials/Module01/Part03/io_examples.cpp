// Input/Output Examples in C++
// This program shows how your program can "talk" to the user (output)
// and "listen" to the user (input) - like having a conversation!

// Include necessary libraries
#include <iostream>   // For basic input/output
#include <iomanip>   // For formatting output (making it look nice)
#include <string>    // For working with text

int main() {
    // PART 1: BASIC OUTPUT (TALKING TO THE USER)
    // =========================================
    
    // Simple messages (like speaking simple sentences)
    std::cout << "Basic Output Examples\n";
    std::cout << "====================\n";
    std::cout << "Hello World" << std::endl;  // endl is like pressing Enter
    std::cout << "Line 1\n";                  // \n is also like pressing Enter
    std::cout << "Value: " << 42 << "\n\n";   // Mixing text and numbers

    // PART 2: FORMATTING NUMBERS (MAKING NUMBERS LOOK NICE)
    // ==================================================
    
    // Numbers we'll work with
    double price = 19.99;           // A price with cents
    double pi = 3.14159265359;      // Pi with many decimal places
    
    std::cout << "Number Formatting (Making Numbers Pretty)\n";
    std::cout << "======================================\n";
    std::cout << "Default price: " << price << "\n";
    
    // Set up fixed decimal point and 2 decimal places
    // (Like setting rules for how to display money)
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Price (2 decimals): $" << price << "\n";
    std::cout << "Pi (2 decimals): " << pi << "\n";
    
    // Change to 4 decimal places
    std::cout << std::setprecision(4);
    std::cout << "Pi (4 decimals): " << pi << "\n\n";

    // PART 3: ALIGNMENT AND SPACING (MAKING TEXT LINE UP)
    // ================================================
    
    std::cout << "Text Alignment (Making Things Line Up)\n";
    std::cout << "===================================\n";
    // Left alignment (like text starting at the left margin)
    std::cout << std::left << std::setw(15) << "Left Aligned" << "|\n";
    
    // Right alignment (like numbers in a calculator)
    std::cout << std::right << std::setw(15) << "Right Aligned" << "|\n";
    
    // Filling empty space with dots
    std::cout << std::setfill('.') << std::setw(15) << "Filled" << "|\n\n";

    // PART 4: BOOLEAN VALUES (TRUE/FALSE)
    // =================================
    
    bool isTrue = true;
    std::cout << "Boolean Values (True/False)\n";
    std::cout << "=========================\n";
    std::cout << "Default display: " << isTrue << "\n";  // Shows 1
    std::cout << std::boolalpha;                        // Switch to words
    std::cout << "Word display: " << isTrue << "\n\n";   // Shows "true"

    // PART 5: CREATING TABLES (ORGANIZING INFORMATION)
    // =============================================
    
    std::cout << "Table Example (Organizing Data)\n";
    std::cout << "=============================\n";
    // Reset fill character to spaces
    std::cout << std::setfill(' ');
    
    // Table header (like column names in Excel)
    std::cout << std::left << std::setw(10) << "Name"
              << std::right << std::setw(8) << "Age"
              << std::right << std::setw(10) << "Height" << "\n";
    
    // Separator line
    std::cout << std::setfill('-') << std::setw(28) << "" << "\n";
    std::cout << std::setfill(' ');  // Back to spaces
    
    // Table data
    std::cout << std::left << std::setw(10) << "John"
              << std::right << std::setw(8) << "25"
              << std::right << std::setw(10) << "1.75" << "\n";
    std::cout << std::left << std::setw(10) << "Jane"
              << std::right << std::setw(8) << "30"
              << std::right << std::setw(10) << "1.68" << "\n\n";

    // PART 6: GETTING INPUT (LISTENING TO THE USER)
    // ==========================================
    
    std::cout << "Input Example (Talking to You!)\n";
    std::cout << "=============================\n";
    std::string name;
    int age;

    // Getting text input (like asking for someone's name)
    std::cout << "What's your name? ";
    std::getline(std::cin, name);  // Gets entire line, including spaces

    // Getting number input (like asking for someone's age)
    std::cout << "How old are you? ";
    while (!(std::cin >> age)) {  // Keep trying until we get a valid number
        std::cout << "Oops! Please enter a number: ";
        std::cin.clear();         // Reset error flags
        std::cin.ignore(10000, '\n');  // Clear bad input
    }

    // Show what we learned about the user
    std::cout << "\nNice to meet you!\n";
    std::cout << "----------------\n";
    std::cout << "Your name is " << name << "\n";
    std::cout << "You are " << age << " years old\n";

    return 0;
}

/*
This program demonstrates:
1. How to display messages to the user
2. How to format numbers and text
3. How to create neat tables
4. How to get input from the user
5. How to handle input errors

Try:
1. Changing the price and seeing how it displays
2. Adding more rows to the table
3. Changing the table column widths
4. Running the program and entering different inputs
*/
