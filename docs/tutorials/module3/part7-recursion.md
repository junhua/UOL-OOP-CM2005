---
layout: default
title: Part 7 - Introduction to Recursion
nav_order: 7
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part7-recursion/
---

# Part 7: Introduction to Recursion

## Overview
Recursion is a programming concept where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems. Understanding recursion is crucial for solving certain types of problems elegantly.

## Basic Concept

### What is Recursion?
- Function that calls itself
- Solves problem by breaking it down
- Has base case(s) to stop recursion
- Each call works on smaller problem

### Components of Recursion
1. Base Case
   - Condition to stop recursion
   - Simple case solved directly
   - Prevents infinite recursion

2. Recursive Case
   - Function calls itself
   - Problem gets smaller
   - Moves toward base case

## Simple Example: Factorial

```cpp
int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorial(n - 1);
}
```

### How it Works
```
factorial(4)
→ 4 * factorial(3)
  → 3 * factorial(2)
    → 2 * factorial(1)
      → 1  // Base case
    ← 2 * 1 = 2
  ← 3 * 2 = 6
← 4 * 6 = 24
```

## Common Recursive Problems

### 1. Fibonacci Sequence
```cpp
int fibonacci(int n) {
    // Base cases
    if (n <= 1) return n;
    
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### 2. Sum of Array
```cpp
int arraySum(int arr[], int size) {
    // Base case
    if (size <= 0) return 0;
    
    // Recursive case
    return arr[size - 1] + arraySum(arr, size - 1);
}
```

### 3. Power Function
```cpp
double power(double base, int exponent) {
    // Base cases
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    
    // Recursive case
    return base * power(base, exponent - 1);
}
```

## Practice Exercise

Create a program that implements several recursive functions:
1. Calculate sum of digits in a number
2. Count occurrences of a digit in a number
3. Print number in reverse
4. Check if string is palindrome

Solution:
```cpp
#include <iostream>
#include <string>
using namespace std;

// Sum of digits
int sumDigits(int number) {
    // Base case: single digit
    if (number < 10) {
        return number;
    }
    
    // Recursive case: add last digit to sum of remaining digits
    return (number % 10) + sumDigits(number / 10);
}

// Count digit occurrences
int countDigit(int number, int digit) {
    // Base case: no more digits
    if (number == 0) {
        return 0;
    }
    
    // Check last digit and recurse with remaining digits
    int lastDigit = number % 10;
    return (lastDigit == digit ? 1 : 0) + countDigit(number / 10, digit);
}

// Print number in reverse
void printReverse(int number) {
    // Base case: single digit
    if (number < 10) {
        cout << number;
        return;
    }
    
    // Print last digit and recurse with remaining digits
    cout << number % 10;
    printReverse(number / 10);
}

// Check palindrome
bool isPalindrome(string str, int start, int end) {
    // Base cases
    if (start >= end) {
        return true;
    }
    
    // If characters don't match, not a palindrome
    if (str[start] != str[end]) {
        return false;
    }
    
    // Check remaining characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    // Test sum of digits
    int number = 12345;
    cout << "Sum of digits in " << number << ": " 
         << sumDigits(number) << endl;
    
    // Test count digit
    int digit = 3;
    cout << "Occurrences of " << digit << " in " << number << ": " 
         << countDigit(number, digit) << endl;
    
    // Test reverse print
    cout << number << " in reverse: ";
    printReverse(number);
    cout << endl;
    
    // Test palindrome
    string text = "racecar";
    cout << text << " is " 
         << (isPalindrome(text, 0, text.length() - 1) ? "" : "not ")
         << "a palindrome" << endl;
    
    return 0;
}
```

## Recursion vs Iteration

### Advantages of Recursion
1. Cleaner code for some problems
2. Natural solution for recursive problems
3. Easier to understand and maintain
4. Good for tree-like structures

### Disadvantages of Recursion
1. Memory overhead for call stack
2. Can be slower than iteration
3. Risk of stack overflow
4. May be harder to debug

## Best Practices

### 1. Base Case Design
- Always have at least one base case
- Make sure base case is reachable
- Handle edge cases
- Test base case separately

### 2. Recursive Case Design
- Ensure problem gets smaller
- Move toward base case
- Avoid unnecessary recursion
- Consider stack depth

### 3. Performance Considerations
- Use tail recursion when possible
- Consider iterative solution for simple cases
- Be aware of stack limitations
- Avoid redundant calculations

### 4. Testing Strategy
- Test base cases first
- Test small inputs
- Test edge cases
- Verify stack behavior

## Common Mistakes to Avoid
1. Missing base case
2. Infinite recursion
3. Stack overflow
4. Redundant calculations
5. Wrong base case condition

## Next Steps
- Try the practice exercise
- Experiment with different recursive problems
- Study more complex recursive algorithms
- Consider taking [Module 4: Collections and Strings]({{ site.baseurl }}/tutorials/module4)
