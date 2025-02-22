---
layout: default
title: Part 5 - Basic Programs
nav_order: 5
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part5-basic-programs/
---

# Part 5: Basic Programs

Learn how to create complete, functional programs by combining the concepts you've learned so far.

## Program Flow

### Basic Structure
```cpp
#include <iostream>

int main() {
    // Program logic here
    return 0;
}
```

## Simple Calculations

### Temperature Converter
```cpp
double celsius;
std::cout << "Enter temperature in Celsius: ";
std::cin >> celsius;

double fahrenheit = (celsius * 9/5) + 32;
std::cout << celsius << "°C = " << fahrenheit << "°F\n";
```

## User Interaction

### Interactive Menu
```cpp
int choice;
std::cout << "Choose an option:\n"
          << "1. Calculate Area\n"
          << "2. Calculate Perimeter\n"
          << "Enter choice (1-2): ";
std::cin >> choice;
```

## Basic Error Checking

### Input Validation
```cpp
if (choice < 1 || choice > 2) {
    std::cout << "Invalid choice!\n";
    return 1;
}
```

## Program Organization

### Functions
```cpp
double calculateArea(double length, double width) {
    return length * width;
}

double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}
```

## Practice Exercises

1. Create a basic calculator
2. Build a temperature converter
3. Make an interactive menu program
4. Implement input validation

## Next Steps
Move on to [Part 6: Problem Solving]({{ site.baseurl }}/tutorials/module1/part6-problem-solving) to learn how to approach and solve programming problems systematically.
