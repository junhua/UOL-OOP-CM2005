// This tutorial demonstrates:
// 1. Function overriding (runtime polymorphism)
// 2. How derived class can provide its own implementation of base class methods
// 3. The importance of matching function signatures exactly

#include <iostream>
#include <string>
using namespace std;

// Base class representing a generic shape
class Shape {
protected:
    string name;
    
public:
    Shape(const string& n) : name(n) {}
    
    // Method to calculate area - will be overridden by derived classes
    double getArea() {
        return 0.0;  // Base class provides a default implementation
    }
    
    // Method to calculate perimeter - will be overridden by derived classes
    double getPerimeter() {
        return 0.0;  // Base class provides a default implementation
    }
    
    // Method to display shape information
    void display() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

// Derived class for rectangles
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) 
        : Shape("Rectangle"), width(w), height(h) {}
    
    // Override getArea() to provide rectangle-specific implementation
    double getArea() {
        return width * height;
    }
    
    // Override getPerimeter() to provide rectangle-specific implementation
    double getPerimeter() {
        return 2 * (width + height);
    }
};

// Derived class for circles
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
    
public:
    Circle(double r) 
        : Shape("Circle"), radius(r) {}
    
    // Override getArea() to provide circle-specific implementation
    double getArea() {
        return PI * radius * radius;
    }
    
    // Override getPerimeter() to provide circle-specific implementation
    double getPerimeter() {
        return 2 * PI * radius;
    }
};

int main() {
    // Create instances of different shapes
    Rectangle rect(5.0, 3.0);
    Circle circle(2.5);
    
    // Display information about each shape
    cout << "Rectangle Information:" << endl;
    rect.display();
    cout << endl;
    
    cout << "Circle Information:" << endl;
    circle.display();
    cout << endl;
    
    // Demonstrate using base class pointer
    Shape* shapes[] = {&rect, &circle};
    
    cout << "Using base class pointers:" << endl;
    for(Shape* shape : shapes) {
        shape->display();
        cout << endl;
    }
    
    return 0;
}
