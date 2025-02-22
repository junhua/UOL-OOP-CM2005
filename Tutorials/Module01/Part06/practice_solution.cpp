// Student Records Analysis Program
// Think of this program like a teacher's gradebook that can:
// - Store student information
// - Calculate grades
// - Generate report cards
// - Analyze class performance

#include <iostream>   // For input/output
#include <vector>     // For storing lists
#include <string>     // For text handling
#include <iomanip>    // For formatting output
#include <algorithm>  // For min/max functions
#include <limits>     // For numeric limits
#include <cassert>    // For testing

// Structure to hold student data
// Like a student's file folder containing all their information
struct Student {
    std::string name;           // Student's name
    int id;                     // Student ID number
    std::vector<int> scores;    // List of test scores
    double average;             // Average score
    char grade;                 // Letter grade (A, B, C, D, F)
};

// Structure to hold class statistics
// Like a teacher's summary report of the whole class
struct ClassStats {
    double classAverage;                // Average for whole class
    int highestScore;                   // Best score in class
    int lowestScore;                    // Lowest score in class
    std::vector<Student> topPerformers; // List of best students
    int aboveAverage;                   // Number of students above average
    int belowAverage;                   // Number of students below average
};

// First, declare all the functions we'll need
// Like listing all the tasks a teacher needs to do
std::vector<Student> getStudentData();    // Get information about students
void calculateStudentStats(Student& student);  // Calculate student's performance
ClassStats analyzeClassStats(const std::vector<Student>& students);  // Analyze whole class
void generateReport(const std::vector<Student>& students, const ClassStats& stats);  // Create report
void runTests();                          // Test our calculations
char calculateGrade(double average);      // Convert average to letter grade
void clearInputBuffer();                  // Clean up input

int main() {
    // First, test our grading system
    // Like checking that our calculator works
    std::cout << "Running tests...\n";
    runTests();
    std::cout << "All tests passed!\n\n";

    // Welcome message
    std::cout << "Student Records Analysis\n";
    std::cout << "======================\n\n";

    // Get information about all students
    // Like collecting all student papers
    std::vector<Student> students = getStudentData();

    // Calculate each student's performance
    // Like grading each student's work
    for (auto& student : students) {
        calculateStudentStats(student);
    }

    // Analyze how the whole class did
    // Like creating a class summary
    ClassStats stats = analyzeClassStats(students);

    // Create the final report
    // Like writing up the final grades
    generateReport(students, stats);

    return 0;
}

// Function to get student data
// Like collecting student information forms
std::vector<Student> getStudentData() {
    std::vector<Student> students;
    int numStudents;
    
    // Get number of students
    do {
        std::cout << "Enter number of students: ";
        std::cin >> numStudents;
        if (std::cin.fail() || numStudents <= 0) {
            std::cout << "Please enter a positive number.\n";
            clearInputBuffer();
        }
    } while (numStudents <= 0);

    clearInputBuffer();

    // Get information for each student
    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "\nStudent " << (i + 1) << ":\n";
        
        // Get name and ID
        std::cout << "Name: ";
        std::getline(std::cin, student.name);
        
        std::cout << "ID: ";
        std::cin >> student.id;
        
        // Get test scores
        int score;
        std::cout << "Enter scores (enter -1 to finish):\n";
        while (std::cin >> score && score != -1) {
            if (score >= 0 && score <= 100) {  // Valid scores: 0-100
                student.scores.push_back(score);
            } else {
                std::cout << "Invalid score. Enter 0-100.\n";
            }
        }
        
        clearInputBuffer();
        students.push_back(student);
    }

    return students;
}

// Function to calculate student statistics
// Like grading a single student's work
void calculateStudentStats(Student& student) {
    // Handle case with no scores
    if (student.scores.empty()) {
        student.average = 0.0;
        student.grade = 'F';
        return;
    }

    // Calculate average score
    int sum = 0;
    for (int score : student.scores) {
        sum += score;
    }
    student.average = static_cast<double>(sum) / student.scores.size();

    // Convert average to letter grade
    student.grade = calculateGrade(student.average);
}

// Function to calculate letter grade from average
// Like converting numerical score to letter grade
char calculateGrade(double average) {
    if (average >= 90) return 'A';  // Excellent
    if (average >= 80) return 'B';  // Good
    if (average >= 70) return 'C';  // Satisfactory
    if (average >= 60) return 'D';  // Needs Improvement
    return 'F';                     // Failed
}

