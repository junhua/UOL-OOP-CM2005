#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

/**
 * Module 4 - Part 1: Vector, Set and Map
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Using vector for grade storage and processing
 * 2. Using set for unique student ID tracking
 * 3. Using map for student name-grade associations
 */

int main() {
    // Vector example - storing and processing grades
    vector<int> grades;
    grades.push_back(85);
    grades.push_back(92);
    grades.push_back(78);
    grades.push_back(95);
    
    // Calculate average grade
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    double average = static_cast<double>(sum) / grades.size();
    
    // Display grades and average
    cout << "Student Grades:" << endl;
    cout << "Grades: ";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << "\nAverage: " << average << endl;
    
    // Set example - tracking unique student IDs
    set<int> studentIds;
    
    // Add some IDs (including a duplicate)
    cout << "\nAdding student IDs..." << endl;
    cout << "Adding 1001: " 
         << (studentIds.insert(1001).second ? "Added" : "Duplicate") << endl;
    cout << "Adding 1002: " 
         << (studentIds.insert(1002).second ? "Added" : "Duplicate") << endl;
    cout << "Adding 1001: " 
         << (studentIds.insert(1001).second ? "Added" : "Duplicate") << endl;
    cout << "Adding 1003: " 
         << (studentIds.insert(1003).second ? "Added" : "Duplicate") << endl;
    
    // Display all unique IDs
    cout << "\nUnique Student IDs:" << endl;
    for (int id : studentIds) {
        cout << id << " ";
    }
    cout << "\nTotal unique students: " << studentIds.size() << endl;
    
    // Map example - storing student name-grade pairs
    map<string, int> studentGrades;
    
    // Add student grades
    studentGrades["Alice"] = 95;
    studentGrades["Bob"] = 87;
    studentGrades["Charlie"] = 92;
    
    // Display all student grades
    cout << "\nStudent Grade Records:" << endl;
    for (const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Demonstrate grade lookup
    string student = "Alice";
    auto it = studentGrades.find(student);
    if (it != studentGrades.end()) {
        cout << "\nLooking up " << student << "'s grade: " 
             << it->second << endl;
    } else {
        cout << "\nStudent " << student << " not found." << endl;
    }
    
    // Demonstrate safe access with at()
    try {
        cout << "Bob's grade: " << studentGrades.at("Bob") << endl;
        cout << "David's grade: " << studentGrades.at("David") << endl;
    } catch (const out_of_range& e) {
        cout << "Error: Student not found" << endl;
    }
    
    return 0;
}
