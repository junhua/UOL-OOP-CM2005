---
layout: default
title: Part 2 - Variables and Types
---

# Part 2: Variables and Types

Welcome to Part 2! Now that you can write and run basic programs, let's learn about variables and data types - the building blocks of programming.

## What are Variables?

Think of variables like labeled boxes where you can store different types of things:
- A box labeled "age" might store the number 20
- A box labeled "name" might store the text "John"
- A box labeled "temperature" might store 98.6

In C++, we need to tell the computer what type of data each box (variable) will store.

## Data Types in C++

### Understanding Types with Real-World Examples

#### 1. Integer Types (Whole Numbers)
Just like different size boxes, C++ has different types for storing whole numbers:

```cpp
int age = 20;              // Regular box: -2 billion to +2 billion
short smallNumber = 100;   // Small box: -32,768 to +32,767
long bigNumber = 1000000;  // Big box: very large numbers
```

Real-world examples:
- `int`: Age, counting things, scores
- `short`: Day of month, hour of day
- `long`: Population counts, distances in meters

#### 2. Floating-Point Types (Decimal Numbers)
For numbers with decimal points:

```cpp
float temperature = 98.6f;    // Single precision (7 digits)
double price = 19.99;         // Double precision (15 digits)
```

Think of it like:
- `float`: Temperature, height in meters
- `double`: Scientific calculations, precise money amounts

#### 3. Character Type (Single Characters)
For storing single characters:

```cpp
char grade = 'A';            // Single quotes for characters
char symbol = '$';
char digit = '7';            // The character '7', not the number 7
```

Like a tiny box that fits exactly one character:
- Letters: 'A' to 'Z', 'a' to 'z'
- Digits: '0' to '9'
- Symbols: '$', '#', '@', etc.

#### 4. Boolean Type (True/False)
For yes/no, true/false situations:

```cpp
bool isStudent = true;
bool isPassed = false;
```

Like a light switch - only two possible states:
- `true`: Yes, on, correct
- `false`: No, off, incorrect

### Understanding Memory and Size

Every variable takes up space in the computer's memory. Let's see how much:

```cpp
#include <iostream>

int main() {
    std::cout << "Size of different types:\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " byte\n";
    std::cout << "bool: " << sizeof(bool) << " byte\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
}
```

Think of it like:
- `char` (1 byte): Like a small locker
- `int` (4 bytes): Like a medium cabinet
- `double` (8 bytes): Like a large storage unit

## Declaring Variables

### Basic Declaration
There are three main ways to create variables:

```cpp
// Method 1: Declaration and initialization in one line
int studentAge = 20;                // Most common way

// Method 2: Declare first, assign later
int score;                          // Create the variable
score = 95;                         // Assign a value

// Method 3: Initialize multiple variables
int x = 0, y = 0, z = 0;           // All in one line
```

### Type Inference with 'auto'
Let C++ figure out the type automatically:

```cpp
auto number = 42;        // C++ sees 42 and knows it's an int
auto name = "John";      // C++ sees "John" and knows it's a string
auto price = 19.99;      // C++ sees 19.99 and knows it's a double
```

Think of `auto` like telling C++: "You figure out what size box we need."

## Constants

Some values should never change. We use constants for these:

```cpp
const double PI = 3.14159;          // Mathematical constant
const int MAX_STUDENTS = 30;        // Class size limit
const char GRADE_A = 'A';           // Grade symbol
```

Real-world examples of constants:
- Days in a week (always 7)
- Months in a year (always 12)
- Freezing point of water (always 0°C)

## Type Conversion

Sometimes we need to convert between types:

### Safe Conversions
```cpp
int whole = 5;
double decimal = whole;    // Safe: 5 becomes 5.0
```
Like pouring water from a small cup into a bigger one - no spillage!

### Risky Conversions
```cpp
double price = 19.99;
int dollars = price;       // Risky: loses the .99
```
Like pouring water from a big cup into a smaller one - might lose some!

### Safe Type Casting
```cpp
double price = 19.99;
int dollars = static_cast<int>(price);  // Proper way to convert
```

## Practice Exercise

Create a program that:
1. Declares variables for:
   - Your age (int)
   - Your height in meters (double)
   - Your first initial (char)
   - Whether you're a student (bool)
2. Prints all these values
3. Performs some calculations:
   - Age in months
   - Height in centimeters
   - Years until graduation

[View Solution]({{ site.baseurl }}/tutorials/module1/part2/solution)

## Common Mistakes to Avoid

### 1. Using Variables Before Initialization
```cpp
int score;
std::cout << score;    // Wrong! Value is undefined
```
Always give variables a value before using them!

### 2. Type Mismatch
```cpp
int number = 3.14;     // Wrong! Loses decimal part
char grade = "A";      // Wrong! "A" is string, 'A' is char
```

### 3. Name Conflicts
```cpp
int age = 20;
int Age = 25;     // Different variable! C++ is case-sensitive
```

## Best Practices
1. Use meaningful variable names
   - Good: `studentAge`, `totalScore`
   - Bad: `x`, `temp`, `var1`

2. Initialize variables when declared
   ```cpp
   int count = 0;    // Good
   int count;        // Less good
   ```

3. Use constants for fixed values
   ```cpp
   const int DAYS_IN_WEEK = 7;
   ```

4. Choose appropriate types
   - Use `int` for whole numbers
   - Use `double` for decimal numbers
   - Use `char` for single characters
   - Use `bool` for true/false values

## Next Steps
1. Complete the practice exercise
2. Experiment with different types
3. Try type conversions
4. Move on to [Part 3: Input/Output]({{ site.baseurl }}/tutorials/module1/part3)

## Additional Resources
- [C++ Data Types Reference]({{ site.baseurl }}/docs/reference/data-types)
- [Variable Naming Guidelines]({{ site.baseurl }}/docs/guides/naming)
- [Type Conversion Guide]({{ site.baseurl }}/docs/guides/type-conversion)

Remember: Take your time to understand these concepts - they're fundamental to everything else in C++!
