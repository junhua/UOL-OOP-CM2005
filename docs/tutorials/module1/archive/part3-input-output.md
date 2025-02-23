---
layout: default
title: Part 3 - Input/Output
nav_order: 3
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part3-input-output/
---

# Part 3: Input/Output in C++

## Learning Objectives
By the end of this section, you will be able to:
- Use standard input/output streams in C++
- Handle different types of user input safely
- Format output for better presentation
- Implement basic error handling for input operations

## Understanding Input/Output in C++

Input/Output (I/O) operations are fundamental to any program that needs to interact with users or process data. In C++, these operations are handled through streams, which are sequences of bytes flowing between your program and input/output devices.

### Why Streams?
Streams provide a consistent way to handle input and output, regardless of where the data comes from or goes to. This abstraction means you can use the same code whether you're:
- Reading from the keyboard
- Writing to the screen
- Working with files
- Communicating over a network

## Standard I/O Streams

C++ provides four standard streams, each serving a specific purpose:

### 1. cout (Console Output)
- The standard output stream
- Usually connected to the terminal/console
- Used for normal program output
- Part of `std` namespace

### 2. cin (Console Input)
- The standard input stream
- Usually connected to the keyboard
- Used for user input
- Automatically converts input to the correct data type

### 3. cerr (Console Error)
- The standard error stream
- Used for error messages
- Output is not buffered (immediate display)
- Useful for debugging and error reporting

### 4. clog (Console Log)
- Used for logging messages
- Similar to cerr but buffered
- Useful for program status and debugging information

## Working with Output (cout)

The `cout` stream is your primary tool for displaying information to users. It's used with the insertion operator (`<<`), which can be chained for multiple outputs.

### Basic Output Examples

```cpp
#include <iostream>

int main() {
    // Simple string output
    std::cout << "Hello, World!" << std::endl;
    
    // Multiple values in one statement
    int age = 25;
    double height = 1.75;
    std::cout << "Age: " << age << " years, "
              << "Height: " << height << "m" << std::endl;
    
    // Using '\n' vs std::endl
    std::cout << "Line 1\n";     // Just adds newline
    std::cout << "Line 2" << std::endl;  // Adds newline and flushes buffer
}
```

### Understanding endl vs \n
- `std::endl`:
  * Adds a newline character
  * Flushes the output buffer
  * Slower but ensures immediate output
  * Use when you need to ensure output is displayed immediately

- `\n`:
  * Just adds a newline character
  * Doesn't flush the buffer
  * More efficient for multiple outputs
  * Use for general formatting when immediate display isn't critical

## Working with Input (cin)

The `cin` stream reads input from the user, automatically converting text to the appropriate data type. It uses the extraction operator (`>>`).

### Understanding How cin Works

```cpp
#include <iostream>
#include <string>

int main() {
    int number;
    std::string text;
    
    // Basic number input
    std::cout << "Enter a number: ";
    std::cin >> number;   // cin converts text to int
    
    // Multiple inputs
    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;   // Read two numbers in sequence
    
    // String input (single word)
    std::cout << "Enter a word: ";
    std::cin >> text;     // Stops at whitespace
}
```

### How cin Processes Input
1. Skips leading whitespace
2. Reads characters until it finds a delimiter (space, tab, newline)
3. Converts the characters to the requested data type
4. Leaves remaining characters in the input buffer

### Common cin Problems and Solutions

1. **Reading Past Whitespace**
   ```cpp
   std::string fullName;
   
   // Wrong way (stops at first space):
   std::cin >> fullName;
   
   // Right way (reads entire line):
   std::getline(std::cin, fullName);
   ```

2. **Mixing cin and getline**
   ```cpp
   int age;
   std::string name;
   
   // Problem: leftover newline from cin
   std::cin >> age;
   std::getline(std::cin, name);  // Reads empty line!
   
   // Solution: clear the buffer
   std::cin >> age;
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::getline(std::cin, name);
   ```

## Input Validation and Error Handling

Input validation is crucial for creating robust programs. Never trust user input without validation!

### Types of Input Validation

1. **Type Validation**: Ensure input matches expected data type
2. **Range Validation**: Check if value is within acceptable limits
3. **Format Validation**: Verify input follows required pattern
4. **Logical Validation**: Ensure input makes sense in context

### Comprehensive Input Validation Example

```cpp
#include <iostream>
#include <limits>

double getValidPrice() {
    double price;
    bool valid = false;
    
    do {
        std::cout << "Enter price ($0.01-$1000.00): $";
        
        // Check if input is a number
        if (std::cin >> price) {
            // Range validation
            if (price >= 0.01 && price <= 1000.00) {
                valid = true;
            } else {
                std::cout << "Price must be between $0.01 and $1000.00\n";
            }
        } else {
            // Input was not a number
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();  // Reset error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!valid);
    
    return price;
}
```

## Output Formatting

