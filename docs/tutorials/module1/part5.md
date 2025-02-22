---
layout: default
title: Part 5 - Basic Programs
---

# Part 5: Basic Programs

Welcome to Part 5! Now that we know about variables, input/output, and operators, let's learn how to organize our code into well-structured programs. Think of it like writing a recipe - we need clear steps and organization!

## Understanding Program Structure

### The Recipe Analogy
Think of a C++ program like a cooking recipe:
- The ingredients list → Variables and constants
- The utensils needed → Libraries we include
- The main steps → The main() function
- Individual techniques → Other functions
- Notes and tips → Comments

### Basic Program Template
```cpp
// 1. Include needed libraries (like getting out your utensils)
#include <iostream>
#include <string>

// 2. Declare any functions we'll use (like listing the techniques we'll need)
void displayMenu();
int getChoice();
void processChoice(int choice);

// 3. Main function (like the main recipe steps)
int main() {
    // Your program starts here
    displayMenu();
    int choice = getChoice();
    processChoice(choice);
    return 0;
}
```

## Functions: Breaking Down Your Program

### What is a Function?
Think of a function like a mini-recipe within your main recipe:
- It has a specific job
- It might need ingredients (parameters)
- It might produce something (return value)
- It can be used multiple times

### Function Example
```cpp
// Function to calculate area of a rectangle
double calculateArea(double length, double width) {
    // Parameters are like ingredients
    double area = length * width;  // Processing
    return area;                   // Result
}

int main() {
    // Using the function
    double roomArea = calculateArea(5.0, 3.0);
    std::cout << "Room area: " << roomArea << " square meters\n";
}
```

### Function Parts Explained
```cpp
double calculateArea(double length, double width)
↑      ↑            ↑
│      │            └── Parameters (what goes in)
│      └─────────────── Function name (what it does)
└────────────────────── Return type (what comes out)
```

## Simple Calculations Example

### Temperature Converter
```cpp
double celsiusToFahrenheit(double celsius) {
    // Formula: °F = (°C × 9/5) + 32
    return (celsius * 9.0/5.0) + 32.0;
}

double fahrenheitToCelsius(double fahrenheit) {
    // Formula: °C = (°F - 32) × 5/9
    return (fahrenheit - 32.0) * 5.0/9.0;
}

int main() {
    double tempC = 20.0;  // 20°C
    double tempF = celsiusToFahrenheit(tempC);
    
    std::cout << tempC << "°C is " << tempF << "°F\n";
}
```

## User Interaction

### Creating a Menu System
Think of a menu system like a restaurant menu:
```cpp
void displayMenu() {
    std::cout << "=== Calculator Menu ===\n";
    std::cout << "1. Add numbers\n";
    std::cout << "2. Subtract numbers\n";
    std::cout << "3. Exit\n";
    std::cout << "====================\n";
}

int getChoice() {
    int choice;
    do {
        std::cout << "Enter choice (1-3): ";
        std::cin >> choice;
        
        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice < 1 || choice > 3);
    
    return choice;
}
```

### Processing User Input
```cpp
void processChoice(int choice) {
    switch (choice) {
        case 1:
            // Handle addition
            handleAddition();
            break;
        case 2:
            // Handle subtraction
            handleSubtraction();
            break;
        case 3:
            std::cout << "Goodbye!\n";
            break;
    }
}
```

## Error Handling

### Checking for Valid Input
Like a quality control check in cooking:
```cpp
bool isValidNumber(double number, double min, double max) {
    if (number < min || number > max) {
        std::cout << "Number must be between "
                  << min << " and " << max << "\n";
        return false;
    }
    return true;
}
```

### Safe Division
Like checking if you have enough ingredients:
```cpp
bool isDivisionSafe(double denominator) {
    const double EPSILON = 0.0001;  // Very small number
    if (std::abs(denominator) < EPSILON) {
        std::cout << "Cannot divide by zero!\n";
        return false;
    }
    return true;
}
```

## Program Organization

### Using Constants
Like having standard measurements in cooking:
```cpp
// At the top of your program
const double PI = 3.14159;
const int MAX_ATTEMPTS = 3;
const std::string ERROR_MESSAGE = "Invalid input!";

// Using constants makes changes easier
double circleArea = PI * radius * radius;
```

### Breaking Down Complex Operations
Like breaking a recipe into smaller steps:
```cpp
double calculateFinalPrice() {
    double basePrice = getBasePrice();
    double discount = calculateDiscount(basePrice);
    double tax = calculateTax(basePrice - discount);
    return basePrice - discount + tax;
}
```

## Practice Exercise

Create a calculator program that:
1. Shows a menu with options:
   - Add two numbers
   - Subtract two numbers
   - Multiply two numbers
   - Divide two numbers
   - Exit
2. Gets user input for numbers
3. Performs the calculation
4. Handles errors (like division by zero)
5. Shows the result
6. Asks if user wants to continue

Example output:
```
=== Calculator ===
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit

Choice: 1
Enter first number: 10
Enter second number: 5
Result: 10 + 5 = 15

Continue? (y/n): 
```

[View Solution]({{ site.baseurl }}/tutorials/module1/part5/solution)

## Best Practices

### 1. Function Design
- Each function should do one thing well
- Keep functions short and focused
- Use meaningful function names
- Add comments to explain complex logic

### 2. Input Validation
```cpp
double getPositiveNumber() {
    double number;
    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while (number <= 0);
    return number;
}
```

### 3. Error Messages
```cpp
void showError(const std::string& message) {
    std::cout << "ERROR: " << message << "\n";
    std::cout << "Please try again.\n";
}
```

### 4. Program Flow
```cpp
int main() {
    // 1. Initialize
    setup();
    
    // 2. Main loop
    while (isRunning) {
        // 3. Get input
        processInput();
        
        // 4. Update
        update();
        
        // 5. Display
        display();
    }
    
    // 6. Cleanup
    cleanup();
    return 0;
}
```

## Next Steps
1. Complete the practice exercise
2. Try modifying the calculator program
3. Create your own menu-based program
4. Move on to [Part 6: Problem Solving]({{ site.baseurl }}/tutorials/module1/part6)

## Additional Resources
- [Program Structure Guide]({{ site.baseurl }}/docs/guides/program-structure)
- [Function Design Tips]({{ site.baseurl }}/docs/guides/functions)
- [Error Handling Best Practices]({{ site.baseurl }}/docs/guides/error-handling)

Remember: Good program organization makes your code easier to understand, test, and modify!
