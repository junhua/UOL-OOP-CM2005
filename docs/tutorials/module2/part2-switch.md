---
layout: default
title: Part 2 - Switch Statements
nav_order: 2
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part2-switch/
---

# Part 2: Switch Statements

## Overview
Switch statements provide an alternative to if-else chains when you need to compare a single value against multiple constants. They can make your code more readable and efficient when dealing with multiple discrete cases.

## Basic Syntax
```cpp
switch (expression) {
    case constant1:
        // code for case 1
        break;
    case constant2:
        // code for case 2
        break;
    default:
        // code for all other cases
        break;
}
```

## Key Components

### 1. Switch Expression
- Must evaluate to an integral type (int, char, enum)
- Cannot use floating-point numbers or strings
- Cannot use conditions (only exact matches)

### 2. Case Labels
- Must be compile-time constants
- Must be unique within the switch
- Can have multiple cases execute the same code

### 3. Break Statement
- Exits the switch statement
- Without break, execution "falls through" to next case
- Forgetting break is a common source of bugs

### 4. Default Case
- Optional but recommended
- Handles all cases not explicitly listed
- Usually placed last (though can be anywhere)

## Example: Basic Switch
```cpp
int dayNumber = 3;
switch (dayNumber) {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cout << "Invalid day number" << endl;
        break;
}
```

## Fall-Through Behavior
Sometimes you want multiple cases to execute the same code:

```cpp
char grade = 'B';
switch (grade) {
    case 'A':
    case 'B':
        cout << "Good job!" << endl;
        break;
    case 'C':
        cout << "You passed" << endl;
        break;
    case 'D':
    case 'F':
        cout << "You need to study more" << endl;
        break;
    default:
        cout << "Invalid grade" << endl;
        break;
}
```

## Practice Exercise

Create a simple calculator that:
1. Asks for two numbers
2. Asks for an operation (+, -, *, /)
3. Performs the calculation using a switch statement
4. Handles division by zero
5. Handles invalid operators

Solution:
```cpp
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Invalid operator" << endl;
            break;
    }
    
    return 0;
}
```

## When to Use Switch vs If-Else

Use Switch when:
- Comparing a single value against multiple constants
- You have many (3+) possible values to compare
- All comparisons are equality checks
- Values are integral types

Use If-Else when:
- Testing multiple different variables
- Using ranges or complex conditions
- Working with floating-point numbers
- Need less than 3 comparisons
- Using non-integral types

## Common Mistakes to Avoid
1. Forgetting break statements
2. Using non-constant case labels
3. Trying to use conditions in case statements
4. Duplicate case labels
5. Forgetting the default case

## Next Steps
- Try the practice exercise
- Experiment with fall-through behavior
- Move on to [Part 3: Loops]({{ site.baseurl }}/tutorials/module2/part3-loops)
