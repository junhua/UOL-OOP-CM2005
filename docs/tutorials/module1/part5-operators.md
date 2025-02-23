# Part 05: Basic Operators

## Learning Objectives
- Understand different types of operators in C++
- Learn operator precedence and associativity
- Practice using operators in expressions
- Handle common operator-related issues
- Combine operators effectively

## Introduction
Operators in C++ are like the basic tools in a toolbox - each has a specific purpose and works in a particular way. Just as you choose the right tool for a job, you need to select and use the appropriate operators for different programming tasks.

## Core Concepts

### 1. Arithmetic Operators
```cpp
int a = 10, b = 3;
int sum = a + b;      // Addition
int diff = a - b;     // Subtraction
int prod = a * b;     // Multiplication
int quot = a / b;     // Division
int rem = a % b;      // Modulus (remainder)
```

#### Key Points:
- Integer division truncates
- Modulus works with integers only
- Watch for overflow
- Consider type promotion

### 2. Assignment Operators
```cpp
int x = 5;            // Basic assignment
x += 3;               // Add and assign (x = x + 3)
x -= 2;               // Subtract and assign
x *= 4;               // Multiply and assign
x /= 2;               // Divide and assign
x %= 3;               // Modulus and assign
```

### 3. Comparison Operators
```cpp
bool isEqual = (a == b);     // Equal to
bool notEqual = (a != b);    // Not equal to
bool greater = (a > b);      // Greater than
bool less = (a < b);         // Less than
bool greaterEq = (a >= b);   // Greater than or equal
bool lessEq = (a <= b);      // Less than or equal
```

### 4. Logical Operators
```cpp
bool p = true, q = false;
bool andResult = p && q;     // Logical AND
bool orResult = p || q;      // Logical OR
bool notResult = !p;         // Logical NOT
```

#### Short-circuit Evaluation:
- `&&` stops at first false
- `||` stops at first true
- Use for conditional checks

### 5. Increment/Decrement Operators
```cpp
int i = 5;
++i;                 // Pre-increment
i++;                 // Post-increment
--i;                 // Pre-decrement
i--;                 // Post-decrement
```

#### Differences:
```cpp
int a = 5, b;
b = ++a;             // a = 6, b = 6
b = a++;             // a = 7, b = 6
```

### 6. Operator Precedence
```cpp
int result = 5 + 3 * 2;     // 11, not 16
int result2 = (5 + 3) * 2;  // 16
```

Common Precedence Rules:
1. Parentheses ()
2. Increment/Decrement
3. Multiplication/Division
4. Addition/Subtraction
5. Comparison operators
6. Logical operators
7. Assignment operators

## Practice Exercises

### 1. Basic Arithmetic
Create a calculator that:
- Performs basic operations
- Handles integer and floating-point
- Shows operator precedence
- Demonstrates type conversion

### 2. Logical Operations
Write a program that:
- Combines multiple conditions
- Uses short-circuit evaluation
- Demonstrates operator precedence
- Shows truth tables

### 3. Increment/Decrement
Create examples showing:
- Pre vs post increment
- Operator in expressions
- Common usage patterns
- Potential pitfalls

## Common Pitfalls
- Integer division truncation
- Operator precedence confusion
- Pre/post increment misuse
- Type conversion issues
- Logical operator misunderstanding

## Best Practices
- Use parentheses for clarity
- Consider type promotion
- Watch for overflow
- Test edge cases
- Document complex expressions
- Break down complex operations

## Further Reading
- Bitwise operators
- Advanced operators
- Type promotion rules
- Operator overloading
- Expression evaluation
