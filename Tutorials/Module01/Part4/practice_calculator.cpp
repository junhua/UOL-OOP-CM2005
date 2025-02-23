#include <iostream>
#include <iomanip>
#include <limits>

// Function to clear input buffer and ignore remaining characters
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid number input
double getNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number) {
            clearInputBuffer();
            return number;
        }
        std::cout << "Invalid input. Please enter a number.\n";
        clearInputBuffer();
    }
}

int main() {
    char continueCalculation;
    
    do {
        std::cout << "\n=== Simple Calculator ===\n";
        
        // Get first number
        double num1 = getNumber("Enter first number: ");
        
        // Get second number
        double num2 = getNumber("Enter second number: ");
        
        // Set output formatting
        std::cout << std::fixed << std::setprecision(2);
        
        // Perform and display calculations
        std::cout << "\nResults:\n";
        std::cout << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;
        std::cout << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;
        std::cout << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;
        
        // Handle division (check for division by zero)
        if (num2 != 0) {
            std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
        } else {
            std::cout << "Division by zero is not allowed!" << std::endl;
        }
        
        // Ask if user wants to continue
        do {
            std::cout << "\nDo you want to perform another calculation? (y/n): ";
            std::cin >> continueCalculation;
            clearInputBuffer();
            
            if (continueCalculation != 'y' && continueCalculation != 'Y' && 
                continueCalculation != 'n' && continueCalculation != 'N') {
                std::cout << "Please enter 'y' or 'n'.\n";
            }
        } while (continueCalculation != 'y' && continueCalculation != 'Y' && 
                continueCalculation != 'n' && continueCalculation != 'N');
                
    } while (continueCalculation == 'y' || continueCalculation == 'Y');
    
    std::cout << "\nThank you for using the calculator!\n";
    return 0;
}
