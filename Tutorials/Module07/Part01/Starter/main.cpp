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
    // Create and populate a vector of integers
    vector<int> numbers;
    cout << "Adding numbers to vector:" << endl;
    for(int i = 1; i <= 5; i++) {
        numbers.push_back(i * 10);
        cout << "Added " << i * 10 << endl;
    }
    
    // Access elements using index
    cout << "\nFirst element: " << numbers[0] << endl;
    cout << "Last element: " << numbers.back() << endl;
    
    // Iterate using range-based for loop
    cout << "\nAll numbers:" << endl;
    for(const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Create a vector of Items
    vector<Item> inventory;
    inventory.push_back(Item("Sword", 1));
    inventory.push_back(Item("Potion", 5));
    inventory.push_back(Item("Shield", 2));
    
    // Use iterator to access elements
    cout << "\nInventory contents:" << endl;
    for(vector<Item>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
        it->display();
    }
    
    // Modify elements
    inventory[1].addQuantity(3);  // Add 3 more potions
    
    // Remove last item
    inventory.pop_back();
    
    // Display final inventory
    cout << "\nUpdated inventory:" << endl;
    for(const Item& item : inventory) {
        item.display();
    }
    
    return 0;
}
