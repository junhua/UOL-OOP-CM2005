// Module 09 - Part 01: Introduction to Pointers
// This tutorial demonstrates:
// 1. What are pointers and memory addresses
// 2. Declaring and initializing pointers
// 3. Dereferencing pointers
// 4. Null pointers and pointer safety

#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable and initialize it
    int number = 42;
    cout << "1. Working with basic pointers:" << endl;
    cout << "number = " << number << endl;
    
    // Declare a pointer to an integer and make it point to number's address
    // The & operator gets the memory address of a variable
    int* ptr = &number;
    
    // Print the integer's memory address using & operator
    cout << "\n2. Memory addresses:" << endl;
    cout << "Address of number: " << &number << endl;
    
    // Print the pointer's value (which is the address it stores)
    cout << "Value of ptr (address it points to): " << ptr << endl;
    
    // Print the value that the pointer points to using the dereference operator *
    cout << "\n3. Dereferencing pointers:" << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    // Modify the integer through the pointer
    *ptr = 100;  // Changes the value of 'number'
    cout << "\n4. Modifying value through pointer:" << endl;
    cout << "number after *ptr = 100: " << number << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    // Demonstrate null pointer safety
    cout << "\n5. Null pointer safety:" << endl;
    
    // Initialize a pointer to nullptr
    int* nullPtr = nullptr;
    cout << "nullPtr = " << nullPtr << endl;
    
    // Safe way to use pointers: always check for nullptr before dereferencing
    if (nullPtr != nullptr) {
        cout << "Value pointed to by nullPtr: " << *nullPtr << endl;
    } else {
        cout << "Cannot dereference nullPtr: it is null" << endl;
    }
    
    // Example of pointer reassignment
    cout << "\n6. Pointer reassignment:" << endl;
    int anotherNumber = 200;
    cout << "anotherNumber = " << anotherNumber << endl;
    
    // Make ptr point to anotherNumber instead
    ptr = &anotherNumber;
    cout << "After ptr = &anotherNumber:" << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;
    
    // Important notes about pointer safety:
    // 1. Always initialize pointers (either to an address or nullptr)
    // 2. Check for nullptr before dereferencing
    // 3. Be careful not to dereference pointers to invalid memory
    // 4. When you're done with a pointer, set it to nullptr if you're not going to use it anymore
    
    ptr = nullptr;  // Clean up: set pointer to nullptr when done
    
    return 0;
}
