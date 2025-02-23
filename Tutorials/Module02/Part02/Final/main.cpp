#include <iostream>
using namespace std;

/**
 * Module 2 - Part 2: Switch Statements
 * Practice Exercise Solution
 * 
 * This program implements a simple calculator that:
 * 1. Takes two numbers as input
 * 2. Takes an operation (+, -, *, /) as input
 * 3. Uses a switch statement to perform the calculation
 * 4. Handles division by zero
 * 5. Handles invalid operators
 */

int main() {
    double num1, num2;
    char operation;
    
    // Get user input
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    // Perform calculation based on operation
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    
    return 0;
}
