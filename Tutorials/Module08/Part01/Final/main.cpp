#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
 * Module 8 - Part 1: Introduction to Polymorphism
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Runtime polymorphism
 * 2. Virtual functions
 * 3. Abstract classes
 * 4. Smart pointers
 */

// Abstract base class
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {
        cout << "Creating " << color << " shape" << endl;
    }
    
    virtual ~Shape() {
        cout << "Destroying " << color << " shape" << endl;
    }
    
    // Pure virtual methods
    virtual void draw() const = 0;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    
    // Virtual method with default implementation
    virtual void displayInfo() const {
        cout << "\nShape Information:" << endl;
        cout << "Color: " << color << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
    
    string getColor() const { return color; }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string color, double r) 
        : Shape(color), radius(r) {
        cout << "Creating circle with radius " << radius << endl;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle" << endl;
        // Simple ASCII art circle
        int size = static_cast<int>(radius * 2);
        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                double distance = sqrt(pow(i - radius, 2) + pow(j - radius, 2));
                cout << (distance <= radius ? "*" : " ");
            }
            cout << endl;
        }
    }
    
    double getArea() const override {
        return M_PI * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(string color, double w, double h)
        : Shape(color), width(w), height(h) {
        cout << "Creating rectangle " << width << "x" << height << endl;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " rectangle" << endl;
        // ASCII art rectangle
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
    
public:
    Triangle(string color, double b, double h)
        : Shape(color), base(b), height(h) {
        cout << "Creating triangle with base " << base << endl;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " triangle" << endl;
        // ASCII art triangle
        for (int i = 0; i < height; i++) {
            int stars = (i + 1) * (base / height);
            int spaces = (base - stars) / 2;
            cout << string(spaces, ' ') << string(stars, '*') << endl;
        }
    }
    
    double getArea() const override {
        return 0.5 * base * height;
    }
    
    double getPerimeter() const override {
        // Assuming isosceles triangle
        double side = sqrt(pow(base/2, 2) + pow(height, 2));
        return base + 2 * side;
    }
    
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }
};

class DrawingCanvas {
private:
    vector<Shape*> shapes;
    string canvasName;
    
public:
    DrawingCanvas(string name = "My Canvas") 
        : canvasName(name) {
        cout << "Creating canvas: " << canvasName << endl;
    }
    
    ~DrawingCanvas() {
        cout << "Destroying canvas: " << canvasName << endl;
        for (Shape* shape : shapes) {
            delete shape;
        }
    }
    
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }
    
    void drawAll() const {
        cout << "\nDrawing all shapes on " << canvasName << ":" << endl;
        cout << string(50, '=') << endl;
        
        for (const auto& shape : shapes) {
            shape->draw();
            shape->displayInfo();
            cout << string(50, '-') << endl;
        }
    }
    
    void showStats() const {
        cout << "\nCanvas Statistics:" << endl;
        cout << string(30, '=') << endl;
        cout << "Total shapes: " << shapes.size() << endl;
        cout << "Total area: " << getTotalArea() << endl;
    }
    
private:
    double getTotalArea() const {
        double total = 0;
        for (const auto& shape : shapes) {
            total += shape->getArea();
        }
        return total;
    }
};

int main() {
    try {
        // Create drawing canvas
        DrawingCanvas canvas("Polymorphism Demo");
        
        // Add different shapes
        cout << "\nAdding shapes to canvas:" << endl;
        cout << string(50, '-') << endl;
        
        canvas.addShape(new Circle("Red", 3));
        canvas.addShape(new Rectangle("Blue", 4, 3));
        canvas.addShape(new Triangle("Green", 5, 4));
        
        // Draw all shapes
        canvas.drawAll();
        
        // Show statistics
        canvas.showStats();
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
