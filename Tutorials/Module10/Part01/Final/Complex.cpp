#include "Complex.h"

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

// Operator overloading for addition
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// Friend function to overload << operator for output
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    if (c.imag >= 0) {
        os << "+";
    }
    os << c.imag << "i";
    return os;
}
