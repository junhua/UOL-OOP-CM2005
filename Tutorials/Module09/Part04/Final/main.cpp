#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

/**
 * Module 9 - Part 4: Memory Leaks
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Memory leak scenarios
 * 2. RAII pattern
 * 3. Smart pointers
 * 4. Resource management
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
};

void demonstrateLeaks() {
    cout << "\nDemonstrating Memory Leaks:" << endl;
    cout << string(30, '-') << endl;
    
    // Lost pointer
    cout << "Lost pointer leak:" << endl;
    int* ptr1 = new int(42);
    ptr1 = new int(100);  // Original memory leaked
    delete ptr1;  // Only frees second allocation
    
    // Missing delete
    cout << "\nMissing delete leak:" << endl;
    int* ptr2 = new int[5];
    // No delete - memory leaked
    
    // Exception leak
    cout << "\nException leak:" << endl;
    try {
        int* ptr3 = new int[1000];
        throw runtime_error("Error");
        delete[] ptr3;  // Never reached
    } catch (const exception& e) {
        cout << "Error caught: " << e.what() << endl;
        // Memory leaked
    }
}

void demonstrateRAII() {
    cout << "\nDemonstrating RAII:" << endl;
    cout << string(30, '-') << endl;
    
    // Automatic cleanup
    {
        Resource res("RAII Example", 3);
        // Resource automatically cleaned up when scope ends
    }
    
    // Exception safety
    try {
        Resource res("Exception Safe", 5);
        throw runtime_error("Error");
    } catch (const exception& e) {
        cout << "Error caught: " << e.what() << endl;
        // Resource automatically cleaned up
    }
}

void demonstrateSmartPointers() {
    cout << "\nDemonstrating Smart Pointers:" << endl;
    cout << string(30, '-') << endl;
    
    // unique_ptr
    cout << "unique_ptr example:" << endl;
    {
        unique_ptr<Resource> res1(new Resource("Unique", 3));
        res1->display();
        // Automatically deleted when scope ends
    }
    
    // shared_ptr
    cout << "\nshared_ptr example:" << endl;
    {
        shared_ptr<Resource> res2(new Resource("Shared1", 2));
        {
            shared_ptr<Resource> res3 = res2;  // Share ownership
            cout << "Reference count: " << res2.use_count() << endl;
        }
        cout << "Reference count: " << res2.use_count() << endl;
        // Deleted when last reference is gone
    }
    
    // weak_ptr
    cout << "\nweak_ptr example:" << endl;
    {
        shared_ptr<Resource> shared(new Resource("SharedWeak", 2));
        weak_ptr<Resource> weak = shared;
        
        if (auto res = weak.lock()) {
            cout << "Resource still exists" << endl;
            res->display();
        }
        
        shared.reset();  // Release shared_ptr
        
        if (weak.expired()) {
            cout << "Resource no longer exists" << endl;
        }
    }
}

class ResourceManager {
private:
    vector<unique_ptr<Resource>> resources;
    
public:
    void addResource(string name, size_t size) {
        resources.push_back(unique_ptr<Resource>(new Resource(name, size)));
    }
    
    void displayAll() const {
        cout << "\nAll resources:" << endl;
        for (const auto& res : resources) {
            res->display();
        }
    }
    
    // No need for manual cleanup - unique_ptr handles it
};

int main() {
    try {
        cout << "Memory Leak Prevention Demonstration" << endl;
        cout << string(50, '=') << endl;
        
        // Bad practices - showing leaks
        demonstrateLeaks();
        
        // Good practices
        demonstrateRAII();
        demonstrateSmartPointers();
        
        // Resource management
        cout << "\nResource Management:" << endl;
        cout << string(30, '-') << endl;
        
        ResourceManager manager;
        manager.addResource("First", 2);
        manager.addResource("Second", 3);
        manager.displayAll();
        
        cout << "\nDemonstration completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
