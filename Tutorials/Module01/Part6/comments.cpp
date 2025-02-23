/**
 * @file comments.cpp
 * @brief Demonstrates proper code documentation, formatting, and naming conventions in C++
 * @author Tutorial Module 1
 * @date 2025-02-23
 * 
 * This program shows various types of comments, proper code formatting,
 * and naming conventions. It includes examples of function and class
 * documentation, as well as different comment styles.
 */

#include <iostream>
#include <string>

/**
 * @brief Calculates the area of a rectangle
 * @param length The length of the rectangle
 * @param width The width of the rectangle
 * @return The area of the rectangle
 * @warning Both parameters must be positive numbers
 */
double calculateRectangleArea(double length, double width) {
    return length * width;
}

/**
 * @class Student
 * @brief Represents a student entity with basic information
 * 
 * This class maintains student information including ID, name,
 * and grade. It provides methods to access and modify this data.
 * 
 * Example usage:
 * @code
 *     Student student(12345, "John Doe");
 *     student.setGrade(85.5);
 *     double grade = student.getGrade();
 * @endcode
 */
class Student {
private:
    // Member variables with clear, descriptive names
    int studentId;        ///< Unique identifier for the student
    std::string name;     ///< Full name of the student
    double grade;         ///< Student's grade (0-100)

public:
    // Constructor with initialization list
    Student(int id, const std::string& studentName) 
        : studentId(id), name(studentName), grade(0.0) {
    }

    // Accessor methods
    int getStudentId() const { return studentId; }
    std::string getName() const { return name; }
    double getGrade() const { return grade; }

    // Mutator method with validation
    void setGrade(double newGrade) {
        /* Multi-line comment example:
           Check if the new grade is within valid range
           before assigning it to the member variable */
        if (newGrade >= 0.0 && newGrade <= 100.0) {
            grade = newGrade;
        }
    }
};

int main() {
    // Constants using UPPER_SNAKE_CASE
    const double MAX_GRADE = 100.0;
    const int PASSING_GRADE = 50;

    // Variables using camelCase
    double rectangleLength = 5.0;
    double rectangleWidth = 3.0;

    // Calculate and display rectangle area
    double area = calculateRectangleArea(rectangleLength, rectangleWidth);
    std::cout << "Rectangle area: " << area << std::endl;

    // Create and use a Student object
    Student student(1001, "Jane Smith");
    student.setGrade(95.5);

    // Display student information with proper spacing and alignment
    std::cout << "\nStudent Information:\n"
              << "ID: " << student.getStudentId() << "\n"
              << "Name: " << student.getName() << "\n"
              << "Grade: " << student.getGrade() << "\n";

    // Demonstrate logical grouping of related operations
    {
        // Local scope for grade calculation
        double currentGrade = student.getGrade();
        bool isPassing = currentGrade >= PASSING_GRADE;
        
        std::cout << "\nGrade Status:\n"
                  << "Current Grade: " << currentGrade << "\n"
                  << "Passing: " << (isPassing ? "Yes" : "No") << "\n";
    }

    return 0;
}
