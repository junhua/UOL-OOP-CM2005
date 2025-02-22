// This tutorial demonstrates:
// 1. Vector container basics
// 2. Vector operations (push_back, pop_back)
// 3. Vector iterators
// 4. Vector element access

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Simple Item class to demonstrate vector with objects
class Item {
private:
    string name;
    int quantity;
    
public:
    Item(string n, int q) : name(n), quantity(q) {}
    
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    
    void addQuantity(int q) { quantity += q; }
    
    void display() const {
        cout << name << " (Qty: " << quantity << ")" << endl;
    }
};

int main() {
    // Create a vector of integers
    // vector<T> creates a dynamic array that can grow and shrink
    vector<int> numbers;
    
    // Add elements to the vector using push_back
    // push_back automatically resizes the vector if needed
    cout << "Adding numbers to vector:" << endl;
    for(int i = 1; i <= 5; i++) {
        numbers.push_back(i * 10);  // Adds element to end of vector
        cout << "Added " << i * 10 << endl;
    }
    
    // Access elements using array syntax []
    // First element is at index 0
    cout << "\nFirst element: " << numbers[0] << endl;
    // .back() returns reference to last element
    cout << "Last element: " << numbers.back() << endl;
    
    // Range-based for loop provides easy iteration
    // const reference prevents unnecessary copying
    cout << "\nAll numbers:" << endl;
    for(const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Create a vector of custom objects
    // Vector can store any type that is copyable
    vector<Item> inventory;
    
    // Add items to inventory
    // push_back creates a copy of the object
    inventory.push_back(Item("Sword", 1));
    inventory.push_back(Item("Potion", 5));
    inventory.push_back(Item("Shield", 2));
    
    // Iterator provides sequential access to elements
    // Iterator syntax is common across all STL containers
    cout << "\nInventory contents:" << endl;
    for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        it->display();  // Use -> to access members through iterator
    }
    
    // Modify element using array syntax
    // Vector elements can be modified after insertion
    inventory[1].addQuantity(3);  // Add 3 more potions
    
    // Remove last element using pop_back
    // pop_back reduces the vector size by 1
    inventory.pop_back();
    
    // Range-based for loop works with custom objects too
    // const reference prevents modification of elements
    cout << "\nUpdated inventory:" << endl;
    for(const Item& item : inventory) {
        item.display();
    }
    
    return 0;
}
