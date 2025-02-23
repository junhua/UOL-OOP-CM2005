# Part 02: Basic C++ Program Structure

## Learning Objectives
- Understand the basic structure of a C++ program
- Learn about the preprocessor and include directives
- Understand the purpose of the main function
- Learn about statements and blocks
- Understand basic code organization

## Introduction
A C++ program is like a recipe - it has specific ingredients (includes), a main procedure (main function), and step-by-step instructions (statements). Understanding this structure is fundamental to writing effective C++ programs.

## Core Concepts

### 1. Program Components
```cpp
// Include directives
#include <iostream>

// Main function
int main() {
    // Statements
    std::cout << "Hello" << std::endl;
    return 0;
}
```

#### Key Elements:
- Include directives (#include)
- Main function declaration
- Function body with statements
- Return statement

### 2. Preprocessor Directives
- Start with # symbol
- Processed before compilation
- Common directives:
  * #include: Include headers
  * #define: Define constants/macros
  * #ifndef/#endif: Header guards

### 3. The Main Function
- Entry point of the program
- Required in every C++ program
- Returns an integer (status code)
- Two common forms:
  ```cpp
  int main() { ... }
  int main(int argc, char* argv[]) { ... }
  ```

### 4. Statements and Blocks
- Statements end with semicolons
- Blocks enclosed in curly braces
- Nested blocks create scope
- Example:
  ```cpp
  int main() {
      // Block start
      int x = 5;
      {
          // Nested block
          int y = 10;
      } // y goes out of scope
      return 0;
  } // x goes out of scope
  ```

## Practice Exercises

### 1. Basic Program Structure
Create a program that:
- Includes necessary headers
- Has a main function
- Prints multiple lines
- Uses proper indentation

### 2. Understanding Scope
Create a program demonstrating:
- Variable declaration
- Block scope
- Nested blocks
- Scope visibility

## Common Pitfalls
- Missing semicolons
- Incorrect include syntax
- Mismatched braces
- Wrong return type for main
- Inconsistent indentation

## Best Practices
- Use consistent indentation
- Comment your code
- One statement per line
- Use meaningful names
- Keep functions focused

## Further Reading
- C++ preprocessor directives
- Scope and lifetime
- Program organization
- Coding standards
- Build process
