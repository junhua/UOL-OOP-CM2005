// This tutorial demonstrates:
// 1. Set container basics
// 2. Set operations (insert, erase)
// 3. Set properties (unique, ordered elements)
// 4. Set algorithms (find, count)

#include <iostream>
#include <set>
#include <string>
using namespace std;

// Custom class to store in set
class Student {
private:
    int id;
    string name;
    
public:
    Student(int i, string n) : id(i), name(n) {}
    
    int getId() const { return id; }
    string getName() const { return name; }
    
    // Required for set to compare elements
    bool operator<(const Student& other) const {
        return id < other.id;
    }
    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    // Create and populate a set of integers
    set<int> numbers;
    cout << "Inserting numbers into set:" << endl;
    
    // Insert returns a pair: iterator to element and bool indicating success
    for(int i : {10, 5, 8, 10, 3, 5}) {
        auto result = numbers.insert(i);
        if(result.second) {
            cout << "Inserted " << i << endl;
        } else {
            cout << i << " already exists in set" << endl;
        }
    }
    
    // Set maintains elements in sorted order
    cout << "\nNumbers in set (automatically sorted):" << endl;
    for(const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Find element in set
    int searchNum = 8;
    auto it = numbers.find(searchNum);
    if(it != numbers.end()) {
        cout << "\nFound " << searchNum << " in set" << endl;
    }
    
    // Create set of custom objects
    set<Student> students;
    students.insert(Student(101, "Alice"));
    students.insert(Student(103, "Bob"));
    students.insert(Student(102, "Charlie"));
    students.insert(Student(101, "David")); // Won't insert - duplicate ID
    
    // Display all students (automatically sorted by ID)
    cout << "\nStudents in set:" << endl;
    for(const Student& student : students) {
        student.display();
    }
    
    // Count elements with specific value
    Student searchStudent(102, "");
    cout << "\nNumber of students with ID 102: " << students.count(searchStudent) << endl;
    
    // Erase element
    if(students.erase(searchStudent)) {
        cout << "Erased student with ID 102" << endl;
    }
    
    // Final set contents
    cout << "\nFinal student list:" << endl;
    for(const Student& student : students) {
        student.display();
    }
    
    return 0;
}
