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
int integer = 42;              // Regular box (e.g., counting people)
short smallNumber = 123;       // Small box (e.g., age)
long largeNumber = 123456789L; // Big box (e.g., population)
unsigned positiveOnly = 100;   // Box for positive numbers only
```

Each type is like a different size box:
- `int`: Regular box for most whole numbers
- `short`: Small box for small numbers
- `long`: Big box for very large numbers
- `unsigned`: Box that only holds positive numbers

### Adding Floating-Point Types

Add these after the next TODO:
```cpp
// Floating-point types (decimal numbers)
float decimal = 3.14159f;      // Regular measuring box
double precise = 3.14159265359;// Precise measuring box
```

Think of these like:
- `float`: Regular measuring cup
- `double`: Precise scientific instrument

### Character and Boolean Types

Add these next:
```cpp
// Character type
char letter = 'A';             // Single character box

// Boolean type
bool isTrue = true;            // Like a light switch
```

Note:
- Characters use single quotes ('A')
- Booleans can only be true or false

### Displaying Information

Uncomment the cout statements and add the size information:
```cpp
std::cout << "int: " << sizeof(int) 
          << " bytes (like a regular storage box)\n";
// Add similar lines for other types...
```

### Understanding Memory and Size

Add the number ranges section:
```cpp
std::cout << "int: " << std::numeric_limits<int>::min() 
          << " to " << std::numeric_limits<int>::max() << "\n";
```

## Practice Exercise: Shopping Cart Calculator

Now let's apply what we learned in a practical example!

1. Open `practice_starter.cpp` in the Starter folder

2. Add the necessary headers:
```cpp
#include <iostream>
#include <iomanip>    // For formatting numbers
```

3. Declare constants:
```cpp
const double TAX_RATE = 0.07;        // 7% sales tax
constexpr int MONTHS_IN_YEAR = 12;   // Always 12 months
```

4. Declare variables:
```cpp
double itemPrice = 29.99;            // Price with cents
int quantity = 3;                    // Whole number
float discountPercent = 10.5f;       // Percentage
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
// Wrong: Integer division drops decimals
int result = 5 / 2;  // Gets 2

// Right: Use decimal numbers
double result = 5.0 / 2.0;  // Gets 2.5
```

### 2. Type Mismatch
```cpp
int number = 3.14;     // Wrong! Loses decimal part
char grade = "A";      // Wrong! "A" is string, 'A' is char
```

### 3. Overflow
```cpp
short small = 32767;
small = small + 1;    // Oops! Goes beyond short's limit
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
2. Compare with the final versions
3. Try modifying the values
4. Move on to [Part 3: Input/Output]({{ site.baseurl }}/tutorials/module1/part3)

## Additional Resources
- [C++ Data Types Reference]({{ site.baseurl }}/docs/reference/data-types)
- [Variable Naming Guidelines]({{ site.baseurl }}/docs/guides/naming)
- [Type Conversion Guide]({{ site.baseurl }}/docs/guides/type-conversion)

Remember: Take your time to understand these concepts - they're fundamental to everything else in C++!
