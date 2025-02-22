// This tutorial demonstrates:
// 1. Pointers to objects
// 2. Dynamic object creation
// 3. Memory management
// 4. Array of object pointers

#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    string name;
    int value;
    
public:
    Item(string n, int v) : name(n), value(v) {
        cout << "📦 Created " << name << endl;
    }
    
    ~Item() {
        cout << "🗑️ Destroyed " << name << endl;
    }
    
    void display() const {
        cout << name << " (Value: " << value << ")" << endl;
    }
    
    int getValue() const { return value; }
    string getName() const { return name; }
};

class Inventory {
private:
    Item** items;  // Array of pointers to items
    int capacity;
    int count;
    
public:
    Inventory(int size) : capacity(size), count(0) {
        items = new Item*[capacity];  // Allocate array of pointers
        cout << "🎒 Created inventory with capacity " << capacity << endl;
    }
    
    ~Inventory() {
        // Clean up all items
        for(int i = 0; i < count; i++) {
            delete items[i];
        }
        // Delete array of pointers
        delete[] items;
        cout << "🗑️ Destroyed inventory" << endl;
    }
    
    bool addItem(string name, int value) {
        if(count < capacity) {
            items[count] = new Item(name, value);
            count++;
            return true;
        }
        cout << "❌ Inventory full!" << endl;
        return false;
    }
    
    void displayItems() const {
        cout << "\n📋 Inventory contents:" << endl;
        for(int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            items[i]->display();
        }
        cout << endl;
    }
    
    int getTotalValue() const {
        int total = 0;
        for(int i = 0; i < count; i++) {
            total += items[i]->getValue();
        }
        return total;
    }
};

int main() {
    // Create inventory
    Inventory backpack(3);
    
    // Add some items
    backpack.addItem("Health Potion", 50);
    backpack.addItem("Magic Scroll", 120);
    backpack.addItem("Ancient Coin", 500);
    backpack.addItem("Dragon Scale", 1000);  // Should fail
    
    // Display inventory
    backpack.displayItems();
    
    // Show total value
    cout << "💰 Total value: " << backpack.getTotalValue() << endl;
    
    return 0;
}
