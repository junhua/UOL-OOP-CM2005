#include "Student.h"
#include <stdexcept>
#include <algorithm>
#include <sstream>

Student::Student(const std::string& id, const std::string& studentName, int studentAge)
    : studentId(id), name(studentName), age(studentAge), gpa(0.0) {
    if (!isValidStudentId(id)) {
        throw std::invalid_argument("Invalid student ID format");
    }
    if (!isValidAge(studentAge)) {
        throw std::invalid_argument("Invalid age");
    }
}

bool Student::isValidStudentId(const std::string& id) const {
    // Student ID must be 8 characters: 2 letters followed by 6 digits
    if (id.length() != 8) return false;
    
    // First two characters must be letters
    if (!isalpha(id[0]) || !isalpha(id[1])) return false;
    
    // Remaining characters must be digits
    for (int i = 2; i < 8; i++) {
        if (!isdigit(id[i])) return false;
    }
    
    return true;
}

bool Student::isValidAge(int age) const {
    // Age must be between 16 and 120
    return age >= 16 && age <= 120;
}

bool Student::isValidGPA(double gpa) const {
    // GPA must be between 0.0 and 4.0
    return gpa >= 0.0 && gpa <= 4.0;
}

void Student::setName(const std::string& newName) {
    if (newName.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }
    name = newName;
}

void Student::setAge(int newAge) {
    if (!isValidAge(newAge)) {
        throw std::invalid_argument("Invalid age");
    }
    age = newAge;
}

void Student::setGPA(double newGPA) {
    if (!isValidGPA(newGPA)) {
        throw std::invalid_argument("Invalid GPA. Must be between 0.0 and 4.0");
    }
    gpa = newGPA;
}

void Student::addCourse(const std::string& course) {
    // Check if course is empty
    if (course.empty()) {
        throw std::invalid_argument("Course name cannot be empty");
    }
    
    // Check if course already exists
    if (std::find(courses.begin(), courses.end(), course) != courses.end()) {
        throw std::invalid_argument("Course already exists");
    }
    
    courses.push_back(course);
}

bool Student::removeCourse(const std::string& course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it);
        return true;
    }
    return false;
}

std::string Student::getStudentInfo() const {
    std::stringstream ss;
    ss << "Student ID: " << studentId << "\n"
       << "Name: " << name << "\n"
       << "Age: " << age << "\n"
       << "GPA: " << gpa << "\n"
       << "Courses:\n";
    
    if (courses.empty()) {
        ss << "  No courses registered\n";
    } else {
        for (const auto& course : courses) {
            ss << "  - " << course << "\n";
        }
    }
    
    return ss.str();
}
