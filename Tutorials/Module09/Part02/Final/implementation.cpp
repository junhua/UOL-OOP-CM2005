// Module 09 - Part 02: Pointer Arithmetic
// This tutorial demonstrates:
// 1. Basic pointer arithmetic operations
// 2. Array traversal using pointer arithmetic
// 3. Relationship between arrays and pointers
// 4. Pointer arithmetic with different data types

#include <iostream>
using namespace std;

int main() {
    // Create an integer array with 5 elements
    int numbers[] = {10, 20, 30, 40, 50};
    const int SIZE = 5;
    
    cout << "1. Basic array traversal:" << endl;
    
    // Create a pointer to the first element of the array
    int* ptr = numbers;  // Equivalent to: int* ptr = &numbers[0];
    
    // Print array elements using array indexing
    cout << "\nUsing array indexing:" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;
    }
    
    // Print array elements using pointer arithmetic
    cout << "\nUsing pointer arithmetic (forward):" << endl;
    for(int i = 0; i < SIZE; i++) {
        // Print both the address and value
        cout << "Address: " << ptr + i  // Adding i to ptr
             << ", Value: " << *(ptr + i) << endl;  // Dereferencing ptr + i
    }
    
    // Alternative way using pointer increment
    cout << "\nUsing pointer increment:" << endl;
    ptr = numbers;  // Reset pointer to start of array
    for(int i = 0; i < SIZE; i++) {
        cout << "Address: " << ptr << ", Value: " << *ptr << endl;
        ptr++;  // Move to next element
    }
    
    // Traverse array backwards using pointer arithmetic
    cout << "\n2. Backward traversal:" << endl;
    
    // Point to the last element
    ptr = &numbers[SIZE - 1];
    
    for(int i = 0; i < SIZE; i++) {
        cout << "Address: " << ptr << ", Value: " << *ptr << endl;
        ptr--;  // Move to previous element
    }
    
    // Demonstrate pointer arithmetic with different data types
    cout << "\n3. Pointer arithmetic with different data types:" << endl;
    
    double doubles[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double* doublePtr = doubles;
    
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    
    // Show how pointer increment changes based on data type
    cout << "\nDouble array pointer arithmetic:" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << "Address: " << doublePtr + i  // Notice the address difference
             << ", Value: " << *(doublePtr + i) << endl;
    }
    
    // Demonstrate equivalence of pointer arithmetic and array indexing
    cout << "\n4. Equivalence of pointer arithmetic and array indexing:" << endl;
    
    int index = 2;  // Access the third element
    cout << "Using array index: numbers[" << index << "] = " 
         << numbers[index] << endl;
    cout << "Using pointer arithmetic: *(ptr + " << index << ") = " 
         << *(numbers + index) << endl;
    
    // Important notes about pointer arithmetic:
    // 1. Pointer arithmetic automatically accounts for data type size
    // 2. ptr++ moves to the next element, not the next byte
    // 3. Can subtract pointers to find number of elements between them
    // 4. Cannot add two pointers (makes no sense)
    // 5. Can add or subtract integers to/from pointers
    
    // Example of pointer subtraction
    int* start = numbers;
    int* end = &numbers[SIZE - 1];
    cout << "\n5. Pointer subtraction:" << endl;
    cout << "Number of elements between start and end: " 
         << end - start + 1 << endl;
    
    return 0;
}