Professional-looking output can make your programs more user-friendly and readable. C++ provides various tools for formatting through the `<iomanip>` library.

### Key Formatting Tools

1. **Precision Control**
   ```cpp
   double pi = 3.14159265359;
   
   // Default precision
   std::cout << "Default: " << pi << std::endl;
   
   // Fixed decimal places
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Fixed (2): " << pi << std::endl;
   
   // Scientific notation
   std::cout << std::scientific;
   std::cout << "Scientific: " << pi << std::endl;
   ```

2. **Field Width and Alignment**
   ```cpp
   // Right alignment (default)
   std::cout << std::setw(10) << "Right" << "|" << std::endl;
   
   // Left alignment
   std::cout << std::left << std::setw(10) << "Left" << "|" << std::endl;
   
   // Custom fill character
   std::cout << std::setfill('.') << std::setw(10) << "Dots" << "|" << std::endl;
   ```

3. **Creating Professional Tables**
   ```cpp
   std::cout << std::left << std::setw(15) << "Product"
             << std::right << std::setw(10) << "Price"
             << std::right << std::setw(8) << "Qty" << std::endl;
   
   std::cout << std::setfill('-') << std::setw(33) << "" << std::endl;
   std::cout << std::setfill(' ');  // Reset fill character
   
   std::cout << std::left << std::setw(15) << "Apple"
             << std::right << std::setw(10) << "$0.99"
             << std::right << std::setw(8) << "5" << std::endl;
   ```

### Common Manipulators Reference

| Manipulator | Purpose | Example |
|------------|---------|---------|
| `fixed` | Fixed-point notation | `std::fixed` |
| `scientific` | Scientific notation | `std::scientific` |
| `setprecision(n)` | Set decimal places | `std::setprecision(2)` |
| `setw(n)` | Set field width | `std::setw(10)` |
| `left/right` | Set alignment | `std::left` |
| `setfill(c)` | Set fill character | `std::setfill('.')` |
| `showpoint` | Show decimal point | `std::showpoint` |
| `boolalpha` | Show true/false as words | `std::boolalpha` |

## Practice Exercises

1. **User Information Form**
   - Create a program that collects user information (name, age, height)
   - Validate each input appropriately:
     * Name: Allow spaces, no numbers
     * Age: Positive integer between 0-120
     * Height: Decimal between 0.5-2.5 meters
   - Display the information in a formatted table
   - Handle all possible input errors gracefully

2. **Calculator Input**
   - Write a program that reads two numbers and an operator (+, -, *, /)
   - Implement proper input validation:
     * Numbers: Any valid floating-point
     * Operator: Must be one of +, -, *, /
   - Handle division by zero
   - Format output to 2 decimal places
   - Allow continuous calculations until user chooses to exit

3. **Temperature Converter**
   - Create a program that converts between Celsius and Fahrenheit
   - Validate input temperatures:
     * Celsius: Above absolute zero (-273.15°C)
     * Fahrenheit: Above absolute zero (-459.67°F)
   - Format output to 1 decimal place
   - Display both scales side by side in a table
   - Allow multiple conversions in one session

4. **Shopping List**
   - Read items and prices from user input
   - For each item:
     * Name: Allow spaces, maximum 30 characters
     * Price: Positive number with 2 decimal places
     * Quantity: Positive integer
   - Format the output as a receipt with:
     * Aligned columns for items, prices, quantities
     * Subtotal for each item (price × quantity)
     * Total at bottom with proper currency formatting
   - Handle invalid inputs gracefully

## Common Mistakes to Avoid

1. **Not Clearing Input Buffer**
   ```cpp
   std::string name;
   int age;
   
   std::cin >> age;
   // Wrong: Buffer still contains newline
   std::getline(std::cin, name);
   
   // Correct: Clear buffer first
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   std::getline(std::cin, name);
   ```

2. **Not Handling Input Failures**
   ```cpp
   int number;
   // Wrong: No validation
   std::cin >> number;
   
   // Correct: Validate input
   if (!(std::cin >> number)) {
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       // Handle error
   }
   ```

3. **Assuming Input Will Be Valid**
   ```cpp
   // Wrong: Assumes valid input
   int age;
   std::cout << "Enter age: ";
   std::cin >> age;
   
   // Correct: Validate range and type
   int age;
   do {
       std::cout << "Enter age (0-120): ";
       if (std::cin >> age && age >= 0 && age <= 120) {
           break;
       }
       std::cout << "Invalid age!\n";
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   } while (true);
   ```

4. **Not Considering Buffer State**
   ```cpp
   // Wrong: Doesn't check buffer state
   std::string line;
   std::getline(std::cin, line);
   
   // Correct: Ensure buffer is ready
   if (std::cin.good()) {
       std::string line;
       std::getline(std::cin, line);
   }
   ```

## Next Steps
Move on to [Part 4: Operators]({{ site.baseurl }}/tutorials/module1/part4-operators) to learn about different types of operators in C++.
