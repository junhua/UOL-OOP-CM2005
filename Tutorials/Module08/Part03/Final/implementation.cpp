// This tutorial demonstrates:
// 1. Abstract classes and pure virtual functions
// 2. How abstract classes serve as interfaces
// 3. The requirement to implement all pure virtual functions
// 4. Using abstract classes as base classes

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class for shapes
class Shape {
protected:
    string name;
    
public:
    Shape(const string& n) : name(n) {}
    
    // Pure virtual functions - must be implemented by derived classes
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    
    // Regular virtual function with implementation
    virtual void display() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
    
    // Virtual destructor
    virtual ~Shape() {
        cout << "Shape destructor called for " << name << endl;
    }
    
    // Non-virtual function
    string getName() const {
        return name;
    }
};

// Concrete class implementing Shape
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(const string& n, double w, double h) 
        : Shape(n), width(w), height(h) {}
    
    // Implementation of pure virtual functions
    virtual double calculateArea() override {
        return width * height;
    }
    
    virtual double calculatePerimeter() override {
        return 2 * (width + height);
    }
    
    // Additional functions specific to Rectangle
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Another concrete class implementing Shape
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;
    
public:
    Circle(const string& n, double r) 
        : Shape(n), radius(r) {}
    
    // Implementation of pure virtual functions
    virtual double calculateArea() override {
        return PI * radius * radius;
    }
    
    virtual double calculatePerimeter() override {
        return 2 * PI * radius;
    }
    
    // Additional functions specific to Circle
    double getRadius() const { return radius; }
};

// Abstract class for drawable shapes
class Drawable {
public:
    // Pure virtual function for drawing
    virtual void draw() = 0;
    
    // Virtual destructor
    virtual ~Drawable() {}
};

// Class implementing multiple abstract classes
class DrawableRectangle : public Rectangle, public Drawable {
public:
    DrawableRectangle(const string& n, double w, double h)
        : Rectangle(n, w, h) {}
    
    // Implementation of Drawable's pure virtual function
    virtual void draw() override {
        cout << "Drawing " << getName() << " rectangle:" << endl;
        for(int i = 0; i < getHeight(); i++) {
            for(int j = 0; j < getWidth(); j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Cannot create instance of abstract class
    // Shape shape("Generic"); // This would cause compilation error
    
    // Create concrete shape objects
    Rectangle rect("Rectangle1", 4.0, 3.0);
    Circle circle("Circle1", 2.5);
    
    // Use base class pointers
    vector<Shape*> shapes;
    shapes.push_back(&rect);
    shapes.push_back(&circle);
    
    // Demonstrate polymorphic behavior
    cout << "Shape Information:" << endl;
    for(Shape* shape : shapes) {
        shape->display();
        cout << endl;
    }
    
    // Demonstrate drawable rectangle
    DrawableRectangle drawRect("DrawRect1", 5, 3);
    cout << "Drawable Rectangle Information:" << endl;
    drawRect.display();
    cout << endl;
    
    // Draw the rectangle
    drawRect.draw();
    
    return 0;
}
