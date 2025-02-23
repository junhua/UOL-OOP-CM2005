/**
 * Student Grade Management System
 * 
 * This program demonstrates a simple student grade management system
 * that stores student information, calculates grade points, and
 * converts GPAs to letter grades.
 * 
 * Key features:
 * - Student information storage
 * - GPA to grade point conversion
 * - Letter grade calculation
 * - Class average computation
 */

#include <iostream>
#include <string>
#include <iomanip>  // For output formatting

// Use specific elements from std namespace instead of entire namespace
using std::cout;
using std::endl;
using std::string;

/**
 * @class Student
 * @brief Represents a student with their academic information
 * 
 * This class manages student data including name, age, and GPA.
 * It provides functionality to display student information and
 * calculate grade-related values.
 */
class Student {
private:
    // Student information
    string name;     // Student's full name
    int age;        // Student's age
    double gpa;     // Grade Point Average (0.0 - 4.0)

public:
    /**
     * @brief Construct a new Student object
     * 
     * @param studentName The full name of the student
     * @param studentAge The age of the student
     * @param studentGPA The student's Grade Point Average (0.0 - 4.0)
     */
    Student(string studentName, int studentAge, double studentGPA) {
        name = studentName;
        age = studentAge;
        gpa = studentGPA;
    }

    /**
     * @brief Display student information
     * 
     * Prints the student's name, age, and GPA to the console
     * with proper formatting.
     */
    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Age:  " << age << endl;
        cout << "GPA:  " << std::fixed << std::setprecision(2) << gpa << endl;
    }

    /**
     * @brief Calculate grade points based on GPA
     * 
     * Converts GPA to a standardized 4.0 scale grade point:
     * - 3.5 and above = 4.0
     * - 3.0 to 3.49   = 3.0
     * - 2.0 to 2.99   = 2.0
     * - Below 2.0     = 0.0
     * 
     * @return double The calculated grade points
     */
    double calculateGradePoints() {
        if (gpa >= 3.5) {
            return 4.0;
        } else if (gpa >= 3.0) {
            return 3.0;
        } else if (gpa >= 2.0) {
            return 2.0;
        } else {
            return 0.0;
        }
    }

    /**
     * @brief Get the letter grade based on grade points
     * 
     * Converts grade points to letter grades:
     * - 4.0 = A
     * - 3.0 = B
     * - 2.0 = C
     * - 0.0 = F
     * 
     * @return string The letter grade
     */
    string getLetterGrade() {
        double gradePoints = calculateGradePoints();
        
        if (gradePoints == 4.0) {
            return "A";
        } else if (gradePoints == 3.0) {
            return "B";
        } else if (gradePoints == 2.0) {
            return "C";
        } else {
            return "F";
        }
    }

    // Getter for GPA (needed for average calculation)
    double getGPA() const {
        return gpa;
    }
};

/**
 * Main program entry point
 * 
 * Creates student objects, displays their information,
 * and calculates class average GPA.
 */
int main() {
    // Create and display first student
    Student student1("John Smith", 20, 3.8);
    cout << "Student 1 Information:" << endl;
    cout << "--------------------" << endl;
    student1.printInfo();
    cout << "Letter Grade: " << student1.getLetterGrade() << endl << endl;

    // Create and display second student
    Student student2("Jane Doe", 19, 2.9);
    cout << "Student 2 Information:" << endl;
    cout << "--------------------" << endl;
    student2.printInfo();
    cout << "Letter Grade: " << student2.getLetterGrade() << endl << endl;

    // Calculate and display class average
    double averageGPA = (student1.getGPA() + student2.getGPA()) / 2.0;
    cout << "Class Statistics:" << endl;
    cout << "----------------" << endl;
    cout << "Average GPA: " << std::fixed << std::setprecision(2) 
         << averageGPA << endl;

    return 0;
}

/*
Code Organization and Style Notes:

1. File Structure
   - Documentation header at top
   - Includes grouped together
   - Selective using declarations
   - Class definition with documentation
   - Main function at bottom

2. Naming Conventions
   - Descriptive variable names
   - Consistent function names
   - Clear parameter names
   - Meaningful constants

3. Documentation
   - Class purpose and features
   - Function descriptions
   - Parameter explanations
   - Return value details
   - Implementation notes

4. Formatting
   - Consistent indentation
   - Logical grouping
   - Clear spacing
   - Aligned output
   - Readable line lengths
*/
