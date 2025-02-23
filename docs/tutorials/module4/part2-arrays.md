---
layout: default
title: Part 2 - Accessing Array Elements
nav_order: 2
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part2-arrays/
---

# Part 2: Accessing Array Elements

## Overview
Arrays in C++ provide a way to store collections of elements of the same type. Understanding how to access and manipulate array elements is crucial for working with collections of data.

## Array Basics

### Declaration and Initialization
```cpp
// Fixed-size array declaration
int numbers[5];                    // Uninitialized array
int scores[3] = {95, 88, 78};     // Initialized array
double grades[] = {85.5, 92.0};   // Size determined by initializer

// C++11 uniform initialization
int values[]{1, 2, 3, 4, 5};
```

### Array Size
```cpp
// Using sizeof to get array size
int arr[] = {1, 2, 3, 4, 5};
int size = sizeof(arr) / sizeof(arr[0]);

// C++17 std::size
#include <array>
size_t length = std::size(arr);
```

## Accessing Elements

### Using Index Operator
```cpp
int numbers[5] = {10, 20, 30, 40, 50};

// Reading elements
int first = numbers[0];    // First element
int last = numbers[4];     // Last element

// Modifying elements
numbers[2] = 35;           // Change third element
```

### Bounds Checking
```cpp
// Manual bounds checking
int index = 5;
if (index >= 0 && index < sizeof(numbers)/sizeof(numbers[0])) {
    cout << numbers[index];
} else {
    cout << "Index out of bounds";
}

// Using std::array for automatic bounds checking
#include <array>
std::array<int, 5> nums = {10, 20, 30, 40, 50};
try {
    cout << nums.at(5);  // Throws out_of_range exception
} catch (const out_of_range& e) {
    cout << "Index out of bounds";
}
```

## Array Iteration

### Using Index-based Loop
```cpp
int numbers[] = {1, 2, 3, 4, 5};
int size = sizeof(numbers) / sizeof(numbers[0]);

for (int i = 0; i < size; i++) {
    cout << numbers[i] << " ";
}
```

### Using Range-based Loop
```cpp
int numbers[] = {1, 2, 3, 4, 5};

for (int num : numbers) {
    cout << num << " ";
}
```

### Using Iterators (with std::array)
```cpp
#include <array>
std::array<int, 5> numbers = {1, 2, 3, 4, 5};

for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    cout << *it << " ";
}
```

## Multi-dimensional Arrays

### Declaration and Initialization
```cpp
// 2D array declaration
int matrix[3][3];

// 2D array initialization
int grid[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### Accessing Elements
```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

// Accessing elements
int element = matrix[1][2];  // Access 6

// Modifying elements
matrix[0][1] = 10;          // Change 2 to 10
```

### Iteration
```cpp
int matrix[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

// Using nested loops
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

## Practice Exercise

Create a program that demonstrates array operations:
1. Create and initialize arrays
2. Access and modify elements
3. Implement array searching
4. Work with 2D arrays

Solution:
```cpp
#include <iostream>
using namespace std;

// Function to find element in array
int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Not found
}

// Function to print 2D array
void print2DArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 1D array operations
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Print original array
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Modify elements
    numbers[2] = 35;  // Change 30 to 35
    
    // Print modified array
    cout << "Modified array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Search for element
    int target = 40;
    int index = findElement(numbers, size, target);
    if (index != -1) {
        cout << target << " found at index " << index << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    // 2D array operations
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "\n2D Array:" << endl;
    print2DArray(matrix, 2);
    
    // Modify 2D array element
    matrix[1][1] = 10;  // Change 5 to 10
    
    cout << "\nModified 2D Array:" << endl;
    print2DArray(matrix, 2);
    
    // Calculate sum of elements
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "\nSum of all elements: " << sum << endl;
    
    return 0;
}
```

## Best Practices

### Array Declaration
1. Initialize arrays when declared
2. Use const for read-only arrays
3. Consider std::array for fixed size
4. Use vector for dynamic size
5. Declare size as constant

### Array Access
1. Always check bounds
2. Use range-based for when possible
3. Be careful with pointer arithmetic
4. Consider using at() for safety
5. Document array dimensions

### Array Parameters
1. Pass size with array
2. Use const for read-only arrays
3. Consider reference for large arrays
4. Document parameter requirements
5. Validate array parameters

## Common Mistakes to Avoid
1. Array bounds overflow
2. Uninitialized arrays
3. Incorrect size calculations
4. Pointer/array confusion
5. Missing null terminator (char arrays)

## Next Steps
- Try the practice exercise
- Experiment with different array types
- Move on to [Part 3: Strings]({{ site.baseurl }}/tutorials/module4/part3-strings)
