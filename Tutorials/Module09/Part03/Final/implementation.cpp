// Module 09 - Part 03: Dynamic Memory Allocation
// This tutorial demonstrates:
// 1. Using new and delete operators
// 2. Dynamic array allocation and deallocation
// 3. Proper memory management practices
// 4. Common pitfalls to avoid

#include <iostream>
using namespace std;

// Function to demonstrate dynamic allocation of a single integer
void allocateSingleInteger() {
    cout << "Allocating a single integer:" << endl;
    
    // Dynamically allocate an integer
    int* ptr = new int;  // Allocate memory
    *ptr = 42;           // Initialize the integer
    
    cout << "Value stored: " << *ptr << endl;
    cout << "Memory address: " << ptr << endl;
    
    // Always delete dynamically allocated memory when done
    delete ptr;          // Free the allocated memory
    ptr = nullptr;       // Good practice: set pointer to nullptr after deletion
    
    cout << "Memory has been freed" << endl;
}

// Function to demonstrate dynamic array allocation
void allocateIntegerArray() {
    cout << "Enter array size: ";
    int size;
    cin >> size;
    
    // Dynamically allocate an array
    int* arr = new int[size];  // Allocate array of specified size
    
    // Initialize array elements
    cout << "Initializing array elements..." << endl;
    for(int i = 0; i < size; i++) {
        arr[i] = i * 10;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    
    // Use array notation or pointer arithmetic to access elements
    cout << "\nAccessing elements using pointer arithmetic:" << endl;
    for(int i = 0; i < size; i++) {
        cout << "*(arr + " << i << ") = " << *(arr + i) << endl;
    }
    
    // Delete array using delete[]
    delete[] arr;  // Must use delete[] for arrays
    arr = nullptr;
    
    cout << "Array has been freed" << endl;
}

// Function to demonstrate common mistakes to avoid
void demonstrateCommonMistakes() {
    cout << "Common mistakes and how to avoid them:" << endl;
    
    // 1. Memory leak - forgetting to delete
    cout << "\n1. Avoiding memory leaks:" << endl;
    int* ptr1 = new int(5);
    cout << "Memory allocated for ptr1" << endl;
    // Correct: Always delete when done
    delete ptr1;
    ptr1 = nullptr;
    cout << "Memory freed and pointer set to nullptr" << endl;
    
    // 2. Using wrong delete operator
    cout << "\n2. Using correct delete operator:" << endl;
    int* arr = new int[5];
    cout << "Array allocated" << endl;
    // Correct: Use delete[] for arrays
    delete[] arr;
    arr = nullptr;
    cout << "Array freed using delete[]" << endl;
    
    // 3. Dangling pointer
    cout << "\n3. Avoiding dangling pointers:" << endl;
    int* ptr2 = new int(10);
    delete ptr2;      // Memory is freed
    ptr2 = nullptr;   // Correct: Set to nullptr after deletion
    if(ptr2 == nullptr) {
        cout << "Pointer is null - safe to check before using" << endl;
    }
    
    // 4. Double deletion
    cout << "\n4. Avoiding double deletion:" << endl;
    int* ptr3 = new int(15);
    delete ptr3;      // First deletion
    ptr3 = nullptr;   // Set to nullptr
    // Correct: Check before deleting
    if(ptr3 != nullptr) {
        delete ptr3;  // Won't execute because ptr3 is nullptr
    }
    cout << "Avoided double deletion by checking for nullptr" << endl;
}

// Function to demonstrate dynamic allocation of 2D array
void allocate2DArray() {
    int rows = 3;
    int cols = 4;
    
    cout << "Creating a " << rows << "x" << cols << " 2D array:" << endl;
    
    // Allocate array of pointers (rows)
    int** array2D = new int*[rows];
    
    // Allocate each row
    for(int i = 0; i < rows; i++) {
        array2D[i] = new int[cols];
    }
    
    // Initialize and print the 2D array
    cout << "\nInitializing and printing 2D array:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array2D[i][j] = i * cols + j;
            cout << array2D[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Proper deallocation of 2D array
    cout << "\nDeallocating 2D array:" << endl;
    
    // First delete each row
    for(int i = 0; i < rows; i++) {
        delete[] array2D[i];
        array2D[i] = nullptr;
    }
    
    // Then delete the array of pointers
    delete[] array2D;
    array2D = nullptr;
    
    cout << "2D array has been freed" << endl;
}

int main() {
    cout << "1. Single Integer Allocation:" << endl;
    allocateSingleInteger();
    
    cout << "\n2. Integer Array Allocation:" << endl;
    allocateIntegerArray();
    
    cout << "\n3. Common Mistakes Demonstration:" << endl;
    demonstrateCommonMistakes();
    
    cout << "\n4. 2D Array Allocation:" << endl;
    allocate2DArray();
    
    return 0;
}
