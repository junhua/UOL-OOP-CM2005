#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 5 - Part 3: Creating and Using Objects
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Class implementation with data and methods
 * 2. Object creation and management
 * 3. Collection of objects
 * 4. Object interaction
 */

class Student {
private:
    string name;
    vector<double> grades;
    
public:
    // Constructor
    Student(string n = "Unknown") : name(n) {
        cout << "Creating student: " << name << endl;
    }
    
    // Destructor
    ~Student() {
        cout << "Destroying student: " << name << endl;
    }
    
    // Add a grade
    void addGrade(double grade) {
        if (grade >= 0 && grade <= 100) {
            grades.push_back(grade);
            cout << "Added grade " << grade << " for " << name << endl;
        } else {
            cout << "Invalid grade: " << grade << endl;
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
    
    // Get name
    string getName() const {
        return name;
    }
    
    // Print student info
    void printInfo() const {
        cout << "Student: " << name << endl;
        cout << "Grades: ";
        for (double grade : grades) {
            cout << fixed << setprecision(1) << grade << " ";
        }
        cout << endl;
        cout << "Average: " << fixed << setprecision(2) << getAverage() << endl;
        cout << "Highest: " << getHighest() << endl;
    }
};

class Classroom {
private:
    vector<Student> students;
    string className;
    
public:
    // Constructor
    Classroom(string name = "Default Class") : className(name) {
        cout << "Creating classroom: " << className << endl;
    }
    
    // Destructor
    ~Classroom() {
        cout << "Destroying classroom: " << className << endl;
    }
    
    // Add student
    void addStudent(const Student& student) {
        students.push_back(student);
        cout << "Added " << student.getName() << " to " << className << endl;
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
    
    // Get highest class grade
    double getHighestClassGrade() const {
        if (students.empty()) {
            return 0.0;
        }
        
        double highest = 0.0;
        for (const Student& student : students) {
            double studentHighest = student.getHighest();
            if (studentHighest > highest) {
                highest = studentHighest;
            }
        }
        return highest;
    }
    
    // Print class info
    void printClassInfo() const {
        cout << "\nClass Information: " << className << endl;
        cout << "==================" << string(className.length(), '=') << endl;
        cout << "Number of students: " << students.size() << endl;
        cout << "Class average: " << fixed << setprecision(2) << getClassAverage() << endl;
        cout << "Highest grade: " << getHighestClassGrade() << endl;
        
        cout << "\nStudent Details:" << endl;
        cout << "================" << endl;
        for (const Student& student : students) {
            student.printInfo();
            cout << endl;
        }
    }
};

int main() {
    // Create a scope to demonstrate object lifecycle
    {
        cout << "Beginning student management demo" << endl;
        cout << "================================" << endl;
        
        // Create classroom
        Classroom classroom("C++ Programming 101");
        
        // Create and add students
        Student alice("Alice");
        alice.addGrade(85.5);
        alice.addGrade(92.0);
        alice.addGrade(88.5);
        classroom.addStudent(alice);
        
        Student bob("Bob");
        bob.addGrade(78.0);
        bob.addGrade(85.5);
        bob.addGrade(90.0);
        classroom.addStudent(bob);
        
        Student charlie("Charlie");
        charlie.addGrade(95.0);
        charlie.addGrade(88.5);
        charlie.addGrade(91.0);
        classroom.addStudent(charlie);
        
        // Test invalid grade
        charlie.addGrade(101.0);  // Should print error
        
        // Print class information
        classroom.printClassInfo();
        
        cout << "\nEnd of scope - objects will be destroyed" << endl;
        cout << "=======================================" << endl;
    }  // Objects destroyed here
    
    cout << "\nAll objects have been destroyed" << endl;
    return 0;
}
