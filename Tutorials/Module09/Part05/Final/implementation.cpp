// Module 09 - Part 05: Pointers and Arrays
// This tutorial demonstrates:
// 1. Relationship between arrays and pointers
// 2. Array traversal using pointers
// 3. Pointer arithmetic with arrays
// 4. Multidimensional arrays and pointers

#include <iostream>
using namespace std;

// Print array using pointer arithmetic
void printArray(int* arr, int size) {
    cout << "Array elements: ";
    for(int* ptr = arr; ptr < arr + size; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;
}

// Calculate sum using pointer arithmetic
int arraySum(int* arr, int size) {
    int sum = 0;
    int* end = arr + size;  // Point to one past the last element
    
    for(int* ptr = arr; ptr < end; ptr++) {
        sum += *ptr;
    }
    return sum;
}

// Reverse array using two pointers
void reverseArray(int* arr, int size) {
    int* start = arr;
    int* end = arr + size - 1;
    
    cout << "Reversing array..." << endl;
    while(start < end) {
        // Swap elements
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Move pointers
        start++;
        end--;
    }
}

// Demonstrate working with 2D arrays using pointer arithmetic
void process2DArray(int rows, int cols) {
    cout << "\nWorking with 2D array (" << rows << "x" << cols << "):" << endl;
    
    // Allocate 2D array
    int** array2D = new int*[rows];
    for(int i = 0; i < rows; i++) {
        array2D[i] = new int[cols];
    }
    
    // Initialize array with values
    cout << "Initializing 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(*(array2D + i) + j) = i * cols + j;  // Using pointer arithmetic
            cout << *(*(array2D + i) + j) << "\t";
        }
        cout << endl;
    }
    
    // Calculate sum using pointer arithmetic
    int sum = 0;
    for(int** row = array2D; row < array2D + rows; row++) {
        for(int* col = *row; col < *row + cols; col++) {
            sum += *col;
        }
    }
    cout << "Sum of all elements: " << sum << endl;
    
    // Free memory
    for(int i = 0; i < rows; i++) {
        delete[] array2D[i];
    }
    delete[] array2D;
}

// Demonstrate array of pointers
void arrayOfPointers() {
    const int SIZE = 5;
    cout << "\nDemonstrating array of pointers:" << endl;
    
    // Create array of pointers
    int** ptrArray = new int*[SIZE];
    
    // Allocate and initialize memory for each pointer
    for(int i = 0; i < SIZE; i++) {
        ptrArray[i] = new int(i * 10);
        cout << "ptrArray[" << i << "] points to value: " << *ptrArray[i] << endl;
    }
    
    // Modify values through pointers
    cout << "\nModifying values through pointers:" << endl;
    for(int i = 0; i < SIZE; i++) {
        *ptrArray[i] *= 2;
        cout << "New value at ptrArray[" << i << "]: " << *ptrArray[i] << endl;
    }
    
    // Clean up memory
    for(int i = 0; i < SIZE; i++) {
        delete ptrArray[i];
    }
    delete[] ptrArray;
}

int main() {
    // Create and initialize array
    int numbers[] = {10, 20, 30, 40, 50};
    const int SIZE = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "1. Basic array operations with pointers:" << endl;
    
    // Create pointer to array
    int* ptr = numbers;  // Equivalent to: int* ptr = &numbers[0];
    
    // Demonstrate array traversal using pointer arithmetic
    cout << "Traversing array using pointer arithmetic:" << endl;
    for(int i = 0; i < SIZE; i++) {
        cout << "*(ptr + " << i << ") = " << *(ptr + i)
             << " is same as numbers[" << i << "] = " << numbers[i] << endl;
    }
    
    // Print array using our function
    cout << "\n2. Using printArray function:" << endl;
    printArray(numbers, SIZE);
    
    // Calculate and display sum
    cout << "\n3. Using arraySum function:" << endl;
    int sum = arraySum(numbers, SIZE);
    cout << "Sum of array elements: " << sum << endl;
    
    // Reverse and display array
    cout << "\n4. Using reverseArray function:" << endl;
    cout << "Original array: ";
    printArray(numbers, SIZE);
    
    reverseArray(numbers, SIZE);
    cout << "Reversed array: ";
    printArray(numbers, SIZE);
    
    // Work with 2D arrays
    cout << "\n5. Working with 2D arrays:" << endl;
    process2DArray(3, 4);  // 3x4 array
    
    // Demonstrate array of pointers
    cout << "\n6. Array of pointers:" << endl;
    arrayOfPointers();
    
    cout << "\nAll array and pointer operations completed successfully" << endl;
    return 0;
}
