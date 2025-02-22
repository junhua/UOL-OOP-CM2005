// This tutorial demonstrates:
// 1. Getter methods for controlled access to private data
// 2. Setter methods with validation
// 3. Const correctness in getter methods
// 4. Proper encapsulation through getters and setters

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string studentId;
    std::string name;
    int age;
    double gpa;
    std::vector<std::string> courses;
    
    // Private helper methods
    bool isValidStudentId(const std::string& id) const;
    bool isValidAge(int age) const;
    bool isValidGPA(double gpa) const;

public:
    // Constructor
    Student(const std::string& id, const std::string& studentName, int studentAge);
    
    // Getter methods - note the const keyword
    std::string getStudentId() const { return studentId; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getGPA() const { return gpa; }
    std::vector<std::string> getCourses() const { return courses; }
    
    // Setter methods with validation
    void setName(const std::string& newName);
    void setAge(int newAge);
    void setGPA(double newGPA);
    void addCourse(const std::string& course);
    bool removeCourse(const std::string& course);
    
    // Utility method
    std::string getStudentInfo() const;
};

#endif // STUDENT_H
