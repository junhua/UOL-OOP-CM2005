#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 5: Function Overloading
 * Practice Exercise Starter Code
 * 
 * Task: Create a program that demonstrates function overloading with:
 * 1. Functions to find maximum of different types
 * 2. Functions to print different types of arrays
 * 3. Functions to format data in different ways
 */

// TODO: Implement findMax functions for:
// - Two integers
// - Two doubles
// - Two characters

// TODO: Implement printArray functions for:
// - Integer array
// - Double array
// - Character array

// TODO: Implement format functions for:
// - Integer (returns "Number: <value>")
// - Double with precision (returns "Value: <value>")
// - String with uppercase option (returns "Text: <value>")

int main() {
    // Test maximum functions
    cout << "Maximum tests:" << endl;
    // TODO: Test findMax with different types
    
    // Test array print functions
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    
    // TODO: Test printArray with different array types
    
    // Test format functions
    cout << "\nFormat tests:" << endl;
    // TODO: Test format with different types and options
    
    return 0;
}
