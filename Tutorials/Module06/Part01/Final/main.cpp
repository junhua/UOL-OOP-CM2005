// This tutorial demonstrates:
// 1. Function templates
// 2. Template type parameters
// 3. Multiple template parameters
// 4. Template specialization

#include <iostream>
#include <string>
using namespace std;

// Generic function template for swapping values
// This template can work with any data type that supports assignment
template<typename T>
void swap_values(T& a, T& b) {
    T temp = a;  // Store first value in temporary variable
    a = b;       // Assign second value to first variable
    b = temp;    // Assign temporary (original first value) to second variable
}

// Generic function template for finding maximum value
// This template can work with any data type that supports the > operator
template<typename T>
T find_max(T a, T b) {
    return (a > b) ? a : b;  // Return larger value using ternary operator
}

// Template with multiple parameters
// This template demonstrates using two different type parameters
template<typename T, typename U>
void print_pair(T a, U b) {
    cout << "Pair: " << a << ", " << b << endl;
}

// Template specialization for string comparison
// This specialization provides different behavior for strings
template<>
string find_max<string>(string a, string b) {
    return (a.length() > b.length()) ? a : b;  // Compare by length instead of lexicographical order
}

int main() {
    // Test with integers
    int num1 = 5, num2 = 10;
    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    swap_values(num1, num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    
    // Test with doubles
    double d1 = 3.14, d2 = 2.718;
    cout << "Maximum of " << d1 << " and " << d2 << " is: " << find_max(d1, d2) << endl;
    
    // Test with strings
    string s1 = "hello", s2 = "world!";
    cout << "Longer string between '" << s1 << "' and '" << s2 << "' is: " << find_max(s1, s2) << endl;
    
    // Test multiple parameter template
    print_pair(42, "answer");
    print_pair(3.14, 'π');
    
    return 0;
}
