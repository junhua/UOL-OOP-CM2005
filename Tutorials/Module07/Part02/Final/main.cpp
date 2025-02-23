#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Module 7 - Part 2: "is-a" Relationship
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Abstract base class implementation
 * 2. Inheritance relationships
 * 3. Method overriding
 * 4. Polymorphic behavior
 */

class Shape {
protected:
    string color;
    string name;
    
public:
    // Constructor
    Shape(string name, string color) 
        : name(name), color(color) {
        cout << "Creating " << color << " " << name << endl;
    }
    
    // Virtual destructor
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
    
    // Virtual method with default implementation
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
        : Shape("Circle", color), radius(r) {
        cout << "Setting radius to " << radius << endl;
    }
    
    double getArea() const override {
        return M_PI * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * M_PI * radius;
    }
    
    void draw() const override {
        cout << "Drawing " << color << " circle with radius " << radius << endl;
        // Draw circle using ASCII art
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
        : Shape("Rectangle", color), width(w), height(h) {
        cout << "Setting dimensions to " << width << "x" << height << endl;
    }
    
    double getArea() const override {
        return width * height;
    }
    
    double getPerimeter() const override {
        return 2 * (width + height);
    }
    
    void draw() const override {
        cout << "Drawing " << color << " rectangle " 
             << width << "x" << height << endl;
        // Draw rectangle using ASCII art
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
        : Shape("Triangle", color), base(b), height(h) {
        cout << "Setting base to " << base << " and height to " << height << endl;
    }
    
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
        // Draw triangle using ASCII art
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
    string collectionName;
    
public:
    ShapeCollection(string name = "My Shapes") : collectionName(name) {
        cout << "Creating shape collection: " << collectionName << endl;
    }
    
    ~ShapeCollection() {
        cout << "Destroying shape collection: " << collectionName << endl;
        for (Shape* shape : shapes) {
            delete shape;
        }
    }
    
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }
    
    void displayAllShapes() const {
        cout << "\nShape Collection: " << collectionName << endl;
        cout << string(50, '=') << endl;
        
        if (shapes.empty()) {
            cout << "No shapes in collection" << endl;
            return;
        }
        
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
    try {
        // Create shape collection
        ShapeCollection shapes("Geometric Shapes Demo");
        
        // Add various shapes
        cout << "\nCreating shapes:" << endl;
        cout << string(50, '-') << endl;
        
        shapes.addShape(new Circle("Red", 3));
        shapes.addShape(new Rectangle("Blue", 4, 3));
        shapes.addShape(new Triangle("Green", 5, 4));
        
        // Display all shapes
        shapes.displayAllShapes();
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