// Function to analyze class statistics
// Like creating a summary of the whole class
ClassStats analyzeClassStats(const std::vector<Student>& students) {
    ClassStats stats;
    
    // Handle empty class
    if (students.empty()) {
        stats = {0.0, 0, 0, {}, 0, 0};
        return stats;
    }

    // Calculate class average
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.average;
    }
    stats.classAverage = sum / students.size();

    // Find highest and lowest scores
    // Like finding the best and worst performances
    stats.highestScore = students[0].scores[0];
    stats.lowestScore = students[0].scores[0];
    for (const auto& student : students) {
        for (int score : student.scores) {
            stats.highestScore = std::max(stats.highestScore, score);
            stats.lowestScore = std::min(stats.lowestScore, score);
        }
    }

    // Find top students (90% or above)
    // Like creating honor roll
    for (const auto& student : students) {
        if (student.average >= 90) {
            stats.topPerformers.push_back(student);
        }
    }

    // Count students above/below average
    // Like comparing to class average
    stats.aboveAverage = 0;
    stats.belowAverage = 0;
    for (const auto& student : students) {
        if (student.average > stats.classAverage) {
            stats.aboveAverage++;
        } else if (student.average < stats.classAverage) {
            stats.belowAverage++;
        }
    }

    return stats;
}

// Function to generate report
// Like creating final report cards
void generateReport(const std::vector<Student>& students, const ClassStats& stats) {
    std::cout << "\nClass Report\n";
    std::cout << "============\n\n";

    // Show class statistics
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Class Statistics:\n";
    std::cout << "----------------\n";
    std::cout << "Class Average: " << stats.classAverage << "\n";
    std::cout << "Highest Score: " << stats.highestScore << "\n";
    std::cout << "Lowest Score: " << stats.lowestScore << "\n";
    std::cout << "Students Above Average: " << stats.aboveAverage << "\n";
    std::cout << "Students Below Average: " << stats.belowAverage << "\n\n";

    // Show individual student records
    std::cout << "Student Records:\n";
    std::cout << "--------------\n";
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << "\n";
        std::cout << "ID: " << student.id << "\n";
        std::cout << "Average: " << student.average << "\n";
        std::cout << "Grade: " << student.grade << "\n";
        std::cout << "Scores: ";
        for (int score : student.scores) {
            std::cout << score << " ";
        }
        std::cout << "\n\n";
    }

    // Show top performers
    std::cout << "Top Performers:\n";
    std::cout << "--------------\n";
    if (stats.topPerformers.empty()) {
        std::cout << "No top performers (90% or above)\n";
    } else {
        for (const auto& student : stats.topPerformers) {
            std::cout << student.name << " (" << student.average << "%)\n";
        }
    }
}

// Function to test our calculations
// Like checking our grading system
void runTests() {
    // Test student grade calculation
    Student testStudent{"Test Student", 1, {85, 90, 95}, 0.0, 'X'};
    calculateStudentStats(testStudent);
    assert(testStudent.average == 90.0);  // Should be A
    assert(testStudent.grade == 'A');

    // Test grade boundaries
    assert(calculateGrade(95) == 'A');  // Well above 90
    assert(calculateGrade(85) == 'B');  // Between 80 and 90
    assert(calculateGrade(75) == 'C');  // Between 70 and 80
    assert(calculateGrade(65) == 'D');  // Between 60 and 70
    assert(calculateGrade(55) == 'F');  // Below 60

    // Test class statistics with one student
    std::vector<Student> singleStudent{testStudent};
    ClassStats singleStats = analyzeClassStats(singleStudent);
    assert(singleStats.classAverage == 90.0);
    assert(singleStats.highestScore == 95);
    assert(singleStats.lowestScore == 85);
    assert(singleStats.topPerformers.size() == 1);
}

// Function to clear input buffer
// Like erasing the chalkboard
void clearInputBuffer() {
    std::cin.clear();  // Reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
}

/*
This program shows:
1. How to store and organize student data
2. How to calculate grades and statistics
3. How to generate reports
4. How to test our calculations
5. How to handle user input

Try:
1. Enter data for several students
2. Try different test scores
3. See how the class average changes
4. Look for top performers
5. Test the grading boundaries
*/
