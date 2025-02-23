---
layout: default
title: Part 3 - Getter and Setter Methods
nav_order: 3
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part3-getters-setters/
---

# Part 3: Getter and Setter Methods

## Overview
Getter and setter methods provide controlled access to class members, enabling proper encapsulation while allowing safe interaction with object data.

## Basic Implementation

### Simple Getters and Setters
```cpp
class Student {
private:
    string name;
    int age;
    double gpa;
    
public:
    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGpa() const { return gpa; }
    
    // Setters
    void setName(const string& n) { name = n; }
    void setAge(int a) { age = a; }
    void setGpa(double g) { gpa = g; }
};
```

### Validation in Setters
```cpp
class Student {
private:
    string name;
    int age;
    double gpa;
    
public:
    void setAge(int a) {
        if (a >= 0 && a <= 120) {
            age = a;
        } else {
            throw invalid_argument("Invalid age value");
        }
    }
    
    void setGpa(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        } else {
            throw invalid_argument("GPA must be between 0.0 and 4.0");
        }
    }
};
```

### Computed Properties
```cpp
class Rectangle {
private:
    double width;
    double height;
    
public:
    // Getters for computed properties
    double getArea() const {
        return width * height;
    }
    
    double getPerimeter() const {
        return 2 * (width + height);
    }
    
    // Setters that affect multiple properties
    void setDimensions(double w, double h) {
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        } else {
            throw invalid_argument("Dimensions must be positive");
        }
    }
};
```

## Practice Exercise

Create a product inventory system with proper getter and setter methods:
1. Product class with validation
2. Inventory management
3. Price calculations
4. Stock tracking

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Product {
private:
    string id;
    string name;
    double price;
    int stockLevel;
    double taxRate;
    
    // Private validation methods
    bool isValidPrice(double p) const {
        return p >= 0.0;
    }
    
    bool isValidStock(int s) const {
        return s >= 0;
    }
    
    bool isValidTaxRate(double r) const {
        return r >= 0.0 && r <= 1.0;
    }
    
public:
    // Constructor
    Product(string id, string name, double price = 0.0, int stock = 0, double tax = 0.1)
        : id(id), name(name) {
        setPrice(price);
        setStockLevel(stock);
        setTaxRate(tax);
    }
    
    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStockLevel() const { return stockLevel; }
    double getTaxRate() const { return taxRate; }
    
    // Computed getters
    double getTaxAmount() const {
        return price * taxRate;
    }
    
    double getTotalPrice() const {
        return price + getTaxAmount();
    }
    
    bool isInStock() const {
        return stockLevel > 0;
    }
    
    // Setters with validation
    void setPrice(double p) {
        if (!isValidPrice(p)) {
            throw invalid_argument("Price must be non-negative");
        }
        price = p;
    }
    
    void setStockLevel(int s) {
        if (!isValidStock(s)) {
            throw invalid_argument("Stock level must be non-negative");
        }
        stockLevel = s;
    }
    
    void setTaxRate(double r) {
        if (!isValidTaxRate(r)) {
            throw invalid_argument("Tax rate must be between 0 and 1");
        }
        taxRate = r;
    }
    
    // Stock management methods
    bool addStock(int quantity) {
        if (quantity < 0) {
            return false;
        }
        stockLevel += quantity;
        return true;
    }
    
    bool removeStock(int quantity) {
        if (quantity < 0 || quantity > stockLevel) {
            return false;
        }
        stockLevel -= quantity;
        return true;
    }
    
    // Display method
    void displayInfo() const {
        cout << fixed << setprecision(2);
        cout << "Product Information:" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Tax Rate: " << (taxRate * 100) << "%" << endl;
        cout << "Tax Amount: $" << getTaxAmount() << endl;
        cout << "Total Price: $" << getTotalPrice() << endl;
        cout << "Stock Level: " << stockLevel << endl;
        cout << "Status: " << (isInStock() ? "In Stock" : "Out of Stock") << endl;
    }
};

class Inventory {
private:
    vector<Product> products;
    
public:
    // Add product
    void addProduct(const Product& product) {
        products.push_back(product);
    }
    
    // Get product by ID
    Product* findProduct(const string& id) {
        for (auto& product : products) {
            if (product.getId() == id) {
                return &product;
            }
        }
        return nullptr;
    }
    
    // Display inventory
    void displayInventory() const {
        cout << "\nInventory Status:" << endl;
        cout << string(50, '=') << endl;
        
        for (const auto& product : products) {
            product.displayInfo();
            cout << string(50, '-') << endl;
        }
    }
};

int main() {
    try {
        // Create inventory
        Inventory inventory;
        
        // Add products
        inventory.addProduct(Product("P001", "Laptop", 999.99, 5, 0.1));
        inventory.addProduct(Product("P002", "Mouse", 29.99, 10, 0.1));
        inventory.addProduct(Product("P003", "Keyboard", 59.99, 8, 0.1));
        
        // Display initial inventory
        cout << "Initial Inventory:" << endl;
        inventory.displayInventory();
        
        // Test stock management
        cout << "\nTesting Stock Management:" << endl;
        cout << string(50, '=') << endl;
        
        Product* laptop = inventory.findProduct("P001");
        if (laptop) {
            cout << "\nTesting valid operations:" << endl;
            laptop->removeStock(2);
            cout << "Removed 2 laptops" << endl;
            laptop->addStock(1);
            cout << "Added 1 laptop" << endl;
            laptop->displayInfo();
            
            cout << "\nTesting invalid operations:" << endl;
            if (!laptop->removeStock(10)) {
                cout << "Failed to remove 10 laptops (insufficient stock)" << endl;
            }
            if (!laptop->removeStock(-1)) {
                cout << "Failed to remove -1 laptops (invalid quantity)" << endl;
            }
        }
        
        // Test price management
        cout << "\nTesting Price Management:" << endl;
        cout << string(50, '=') << endl;
        
        Product* mouse = inventory.findProduct("P002");
        if (mouse) {
            cout << "\nBefore price update:" << endl;
            mouse->displayInfo();
            
            mouse->setPrice(34.99);
            cout << "\nAfter price update:" << endl;
            mouse->displayInfo();
            
            try {
                mouse->setPrice(-10.0);
            } catch (const invalid_argument& e) {
                cout << "\nError: " << e.what() << endl;
            }
        }
        
        // Display final inventory
        cout << "\nFinal Inventory:" << endl;
        inventory.displayInventory();
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Best Practices

### Getter Design
1. Use const when appropriate
2. Return by value for small types
3. Return by const reference for large types
4. Consider lazy evaluation
5. Provide meaningful names

### Setter Design
1. Validate input data
2. Use appropriate parameter types
3. Consider side effects
4. Handle errors appropriately
5. Maintain invariants

### General Guidelines
1. Keep methods focused
2. Document behavior
3. Consider thread safety
4. Use consistent naming
5. Maintain encapsulation

## Common Mistakes to Avoid
1. Public data members
2. Missing validation
3. Inconsistent state
4. Poor error handling
5. Breaking encapsulation

## Next Steps
- Try the practice exercise
- Experiment with validation
- Consider taking [Module 7: Core OOP Concepts - Inheritance]({{ site.baseurl }}/tutorials/module7)
