# Module 1 - Part 1: Setup and Basics

Welcome to your first C++ programming tutorial! This directory contains helper code that will guide you through your first steps in programming.

## Understanding the Files

### hello.cpp - Your First Program!
This is a simple "Hello, World!" program that shows:
- How every C++ program is structured
- How to include necessary tools (libraries)
- How to output text to the screen
- How to use comments to explain your code

Think of it as your first recipe in cooking - it's simple but teaches the basic ingredients and steps!

To run this program:
1. Open your terminal/command prompt
2. Navigate to this directory
3. Compile the program:
   ```bash
   g++ hello.cpp -o hello
   ```
4. Run the program:
   ```bash
   # On Windows:
   hello.exe
   
   # On macOS/Linux:
   ./hello
   ```

### practice_solution.cpp - Practice Exercise Solution
This program shows you how to:
- Print multiple lines of text
- Add blank lines for better readability
- Structure your code clearly
- Use comments to explain what your code does

It's like a slightly more complex recipe that builds on what you learned!

To run this program:
1. Compile it:
   ```bash
   g++ practice_solution.cpp -o practice
   ```
2. Run it:
   ```bash
   # On Windows:
   practice.exe
   
   # On macOS/Linux:
   ./practice
   ```

## Learning Objectives
After working with these programs, you should be able to:
- Set up your C++ development environment
- Write basic C++ programs
- Understand the basic structure of a C++ program
- Use comments to document your code
- Print text to the screen
- Compile and run your programs

## Common Issues and Solutions

### 1. Compiler Errors
If you see an error like:
```
'cout' was not declared in this scope
```
This means the program doesn't know about cout. To fix this:
1. Make sure you have this line at the top:
   ```cpp
   #include <iostream>
   ```
2. Make sure you use `std::cout` (not just `cout`)

### 2. Program Won't Run
If you get "command not found" or similar:
1. Check you're in the right directory:
   ```bash
   # List files to make sure you see hello.cpp
   dir      # on Windows
   ls       # on macOS/Linux
   ```
2. Make sure you compiled the program first
3. On Unix systems, remember the `./`:
   ```bash
   ./hello    # correct
   hello      # won't work
   ```

### 3. Text Doesn't Display Correctly
If your output looks wrong:
1. Check for missing quotes: `"Hello"`
2. Check for missing semicolons: `;`
3. Make sure you use `std::endl` or `\n` for new lines

## Practice Suggestions
1. Modify hello.cpp to:
   - Print your name
   - Add more lines of text
   - Try different messages
   
2. Create your own program that:
   - Prints a short story
   - Uses blank lines to separate paragraphs
   - Uses comments to explain each part

3. Try fixing these common mistakes:
   ```cpp
   // What's wrong with these?
   cout << "Hello";           // Missing std::
   std::cout << Hello;        // Missing quotes
   std::cout << "Hello"       // Missing semicolon
   ```

## Next Steps
1. Make sure you understand every line in hello.cpp
2. Try the practice exercise without looking at the solution
3. Experiment with different ways to format your output
4. When you're comfortable, move on to Part 2

## Getting Help
If you run into problems:
1. Check your spelling carefully
2. Make sure every line ends with a semicolon
3. Verify all opening quotes/brackets have matching closing ones
4. Read the error messages - they often tell you what's wrong
5. Ask for help - everyone was a beginner once!

Remember: Making mistakes is a normal part of learning to program. Don't get discouraged!
