---
layout: default
title: Part 5 - Simple Program Examples
nav_order: 5
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part5-examples/
---

# Part 5: Simple Program Examples

## Overview
This section provides complete program examples that demonstrate the control flow concepts we've learned. Each example combines different control structures to solve practical problems.

## Example 1: Temperature Converter

This program converts temperatures between Celsius and Fahrenheit, demonstrating if-else statements and loops.

```cpp
#include <iostream>
using namespace std;

int main() {
    char choice;
    double temp;
    
    do {
        cout << "\nTemperature Converter" << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                cout << "Enter temperature in Celsius: ";
                cin >> temp;
                cout << temp << "°C = " 
                     << (temp * 9/5) + 32 << "°F" << endl;
                break;
            case '2':
                cout << "Enter temperature in Fahrenheit: ";
                cin >> temp;
                cout << temp << "°F = " 
                     << (temp - 32) * 5/9 << "°C" << endl;
                break;
            case '3':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '3');
    
    return 0;
}
```

## Example 2: Prime Number Checker

This program checks if a number is prime, demonstrating for loops and break statements.

```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    bool isPrime = true;
    
    cout << "Enter a positive integer: ";
    cin >> number;
    
    // Handle special cases
    if (number <= 1) {
        isPrime = false;
    } else {
        // Check for divisibility from 2 to number/2
        for (int i = 2; i <= number/2; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;  // Exit loop once we find a factor
            }
        }
    }
    
    if (isPrime) {
        cout << number << " is a prime number" << endl;
    } else {
        cout << number << " is not a prime number" << endl;
    }
    
    return 0;
}
```

## Example 3: Grade Calculator

This program calculates a student's average grade and letter grade, demonstrating nested if statements and input validation.

```cpp
#include <iostream>
using namespace std;

int main() {
    int numGrades;
    double grade, total = 0, average;
    
    cout << "How many grades to enter? ";
    cin >> numGrades;
    
    if (numGrades > 0) {
        // Get grades
        for (int i = 1; i <= numGrades; i++) {
            do {
                cout << "Enter grade " << i << " (0-100): ";
                cin >> grade;
                
                if (grade < 0 || grade > 100) {
                    cout << "Invalid grade! Try again." << endl;
                }
            } while (grade < 0 || grade > 100);
            
            total += grade;
        }
        
        // Calculate average
        average = total / numGrades;
        cout << "\nAverage grade: " << average << endl;
        
        // Determine letter grade
        cout << "Letter grade: ";
        if (average >= 90) {
            cout << "A" << endl;
        } else if (average >= 80) {
            cout << "B" << endl;
        } else if (average >= 70) {
            cout << "C" << endl;
        } else if (average >= 60) {
            cout << "D" << endl;
        } else {
            cout << "F" << endl;
        }
    } else {
        cout << "Invalid number of grades!" << endl;
    }
    
    return 0;
}
```

## Example 4: Simple ATM Machine

This program simulates a simple ATM, demonstrating switch statements, loops, and input validation.

```cpp
#include <iostream>
using namespace std;

int main() {
    double balance = 1000;  // Initial balance
    int choice;
    double amount;
    
    while (true) {
        // Display menu
        cout << "\nATM Menu" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Current balance: $" << balance << endl;
                break;
                
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful" << endl;
                } else {
                    cout << "Invalid amount!" << endl;
                }
                break;
                
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    cout << "Withdrawal successful" << endl;
                } else {
                    cout << "Invalid amount or insufficient funds!" << endl;
                }
                break;
                
            case 4:
                cout << "Thank you for using our ATM!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
```

## Practice Exercise

Create a simple game that:
1. Generates a random pattern of characters (e.g., "RBRG" for Red, Blue, Red, Green)
2. Asks the player to repeat the pattern
3. Keeps track of score
4. Increases pattern length after each successful attempt
5. Ends game on wrong pattern or when player chooses to quit

This exercise will combine:
- Random number generation
- String manipulation
- Loops
- Switch statements
- Break statements
- Input validation

## Key Takeaways
1. Break down complex problems into smaller parts
2. Use appropriate control structures for each part
3. Validate user input
4. Handle edge cases and errors
5. Keep code organized and readable
6. Use comments to explain complex logic

## Next Steps
- Try modifying the example programs
- Add new features to them
- Create your own programs combining different control structures
- Move on to [Module 3: Functions]({{ site.baseurl }}/tutorials/module3)
