---
layout: default
title: Part 1 - Conditional Statements
nav_order: 1
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part1-conditionals/
---

# Part 1: Conditional Statements

## Overview
In this part, you'll learn about conditional statements in C++, which allow your programs to make decisions and execute different code based on specific conditions.

## If Statements
The most basic form of conditional statement is the `if` statement:

```cpp
if (condition) {
    // code to execute if condition is true
}
```

Example:
```cpp
int age = 18;
if (age >= 18) {
    cout << "You are an adult" << endl;
}
```

## If-Else Statements
You can use `else` to specify what happens when the condition is false:

```cpp
if (condition) {
    // code to execute if condition is true
} else {
    // code to execute if condition is false
}
```

Example:
```cpp
int score = 75;
if (score >= 60) {
    cout << "You passed!" << endl;
} else {
    cout << "You failed." << endl;
}
```

## If-Else If-Else Statements
For multiple conditions, use `else if`:

```cpp
if (condition1) {
    // code for condition1
} else if (condition2) {
    // code for condition2
} else {
    // code if no conditions are true
}
```

Example:
```cpp
int grade = 85;
if (grade >= 90) {
    cout << "A grade" << endl;
} else if (grade >= 80) {
    cout << "B grade" << endl;
} else if (grade >= 70) {
    cout << "C grade" << endl;
} else {
    cout << "Failed" << endl;
}
```

## Nested If Statements
You can place if statements inside other if statements:

```cpp
if (condition1) {
    if (condition2) {
        // code for both conditions true
    }
}
```

Example:
```cpp
bool hasLicense = true;
int age = 19;

if (age >= 18) {
    if (hasLicense) {
        cout << "You can drive" << endl;
    } else {
        cout << "You need a license" << endl;
    }
} else {
    cout << "Too young to drive" << endl;
}
```

## Practice Exercise

Create a program that:
1. Asks for a user's age
2. Asks if they have a driver's license (y/n)
3. Determines and outputs what vehicles they can operate:
   - Under 16: Can ride a bicycle
   - 16-17 with license: Can drive a car with supervision
   - 18+ with license: Can drive a car
   - Any age without license: Can only ride a bicycle

Solution:
```cpp
#include <iostream>
using namespace std;

int main() {
    int age;
    char hasLicense;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Do you have a license? (y/n): ";
    cin >> hasLicense;
    
    if (age >= 18) {
        if (hasLicense == 'y') {
            cout << "You can drive a car" << endl;
        } else {
            cout << "You can only ride a bicycle" << endl;
        }
    } else if (age >= 16) {
        if (hasLicense == 'y') {
            cout << "You can drive a car with supervision" << endl;
        } else {
            cout << "You can only ride a bicycle" << endl;
        }
    } else {
        cout << "You can only ride a bicycle" << endl;
    }
    
    return 0;
}
```

## Key Points
- Conditions must evaluate to a boolean value (true/false)
- Use comparison operators (==, !=, >, <, >=, <=) to create conditions
- Use logical operators (&&, ||, !) to combine conditions
- Always use curly braces {} to clearly define code blocks
- Be careful with condition order in if-else if chains

## Common Mistakes to Avoid
1. Using = instead of == for comparison
2. Forgetting curly braces
3. Testing floating-point numbers for exact equality
4. Complex nested if statements (consider switch statements instead)
5. Not considering all possible cases

## Next Steps
- Try the practice exercise
- Experiment with different conditions
- Move on to [Part 2: Switch Statements]({{ site.baseurl }}/tutorials/module2/part2-switch)
