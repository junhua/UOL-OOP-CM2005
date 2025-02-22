// Scientific Calculator Program
// Think of this program like a scientific calculator with multiple functions,
// error checking, and a user-friendly menu system.

#include <iostream>   // For input/output
#include <iomanip>    // For formatting numbers
#include <limits>     // For numeric limits
#include <cmath>      // For mathematical functions

// Constants (like built-in calculator settings)
const int MAX_ATTEMPTS = 3;        // Maximum tries for input
const double EPSILON = 1e-10;      // Very small number for division check

// First, declare all the functions we'll need
// Like listing all the buttons on our calculator

// Menu and display functions (like the calculator's screen)
void displayMenu();                // Show available operations
int getMenuChoice();              // Get user's choice
void displayResult(double result); // Show the answer
void displayError(const std::string& message);  // Show error messages

// Input functions (like reading button presses)
double getNumber(const std::string& prompt);  // Get a number from user
char getOperator();               // Get +, -, *, or /
void clearInputBuffer();          // Clear any leftover input

// Safety checks (like calculator's error prevention)
bool isDivisionSafe(double denominator);  // Check if division is safe

// Basic math operations (like calculator's basic functions)
double add(double a, double b);        // Addition
double subtract(double a, double b);    // Subtraction
double multiply(double a, double b);    // Multiplication
double divide(double a, double b);      // Division
double power(double base, double exp);  // Power function
double squareRoot(double number);       // Square root

int main() {
    // Welcome screen
    std::cout << "Scientific Calculator\n";
    std::cout << "===================\n\n";

    // Main calculator loop (like keeping calculator on)
    bool running = true;
    while (running) {
        // Show menu and get choice (like calculator's mode selection)
        displayMenu();
        int choice = getMenuChoice();

        // Handle different operations (like different calculator modes)
        switch (choice) {
            case 1: {  // Basic arithmetic mode
                // Get first number
                double num1 = getNumber("Enter first number: ");
                
                // Get operation (+, -, *, /)
                char op = getOperator();
                
                // Get second number
                double num2 = getNumber("Enter second number: ");
                
                // Calculate result
                double result;
                bool validOperation = true;

                // Perform the chosen operation
                switch (op) {
                    case '+': result = add(num1, num2); break;
                    case '-': result = subtract(num1, num2); break;
                    case '*': result = multiply(num1, num2); break;
                    case '/':
                        // Check for division by zero
                        if (isDivisionSafe(num2)) {
                            result = divide(num1, num2);
                        } else {
                            displayError("Cannot divide by zero!");
                            validOperation = false;
                        }
                        break;
                    default:
                        displayError("Invalid operator!");
                        validOperation = false;
                }

                // Show result if operation was valid
                if (validOperation) {
                    displayResult(result);
                }
                break;
            }
            case 2: {  // Power function mode
                double base = getNumber("Enter base number: ");
                double exp = getNumber("Enter exponent: ");
                displayResult(power(base, exp));
                break;
            }
            case 3: {  // Square root mode
                double num = getNumber("Enter number: ");
                // Can't take square root of negative numbers
                if (num >= 0) {
                    displayResult(squareRoot(num));
                } else {
                    displayError("Cannot find square root of negative number!");
                }
                break;
            }
            case 4:  // Exit (turn off calculator)
                running = false;
                std::cout << "\nThank you for using Scientific Calculator!\n";
                break;
            default:  // Invalid choice
                displayError("Invalid menu choice!");
        }
    }

    return 0;  // Program completed successfully
}

// Function to show available operations
// Like the calculator's mode display
void displayMenu() {
    std::cout << "\nAvailable Operations:\n";
    std::cout << "1. Basic Math (+, -, *, /)\n";
    std::cout << "2. Power Function (x^y)\n";
    std::cout << "3. Square Root (√x)\n";
    std::cout << "4. Exit\n\n";
}

// Function to get user's menu choice
// Like reading which button was pressed
int getMenuChoice() {
    int choice;
    std::cout << "Enter choice (1-4): ";
    if (std::cin >> choice) {
        clearInputBuffer();
        return choice;
    }
    clearInputBuffer();
    return 0;  // Invalid input
}

// Function to get a number from the user
// Like reading numbers entered on calculator
double getNumber(const std::string& prompt) {
    double number;
    bool valid = false;
    int attempts = 0;

    // Keep trying until we get a valid number
    do {
        std::cout << prompt;
        if (std::cin >> number) {
            valid = true;
        } else {
            displayError("Please enter a valid number!");
            clearInputBuffer();
            attempts++;
        }
    } while (!valid && attempts < MAX_ATTEMPTS);

    // If we never got a valid number
    if (!valid) {
        throw std::runtime_error("Too many invalid attempts!");
    }

    clearInputBuffer();
    return number;
}

// Function to get an operator from the user
// Like pressing +, -, *, or / on calculator
char getOperator() {
    char op;
    bool valid = false;
    
    do {
        std::cout << "Enter operator (+, -, *, /): ";
        if (std::cin >> op && (op == '+' || op == '-' || op == '*' || op == '/')) {
            valid = true;
        } else {
            displayError("Please enter a valid operator!");
            clearInputBuffer();
        }
    } while (!valid);

    clearInputBuffer();
    return op;
}

// Function to clear input buffer
// Like clearing calculator's memory
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to check if division is safe
// Like checking for division by zero
bool isDivisionSafe(double denominator) {
    return std::abs(denominator) > EPSILON;
}

// Function to display the result
// Like showing the answer on calculator's screen
void displayResult(double result) {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nResult: " << result << "\n";
}

// Function to display error messages
// Like calculator's error display
void displayError(const std::string& message) {
    std::cout << "\nError: " << message << "\n";
}

// Basic calculator operations
// Like the basic function buttons on a calculator

double add(double a, double b) {
    return a + b;  // Simple addition
}

double subtract(double a, double b) {
    return a - b;  // Simple subtraction
}

double multiply(double a, double b) {
    return a * b;  // Simple multiplication
}

double divide(double a, double b) {
    return a / b;  // Simple division
}

double power(double base, double exponent) {
    return std::pow(base, exponent);  // Power function
}

double squareRoot(double number) {
    return std::sqrt(number);  // Square root function
}

/*
This program shows:
1. How to organize a larger program into functions
2. How to handle user input safely
3. How to create a menu system
4. How to perform calculations
5. How to handle errors

Try:
1. Basic calculations (like 5 + 3)
2. Powers (like 2^3 = 8)
3. Square roots (like √16 = 4)
4. Division by zero (to see error handling)
5. Invalid inputs (to test error checking)
*/
