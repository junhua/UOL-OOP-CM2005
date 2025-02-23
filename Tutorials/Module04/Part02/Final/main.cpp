#include <iostream>
using namespace std;

/**
 * Module 4 - Part 2: Accessing Array Elements
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Array creation and initialization
 * 2. Element access and modification
 * 3. Array searching
 * 4. 2D array operations
 */

// Function to find element in array
int findElement(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to print 2D array
void print2DArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 1D array operations
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Print original array
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Modify elements
    numbers[2] = 35;  // Change 30 to 35
    
    // Print modified array
    cout << "Modified array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Search for elements
    int target = 40;
    int index = findElement(numbers, size, target);
    if (index != -1) {
        cout << target << " found at index " << index << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    // Test with element not in array
    target = 25;
    index = findElement(numbers, size, target);
    if (index != -1) {
        cout << target << " found at index " << index << endl;
    } else {
        cout << target << " not found" << endl;
    }
    
    // 2D array operations
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "\nOriginal 2D Array:" << endl;
    print2DArray(matrix, 2);
    
    // Modify 2D array elements
    matrix[1][1] = 10;  // Change 5 to 10
    matrix[0][2] = 8;   // Change 3 to 8
    
    cout << "\nModified 2D Array:" << endl;
    print2DArray(matrix, 2);
    
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "\nSum of all elements: " << sum << endl;
    
    // Calculate and print row sums
    cout << "\nRow sums:" << endl;
    for (int i = 0; i < 2; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += matrix[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }
    
    return 0;
}
