// Temperature Converter Program
// Think of this program like a smart thermometer that can convert
// temperatures between Celsius and Fahrenheit scales.

#include <iostream>   // For input/output
#include <iomanip>    // For formatting numbers
#include <limits>     // For numeric limits

// First, we declare all the functions we'll need
// This is like making a list of tools before starting a project

// Convert temperatures between scales
double celsiusToFahrenheit(double celsius);    // Like a C° to F° calculator
double fahrenheitToCelsius(double fahrenheit);  // Like a F° to C° calculator

// Helper functions for input/output
void clearInputBuffer();              // Like clearing a calculator's memory
double getValidTemperature();         // Like making sure input is a real temperature
int getMenuChoice();                  // Like showing options on a digital display
void displayResult(double temp, char unit);  // Like showing the final answer

int main() {
    // Welcome message (like the startup screen)
    std::cout << "Temperature Converter\n";
    std::cout << "===================\n\n";

    // Main program loop
    // Like keeping the calculator on until you're done
    bool running = true;
    while (running) {
        // Show menu and get user's choice
        // Like pressing buttons on a calculator
        int choice = getMenuChoice();
        
        // Handle different choices
        // Like different modes on a calculator
        switch (choice) {
            case 1: {  // Celsius to Fahrenheit mode
                std::cout << "\nEnter Celsius temperature:\n";
                double celsius = getValidTemperature();
                double fahrenheit = celsiusToFahrenheit(celsius);
                displayResult(fahrenheit, 'F');
                break;
            }
            case 2: {  // Fahrenheit to Celsius mode
                std::cout << "\nEnter Fahrenheit temperature:\n";
                double fahrenheit = getValidTemperature();
                double celsius = fahrenheitToCelsius(fahrenheit);
                displayResult(celsius, 'C');
                break;
            }
            case 3: {  // Exit (turn off the calculator)
                running = false;
                std::cout << "\nThank you for using Temperature Converter!\n";
                break;
            }
            default: {  // Invalid choice (like pressing a wrong button)
                std::cout << "\nInvalid choice. Please try again.\n\n";
            }
        }
    }

    return 0;  // Program completed successfully
}

// Function that converts Celsius to Fahrenheit
// Formula: °F = (°C × 9/5) + 32
double celsiusToFahrenheit(double celsius) {
    // Use 9.0 and 5.0 to ensure floating-point division
    return (celsius * 9.0/5.0) + 32.0;
}

// Function that converts Fahrenheit to Celsius
// Formula: °C = (°F - 32) × 5/9
double fahrenheitToCelsius(double fahrenheit) {
    // Use 5.0 and 9.0 to ensure floating-point division
    return (fahrenheit - 32.0) * 5.0/9.0;
}

// Function to clear any leftover input
// Like clearing a calculator's memory
void clearInputBuffer() {
    std::cin.clear();         // Reset error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
}

// Function to get a valid temperature from the user
// Like making sure someone enters a real number
double getValidTemperature() {
    double temp;
    bool valid = false;

    do {
        std::cout << "Temperature: ";
        if (std::cin >> temp) {
            // Input was a valid number
            valid = true;
        } else {
            // Input wasn't a number
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
        }
    } while (!valid);  // Keep trying until we get a valid number

    clearInputBuffer();  // Clean up before returning
    return temp;
}

// Function to show the menu and get user's choice
// Like showing options on a digital display
int getMenuChoice() {
    // Display available options
    std::cout << "Menu Options:\n";
    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "3. Exit\n\n";
    std::cout << "Enter choice (1-3): ";

    // Get and validate the choice
    int choice;
    if (std::cin >> choice) {
        clearInputBuffer();
        return choice;
    }
    
    // If input wasn't valid, return 0 (invalid choice)
    clearInputBuffer();
    return 0;
}

// Function to display the converted temperature
// Like showing the final answer on a calculator display
void displayResult(double temp, char unit) {
    // Set up number formatting (show 2 decimal places)
    std::cout << std::fixed << std::setprecision(2);
    
    // Show the result with the appropriate unit (°C or °F)
    std::cout << "\nResult: " << temp << "°" << unit << "\n\n";
}

/*
This program shows:
1. How to organize code into functions
2. How to handle user input safely
3. How to convert between temperature scales
4. How to format output nicely
5. How to create a menu-driven program

Try:
1. Converting freezing point (0°C = 32°F)
2. Converting boiling point (100°C = 212°F)
3. Converting room temperature (20°C = 68°F)
4. Entering invalid inputs to test error handling
*/
