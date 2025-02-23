---
layout: default
title: Part 2 - Constructors and Destructors
nav_order: 2
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part2-constructors/
---

# Part 2: Constructors and Destructors

## Overview
Constructors and destructors are special member functions that handle object initialization and cleanup. Understanding how to properly implement these is crucial for effective class design.

## Constructors

### Default Constructor
```cpp
class Student {
private:
    string name;
    int age;
    
public:
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
    }
};
```

### Parameterized Constructor
```cpp
class Student {
private:
    string name;
    int age;
    
public:
    // Parameterized constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }
};
```

### Constructor Initialization List
```cpp
class Student {
private:
    const string id;
    string name;
    int age;
    
public:
    // Constructor with initialization list
    Student(string i, string n, int a) 
        : id(i), name(n), age(a) {
        // Constructor body
    }
};
```

### Multiple Constructors
```cpp
class Rectangle {
private:
    double width;
    double height;
    
public:
    // Default constructor
    Rectangle() : width(0), height(0) {}
    
    // Single parameter constructor
    Rectangle(double size) : width(size), height(size) {}
    
    // Two parameter constructor
    Rectangle(double w, double h) : width(w), height(h) {}
};
```

## Destructors

### Basic Destructor
```cpp
class DynamicArray {
private:
    int* data;
    int size;
    
public:
    // Constructor
    DynamicArray(int s) {
        size = s;
        data = new int[size];
    }
    
    // Destructor
    ~DynamicArray() {
        delete[] data;  // Free allocated memory
    }
};
```

### Virtual Destructor
```cpp
class Base {
public:
    virtual ~Base() {
        // Cleanup base resources
    }
};

class Derived : public Base {
public:
    ~Derived() {
        // Cleanup derived resources
    }
};
```

## Practice Exercise

Create a class to represent a dynamic string buffer:
1. Constructor to allocate memory
2. Destructor to free memory
3. Copy constructor for deep copying
4. Methods to manipulate the buffer

Solution:
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class StringBuffer {
private:
    char* buffer;
    size_t capacity;
    
    // Helper to allocate memory
    void allocate(size_t size) {
        buffer = new char[size];
        capacity = size;
    }
    
public:
    // Default constructor
    StringBuffer() {
        allocate(1);
        buffer[0] = '\0';
    }
    
    // Parameterized constructor
    StringBuffer(const char* str) {
        size_t len = strlen(str);
        allocate(len + 1);
        strcpy(buffer, str);
    }
    
    // Copy constructor
    StringBuffer(const StringBuffer& other) {
        allocate(other.capacity);
        strcpy(buffer, other.buffer);
    }
    
    // Destructor
    ~StringBuffer() {
        delete[] buffer;
    }
    
    // Assignment operator
    StringBuffer& operator=(const StringBuffer& other) {
        if (this != &other) {
            delete[] buffer;
            allocate(other.capacity);
            strcpy(buffer, other.buffer);
        }
        return *this;
    }
    
    // Get string length
    size_t length() const {
        return strlen(buffer);
    }
    
    // Get buffer capacity
    size_t getCapacity() const {
        return capacity;
    }
    
    // Get string content
    const char* getString() const {
        return buffer;
    }
    
    // Append string
    void append(const char* str) {
        size_t newLen = length() + strlen(str);
        if (newLen >= capacity) {
            // Create new buffer with more space
            size_t newCapacity = newLen + 1;
            char* newBuffer = new char[newCapacity];
            strcpy(newBuffer, buffer);
            delete[] buffer;
            buffer = newBuffer;
            capacity = newCapacity;
        }
        strcat(buffer, str);
    }
    
    // Clear buffer
    void clear() {
        buffer[0] = '\0';
    }
};

int main() {
    // Test default constructor
    StringBuffer sb1;
    cout << "Default constructed buffer:" << endl;
    cout << "Content: \"" << sb1.getString() << "\"" << endl;
    cout << "Length: " << sb1.length() << endl;
    cout << "Capacity: " << sb1.getCapacity() << endl;
    
    // Test parameterized constructor
    StringBuffer sb2("Hello");
    cout << "\nParameterized constructed buffer:" << endl;
    cout << "Content: \"" << sb2.getString() << "\"" << endl;
    cout << "Length: " << sb2.length() << endl;
    cout << "Capacity: " << sb2.getCapacity() << endl;
    
    // Test copy constructor
    StringBuffer sb3 = sb2;
    cout << "\nCopy constructed buffer:" << endl;
    cout << "Content: \"" << sb3.getString() << "\"" << endl;
    
    // Test append
    sb3.append(" World!");
    cout << "\nAfter append:" << endl;
    cout << "Content: \"" << sb3.getString() << "\"" << endl;
    cout << "Length: " << sb3.length() << endl;
    cout << "Capacity: " << sb3.getCapacity() << endl;
    
    // Test assignment
    StringBuffer sb4;
    sb4 = sb3;
    cout << "\nAfter assignment:" << endl;
    cout << "Content: \"" << sb4.getString() << "\"" << endl;
    
    // Test clear
    sb4.clear();
    cout << "\nAfter clear:" << endl;
    cout << "Content: \"" << sb4.getString() << "\"" << endl;
    cout << "Length: " << sb4.length() << endl;
    
    return 0;
}
```

## Best Practices

### Constructor Design
1. Initialize all members
2. Use initialization lists
3. Consider delegating constructors
4. Handle resource allocation
5. Validate parameters

### Destructor Design
1. Clean up all resources
2. Make base destructors virtual
3. Handle cleanup errors
4. Never throw exceptions
5. Consider RAII pattern

### Resource Management
1. Follow Rule of Three/Five
2. Use smart pointers
3. Consider move semantics
4. Handle self-assignment
5. Implement deep copying

## Common Mistakes to Avoid
1. Uninitialized members
2. Memory leaks
3. Shallow copying
4. Missing virtual destructors
5. Resource cleanup errors

## Next Steps
- Try the practice exercise
- Experiment with constructors
- Move on to [Part 3: Creating and Using Objects]({{ site.baseurl }}/tutorials/module5/part3-objects)
