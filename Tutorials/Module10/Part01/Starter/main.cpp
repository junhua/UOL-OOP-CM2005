// This tutorial demonstrates:
// 1. Basic usage of Complex class
// 2. Operator overloading for Complex numbers

#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    // Create Complex objects
    Complex c1(2, 3);
    Complex c2(1, -1);

    // Display complex numbers
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    // Add complex numbers using overloaded + operator
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    return 0;
}
