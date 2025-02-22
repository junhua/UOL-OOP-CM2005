#include "Student.h"
#include <iostream>

int main() {
    try {
        // TODO: Test your Student class implementation
        
        // 1. Test constructor with valid data
        std::cout << "Creating student with valid data...\n";
        Student student("AB123456", "John Smith", 20);
        std::cout << student.getStudentInfo() << "\n\n";
        
        // TODO: Test setter methods with valid data
        std::cout << "Testing setters with valid data...\n";
        // Set a new name
        // Set a new age
        // Set a GPA
        // Print updated information
        
        // TODO: Test course management
        std::cout << "\nTesting course management...\n";
        // Add some courses
        // Try to add a duplicate course (should throw exception)
        // Remove a course
        // Try to remove a non-existent course
        // Print updated information
        
        // TODO: Test input validation
        std::cout << "\nTesting input validation...\n";
        // Try to set invalid age
        // Try to set invalid GPA
        // Try to add empty course name
        
        // TODO: Test constructor with invalid data
        std::cout << "\nTesting constructor with invalid data...\n";
        // Try to create student with invalid ID
        // Try to create student with invalid age
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
