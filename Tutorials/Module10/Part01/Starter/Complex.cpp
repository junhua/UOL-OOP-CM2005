#include "Complex.h"
#include <iostream>

using namespace std;

// Default constructor
Complex::Complex() : real(0.0), imag(0.0) {}

// Parameterized constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getter methods
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

/* Implement the operator+ member function
 * This function should:
 * 1. Take a const Complex reference as parameter
 * 2. Add the real parts and imaginary parts separately
 * 3. Return a new Complex object with the results
 * 
 * Example:
 * If this object is (a + bi) and parameter is (c + di)
 * Result should be ((a+c) + (b+d)i)
 */
Complex Complex::operator+(const Complex& other) const {
    double newReal = real + other.real;
    double newImag = imag + other.imag;
    return Complex(newReal, newImag);
}

/* Implement the operator<< friend function
 * This function should:
 * 1. Take an ostream reference and a const Complex reference
 * 2. Format the complex number as "a+bi" or "a-bi"
 * 3. Return the ostream reference
 * 
 * Example output formats:
 * 3+2i  (for 3 + 2i)
 * 1-4i  (for 1 - 4i)
 * -2+3i (for -2 + 3i)
 */
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.getReal();
    if (c.getImag() >= 0) {
        os << "+";
    }
    os << c.getImag() << "i";
    return os;
}
