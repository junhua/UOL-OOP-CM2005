---
layout: default
title: Part 5 - Working with Operators
nav_order: 5
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part5-operators
---

# Part 5: Basic Operators

## Learning Objectives
- Understand different types of operators in C++
- Learn operator precedence and associativity
- Practice using operators in expressions
- Handle common operator-related issues
- Combine operators effectively

## Introduction
Operators are the building blocks of computation in C++, allowing you to perform calculations, make comparisons, and manipulate data. This part explores several categories of operators:

1. **Arithmetic Operators**:
   - Basic mathematics (+, -, *, /, %)
   - Order of operations
   - Integer vs floating-point division
   - Modulus operations

2. **Assignment Operators**:
   - Simple assignment (=)
   - Compound assignments (+=, -=, *=, /=)
   - Chained assignments
   - Assignment with type conversion

3. **Comparison Operators**:
   - Equality and inequality (==, !=)
   - Relational operators (<, >, <=, >=)
   - Comparing different types
   - Common comparison pitfalls

4. **Logical Operators**:
   - AND, OR, NOT operations (&&, \|\|, !)
   - Short-circuit evaluation
   - Combining conditions
   - Truth tables and boolean logic

5. **Increment/Decrement**:
   - Pre and post increment (++x, x++)
   - Pre and post decrement (--x, x--)
   - Side effects and sequence points
   - Common usage patterns

Understanding these operators and their proper usage is crucial for writing efficient and bug-free code. Through examples, you'll learn how to combine operators effectively while avoiding common pitfalls.

## Implementation Guide

### Step 1: Start with the Template
Let's examine our starting point:
1. Open the starter code file `Tutorials/Module01/Part5/operators_starter.cpp`
2. The template outlines what we'll implement:

```cpp
// TODO: Add necessary include directives

int main() {
    // TODO: Demonstrate arithmetic operators
    // 1. Addition
    // 2. Subtraction
    // 3. Multiplication
    // 4. Division
    // 5. Modulus
    // Print results of each operation

    // TODO: Demonstrate assignment operators
    // 1. Basic assignment
    // 2. Compound assignments (+=, -=, *=, /=, %=)
    // Print results after each assignment

    // TODO: Demonstrate comparison operators
    // 1. Equal to (==)
    // 2. Not equal to (!=)
    // 3. Greater than (>)
    // 4. Less than (<)
    // 5. Greater than or equal to (>=)
    // 6. Less than or equal to (<=)
    // Print results of comparisons

    // TODO: Demonstrate logical operators
    // 1. AND (&&)
    // 2. OR (||)
    // 3. NOT (!)
    // Print results of logical operations

    // TODO: Demonstrate increment/decrement operators
    // 1. Pre-increment (++x)
    // 2. Post-increment (x++)
    // 3. Pre-decrement (--x)
    // 4. Post-decrement (x--)
    // Show the difference between pre and post operations

    return 0;
}
```

### Step 2: Add Include Directives
We need two headers for our program:
1. iostream for output operations
2. iomanip for formatting boolean values

```cpp
#include <iostream>
#include <iomanip>
```

### Step 3: Implement Arithmetic Operators
Let's demonstrate basic mathematical operations:
1. Declare two variables for operands
2. Show each arithmetic operation
3. Display results clearly

```cpp
    // Arithmetic Operators
    std::cout << "--- Arithmetic Operators ---\n";
    int a = 10, b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Addition: a + b = " << a + b << std::endl;
    std::cout << "Subtraction: a - b = " << a - b << std::endl;
    std::cout << "Multiplication: a * b = " << a * b << std::endl;
    std::cout << "Division: a / b = " << a / b << std::endl;
    std::cout << "Modulus: a % b = " << a % b << std::endl;
```

### Step 4: Implement Assignment Operators
Now let's show different ways to assign values:
1. Start with basic assignment
2. Demonstrate compound assignments
3. Show how each modifies the variable

