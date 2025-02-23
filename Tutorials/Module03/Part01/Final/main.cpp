#include <iostream>
using namespace std;

/**
 * Module 3 - Part 1: What are Functions?
 * Practice Exercise Solution
 * 
 * This program demonstrates three functions:
 * 1. printStars - prints a line of stars (*)
 * 2. findLarger - returns the larger of two numbers
 * 3. isEven - checks if a number is even
 */

// Function to print a line of stars
void printStars(int count) {
    for (int i = 0; i < count; i++) {
        cout << "*";
    }
    cout << endl;
}

// Function to return larger number
int findLarger(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Function to check if number is even
bool isEven(int number) {
    return number % 2 == 0;
}

int main() {
    // Test printStars function
    cout << "Printing 5 stars: ";
    printStars(5);
    
    // Test findLarger function
    int larger = findLarger(10, 20);
    cout << "Larger number is: " << larger << endl;
    
    // Test isEven function
    int testNumber = 7;
    if (isEven(testNumber)) {
        cout << testNumber << " is even" << endl;
    } else {
        cout << testNumber << " is odd" << endl;
    }
    
    return 0;
}
