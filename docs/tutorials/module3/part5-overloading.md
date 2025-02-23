---
layout: default
title: Part 5 - Function Overloading
nav_order: 5
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part5-overloading/
---

# Part 5: Function Overloading

## Overview
Function overloading allows you to define multiple functions with the same name but different parameter lists. This enables you to create functions that perform similar operations on different types or numbers of parameters.

## Basic Concept

### What is Function Overloading?
- Multiple functions with same name
- Different parameter lists
- Same scope
- Compiler selects correct version

### How it Works
```cpp
// Overloaded functions
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(string a, string b) {
    return a + b;
}

int main() {
    cout << add(5, 3);        // Calls int version
    cout << add(3.2, 1.4);    // Calls double version
    cout << add("Hello", "!"); // Calls string version
    return 0;
}
```

## Function Overloading Rules

### Valid Overloading
1. Different parameter types
```cpp
void print(int x);
void print(double x);
void print(string x);
```

2. Different number of parameters
```cpp
void display(int x);
void display(int x, int y);
void display(int x, int y, int z);
```

3. Different parameter order
```cpp
void format(int a, double b);
void format(double a, int b);
```

### Invalid Overloading
1. Return type only
```cpp
int getValue();     // ERROR: Can't overload
double getValue();  // by return type only
```

2. Parameter names only
```cpp
void process(int x);      // ERROR: Parameter names
void process(int value);  // don't count
```

## Practice Exercise

Create a program that demonstrates function overloading with:
1. Functions to find maximum of different types
2. Functions to print different types of arrays
3. Functions to format data in different ways

Solution:
```cpp
#include <iostream>
#include <string>
using namespace std;

// Overloaded maximum functions
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

char findMax(char a, char b) {
    return (a > b) ? a : b;
}

// Overloaded array print functions
void printArray(int arr[], int size) {
    cout << "Integer array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(double arr[], int size) {
    cout << "Double array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(char arr[], int size) {
    cout << "Character array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Overloaded format functions
string format(int number) {
    return "Number: " + to_string(number);
}

string format(double number, int precision) {
    string result = to_string(number);
    size_t decimal = result.find('.');
    if (decimal != string::npos) {
        result = result.substr(0, decimal + precision + 1);
    }
    return "Value: " + result;
}

string format(string text, bool uppercase) {
    if (uppercase) {
        for (char& c : text) {
            c = toupper(c);
        }
    }
    return "Text: " + text;
}

int main() {
    // Test maximum functions
    cout << "Maximum tests:" << endl;
    cout << findMax(10, 20) << endl;
    cout << findMax(3.14, 2.72) << endl;
    cout << findMax('a', 'z') << endl;
    
    // Test array print functions
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    
    printArray(intArr, 5);
    printArray(doubleArr, 5);
    printArray(charArr, 5);
    
    // Test format functions
    cout << "\nFormat tests:" << endl;
    cout << format(42) << endl;
    cout << format(3.14159, 2) << endl;
    cout << format("hello world", true) << endl;
    
    return 0;
}
```

## Common Use Cases

### Type Variations
```cpp
void print(int x);
void print(double x);
void print(string x);
```

### Parameter Count Variations
```cpp
void setColor(int r, int g, int b);
void setColor(int grayscale);
```

### Optional Parameters
```cpp
void drawRect(int x, int y);
void drawRect(int x, int y, string color);
void drawRect(int x, int y, string color, bool filled);
```

## Best Practices

1. Consistent Behavior
   - Related overloads should behave similarly
   - Keep parameter order consistent
   - Use similar naming conventions

2. Clear Purpose
   - Each overload should have clear use case
   - Avoid ambiguous overloads
   - Document differences clearly

3. Type Safety
   - Consider implicit conversions
   - Avoid ambiguous type situations
   - Use explicit type conversions when needed

4. Parameter Design
   - Keep parameter lists reasonable
   - Use default arguments when appropriate
   - Consider parameter order carefully

## Common Mistakes to Avoid
1. Overloading based on return type only
2. Creating ambiguous overloads
3. Inconsistent behavior between overloads
4. Too many overloads
5. Poor documentation of differences

## Next Steps
- Try the practice exercise
- Experiment with different overloading scenarios
- Move on to [Part 6: Scope of Variables]({{ site.baseurl }}/tutorials/module3/part6-scope)
