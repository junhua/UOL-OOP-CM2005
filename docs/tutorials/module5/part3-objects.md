---
layout: default
title: Part 3 - Creating and Using Objects
nav_order: 3
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part3-objects/
---

# Part 3: Creating and Using Objects

## Overview
This part covers how to create and use objects in C++, including object instantiation, member access, and object lifecycle management.

## Object Creation

### Stack Objects
```cpp
class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void print() { cout << "(" << x << "," << y << ")" << endl; }
};

// Stack allocation
Point p1;          // Default constructor
Point p2(3, 4);    // Parameterized constructor
```

### Heap Objects
```cpp
// Heap allocation
Point* p3 = new Point();       // Default constructor
Point* p4 = new Point(5, 6);   // Parameterized constructor

// Don't forget to delete
delete p3;
delete p4;
```

## Object Access

### Direct Member Access
```cpp
class Rectangle {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getArea() {
        return width * height;
    }
    
    void scale(double factor) {
        width *= factor;
        height *= factor;
    }
};

// Using object directly
Rectangle rect(3.0, 4.0);
double area = rect.getArea();
rect.scale(2.0);
```

### Pointer Member Access
```cpp
// Using object through pointer
Rectangle* pRect = new Rectangle(3.0, 4.0);
double area = pRect->getArea();
pRect->scale(2.0);
delete pRect;
```

## Object Arrays

### Static Arrays
```cpp
// Array of objects
Point points[3] = {
    Point(1, 1),
    Point(2, 2),
    Point(3, 3)
};

// Accessing array elements
for (int i = 0; i < 3; i++) {
    points[i].print();
}
```

### Dynamic Arrays
```cpp
// Dynamic array of objects
Point* pointArray = new Point[3];
pointArray[0] = Point(1, 1);
pointArray[1] = Point(2, 2);
pointArray[2] = Point(3, 3);

// Don't forget to delete array
delete[] pointArray;
```

## Practice Exercise

Create a program that manages a collection of students:
1. Create Student class with name and grades
2. Implement array of students
3. Add methods for grade calculations
4. Demonstrate object lifecycle

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    vector<double> grades;
    
public:
    // Constructor
    Student(string n = "Unknown") : name(n) {}
    
    // Add a grade
    void addGrade(double grade) {
        if (grade >= 0 && grade <= 100) {
            grades.push_back(grade);
        }
    }
    
    // Calculate average
    double getAverage() const {
        if (grades.empty()) {
            return 0.0;
        }
        
        double sum = 0.0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
    
    // Get highest grade
    double getHighest() const {
        if (grades.empty()) {
            return 0.0;
        }
        
        double highest = grades[0];
        for (double grade : grades) {
            if (grade > highest) {
                highest = grade;
            }
        }
        return highest;
    }
    
    // Print student info
    void printInfo() const {
        cout << "Student: " << name << endl;
        cout << "Grades: ";
        for (double grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
        cout << "Average: " << getAverage() << endl;
        cout << "Highest: " << getHighest() << endl;
    }
};

class Classroom {
private:
    vector<Student> students;
    
public:
    // Add student
    void addStudent(const Student& student) {
        students.push_back(student);
    }
    
    // Get class average
    double getClassAverage() const {
        if (students.empty()) {
            return 0.0;
        }
        
        double sum = 0.0;
        for (const Student& student : students) {
            sum += student.getAverage();
        }
        return sum / students.size();
    }
    
    // Print class info
    void printClassInfo() const {
        cout << "\nClass Information:" << endl;
        cout << "==================" << endl;
        cout << "Number of students: " << students.size() << endl;
        cout << "Class average: " << getClassAverage() << endl;
        
        cout << "\nStudent Details:" << endl;
        cout << "================" << endl;
        for (const Student& student : students) {
            student.printInfo();
            cout << endl;
        }
    }
};

int main() {
    // Create classroom
    Classroom classroom;
    
    // Create and add students
    Student alice("Alice");
    alice.addGrade(85);
    alice.addGrade(92);
    alice.addGrade(88);
    classroom.addStudent(alice);
    
    Student bob("Bob");
    bob.addGrade(78);
    bob.addGrade(85);
    bob.addGrade(90);
    classroom.addStudent(bob);
    
    Student charlie("Charlie");
    charlie.addGrade(95);
    charlie.addGrade(88);
    charlie.addGrade(91);
    classroom.addStudent(charlie);
    
    // Print class information
    classroom.printClassInfo();
    
    return 0;
}
```

## Best Practices

### Object Creation
1. Prefer stack allocation
2. Use smart pointers for heap
3. Initialize all members
4. Consider object pools
5. Handle allocation failures

### Object Access
1. Use appropriate access methods
2. Consider const correctness
3. Validate input parameters
4. Handle error conditions
5. Document access patterns

### Object Management
1. Clean up resources properly
2. Use RAII pattern
3. Consider move semantics
4. Handle exceptions
5. Monitor object lifecycle

## Common Mistakes to Avoid
1. Memory leaks
2. Dangling pointers
3. Array deletion errors
4. Uninitialized objects
5. Resource management issues

## Next Steps
- Try the practice exercise
- Experiment with object creation
- Consider taking [Module 6: Core OOP Concepts - Encapsulation]({{ site.baseurl }}/tutorials/module6)
