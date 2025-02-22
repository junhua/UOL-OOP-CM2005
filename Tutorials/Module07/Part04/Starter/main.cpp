// This tutorial demonstrates:
// 1. STL algorithms basics
// 2. Sorting algorithms
// 3. Searching algorithms
// 4. Transform operations

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Custom class to demonstrate algorithms with objects
class Product {
private:
    string name;
    double price;
    int quantity;
    
public:
    Product(string n, double p, int q) : name(n), price(p), quantity(q) {}
    
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    
    void display() const {
        cout << name << " - $" << price << " (Qty: " << quantity << ")" << endl;
    }
    
    // For sorting products by price
    bool operator<(const Product& other) const {
        return price < other.price;
    }
};

// Predicate function for finding expensive products
bool isExpensive(const Product& p) {
    return p.getPrice() > 50.0;
}

// Predicate function for counting low stock products
bool isLowStock(const Product& p) {
    return p.getQuantity() < 5;
}

// Transform function to calculate total value
double calculateValue(const Product& p) {
    return p.getPrice() * p.getQuantity();
}

int main() {
    // Create and populate vector of numbers
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // Sort numbers in ascending order
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted numbers:" << endl;
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Find first number greater than 50
    auto it = find_if(numbers.begin(), numbers.end(),
                     [](int n) { return n > 50; });
    
    if(it != numbers.end()) {
        cout << "\nFirst number greater than 50: " << *it << endl;
    }
    
    // Create vector of products
    vector<Product> inventory = {
        Product("Laptop", 899.99, 3),
        Product("Mouse", 24.99, 10),
        Product("Keyboard", 59.99, 4),
        Product("Monitor", 299.99, 2),
        Product("Headphones", 79.99, 8)
    };
    
    // Sort products by price
    sort(inventory.begin(), inventory.end());
    
    cout << "\nProducts sorted by price:" << endl;
    for(const Product& p : inventory) {
        p.display();
    }
    
    // Count products with low stock
    int lowStockCount = count_if(inventory.begin(), inventory.end(), isLowStock);
    cout << "\nNumber of low stock products: " << lowStockCount << endl;
    
    // Find first expensive product
    auto expensiveIt = find_if(inventory.begin(), inventory.end(), isExpensive);
    if(expensiveIt != inventory.end()) {
        cout << "\nFirst expensive product:" << endl;
        expensiveIt->display();
    }
    
    // Calculate total values
    vector<double> totalValues;
    transform(inventory.begin(), inventory.end(), 
              back_inserter(totalValues), calculateValue);
    
    cout << "\nTotal values of each product:" << endl;
    for(size_t i = 0; i < inventory.size(); ++i) {
        cout << inventory[i].getName() << ": $" << totalValues[i] << endl;
    }
    
    // Find maximum total value
    auto maxValueIt = max_element(totalValues.begin(), totalValues.end());
    if(maxValueIt != totalValues.end()) {
        cout << "\nHighest total value: $" << *maxValueIt << endl;
    }
    
    return 0;
}
