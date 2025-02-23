---
layout: default
title: Part 1 - Conditional Statements
nav_order: 1
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part1-conditionals/
---

# Part 1: Conditional Statements

## Learning Objectives
- Understand the purpose and syntax of conditional statements
- Learn different types of conditional structures
- Master condition evaluation and boolean logic
- Practice implementing decision-making in programs
- Learn best practices for conditional statements
- Implement robust input validation
- Handle error conditions gracefully

## Introduction
Conditional statements are fundamental building blocks that enable programs to make decisions and execute different code paths based on specific conditions. This part explores several key concepts:

1. **Basic Conditionals**:
   - If statements for simple decisions
   - Boolean expressions and conditions
   - Code block execution
   - Condition evaluation rules
   - Input validation techniques

2. **Complex Conditions**:
   - Multiple conditions with else-if
   - Nested conditional statements
   - Combining conditions with logical operators
   - Short-circuit evaluation
   - Error handling patterns

3. **Best Practices**:
   - Clear condition writing
   - Proper block organization
   - Error prevention
   - Code readability
   - Input validation
   - Buffer management

Understanding these concepts is essential for writing robust programs that can handle various inputs and make appropriate decisions. Through practical examples, you'll learn how to implement reliable decision-making logic with proper error handling.

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part1/conditionals_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part1/conditionals.cpp`.

### Step 1: Start with Input Validation
First, let's create a robust input handling system:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int age;
    char hasLicense;
    bool validInput = false;
    
    // Get age with validation
    do {
        cout << "Enter your age: ";
        if (cin >> age && age >= 0 && age <= 120) {
            validInput = true;
        } else {
            cout << "Invalid age. Please enter a number between 0 and 120." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Clear input buffer before character input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Get license status with validation
    validInput = false;
    do {
        cout << "Do you have a license? (y/n): ";
        if (cin >> hasLicense && (hasLicense == 'y' || hasLicense == 'n' || 
            hasLicense == 'Y' || hasLicense == 'N')) {
            validInput = true;
            hasLicense = tolower(hasLicense);  // Normalize input
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
```

### Step 2: Implement Basic Decision Structure
Create a clear and organized decision structure:

```cpp
    // Age categories
    const int ADULT_AGE = 18;
    const int TEEN_AGE = 16;
    
    // Determine person's category
    string category;
    if (age >= ADULT_AGE) {
        category = "Adult";
    } else if (age >= TEEN_AGE) {
        category = "Teen";
    } else {
        category = "Child";
    }
```

### Step 3: Add Complex Condition Handling
Implement nested conditions with clear organization:

```cpp
    // Determine driving privileges
    string privileges;
    if (age >= ADULT_AGE) {
        if (hasLicense == 'y') {
            privileges = "Full driving privileges";
        } else {
            privileges = "Eligible for license, but currently no driving privileges";
        }
    } else if (age >= TEEN_AGE) {
        if (hasLicense == 'y') {
            privileges = "Restricted driving privileges (with supervision)";
        } else {
            privileges = "Eligible for learner's permit";
        }
    } else {
        privileges = "No driving privileges";
    }
```

### Step 4: Implement Status Display
Create a well-formatted output system:

```cpp
    // Display results with clear formatting
    cout << "\n=== Status Report ===" << endl;
    cout << "Age Category: " << category << endl;
    cout << "License Status: " << (hasLicense == 'y' ? "Yes" : "No") << endl;
    cout << "Privileges: " << privileges << endl;
    
    // Additional warnings or recommendations
    if (age >= TEEN_AGE && hasLicense != 'y') {
        cout << "\nRecommendation: Consider applying for a driver's license." << endl;
    }
```

### Final Code
Here's the complete implementation with all features:

```cpp
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    // Constants
    const int ADULT_AGE = 18;
    const int TEEN_AGE = 16;
    const int MAX_AGE = 120;
    
    // Variables
    int age;
    char hasLicense;
    bool validInput = false;
    
    // Get age with validation
    do {
        cout << "Enter your age: ";
        if (cin >> age && age >= 0 && age <= MAX_AGE) {
            validInput = true;
        } else {
            cout << "Invalid age. Please enter a number between 0 and " 
                 << MAX_AGE << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Clear input buffer before character input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    // Get license status with validation
    validInput = false;
    do {
        cout << "Do you have a license? (y/n): ";
        if (cin >> hasLicense && (hasLicense == 'y' || hasLicense == 'n' || 
            hasLicense == 'Y' || hasLicense == 'N')) {
            validInput = true;
            hasLicense = tolower(hasLicense);  // Normalize input
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Determine person's category
    string category;
    if (age >= ADULT_AGE) {
        category = "Adult";
    } else if (age >= TEEN_AGE) {
        category = "Teen";
    } else {
        category = "Child";
    }
    
    // Determine driving privileges
    string privileges;
    if (age >= ADULT_AGE) {
        if (hasLicense == 'y') {
            privileges = "Full driving privileges";
        } else {
            privileges = "Eligible for license, but currently no driving privileges";
        }
    } else if (age >= TEEN_AGE) {
        if (hasLicense == 'y') {
            privileges = "Restricted driving privileges (with supervision)";
        } else {
            privileges = "Eligible for learner's permit";
        }
    } else {
        privileges = "No driving privileges";
    }
    
    // Display results
    cout << "\n=== Status Report ===" << endl;
    cout << "Age Category: " << category << endl;
    cout << "License Status: " << (hasLicense == 'y' ? "Yes" : "No") << endl;
    cout << "Privileges: " << privileges << endl;
    
    // Additional recommendations
    if (age >= TEEN_AGE && hasLicense != 'y') {
        cout << "\nRecommendation: Consider applying for a driver's license." << endl;
    }
    
    return 0;
}
```

