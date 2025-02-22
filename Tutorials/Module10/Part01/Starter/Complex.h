#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructors
    Complex();
    Complex(double r, double i);

    // Getter methods
    double getReal() const;
    double getImag() const;

    // Declare the operator+ member function to add two Complex numbers
    // Hint: It should take a const reference parameter and return a Complex object
    Complex operator+(const Complex& other) const;

    // Declare the operator<< friend function for output stream
    // Hint: It should be declared as a friend function that takes an ostream reference and a const Complex reference
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif // COMPLEX_H