```cpp
    // Assignment Operators
    std::cout << "\n--- Assignment Operators ---\n";
    int x = 5;
    std::cout << "Initial x = " << x << std::endl;
    x += 3;  // x = x + 3
    std::cout << "After x += 3: x = " << x << std::endl;
    x -= 2;  // x = x - 2
    std::cout << "After x -= 2: x = " << x << std::endl;
    x *= 4;  // x = x * 4
    std::cout << "After x *= 4: x = " << x << std::endl;
    x /= 2;  // x = x / 2
    std::cout << "After x /= 2: x = " << x << std::endl;
    x %= 3;  // x = x % 3
    std::cout << "After x %= 3: x = " << x << std::endl;
```

### Step 5: Implement Comparison Operators
Let's explore how to compare values:
1. Set up two variables to compare
2. Show all comparison operations
3. Display results as true/false

```cpp
    // Comparison Operators
    std::cout << "\n--- Comparison Operators ---\n";
    int p = 5, q = 10;
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << std::boolalpha;  // Print bool as true/false instead of 1/0
    std::cout << "p == q: " << (p == q) << std::endl;
    std::cout << "p != q: " << (p != q) << std::endl;
    std::cout << "p > q: " << (p > q) << std::endl;
    std::cout << "p < q: " << (p < q) << std::endl;
    std::cout << "p >= q: " << (p >= q) << std::endl;
    std::cout << "p <= q: " << (p <= q) << std::endl;
```

### Step 6: Implement Logical Operators
Demonstrate boolean logic operations:
1. Create boolean variables
2. Show AND, OR, NOT operations
3. Display logical results

```cpp
    // Logical Operators
    std::cout << "\n--- Logical Operators ---\n";
    bool condition1 = true, condition2 = false;
    std::cout << "condition1 = " << condition1 << ", condition2 = " << condition2 << std::endl;
    std::cout << "AND (&&): " << (condition1 && condition2) << std::endl;
    std::cout << "OR (||): " << (condition1 || condition2) << std::endl;
    std::cout << "NOT (!): " << (!condition1) << std::endl;
```

### Step 7: Implement Increment/Decrement Operators
Show the difference between pre and post operations:
1. Demonstrate pre-increment/decrement
2. Show post-increment/decrement
3. Explain the differences clearly

```cpp
    // Increment/Decrement Operators
    std::cout << "\n--- Increment/Decrement Operators ---\n";
    int i = 5, j;
    std::cout << "Initial i = " << i << std::endl;
    
    // Pre-increment
    j = ++i;  // i is incremented first, then j gets the new value
    std::cout << "After j = ++i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-increment
    j = i++;  // j gets the original value, then i is incremented
    std::cout << "After j = i++: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Pre-decrement
    j = --i;  // i is decremented first, then j gets the new value
    std::cout << "After j = --i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-decrement
    j = i--;  // j gets the original value, then i is decremented
    std::cout << "After j = i--: i = " << i << ", j = " << j << std::endl;
```

### Final Code
Here's how all the pieces fit together:

