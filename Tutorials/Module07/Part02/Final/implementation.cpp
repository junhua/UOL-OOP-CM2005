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
    
    // Operator< is required for set to maintain order
    // Set uses this to determine element uniqueness and ordering
    bool operator<(const Student& other) const {
        return id < other.id;  // Order students by ID
    }
    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    // Create a set of integers
    // set<T> maintains unique elements in sorted order
    set<int> numbers;
    cout << "Inserting numbers into set:" << endl;
    
    // Insert elements and check for duplicates
    // insert() returns pair<iterator, bool>
    // - iterator points to element in set
    // - bool indicates if insertion was successful
    for(int i : {10, 5, 8, 10, 3, 5}) {
        auto result = numbers.insert(i);
        if(result.second) {
            cout << "Inserted " << i << endl;
        } else {
            cout << i << " already exists in set" << endl;
        }
    }
    
    // Elements are automatically maintained in sorted order
    // No explicit sorting required
    cout << "\nNumbers in set (automatically sorted):" << endl;
    for(const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // find() returns iterator to element if found
    // or end() if not found
    int searchNum = 8;
    auto it = numbers.find(searchNum);
    if(it != numbers.end()) {
        cout << "\nFound " << searchNum << " in set" << endl;
    }
    
    // Create set of custom objects
    // Objects must be comparable using operator<
    set<Student> students;
    
    // Insert students into set
    // Duplicates are determined by operator<
    students.insert(Student(101, "Alice"));
    students.insert(Student(103, "Bob"));
    students.insert(Student(102, "Charlie"));
    students.insert(Student(101, "David")); // Won't insert - duplicate ID
    
    // Elements are sorted according to operator<
    cout << "\nStudents in set:" << endl;
    for(const Student& student : students) {
        student.display();
    }
    
    // count() returns number of elements matching value
    // For set, this will be 0 or 1 since duplicates aren't allowed
    Student searchStudent(102, "");
    cout << "\nNumber of students with ID 102: " << students.count(searchStudent) << endl;
    
    // erase() removes element matching value
    // Returns number of elements removed (0 or 1)
    if(students.erase(searchStudent)) {
        cout << "Erased student with ID 102" << endl;
    }
    
    // Final set contents after modifications
    cout << "\nFinal student list:" << endl;
    for(const Student& student : students) {
        student.display();
    }
    
    return 0;
}
