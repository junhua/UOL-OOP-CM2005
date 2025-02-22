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
    
    // Operator< enables sorting products by price
    // Required by STL algorithms that compare elements
    bool operator<(const Product& other) const {
        return price < other.price;  // Sort based on price
    }
};

// Predicate function for finding expensive products
// Used with find_if and count_if algorithms
bool isExpensive(const Product& p) {
    return p.getPrice() > 50.0;  // Consider products over $50 as expensive
}

// Predicate function for counting low stock products
// Used with count_if algorithm
bool isLowStock(const Product& p) {
    return p.getQuantity() < 5;  // Consider less than 5 items as low stock
}

// Transform function to calculate total value
// Used with transform algorithm to compute new values
double calculateValue(const Product& p) {
    return p.getPrice() * p.getQuantity();  // Total value = price * quantity
}

int main() {
    // Create and populate vector of numbers
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    
    // sort() arranges elements in ascending order
    // Uses operator< for comparison
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted numbers:" << endl;
    for(int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // find_if() searches for first element matching predicate
    // Lambda function provides inline predicate
    auto it = find_if(numbers.begin(), numbers.end(),
                     [](int n) { return n > 50; });
    
    if(it != numbers.end()) {
        cout << "\nFirst number greater than 50: " << *it << endl;
    }
    
    // Create vector of products for testing algorithms
    vector<Product> inventory = {
        Product("Laptop", 899.99, 3),
        Product("Mouse", 24.99, 10),
        Product("Keyboard", 59.99, 4),
        Product("Monitor", 299.99, 2),
        Product("Headphones", 79.99, 8)
    };
    
    // sort() uses Product's operator< to order elements
    // Elements are sorted by price (ascending)
    sort(inventory.begin(), inventory.end());
    
    cout << "\nProducts sorted by price:" << endl;
    for(const Product& p : inventory) {
        p.display();
    }
    
    // count_if() counts elements matching predicate
    // Uses isLowStock function to check each element
    int lowStockCount = count_if(inventory.begin(), inventory.end(), isLowStock);
    cout << "\nNumber of low stock products: " << lowStockCount << endl;
    
    // find_if() with isExpensive predicate
    // Finds first product with price > $50
    auto expensiveIt = find_if(inventory.begin(), inventory.end(), isExpensive);
    if(expensiveIt != inventory.end()) {
        cout << "\nFirst expensive product:" << endl;
        expensiveIt->display();
    }
    
    // transform() applies function to range and stores results
    // back_inserter provides iterator that uses push_back
    vector<double> totalValues;
    transform(inventory.begin(), inventory.end(), 
              back_inserter(totalValues), calculateValue);
    
    cout << "\nTotal values of each product:" << endl;
    for(size_t i = 0; i < inventory.size(); ++i) {
        cout << inventory[i].getName() << ": $" << totalValues[i] << endl;
    }
    
    // max_element() finds largest element in range
    // Uses operator< for comparison
    auto maxValueIt = max_element(totalValues.begin(), totalValues.end());
    if(maxValueIt != totalValues.end()) {
        cout << "\nHighest total value: $" << *maxValueIt << endl;
    }
    
    return 0;
}
