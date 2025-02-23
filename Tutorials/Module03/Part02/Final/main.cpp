#include <iostream>
using namespace std;

/**
 * Module 3 - Part 2: Function Declaration and Definition
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Function declarations (prototypes)
 * 2. Separate function definitions
 * 3. Using functions for arithmetic operations
 */

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void printResult(string operation, double result);

int main() {
    double num1 = 10.5;
    double num2 = 5.25;
    
    // Using the functions
    printResult("Addition", add(num1, num2));
    printResult("Subtraction", subtract(num1, num2));
    printResult("Multiplication", multiply(num1, num2));
    printResult("Division", divide(num1, num2));
    
    // Test division by zero
    cout << "\nTesting division by zero:" << endl;
    printResult("Division", divide(num1, 0));
    
    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

void printResult(string operation, double result) {
    cout << operation << " result: " << result << endl;
}
