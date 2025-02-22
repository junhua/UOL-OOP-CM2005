// Personal Information Form
// This program demonstrates how to:
// 1. Get different types of input from the user
// 2. Validate input to ensure it's correct
// 3. Format output to look professional
// Think of it like creating a digital form that checks your answers!

#include <iostream>   // For input/output
#include <iomanip>    // For formatting
#include <string>     // For text handling
#include <limits>     // For numeric limits

// Function to clean up any leftover input
// Like erasing a mistake and starting fresh
void clearInputBuffer() {
    std::cin.clear();         // Reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear remaining input
}

// Function to get a valid integer (whole number) input
// Like a form field that only accepts numbers in a certain range
int getValidIntInput(const std::string& prompt, int min, int max) {
    int value;
    bool valid = false;

    do {
        // Ask for input
        std::cout << prompt;
        
        // Try to get a number
        if (std::cin >> value) {
            // Check if the number is in the allowed range
            if (value >= min && value <= max) {
                valid = true;  // Input is good!
            } else {
                // Number is out of range
                std::cout << "Error: Value must be between " << min 
                         << " and " << max << "\n";
            }
        } else {
            // Input wasn't even a number
            std::cout << "Error: Please enter a valid number\n";
            clearInputBuffer();
        }
    } while (!valid);  // Keep trying until we get valid input

    clearInputBuffer();  // Clean up before returning
    return value;
}

// Function to get a valid floating-point (decimal) input
// Similar to integer input, but allows decimal points
float getValidFloatInput(const std::string& prompt, float min, float max) {
    float value;
    bool valid = false;

    do {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                valid = true;
            } else {
                std::cout << "Error: Value must be between " << min 
                         << " and " << max << "\n";
            }
        } else {
            std::cout << "Error: Please enter a valid number\n";
            clearInputBuffer();
        }
    } while (!valid);

    clearInputBuffer();
    return value;
}

int main() {
    // Create a nice header for our form
    // Like the title at the top of a paper form
    std::cout << "Personal Information Form\n";
    std::cout << "=======================\n\n";

    // Get the user's name
    // We use getline to allow spaces in names
    std::string firstName, lastName;
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    // Get age with validation
    // Only accepts ages between 0 and 120
    int age = getValidIntInput("Enter age (0-120): ", 0, 120);

    // Get height with validation
    // Only accepts heights between 1.0 and 2.5 meters
    float height = getValidFloatInput("Enter height in meters (1.0-2.5): ", 1.0f, 2.5f);

    // Now let's display all the information in a nice format
    // Like creating a professional-looking report
    
    // First, a simple summary
    std::cout << "\nInformation Summary\n";
    std::cout << "==================\n";

    // Set up number formatting (2 decimal places)
    std::cout << std::fixed << std::setprecision(2);

    // Create a neat table with aligned columns
    const int WIDTH = 15;  // Width of the first column
    
    // Each line has a label and a value, neatly aligned
    std::cout << std::left << std::setw(WIDTH) << "Name:"
              << firstName + " " + lastName << "\n";
    
    std::cout << std::left << std::setw(WIDTH) << "Age:"
              << age << " years\n";
    
    std::cout << std::left << std::setw(WIDTH) << "Height:"
              << height << " meters\n";

    // Create a fancy formatted card
    // Like an ID card or business card
    std::cout << "\nFormatted Card\n";
    std::cout << "==============\n";
    
    // Create a border with = symbols
    std::cout << std::setfill('=') << std::setw(30) << "" << "\n";
    std::cout << std::setfill(' ');  // Reset to spaces
    
    // Display information in a card format
    std::cout << std::left << std::setw(20) << firstName + " " + lastName << "\n";
    std::cout << "Age: " << std::right << std::setw(3) << age << " years\n";
    std::cout << "Height: " << std::right << std::setw(5) << height << " m\n";
    
    // Bottom border
    std::cout << std::setfill('=') << std::setw(30) << "" << "\n";

    return 0;
}

/*
This program shows how to:
1. Get different types of input (text, whole numbers, decimals)
2. Check that input is valid
3. Format output in different ways
4. Create professional-looking displays

Try:
1. Entering invalid input to see the error messages
2. Entering different names and numbers
3. Looking at how the output is formatted
4. Adding more information to the form
*/
