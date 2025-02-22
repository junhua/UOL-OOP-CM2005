// Module 09 - Part 05: Pointers and Arrays
// This tutorial demonstrates:
// 1. Relationship between arrays and pointers
// 2. Array traversal using pointers
// 3. Pointer arithmetic with arrays
// 4. Multidimensional arrays and pointers

#include <iostream>
#include <string>
using namespace std;

// Function to print array using pointer arithmetic
void printArray(string* arr, int size) {
    cout << "Inventory: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

// Function to find sum of array elements using pointers
int arraySum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

// Function to reverse array using pointers
void reverseArray(string* arr, int size) {
    string* start = arr;
    string* end = arr + size - 1;
    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

// Function to work with 2D array using pointer arithmetic
void process2DArray(int rows, int cols) {
    // 1. Allocate 2D array dynamically
    int** map = new int*[rows];
    for (int i = 0; i < rows; i++) {
        map[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            map[i][j] = i * cols + j; // Initialize elements
        }
    }

    // 2. Print array using pointer arithmetic
    cout << "2D Map:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(map + i) + j) << " ";
        }
        cout << endl;
    }

    // 3. Free memory
    for (int i = 0; i < rows; i++) {
        delete[] map[i];
    }
    delete[] map;
}

// Function to demonstrate array of pointers
void arrayOfPointers() {
    // 1. Create array of pointers
    string* inventory[] = {new string("Sword"), new string("Shield"), new string("Potion")};
    int numItems = sizeof(inventory) / sizeof(inventory[0]);

    // 2. Use the array of pointers
    cout << "Items:\n";
    for (int i = 0; i < numItems; i++) {
        cout << *inventory[i] << endl;
    }

    // 3. Clean up memory
    for (int i = 0; i < numItems; i++) {
        delete inventory[i];
    }
}

int main() {
    // Create and initialize a regular array
    string inventory[] = {"Sword", "Shield", "Potion", "Map"};
    int numItems = sizeof(inventory) / sizeof(inventory[0]);

    // Create pointer to array
    string* itemPtr = inventory;

    // Demonstrate array traversal using pointer arithmetic
    cout << "Inventory (Pointer Arithmetic):\n";
    for (int i = 0; i < numItems; i++) {
        cout << *(itemPtr + i) << " ";
    }
    cout << endl;

    // Call printArray function
    cout << "Inventory (Function Call):\n";
    printArray(inventory, numItems);

    // Call arraySum function and display result
    int scores[] = {10, 20, 30, 40, 50};
    int numScores = sizeof(scores) / sizeof(scores[0]);
    cout << "Sum of scores: " << arraySum(scores, numScores) << endl;

    // Call reverseArray function and show result
    reverseArray(inventory, numItems);
    cout << "Reversed Inventory:\n";
    printArray(inventory, numItems);

    // Work with 2D arrays
    cout << "\nProcessing 2D Array:\n";
    process2DArray(3, 4);

    // Demonstrate array of pointers
    cout << "\nArray of Pointers:\n";
    arrayOfPointers();

    return 0;
}
