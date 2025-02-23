# Part 03: Variables and Data Types

## Learning Objectives
- Understand fundamental C++ data types
- Learn about variable declaration and initialization
- Understand type sizes and ranges
- Learn about type conversion and casting
- Practice using different data types

## Introduction
In C++, data types are like different kinds of containers, each designed to hold specific types of information. Just as you wouldn't store liquid in a paper bag or books in a water bottle, different types of data need appropriate types of variables to store them properly.

## Core Concepts

### 1. Fundamental Data Types
```cpp
int age = 25;              // Whole numbers
double price = 19.99;      // Decimal numbers
char grade = 'A';          // Single characters
bool isActive = true;      // True/false values
```

#### Common Types:
- **Integer Types**
  * `int`: General purpose integer (-2,147,483,648 to 2,147,483,647)
  * `short`: Small integers (-32,768 to 32,767)
  * `long`: Large integers
  * `unsigned`: Non-negative integers only

- **Floating Point Types**
  * `float`: Single precision (7 digits)
  * `double`: Double precision (15 digits)
  * `long double`: Extended precision

- **Character Types**
  * `char`: Single character
  * `wchar_t`: Wide character

- **Boolean Type**
  * `bool`: true or false

### 2. Variable Declaration and Initialization

```cpp
// Declaration only
int count;

// Declaration with initialization
int quantity = 100;

// Multiple declarations
int x = 0, y = 0, z = 0;

// Modern initialization syntax
int value{42};  // Uniform initialization
auto number = 42;  // Type inference
```

### 3. Type Sizes and Ranges

```cpp
#include <limits>
std::cout << "Int range: "
          << std::numeric_limits<int>::min() << " to "
          << std::numeric_limits<int>::max() << std::endl;
```

- Size varies by system
- Use `sizeof()` to check size
- Consider memory usage
- Choose appropriate types

### 4. Type Conversion

```cpp
// Implicit conversion
int x = 10;
double y = x;    // int to double (safe)

// Explicit conversion (casting)
double pi = 3.14159;
int wholePi = (int)pi;  // C-style cast
int modernPi = static_cast<int>(pi);  // Modern C++ cast
```

## Practice Exercises

### 1. Variable Declaration
Create variables of different types:
```cpp
// TODO: Declare variables for:
// - Age (whole number)
// - Price (decimal)
// - Initial (character)
// - Status (boolean)
```

### 2. Type Ranges
Write a program to display:
- Ranges of different numeric types
- Sizes of different types
- Overflow examples

### 3. Type Conversion
Practice different types of conversion:
- Implicit conversions
- Explicit casts
- Potential data loss scenarios

## Common Pitfalls
- Integer overflow
- Floating point precision
- Implicit conversion risks
- Uninitialized variables
- Type mismatch errors

## Best Practices
- Initialize variables
- Use appropriate types
- Be explicit about conversions
- Check for overflow
- Consider memory usage
- Use meaningful names

## Further Reading
- Type safety
- Platform dependencies
- Advanced data types
- Custom type aliases
- Type deduction rules
