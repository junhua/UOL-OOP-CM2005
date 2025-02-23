#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 4: Call by Value and Call by Reference
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Call by value (changes don't affect original)
 * 2. Call by reference (changes affect original)
 * 3. Const reference (efficient, read-only access)
 */

// Call by value example - changes don't affect original values
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: " << a << ", " << b << endl;
}

// Call by reference example - changes affect original values
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: " << a << ", " << b << endl;
}

// Const reference example - efficient access without copying
void printDetails(const string& str) {
    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;
}

// Function that modifies multiple values by reference
void getNameStats(const string& name, int& letters, int& vowels) {
    letters = name.length();
    vowels = 0;
    string vowelList = "aeiouAEIOU";
    
    for (char c : name) {
        if (vowelList.find(c) != string::npos) {
            vowels++;
        }
    }
}

int main() {
    // Test value vs reference swap
    int x = 5, y = 10;
    cout << "Original values: " << x << ", " << y << endl;
    
    swapByValue(x, y);
    cout << "After swapByValue: " << x << ", " << y << endl;
    
    swapByReference(x, y);
    cout << "After swapByReference: " << x << ", " << y << endl;
    
    // Test const reference
    string name = "John Smith";
    cout << "\nTesting const reference:" << endl;
    printDetails(name);
    
    // Test multiple reference parameters
    int letterCount, vowelCount;
    cout << "\nTesting multiple reference parameters:" << endl;
    getNameStats(name, letterCount, vowelCount);
    cout << "Name statistics:" << endl;
    cout << "Letters: " << letterCount << endl;
    cout << "Vowels: " << vowelCount << endl;
    
    return 0;
}
