---
layout: default
title: Part 3 - Strings
nav_order: 3
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part3-strings/
---

# Part 3: Strings

## Overview
C++ provides two ways to work with strings: C-style strings (character arrays) and the more modern `std::string` class. This part covers both approaches and their common operations.

## C-style Strings

### Characteristics
- Null-terminated character arrays
- Fixed size
- Lower-level operations
- Legacy code compatibility
- Manual memory management

### Basic Operations
```cpp
// Declaration and initialization
char str1[] = "Hello";           // Array initialization
char str2[10] = "World";        // Fixed-size array
const char* str3 = "Constant";  // String literal

// String length
int len = strlen(str1);        // Get length
cout << len << endl;           // Prints 5

// String copy
char dest[10];
strcpy(dest, str1);           // Copy str1 to dest

// String concatenation
strcat(dest, str2);          // Append str2 to dest

// String comparison
if (strcmp(str1, str2) == 0) {
    cout << "Strings are equal" << endl;
}
```

## std::string Class

### Characteristics
- Dynamic size management
- Rich set of operations
- RAII compliant
- Exception safe
- Modern C++ approach

### Basic Operations
```cpp
#include <string>

// Creation and initialization
string str1 = "Hello";
string str2("World");
string str3(5, '*');     // Creates "*****"

// String concatenation
string result = str1 + " " + str2;  // "Hello World"
str1 += " there";                   // Append to str1

// String length
cout << str1.length() << endl;     // Get length
cout << str1.size() << endl;       // Same as length

// Substring
string sub = str1.substr(0, 5);    // Get first 5 chars

// Find operations
size_t pos = str1.find("lo");      // Find substring
if (pos != string::npos) {
    cout << "Found at " << pos << endl;
}
```

## String Manipulation

### Character Access
```cpp
string str = "Hello";

// Using array notation
char first = str[0];           // Get first char
str[0] = 'h';                 // Modify first char

// Using at() method (bounds checking)
char last = str.at(4);        // Get last char
try {
    str.at(10) = 'x';        // Throws out_of_range
} catch (const out_of_range& e) {
    cout << "Index out of range" << endl;
}
```

### String Modification
```cpp
string str = "Hello World";

// Insert
str.insert(5, " there");     // Insert at position

// Erase
str.erase(5, 6);            // Remove 6 chars from pos 5

// Replace
str.replace(0, 5, "Hi");    // Replace first 5 chars

// Clear
str.clear();                // Empty the string

// Resize
str.resize(10, '*');        // Resize and fill with '*'
```

## Practice Exercise

Create a program that demonstrates string operations:
1. Basic string manipulation
2. String searching and extraction
3. String comparison and conversion
4. Mixed string operations

Solution:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Basic string operations
    string text = "Hello, World!";
    cout << "Original text: " << text << endl;
    
    // String manipulation
    text[0] = 'h';                     // Modify character
    text.append(" Welcome");           // Append text
    cout << "Modified text: " << text << endl;
    
    // String information
    cout << "Length: " << text.length() << endl;
    cout << "First char: " << text.front() << endl;
    cout << "Last char: " << text.back() << endl;
    
    // Substring operations
    string sub = text.substr(0, 5);    // Get "hello"
    cout << "Substring: " << sub << endl;
    
    // Find operations
    size_t pos = text.find("World");
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }
    
    // Replace operations
    text.replace(text.find("World"), 5, "Everyone");
    cout << "After replace: " << text << endl;
    
    // String comparison
    string str1 = "apple";
    string str2 = "banana";
    if (str1 < str2) {
        cout << str1 << " comes before " << str2 << endl;
    }
    
    // String conversion
    string numStr = "123";
    int num = stoi(numStr);            // String to int
    string backToStr = to_string(num);  // Int to string
    
    // String splitting
    string sentence = "This is a test";
    size_t start = 0;
    size_t end = sentence.find(" ");
    
    cout << "\nSplitting sentence into words:" << endl;
    while (end != string::npos) {
        cout << sentence.substr(start, end - start) << endl;
        start = end + 1;
        end = sentence.find(" ", start);
    }
    cout << sentence.substr(start) << endl;
    
    return 0;
}
```

## Best Practices

### String Choice
1. Prefer std::string over C-strings
2. Use string_view for read-only strings
3. Consider string_stream for formatting
4. Use const string& for parameters
5. Reserve space for known sizes

### String Operations
1. Use appropriate methods
2. Check string bounds
3. Handle empty strings
4. Consider string_view for substrings
5. Use references for large strings

### Performance Considerations
1. Avoid unnecessary copies
2. Use reserve() when size known
3. Use references in loops
4. Consider SSO (Small String Optimization)
5. Profile string operations

## Common Mistakes to Avoid
1. Buffer overflow with C-strings
2. Not checking find() results
3. Inefficient string concatenation
4. Ignoring string capacity
5. Unnecessary string copies

## Next Steps
- Try the practice exercise
- Experiment with string operations
- Move on to [Part 4: Common String Operations]({{ site.baseurl }}/tutorials/module4/part4-string-ops)
