---
layout: default
title: Part 4 - Operators
nav_order: 4
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part4-operators/
---

# Part 4: Operators

Learn about the different types of operators in C++ and how to use them effectively in your programs.

## Arithmetic Operators

### Basic Operations
```cpp
int a = 10, b = 3;
int sum = a + b;      // Addition
int diff = a - b;     // Subtraction
int prod = a * b;     // Multiplication
int quot = a / b;     // Division
int rem = a % b;      // Modulus (remainder)
```

## Assignment Operators

### Simple Assignment
```cpp
int x = 5;            // Basic assignment
x += 3;               // Same as: x = x + 3
x -= 2;               // Same as: x = x - 2
x *= 4;               // Same as: x = x * 4
x /= 2;               // Same as: x = x / 2
x %= 3;               // Same as: x = x % 3
```

## Comparison Operators

### Common Comparisons
```cpp
bool isEqual = (a == b);   // Equal to
bool notEqual = (a != b);  // Not equal to
bool greater = (a > b);    // Greater than
bool less = (a < b);       // Less than
bool greaterEq = (a >= b); // Greater than or equal to
bool lessEq = (a <= b);    // Less than or equal to
```

## Logical Operators

### Boolean Logic
```cpp
bool condition1 = true;
bool condition2 = false;

bool andResult = condition1 && condition2;  // AND
bool orResult = condition1 || condition2;   // OR
bool notResult = !condition1;               // NOT
```

## Operator Precedence

### Order of Operations
```cpp
int result = 5 + 3 * 2;    // Multiplication before addition
int result2 = (5 + 3) * 2; // Parentheses override precedence
```

## Practice Exercises

1. Create a calculator program using different operators
2. Experiment with operator precedence
3. Use comparison operators in conditions
4. Combine logical operators in complex conditions

## Next Steps
Continue to [Part 5: Basic Programs]({{ site.baseurl }}/tutorials/module1/part5-basic-programs) to learn how to put these concepts together in complete programs.
