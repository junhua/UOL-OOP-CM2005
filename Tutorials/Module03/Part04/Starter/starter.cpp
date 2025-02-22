#include <iostream>
#include <string>
using namespace std;

// TODO: Create a function called 'modifyValue' that:
// - Takes an int parameter by value
// - Adds 10 to the parameter
// - Prints the modified value inside the function
// The original variable should remain unchanged


// TODO: Create a function called 'modifyReference' that:
// - Takes an int parameter by reference (using &)
// - Adds 10 to the parameter
// - Prints the modified value inside the function
// The original variable should be modified


// TODO: Create a function called 'swapValues' that:
// - Takes two int parameters by reference
// - Swaps their values using a temporary variable


// TODO: Create a function called 'modifyString' that:
// - Takes a string parameter by reference
// - Adds "modified_" to the beginning of the string
// This demonstrates why we use references for large objects (efficiency)


int main() {
    cout << "Learning about call by value and call by reference!\n\n";
    
    // Test value vs reference with integers
    cout << "Testing with integers:\n";
    int num1 = 5;
    cout << "Original value: " << num1 << endl;
    
    // TODO: Call modifyValue with num1
    // Print num1 after the call to show it's unchanged
    
    // TODO: Call modifyReference with num1
    // Print num1 after the call to show it's changed
    
    
    // Test swapping values
    cout << "\nTesting swap function:\n";
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    
    // TODO: Call swapValues with a and b
    // Print a and b after the call to show they're swapped
    
    
    // Test with strings
    cout << "\nTesting with strings:\n";
    string text = "Hello";
    cout << "Original string: " << text << endl;
    
    // TODO: Call modifyString with text
    // Print text after the call to show it's modified
    
    return 0;
}
