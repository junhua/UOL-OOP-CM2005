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

    // Operator overloading
    Complex operator+(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif // COMPLEX_H
