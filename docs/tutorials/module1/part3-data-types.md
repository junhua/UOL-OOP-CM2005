---
layout: default
title: Part 3 - Variables and Data Types
nav_order: 3
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part3-data-types
---

# Part 3: Variables and Data Types

## Learning Objectives
- Understand fundamental C++ data types
- Learn about variable declaration and initialization
- Understand type sizes and ranges
- Learn about type conversion and casting
- Practice using different data types

## Introduction
Data types are fundamental building blocks in C++ that determine how data is stored and manipulated. This part explores several key concepts:

1. **Fundamental Data Types**: 
   - Integers (int, short, long) for whole numbers
   - Floating-point (float, double) for decimal numbers
   - Characters (char) for single text characters
   - Booleans (bool) for true/false values

2. **Memory and Storage**:
   - How different types use memory
   - Size limitations and ranges
   - Type overflow considerations

3. **Type Conversion**:
   - Implicit conversion (automatic type casting)
   - Explicit conversion (manual type casting)
   - Potential data loss during conversion

4. **Variable Declaration and Initialization**:
   - Proper syntax for declaring variables
   - Initialization techniques
   - Best practices for variable usage

Understanding these concepts is essential as they affect program efficiency, memory usage, and data accuracy. Through practical examples, you'll learn how to choose appropriate data types for different scenarios and handle type conversions safely.

## Implementation Guide

### Step 1: Start with the Template
First, let's examine our starting point:
1. Open the starter code file `Tutorials/Module01/Part3/data_types_starter.cpp`
2. The template outlines what we'll implement:

```cpp
// TODO: Add necessary include directives

int main() {
    // TODO: Declare and initialize variables of different fundamental types
    // 1. Integer type
    // 2. Floating-point type
    // 3. Character type
    // 4. Boolean type

    // TODO: Print the values of all variables

    // TODO: Demonstrate type conversion
    // 1. Implicit conversion
    // 2. Explicit conversion (casting)

    // TODO: Show the sizes of different data types

    return 0;
}
```

### Step 2: Add Include Directives
We need two important headers for our program:
1. iostream for input/output operations
2. limits for working with type ranges
3. Add these lines at the top:

```cpp
#include <iostream>
#include <limits>
```

### Step 3: Declare Fundamental Types
Let's create variables of different types to demonstrate their use:
1. Create an integer for whole numbers
2. Use double for decimal numbers
3. Add a character for single letters
4. Include a boolean for true/false values

```cpp
    // Fundamental data types
    int age = 25;                    // Integer
    double price = 19.99;            // Double precision floating-point
    char grade = 'A';                // Character
    bool isStudent = true;           // Boolean
```

### Step 4: Print Variable Values
Now we'll display each variable to see how they're represented:
1. Use cout to print each value
2. Add descriptive labels
3. Use endl for line breaks

```cpp
    // Print values
    std::cout << "Integer (age): " << age << std::endl;
    std::cout << "Double (price): " << price << std::endl;
    std::cout << "Character (grade): " << grade << std::endl;
    std::cout << "Boolean (isStudent): " << isStudent << std::endl;
```

### Step 5: Demonstrate Type Conversion
Let's show how to convert between types:
1. Create a height in meters (double)
2. Convert it to centimeters (integer)
3. Show both implicit and explicit conversion

```cpp
    // Type conversion examples
    double height = 1.85;            // meters
    int heightCm = (int)(height * 100);  // Explicit conversion
    std::cout << "\nHeight conversion:" << std::endl;
    std::cout << "Height in meters: " << height << std::endl;
    std::cout << "Height in centimeters: " << heightCm << std::endl;
```

### Step 6: Show Type Sizes
Let's explore how much memory each type uses:
1. Use sizeof to get the size in bytes
2. Display sizes for all fundamental types
3. Add clear labels for each

```cpp
    // Size of different types
    std::cout << "\nSize of data types:" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
```

### Step 7: Display Type Ranges
Finally, let's show the range of values for integers:
1. Use numeric_limits to get minimum and maximum values
2. Display these ranges clearly
3. Help understand type limitations

```cpp
    // Range of integer type
    std::cout << "\nRange of integer type:" << std::endl;
    std::cout << "Minimum int value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum int value: " << std::numeric_limits<int>::max() << std::endl;
```

### Final Code
Here's how everything comes together in the complete program:

