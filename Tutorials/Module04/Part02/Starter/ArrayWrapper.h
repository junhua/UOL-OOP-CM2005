#ifndef ARRAY_WRAPPER_H
#define ARRAY_WRAPPER_H

#include <iostream>
#include <stdexcept>

// First approach: Wrapping a C-style array
class ArrayWrapper {
private:
    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int size;
    
public:
    ArrayWrapper() : size(0) {
        // TODO: Initialize all elements to 0
        // Hint: Use a for loop
    }
    
    // Add element to array
    bool add(int value) {
        // TODO: Add value to array if there's space
        // Return true if successful, false if array is full
        return false;
    }
    
    // Get element (with bounds checking)
    bool get(int index, int& value) const {
        // TODO: Return element at index if valid
        // Return false if index is out of bounds
        return false;
    }
    
    // Update element
    bool update(int index, int value) {
        // TODO: Update element at index if valid
        // Return false if index is out of bounds
        return false;
    }
    
    // Remove last element
    bool removeLast() {
        // TODO: Remove last element if array is not empty
        // Return false if array is empty
        return false;
    }
    
    // Get current size
    int getSize() const {
        return size;
    }
    
    // Get maximum size
    int getMaxSize() const {
        return MAX_SIZE;
    }
    
    // Display array
    void display() const {
        std::cout << "Array contents [" << size << "/" 
             << MAX_SIZE << "]: ";
        // TODO: Print all elements
        // Hint: Use a for loop
        std::cout << std::endl;
    }
};

#endif // ARRAY_WRAPPER_H
