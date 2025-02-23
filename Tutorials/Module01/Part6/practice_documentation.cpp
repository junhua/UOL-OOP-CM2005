/**
 * @file practice_documentation.cpp
 * @brief Demonstrates proper code documentation and organization in C++
 * @author Tutorial Module 1
 * @date 2025-02-23
 * 
 * This program shows various documentation techniques including:
 * - File-level documentation
 * - Function documentation
 * - Class documentation
 * - Member variable and method documentation
 * - Different types of comments and their appropriate usage
 */

#include <iostream>
#include <string>

/**
 * @brief Calculates the grade percentage and returns the corresponding letter grade
 * @param totalPoints The total points earned by the student
 * @param maxPoints The maximum possible points
 * @return The letter grade (A, B, C, D, or F)
 * @throw None
 * 
 * This function calculates the percentage score and converts it to a letter grade
 * using the following scale:
 * - A: 90-100%
 * - B: 80-89%
 * - C: 70-79%
 * - D: 60-69%
 * - F: Below 60%
 */
char calculateGrade(double totalPoints, double maxPoints) {
    // Calculate percentage
    double percentage = (totalPoints / maxPoints) * 100;
    
    // Determine letter grade
    if (percentage >= 90) return 'A';
    if (percentage >= 80) return 'B';
    if (percentage >= 70) return 'C';
    if (percentage >= 60) return 'D';
    return 'F';
}

/**
 * @class Student
 * @brief Represents a student with their academic information
 * 
 * This class maintains a student's personal and academic information,
 * including their name, ID, and grades. It provides methods to
 * update and retrieve this information.
 * 
 * Example usage:
 * @code
 *     Student student("John Doe", 12345);
 *     student.addGrade(95.5);
 *     double avg = student.getAverageGrade();
 *     char letterGrade = student.getLetterGrade();
 * @endcode
 */
class Student {
private:
    std::string name;        ///< Student's full name
    int studentId;           ///< Unique identifier for the student
    double totalPoints;      ///< Sum of all grades
    int gradeCount;          ///< Number of grades entered
    static const double MAX_POINTS = 100.0;  ///< Maximum points per grade

public:
    /**
     * @brief Constructs a new Student object
     * @param studentName The full name of the student
     * @param id The student's ID number
     */
    Student(const std::string& studentName, int id)
        : name(studentName), studentId(id), totalPoints(0), gradeCount(0) {
    }

    /**
     * @brief Adds a new grade for the student
     * @param points The points earned (0-100)
     * @return true if grade was added successfully, false otherwise
     */
    bool addGrade(double points) {
        if (points >= 0 && points <= MAX_POINTS) {
            totalPoints += points;
            gradeCount++;
            return true;
        }
        return false;
    }

    /**
     * @brief Calculates the student's average grade
     * @return The average grade, or 0 if no grades have been entered
     */
    double getAverageGrade() const {
        return gradeCount > 0 ? totalPoints / gradeCount : 0;
    }

    /**
     * @brief Gets the student's letter grade based on their average
     * @return The letter grade (A, B, C, D, or F)
     */
    char getLetterGrade() const {
        return calculateGrade(getAverageGrade(), MAX_POINTS);
    }

    // Accessor methods
    std::string getName() const { return name; }
    int getStudentId() const { return studentId; }
};

int main() {
    // Create a student object
    Student student("Jane Smith", 12345);

    /* Add some test grades
       These grades will be used to calculate the average
       and determine the final letter grade */
    student.addGrade(95.5);  // First test
    student.addGrade(87.0);  // Second test
    student.addGrade(91.5);  // Third test

    // Display student information
    std::cout << "Student Information:\n";
    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "ID: " << student.getStudentId() << std::endl;
    std::cout << "Average Grade: " << student.getAverageGrade() << std::endl;
    std::cout << "Letter Grade: " << student.getLetterGrade() << std::endl;

    // Demonstrate grade calculation function directly
    double totalPoints = 85;
    double maxPoints = 100;
    char grade = calculateGrade(totalPoints, maxPoints);
    
    // Single-line comment explaining the output
    // Display the calculated grade
    std::cout << "\nDirect grade calculation:\n";
    std::cout << "Points: " << totalPoints << "/" << maxPoints << std::endl;
    std::cout << "Grade: " << grade << std::endl;

    return 0;
}
