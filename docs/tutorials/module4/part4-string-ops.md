---
layout: default
title: Part 4 - Common String Operations
nav_order: 4
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part4-string-ops/
---

# Part 4: Common String Operations

## Overview
This part covers common string operations in C++, including string manipulation, searching, comparison, and formatting. Understanding these operations is essential for effective text processing.

## String Manipulation

### Concatenation
```cpp
// Using + operator
string first = "Hello";
string second = "World";
string result = first + " " + second;  // "Hello World"

// Using append
string text = "Hello";
text.append(" there");                 // "Hello there"
text += "!";                           // "Hello there!"
```

### Insertion and Erasure
```cpp
string str = "Hello World";

// Insert
str.insert(5, " beautiful");  // "Hello beautiful World"

// Erase
str.erase(6, 9);             // Remove "beautiful"
str.erase(5);                // Remove from position 5 to end
```

### Replacement
```cpp
string text = "Hello World";

// Replace substring
text.replace(6, 5, "there");  // "Hello there"

// Replace all occurrences
size_t pos = 0;
while ((pos = text.find("l", pos)) != string::npos) {
    text.replace(pos, 1, "L");
    pos++;
}
```

## String Searching

### Find Operations
```cpp
string text = "Hello World";

// Find first occurrence
size_t pos = text.find("o");        // Returns 4

// Find last occurrence
pos = text.rfind("o");              // Returns 7

// Find first of several characters
pos = text.find_first_of("aeiou");  // Find first vowel

// Find last of several characters
pos = text.find_last_of("aeiou");   // Find last vowel

// Check if contains
if (text.find("World") != string::npos) {
    cout << "Contains 'World'" << endl;
}
```

### Substring Operations
```cpp
string str = "Hello World";

// Get substring
string sub1 = str.substr(0, 5);     // "Hello"
string sub2 = str.substr(6);        // "World"

// Find between delimiters
size_t start = str.find_first_of("aeiou");
size_t end = str.find_last_of("aeiou");
if (start != string::npos && end != string::npos) {
    string sub = str.substr(start, end - start + 1);
}
```

## String Comparison

### Comparison Operations
```cpp
string str1 = "apple";
string str2 = "banana";

// Using operators
bool isEqual = (str1 == str2);
bool isLess = (str1 < str2);

// Using compare method
int result = str1.compare(str2);
// negative if str1 < str2
// 0 if str1 == str2
// positive if str1 > str2

// Compare substrings
result = str1.compare(0, 2, str2, 0, 2);
```

### Case-Insensitive Comparison
```cpp
bool compareIgnoreCase(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    
    for (size_t i = 0; i < str1.length(); i++) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
    }
    return true;
}
```

## Practice Exercise

Create a program that implements various string operations:
1. Text analysis (count vowels, consonants, etc.)
2. String transformation (case conversion, replacement)
3. Pattern matching
4. Word processing

Solution:
```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to count vowels in string
int countVowels(const string& str) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    
    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Function to convert string to title case
string toTitleCase(string str) {
    bool newWord = true;
    
    for (char& c : str) {
        if (isspace(c)) {
            newWord = true;
        } else if (newWord) {
            c = toupper(c);
            newWord = false;
        } else {
            c = tolower(c);
        }
    }
    return str;
}

// Function to find all occurrences of a pattern
void findAllOccurrences(const string& str, const string& pattern) {
    size_t pos = 0;
    while ((pos = str.find(pattern, pos)) != string::npos) {
        cout << "Found at position: " << pos << endl;
        pos++;
    }
}

int main() {
    // Text analysis
    string text = "Hello World! This is a test.";
    cout << "Original text: " << text << endl;
    cout << "Number of vowels: " << countVowels(text) << endl;
    cout << "Length: " << text.length() << endl;
    
    // String transformation
    cout << "\nTransformations:" << endl;
    cout << "Title case: " << toTitleCase(text) << endl;
    
    // Convert to upper case
    string upper = text;
    for (char& c : upper) {
        c = toupper(c);
    }
    cout << "Upper case: " << upper << endl;
    
    // Convert to lower case
    string lower = text;
    for (char& c : lower) {
        c = tolower(c);
    }
    cout << "Lower case: " << lower << endl;
    
    // Pattern matching
    cout << "\nPattern matching:" << endl;
    string pattern = "is";
    cout << "Finding all occurrences of '" << pattern << "':" << endl;
    findAllOccurrences(text, pattern);
    
    // Word processing
    cout << "\nWord processing:" << endl;
    string sentence = "   This   has   extra   spaces   ";
    
    // Trim leading spaces
    size_t start = sentence.find_first_not_of(" \t\n\r");
    if (start != string::npos) {
        sentence = sentence.substr(start);
    }
    
    // Trim trailing spaces
    size_t end = sentence.find_last_not_of(" \t\n\r");
    if (end != string::npos) {
        sentence = sentence.substr(0, end + 1);
    }
    
    // Reduce multiple spaces to single space
    string result;
    bool lastWasSpace = false;
    
    for (char c : sentence) {
        if (isspace(c)) {
            if (!lastWasSpace) {
                result += ' ';
                lastWasSpace = true;
            }
        } else {
            result += c;
            lastWasSpace = false;
        }
    }
    
    cout << "Original: \"" << sentence << "\"" << endl;
    cout << "Processed: \"" << result << "\"" << endl;
    
    return 0;
}
```

## Best Practices

### String Efficiency
1. Use string_view for read-only strings
2. Reserve space for known sizes
3. Use references to avoid copies
4. Consider SSO for small strings
5. Use appropriate search methods

### String Safety
1. Check string bounds
2. Validate input strings
3. Handle empty strings
4. Use exception handling
5. Check search results

### String Style
1. Be consistent with case
2. Use clear string literals
3. Consider internationalization
4. Document string formats
5. Use meaningful names

## Common Mistakes to Avoid
1. Ignoring string capacity
2. Unchecked string access
3. Inefficient concatenation
4. Not handling empty strings
5. Assuming string encoding

## Next Steps
- Try the practice exercise
- Experiment with string operations
- Consider taking [Module 5: Classes and Objects]({{ site.baseurl }}/tutorials/module5)
