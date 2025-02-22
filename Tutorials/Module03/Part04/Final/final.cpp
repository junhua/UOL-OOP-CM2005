#include <iostream>
#include <string>
using namespace std;

// Pass by value - original variable is not modified
void modifyValue(int x) {
    x += 10;  // Only modifies the local copy
    cout << "Inside modifyValue: " << x << endl;
    // When function ends, local copy is destroyed
}

// Pass by reference - original variable is modified
void modifyReference(int& x) {
    x += 10;  // Modifies the original variable
    cout << "Inside modifyReference: " << x << endl;
    // Changes persist after function ends
}

// Swap values using references
void swapValues(int& a, int& b) {
    int temp = a;  // Store first value
    a = b;         // Put second value in first variable
    b = temp;      // Put stored value in second variable
}

// Efficient string modification using reference
void modifyString(string& text) {
    text = "modified_" + text;  // Modifies original string
    // If this was pass by value, it would copy the entire string
}

int main() {
    cout << "Learning about call by value and call by reference!\n\n";
    
    // Test value vs reference with integers
    cout << "Testing with integers:\n";
    int num1 = 5;
    cout << "Original value: " << num1 << endl;
    
    modifyValue(num1);
    cout << "After modifyValue: " << num1 << " (unchanged)\n";
    
    modifyReference(num1);
    cout << "After modifyReference: " << num1 << " (changed)\n";
    
    // Test swapping values
    cout << "\nTesting swap function:\n";
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;
    
    // Test with strings
    cout << "\nTesting with strings:\n";
    string text = "Hello";
    cout << "Original string: " << text << endl;
    
    modifyString(text);
    cout << "After modifyString: " << text << endl;
    
    return 0;
}
