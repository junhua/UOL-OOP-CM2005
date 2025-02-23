#include <iostream>
#include <string>
using namespace std;

/**
 * Module 9 - Part 3: Dynamic Memory Allocation
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Basic allocation/deallocation
 * 2. Array handling
 * 3. Object management
 * 4. Memory safety
 */

class Resource {
private:
    string name;
    int* data;
    size_t size;
    
public:
    Resource(string n, size_t s) 
        : name(n), size(s) {
        cout << "Creating resource: " << name << endl;
        data = new int[size];
        
        // Initialize data
        for (size_t i = 0; i < size; i++) {
            data[i] = i + 1;
        }
    }
    
    ~Resource() {
        cout << "Destroying resource: " << name << endl;
        delete[] data;
    }
    
    void display() const {
        cout << "Resource " << name << " data: ";
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    void modify(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }
};

void basicAllocation() {
    cout << "\nBasic Allocation:" << endl;
    cout << string(30, '-') << endl;
    
    // Single value allocation
    int* number = new int(42);
    cout << "Allocated value: " << *number << endl;
    delete number;
    
    // Array allocation
    const size_t size = 5;
    double* numbers = new double[size]{1.1, 2.2, 3.3, 4.4, 5.5};
    
    cout << "Allocated array: ";
    for (size_t i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    delete[] numbers;
}

void dynamicArrays() {
    cout << "\nDynamic Arrays:" << endl;
    cout << string(30, '-') << endl;
    
    // Get size at runtime
    size_t size;
    cout << "Enter array size: ";
    cin >> size;
    
    // Allocate array
    int* array = new int[size];
    
    // Initialize array
    cout << "Initializing array..." << endl;
    for (size_t i = 0; i < size; i++) {
        array[i] = i * 2;
    }
    
    // Display array
    cout << "Array contents: ";
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    // Cleanup
    delete[] array;
}

void objectAllocation() {
    cout << "\nObject Allocation:" << endl;
    cout << string(30, '-') << endl;
    
    // Single object
    Resource* res1 = new Resource("Single", 3);
    res1->display();
    res1->modify(1, 10);
    res1->display();
    delete res1;
    
    // Array of objects
    const size_t count = 2;
    Resource** resources = new Resource*[count];
    
    // Create objects
    for (size_t i = 0; i < count; i++) {
        resources[i] = new Resource("Array" + to_string(i), 2);
    }
    
    // Use objects
    for (size_t i = 0; i < count; i++) {
        resources[i]->display();
    }
    
    // Cleanup
    for (size_t i = 0; i < count; i++) {
        delete resources[i];
    }
    delete[] resources;
}

void memoryLeakPrevention() {
    cout << "\nMemory Leak Prevention:" << endl;
    cout << string(30, '-') << endl;
    
    try {
        // Allocate resources
        int* data = new int[1000];
        Resource* res = new Resource("Test", 5);
        
        // Simulate error
        throw runtime_error("Simulated error");
        
        // This cleanup never happens!
        delete[] data;
        delete res;
        
    } catch (const exception& e) {
        cout << "Error caught: " << e.what() << endl;
        // Memory leak! Resources not freed
    }
    
    // Proper way with RAII
    try {
        // Resources automatically cleaned up when going out of scope
        Resource res("RAII", 3);
        res.display();
        
        throw runtime_error("Another error");
        
    } catch (const exception& e) {
        cout << "Error caught: " << e.what() << endl;
        // No memory leak - destructor automatically called
    }
}

int main() {
    try {
        cout << "Dynamic Memory Management Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        basicAllocation();
        dynamicArrays();
        objectAllocation();
        memoryLeakPrevention();
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
