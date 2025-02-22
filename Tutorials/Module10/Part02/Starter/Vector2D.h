#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructors
    Vector2D();
    Vector2D(double x, double y);

    // Getter methods
    double getX() const;
    double getY() const;

    // Declare arithmetic operator overloading functions
    // 1. operator+ for vector addition (v1 + v2)
    // 2. operator- for vector subtraction (v1 - v2)
    // 3. operator* for scalar multiplication (v * scalar)
    // 4. operator/ for scalar division (v / scalar)
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    // Declare the friend operator<< for output stream
    // Hint: Should be declared as a friend function that takes an ostream reference and a const Vector2D reference
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);

    // Declare the non-member operator* for scalar multiplication (scalar * v)
    // Hint: This allows expressions like 2.0 * vector
    friend Vector2D operator*(double scalar, const Vector2D& v);
};

#endif // VECTOR2D_H
