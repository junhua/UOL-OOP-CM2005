#include <iostream>
#include <string>
using namespace std;

// TODO: Create an overloaded function 'print' that:
// 1. Takes an int and displays it
// 2. Takes a double and displays it with 2 decimal places
// 3. Takes a string and displays it in quotes
// This shows basic overloading with different parameter types


// TODO: Create an overloaded function 'max' that:
// 1. Takes two ints and returns the larger one
// 2. Takes three ints and returns the largest one
// This shows overloading with different parameter counts


// TODO: Create an overloaded function 'formatText' that:
// 1. Takes a string and returns it in uppercase
// 2. Takes a string and int n, returns the string repeated n times
// 3. Takes two strings and returns them concatenated with a space
// This shows practical uses of overloading


int main() {
    cout << "Learning about function overloading!\n\n";
    
    // Test print with different types
    cout << "Testing print function:\n";
    // TODO: Call print with:
    // - integer (42)
    // - double (3.14159)
    // - string ("Hello")
    
    
    // Test max with different numbers of parameters
    cout << "\nTesting max function:\n";
    // TODO: Test max with:
    // - Two numbers (10, 20)
    // - Three numbers (10, 20, 15)
    
    
    // Test formatText with different parameters
    cout << "\nTesting formatText function:\n";
    // TODO: Test formatText with:
    // - Single string ("hello")
    // - String and number ("ha", 3)
    // - Two strings ("hello", "world")
    
    
    return 0;
}
