#include "Student.h"
#include <iostream>

int main() {
    try {
        // Create a student with valid data
        Student student("AB123456", "John Smith", 20);
        std::cout << "Initial student information:\n" << student.getStudentInfo() << "\n";
        
        // Demonstrate setter methods with validation
        std::cout << "Testing setter methods with valid data:\n";
        student.setName("John Doe");
        student.setAge(21);
        student.setGPA(3.75);
        std::cout << student.getStudentInfo() << "\n";
        
        // Add some courses
        std::cout << "Adding courses:\n";
        student.addCourse("Mathematics");
        student.addCourse("Physics");
        student.addCourse("Computer Science");
        std::cout << student.getStudentInfo() << "\n";
        
        // Remove a course
        std::cout << "Removing Physics course:\n";
        if (student.removeCourse("Physics")) {
            std::cout << "Course removed successfully\n";
        }
        std::cout << student.getStudentInfo() << "\n";
        
        // Demonstrate validation in setter methods
        std::cout << "\nTesting setter methods with invalid data:\n";
        
        try {
            std::cout << "Trying to set invalid age (15)...\n";
            student.setAge(15);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        
        try {
            std::cout << "Trying to set invalid GPA (4.5)...\n";
            student.setGPA(4.5);
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        
        try {
            std::cout << "Trying to add duplicate course...\n";
            student.addCourse("Mathematics");
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        
        // Create student with invalid ID
        std::cout << "\nTrying to create student with invalid ID...\n";
        Student invalidStudent("12345678", "Jane Doe", 19);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
