---
layout: default
title: Part 1 - Introduction to Polymorphism
nav_order: 1
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part1-polymorphism/
---

# Part 1: Introduction to Polymorphism

## Overview
Polymorphism allows objects of different classes to be treated as objects of a common base class, enabling flexible and extensible code design.

## Types of Polymorphism

### Compile-time Polymorphism
```cpp
class Calculator {
public:
    // Function overloading
    int add(int a, int b) {
        return a + b;
    }
    
    double add(double a, double b) {
        return a + b;
    }
    
    string add(string a, string b) {
        return a + b;
    }
};
```

### Runtime Polymorphism
```cpp
class Shape {
public:
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    void draw() const override {
        cout << "Drawing circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() const override {
        return width * height;
    }
    
    void draw() const override {
        cout << "Drawing rectangle" << endl;
    }
};
```

## Practice Exercise

Create a drawing application demonstrating polymorphism:
1. Shape hierarchy with different shapes
2. Common interface for all shapes
3. Collection of shapes
4. Polymorphic behavior

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

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
    
    // Common methods
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
    vector<unique_ptr<Shape>> shapes;
    string canvasName;
    
public:
    DrawingCanvas(string name = "My Canvas") 
        : canvasName(name) {
        cout << "Creating canvas: " << canvasName << endl;
    }
    
    void addShape(unique_ptr<Shape> shape) {
        shapes.push_back(move(shape));
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
        DrawingCanvas canvas("Polymorphism Demo");
        
        // Create and add shapes
        canvas.addShape(make_unique<Circle>("Red", 3));
        canvas.addShape(make_unique<Rectangle>("Blue", 4, 3));
        canvas.addShape(make_unique<Triangle>("Green", 5, 4));
        
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
```

## Best Practices

### Virtual Functions
1. Use virtual destructors
2. Override keyword
3. Final when needed
4. Document behavior
5. Consider pure virtual

### Base Class Design
1. Common interface
2. Virtual destructor
3. Protected members
4. Pure virtual methods
5. Default implementations

### Derived Class Design
1. Override correctly
2. Call base methods
3. Follow LSP
4. Document changes
5. Test thoroughly

## Common Mistakes to Avoid
1. Missing virtual destructor
2. Slicing objects
3. Wrong override
4. Breaking LSP
5. Memory leaks

## Next Steps
- Try the practice exercise
- Experiment with polymorphism
- Move on to [Part 2: Virtual Functions]({{ site.baseurl }}/tutorials/module8/part2-virtual)
