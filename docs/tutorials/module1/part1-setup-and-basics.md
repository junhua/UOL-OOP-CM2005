---
layout: default
title: Part 1 - Setup and Basics
nav_order: 1
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part1-setup-and-basics/
---

# Part 1: Setup and Basics

Welcome to your first step in learning C++ programming! This guide will help you set up your programming environment and write your first program. Don't worry if some terms are unfamiliar - we'll explain everything step by step.

## What is Programming?

Before we dive into C++, let's understand what programming is. Think of programming like giving instructions to bake a cake:
- You need the right tools (your development environment)
- You need ingredients (data and variables)
- You follow a recipe (your program code)
- You perform steps in order (program execution)
- You get a result (program output)

Programming is simply telling the computer what to do, step by step, using a language it understands.

## Setting Up Your Development Environment

Just like you need a kitchen to bake a cake, you need a development environment to write programs. Let's set up yours!

### Required Software

#### 1. C++ Compiler
Think of the compiler as a translator - it converts your C++ code (which humans can read) into machine code (which computers can understand).

Choose based on your operating system:
- **Windows**: Install MinGW or Visual Studio
  - MinGW is lighter and simpler for beginners
  - [Download MinGW](https://sourceforge.net/projects/mingw/)
  - Follow the installer's instructions
  
- **macOS**: Install Xcode Command Line Tools
  - Open Terminal
  - Type: `xcode-select --install`
  - Follow the prompts
  
- **Linux**: Install GCC
  - Open Terminal
  - Type: `sudo apt-get install g++` (Ubuntu/Debian)
  - Or: `sudo yum install gcc-c++` (Fedora/RHEL)

#### 2. Visual Studio Code (VS Code)
This is your text editor - like a high-tech notepad for writing code.
- Download from [code.visualstudio.com](https://code.visualstudio.com)
- Install the C/C++ extension:
  1. Open VS Code
  2. Click the Extensions icon (or press Ctrl+Shift+X)
  3. Search for "C/C++"
  4. Click Install

### Verifying Your Installation

Let's make sure everything is working:
1. Open a terminal (Command Prompt on Windows)
2. Type this command:
```bash
g++ --version
```
3. You should see version information, not an error

If you see an error, don't worry! Common solutions:
- Windows: Add MinGW to your PATH
- macOS: Reinstall Command Line Tools
- Linux: Make sure installation completed

## Your First C++ Program

Now comes the exciting part - writing your first program! We'll create the traditional "Hello, World!" program.

### Getting Started with the Starter Code

1. Open the starter file:
   - Navigate to `Tutorials/Module01/Part01/Starter/`
   - Open `hello_starter.cpp`

2. You'll see a program structure with TODOs:
```cpp
// TODO: Include necessary header for input/output

int main() {
    // TODO: Display "Hello, World!" message
    // ...
}
```

### Step-by-Step Implementation

1. First, include the input/output library:
```cpp
#include <iostream>
```
This gives us access to `cout` for displaying output.

2. Add the "Hello, World!" message:
```cpp
std::cout << "Hello, World!" << std::endl;
```
- `std::cout`: The output stream (like a channel for sending text)
- `<<`: Sends data to the output
- `std::endl`: Adds a new line

3. Add your name:
```cpp
std::cout << "My name is [Your Name]" << std::endl;
```
Replace [Your Name] with your actual name!

4. Add the welcome message:
```cpp
std::cout << "Welcome to C++ Programming!" << std::endl;
```

### Compiling and Running

1. Open terminal in VS Code (View → Terminal)
2. Navigate to your code directory
3. Compile the program:
```bash
g++ hello_starter.cpp -o hello
```
4. Run the program:
```bash
# On Windows:
hello.exe

# On macOS/Linux:
./hello
```

You should see:
```
Hello, World!
My name is [Your Name]
Welcome to C++ Programming!
```

### Understanding Your Code

Let's break down what each part does:

```cpp
#include <iostream>
```
- Like getting your tools ready before cooking
- Tells C++ we want to use input/output features

```cpp
int main() {
```
- Every C++ program needs a main function
- This is where your program starts
- Like "Step 1" of your recipe

```cpp
std::cout << "Hello, World!" << std::endl;
```
- `std::cout`: How we send text to the screen
- `<<`: Sends our text to the output
- `std::endl`: Adds a new line (like pressing Enter)

```cpp
return 0;
```
- Tells the computer our program finished successfully
- Like saying "The recipe is complete!"

## Practice Exercise

Now that you understand the basics, try the practice exercise:

1. Open `practice_starter.cpp` in the Starter folder
2. Follow the TODOs to create a formatted welcome message
3. Your output should look like:
```
******************
* Welcome to C++ *
******************

Created by: [Your Name]
Date: [Current Date]

Let's start programming!
--------------------
```

### Implementation Steps

1. Add the header:
```cpp
#include <iostream>
```

2. Create the top border:
```cpp
std::cout << "******************" << std::endl;
```

3. Add the welcome message:
```cpp
std::cout << "* Welcome to C++ *" << std::endl;
```

4. Continue following the TODOs, testing after each step

### Checking Your Solution

1. Compare your output with the example above
2. Make sure all borders line up
3. Check that spacing is correct
4. If needed, look at `practice.cpp` in the `Final/` folder

## Common Mistakes and Solutions

### 1. Forgotten Semicolon
```cpp
std::cout << "Hello, World!" << std::endl   // Missing ;
```
Solution: Add a semicolon at the end of the line

### 2. Missing Brackets
```cpp
int main() {
    std::cout << "Hello, World!" << std::endl;
// Missing }
```
Solution: Make sure each { has a matching }

### 3. Incorrect Case
```cpp
Int Main() {   // Wrong! C++ is case-sensitive
```
Solution: Use exactly `int main()`

## Next Steps

Once you've completed both programs:
1. Try modifying the messages
2. Experiment with different border patterns
3. Add more information about yourself
4. Move on to [Part 2: Variables and Types]({{ site.baseurl }}/tutorials/module1/part2)

## Additional Resources
- [Detailed Setup Guide]({{ site.baseurl }}/docs/setup/cpp-compiler)
- [VS Code C++ Guide]({{ site.baseurl }}/docs/setup/vscode-cpp)
- [Common Setup Issues]({{ site.baseurl }}/docs/troubleshooting/setup)

Remember: Every programmer started exactly where you are now. Take your time, practice, and don't hesitate to experiment!
