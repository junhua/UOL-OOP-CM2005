// Module 09 - Part 02: Pointer Arithmetic
// This tutorial demonstrates:
// 1. Basic pointer arithmetic operations
// 2. Array traversal using pointer arithmetic
// 3. Relationship between arrays and pointers
// 4. Pointer arithmetic with different data types

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Create a game inventory (string array)
    string inventory[] = {"Sword", "Shield", "Potion", "Map", "Torch"};
    int numItems = sizeof(inventory) / sizeof(inventory[0]);

    // Create a pointer to the first element of the array
    string* itemPtr = inventory;

    // Print array elements using array indexing
    cout << "Game Inventory (Array Indexing):\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ": " << inventory[i] << endl;
    }

    // Print array elements using pointer arithmetic
    cout << "\nGame Inventory (Pointer Arithmetic):\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << ": Address: " << itemPtr << ", Value: " << *itemPtr << endl;
        itemPtr++; // Move the pointer to the next item
    }

    // Create a pointer to the last element and traverse backwards
    string* lastItemPtr = inventory + numItems - 1; // Point to the last element

    cout << "\nGame Inventory (Reverse Order):\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << numItems - i << ": Address: " << lastItemPtr << ", Value: " << *lastItemPtr << endl;
        lastItemPtr--; // Move the pointer to the previous item
    }

    // Demonstrate pointer arithmetic with different data types
    double healthValues[] = {100.0, 75.5, 90.0, 60.2, 82.7};
    double* healthPtr = healthValues;
    cout << "\nSize of double: " << sizeof(double) << " bytes\n";
    cout << "Address of first health value: " << &healthValues[0] << endl;
    cout << "Address of second health value: " << &healthValues[1] << endl;
    cout << "Difference between addresses: " << (char*)(&healthValues[1]) - (char*)(&healthValues[0]) << " bytes\n";

    // Show pointer arithmetic with array indexing
    cout << "\nArray Indexing vs Pointer Arithmetic:\n";
    cout << "Item 1 (Array Indexing): " << inventory[0] << endl;
    cout << "Item 1 (Pointer Arithmetic): " << *(inventory + 0) << endl;

    return 0;
}
