// Module 09 - Part 06: Pointers and Objects
// This tutorial demonstrates:
// 1. Object pointers and dynamic object creation
// 2. Arrow operator (->) for accessing members
// 3. Pointers to member functions
// 4. Array of objects using pointers

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    float* grades;  // Dynamic array for grades
    int numGrades;
    int capacity;   // Current capacity of grades array
    
public:
    // Constructor
    Student(const string& n, int i) : name(n), id(i), numGrades(0), capacity(5) {
        grades = new float[capacity];  // Initial capacity for 5 grades
        cout << "Student " << name << " constructed" << endl;
    }
    
    // Destructor
    ~Student() {
        delete[] grades;
        cout << "Student " << name << " destroyed" << endl;
    }
    
    // Copy constructor
    Student(const Student& other) : 
        name(other.name), id(other.id), 
        numGrades(other.numGrades), capacity(other.capacity) {
        // Deep copy of grades array
        grades = new float[capacity];
        for(int i = 0; i < numGrades; i++) {
            grades[i] = other.grades[i];
        }
        cout << "Student " << name << " copied" << endl;
    }
    
    // Assignment operator
    Student& operator=(const Student& other) {
        if(this != &other) {
            // Free existing memory
            delete[] grades;
            
            // Copy data
            name = other.name;
            id = other.id;
            numGrades = other.numGrades;
            capacity = other.capacity;
            
            // Deep copy of grades array
            grades = new float[capacity];
            for(int i = 0; i < numGrades; i++) {
                grades[i] = other.grades[i];
            }
            cout << "Student " << name << " assigned" << endl;
        }
        return *this;
    }
    
    // Add grade (with dynamic array resizing)
    void addGrade(float grade) {
        if(numGrades == capacity) {
            // Double the capacity
            capacity *= 2;
            float* newGrades = new float[capacity];
            
            // Copy existing grades
            for(int i = 0; i < numGrades; i++) {
                newGrades[i] = grades[i];
            }
            
            // Free old array and update pointer
            delete[] grades;
            grades = newGrades;
        }
        
        grades[numGrades++] = grade;
        cout << "Added grade " << grade << " for " << name << endl;
    }
    
    // Calculate average grade
    float calculateAverage() const {
        if(numGrades == 0) return 0.0f;
        
        float sum = 0.0f;
        for(int i = 0; i < numGrades; i++) {
            sum += grades[i];
        }
        return sum / numGrades;
    }
    
    // Display student information
    void display() const {
        cout << "Student: " << name << " (ID: " << id << ")" << endl;
        cout << "Grades: ";
        for(int i = 0; i < numGrades; i++) {
            cout << grades[i] << " ";
        }
        cout << "\nAverage: " << calculateAverage() << endl;
    }
    
    // Getters
    string getName() const { return name; }
    int getId() const { return id; }
};

// Demonstrate basic object pointer usage
void demonstrateObjectPointers() {
    cout << "Creating student on stack..." << endl;
    Student alice("Alice", 1001);
    
    // Create pointer to stack object
    Student* ptr = &alice;
    
    // Access members using -> operator
    cout << "\nAccessing through pointer:" << endl;
    cout << "Name: " << ptr->getName() << endl;
    cout << "ID: " << ptr->getId() << endl;
    
    // Add grades and display using pointer
    ptr->addGrade(85.5);
    ptr->addGrade(92.0);
    ptr->display();
}

// Demonstrate dynamic object creation
void demonstrateDynamicObjects() {
    // Create object dynamically
    cout << "\nCreating student dynamically..." << endl;
    Student* bob = new Student("Bob", 1002);
    
    // Use the object through pointer
    bob->addGrade(78.5);
    bob->addGrade(88.0);
    bob->addGrade(95.5);
    
    // Display information
    bob->display();
    
    // Clean up
    delete bob;
    cout << "Dynamic student deleted" << endl;
}

// Demonstrate array of object pointers
void demonstrateObjectArray() {
    const int NUM_STUDENTS = 3;
    cout << "\nCreating array of student pointers..." << endl;
    
    // Create array of pointers
    Student** students = new Student*[NUM_STUDENTS];
    
    // Create each student dynamically
    students[0] = new Student("Charlie", 1003);
    students[1] = new Student("David", 1004);
    students[2] = new Student("Eve", 1005);
    
    // Add grades for each student
    for(int i = 0; i < NUM_STUDENTS; i++) {
        students[i]->addGrade(75.0 + i * 5);
        students[i]->addGrade(85.0 + i * 5);
    }
    
    // Display all students
    cout << "\nAll students:" << endl;
    for(int i = 0; i < NUM_STUDENTS; i++) {
        students[i]->display();
        cout << endl;
    }
    
    // Clean up
    cout << "Cleaning up..." << endl;
    for(int i = 0; i < NUM_STUDENTS; i++) {
        delete students[i];
    }
    delete[] students;
}

// Demonstrate pointer to member function
void demonstrateMemberFunctionPointers() {
    cout << "\nDemonstrating pointer to member function:" << endl;
    
    // Define pointer to member function
    void (Student::*displayFunc)() const = &Student::display;
    
    // Create student and use member function pointer
    Student frank("Frank", 1006);
    frank.addGrade(88.5);
    
    cout << "Calling display through member function pointer:" << endl;
    (frank.*displayFunc)();
}

int main() {
    cout << "1. Basic Object Pointer Usage:" << endl;
    demonstrateObjectPointers();
    
    cout << "\n2. Dynamic Object Creation:" << endl;
    demonstrateDynamicObjects();
    
    cout << "\n3. Array of Objects:" << endl;
    demonstrateObjectArray();
    
    cout << "\n4. Member Function Pointers:" << endl;
    demonstrateMemberFunctionPointers();
    
    return 0;
}
