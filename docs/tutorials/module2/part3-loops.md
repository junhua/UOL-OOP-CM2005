---
layout: default
title: Part 3 - Loops
nav_order: 3
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part3-loops/
---

# Part 3: Loops

## Learning Objectives
- Master different types of loops (for, while, do-while)
- Understand loop selection criteria
- Implement robust input validation in loops
- Handle loop control and termination
- Track and maintain loop state
- Process loop results effectively
- Create professional user interfaces

## Introduction
Loops are fundamental control structures in C++ that enable you to execute a block of code repeatedly based on specific conditions. They are essential for automating repetitive tasks, processing collections of data, and implementing iterative algorithms. This part explores several key concepts:

1. **Loop Types and Usage**:
   - For loops for counted iteration
   - While loops for condition-based iteration
   - Do-while loops for post-condition checking
   - Nested loops for complex patterns
   - Loop selection criteria

2. **Input Validation and Error Handling**:
   - Buffer management
   - Input validation patterns
   - Error recovery strategies
   - User feedback
   - Retry mechanisms

3. **Loop Control and State**:
   - Loop variables
   - Termination conditions
   - State tracking
   - Progress monitoring
   - Result accumulation

Understanding these concepts is crucial for writing robust and maintainable code that can handle various input scenarios and provide clear feedback to users.

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part3/loops_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part3/loops.cpp`.

### Step 1: For Loop Implementation
Let's start with the most structured loop type:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    const int COUNT = 5;
    int sum = 0;
    
    cout << "Enter " << COUNT << " numbers to sum:" << endl;
    
    for (int i = 1; i <= COUNT; i++) {
        int number;
        bool validInput = false;
        
        do {
            cout << "Number " << i << ": ";
            if (cin >> number) {
                sum += number;
                validInput = true;
            } else {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validInput);
    }
    
    cout << "Sum: " << sum << endl;
    return 0;
}
```

Key points:
- Clear loop bounds
- Input validation
- Error handling
- Progress tracking
- Buffer management

### Step 2: While Loop Implementation
Demonstrate condition-based iteration:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int sum = 0;
    int number;
    bool validInput;
    
    cout << "Enter numbers to sum (0 to finish):" << endl;
    
    while (true) {
        do {
            cout << "Enter a number: ";
            validInput = (cin >> number);
            
            if (!validInput) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validInput);
        
        if (number == 0) {
            break;
        }
        
        sum += number;
        cout << "Current sum: " << sum << endl;
    }
    
    cout << "Final sum: " << sum << endl;
    return 0;
}
```

Key points:
- Sentinel value
- Running total
- Input validation
- Clear termination condition
- User feedback

### Step 3: Do-While Loop Implementation
Show post-condition checking:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int choice;
    bool validInput;
    
    do {
        // Display menu
        cout << "\nMenu Options:\n"
             << "1. View data\n"
             << "2. Add data\n"
             << "3. Delete data\n"
             << "4. Exit\n"
             << "Enter choice (1-4): ";
        
        // Get and validate input
        do {
            validInput = (cin >> choice) && (choice >= 1) && (choice <= 4);
            
            if (!validInput) {
                cout << "Invalid choice. Please enter 1-4: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validInput);
        
        // Process choice
        switch (choice) {
            case 1:
                cout << "Viewing data..." << endl;
                break;
            case 2:
                cout << "Adding data..." << endl;
                break;
            case 3:
                cout << "Deleting data..." << endl;
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}
```

Key points:
- Menu structure
- Input validation
- Clear exit condition
- User feedback
- Buffer management

