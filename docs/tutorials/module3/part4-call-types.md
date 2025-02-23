---
layout: default
title: Part 4 - Call by Value and Call by Reference
nav_order: 4
parent: Module 3 - Functions
grand_parent: Tutorials
permalink: /tutorials/module3/part4-call-types/
---

# Part 4: Call by Value and Call by Reference

## Overview
C++ provides two ways to pass arguments to functions: by value and by reference. Understanding the differences between these methods is crucial for writing efficient and effective code.

## Call by Value

### Characteristics
- Creates a copy of the argument
- Changes to parameter don't affect original
- Safe but can be inefficient for large objects
- Default parameter passing method

### Example
```cpp
void modifyValue(int num) {
    num = num * 2;  // Only modifies local copy
}

int main() {
    int x = 5;
    modifyValue(x);  // x is still 5
    return 0;
}
```

### When to Use
- For small data types (int, char, etc.)
- When you don't want to modify original
- When working with temporary values
- To ensure data safety

## Call by Reference

### Characteristics
- Passes memory address of argument
- Changes to parameter affect original
- More efficient (no copying)
- Can modify multiple values

### Example
```cpp
void modifyReference(int& num) {
    num = num * 2;  // Modifies original value
}

int main() {
    int x = 5;
    modifyReference(x);  // x is now 10
    return 0;
}
```

### When to Use
- For large objects (to avoid copying)
- When you need to modify original
- When returning multiple values
- For better performance

## Const References

### Purpose
- Efficient parameter passing
- Prevents modification
- Best of both worlds
- Common in modern C++

### Example
```cpp
void printValue(const int& num) {
    cout << num << endl;  // Can read but not modify
}

void processLargeObject(const string& data) {
    // Process data without copying
    cout << "Length: " << data.length() << endl;
}
```

## Practice Exercise

Create a program that demonstrates different parameter passing methods:
1. Function using call by value
2. Function using call by reference
3. Function using const reference

Solution:
```cpp
#include <iostream>
#include <string>
using namespace std;

// Call by value example
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: " << a << ", " << b << endl;
}

// Call by reference example
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: " << a << ", " << b << endl;
}

// Const reference example
void printDetails(const string& str) {
    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;
}

// Function that modifies multiple values by reference
void getNameStats(const string& name, int& letters, int& vowels) {
    letters = name.length();
    vowels = 0;
    string vowelList = "aeiouAEIOU";
    
    for (char c : name) {
        if (vowelList.find(c) != string::npos) {
            vowels++;
        }
    }
}

int main() {
    // Test value vs reference swap
    int x = 5, y = 10;
    cout << "Original values: " << x << ", " << y << endl;
    
    swapByValue(x, y);
    cout << "After swapByValue: " << x << ", " << y << endl;
    
    swapByReference(x, y);
    cout << "After swapByReference: " << x << ", " << y << endl;
    
    // Test const reference
    string name = "John Smith";
    printDetails(name);
    
    // Test multiple reference parameters
    int letterCount, vowelCount;
    getNameStats(name, letterCount, vowelCount);
    cout << "Name statistics:" << endl;
    cout << "Letters: " << letterCount << endl;
    cout << "Vowels: " << vowelCount << endl;
    
    return 0;
}
```

## Performance Considerations

### Call by Value
- Creates copy of data
- More memory usage
- Extra copy operations
- Safe but potentially slow

### Call by Reference
- No data copying
- Minimal memory overhead
- Direct access to original
- Better performance

## Common Use Cases

### Call by Value
```cpp
int square(int num) {
    return num * num;
}

bool isEven(int num) {
    return num % 2 == 0;
}
```

### Call by Reference
```cpp
void readUserInput(string& input) {
    getline(cin, input);
}

void splitName(const string& fullName, string& firstName, string& lastName) {
    size_t spacePos = fullName.find(' ');
    firstName = fullName.substr(0, spacePos);
    lastName = fullName.substr(spacePos + 1);
}
```

## Best Practices

1. Parameter Selection
   - Use value for small types
   - Use reference for large objects
   - Use const reference for read-only
   - Consider performance needs

2. Function Design
   - Be clear about modification intent
   - Document parameter behavior
   - Use const when possible
   - Consider return values

3. Error Handling
   - Validate reference parameters
   - Handle null/empty cases
   - Provide clear error messages
   - Consider exceptions

## Common Mistakes to Avoid
1. Returning references to local variables
2. Modifying const references
3. Using references to temporary objects
4. Forgetting to initialize reference parameters
5. Unnecessary use of references for small types

## Next Steps
- Try the practice exercise
- Experiment with different parameter types
- Move on to [Part 5: Function Overloading]({{ site.baseurl }}/tutorials/module3/part5-overloading)
