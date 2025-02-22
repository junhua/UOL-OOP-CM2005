// Module 09 - Part 04: Memory Leaks and How to Avoid Them
// This tutorial demonstrates:
// 1. Common scenarios that cause memory leaks
// 2. How to identify potential memory leaks
// 3. Best practices to prevent memory leaks
// 4. Using tools and techniques for memory management

#include <iostream>
#include <string>
using namespace std;

// Example of proper resource management using RAII
class Resource {
private:
    int* data;
    string name;
    
public:
    // Constructor: allocates memory
    Resource(const string& n) : name(n) {
        data = new int(0);  // Allocate memory
        cout << "Resource " << name << " constructed" << endl;
    }
    
    // Destructor: ensures memory is freed
    ~Resource() {
        delete data;  // Free memory
        cout << "Resource " << name << " destroyed" << endl;
    }
    
    // Copy constructor: implements deep copy
    Resource(const Resource& other) : name(other.name) {
        data = new int(*other.data);  // Create new memory with copied value
        cout << "Resource " << name << " copied" << endl;
    }
    
    // Assignment operator: prevents memory leaks during assignment
    Resource& operator=(const Resource& other) {
        if(this != &other) {  // Prevent self-assignment
            delete data;       // Free existing memory
            name = other.name;
            data = new int(*other.data);  // Create new memory with copied value
            cout << "Resource " << name << " assigned" << endl;
        }
        return *this;
    }
    
    void setValue(int val) {
        *data = val;
    }
    
    int getValue() const {
        return *data;
    }
    
    string getName() const {
        return name;
    }
};

// Fixed: Proper resource cleanup
void scenario1_ResourceLeak() {
    int* number = new int(42);
    cout << "Value: " << *number << endl;
    delete number;  // Properly free the memory
    number = nullptr;  // Set to nullptr after deletion
}

// Fixed: Ensure cleanup in all code paths
void scenario2_ConditionalLeak(bool condition) {
    int* data = new int(100);
    
    try {
        if(condition) {
            cout << "Condition is true" << endl;
            delete data;  // Clean up before return
            return;
        }
        
        // Process data
        cout << "Processing value: " << *data << endl;
        delete data;  // Clean up in normal path
    }
    catch(...) {
        delete data;  // Clean up if exception occurs
        throw;        // Re-throw the exception
    }
}

// Fixed: Use RAII or ensure cleanup with try-catch
void scenario3_ExceptionLeak() {
    int* array = nullptr;
    try {
        array = new int[1000];
        throw runtime_error("Test exception");
    }
    catch(...) {
        delete[] array;  // Clean up if exception occurs
        throw;          // Re-throw the exception
    }
    // Note: This line is never reached, but if it was:
    // delete[] array;
}

// Fixed: Prevent memory leaks during pointer reassignment
void scenario4_PointerReassignment() {
    int* ptr = new int(5);
    cout << "First value: " << *ptr << endl;
    
    delete ptr;  // Delete original memory before reassignment
    ptr = new int(10);
    cout << "New value: " << *ptr << endl;
    
    delete ptr;  // Clean up final allocation
    ptr = nullptr;
}

// Example of proper resource management class
class ResourceManager {
private:
    Resource** resources;
    int capacity;
    int count;
    
public:
    ResourceManager(int cap) : capacity(cap), count(0) {
        resources = new Resource*[capacity];
        for(int i = 0; i < capacity; i++) {
            resources[i] = nullptr;
        }
        cout << "ResourceManager created with capacity " << capacity << endl;
    }
    
    // Destructor ensures all resources are properly cleaned up
    ~ResourceManager() {
        for(int i = 0; i < count; i++) {
            delete resources[i];
        }
        delete[] resources;
        cout << "ResourceManager destroyed, all resources cleaned up" << endl;
    }
    
    void addResource(const string& name) {
        if(count < capacity) {
            resources[count] = new Resource(name);
            count++;
            cout << "Added resource: " << name << endl;
        } else {
            cout << "Cannot add resource: manager is full" << endl;
        }
    }
    
    void removeResource(const string& name) {
        for(int i = 0; i < count; i++) {
            if(resources[i] && resources[i]->getName() == name) {
                delete resources[i];
                // Shift remaining resources
                for(int j = i; j < count - 1; j++) {
                    resources[j] = resources[j + 1];
                }
                resources[count - 1] = nullptr;
                count--;
                cout << "Removed resource: " << name << endl;
                return;
            }
        }
        cout << "Resource not found: " << name << endl;
    }
    
    void displayResources() const {
        cout << "Current resources:" << endl;
        if(count == 0) {
            cout << "No resources" << endl;
            return;
        }
        for(int i = 0; i < count; i++) {
            cout << "- " << resources[i]->getName() << endl;
        }
    }
};

int main() {
    cout << "Memory Leak Scenarios and Solutions:" << endl;
    
    cout << "\n1. Basic Resource Leak:" << endl;
    scenario1_ResourceLeak();
    
    cout << "\n2. Conditional Leak:" << endl;
    scenario2_ConditionalLeak(true);
    scenario2_ConditionalLeak(false);
    
    cout << "\n3. Exception Leak:" << endl;
    try {
        scenario3_ExceptionLeak();
    } catch(const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }
    
    cout << "\n4. Pointer Reassignment Leak:" << endl;
    scenario4_PointerReassignment();
    
    cout << "\n5. Resource Management:" << endl;
    {  // Create a scope to demonstrate RAII
        ResourceManager manager(5);
        manager.addResource("Resource1");
        manager.addResource("Resource2");
        manager.displayResources();
        manager.removeResource("Resource1");
        manager.displayResources();
        // ResourceManager destructor will be called automatically here
    }
    
    cout << "\nAll scenarios completed with proper memory management" << endl;
    return 0;
}
