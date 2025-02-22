#include "Vector2D.h"
#include <stdexcept>

// Default constructor
Vector2D::Vector2D() : x(0.0), y(0.0) {}

// Parameterized constructor
Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

// Getter methods
double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

// Vector addition
Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

// Vector subtraction
Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

// Scalar multiplication (vector * scalar)
Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

// Scalar division
Vector2D Vector2D::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero");
    }
    return Vector2D(x / scalar, y / scalar);
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// Non-member scalar multiplication (scalar * vector)
Vector2D operator*(double scalar, const Vector2D& vec) {
    return vec * scalar;  // Reuse the member operator*
}
