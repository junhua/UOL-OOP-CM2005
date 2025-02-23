#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 6 - Part 3: Getter and Setter Methods
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Proper getter/setter implementation
 * 2. Input validation
 * 3. Computed properties
 * 4. Inventory management
 */

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
    // Constructor with validation
    Product(string id, string name, double price = 0.0, int stock = 0, double tax = 0.1)
        : id(id), name(name) {
        // Use setters for validation
        setPrice(price);
        setStockLevel(stock);
        setTaxRate(tax);
        cout << "Created product: " << name << endl;
    }
    
    // Basic getters
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
    
    bool isLowStock() const {
        return stockLevel > 0 && stockLevel <= 5;
    }
    
    // Setters with validation
    void setPrice(double p) {
        if (!isValidPrice(p)) {
            throw invalid_argument("Price must be non-negative");
        }
        price = p;
        cout << "Updated price for " << name << " to $" << fixed << setprecision(2) << price << endl;
    }
    
    void setStockLevel(int s) {
        if (!isValidStock(s)) {
            throw invalid_argument("Stock level must be non-negative");
        }
        stockLevel = s;
        cout << "Updated stock level for " << name << " to " << stockLevel << endl;
    }
    
    void setTaxRate(double r) {
        if (!isValidTaxRate(r)) {
            throw invalid_argument("Tax rate must be between 0 and 1");
        }
        taxRate = r;
        cout << "Updated tax rate for " << name << " to " << (taxRate * 100) << "%" << endl;
    }
    
    // Stock management methods
    bool addStock(int quantity) {
        if (quantity < 0) {
            cout << "Cannot add negative stock quantity" << endl;
            return false;
        }
        
        int newLevel = stockLevel + quantity;
        setStockLevel(newLevel);
        return true;
    }
    
    bool removeStock(int quantity) {
        if (quantity < 0) {
            cout << "Cannot remove negative stock quantity" << endl;
            return false;
        }
        
        if (quantity > stockLevel) {
            cout << "Insufficient stock to remove" << endl;
            return false;
        }
        
        int newLevel = stockLevel - quantity;
        setStockLevel(newLevel);
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
        cout << "Stock Level: " << stockLevel;
        if (isLowStock()) {
            cout << " (LOW STOCK)";
        }
        cout << endl;
        cout << "Status: " << (isInStock() ? "In Stock" : "Out of Stock") << endl;
    }
};

class Inventory {
private:
    vector<Product> products;
    string inventoryName;
    
public:
    // Constructor
    Inventory(string name = "Main Inventory") : inventoryName(name) {
        cout << "Created inventory: " << inventoryName << endl;
    }
    
    // Add product
    void addProduct(const Product& product) {
        products.push_back(product);
        cout << "Added " << product.getName() << " to inventory" << endl;
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
        cout << "\nInventory Status: " << inventoryName << endl;
        cout << string(50, '=') << endl;
        
        if (products.empty()) {
            cout << "No products in inventory" << endl;
            return;
        }
        
        for (const auto& product : products) {
            product.displayInfo();
            cout << string(50, '-') << endl;
        }
        
        // Display summary
        cout << "\nInventory Summary:" << endl;
        cout << "Total Products: " << products.size() << endl;
        cout << "Products in Stock: " << countInStock() << endl;
        cout << "Products Low Stock: " << countLowStock() << endl;
    }
    
private:
    // Helper methods for inventory statistics
    int countInStock() const {
        int count = 0;
        for (const auto& product : products) {
            if (product.isInStock()) {
                count++;
            }
        }
        return count;
    }
    
    int countLowStock() const {
        int count = 0;
        for (const auto& product : products) {
            if (product.isLowStock()) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    try {
        // Create inventory
        Inventory inventory("Electronics Store");
        
        // Add products
        cout << "\nAdding Products:" << endl;
        cout << string(50, '-') << endl;
        
        inventory.addProduct(Product("P001", "Laptop", 999.99, 5, 0.1));
        inventory.addProduct(Product("P002", "Mouse", 29.99, 10, 0.1));
        inventory.addProduct(Product("P003", "Keyboard", 59.99, 8, 0.1));
        
        // Display initial inventory
        inventory.displayInventory();
        
        // Test stock management
        cout << "\nTesting Stock Management:" << endl;
        cout << string(50, '-') << endl;
        
        Product* laptop = inventory.findProduct("P001");
        if (laptop) {
            cout << "\nTesting valid operations:" << endl;
            laptop->removeStock(2);
            laptop->addStock(1);
            laptop->displayInfo();
            
            cout << "\nTesting invalid operations:" << endl;
            laptop->removeStock(10);  // Should fail
            laptop->removeStock(-1);  // Should fail
            laptop->addStock(-5);     // Should fail
        }
        
        // Test price management
        cout << "\nTesting Price Management:" << endl;
        cout << string(50, '-') << endl;
        
        Product* mouse = inventory.findProduct("P002");
        if (mouse) {
            cout << "\nBefore price update:" << endl;
            mouse->displayInfo();
            
            mouse->setPrice(34.99);
            cout << "\nAfter price update:" << endl;
            mouse->displayInfo();
            
            try {
                mouse->setPrice(-10.0);  // Should throw exception
            } catch (const invalid_argument& e) {
                cout << "\nCaught expected error: " << e.what() << endl;
            }
        }
        
        // Test tax rate management
        cout << "\nTesting Tax Rate Management:" << endl;
        cout << string(50, '-') << endl;
        
        Product* keyboard = inventory.findProduct("P003");
        if (keyboard) {
            try {
                keyboard->setTaxRate(0.15);  // Valid
                keyboard->setTaxRate(2.0);   // Should throw exception
            } catch (const invalid_argument& e) {
                cout << "Caught expected error: " << e.what() << endl;
            }
        }
        
        // Display final inventory
        inventory.displayInventory();
        
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
    }
    
    return 0;
}
