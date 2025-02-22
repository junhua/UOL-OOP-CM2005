---
layout: default
title: Part 3 - Input/Output
nav_order: 3
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part3-input-output/
---

# Part 3: Input/Output

This section covers how to get input from users and display output in C++. You'll learn about the standard input/output streams and how to format your output for better presentation.

## Console Input/Output Basics

### Input with cin
```cpp
#include <iostream>

int age;
std::cout << "Enter your age: ";
std::cin >> age;
```

### Output with cout
```cpp
std::cout << "You are " << age << " years old." << std::endl;
```

## Formatting Output

### Using iomanip
```cpp
#include <iomanip>

double price = 19.99;
std::cout << std::fixed << std::setprecision(2);
std::cout << "Price: $" << price << std::endl;
```

## Working with Strings

### String Input/Output
```cpp
#include <string>

std::string name;
std::cout << "Enter your name: ";
std::getline(std::cin, name);
```

## Basic Error Handling

### Input Validation
```cpp
if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
```

## Practice Exercises

Try creating programs that:
1. Get user information and format it nicely
2. Handle different types of input
3. Validate user input
4. Format numerical output

## Next Steps
Move on to [Part 4: Operators]({{ site.baseurl }}/tutorials/module1/part4-operators) to learn about different types of operators in C++.