```cpp
#include <iostream>
#include <iomanip>

int main() {
    // Arithmetic Operators
    std::cout << "--- Arithmetic Operators ---\n";
    int a = 10, b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Addition: a + b = " << a + b << std::endl;
    std::cout << "Subtraction: a - b = " << a - b << std::endl;
    std::cout << "Multiplication: a * b = " << a * b << std::endl;
    std::cout << "Division: a / b = " << a / b << std::endl;
    std::cout << "Modulus: a % b = " << a % b << std::endl;

    // Assignment Operators
    std::cout << "\n--- Assignment Operators ---\n";
    int x = 5;
    std::cout << "Initial x = " << x << std::endl;
    x += 3;  // x = x + 3
    std::cout << "After x += 3: x = " << x << std::endl;
    x -= 2;  // x = x - 2
    std::cout << "After x -= 2: x = " << x << std::endl;
    x *= 4;  // x = x * 4
    std::cout << "After x *= 4: x = " << x << std::endl;
    x /= 2;  // x = x / 2
    std::cout << "After x /= 2: x = " << x << std::endl;
    x %= 3;  // x = x % 3
    std::cout << "After x %= 3: x = " << x << std::endl;

    // Comparison Operators
    std::cout << "\n--- Comparison Operators ---\n";
    int p = 5, q = 10;
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << std::boolalpha;  // Print bool as true/false instead of 1/0
    std::cout << "p == q: " << (p == q) << std::endl;
    std::cout << "p != q: " << (p != q) << std::endl;
    std::cout << "p > q: " << (p > q) << std::endl;
    std::cout << "p < q: " << (p < q) << std::endl;
    std::cout << "p >= q: " << (p >= q) << std::endl;
    std::cout << "p <= q: " << (p <= q) << std::endl;

    // Logical Operators
    std::cout << "\n--- Logical Operators ---\n";
    bool condition1 = true, condition2 = false;
    std::cout << "condition1 = " << condition1 << ", condition2 = " << condition2 << std::endl;
    std::cout << "AND (&&): " << (condition1 && condition2) << std::endl;
    std::cout << "OR (||): " << (condition1 || condition2) << std::endl;
    std::cout << "NOT (!): " << (!condition1) << std::endl;

    // Increment/Decrement Operators
    std::cout << "\n--- Increment/Decrement Operators ---\n";
    int i = 5, j;
    std::cout << "Initial i = " << i << std::endl;
    
    // Pre-increment
    j = ++i;  // i is incremented first, then j gets the new value
    std::cout << "After j = ++i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-increment
    j = i++;  // j gets the original value, then i is incremented
    std::cout << "After j = i++: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Pre-decrement
    j = --i;  // i is decremented first, then j gets the new value
    std::cout << "After j = --i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-decrement
    j = i--;  // j gets the original value, then i is decremented
    std::cout << "After j = i--: i = " << i << ", j = " << j << std::endl;

    return 0;
}
```

## Understanding Operators

### Arithmetic Operators
- Addition (+): Adds two values
- Subtraction (-): Subtracts second value from first
- Multiplication (*): Multiplies two values
- Division (/): Divides first value by second
- Modulus (%): Returns division remainder

### Assignment Operators
- Basic (=): Assigns right value to left
- Compound (+=, -=, etc.): Combines operation with assignment
- Shorthand for common operations

### Comparison Operators
- Equal (==): Tests for equality
- Not Equal (!=): Tests for inequality
- Greater/Less (<, >): Tests relative values
- Greater/Less Equal (<=, >=): Includes equality

### Logical Operators
- AND (&&): True if both true
- OR (\|\|): True if either true
- NOT (!): Inverts truth value

### Increment/Decrement
- Pre (++x): Increment then use
- Post (x++): Use then increment
- Same for decrement (--x, x--)

## Practice Exercises

Open the starter code file `Tutorials/Module01/Part5/practice_operators_starter.cpp`. This file contains a template for exploring different types of operators.

### 1. Calculator Operations
Implement the following in the starter code:
1. Create variables for two numbers
2. Implement all arithmetic operators (+, -, *, /, %)
3. Show operator precedence with complex expressions
4. Format the output for clarity
5. Handle division by zero cases

### 2. Logical Operations
Add to your implementation:
1. Create boolean variables for testing conditions
2. Demonstrate AND, OR, NOT operations
3. Create a complete truth table
4. Show short-circuit evaluation with examples
5. Combine multiple conditions in complex expressions

### 3. Increment/Decrement Operations
Complete your implementation by adding:
1. Demonstrate pre and post increment (++x vs x++)
2. Show pre and post decrement (--x vs x--)
3. Use increments in expressions to show differences
4. Implement common usage patterns in loops

You can compare your solution with the completed example in `Tutorials/Module01/Part5/practice_operators.cpp`.

The final code demonstrates:
- Arithmetic operator usage
- Logical operator combinations
- Increment/decrement behavior
- Operator precedence
- Formatted output

## Common Pitfalls
- Integer division truncation
- Operator precedence confusion
- Pre/post increment misuse
- Type conversion issues
- Division by zero

## Best Practices
1. Use parentheses for clarity
2. Be careful with integer division
3. Consider type promotion
4. Watch for overflow
5. Document complex expressions

## Next Steps
After completing this part:
1. Make sure your program compiles and runs
2. Try the practice exercises
3. Compare your solutions with the final version
4. Move on to Part 6 to learn about comments

[Continue to Part 6: Comments and Code Readability]({{ site.baseurl }}/tutorials/module1/part6-comments)
