#include "Vector2D.h"
#include <stdexcept>
#include <iostream>

using namespace std;

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

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    if (scalar == 0.0) {
        throw std::invalid_argument("Division by zero!");
    }
    return Vector2D(x / scalar, y / scalar);
}

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << ", " << v.getY() << ")";
    return os;
}

Vector2D operator*(double scalar, const Vector2D& v) {
    return v * scalar;
}
