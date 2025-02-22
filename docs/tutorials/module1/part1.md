---
layout: default
title: Part 1 - Setup and Basics
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

### Creating Your First File

1. Open VS Code
2. Create a new file named `hello.cpp`
   - The `.cpp` extension tells VS Code this is a C++ file
3. Type this code exactly as shown:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```

### Understanding Each Part

Let's break down this code line by line:

```cpp
#include <iostream>
```
- This is like importing tools we need
- `iostream` gives us input/output capabilities
- Think of it as getting your baking tools ready

```cpp
int main() {
```
- Every C++ program needs a `main` function
- This is where your program starts
- Like the "Step 1" of your recipe

```cpp
    std::cout << "Hello, World!" << std::endl;
```
- `std::cout` is how we print text to the screen
- `<<` sends our text to the output
- `std::endl` adds a new line (like pressing Enter)

```cpp
    return 0;
```
- Tells the computer our program finished successfully
- Like saying "The cake is done!"

### Compiling and Running

Now let's run your program:

1. Open terminal in VS Code (View → Terminal)
2. Type these commands:

```bash
# Compile your program
g++ hello.cpp -o hello

# Run your program
./hello  # On Unix-like systems (macOS/Linux)
hello.exe  # On Windows
```

You should see:
```
Hello, World!
```

Congratulations! You've written and run your first C++ program! 🎉

## Common Mistakes and Solutions

Don't worry if you get errors - they're normal when learning! Here are common ones:

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

## Practice Exercise

Let's try something on your own! Create a program that:
1. Prints "Welcome to C++"
2. Prints your name on the next line
3. Adds a blank line
4. Prints "Let's start programming!"

Try it yourself first, then check the [solution]({{ site.baseurl }}/tutorials/module1/part1/solution)

## Next Steps

Once you're comfortable with this:
1. Try modifying the "Hello, World!" program
2. Complete the practice exercise
3. Experiment with different messages
4. Move on to [Part 2: Variables and Types]({{ site.baseurl }}/tutorials/module1/part2)

## Additional Resources
- [Detailed Setup Guide]({{ site.baseurl }}/docs/setup/cpp-compiler)
- [VS Code C++ Guide]({{ site.baseurl }}/docs/setup/vscode-cpp)
- [Common Setup Issues]({{ site.baseurl }}/docs/troubleshooting/setup)

Remember: Every programmer started exactly where you are now. Take your time, practice, and don't hesitate to experiment!
