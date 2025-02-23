# Part 04: Input and Output (cin, cout)

## Learning Objectives
- Understand C++ input/output streams
- Learn to use cin and cout effectively
- Format output for readability
- Handle input validation
- Work with different data types in I/O operations

## Introduction
Input and output operations are like having a conversation with your program. Just as we use words to communicate, programs use streams to send and receive information. The `cout` stream is like speaking (output), while `cin` is like listening (input).

## Core Concepts

### 1. Basic Output with cout
```cpp
std::cout << "Hello, World!" << std::endl;
```

#### Key Features:
- Stream insertion operator (<<)
- Output formatting
- Ending lines (endl vs. \n)
- Chaining output

### 2. Basic Input with cin
```cpp
int age;
std::cout << "Enter your age: ";
std::cin >> age;
```

#### Key Features:
- Stream extraction operator (>>)
- Input buffering
- Type safety
- Error handling

### 3. Input/Output Formatting
```cpp
#include <iomanip>

double price = 19.99;
std::cout << std::fixed 
          << std::setprecision(2)
          << price << std::endl;
```

#### Common Manipulators:
- `std::fixed`: Fixed-point notation
- `std::scientific`: Scientific notation
- `std::setprecision`: Decimal precision
- `std::setw`: Field width
- `std::left/right`: Alignment
- `std::boolalpha`: Boolean text format

### 4. Input Validation
```cpp
while(true) {
    std::cout << "Enter a number: ";
    if(std::cin >> number) {
        break;  // Valid input
    }
    std::cout << "Invalid input. Try again.\n";
    std::cin.clear();  // Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
```

#### Key Concepts:
- Error checking
- Buffer clearing
- Input recovery
- Type mismatch handling

### 5. Working with Different Types
```cpp
// String input
std::string name;
std::cout << "Enter name: ";
std::getline(std::cin, name);  // Read entire line

// Character input
char choice;
std::cout << "Enter choice (Y/N): ";
std::cin >> choice;

// Numeric input
int quantity;
double price;
std::cout << "Enter quantity and price: ";
std::cin >> quantity >> price;
```

## Practice Exercises

### 1. Basic Input/Output
Create a program that:
- Asks for user's name
- Asks for user's age
- Displays a formatted greeting

### 2. Calculator Input
Create a program that:
- Reads two numbers
- Performs basic arithmetic
- Displays formatted results
- Handles invalid input

### 3. Formatted Output
Create a program that:
- Displays a table of values
- Uses proper alignment
- Sets decimal precision
- Uses different number formats

## Common Pitfalls
- Forgetting to clear input buffer
- Not handling invalid input
- Mixing cin >> and getline
- Incorrect format specifiers
- Buffer overflow issues

## Best Practices
- Always validate input
- Clear input buffer when needed
- Use appropriate data types
- Format output for readability
- Handle error cases
- Use meaningful prompts
- Provide user feedback

## Further Reading
- Stream manipulators
- File I/O operations
- Error handling techniques
- Advanced formatting
- Buffer management
