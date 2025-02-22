// Module 10 - Part 03: Overloading Comparison Operators
// This tutorial demonstrates:
// 1. Overloading comparison operators (==, !=, <, >, <=, >=)
// 2. Implementing comparison logic for custom classes
// 3. Using overloaded comparison operators in conditional statements

#include <iostream>
#include "Temperature.h"

using namespace std;

int main() {
    // Create Temperature objects
    Temperature temp1(25.0, 'C');
    Temperature temp2(77.0, 'F'); // Equivalent to 25°C
    Temperature temp3(30.0, 'C');

    // Test equality and inequality operators
    cout << "Comparing temperatures:" << endl;
    cout << temp1 << " == " << temp2 << ": " << (temp1 == temp2) << endl;
    cout << temp1 << " != " << temp3 << ": " << (temp1 != temp3) << endl;

    // Test relational operators
    cout << "\nRelational comparisons:" << endl;
    cout << temp1 << " < " << temp3 << ": " << (temp1 < temp3) << endl;
    cout << temp1 << " > " << temp3 << ": " << (temp1 > temp3) << endl;
    cout << temp1 << " <= " << temp2 << ": " << (temp1 <= temp2) << endl;
    cout << temp1 << " >= " << temp3 << ": " << (temp1 >= temp3) << endl;

    // Using comparison operators in conditional statements
    if (temp1 == temp2) {
        cout << "\nTemperature 1 and Temperature 2 are the same temperature." << endl;
    } else {
        cout << "\nTemperature 1 and Temperature 2 are different temperatures." << endl;
    }

    if (temp1 < temp3) {
        cout << "\nTemperature 1 is colder than Temperature 3." << endl;
    } else {
        cout << "\nTemperature 1 is not colder than Temperature 3." << endl;
    }

    return 0;
}
