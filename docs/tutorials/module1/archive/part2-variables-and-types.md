---
layout: default
title: Part 2 - Variables and Types
nav_order: 2
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part2-variables-and-types/
---

# Part 2: Variables and Types

Welcome to Part 2! Now that you can write and run basic programs, let's learn about variables and data types - the building blocks of programming.

## What are Variables?

Think of variables like labeled boxes where you can store different types of things:
- A box labeled "age" might store the number 20
- A box labeled "name" might store the text "John"
- A box labeled "temperature" might store 98.6

In C++, we need to tell the computer what type of data each box (variable) will store.

## Understanding Data Types

### Getting Started with the Data Types Example

1. Open the starter file:
   - Navigate to `Tutorials/Module01/Part02/Starter/`
   - Open `data_types_starter.cpp`

2. First, add the necessary headers:
```cpp
#include <iostream>   // For input/output
#include <limits>     // For finding limits of data types
```

### Implementing Integer Types

Add these variables after the first TODO:
```cpp
// Integer types (whole numbers)
int integer = 42;              // Most common type, range: roughly ±2 billion
short smallNumber = 123;       // Uses less memory, range: roughly ±32,000
long largeNumber = 123456789L; // For very large numbers, range: ±9 quintillion
unsigned positiveOnly = 100;   // Only positive numbers, doubles the positive range
```

Each integer type serves a specific purpose:
- `int`: Default choice for most whole numbers (counting items, ages, scores)
- `short`: When memory is tight and values stay small (e.g., days in month, hour of day)
- `long`: For very large calculations (e.g., world population, financial calculations)
- `unsigned`: When negative values are impossible (e.g., quantity, array size)

### Adding Floating-Point Types

Add these after the next TODO:
```cpp
// Floating-point types (decimal numbers)
float decimal = 3.14159f;      // 7 digits of precision (32-bit)
double precise = 3.14159265359;// 15-16 digits of precision (64-bit)
```

Choose between them based on needs:
- `float`: Good for graphics, simple measurements where extreme precision isn't needed
  - Example: game physics, temperature readings, basic calculations
- `double`: Essential for financial calculations, scientific computations
  - Example: currency calculations, scientific measurements, statistical analysis

### Character and Boolean Types

Add these next:
```cpp
// Character type (stores a single character)
char letter = 'A';             // Uses single quotes for characters
char digit = '5';              // Can store numbers as characters
char symbol = '$';             // Can store special symbols

// Boolean type (true/false values)
bool isAdult = true;           // Used for yes/no conditions
bool hasPassedExam = false;    // Used for state tracking
```

Important notes:
- Characters (`char`):
  - Always use single quotes ('A'), not double quotes ("A")
  - Can represent letters, numbers, symbols, or special characters
  - Often used in text processing and input validation

- Booleans (`bool`):
  - Perfect for conditions (if statements, loop controls)
  - Used for flags and state tracking in programs
  - More memory efficient than using integers for true/false values

### Displaying Information

Let's see how much memory each type uses. Uncomment and complete these statements:
```cpp
// Display size of each type in bytes
std::cout << "int: " << sizeof(int) 
          << " bytes (typically 4 bytes on most systems)\n";
std::cout << "short: " << sizeof(short)
          << " bytes (typically 2 bytes, good for small numbers)\n";
std::cout << "long: " << sizeof(long)
          << " bytes (typically 8 bytes for large numbers)\n";
std::cout << "float: " << sizeof(float)
          << " bytes (typically 4 bytes for basic decimal numbers)\n";
std::cout << "double: " << sizeof(double)
          << " bytes (typically 8 bytes for precise calculations)\n";
std::cout << "char: " << sizeof(char)
          << " byte (always 1 byte for single characters)\n";
std::cout << "bool: " << sizeof(bool)
          << " byte (typically 1 byte despite only needing 1 bit)\n";
```

This will show you the memory footprint of each type. Understanding memory usage helps you:
- Choose efficient types for your data
- Understand system limitations
- Optimize memory usage in large programs

### Understanding Memory and Size

Now let's explore the range of values each type can hold:
```cpp
// Display minimum and maximum values for integer types
std::cout << "int range: " 
          << std::numeric_limits<int>::min() << " to " 
          << std::numeric_limits<int>::max() << "\n";
std::cout << "unsigned int range: 0 to "
          << std::numeric_limits<unsigned int>::max() << "\n";
std::cout << "short range: "
          << std::numeric_limits<short>::min() << " to "
          << std::numeric_limits<short>::max() << "\n";
std::cout << "long range: "
          << std::numeric_limits<long>::min() << " to "
          << std::numeric_limits<long>::max() << "\n";

// Display precision for floating-point types
std::cout << "float precision: " 
          << std::numeric_limits<float>::digits10 << " digits\n";
std::cout << "double precision: "
          << std::numeric_limits<double>::digits10 << " digits\n";
```

