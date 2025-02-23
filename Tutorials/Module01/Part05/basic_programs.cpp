// File: basic_programs.cpp
// Description: Demonstrates how to create complete programs with real-world examples

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <vector>

// Function to clear input buffer and handle invalid input
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid integer input within a range
int getValidInteger(const std::string& prompt, int min, int max) {
    int value;
    bool validInput = false;
    
    do {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                validInput = true;
            } else {
                std::cout << "Error: Please enter a number between " 
                         << min << " and " << max << ".\n";
            }
        } else {
            std::cout << "Error: Please enter a valid number.\n";
            clearInputBuffer();
        }
    } while (!validInput);
    
    clearInputBuffer();
    return value;
}

// Function to format currency
std::string formatCurrency(double amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << "$" << amount;
    return ss.str();
}

// Function to calculate total with tax
double calculateTotal(double price, int quantity, double taxRate) {
    double subtotal = price * quantity;
    double tax = subtotal * taxRate;
    return subtotal + tax;
}

int main() {
    std::cout << "Basic Programs Demo\n";
    std::cout << "==================\n\n";

    // Restaurant Order System Example
    std::cout << "Restaurant Order System\n";
    std::cout << "----------------------\n";
    
    // Get customer information
    std::string customerName;
    std::cout << "Please enter customer name: ";
    std::getline(std::cin, customerName);
    
    // Initialize order variables
    const double MENU_PRICES[] = {9.99, 12.99, 8.99, 15.99};
    const std::string MENU_ITEMS[] = {"Burger", "Pizza", "Salad", "Steak"};
    const int MENU_SIZE = 4;
    const double TAX_RATE = 0.08;  // 8% tax
    
    std::vector<int> quantities(MENU_SIZE, 0);
    double orderTotal = 0.0;
    
    // Display menu and take order
    bool ordering = true;
    while (ordering) {
        std::cout << "\nMenu:\n";
        for (int i = 0; i < MENU_SIZE; i++) {
            std::cout << (i + 1) << ". " << MENU_ITEMS[i] 
                      << " (" << formatCurrency(MENU_PRICES[i]) << ")\n";
        }
        std::cout << "5. Finish Order\n";
        
        int choice = getValidInteger("Enter choice (1-5): ", 1, 5);
        
        if (choice == 5) {
            ordering = false;
        } else {
            int quantity = getValidInteger("Enter quantity (1-10): ", 1, 10);
            quantities[choice - 1] += quantity;
        }
    }
    
    // Calculate and display receipt
    std::cout << "\nOrder Receipt\n";
    std::cout << "-------------\n";
    std::cout << "Customer: " << customerName << "\n\n";
    
    double subtotal = 0.0;
    for (int i = 0; i < MENU_SIZE; i++) {
        if (quantities[i] > 0) {
            double itemTotal = MENU_PRICES[i] * quantities[i];
            subtotal += itemTotal;
            std::cout << MENU_ITEMS[i] << " x " << quantities[i] 
                      << " = " << formatCurrency(itemTotal) << "\n";
        }
    }
    
    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;
    
    std::cout << "\nSubtotal: " << formatCurrency(subtotal) << "\n";
    std::cout << "Tax (8%): " << formatCurrency(tax) << "\n";
    std::cout << "Total: " << formatCurrency(total) << "\n";
    
    // Temperature Monitoring Example
    std::cout << "\nTemperature Monitoring\n";
    std::cout << "---------------------\n";
    
    const int NUM_READINGS = 3;
    std::vector<double> temperatures;
    
    // Get temperature readings
    for (int i = 0; i < NUM_READINGS; i++) {
        double temp;
        std::cout << "Enter temperature " << (i + 1) << ": ";
        std::cin >> temp;
        temperatures.push_back(temp);
    }
    
    // Calculate statistics
    double sum = 0.0;
    double highest = temperatures[0];
    double lowest = temperatures[0];
    
    for (double temp : temperatures) {
        sum += temp;
        highest = std::max(highest, temp);
        lowest = std::min(lowest, temp);
    }
    
    double average = sum / temperatures.size();
    
    // Display results
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "\nTemperature Statistics:\n";
    std::cout << "Average: " << average << "°C\n";
    std::cout << "Highest: " << highest << "°C\n";
    std::cout << "Lowest: " << lowest << "°C\n";
    
    // Alert for extreme temperatures
    const double HIGH_TEMP_THRESHOLD = 30.0;
    const double LOW_TEMP_THRESHOLD = 0.0;
    
    if (highest > HIGH_TEMP_THRESHOLD) {
        std::cout << "WARNING: High temperature detected!\n";
    }
    if (lowest < LOW_TEMP_THRESHOLD) {
        std::cout << "WARNING: Low temperature detected!\n";
    }

    return 0;
}