### Test Cases
Here are comprehensive test cases to verify your implementation:

1. Valid Adult with License

```
Input:
Age: 25
License: y

Expected Output:
=== Status Report ===
Age Category: Adult
License Status: Yes
Privileges: Full driving privileges
```

2. Valid Adult without License

```
Input:
Age: 20
License: n

Expected Output:
=== Status Report ===
Age Category: Adult
License Status: No
Privileges: Eligible for license, but currently no driving privileges
Recommendation: Consider applying for a driver's license.
```

3. Teen with License

```
Input:
Age: 16
License: y

Expected Output:
=== Status Report ===
Age Category: Teen
License Status: Yes
Privileges: Restricted driving privileges (with supervision)
```

4. Teen without License

```
Input:
Age: 17
License: n

Expected Output:
=== Status Report ===
Age Category: Teen
License Status: No
Privileges: Eligible for learner's permit
Recommendation: Consider applying for a driver's license.
```

5. Child

```
Input:
Age: 12
License: n

Expected Output:
=== Status Report ===
Age Category: Child
License Status: No
Privileges: No driving privileges
```

6. Invalid Age Input Recovery

```
Input:
Age: abc
Output: Invalid age. Please enter a number between 0 and 120.
Age: -5
Output: Invalid age. Please enter a number between 0 and 120.
Age: 15

Expected: Program continues with valid input
```

7. Invalid License Input Recovery

```
Input:
Age: 18
License: m
Output: Invalid input. Please enter 'y' or 'n'.
License: Y

Expected: Program accepts uppercase input and continues
```

8. Boundary Testing

```
Input:
Age: 16 (TEEN_AGE)
Age: 18 (ADULT_AGE)
Age: 0 (Minimum)
Age: 120 (Maximum)

Expected: Correct category and privilege assignment for each boundary
```

## Understanding Conditional Logic

### Basic If Statement

```cpp
if (condition) {
    // Execute if condition is true
}
```

### If-Else Structure

```cpp
if (condition) {
    // Execute if condition is true
} else {
    // Execute if condition is false
}
```

### Multiple Conditions

```cpp
if (condition1) {
    // First case
} else if (condition2) {
    // Second case
} else {
    // Default case
}
```

### Input Validation Pattern

```cpp
do {
    cout << "Enter value: ";
    if (cin >> value && value >= min && value <= max) {
        validInput = true;
    } else {
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
} while (!validInput);
```

## Practice Exercises

### Step 1: Open the Starter Code
1. Open the starter code file `Tutorials/Module02/Part1/practice_conditionals_starter.cpp`
2. You'll see the following template:

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    // TODO: Declare variables for input
    // TODO: Implement input validation
    // TODO: Add conditional logic
    // TODO: Display results
    // TODO: Handle additional cases
    
    return 0;
}
```

### Exercise 1: Grade Calculator
Create a program that:
1. Takes a numeric grade (0-100)
2. Handles invalid input gracefully
3. Calculates letter grade with plus/minus
4. Provides appropriate feedback
5. Allows multiple calculations

### Exercise 2: Insurance Eligibility
Implement a program that:
1. Checks multiple eligibility criteria
2. Uses nested conditions effectively
3. Provides detailed feedback
4. Validates all inputs
5. Handles edge cases

### Exercise 3: Game Character Status
Create a system that:
1. Tracks multiple character attributes
2. Uses compound conditions
3. Implements status effects
4. Provides clear feedback
5. Handles invalid states

You can compare your solutions with the completed examples in `Tutorials/Module02/Part1/practice_conditionals.cpp`.

## Common Pitfalls
1. Missing input validation
2. Incorrect comparison operators
3. Complex nested conditions
4. Buffer handling issues
5. Missing edge cases
6. Unclear error messages

## Best Practices
1. Always validate input
2. Use clear condition names
3. Keep conditions simple
4. Handle all edge cases
5. Provide helpful feedback
6. Use constants for magic numbers
7. Implement proper error recovery
8. Format output clearly

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Handle edge cases properly
4. Review error handling
5. Move on to [Part 2: Switch Statements]({{ site.baseurl }}/tutorials/module2/part2-switch)

Remember that robust input handling and clear error messages are as important as the core logic in your programs. Always validate input and provide meaningful feedback to users.
