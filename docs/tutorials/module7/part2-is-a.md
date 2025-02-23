---
layout: default
title: Part 2 - "is-a" Relationship
nav_order: 2
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part2-is-a/
---

# Part 2: "is-a" Relationship

## Overview
The "is-a" relationship is a fundamental concept in inheritance where a derived class is a specialized version of its base class. This relationship helps in creating logical class hierarchies.

## Understanding "is-a"

### Basic Concept
```cpp
// Animal is the base class
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void makeSound() = 0;
    virtual void move() = 0;
};

// Dog "is-a" Animal
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}
    
    void makeSound() override {
        cout << name << " barks!" << endl;
    }
    
    void move() override {
        cout << name << " runs on four legs" << endl;
    }
};

// Bird "is-a" Animal
class Bird : public Animal {
private:
    double wingspan;
    
public:
    Bird(string n, int a, double w) : Animal(n, a), wingspan(w) {}
    
    void makeSound() override {
        cout << name << " chirps!" << endl;
    }
    
    void move() override {
        cout << name << " flies with " << wingspan << "m wingspan" << endl;
    }
};
```

### Proper Usage
```cpp
// Shape hierarchy demonstrating proper "is-a" relationships
class Shape {
protected:
    string color;
    
public:
    Shape(string c) : color(c) {}
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
};

// Circle "is-a" Shape
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string c, double r) : Shape(c), radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius << endl;
    }
};

// Rectangle "is-a" Shape
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(string c, double w, double h) 
        : Shape(c), width(w), height(h) {}
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "Drawing " << color << " rectangle " 
             << width << "x" << height << endl;
    }
};
```

## Practice Exercise

Create a shape hierarchy demonstrating "is-a" relationships:
1. Abstract Shape base class
2. Various concrete shapes
3. Common operations
4. Shape-specific behavior

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Abstract base class
class Shape {
protected:
    string color;
    string name;
    
public:
    Shape(string name, string color) 
        : name(name), color(color) {
        cout << "Creating " << color << " " << name << endl;
    }
    
    virtual ~Shape() {
        cout << "Destroying " << color << " " << name << endl;
    }
    
    // Pure virtual methods
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;
    
    // Common methods
    string getColor() const { return color; }
    string getName() const { return name; }
    
    virtual void displayInfo() const {
        cout << "\nShape Information:" << endl;
        cout << "=================" << endl;
        cout << "Type: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Perimeter: " << getPerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(string color, double r) 
        : Shape("Circle", color), radius(r) {}
    
    double getArea() const override {
        return M_PI * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius << endl;
        // Simulate circle drawing with ASCII art
        int size = static_cast<int>(radius * 2);
        for (int i = 0; i <= size; i++) {
            for (int j = 0; j <= size; j++) {
                double distance = sqrt(pow(i - radius, 2) + pow(j - radius, 2));
                cout << (distance <= radius ? "*" : " ");
            }
            cout << endl;
        }
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
        : Shape("Rectangle", color), width(w), height(h) {}
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "Drawing " << color << " rectangle " 
             << width << "x" << height << endl;
        // Draw rectangle with ASCII art
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << "*";
            }
            cout << endl;
        }
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
        : Shape("Triangle", color), base(b), height(h) {}
    
    double getArea() const override {
        return 0.5 * base * height;
    }
    
    double getPerimeter() const override {
        // Assuming isosceles triangle for simplicity
        double side = sqrt(pow(base/2, 2) + pow(height, 2));
        return base + 2 * side;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " triangle with base " 
             << base << " and height " << height << endl;
        // Draw triangle with ASCII art
        for (int i = 0; i < height; i++) {
            int stars = (i + 1) * (base / height);
            int spaces = (base - stars) / 2;
            cout << string(spaces, ' ') << string(stars, '*') << endl;
        }
    }
    
    void displayInfo() const override {
        Shape::displayInfo();
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }
};

class ShapeCollection {
private:
    vector<Shape*> shapes;
    
public:
    ~ShapeCollection() {
        for (Shape* shape : shapes) {
            delete shape;
        }
    }
    
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }
    
    void displayAllShapes() const {
        cout << "\nShape Collection:" << endl;
        cout << "=================" << endl;
        
        for (const Shape* shape : shapes) {
            shape->displayInfo();
            shape->draw();
            cout << string(40, '-') << endl;
        }
        
        cout << "\nCollection Summary:" << endl;
        cout << "Total Shapes: " << shapes.size() << endl;
        cout << "Total Area: " << getTotalArea() << endl;
    }
    
    double getTotalArea() const {
        double total = 0;
        for (const Shape* shape : shapes) {
            total += shape->getArea();
        }
        return total;
    }
};

int main() {
    ShapeCollection shapes;
    
    // Create various shapes
    shapes.addShape(new Circle("Red", 3));
    shapes.addShape(new Rectangle("Blue", 4, 3));
    shapes.addShape(new Triangle("Green", 5, 4));
    
    // Display all shapes
    shapes.displayAllShapes();
    
    return 0;
}
```

## Best Practices

### Inheritance Design
1. Use "is-a" test strictly
2. Keep inheritance logical
3. Consider alternatives
4. Document relationships
5. Use abstract classes

### Implementation
1. Override virtual methods
2. Initialize base properly
3. Use meaningful names
4. Consider composition
5. Test thoroughly

### Common Guidelines
1. Single responsibility
2. Open/closed principle
3. Liskov substitution
4. Interface segregation
5. Dependency inversion

## Common Mistakes to Avoid
1. Forced relationships
2. Deep hierarchies
3. Breaking LSP
4. Mixed abstractions
5. Tight coupling

## Next Steps
- Try the practice exercise
- Experiment with hierarchies
- Move on to [Part 3: Overriding Methods]({{ site.baseurl }}/tutorials/module7/part3-overriding)
