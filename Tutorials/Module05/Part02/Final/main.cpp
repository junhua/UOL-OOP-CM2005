#include <iostream>
#include <cstring>
using namespace std;

/**
 * Module 5 - Part 2: Constructors and Destructors
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Dynamic memory management
 * 2. Constructor/destructor implementation
 * 3. Copy constructor and assignment
 * 4. String buffer manipulation
 */

class StringBuffer {
private:
    char* buffer;
    size_t capacity;
    
    // Helper to allocate memory
    void allocate(size_t size) {
        buffer = new char[size];
        capacity = size;
    }
    
public:
    // Default constructor
    StringBuffer() {
        cout << "Default constructor called" << endl;
        allocate(1);
        buffer[0] = '\0';
    }
    
    // Parameterized constructor
    StringBuffer(const char* str) {
        cout << "Parameterized constructor called" << endl;
        size_t len = strlen(str);
        allocate(len + 1);
        strcpy(buffer, str);
    }
    
    // Copy constructor
    StringBuffer(const StringBuffer& other) {
        cout << "Copy constructor called" << endl;
        allocate(other.capacity);
        strcpy(buffer, other.buffer);
    }
    
    // Destructor
    ~StringBuffer() {
        cout << "Destructor called for buffer: \"" << buffer << "\"" << endl;
        delete[] buffer;
    }
    
    // Assignment operator
    StringBuffer& operator=(const StringBuffer& other) {
        cout << "Assignment operator called" << endl;
        if (this != &other) {  // Handle self-assignment
            delete[] buffer;    // Free existing memory
            allocate(other.capacity);
            strcpy(buffer, other.buffer);
        }
        return *this;
    }
    
    // Get string length
    size_t length() const {
        return strlen(buffer);
    }
    
    // Get buffer capacity
    size_t getCapacity() const {
        return capacity;
    }
    
    // Get string content
    const char* getString() const {
        return buffer;
    }
    
    // Append string
    void append(const char* str) {
        size_t newLen = length() + strlen(str);
        if (newLen >= capacity) {
            // Create new buffer with more space
            size_t newCapacity = newLen + 1;
            char* newBuffer = new char[newCapacity];
            strcpy(newBuffer, buffer);
            delete[] buffer;
            buffer = newBuffer;
            capacity = newCapacity;
        }
        strcat(buffer, str);
    }
    
    // Clear buffer
    void clear() {
        buffer[0] = '\0';
    }
};

int main() {
    cout << "Testing StringBuffer class:" << endl;
    cout << "==========================" << endl;
    
    // Test default constructor
    cout << "\n1. Testing default constructor:" << endl;
    StringBuffer sb1;
    cout << "Content: \"" << sb1.getString() << "\"" << endl;
    cout << "Length: " << sb1.length() << endl;
    cout << "Capacity: " << sb1.getCapacity() << endl;
    
    // Test parameterized constructor
    cout << "\n2. Testing parameterized constructor:" << endl;
    StringBuffer sb2("Hello");
    cout << "Content: \"" << sb2.getString() << "\"" << endl;
    cout << "Length: " << sb2.length() << endl;
    cout << "Capacity: " << sb2.getCapacity() << endl;
    
    // Test copy constructor
    cout << "\n3. Testing copy constructor:" << endl;
    StringBuffer sb3 = sb2;  // Copy constructor
    cout << "Original: \"" << sb2.getString() << "\"" << endl;
    cout << "Copy: \"" << sb3.getString() << "\"" << endl;
    
    // Test append
    cout << "\n4. Testing append operation:" << endl;
    cout << "Before append: \"" << sb3.getString() << "\"" << endl;
    sb3.append(" World!");
    cout << "After append: \"" << sb3.getString() << "\"" << endl;
    cout << "New length: " << sb3.length() << endl;
    cout << "New capacity: " << sb3.getCapacity() << endl;
    
    // Test assignment operator
    cout << "\n5. Testing assignment operator:" << endl;
    StringBuffer sb4;
    cout << "Before assignment: \"" << sb4.getString() << "\"" << endl;
    sb4 = sb3;
    cout << "After assignment: \"" << sb4.getString() << "\"" << endl;
    
    // Test clear
    cout << "\n6. Testing clear operation:" << endl;
    cout << "Before clear: \"" << sb4.getString() << "\"" << endl;
    sb4.clear();
    cout << "After clear: \"" << sb4.getString() << "\"" << endl;
    cout << "Length after clear: " << sb4.length() << endl;
    
    cout << "\n7. Testing destructor (objects going out of scope):" << endl;
    {
        StringBuffer temp("Temporary");
        cout << "Temporary object created" << endl;
    }  // Destructor called here
    cout << "Temporary object destroyed" << endl;
    
    cout << "\nEnd of main function, remaining objects will be destroyed" << endl;
    return 0;
}
