#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

/**
 * Module 2 - Part 5: Complete Program Examples
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * - Menu-driven interface
 * - Data validation
 * - Record management
 * - Statistics calculation
 * - All control flow concepts
 */

// Student record structure
struct Student {
    string name;
    int id;
    double grades[3];  // Math, English, Science
    double attendance;
    bool active;
};

int main() {
    // Constants
    const int MAX_STUDENTS = 100;
    const int ID_MIN = 10000;
    const int ID_MAX = 99999;
    const int MIN_GRADE = 0;
    const int MAX_GRADE = 100;
    const string SUBJECTS[3] = {"Math", "English", "Science"};
    
    // Variables
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;
    bool validInput;
    
    // Initialize student records
    for (int i = 0; i < MAX_STUDENTS; i++) {
        students[i].active = false;
    }
    
    // Main program loop
    do {
        // Display menu
        cout << "\n=== Student Record Management System ===\n"
             << "A - Add student\n"
             << "V - View students\n"
             << "S - Search student\n"
             << "U - Update grades\n"
             << "C - Calculate statistics\n"
             << "E - Exit\n"
             << "Enter choice: ";
        
        // Get and validate choice
        cin >> choice;
        choice = toupper(choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Process choice
        switch (choice) {
            case 'A': {  // Add student
                if (studentCount >= MAX_STUDENTS) {
                    cout << "Error: Maximum number of students reached.\n";
                    break;
                }
                
                Student newStudent;
                newStudent.active = true;
                
                // Get name
                cout << "\nEnter student name: ";
                getline(cin, newStudent.name);
                
                // Get and validate ID
                do {
                    cout << "Enter student ID (" << ID_MIN << "-" << ID_MAX << "): ";
                    validInput = (cin >> newStudent.id) && 
                               (newStudent.id >= ID_MIN) && 
                               (newStudent.id <= ID_MAX);
                    
                    if (!validInput) {
                        cout << "Invalid ID. Please try again.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        // Check for duplicate ID
                        for (int i = 0; i < MAX_STUDENTS; i++) {
                            if (students[i].active && students[i].id == newStudent.id) {
                                cout << "Error: ID already exists.\n";
                                validInput = false;
                                break;
                            }
                        }
                    }
                } while (!validInput);
                
                // Get grades
                for (int i = 0; i < 3; i++) {
                    do {
                        cout << "Enter " << SUBJECTS[i] << " grade (0-100): ";
                        validInput = (cin >> newStudent.grades[i]) && 
                                   (newStudent.grades[i] >= MIN_GRADE) && 
                                   (newStudent.grades[i] <= MAX_GRADE);
                        
                        if (!validInput) {
                            cout << "Invalid grade. Please try again.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (!validInput);
                }
                
                // Get attendance
                do {
                    cout << "Enter attendance percentage (0-100): ";
                    validInput = (cin >> newStudent.attendance) && 
                               (newStudent.attendance >= MIN_GRADE) && 
                               (newStudent.attendance <= MAX_GRADE);
                    
                    if (!validInput) {
                        cout << "Invalid attendance. Please try again.\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (!validInput);
                
                // Find empty slot
                for (int i = 0; i < MAX_STUDENTS; i++) {
                    if (!students[i].active) {
                        students[i] = newStudent;
                        studentCount++;
                        cout << "\nStudent added successfully!\n";
                        break;
                    }
                }
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            
            case 'V': {  // View students
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                
                cout << "\n=== Student List ===\n"
                     << setw(20) << left << "Name"
                     << setw(10) << "ID"
                     << setw(8) << "Math"
                     << setw(8) << "Eng"
                     << setw(8) << "Sci"
                     << "Att%\n"
                     << string(60, '-') << endl;
                
                for (const Student& s : students) {
                    if (s.active) {
                        cout << setw(20) << left << s.name
                             << setw(10) << s.id
                             << fixed << setprecision(1)
                             << setw(8) << s.grades[0]
                             << setw(8) << s.grades[1]
                             << setw(8) << s.grades[2]
                             << s.attendance << "%\n";
                    }
                }
                break;
            }
            
            case 'S': {  // Search student
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                
                int searchId;
                cout << "Enter student ID to search: ";
                cin >> searchId;
                
                bool found = false;
                for (const Student& s : students) {
                    if (s.active && s.id == searchId) {
                        cout << "\nStudent found:\n"
                             << "Name: " << s.name << endl
                             << "ID: " << s.id << endl
                             << "Grades:\n";
                        
                        for (int i = 0; i < 3; i++) {
                            cout << "  " << SUBJECTS[i] << ": " << s.grades[i] << endl;
                        }
                        
                        cout << "Attendance: " << s.attendance << "%\n";
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Student not found.\n";
                }
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            
            case 'U': {  // Update grades
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                
                int updateId;
                cout << "Enter student ID to update: ";
                cin >> updateId;
                
                bool found = false;
                for (Student& s : students) {
                    if (s.active && s.id == updateId) {
                        cout << "Updating grades for " << s.name << ":\n";
                        
                        for (int i = 0; i < 3; i++) {
                            do {
                                cout << "Enter new " << SUBJECTS[i] << " grade (0-100): ";
                                validInput = (cin >> s.grades[i]) && 
                                           (s.grades[i] >= MIN_GRADE) && 
                                           (s.grades[i] <= MAX_GRADE);
                                
                                if (!validInput) {
                                    cout << "Invalid grade. Please try again.\n";
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                            } while (!validInput);
                        }
                        
                        cout << "Grades updated successfully!\n";
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    cout << "Student not found.\n";
                }
                
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            
            case 'C': {  // Calculate statistics
                if (studentCount == 0) {
                    cout << "No students registered.\n";
                    break;
                }
                
                double subjectSums[3] = {0};
                double highestGrades[3] = {0};
                double lowestGrades[3] = {100, 100, 100};
                double totalAttendance = 0;
                
                // Calculate sums and find highest/lowest grades
                for (const Student& s : students) {
                    if (s.active) {
                        for (int i = 0; i < 3; i++) {
                            subjectSums[i] += s.grades[i];
                            highestGrades[i] = max(highestGrades[i], s.grades[i]);
                            lowestGrades[i] = min(lowestGrades[i], s.grades[i]);
                        }
                        totalAttendance += s.attendance;
                    }
                }
                
                // Display statistics
                cout << "\n=== Class Statistics ===\n"
                     << fixed << setprecision(1);
                
                for (int i = 0; i < 3; i++) {
                    cout << SUBJECTS[i] << ":\n"
                         << "  Average: " << (subjectSums[i] / studentCount) << endl
                         << "  Highest: " << highestGrades[i] << endl
                         << "  Lowest:  " << lowestGrades[i] << endl;
                }
                
                cout << "\nClass Attendance: " 
                     << (totalAttendance / studentCount) << "%\n";
                break;
            }
            
            case 'E':
                cout << "Exiting program.\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
    } while (choice != 'E');
    
    return 0;
}
