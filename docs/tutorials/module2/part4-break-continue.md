---
layout: default
title: Part 4 - Break and Continue Statements
nav_order: 4
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part4-break-continue/
---

# Part 4: Break and Continue Statements

## Overview
Break and continue statements provide additional control over loop execution. They allow you to exit a loop early or skip to the next iteration based on certain conditions.

## Break Statement

### Purpose
- Immediately exits the current loop or switch statement
- Execution continues at the first statement after the loop/switch
- Can be used in for, while, do-while loops, and switch statements

### Basic Syntax
```cpp
while (condition) {
    if (exit_condition) {
        break;  // Exit loop immediately
    }
    // Loop code
}
```

### Example
```cpp
// Print numbers until we find a multiple of 7
for (int i = 1; i <= 20; i++) {
    cout << i << " ";
    if (i % 7 == 0) {
        cout << endl << "Found multiple of 7!";
        break;
    }
}
```

## Continue Statement

### Purpose
- Skips the rest of the current iteration
- Jumps to the next iteration of the loop
- Can only be used in loops (not in switch statements)

### Basic Syntax
```cpp
while (condition) {
    if (skip_condition) {
        continue;  // Skip to next iteration
    }
    // Loop code
}
```

### Example
```cpp
// Print only odd numbers from 1 to 10
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;  // Skip even numbers
    }
    cout << i << " ";
}
```

## When to Use Break vs Continue

### Use Break When:
- You need to exit a loop early
- You've found what you're looking for
- An error condition occurs
- You want to implement an exit condition

### Use Continue When:
- You want to skip specific iterations
- You need to avoid nested if statements
- You want to filter out certain cases
- Processing should continue with next item

## Practice Exercise

Create a program that:
1. Asks user for numbers until they enter 0
2. Skips negative numbers (using continue)
3. Exits if sum exceeds 100 (using break)
4. Prints the final sum and count of valid numbers

Solution:
```cpp
#include <iostream>
using namespace std;

int main() {
    int number;
    int sum = 0;
    int count = 0;
    
    cout << "Enter numbers (0 to stop):" << endl;
    
    while (true) {
        cout << "Enter a number: ";
        cin >> number;
        
        // Exit condition
        if (number == 0) {
            break;
        }
        
        // Skip negative numbers
        if (number < 0) {
            cout << "Negative number skipped" << endl;
            continue;
        }
        
        sum += number;
        count++;
        
        // Check if sum exceeds 100
        if (sum > 100) {
            cout << "Sum exceeded 100!" << endl;
            break;
        }
    }
    
    cout << "Final sum: " << sum << endl;
    cout << "Valid numbers entered: " << count << endl;
    
    return 0;
}
```

## Common Use Cases

### Early Exit Pattern
```cpp
while (true) {
    // Process data
    if (error_condition) {
        break;  // Exit on error
    }
}
```

### Filtering Pattern
```cpp
for (int i = 0; i < size; i++) {
    if (!isValid(data[i])) {
        continue;  // Skip invalid data
    }
    // Process valid data
}
```

### Search Pattern
```cpp
for (int i = 0; i < size; i++) {
    if (data[i] == target) {
        cout << "Found at position " << i << endl;
        break;  // Stop searching
    }
}
```

## Common Mistakes to Avoid
1. Using break/continue in nested loops (affects only innermost loop)
2. Creating infinite loops with continue
3. Using continue in do-while loops incorrectly
4. Making code hard to follow with too many breaks/continues
5. Forgetting to update loop variables before continue

## Best Practices
1. Use break/continue sparingly
2. Consider restructuring loops instead
3. Document break/continue conditions clearly
4. Be careful with nested loops
5. Consider using functions instead of complex loop logic

## Next Steps
- Try the practice exercise
- Experiment with break and continue
- Move on to [Part 5: Simple Program Examples]({{ site.baseurl }}/tutorials/module2/part5-examples)
