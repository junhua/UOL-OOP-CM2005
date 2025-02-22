// This tutorial demonstrates:
// 1. Abstract classes and pure virtual functions
// 2. How abstract classes serve as interfaces
// 3. The requirement to implement all pure virtual functions
// 4. Using abstract classes as base classes

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class Shape
class Shape {
protected:
    string name;

public:
    Shape(const string& n) : name(n) {}

    // Pure virtual functions
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    // Virtual display function
    virtual void display() const {
        cout << "Shape: " << name << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }

    // Virtual destructor
    virtual ~Shape() {
        cout << "Shape destructor called for " << name << endl;
    }

    // Non-virtual getName() function
    string getName() const {
        return name;
    }
};

// Concrete Rectangle class that inherits from Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(const string& n, double w, double h) 
        : Shape(n), width(w), height(h) {}

    // Implement pure virtual functions
    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }

    // Getter functions
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Concrete Circle class that inherits from Shape
class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;

public:
    Circle(const string& n, double r) : Shape(n), radius(r) {}

    // Implement pure virtual functions
    double calculateArea() const override {
        return PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }

    // Getter function
    double getRadius() const { return radius; }
};

// Abstract Drawable class
class Drawable {
public:
    virtual void draw() = 0;  // Pure virtual function
    virtual ~Drawable() = default; // Virtual destructor
};

// DrawableRectangle class that inherits from both Rectangle and Drawable
class DrawableRectangle : public Rectangle, public Drawable {
public:
    DrawableRectangle(const string& n, double w, double h)
        : Rectangle(n, w, h) {}

    // Implement draw() function
    void draw() override {
        cout << "Drawing " << getName() << " rectangle:" << endl;
        for (int i = 0; i < getHeight(); i++) {
            for (int j = 0; j < getWidth(); j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Try to create instance of Shape class - This should cause compilation error
    // Shape is an abstract class and cannot be instantiated directly
    // Shape shape("AbstractShape"); // This line would cause a compilation error

    // Create Rectangle and Circle objects
    Rectangle rectangle("Rectangle1", 4, 3);
    Circle circle("Circle1", 2.5);

    // Store shape pointers in vector and demonstrate polymorphism
    vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    cout << "Shape Information:" << endl;
    for (const auto& shape : shapes) {
        shape->display();
        cout << endl;
    }

    // Create DrawableRectangle and demonstrate multiple inheritance
    DrawableRectangle drawRect("DrawRect1", 5, 3);
    cout << "Drawable Rectangle Information:" << endl;
    drawRect.display();  // Call display() from Shape (inherited by Rectangle)
    cout << endl;
    drawRect.draw();     // Call draw() from Drawable

    return 0;
}
