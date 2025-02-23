---
layout: default
title: Part 6 - Scope of Variables
nav_order: 6
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part6-scope/
---

# Part 6: Scope of Variables

## Overview
Variable scope determines where a variable can be accessed in a program. Understanding scope is crucial for writing maintainable code and avoiding naming conflicts.

## Types of Scope

### Local Scope
- Variables declared inside a function or block
- Only accessible within that function/block
- Created when entering block, destroyed when exiting
- Each function call creates new instances

```cpp
void function() {
    int localVar = 5;  // Local to function
    {
        int blockVar = 10;  // Local to this block
    }  // blockVar destroyed here
    // localVar still accessible
}  // localVar destroyed here
```

### Global Scope
- Variables declared outside all functions
- Accessible throughout the program
- Exist for entire program execution
- Should be used sparingly

```cpp
int globalVar = 100;  // Global variable

void function1() {
    cout << globalVar;  // Can access global
}

void function2() {
    globalVar = 200;   // Can modify global
}
```

### Function Parameter Scope
- Parameters are local to function
- Accessible only within function
- New copy/reference for each call
- Destroyed when function returns

```cpp
void function(int parameter) {  // parameter scope starts
    cout << parameter;  // Can use parameter
}  // parameter scope ends
```

## Variable Shadowing

When a local variable has the same name as a global variable:
- Local variable "shadows" global
- Global can be accessed with :: operator
- Generally best to avoid shadowing

```cpp
int value = 100;  // Global

void function() {
    int value = 50;  // Shadows global
    cout << value;     // Prints 50
    cout << ::value;   // Prints 100 (global)
}
```

## Static Variables

### Local Static Variables
- Declared with static keyword
- Retain value between function calls
- Initialized only once
- Local scope but global lifetime

```cpp
void counter() {
    static int count = 0;  // Initialized once
    count++;  // Persists between calls
    cout << count << endl;
}

int main() {
    counter();  // Prints 1
    counter();  // Prints 2
    counter();  // Prints 3
    return 0;
}
```

## Practice Exercise

Create a program that demonstrates different variable scopes:
1. Global variables
2. Local variables
3. Static variables
4. Parameter scope
5. Variable shadowing

Solution:
```cpp
#include <iostream>
using namespace std;

// Global variables
int globalCounter = 0;
string globalMessage = "Hello from global!";

// Function using static variable
void countCalls() {
    static int calls = 0;
    calls++;
    cout << "This function has been called " << calls << " times" << endl;
}

// Function demonstrating parameter and local scope
void processValue(int value) {  // Parameter scope
    int localValue = value * 2;  // Local scope
    globalCounter++;  // Accessing global
    
    cout << "Parameter value: " << value << endl;
    cout << "Local value: " << localValue << endl;
    cout << "Global counter: " << globalCounter << endl;
}

// Function demonstrating variable shadowing
void demonstrateShadowing() {
    string globalMessage = "Hello from local!";  // Shadows global
    
    cout << "Local message: " << globalMessage << endl;
    cout << "Global message: " << ::globalMessage << endl;
}

int main() {
    // Test static variable
    cout << "Testing static variable:" << endl;
    for (int i = 0; i < 3; i++) {
        countCalls();
    }
    
    // Test parameter and local scope
    cout << "\nTesting parameter and local scope:" << endl;
    processValue(5);
    processValue(10);
    
    // Test variable shadowing
    cout << "\nTesting variable shadowing:" << endl;
    demonstrateShadowing();
    
    // Demonstrate block scope
    cout << "\nTesting block scope:" << endl;
    {
        int blockVar = 100;
        cout << "Inside block: " << blockVar << endl;
    }
    // blockVar not accessible here
    
    return 0;
}
```

## Best Practices

### Variable Declaration
1. Declare variables in smallest scope needed
2. Initialize variables at declaration
3. Use meaningful names
4. Avoid global variables when possible

### Global Variables
1. Use only when truly needed
2. Consider making const
3. Document purpose clearly
4. Use naming conventions to identify globals

### Static Variables
1. Use for maintaining state
2. Initialize with constant values
3. Consider alternatives (class members)
4. Document lifetime behavior

## Common Mistakes to Avoid
1. Excessive use of global variables
2. Shadowing variables unintentionally
3. Assuming variable lifetime
4. Accessing out-of-scope variables
5. Confusing static and global scope

## Next Steps
- Try the practice exercise
- Experiment with different scopes
- Move on to [Part 7: Introduction to Recursion]({{ site.baseurl }}/tutorials/module3/part7-recursion)
