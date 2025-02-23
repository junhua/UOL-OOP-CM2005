---
layout: default
title: Part 1 - Welcome to C++ and Object-Oriented Programming
nav_order: 1
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part1-welcome
---

# Part 1: Welcome to C++ and Object-Oriented Programming

## Overview
In this part, you'll set up your C++ development environment and write your first program. We'll use practical examples and exercises to help you understand the basics of C++ programming.

## Environment Setup

### 1. Install a C++ Compiler
To begin programming in C++, you'll need to install a compiler appropriate for your operating system:
- Windows: Install MinGW or Visual Studio Community Edition
- macOS: Install Xcode Command Line Tools
- Linux: Install g++ through your system's package manager

### 2. Setup IDE/Editor
1. Download and install Visual Studio Code from [code.visualstudio.com](https://code.visualstudio.com)
2. Install the C/C++ extension:
   - Open VS Code
   - Click the Extensions icon in the sidebar (or press Ctrl+Shift+X)
   - Search for "C/C++"
   - Install the Microsoft C/C++ extension

### 3. Verify Setup
Open your terminal or command prompt and run:

```bash
g++ --version  # Check compiler
code --version # Check VS Code
```

## Your First C++ Program

### Step 1: Create Your First File
1. Open the starter code file `Tutorials/Module01/Part1/hello_starter.cpp`
2. You'll see the following template:

```cpp
// TODO: Add necessary include
// TODO: Add main function
// TODO: Print "Hello, C++!"
// TODO: Return appropriate value
```

### Step 2: Add the Include Directive
1. Every C++ program that uses input/output needs the iostream header
2. Add this line at the top of your file:

```cpp
#include <iostream>
```

### Step 3: Add the Main Function
1. Every C++ program needs a main function - it's where execution begins
2. Add the main function declaration:

```cpp
int main() {
    
}
```
### Step 4: Add Output Statement
1. Use cout to print "Hello, C++!"
2. Add this line inside main:

```cpp
    std::cout << "Hello, C++!" << std::endl;
```

### Step 5: Add Return Statement
1. Since main returns an int, we need a return statement
2. Add this as the last line in main:

```cpp
    return 0;
```

### Final Code
Your completed program should look like this (you can compare with `Tutorials/Module01/Part1/hello.cpp`):

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!" << std::endl;
    return 0;
}
```

### Test Cases
Here are some test cases to verify your implementation:

1. Basic Output

```
Expected Output:
Hello, C++!
```

2. Return Value Check

```
Command to check return value:
echo $?

Expected Output:
0
```

3. Compilation Test

```
Command:
g++ hello.cpp -o hello

Expected Output:
(No output indicates successful compilation)
```

4. Missing Semicolon Test

```
Code:
std::cout << "Hello, C++!" << std::endl    // Missing semicolon

Expected Output:
Compilation error: expected ';' before 'return'
```

5. Incorrect Include Test

```
Code:
#include "iostream"    // Wrong syntax for system header

Expected Output:
Compilation error: iostream: No such file or directory
```

Try these test cases to ensure your program:
- Compiles successfully
- Outputs the correct message
- Returns proper value
- Handles common errors appropriately

### Understanding Each Component
1. `#include <iostream>`: 
   - Includes the input/output stream library
   - Needed for cout and endl

2. `int main()`: 
   - The program's entry point
   - Must return an integer value

3. `std::cout << "Hello, C++!"`:
   - std::cout is the standard output stream
   - << is the output operator
   - Text in quotes is the string to output

4. `<< std::endl`:
   - Adds a newline
   - Flushes the output buffer

5. `return 0`:
   - Returns success status to operating system
   - 0 indicates successful execution

## Building and Running

### Compile Your Program

```bash
g++ hello.cpp -o hello
```
This command:
- Invokes the C++ compiler (g++)
- Compiles hello.cpp
- Creates an executable named hello (-o hello)

### Run Your Program

```bash
./hello
```
You should see:

```
Hello, C++!
```

## Common Issues and Solutions

### 1. Missing Semicolons

```cpp
std::cout << "Hello" << std::endl   // Error: missing ;
```
Fix: Add semicolon at the end of statements:

```cpp
std::cout << "Hello" << std::endl;  // Correct
```

### 2. Incorrect Include

```cpp
#include "iostream"   // Wrong for system headers
```
Fix: Use angle brackets for system headers:

```cpp
#include <iostream>   // Correct
```

### 3. Mismatched Brackets

```cpp
int main() {
    std::cout << "Hello";
    // Missing closing brace
```
Fix: Ensure each { has a matching }:

```cpp
int main() {
    std::cout << "Hello";
}  // Correct
```

## Practice Exercises

### 1. Basic Output
Modify your program to:
1. Print your name on one line
2. Print your age on the next line
3. Print a greeting that uses both pieces of information

### 2. Error Recognition
Fix these common errors in the code:

```cpp
#include <iostream>

int main() {
    std::cout << "Line 1" << std::endl
    std::cout << "Line 2" << std::endl;
    return 0
}
```

### 3. Program Enhancement
Enhance your program to:
1. Add a welcome message
2. Include multiple lines of output
3. Use different types of text formatting

## Next Steps
After completing this part:
1. Make sure your program compiles and runs correctly
2. Try the practice exercises
3. Compare your solutions with the final version
4. Move on to Part 2 to learn about program structure

[Continue to Part 2: Basic C++ Program Structure]({{ site.baseurl }}/tutorials/module1/part2-program-structure)
