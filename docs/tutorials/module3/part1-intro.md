---
layout: default
title: Part 1 - What are Functions?
nav_order: 1
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part1-intro/
---

# Part 1: What are Functions?

## Overview
Functions are reusable blocks of code that perform specific tasks. They help organize code, reduce repetition, and make programs more maintainable. This part introduces the concept of functions and their basic usage in C++.

## Why Use Functions?

### Code Organization
- Break complex problems into smaller, manageable pieces
- Each function has a specific purpose
- Makes code easier to understand and maintain
- Improves program structure

### Code Reusability
- Write code once, use it multiple times
- Avoid duplicating code
- Easy to modify behavior in one place
- Share code across different programs

### Abstraction
- Hide implementation details
- Focus on what code does, not how it does it
- Make code more readable
- Easier to modify implementation later

## Basic Function Structure

```cpp
return_type function_name(parameters) {
    // Function body
    // Code to be executed
    return value;  // Optional
}
```

### Components
1. Return Type
   - Data type of value returned by function
   - `void` if function doesn't return anything
   - Must match returned value's type

2. Function Name
   - Should describe what function does
   - Follow naming conventions
   - Must be unique in its scope

3. Parameters
   - Input values function needs
   - Optional (can have no parameters)
   - Each parameter has a type and name

4. Function Body
   - Code to be executed
   - Enclosed in curly braces
   - Can contain any valid C++ code

5. Return Statement
   - Returns value to caller
   - Must match return type
   - Optional for void functions

## Simple Function Example

```cpp
// Function to calculate square of a number
int square(int number) {
    return number * number;
}

// Function to print a greeting
void sayHello() {
    cout << "Hello!" << endl;
}

int main() {
    // Using the square function
    int result = square(5);
    cout << "5 squared is: " << result << endl;
    
    // Using the sayHello function
    sayHello();
    
    return 0;
}
```

## Practice Exercise

Create three simple functions:
1. A function that prints a line of stars (*)
2. A function that returns the larger of two numbers
3. A function that checks if a number is even

Solution:
```cpp
#include <iostream>
using namespace std;

// Function to print a line of stars
void printStars(int count) {
    for (int i = 0; i < count; i++) {
        cout << "*";
    }
    cout << endl;
}

// Function to return larger number
int findLarger(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Function to check if number is even
bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    // Test printStars function
    cout << "Printing 5 stars: ";
    printStars(5);
    
    // Test findLarger function
    int larger = findLarger(10, 20);
    cout << "Larger number is: " << larger << endl;
    
    // Test isEven function
    int testNumber = 7;
    if (isEven(testNumber)) {
        cout << testNumber << " is even" << endl;
    } else {
        cout << testNumber << " is odd" << endl;
    }
    
    return 0;
}
```

## Function Design Guidelines

1. Single Responsibility
   - Each function should do one thing
   - Function name should describe that purpose
   - Keep functions focused and simple

2. Meaningful Names
   - Use descriptive names
   - Follow verb-noun convention for actions
   - Be consistent with naming style

3. Parameter Design
   - Use appropriate parameter types
   - Order parameters logically
   - Keep parameter count reasonable
   - Use default values when appropriate

4. Function Size
   - Keep functions small and focused
   - Typically 20-30 lines or less
   - Split large functions into smaller ones

5. Documentation
   - Comment function purpose
   - Document parameters and return values
   - Explain any special cases or requirements

## Common Mistakes to Avoid
1. Too many parameters
2. Unclear function names
3. Multiple unrelated tasks in one function
4. Inconsistent return types
5. Poor documentation

## Next Steps
- Try the practice exercise
- Experiment with creating your own functions
- Move on to [Part 2: Function Declaration and Definition]({{ site.baseurl }}/tutorials/module3/part2-declaration)
