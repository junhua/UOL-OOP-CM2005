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
    virtual double getArea() = 0;
    
    // Method to calculate perimeter - will be overridden by derived classes
    virtual double getPerimeter() = 0;
    
    // Method to display shape information
    void display() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

// Rectangle class that inherits from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& n, double w, double h) : Shape(n), width(w), height(h) {}

    double getArea() override {
        return width * height;
    }

    double getPerimeter() override {
        return 2 * (width + height);
    }
};

// Circle class that inherits from Shape
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;

public:
    Circle(const string& n, double r) : Shape(n), radius(r) {}

    double getArea() override {
        return PI * radius * radius;
    }

    double getPerimeter() override {
        return 2 * PI * radius;
    }
};

int main() {
    // Create instances of Rectangle and Circle with sample dimensions
    Shape* rectangle = new Rectangle("Rectangle", 4, 5);
    Shape* circle = new Circle("Circle", 3);

    // Display information about each shape using the display() method
    rectangle->display();
    cout << endl;
    circle->display();
    cout << endl;

    // Create an array of Shape pointers and demonstrate polymorphism
    // 1. Create array of Shape pointers containing addresses of your shapes
    Shape* shapes[2] = {rectangle, circle};
    // 2. Loop through array and call display() on each shape
    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        cout << endl;
    }

    delete rectangle;
    delete circle;

    return 0;
}
