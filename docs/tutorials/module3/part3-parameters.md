---
layout: default
title: Part 3 - Function Parameters and Return Values
nav_order: 3
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part3-parameters/
---

# Part 3: Function Parameters and Return Values

## Overview
Functions can take input parameters and return values. Understanding how to work with parameters and return values is essential for creating flexible and reusable functions.

## Function Parameters

### Parameter Types
1. Value Parameters
   - Copy of argument is passed
   - Changes to parameter don't affect original
   - Most common parameter type

2. Reference Parameters
   - Reference to original argument
   - Changes affect original value
   - More efficient for large objects

3. Const Parameters
   - Cannot be modified in function
   - Good for read-only parameters
   - Prevents accidental changes

### Parameter Rules
- Each parameter must have a type
- Parameters are separated by commas
- Parameter names must be unique
- Order matters when calling function

## Example: Different Parameter Types

```cpp
// Value parameter
void incrementValue(int num) {
    num++;  // Doesn't affect original
}

// Reference parameter
void incrementReference(int& num) {
    num++;  // Modifies original
}

// Const parameter
void printValue(const int& num) {
    cout << num << endl;  // Can't modify num
}

int main() {
    int x = 5;
    
    incrementValue(x);      // x still 5
    incrementReference(x);  // x now 6
    printValue(x);         // Prints 6
    
    return 0;
}
```

## Return Values

### Return Types
- Any valid C++ type
- void for no return value
- Only one value can be returned
- Must match function declaration

### Return Rules
- Must return value of declared type
- Return exits function immediately
- All paths must return value
- void functions can use bare return

## Example: Return Values

```cpp
// Return type examples
int getSquare(int num) {
    return num * num;
}

string getStatus(int score) {
    if (score >= 60) {
        return "Pass";
    } else {
        return "Fail";
    }
}

void printMessage() {
    cout << "Hello" << endl;
    return;  // Optional for void
}
```

## Default Parameters

### Purpose
- Provide default values for parameters
- Make parameters optional
- Must be rightmost parameters

### Example
```cpp
// Default parameters
void printBox(int width = 10, char symbol = '*') {
    for (int i = 0; i < width; i++) {
        cout << symbol;
    }
    cout << endl;
}

int main() {
    printBox();        // width=10, symbol='*'
    printBox(5);       // width=5,  symbol='*'
    printBox(7, '#');  // width=7,  symbol='#'
    return 0;
}
```

## Practice Exercise

Create a program that works with different types of parameters and return values:
1. Function that modifies multiple values using reference parameters
2. Function with default parameters
3. Function that returns different values based on conditions

Solution:
```cpp
#include <iostream>
using namespace std;

// Function to modify values by reference
void getStats(const int* numbers, int size, int& min, int& max, double& avg) {
    if (size == 0) {
        min = max = 0;
        avg = 0.0;
        return;
    }
    
    min = max = numbers[0];
    int sum = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
        sum += numbers[i];
    }
    
    avg = static_cast<double>(sum) / size;
}

// Function with default parameters
void printLine(int length = 20, char symbol = '-', bool newline = true) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    if (newline) cout << endl;
}

// Function returning different values based on conditions
string getGrade(int score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

int main() {
    // Test getStats
    int numbers[] = {4, 7, 2, 8, 1, 9, 3};
    int min, max;
    double avg;
    
    getStats(numbers, 7, min, max, avg);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avg << endl;
    
    // Test printLine
    printLine();                  // Default values
    printLine(10);               // Custom length
    printLine(15, '*');         // Custom symbol
    printLine(5, '#', false);   // No newline
    cout << endl;
    
    // Test getGrade
    cout << "Score 95: " << getGrade(95) << endl;
    cout << "Score 83: " << getGrade(83) << endl;
    cout << "Score 75: " << getGrade(75) << endl;
    cout << "Score 68: " << getGrade(68) << endl;
    cout << "Score 55: " << getGrade(55) << endl;
    
    return 0;
}
```

## Best Practices

### Parameter Guidelines
1. Use const when parameter shouldn't change
2. Use references for large objects
3. Keep parameter count reasonable
4. Use meaningful parameter names
5. Consider default values

### Return Value Guidelines
1. Be consistent with return types
2. Handle all possible cases
3. Document return values
4. Consider error conditions
5. Use meaningful return values

## Common Mistakes to Avoid
1. Forgetting to return a value
2. Returning local variables by reference
3. Modifying const parameters
4. Using uninitialized reference parameters
5. Inconsistent return types

## Next Steps
- Try the practice exercise
- Experiment with different parameter types
- Move on to [Part 4: Call by Value and Call by Reference]({{ site.baseurl }}/tutorials/module3/part4-call-types)