### Step 4: Nested Loops Implementation
Demonstrate loop combinations:

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int ROWS = 5;
    const int COLS = 5;
    
    // Create multiplication table
    cout << "Multiplication Table:" << endl;
    
    // Print header row
    cout << setw(4) << " ";
    for (int i = 1; i <= COLS; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    
    // Print separator line
    cout << "    ";
    for (int i = 1; i <= COLS; i++) {
        cout << "----";
    }
    cout << endl;
    
    // Print table contents
    for (int i = 1; i <= ROWS; i++) {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= COLS; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
    
    return 0;
}
```

Key points:
- Loop coordination
- Output formatting
- Clear structure
- Progress tracking
- Visual organization

## Understanding Loop Types

### For Loop
- Best for known number of iterations
- Built-in counter management
- Clear initialization and update
- Scope-contained variables

### While Loop
- Ideal for condition-based iteration
- Unknown number of iterations
- Pre-condition testing
- Flexible termination

### Do-While Loop
- Guarantees at least one iteration
- Post-condition testing
- Perfect for input validation
- Menu-driven programs

### Nested Loops
- Complex pattern generation
- Multi-dimensional data processing
- Coordinated iteration
- Hierarchical processing

## Test Cases

### 1. For Loop Input Validation

```cpp
// Number Collection
Input: 1, 2, 3, 4, 5
Expected: All numbers accepted, sum calculated

Input: 1, abc, 3, -5, 2
Expected: 
- Error for 'abc' (retry prompt)
- Error for -5 (retry prompt)
- Only valid numbers included in sum
```

### 2. While Loop with Sentinel

```cpp
// Data Processing
Input: 10, 20, 30, 0 (sentinel)
Expected: Process all numbers until 0

Input: 10, -1, abc, 0
Expected:
- Process 10
- Error for 'abc' (retry)
- Continue until 0 entered
```

### 3. Do-While Menu System

```cpp
// Menu Navigation
Input: 1, 2, 3, 4 (exit)
Expected: Execute each option, then exit

Input: 5, a, -1, 4
Expected:
- Invalid option messages
- Retry prompts
- Continue until valid exit
```

### 4. Nested Loops

```cpp
// Pattern Generation
Input: Size 3
Expected Output:
1
1 2
1 2 3

Input: Size -1
Expected: Error and retry prompt
```

### 5. Buffer Management

```cpp
// String Processing
Input: "Hello", "World", "Quit"
Expected: Process each string

Input: "Hello World", "Quit"
Expected:
- Handle space in input
- Clear buffer properly
- Continue processing
```

### 6. Error Recovery

```cpp
// Number Processing
Input: 123456789012345
Expected: Buffer overflow handled

Input: abc123
Expected:
- Clear error state
- Clear buffer
- Retry prompt
```

## Practice Exercises

### Step 1: Open the Starter Code
1. Open the starter code file `Tutorials/Module02/Part3/practice_loops_starter.cpp`
2. You'll see the following template:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // TODO: Declare loop control variables
    // TODO: Implement input validation loop
    // TODO: Add processing loop
    // TODO: Track and display progress
    // TODO: Handle loop termination
    
    return 0;
}
```

### Exercise 1: Enhanced Number Processor
Create a program that:
1. Accepts a series of numbers
2. Validates each input
3. Calculates statistics (min, max, average)
4. Handles invalid input gracefully
5. Provides clear feedback
6. Allows multiple runs

### Exercise 2: Pattern Generator
Implement a system that:
1. Takes pattern size and type
2. Validates input ranges
3. Uses nested loops
4. Creates various patterns
5. Handles errors properly
6. Formats output professionally

### Exercise 3: Data Analyzer
Build a program that:
1. Reads data until sentinel
2. Validates all inputs
3. Processes data in batches
4. Maintains running statistics
5. Provides progress updates
6. Generates summary report

You can compare your solutions with the completed examples in:

```
Tutorials/Module02/Part3/practice_loops.cpp
```

## Common Pitfalls
1. Infinite loops
2. Buffer overflow
3. Missing input validation
4. Incorrect loop termination
5. Buffer management issues
6. State tracking errors
7. Progress monitoring gaps
8. Unclear user feedback

## Best Practices
1. Input Validation
   - Check all inputs
   - Handle invalid data
   - Provide retry options
   - Clear error states

2. Buffer Management
   - Clear input buffer
   - Handle overflow
   - Manage string input
   - Process line endings

3. State Tracking
   - Initialize variables
   - Update state correctly
   - Monitor progress
   - Maintain statistics

4. User Interface
   - Clear prompts
   - Error messages
   - Progress updates
   - Professional formatting

5. Code Organization
   - Logical structure
   - Clear comments
   - Consistent style
   - Error handling

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Part 4: Break and Continue]({{ site.baseurl }}/tutorials/module2/part4-break-continue)

Remember that robust input handling and clear user feedback are essential for creating reliable loop-based programs. Always validate input, manage buffers properly, and provide meaningful feedback to users.
