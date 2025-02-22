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
    // TODO: Add private access specifier and member variables
    // Member variables to add:
    // - studentId (string): Student's unique identifier
    // - name (string): Student's full name
    // - age (int): Student's age
    // - gpa (double): Student's Grade Point Average
    // - courses (vector<string>): List of enrolled courses
    std::string studentId;
    std::string name;
    int age;
    double gpa;
    std::vector<std::string> courses;
    
    // TODO: Add private helper methods for validation
    // These methods should be declared const as they don't modify the object
    bool isValidStudentId(const std::string& id) const;
    bool isValidAge(int age) const;
    bool isValidGPA(double gpa) const;

public:
    // Constructor
    Student(const std::string& id, const std::string& studentName, int studentAge);
    
    // TODO: Implement getter methods
    // Each getter should:
    // 1. Be declared const as they don't modify the object
    // 2. Return the corresponding member variable
    std::string getStudentId() const { return studentId; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getGPA() const { return gpa; }
    std::vector<std::string> getCourses() const { return courses; }
    
    // TODO: Implement setter methods with validation
    // Each setter should:
    // 1. Validate the input parameter
    // 2. Throw std::invalid_argument if validation fails
    // 3. Update the member variable if validation passes
    void setName(const std::string& newName);
    void setAge(int newAge);
    void setGPA(double newGPA);
    
    // TODO: Implement course management methods
    void addCourse(const std::string& course);
    bool removeCourse(const std::string& course);
    
    // TODO: Implement utility method
    std::string getStudentInfo() const;
};

#endif // STUDENT_H