```cpp
#include <iostream>
#include <limits>

int main() {
    // Fundamental data types
    int age = 25;                    // Integer
    double price = 19.99;            // Double precision floating-point
    char grade = 'A';                // Character
    bool isStudent = true;           // Boolean

    // Print values
    std::cout << "Integer (age): " << age << std::endl;
    std::cout << "Double (price): " << price << std::endl;
    std::cout << "Character (grade): " << grade << std::endl;
    std::cout << "Boolean (isStudent): " << isStudent << std::endl;

    // Type conversion examples
    double height = 1.85;            // meters
    int heightCm = (int)(height * 100);  // Explicit conversion
    std::cout << "\nHeight conversion:" << std::endl;
    std::cout << "Height in meters: " << height << std::endl;
    std::cout << "Height in centimeters: " << heightCm << std::endl;

    // Size of different types
    std::cout << "\nSize of data types:" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    // Range of integer type
    std::cout << "\nRange of integer type:" << std::endl;
    std::cout << "Minimum int value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum int value: " << std::numeric_limits<int>::max() << std::endl;

    return 0;
}
```

### Test Cases
Here are some test cases to verify your implementation:

1. Basic Data Type Values

```
Code:
int age = 25;
double price = 19.99;
char grade = 'A';
bool isStudent = true;

Expected Output:
Integer (age): 25
Double (price): 19.99
Character (grade): A
Boolean (isStudent): 1
```

2. Type Conversion

```
Code:
double height = 1.85;
int heightCm = (int)(height * 100);

Expected Output:
Height in meters: 1.85
Height in centimeters: 185
```

3. Size of Types

```
Expected Output:
Size of int: 4 bytes
Size of double: 8 bytes
Size of char: 1 bytes
Size of bool: 1 bytes
```

4. Integer Range

```
Expected Output:
Minimum int value: -2147483648
Maximum int value: 2147483647
```

5. Floating Point Precision

```
Code:
float f = 3.14159f;
double d = 3.14159;

Expected Output:
float: 3.14159
double: 3.14159
```

6. Type Overflow Test

```
Code:
short s = 32767;  // Maximum short value
s = s + 1;        // Overflow

Expected Output:
-32768            // Wraps around to minimum value
```

7. Character Type Test

```
Code:
char c = 65;
std::cout << c << std::endl;

Expected Output:
A                 // ASCII value 65 is 'A'
```

Try these test cases to verify:
- Proper initialization of different types
- Type conversion behavior
- Size and range limitations
- Overflow handling
- Type representation

## Understanding Data Types

### Integer Types
- `short`: Small whole numbers (-32,768 to 32,767)
- `int`: Standard whole numbers (typically ±2 billion)
- `long`: Large whole numbers
- `unsigned`: Non-negative versions of above types

### Floating Point Types
- `float`: Single precision (7 digits)
- `double`: Double precision (15 digits)
- `long double`: Extended precision

### Character Types
- `char`: Single character ('A', 'b', '1', etc.)
- `wchar_t`: Wide character (for Unicode)

### Boolean Type
- `bool`: true or false values

## Practice Exercises

Open the starter code file `Tutorials/Module01/Part3/practice_types_starter.cpp`. This file contains a template for exploring data types and their properties.

### 1. Type Ranges
Implement the following in the starter code:
1. Declare variables of different integer types (short, int, long)
2. Use numeric_limits to display their minimum and maximum values
3. Demonstrate overflow behavior by incrementing a maximum value
4. Compare float and double precision with large numbers

### 2. Type Conversion
Add to your implementation:
1. Show implicit conversions between different numeric types
2. Demonstrate explicit type casting using static_cast
3. Illustrate precision loss when converting between types
4. Include examples of numeric-to-character conversions

### 3. Size Exploration
Complete your implementation by adding:
1. Display sizes of all fundamental types using sizeof
2. Compare sizes of different integer types
3. Show memory usage patterns with arrays
4. Document the results with clear output formatting

You can compare your solution with the completed example in `Tutorials/Module01/Part3/practice_types.cpp`.

The final code demonstrates:
- Range limits of different types
- Type conversion effects
- Memory size characteristics
- Proper output formatting

## Common Pitfalls
- Integer overflow/underflow
- Precision loss in floating-point
- Implicit conversion issues
- Uninitialized variables
- Type mismatch in operations

## Best Practices
1. Choose appropriate types for data
2. Initialize variables at declaration
3. Use explicit casting for clarity
4. Check for potential overflow
5. Consider memory usage in type selection

## Next Steps
After completing this part:
1. Make sure your program compiles and runs
2. Try the practice exercises
3. Compare your solutions with the final version
4. Move on to Part 4 to learn about input/output operations

[Continue to Part 4: Input and Output Operations]({{ site.baseurl }}/tutorials/module1/part4-io)
