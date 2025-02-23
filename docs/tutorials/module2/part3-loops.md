---
layout: default
title: Part 3 - Loops
nav_order: 3
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part3-loops/
---

# Part 3: Loops

## Overview
Loops allow you to execute a block of code repeatedly. C++ provides three main types of loops: for, while, and do-while. Each type has its own use cases and advantages.

## For Loops

### Basic Syntax
```cpp
for (initialization; condition; update) {
    // code to repeat
}
```

### Components
1. Initialization: Executed once before the loop starts
2. Condition: Checked before each iteration
3. Update: Executed after each iteration

### Example
```cpp
// Count from 1 to 5
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}  // Output: 1 2 3 4 5
```

### Common Use Cases
- Iterating a known number of times
- Processing arrays or collections
- Counting up or down
- Fixed-step iterations

## While Loops

### Basic Syntax
```cpp
while (condition) {
    // code to repeat
}
```

### Characteristics
- Condition checked before each iteration
- May never execute if condition is initially false
- Used when number of iterations is unknown

### Example
```cpp
// Keep asking for input until user enters a positive number
int number;
cout << "Enter a positive number: ";
cin >> number;

while (number <= 0) {
    cout << "Invalid. Enter a positive number: ";
    cin >> number;
}
```

## Do-While Loops

### Basic Syntax
```cpp
do {
    // code to repeat
} while (condition);
```

### Characteristics
- Condition checked after each iteration
- Always executes at least once
- Good for input validation

### Example
```cpp
char response;
do {
    cout << "Do you want to continue? (y/n): ";
    cin >> response;
} while (response == 'y');
```

## Loop Selection Guide

### Use For Loop When:
- Number of iterations is known
- Iterating over a range
- Need a counter variable
- Processing array elements

### Use While Loop When:
- Number of iterations is unknown
- Condition depends on external factors
- Loop may never execute
- Processing until a condition is met

### Use Do-While Loop When:
- Code must execute at least once
- Validating user input
- Menu-driven programs
- Post-condition checking needed

## Practice Exercise

Create a number guessing game that:
1. Generates a random number between 1 and 100
2. Asks the user to guess the number
3. Tells if the guess is too high or too low
4. Keeps track of number of guesses
5. Continues until the correct number is guessed

Solution:
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Congratulations! You guessed it in " 
                 << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}
```

## Common Loop Patterns

### Counter Loop
```cpp
for (int i = 0; i < count; i++) {
    // Process item i
}
```

### Sentinel Loop
```cpp
int value;
while (cin >> value && value != -1) {
    // Process value until -1 is entered
}
```

### Input Validation
```cpp
do {
    cout << "Enter a positive number: ";
    cin >> number;
} while (number <= 0);
```

### Nested Loops
```cpp
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        cout << i << "," << j << " ";
    }
    cout << endl;
}
```

## Common Mistakes to Avoid
1. Infinite loops (forgetting to update loop variable)
2. Off-by-one errors in loop conditions
3. Modifying loop variables inside the loop
4. Using wrong loop type for the task
5. Complex loop conditions that are hard to understand

## Next Steps
- Try the practice exercise
- Experiment with different loop types
- Move on to [Part 4: Break and Continue]({{ site.baseurl }}/tutorials/module2/part4-break-continue)
