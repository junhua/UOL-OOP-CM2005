---
layout: default
title: Part 2 - Basic C++ Program Structure
nav_order: 2
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part2-program-structure
---

# Part 2: Basic C++ Program Structure

## Learning Objectives
- Understand the basic structure of a C++ program
- Learn about the preprocessor and include directives
- Understand the purpose of the main function
- Learn about statements and blocks
- Understand basic code organization

## Introduction
A C++ program follows a structured format that organizes code into logical components. This part covers several fundamental concepts:

1. **Preprocessor Directives**: We'll learn about #include statements that bring in external libraries and header files, allowing us to use additional functionality in our programs.

2. **The Main Function**: Every C++ program needs a main() function - it's where program execution begins. We'll understand why it's required and how it works.

3. **Code Blocks and Scope**: We'll explore how curly braces {} create blocks of code that define scope - determining where variables can be accessed and when they are destroyed.

4. **Variable Visibility**: You'll learn about variable scope levels, from function-level variables to block-scoped variables, and understand how nested blocks affect variable accessibility.

5. **Basic Program Organization**: We'll cover best practices for structuring your code, including proper placement of declarations, definitions, and statements.

Understanding these foundational concepts is crucial as they form the building blocks for writing well-organized and maintainable C++ programs. Through practical examples, you'll learn how these elements work together to create functional programs.

## Implementation Guide

### Step 1: Start with the Template
First, we'll examine the starter code that provides our basic structure:
1. Open the starter code file `Tutorials/Module01/Part2/program_structure_starter.cpp`
2. The template provides placeholders for the key components we'll implement:

```cpp
// TODO: Add necessary include directives

// TODO: Implement the main function that:
// 1. Declares variables at different scopes
// 2. Uses nested blocks to demonstrate scope
// 3. Outputs values to show variable visibility
// 4. Returns appropriate value
```

### Step 2: Add Include Directives
Now we'll add the necessary header for input/output operations:
1. The iostream header provides cout for output
2. Add this line at the top of your file:

```cpp
#include <iostream>
```

### Step 3: Implement the Main Function
Every C++ program needs a main function. Let's create the basic structure:
1. Add the main function declaration
2. This will serve as our program's entry point

```cpp
int main() {
    
}
```

### Step 4: Add Program-Level Variable
Let's demonstrate variable scope starting at the program level:
1. Declare a variable that will be accessible throughout main
2. Add output to show its value
3. This establishes our first scope level

```cpp
int main() {
    // Program-level variable
    int x = 5;
    std::cout << "Outside any block: x = " << x << std::endl;
}
```

### Step 5: Add First Nested Block
Now we'll create a new scope to show how variables can be nested:
1. Create a block using curly braces
2. Declare a new variable only visible in this block
3. Show how both variables are accessible here

```cpp
int main() {
    // Program-level variable
    int x = 5;
    std::cout << "Outside any block: x = " << x << std::endl;

    {
        // First nested block
        int y = 10;
        std::cout << "Inside first block: x = " << x << ", y = " << y << std::endl;
    } // y goes out of scope here
}
```

### Step 6: Add Second Nested Block
Let's demonstrate deeper nesting to show multiple scope levels:
1. Add another block inside the first one
2. Declare a third variable
3. Show how all variables are accessible in the innermost scope

```cpp
int main() {
    // Program-level variable
    int x = 5;
    std::cout << "Outside any block: x = " << x << std::endl;

    {
        // First nested block
        int y = 10;
        std::cout << "Inside first block: x = " << x << ", y = " << y << std::endl;
        
        {
            // Second nested block
            int z = 15;
            std::cout << "Inside second block: x = " << x << ", y = " << y 
                      << ", z = " << z << std::endl;
        } // z goes out of scope here
        
        std::cout << "Back to first block: x = " << x << ", y = " << y << std::endl;
    } // y goes out of scope here
}
```

### Step 7: Add Final Output and Return
Complete the program with:
1. One final output after all blocks to show what's still accessible
2. A return statement to indicate successful execution

```cpp
    std::cout << "Back to main scope: x = " << x << std::endl;
    return 0;
```

### Final Code
Here's how all the pieces fit together. Your completed program should look like this:

```cpp
#include <iostream>

int main() {
    // Program-level variable
    int x = 5;
    std::cout << "Outside any block: x = " << x << std::endl;

    {
        // First nested block
        int y = 10;
        std::cout << "Inside first block: x = " << x << ", y = " << y << std::endl;
        
        {
            // Second nested block
            int z = 15;
            std::cout << "Inside second block: x = " << x << ", y = " << y 
                      << ", z = " << z << std::endl;
        } // z goes out of scope here
        
        std::cout << "Back to first block: x = " << x << ", y = " << y << std::endl;
    } // y goes out of scope here

    std::cout << "Back to main scope: x = " << x << std::endl;
    
    return 0;
}
```

### Test Cases
Here are some test cases to verify your implementation:

1. Basic Scope Test

```
Expected Output:
Outside any block: x = 5
Inside first block: x = 5, y = 10
Inside second block: x = 5, y = 10, z = 15
Back to first block: x = 5, y = 10
Back to main scope: x = 5
```

2. Variable Shadowing Test

```
Code:
int main() {
    int x = 5;
    {
        int x = 10;  // Shadows outer x
        std::cout << "Inner x: " << x << std::endl;
    }
    std::cout << "Outer x: " << x << std::endl;
}

Expected Output:
Inner x: 10
Outer x: 5
```

3. Scope Error Test

```
Code:
int main() {
    {
        int y = 10;
    }
    std::cout << y << std::endl;  // Error: y is out of scope

Expected Output:
Compilation error: 'y' was not declared in this scope
```

4. Block Nesting Test

```
Code:
int main() {
    int x = 1;
    {
        int y = x + 1;
        {
            int z = y + 1;
            std::cout << x << y << z << std::endl;
        }
    }
}

Expected Output:
123
```

5. Variable Lifetime Test

```
Code:
int main() {
    for (int i = 0; i < 2; i++) {
        int temp = i;
        std::cout << temp << std::endl;
    }
    // temp is not accessible here
}

Expected Output:
0
1
```

Try these test cases to verify:
- Variable scope boundaries
- Proper variable lifetime
- Scope nesting behavior
- Variable shadowing effects
- Scope-related error handling

## Understanding Variable Scope

### Scope Rules
1. Variables are only accessible within their declaring block
2. Inner blocks can access variables from outer blocks
3. Variables are destroyed when their block ends
4. Each block creates a new scope level

### Scope Visualization
This diagram shows how variables exist at different scope levels:

```
main() {
    int x;        // Level 0 (main scope)
    {
        int y;    // Level 1 (can access x)
        {
            int z;// Level 2 (can access x and y)
        }         // z is destroyed
    }             // y is destroyed
}                 // x is destroyed
```

## Practice Exercises

Open the starter code file `Tutorials/Module01/Part2/practice_scope_starter.cpp`. This file contains a template for practicing scope and variable visibility concepts.

### 1. Basic Program Structure
Implement the following in the starter code:
1. Define a global constant (outside main)
2. Create variables at different scope levels
3. Demonstrate how each variable is accessible in its scope

### 2. Variable Visibility
Extend your implementation to show:
1. Variables with the same name in different scopes
2. Which version is visible where
3. Scope shadowing effects

### 3. Block Organization
Add to your implementation:
1. Additional nested blocks with their own variables
2. Different variable types at each scope level
3. More complex scope interactions

You can compare your solution with the completed example in `Tutorials/Module01/Part2/practice_scope.cpp`.

The final code demonstrates:
- Global constant accessibility
- Variable visibility at different scope levels
- Proper block organization
- Clear output showing where variables are accessible

## Common Pitfalls
- Using variables outside their scope
- Forgetting to initialize variables
- Shadowing variables unintentionally
- Missing closing braces
- Inconsistent indentation

## Best Practices
1. Initialize variables when declaring them
2. Use meaningful variable names
3. Keep scopes as small as possible
4. Use consistent indentation
5. Comment on scope boundaries in complex code

## Next Steps
After completing this part:
1. Make sure your program compiles and runs
2. Try the practice exercises
3. Compare your solutions with the final version
4. Move on to Part 3 to learn about data types

[Continue to Part 3: Variables and Data Types]({{ site.baseurl }}/tutorials/module1/part3-data-types)
