#include <iostream>
#include <string>
using namespace std;

/**
 * Module 9 - Part 2: Pointer Arithmetic
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Array traversal
 * 2. Memory navigation
 * 3. Array manipulation
 * 4. Pointer comparisons
 */

void basicArithmetic() {
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers;
    
    cout << "\nBasic Arithmetic:" << endl;
    cout << string(30, '-') << endl;
    
    // Forward traversal
    cout << "Forward traversal:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *ptr << endl;
        ptr++;
    }
    
    // Reset pointer
    ptr = numbers;
    
    // Backward traversal
    cout << "\nBackward traversal:" << endl;
    ptr = ptr + 4;  // Move to last element
    for (int i = 4; i >= 0; i--) {
        cout << "Element " << i << ": " << *ptr << endl;
        ptr--;
    }
}

void arrayManipulation() {
    int data[] = {1, 2, 3, 4, 5};
    int* start = data;
    int* end = data + 4;  // Point to last element
    
    cout << "\nArray Manipulation:" << endl;
    cout << string(30, '-') << endl;
    
    // Double each element
    cout << "Doubling elements:" << endl;
    while (start <= end) {
        *start *= 2;  // Double the value
        cout << *start << " ";
        start++;
    }
    cout << endl;
    
    // Reset pointer
    start = data;
    
    // Sum using pointer arithmetic
    int sum = 0;
    for (int* p = start; p <= end; p++) {
        sum += *p;
    }
    cout << "Sum of elements: " << sum << endl;
}

void pointerComparisons() {
    int values[] = {5, 10, 15, 20, 25};
    int* p1 = values;
    int* p2 = values + 4;  // Point to last element
    
    cout << "\nPointer Comparisons:" << endl;
    cout << string(30, '-') << endl;
    
    cout << "Memory addresses:" << endl;
    cout << "p1: " << static_cast<void*>(p1) << endl;
    cout << "p2: " << static_cast<void*>(p2) << endl;
    
    cout << "\nComparisons:" << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "Elements between: " << (p2 - p1) << endl;
    
    // Find middle element
    int* middle = p1 + (p2 - p1) / 2;
    cout << "Middle element: " << *middle << endl;
}

void arrayBounds() {
    const int SIZE = 5;
    int numbers[SIZE] = {1, 2, 3, 4, 5};
    int* ptr = numbers;
    
    cout << "\nArray Bounds:" << endl;
    cout << string(30, '-') << endl;
    
    // Safe traversal
    cout << "Safe traversal:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Address: " << static_cast<void*>(ptr + i);
        cout << ", Value: " << *(ptr + i) << endl;
    }
    
    // Demonstrate bounds checking
    cout << "\nBounds checking:" << endl;
    int* start = numbers;
    int* end = numbers + SIZE - 1;
    
    cout << "First element: " << *start << endl;
    cout << "Last element: " << *end << endl;
    cout << "Array size: " << (end - start + 1) << endl;
}

void multiDimensional() {
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    cout << "\nMulti-dimensional Arrays:" << endl;
    cout << string(30, '-') << endl;
    
    // Using pointer arithmetic
    int* ptr = &matrix[0][0];
    
    cout << "Matrix traversal:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << *(ptr + i * 4 + j) << " ";
        }
        cout << endl;
    }
    
    // Row pointers
    cout << "\nRow-wise access:" << endl;
    for (int i = 0; i < 3; i++) {
        int* row = matrix[i];
        for (int j = 0; j < 4; j++) {
            cout << row[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    try {
        cout << "Pointer Arithmetic Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        basicArithmetic();
        arrayManipulation();
        pointerComparisons();
        arrayBounds();
        multiDimensional();
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
