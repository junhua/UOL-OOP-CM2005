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

    // Arithmetic operator overloading
    Vector2D operator+(const Vector2D& other) const;  // Vector addition
    Vector2D operator-(const Vector2D& other) const;  // Vector subtraction
    Vector2D operator*(double scalar) const;          // Scalar multiplication
    Vector2D operator/(double scalar) const;          // Scalar division

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Non-member operator overload for scalar * vector
Vector2D operator*(double scalar, const Vector2D& vec);

#endif // VECTOR2D_H
