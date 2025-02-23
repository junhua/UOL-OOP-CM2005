---
layout: default
title: Part 2 - Function Declaration and Definition
nav_order: 2
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part2-declaration/
---

# Part 2: Function Declaration and Definition

## Overview
In C++, functions need to be declared before they can be used. The declaration tells the compiler about the function's interface, while the definition contains the actual implementation. Understanding how to properly declare and define functions is crucial for organizing code effectively.

## Function Declaration (Prototype)

### Purpose
- Tells compiler about function's existence
- Specifies function's interface
- Allows function to be used before definition
- Helps catch errors at compile time

### Syntax
```cpp
return_type function_name(parameter_list);
```

### Example
```cpp
// Function declarations (prototypes)
int calculateSum(int a, int b);
void printMessage(string msg);
double getAverage(int numbers[], int size);
```

## Function Definition

### Purpose
- Contains actual implementation
- Provides function body
- Specifies what function does
- Must match declaration

### Syntax
```cpp
return_type function_name(parameter_list) {
    // Function body
    // Implementation
    return value;  // if non-void
}
```

### Example
```cpp
// Function definition
int calculateSum(int a, int b) {
    return a + b;
}
```

## Declaration vs Definition

### Key Differences
1. Declaration
   - Ends with semicolon
   - No function body
   - Can appear multiple times
   - Usually in header files

2. Definition
   - Contains function body
   - Must appear exactly once
   - Usually in source files
   - Implements the function

## Example with Separate Declaration and Definition

```cpp
// Function declarations (top of file)
int calculateArea(int length, int width);
void printArea(int area);

// Main function
int main() {
    int area = calculateArea(5, 3);
    printArea(area);
    return 0;
}

// Function definitions (after main)
int calculateArea(int length, int width) {
    return length * width;
}

void printArea(int area) {
    cout << "The area is: " << area << endl;
}
```

## Practice Exercise

Create a program that:
1. Declares functions for basic arithmetic operations
2. Implements each function separately
3. Uses the functions to perform calculations

Solution:
```cpp
#include <iostream>
using namespace std;

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
```

## Best Practices

### Declaration Guidelines
1. Place all declarations at the top
2. Use meaningful parameter names
3. Be consistent with naming
4. Document parameters and return values
5. Consider using header files

### Definition Guidelines
1. Match declaration exactly
2. Implement one function at a time
3. Keep functions focused
4. Use consistent formatting
5. Add implementation comments

## Common Mistakes to Avoid
1. Forgetting to declare functions
2. Mismatching declaration and definition
3. Declaring but not defining
4. Defining same function multiple times
5. Inconsistent parameter types

## Next Steps
- Try the practice exercise
- Experiment with function declarations
- Move on to [Part 3: Function Parameters and Return Values]({{ site.baseurl }}/tutorials/module3/part3-parameters)