This code demonstrates:
- The vast range difference between types
- Why unsigned types can store larger positive numbers
- The precision capabilities of floating-point types
- Why certain types are better suited for specific tasks

Example output you might see:
```
int range: -2147483648 to 2147483647
unsigned int range: 0 to 4294967295
float precision: 6 digits
double precision: 15 digits
```

## Practice Exercise: Shopping Cart Calculator

Now let's apply what we learned in a practical example!

1. Open `practice_starter.cpp` in the `Starter/` folder

2. Add the necessary headers:
```cpp
#include <iostream>   // Provides input/output functionality
#include <iomanip>    // For formatting decimal numbers (setprecision, fixed)
```

3. Declare constants (values that won't change):
```cpp
const double TAX_RATE = 0.07;        // 'const' prevents accidental changes
constexpr int MONTHS_IN_YEAR = 12;   // 'constexpr' is computed at compile time
                                     // Use for values known before program runs
```

4. Declare variables for the calculation:
```cpp
double itemPrice = 29.99;            // double for money (precise decimal)
int quantity = 3;                    // int for counting whole items
float discountPercent = 10.5f;       // float sufficient for percentage
                                     // 'f' suffix tells C++ it's a float
```

5. Calculate subtotal:
```cpp
double subtotal = itemPrice * quantity;
```

6. Calculate discount:
```cpp
double discount = subtotal * (discountPercent / 100.0);
```

Continue following the TODOs, implementing each calculation step by step.

### Testing Your Implementation

1. Compare your output with the example above
2. Make sure all calculations are correct
3. Check that formatting is neat
4. If needed, look at `practice.cpp` in the `Final/` folder

Your output should look like:
```
Shopping Cart Calculator
======================

Purchase Details:
----------------
Item Price: $29.99
Quantity: 3
...
```

## Common Problems and Solutions

### 1. Integer Division
```cpp
// Wrong: When both numbers are integers, C++ performs integer division
int result = 5 / 2;        // Gets 2 (decimal part is truncated)
int percent = 150 / 100;   // Gets 1 instead of 1.5

// Right: Make at least one number a decimal for floating-point division
double result1 = 5.0 / 2;    // Gets 2.5
double result2 = 5 / 2.0;    // Also gets 2.5
double result3 = 5.0 / 2.0;  // Most explicit way, gets 2.5

// Alternative: Cast to double
double result4 = static_cast<double>(5) / 2;  // Gets 2.5
```

### 2. Type Mismatch
```cpp
// Common type mismatch errors:
int number = 3.14;     // Wrong! Silently truncates to 3
char grade = "A";      // Wrong! "A" is a string (two bytes), 'A' is a char (one byte)
int bigNum = 3000000000; // Wrong! Too big for int, causes overflow

// Correct versions:
double number = 3.14;    // Keeps decimal precision
char grade = 'A';        // Single quotes for single character
long bigNum = 3000000000L; // Use long for very large numbers
```

### 3. Overflow
```cpp
// Overflow in different types:
short small = 32767;     // Maximum value for short
small = small + 1;       // Overflows to -32768!

unsigned int pos = 0;
pos = pos - 1;          // Overflows to 4294967295!

// Prevention strategies:
// 1. Use larger types when needed
long large = 32767 + 1;  // Works fine

// 2. Check before arithmetic
if (small < 32767) {
    small = small + 1;   // Only increment if safe
}

// 3. Use proper unsigned types for non-negative values
unsigned int count = 0;  // Can't go negative
```

## Best Practices
1. Choose appropriate types:
   ```cpp
   int count = 5;         // For counting
   double price = 19.99;  // For money
   char grade = 'A';      // For single characters
   bool isValid = true;   // For yes/no values
   ```

2. Initialize variables when declared:
   ```cpp
   int age = 0;    // Good
   int age;        // Less good
   ```

3. Use constants for fixed values:
   ```cpp
   const double PI = 3.14159;
   const int MAX_STUDENTS = 30;
   ```

## Next Steps
1. Complete both starter programs
2. Compare with the final versions in the `Final/` folder
3. Try modifying the values
4. Move on to [Part 3: Input/Output]({{ site.baseurl }}/tutorials/module1/part3-input-output)

## Additional Resources
- [C++ Data Types Reference]({{ site.baseurl }}/docs/reference/data-types)
- [Variable Naming Guidelines]({{ site.baseurl }}/docs/guides/naming)
- [Type Conversion Guide]({{ site.baseurl }}/docs/guides/type-conversion)

Remember: Take your time to understand these concepts - they're fundamental to everything else in C++!
