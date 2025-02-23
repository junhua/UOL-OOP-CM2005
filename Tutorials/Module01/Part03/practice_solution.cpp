#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <vector>

// Utility functions for input handling
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
T getValidNumber(const std::string& prompt, T min, T max) {
    T value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            clearInputBuffer();
            return value;
        }
        std::cout << "Error: Please enter a number between " << min << " and " << max << "\n";
        clearInputBuffer();
    }
}

// Exercise 1: User Information Form
void userInformationForm() {
    std::cout << "\n=== User Information Form ===\n";
    std::cout << "============================\n";

    // Get name (allowing spaces)
    std::string firstName, lastName;
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    // Get age with validation
    int age = getValidNumber<int>("Enter age (0-120): ", 0, 120);

    // Get height with validation
    double height = getValidNumber<double>("Enter height in meters (1.0-2.5): ", 1.0, 2.5);

    // Display formatted results
    std::cout << "\nInformation Summary\n";
    std::cout << "==================\n";
    std::cout << std::fixed << std::setprecision(2);
    
    const int WIDTH = 15;
    std::cout << std::left << std::setw(WIDTH) << "Name:"
              << firstName + " " + lastName << "\n";
    std::cout << std::left << std::setw(WIDTH) << "Age:"
              << age << " years\n";
    std::cout << std::left << std::setw(WIDTH) << "Height:"
              << height << " meters\n";
}

// Exercise 2: Calculator Input
void calculator() {
    std::cout << "\n=== Calculator ===\n";
    std::cout << "=================\n";

    double num1 = getValidNumber<double>("Enter first number: ", -1000.0, 1000.0);
    double num2 = getValidNumber<double>("Enter second number: ", -1000.0, 1000.0);
    
    char op;
    while (true) {
        std::cout << "Enter operator (+, -, *, /): ";
        if (std::cin >> op && (op == '+' || op == '-' || op == '*' || op == '/')) {
            break;
        }
        std::cout << "Invalid operator! Please try again.\n";
        clearInputBuffer();
    }
    clearInputBuffer();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nCalculation: " << num1 << " " << op << " " << num2 << " = ";

    switch (op) {
        case '+': std::cout << num1 + num2 << "\n"; break;
        case '-': std::cout << num1 - num2 << "\n"; break;
        case '*': std::cout << num1 * num2 << "\n"; break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 / num2 << "\n";
            } else {
                std::cout << "Error: Division by zero!\n";
            }
            break;
    }
}

// Exercise 3: Temperature Converter
void temperatureConverter() {
    std::cout << "\n=== Temperature Converter ===\n";
    std::cout << "===========================\n";

    std::cout << "1. Celsius to Fahrenheit\n";
    std::cout << "2. Fahrenheit to Celsius\n";
    int choice = getValidNumber<int>("Enter choice (1-2): ", 1, 2);

    if (choice == 1) {
        double celsius = getValidNumber<double>("Enter temperature in Celsius: ", -273.15, 1000.0);
        double fahrenheit = (celsius * 9/5) + 32;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << celsius << "°C = " << fahrenheit << "°F\n";
    } else {
        double fahrenheit = getValidNumber<double>("Enter temperature in Fahrenheit: ", -459.67, 1832.0);
        double celsius = (fahrenheit - 32) * 5/9;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << fahrenheit << "°F = " << celsius << "°C\n";
    }
}

// Exercise 4: Shopping List
void shoppingList() {
    std::cout << "\n=== Shopping List ===\n";
    std::cout << "====================\n";

    struct Item {
        std::string name;
        double price;
        int quantity;
    };
    std::vector<Item> items;

    // Get items from user
    while (true) {
        Item item;
        std::cout << "\nEnter item name (or 'done' to finish): ";
        std::getline(std::cin, item.name);
        if (item.name == "done") break;

        item.price = getValidNumber<double>("Enter price: $", 0.0, 1000.0);
        item.quantity = getValidNumber<int>("Enter quantity: ", 1, 100);
        items.push_back(item);
    }

    // Print receipt
    std::cout << "\n=== Receipt ===\n";
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << std::setfill(' ');

    // Header
    std::cout << std::left << std::setw(20) << "Item"
              << std::right << std::setw(8) << "Price"
              << std::right << std::setw(6) << "Qty"
              << std::right << std::setw(8) << "Total" << std::endl;
    
    std::cout << std::setfill('-') << std::setw(42) << "" << std::endl;
    std::cout << std::setfill(' ');

    // Items
    double total = 0;
    std::cout << std::fixed << std::setprecision(2);
    for (const auto& item : items) {
        double itemTotal = item.price * item.quantity;
        total += itemTotal;
        
        std::cout << std::left << std::setw(20) << item.name
                  << std::right << std::setw(7) << "$" << item.price
                  << std::right << std::setw(6) << item.quantity
                  << std::right << std::setw(7) << "$" << itemTotal << std::endl;
    }

    // Total
    std::cout << std::setfill('=') << std::setw(42) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::right << std::setw(35) << "Total: $" << total << std::endl;
}

int main() {
    std::cout << "C++ Input/Output Practice Solutions\n";
    std::cout << "==================================\n";

    while (true) {
        std::cout << "\nSelect an exercise to run:\n";
        std::cout << "1. User Information Form\n";
        std::cout << "2. Calculator\n";
        std::cout << "3. Temperature Converter\n";
        std::cout << "4. Shopping List\n";
        std::cout << "5. Exit\n";

        int choice = getValidNumber<int>("Enter your choice (1-5): ", 1, 5);
        
        switch (choice) {
            case 1: userInformationForm(); break;
            case 2: calculator(); break;
            case 3: temperatureConverter(); break;
            case 4: shoppingList(); break;
            case 5: return 0;
        }
    }
}

/*
This program provides solutions to all practice exercises:
1. User Information Form
   - Demonstrates basic input/output with validation
   - Shows formatted text output
   - Handles different data types

2. Calculator
   - Shows operator input and validation
   - Demonstrates error handling (division by zero)
   - Uses switch statement for operations

3. Temperature Converter
   - Implements temperature conversion formulas
   - Shows menu-based input
   - Demonstrates range validation

4. Shopping List
   - Uses vectors for dynamic data storage
   - Creates formatted tables
   - Calculates totals
   - Shows professional receipt formatting

Key concepts demonstrated:
- Input validation
- Error handling
- String manipulation
- Numeric formatting
- Table formatting
- Menu systems
- Vector usage
- Function organization

Try:
1. Enter invalid inputs to test error handling
2. Try extreme values to test range validation
3. Create a long shopping list to see table formatting
4. Test all temperature conversions
*/
