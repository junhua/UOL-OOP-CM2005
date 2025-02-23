#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

/**
 * Module 2 - Part 1: Conditional Statements
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * - Input validation with error handling
 * - Nested conditional statements
 * - Grade calculation and weighting
 * - Formatted output
 * - Detailed feedback system
 */

int main() {
    // Constants
    const double MIN_SCORE = 0.0;
    const double MAX_SCORE = 100.0;
    const double ASSIGNMENT_WEIGHT = 0.4;  // 40%
    const double EXAM_WEIGHT = 0.4;        // 40%
    const double ATTENDANCE_WEIGHT = 0.2;  // 20%
    const double PASSING_GRADE = 60.0;
    
    // Variables
    string name;
    double assignmentScore, examScore, attendanceScore;
    double finalGrade;
    char letterGrade;
    bool validInput;
    
    cout << "=== Student Grade Calculator ===\n\n";
    
    // Get and validate name
    do {
        cout << "Enter student name: ";
        getline(cin, name);
        
        if (name.empty()) {
            cout << "Error: Name cannot be empty.\n";
        }
    } while (name.empty());
    
    // Get and validate assignment score
    do {
        cout << "\nEnter assignment score (0-100): ";
        validInput = (cin >> assignmentScore) && 
                    (assignmentScore >= MIN_SCORE) && 
                    (assignmentScore <= MAX_SCORE);
        
        if (!validInput) {
            cout << "Error: Score must be between " << MIN_SCORE 
                 << " and " << MAX_SCORE << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Get and validate exam score
    do {
        cout << "Enter exam score (0-100): ";
        validInput = (cin >> examScore) && 
                    (examScore >= MIN_SCORE) && 
                    (examScore <= MAX_SCORE);
        
        if (!validInput) {
            cout << "Error: Score must be between " << MIN_SCORE 
                 << " and " << MAX_SCORE << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Get and validate attendance score
    do {
        cout << "Enter attendance percentage (0-100): ";
        validInput = (cin >> attendanceScore) && 
                    (attendanceScore >= MIN_SCORE) && 
                    (attendanceScore <= MAX_SCORE);
        
        if (!validInput) {
            cout << "Error: Percentage must be between " << MIN_SCORE 
                 << " and " << MAX_SCORE << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Calculate final grade
    finalGrade = (assignmentScore * ASSIGNMENT_WEIGHT) +
                 (examScore * EXAM_WEIGHT) +
                 (attendanceScore * ATTENDANCE_WEIGHT);
    
    // Determine letter grade
    if (finalGrade >= 90.0) {
        letterGrade = 'A';
    } else if (finalGrade >= 80.0) {
        letterGrade = 'B';
    } else if (finalGrade >= 70.0) {
        letterGrade = 'C';
    } else if (finalGrade >= 60.0) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n=== Grade Report for " << name << " ===\n"
         << "Assignment Score: " << assignmentScore << endl
         << "Exam Score: " << examScore << endl
         << "Attendance: " << attendanceScore << "%" << endl
         << "Final Grade: " << finalGrade << endl
         << "Letter Grade: " << letterGrade << endl;
    
    // Determine pass/fail status
    if (finalGrade >= PASSING_GRADE) {
        cout << "Status: PASSED" << endl;
    } else {
        cout << "Status: FAILED" << endl;
    }
    
    // Provide specific feedback
    cout << "\nFeedback:\n";
    
    if (assignmentScore < 70.0) {
        cout << "- Work on improving assignment scores\n";
    }
    
    if (examScore < 70.0) {
        cout << "- Focus on exam preparation\n";
    }
    
    if (attendanceScore < 80.0) {
        cout << "- Improve class attendance\n";
    }
    
    // Additional recommendations based on letter grade
    cout << "\nRecommendations:\n";
    switch (letterGrade) {
        case 'A':
            cout << "Excellent work! Keep it up!" << endl;
            break;
        case 'B':
            cout << "Good performance. Aim for excellence!" << endl;
            break;
        case 'C':
            cout << "Average performance. More effort needed." << endl;
            break;
        case 'D':
            cout << "Passing, but significant improvement needed." << endl;
            break;
        case 'F':
            cout << "Failed. Please seek additional help and consider retaking the course." << endl;
            break;
    }
    
    return 0;
}
