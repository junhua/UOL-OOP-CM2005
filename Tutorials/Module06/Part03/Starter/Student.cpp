#include "Student.h"
#include <stdexcept>
#include <algorithm>
#include <sstream>

// TODO: Implement the constructor
// 1. Use member initializer list to initialize all members
// 2. Validate the student ID and age using helper methods
// 3. Initialize GPA to 0.0
// 4. Throw std::invalid_argument with appropriate message if validation fails
Student::Student(const std::string& id, const std::string& studentName, int studentAge) {
    // Your implementation here
}

// TODO: Implement student ID validation
// Rules for a valid student ID:
// 1. Must be exactly 8 characters long
// 2. First two characters must be letters
// 3. Last six characters must be digits
bool Student::isValidStudentId(const std::string& id) const {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement age validation
// Rules for a valid age:
// 1. Must be between 16 and 120 (inclusive)
bool Student::isValidAge(int age) const {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement GPA validation
// Rules for a valid GPA:
// 1. Must be between 0.0 and 4.0 (inclusive)
bool Student::isValidGPA(double gpa) const {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement name setter
// Rules for a valid name:
// 1. Cannot be empty
void Student::setName(const std::string& newName) {
    // Your implementation here
}

// TODO: Implement age setter
// Use the isValidAge helper method
void Student::setAge(int newAge) {
    // Your implementation here
}

// TODO: Implement GPA setter
// Use the isValidGPA helper method
void Student::setGPA(double newGPA) {
    // Your implementation here
}

// TODO: Implement course addition
// Rules:
// 1. Course name cannot be empty
// 2. Cannot add duplicate courses
void Student::addCourse(const std::string& course) {
    // Your implementation here
}

// TODO: Implement course removal
// Return true if course was found and removed, false otherwise
bool Student::removeCourse(const std::string& course) {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement student info formatting
// Format the output as follows:
// Student ID: [id]
// Name: [name]
// Age: [age]
// GPA: [gpa]
// Courses:
//   - [course1]
//   - [course2]
//   ...
// If no courses are registered, show "No courses registered"
std::string Student::getStudentInfo() const {
    // Your implementation here
    return ""; // Placeholder return
}
