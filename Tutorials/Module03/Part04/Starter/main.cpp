#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 4: Call by Value and Call by Reference
 * Practice Exercise Starter Code
 * 
 * Task: Create a program that demonstrates different parameter passing methods:
 * 1. Function using call by value
 * 2. Function using call by reference
 * 3. Function using const reference
 */

// TODO: Implement swapByValue function
// Parameters: two integers passed by value
// Should attempt to swap values (but won't affect originals)

// TODO: Implement swapByReference function
// Parameters: two integers passed by reference
// Should successfully swap the original values

// TODO: Implement printDetails function
// Parameter: string passed by const reference
// Should print the string and its length

// TODO: Implement getNameStats function
// Parameters:
// - name: string passed by const reference
// - letters: int passed by reference (for total letters)
// - vowels: int passed by reference (for vowel count)
// Should count total letters and vowels in the name

int main() {
    // Test value vs reference swap
    int x = 5, y = 10;
    cout << "Original values: " << x << ", " << y << endl;
    
    // TODO: Test swapByValue
    
    // TODO: Test swapByReference
    
    // Test const reference
    string name = "John Smith";
    // TODO: Test printDetails
    
    // Test multiple reference parameters
    int letterCount, vowelCount;
    // TODO: Test getNameStats
    
    return 0;
}
