// File: practice_solution.cpp
// Description: Complete solutions for basic programs practice exercises

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <sstream>

// Utility function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid double input
double getValidDouble(const std::string& prompt, double min, double max) {
    double value;
    bool validInput = false;
    
    do {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                validInput = true;
            } else {
                std::cout << "Error: Value must be between " << min << " and " << max << "\n";
            }
        } else {
            std::cout << "Error: Please enter a valid number\n";
            clearInputBuffer();
        }
    } while (!validInput);
    
    clearInputBuffer();
    return value;
}

// Function to format currency
std::string formatCurrency(double amount) {
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << "$" << amount;
    return ss.str();
}

int main() {
    std::cout << "Basic Programs Practice Solutions\n";
    std::cout << "================================\n\n";

    // Exercise 1: Restaurant Order System
    std::cout << "Exercise 1: Restaurant Order System\n";
    std::cout << "--------------------------------\n";
    
    // Menu setup
    const std::string MENU_ITEMS[] = {"Burger", "Fries", "Drink", "Dessert"};
    const double MENU_PRICES[] = {8.99, 3.99, 2.49, 4.99};
    const int MENU_SIZE = 4;
    const double TAX_RATE = 0.08;  // 8% tax
    const double DISCOUNT_THRESHOLD = 20.00;  // Discount for orders over $20
    const double DISCOUNT_RATE = 0.10;  // 10% discount
    
    // Order storage
    std::vector<int> quantities(MENU_SIZE, 0);
    
    // Take order
    std::cout << "Today's Menu:\n";
    for (int i = 0; i < MENU_SIZE; i++) {
        std::cout << (i + 1) << ". " << MENU_ITEMS[i] 
                  << " - " << formatCurrency(MENU_PRICES[i]) << "\n";
    }
    
    bool ordering = true;
    while (ordering) {
        std::cout << "\nEnter item number (1-" << MENU_SIZE 
                  << ") or 0 to finish: ";
        int choice;
        std::cin >> choice;
        
        if (choice == 0) {
            ordering = false;
        } else if (choice >= 1 && choice <= MENU_SIZE) {
            std::cout << "Enter quantity: ";
            int quantity;
            std::cin >> quantity;
            if (quantity > 0) {
                quantities[choice - 1] += quantity;
            }
        } else {
            std::cout << "Invalid choice!\n";
        }
    }
    
    // Calculate totals
    double subtotal = 0.0;
    std::cout << "\nOrder Summary:\n";
    std::cout << "-------------\n";
    for (int i = 0; i < MENU_SIZE; i++) {
        if (quantities[i] > 0) {
            double itemTotal = MENU_PRICES[i] * quantities[i];
            subtotal += itemTotal;
            std::cout << MENU_ITEMS[i] << " x " << quantities[i] 
                      << " = " << formatCurrency(itemTotal) << "\n";
        }
    }
    
    // Apply discount if eligible
    double discount = 0.0;
    if (subtotal >= DISCOUNT_THRESHOLD) {
        discount = subtotal * DISCOUNT_RATE;
    }
    
    double afterDiscount = subtotal - discount;
    double tax = afterDiscount * TAX_RATE;
    double total = afterDiscount + tax;
    
    std::cout << "\nSubtotal: " << formatCurrency(subtotal) << "\n";
    if (discount > 0) {
        std::cout << "Discount: -" << formatCurrency(discount) << "\n";
    }
    std::cout << "Tax: " << formatCurrency(tax) << "\n";
    std::cout << "Total: " << formatCurrency(total) << "\n\n";

    // Exercise 2: Bank Account Manager
    std::cout << "Exercise 2: Bank Account Manager\n";
    std::cout << "-----------------------------\n";
    
    double balance = 1000.00;  // Initial balance
    std::vector<std::string> transactions;
    
    while (true) {
        std::cout << "\nCurrent Balance: " << formatCurrency(balance) << "\n\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. View Transactions\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option (1-4): ";
        
        int choice;
        std::cin >> choice;
        
        switch (choice) {
            case 1: {  // Deposit
                double amount = getValidDouble("Enter deposit amount: $", 0.01, 10000.00);
                balance += amount;
                transactions.push_back("Deposit: " + formatCurrency(amount));
                std::cout << "Deposit successful!\n";
                break;
            }
            case 2: {  // Withdraw
                double amount = getValidDouble("Enter withdrawal amount: $", 0.01, balance);
                balance -= amount;
                transactions.push_back("Withdrawal: " + formatCurrency(amount));
                std::cout << "Withdrawal successful!\n";
                break;
            }
            case 3: {  // View transactions
                std::cout << "\nTransaction History:\n";
                std::cout << "-------------------\n";
                for (const auto& transaction : transactions) {
                    std::cout << transaction << "\n";
                }
                std::cout << "Current Balance: " << formatCurrency(balance) << "\n";
                break;
            }
            case 4:  // Exit
                std::cout << "Thank you for using Bank Account Manager!\n\n";
                goto nextExercise;  // Exit nested loop
            default:
                std::cout << "Invalid option! Please try again.\n";
        }
    }
    nextExercise:

    // Exercise 3: Temperature Monitoring System
    std::cout << "Exercise 3: Temperature Monitoring System\n";
    std::cout << "----------------------------------\n";
    
    const int HOURS = 24;
    std::vector<double> temperatures;
    const double HIGH_ALERT = 30.0;
    const double LOW_ALERT = 10.0;
    
    // Simulate temperature readings
    std::cout << "Entering temperature readings for 24 hours...\n";
    for (int hour = 0; hour < HOURS; hour++) {
        // Simulate temperature between 5°C and 35°C
        double temp = 5 + (rand() % 31);
        temperatures.push_back(temp);
        
        std::cout << "Hour " << std::setw(2) << hour << ": " 
                  << std::fixed << std::setprecision(1) << temp << "°C";
        
        if (temp > HIGH_ALERT) {
            std::cout << " (HIGH TEMPERATURE ALERT!)";
        } else if (temp < LOW_ALERT) {
            std::cout << " (LOW TEMPERATURE ALERT!)";
        }
        std::cout << "\n";
    }
    
    // Calculate statistics
    double sum = 0, max = temperatures[0], min = temperatures[0];
    int highAlerts = 0, lowAlerts = 0;
    
    for (double temp : temperatures) {
        sum += temp;
        max = std::max(max, temp);
        min = std::min(min, temp);
        if (temp > HIGH_ALERT) highAlerts++;
        if (temp < LOW_ALERT) lowAlerts++;
    }
    
    double average = sum / temperatures.size();
    
    // Display summary
    std::cout << "\nTemperature Summary:\n";
    std::cout << "Average Temperature: " << average << "°C\n";
    std::cout << "Highest Temperature: " << max << "°C\n";
    std::cout << "Lowest Temperature: " << min << "°C\n";
    std::cout << "High Temperature Alerts: " << highAlerts << "\n";
    std::cout << "Low Temperature Alerts: " << lowAlerts << "\n\n";

    // Exercise 4: Student Grade Calculator
    std::cout << "Exercise 4: Student Grade Calculator\n";
    std::cout << "-------------------------------\n";
    
    // Grade weights
    const double HOMEWORK_WEIGHT = 0.3;  // 30%
    const double MIDTERM_WEIGHT = 0.3;   // 30%
    const double FINAL_WEIGHT = 0.4;     // 40%
    
    // Get grades
    double homework = getValidDouble("Enter homework grade (0-100): ", 0, 100);
    double midterm = getValidDouble("Enter midterm grade (0-100): ", 0, 100);
    double final = getValidDouble("Enter final exam grade (0-100): ", 0, 100);
    
    // Calculate weighted average
    double finalGrade = (homework * HOMEWORK_WEIGHT) +
                       (midterm * MIDTERM_WEIGHT) +
                       (final * FINAL_WEIGHT);
    
    // Determine letter grade
    char letterGrade;
    if (finalGrade >= 90) letterGrade = 'A';
    else if (finalGrade >= 80) letterGrade = 'B';
    else if (finalGrade >= 70) letterGrade = 'C';
    else if (finalGrade >= 60) letterGrade = 'D';
    else letterGrade = 'F';
    
    // Display results
    std::cout << "\nGrade Report:\n";
    std::cout << "------------\n";
    std::cout << "Homework (30%): " << homework << "\n";
    std::cout << "Midterm (30%): " << midterm << "\n";
    std::cout << "Final Exam (40%): " << final << "\n";
    std::cout << "Final Grade: " << std::fixed << std::setprecision(1) 
              << finalGrade << " (" << letterGrade << ")\n";
    
    if (letterGrade == 'F') {
        std::cout << "Student must retake the course.\n";
    } else if (letterGrade == 'D') {
        std::cout << "Student should consider getting additional help.\n";
    } else if (letterGrade == 'A') {
        std::cout << "Excellent work!\n";
    }

    return 0;
}
