---
layout: default
title: Part 1 - Vector, Set and Map
nav_order: 1
parent: Module 4 - Collections and Strings
grand_parent: Tutorials
permalink: /tutorials/module4/part1-collections/
---

# Part 1: Vector, Set and Map

## Overview
C++ provides several container types in the Standard Template Library (STL) for storing and managing collections of data. This part introduces three fundamental container types: Vector, Set, and Map.

## Vector

### What is a Vector?
- Dynamic array implementation
- Automatically resizes as needed
- Continuous memory storage
- Fast random access
- Efficient insertion at end

### Basic Vector Operations
```cpp
#include <vector>

vector<int> numbers;              // Create empty vector
numbers.push_back(10);           // Add element at end
numbers.pop_back();              // Remove last element
numbers[0];                      // Access element
numbers.at(0);                   // Safe access with bounds checking
numbers.size();                  // Get number of elements
numbers.empty();                 // Check if empty
numbers.clear();                 // Remove all elements
```

### Vector Iteration
```cpp
vector<int> nums = {1, 2, 3, 4, 5};

// Using index
for (size_t i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
}

// Using range-based for loop
for (int num : nums) {
    cout << num << " ";
}

// Using iterator
for (auto it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
}
```

## Set

### What is a Set?
- Stores unique elements
- Automatically sorted
- No duplicates allowed
- Fast search operations
- Binary tree implementation

### Basic Set Operations
```cpp
#include <set>

set<int> numbers;                // Create empty set
numbers.insert(10);             // Insert element
numbers.erase(10);              // Remove element
numbers.find(10);               // Find element
numbers.count(10);              // Count occurrences (0 or 1)
numbers.size();                 // Get number of elements
numbers.empty();                // Check if empty
numbers.clear();                // Remove all elements
```

### Set Iteration
```cpp
set<int> nums = {3, 1, 4, 1, 5};  // Stores: {1, 3, 4, 5}

// Using range-based for loop
for (int num : nums) {
    cout << num << " ";  // Prints in sorted order
}

// Using iterator
for (auto it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
}
```

## Map

### What is a Map?
- Key-value pair storage
- Unique keys
- Automatically sorted by key
- Fast key lookup
- Binary tree implementation

### Basic Map Operations
```cpp
#include <map>

map<string, int> scores;         // Create empty map
scores["Alice"] = 100;          // Insert/update value
scores.erase("Alice");          // Remove entry
scores.find("Alice");           // Find entry
scores.count("Alice");          // Check if key exists
scores.size();                  // Get number of entries
scores.empty();                 // Check if empty
scores.clear();                 // Remove all entries
```

### Map Iteration
```cpp
map<string, int> scores = {
    {"Alice", 100},
    {"Bob", 95},
    {"Charlie", 90}
};

// Using range-based for loop
for (const auto& pair : scores) {
    cout << pair.first << ": " << pair.second << endl;
}

// Using iterator
for (auto it = scores.begin(); it != scores.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

## Practice Exercise

Create a program that demonstrates the use of Vector, Set, and Map:
1. Use a vector to store and process student grades
2. Use a set to track unique student IDs
3. Use a map to store student name-grade pairs

Solution:
```cpp
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    // Vector example - storing grades
    vector<int> grades;
    grades.push_back(85);
    grades.push_back(92);
    grades.push_back(78);
    grades.push_back(95);
    
    // Calculate average grade
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    double average = static_cast<double>(sum) / grades.size();
    
    cout << "Grades: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << "\nAverage: " << average << endl;
    
    // Set example - unique student IDs
    set<int> studentIds;
    studentIds.insert(1001);
    studentIds.insert(1002);
    studentIds.insert(1001);  // Duplicate, won't be added
    studentIds.insert(1003);
    
    cout << "\nStudent IDs: ";
    for (int id : studentIds) {
        cout << id << " ";
    }
    cout << "\nNumber of students: " << studentIds.size() << endl;
    
    // Map example - student name-grade pairs
    map<string, int> studentGrades;
    studentGrades["Alice"] = 95;
    studentGrades["Bob"] = 87;
    studentGrades["Charlie"] = 92;
    
    cout << "\nStudent Grades:" << endl;
    for (const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Demonstrate map lookup
    string student = "Alice";
    if (studentGrades.find(student) != studentGrades.end()) {
        cout << "\n" << student << "'s grade: " 
             << studentGrades[student] << endl;
    }
    
    return 0;
}
```

## Common Operations Comparison

### Adding Elements
```cpp
vector<int> vec;
vec.push_back(1);     // Add to end

set<int> s;
s.insert(1);         // Insert element

map<string, int> m;
m["key"] = 1;        // Add/update key-value pair
```

### Removing Elements
```cpp
vector<int> vec = {1, 2, 3};
vec.pop_back();              // Remove last
vec.erase(vec.begin());     // Remove first

set<int> s = {1, 2, 3};
s.erase(2);                 // Remove element

map<string, int> m = {{"a", 1}};
m.erase("a");              // Remove key-value pair
```

### Searching
```cpp
// Vector - linear search
auto it = find(vec.begin(), vec.end(), value);

// Set - logarithmic search
auto it = s.find(value);

// Map - logarithmic search
auto it = m.find(key);
```

## Best Practices

### Vector Best Practices
1. Reserve space if size known
2. Use push_back over [] for adding
3. Use range-based for when possible
4. Check bounds before accessing
5. Consider using emplace_back

### Set Best Practices
1. Use for unique collections
2. Check insert result
3. Use count for existence check
4. Consider multiset if duplicates needed
5. Use emplace for efficient insertion

### Map Best Practices
1. Check key existence before access
2. Use at() for safe access
3. Use emplace for efficient insertion
4. Consider unordered_map for better performance
5. Use structured bindings in C++17

## Common Mistakes to Avoid
1. Not checking bounds
2. Invalidating iterators
3. Using [] without checking map key
4. Forgetting to include headers
5. Not considering performance implications

## Next Steps
- Try the practice exercise
- Experiment with different container types
- Move on to [Part 2: Accessing Array Elements]({% link tutorials/module4/part2-arrays.md %})
