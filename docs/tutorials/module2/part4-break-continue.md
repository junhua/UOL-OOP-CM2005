---
layout: default
title: Part 4 - Break and Continue Statements
nav_order: 4
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part4-break-continue/
---

# Part 4: Break and Continue Statements

## Learning Objectives
- Master the usage of break and continue statements
- Understand when to use each control statement
- Learn proper loop control patterns
- Implement robust error handling
- Practice nested loop control

## Introduction
Loop control statements enhance your ability to manage program flow within loops. The `break` and `continue` statements provide precise control over loop execution, allowing you to exit loops early or skip specific iterations. Understanding these statements is crucial for writing efficient and maintainable code. This part explores several key concepts:

1. **Break Statement Usage**:
   - Early loop termination
   - Switch statement control
   - Search operations
   - Error handling
   - Resource cleanup

2. **Continue Statement Applications**:
   - Input validation
   - Data filtering
   - Iteration control
   - Performance optimization
   - Code organization

3. **Control Flow Patterns**:
   - Nested loop control
   - Error recovery
   - State management
   - Buffer handling
   - User feedback

Understanding these concepts will help you write more efficient and cleaner code by properly controlling program flow and handling special cases effectively. Through practical examples, you'll learn how to use these statements to create robust and maintainable programs.

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part4/break_continue_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part4/break_continue.cpp`.

### Step 1: Start with the Template
1. Open the starter code file `Tutorials/Module02/Part4/practice_break_continue_starter.cpp`
2. You'll see the following template:

```cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    // TODO: Declare validation constants
    // TODO: Implement input collection loop
    // TODO: Add validation checks with continue
    // TODO: Add termination check with break
    // TODO: Process and display results
    
    return 0;
}
```

### Step 2: Add Constants and Variables
First, let's set up our program's configuration:

```cpp
    const int MAX_ENTRIES = 5;
    const int MIN_LENGTH = 3;
    const string SENTINEL = "quit";
    
    string validEntries[MAX_ENTRIES];
    int entryCount = 0;
```

### Step 3: Display Instructions
Add clear user instructions:

```cpp
    cout << "Enter up to " << MAX_ENTRIES << " text entries" << endl;
    cout << "Rules:" << endl;
    cout << "- Minimum " << MIN_LENGTH << " characters" << endl;
    cout << "- No spaces allowed" << endl;
    cout << "- Enter '" << SENTINEL << "' to stop" << endl;
```

### Step 4: Implement Main Loop
Create the main input processing loop:

```cpp
    while (entryCount < MAX_ENTRIES) {
        string input;
        cout << "\nEntry " << (entryCount + 1) << ": ";
        cin >> input;
        
        // Process input here
    }
```

### Step 5: Add Break Condition
Implement the sentinel check using break:

```cpp
        // Check for sentinel
        if (input == SENTINEL) {
            cout << "Input terminated by user" << endl;
            break;  // Exit loop when sentinel is entered
        }
```

### Step 6: Add Continue Conditions
Implement validation using continue:

```cpp
        // Validate length
        if (input.length() < MIN_LENGTH) {
            cout << "Too short! Must be at least " << MIN_LENGTH << " characters" << endl;
            continue;  // Skip to next iteration
        }
        
        // Check for spaces
        if (input.find(' ') != string::npos) {
            cout << "Spaces not allowed!" << endl;
            continue;  // Skip to next iteration
        }
```

### Step 7: Store Valid Data
Add code to store and confirm valid entries:

```cpp
        // Store valid entry
        validEntries[entryCount++] = input;
        cout << "Entry accepted" << endl;
```

### Step 8: Display Results
Add the final results display:

```cpp
    // Display results
    cout << "\nValid entries collected: " << entryCount << endl;
    for (int i = 0; i < entryCount; i++) {
        cout << (i + 1) << ": " << validEntries[i] << endl;
    }
```

### Final Code
Here's the complete implementation:

```cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    const int MAX_ENTRIES = 5;
    const int MIN_LENGTH = 3;
    const string SENTINEL = "quit";
    
    string validEntries[MAX_ENTRIES];
    int entryCount = 0;
    
    cout << "Enter up to " << MAX_ENTRIES << " text entries" << endl;
    cout << "Rules:" << endl;
    cout << "- Minimum " << MIN_LENGTH << " characters" << endl;
    cout << "- No spaces allowed" << endl;
    cout << "- Enter '" << SENTINEL << "' to stop" << endl;
    
    while (entryCount < MAX_ENTRIES) {
        string input;
        cout << "\nEntry " << (entryCount + 1) << ": ";
        cin >> input;
        
        // Check for sentinel
        if (input == SENTINEL) {
            cout << "Input terminated by user" << endl;
            break;
        }
        
        // Validate length
        if (input.length() < MIN_LENGTH) {
            cout << "Too short! Must be at least " << MIN_LENGTH << " characters" << endl;
            continue;
        }
        
        // Check for spaces
        if (input.find(' ') != string::npos) {
            cout << "Spaces not allowed!" << endl;
            continue;
        }
        
        // Store valid entry
        validEntries[entryCount++] = input;
        cout << "Entry accepted" << endl;
    }
    
    // Display results
    cout << "\nValid entries collected: " << entryCount << endl;
    for (int i = 0; i < entryCount; i++) {
        cout << (i + 1) << ": " << validEntries[i] << endl;
    }
    
    return 0;
}
```

### Test Cases

1. Normal Input:
```
Input: hello world test quit
Expected Output:
Entry 1: hello (accepted)
Entry 2: world (accepted)
Entry 3: test (accepted)
Entry 4: quit (program ends)
Valid entries: 3
```

2. Validation Failures:
```
Input: hi no hello quit
Expected Output:
Entry 1: hi (too short)
Entry 2: no (too short)
Entry 3: hello (accepted)
Entry 4: quit (program ends)
Valid entries: 1
```

3. Maximum Entries:
```
Input: test1 test2 test3 test4 test5 test6
Expected Output:
Accepts first 5 entries
Stops after MAX_ENTRIES reached
Valid entries: 5
```

## Practice Exercises

Start with the starter code in `Tutorials/Module02/Part4/practice_break_continue_starter.cpp`.

### Exercise 1: Number Processor
Create a program that:
1. Processes numbers until a sentinel value
2. Uses continue to skip invalid numbers
3. Uses break when sum exceeds limit
4. Validates input properly
5. Displays running statistics

### Exercise 2: Pattern Generator
Implement a system that:
1. Uses nested loops with break/continue
2. Creates various patterns
3. Handles user input
4. Validates pattern size
5. Provides clear output

### Exercise 3: Data Filter
Build a program that:
1. Filters input based on criteria
2. Uses continue for invalid data
3. Uses break for completion
4. Maintains statistics
5. Shows filtered results

You can compare your solutions with the completed examples in `Tutorials/Module02/Part4/practice_break_continue.cpp`.

## Best Practices
1. Use break for:
   - Early loop termination
   - Sentinel values
   - Error conditions
   - Search completion
   - Resource cleanup

2. Use continue for:
   - Input validation
   - Data filtering
   - Skipping iterations
   - Error recovery
   - Performance optimization

3. Code Organization:
   - Clear conditions
   - Proper comments
   - Consistent style
   - Error handling
   - Buffer management

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases
4. Review error handling
5. Move on to [Part 5: Simple Program Examples]({{ site.baseurl }}/tutorials/module2/part5-examples)

Remember that while break and continue are powerful tools, they should be used judiciously. Clear code structure and proper documentation are essential when using these control flow statements.
