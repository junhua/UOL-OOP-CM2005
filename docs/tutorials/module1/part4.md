---
layout: default
title: Part 4 - Operators
---

# Part 4: Operators

Welcome to Part 4! Today we'll learn about operators - the tools that help us perform calculations and make decisions in our programs. Think of operators as the basic tools in your programming toolbox!

## Understanding Operators

Imagine you're working with a calculator:
- The buttons (+, -, ×, ÷) are like arithmetic operators
- The memory buttons (M+, M-) are like assignment operators
- The comparison buttons (>, <, =) are like comparison operators

## Arithmetic Operators

### Basic Math Operations
Just like a calculator, C++ can perform basic math:

```cpp
int a = 10, b = 3;

// Addition
int sum = a + b;        // 10 + 3 = 13
// Like putting two numbers together

// Subtraction
int difference = a - b; // 10 - 3 = 7
// Like taking away one number from another

// Multiplication
int product = a * b;    // 10 * 3 = 30
// Like adding a number to itself multiple times

// Division
int quotient = a / b;   // 10 / 3 = 3 (integer division!)
// Like splitting into equal parts

// Modulus (remainder)
int remainder = a % b;  // 10 % 3 = 1
// Like what's left after division
```

### Understanding Integer Division
```cpp
int result1 = 5 / 2;     // Result: 2 (not 2.5!)
double result2 = 5.0 / 2; // Result: 2.5 (using decimal point)
```

Think of integer division like sharing cookies:
- If you share 5 cookies among 2 people
- Each person gets 2 cookies
- 1 cookie is left over (the remainder)

### Increment/Decrement
These operators add or subtract 1:

```cpp
int x = 5;

// Two ways to add 1:
x++;    // Post-increment: use x, then add 1
++x;    // Pre-increment: add 1, then use x

// Two ways to subtract 1:
x--;    // Post-decrement: use x, then subtract 1
--x;    // Pre-decrement: subtract 1, then use x
```

Think of it like:
- Post-increment (x++): "Use it, then increase it"
- Pre-increment (++x): "Increase it, then use it"

## Assignment Operators

### Simple Assignment
```cpp
int x = 5;  // Put the value 5 into x
```

Like putting a value into a box.

### Compound Assignment
These operators combine arithmetic with assignment:

```cpp
int x = 10;

x += 3;     // Same as: x = x + 3
// Like saying "add 3 to whatever's in x"

x -= 2;     // Same as: x = x - 2
// Like saying "subtract 2 from whatever's in x"

x *= 4;     // Same as: x = x * 4
// Like saying "multiply whatever's in x by 4"

x /= 2;     // Same as: x = x / 2
// Like saying "divide whatever's in x by 2"
```

## Comparison Operators

These operators compare values and return true or false:

```cpp
int a = 5, b = 3;

// Equal to
bool isEqual = (a == b);     // false
// Like asking "Is 5 the same as 3?"

// Not equal to
bool notEqual = (a != b);    // true
// Like asking "Is 5 different from 3?"

// Greater than
bool greater = (a > b);      // true
// Like asking "Is 5 bigger than 3?"

// Less than
bool less = (a < b);         // false
// Like asking "Is 5 smaller than 3?"

// Greater than or equal to
bool greaterEqual = (a >= b); // true
// Like asking "Is 5 bigger than or the same as 3?"

// Less than or equal to
bool lessEqual = (a <= b);    // false
// Like asking "Is 5 smaller than or the same as 3?"
```

## Logical Operators

These operators work with true/false values:

```cpp
bool hasPass = true;
bool isStudent = true;

// AND (&&): Both must be true
bool canEnter = hasPass && isStudent;  // true
// Like needing both a ticket AND ID to enter a movie

// OR (||): At least one must be true
bool canVote = isStudent || hasPass;   // true
// Like accepting either a passport OR driver's license

// NOT (!): Reverses true/false
bool cantEnter = !hasPass;  // false
// Like turning yes into no, or no into yes
```

### Short-Circuit Evaluation
```cpp
// Second part only checked if first part is true
if (isStudent && hasValidID()) {
    // Like checking ID only if person claims to be student
}
```

## Practice Exercise

Create a program that:
1. Gets two numbers from the user
2. Performs all arithmetic operations
3. Shows all comparison results
4. Demonstrates logical operators
5. Uses compound assignments

Example output:
```
Enter first number: 10
Enter second number: 3

Arithmetic:
10 + 3 = 13
10 - 3 = 7
10 * 3 = 30
10 / 3 = 3 (quotient)
10 % 3 = 1 (remainder)

Comparisons:
10 is greater than 3: true
10 is equal to 3: false
...
```

[View Solution]({{ site.baseurl }}/tutorials/module1/part4/solution)

## Common Mistakes to Avoid

### 1. Using = Instead of ==
```cpp
// Wrong! This assigns 5 to x
if (x = 5) { ... }

// Correct! This compares x with 5
if (x == 5) { ... }
```

### 2. Integer Division Surprises
```cpp
// Wrong! Result will be 0
int result = 5 / 10;

// Correct! Result will be 0.5
double result = 5.0 / 10.0;
```

### 3. Operator Precedence
```cpp
// Wrong! Multiplication happens before addition
int result = 2 + 3 * 4;    // Result: 14

// Correct! Use parentheses to control order
int result = (2 + 3) * 4;  // Result: 20
```

## Best Practices
1. Use parentheses for clarity
   ```cpp
   int result = (a + b) * (c + d);
   ```

2. Be careful with integer division
   ```cpp
   double result = static_cast<double>(total) / count;
   ```

3. Use meaningful comparisons
   ```cpp
   if (age >= 18) {  // Clear meaning
       // Can vote
   }
   ```

4. Check for division by zero
   ```cpp
   if (divisor != 0) {
       result = dividend / divisor;
   }
   ```

## Next Steps
1. Complete the practice exercise
2. Experiment with different operators
3. Try combining operators
4. Move on to [Part 5: Basic Programs]({{ site.baseurl }}/tutorials/module1/part5)

## Additional Resources
- [Operator Precedence Chart]({{ site.baseurl }}/docs/reference/operator-precedence)
- [Common Operator Mistakes]({{ site.baseurl }}/docs/guides/operator-mistakes)
- [Integer vs Floating-Point Division]({{ site.baseurl }}/docs/guides/division)

Remember: Operators are the basic tools of programming. Take time to understand how each one works!
