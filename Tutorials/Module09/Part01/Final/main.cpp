#include <iostream>
#include <string>
using namespace std;

/**
 * Module 9 - Part 1: Introduction to Pointers
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Basic pointer operations
 * 2. Multiple data types
 * 3. Pointer arithmetic
 * 4. Memory management
 */

void demonstratePointers() {
    // Basic pointer usage
    int number = 42;
    int* numPtr = &number;
    
    cout << "\nBasic Pointer Demo:" << endl;
    cout << string(30, '-') << endl;
    cout << "number value: " << number << endl;
    cout << "number address: " << &number << endl;
    cout << "numPtr value (address): " << numPtr << endl;
    cout << "numPtr dereferenced: " << *numPtr << endl;
    
    // Modifying through pointer
    *numPtr = 100;
    cout << "\nAfter modification:" << endl;
    cout << "number value: " << number << endl;
    cout << "numPtr dereferenced: " << *numPtr << endl;
}

void multiplePointers() {
    // Different data type pointers
    int i = 10;
    double d = 3.14;
    char c = 'A';
    string s = "Hello";
    
    int* pi = &i;
    double* pd = &d;
    char* pc = &c;
    string* ps = &s;
    
    cout << "\nMultiple Data Types:" << endl;
    cout << string(30, '-') << endl;
    cout << "Integer: " << *pi << endl;
    cout << "Double: " << *pd << endl;
    cout << "Character: " << *pc << endl;
    cout << "String: " << *ps << endl;
}

void pointerArithmetic() {
    // Array and pointer arithmetic
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;  // Array decays to pointer
    
    cout << "\nPointer Arithmetic:" << endl;
    cout << string(30, '-') << endl;
    
    // Moving through array
    cout << "First element: " << *ptr << endl;
    ptr++;  // Move to next element
    cout << "Second element: " << *ptr << endl;
    ptr += 2;  // Skip two elements
    cout << "Fourth element: " << *ptr << endl;
    ptr--;  // Move back one element
    cout << "Third element: " << *ptr << endl;
}

void nullPointers() {
    // Null pointer demonstration
    int* ptr = nullptr;
    
    cout << "\nNull Pointer Demo:" << endl;
    cout << string(30, '-') << endl;
    cout << "Null pointer value: " << ptr << endl;
    
    // Safe null check
    if (ptr == nullptr) {
        cout << "Pointer is null" << endl;
    }
    
    // Allocate memory
    ptr = new int(42);
    cout << "After allocation: " << *ptr << endl;
    
    // Clean up
    delete ptr;
    ptr = nullptr;
}

void constPointers() {
    int value = 10;
    const int* ptr1 = &value;      // Can't modify value through pointer
    int* const ptr2 = &value;      // Can't modify pointer itself
    const int* const ptr3 = &value;// Can't modify either
    
    cout << "\nConst Pointers:" << endl;
    cout << string(30, '-') << endl;
    
    // ptr1 = &value;  // OK
    // *ptr1 = 20;     // Error
    
    // ptr2 = &value;  // Error
    *ptr2 = 20;      // OK
    
    // ptr3 = &value;  // Error
    // *ptr3 = 20;     // Error
    
    cout << "Value after modification: " << value << endl;
}

int main() {
    try {
        cout << "Pointer Basics Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        demonstratePointers();
        multiplePointers();
        pointerArithmetic();
        nullPointers();
        constPointers();
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
