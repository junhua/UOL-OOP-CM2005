#ifndef MODERN_ARRAY_H
#define MODERN_ARRAY_H

#include <array>
#include <iostream>
#include <stdexcept>

// Second approach: Using std::array
template<typename T, std::size_t N>
class ModernArray {
private:
    std::array<T, N> data;  // Fixed-size array from STL
    std::size_t size;
    
public:
    ModernArray() : size(0) {
        // TODO: Initialize array using std::array methods
        // Hint: Use fill() to set all elements to default value
    }
    
    // Add element (with bounds checking)
    bool add(const T& value) {
        // TODO: Use std::array's at() method for safe access
        // Add value if there's space
        // Return true if successful, false if array is full
        return false;
    }
    
    // Get element (with exception handling)
    T get(std::size_t index) const {
        // TODO: Use std::array's at() method
        // This will throw std::out_of_range if index is invalid
        // Hint: Let the exception propagate to demonstrate std::array's safety
        return T();
    }
    
    // Update element (with exception handling)
    void update(std::size_t index, const T& value) {
        // TODO: Use std::array's at() method
        // This will throw std::out_of_range if index is invalid
    }
    
    // Remove last element
    bool removeLast() {
        // TODO: Remove last element if array is not empty
        // Return false if array is empty
        return false;
    }
    
    // Get current size
    std::size_t getSize() const {
        return size;
    }
    
    // Get maximum size using std::array's size() method
    std::size_t getMaxSize() const {
        return N;
    }
    
    // Display array using range-based for loop
    void display() const {
        std::cout << "Array contents [" << size << "/" 
             << N << "]: ";
        // TODO: Use range-based for loop with std::array
        // Hint: Only print up to 'size' elements
        std::cout << std::endl;
    }
};

#endif // MODERN_ARRAY_H
