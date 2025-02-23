---
layout: default
title: Part 1 - Base Classes and Derived Classes
nav_order: 1
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part1-base-derived/
---

# Part 1: Base Classes and Derived Classes

## Overview
Inheritance allows classes to inherit properties and methods from other classes, enabling code reuse and establishing relationships between classes.

## Base Class Definition

### Basic Base Class
```cpp
class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;
    
public:
    // Constructor
    Vehicle(string make, string model, int year, double price)
        : make(make), model(model), year(year), price(price) {}
    
    // Virtual destructor
    virtual ~Vehicle() {}
    
    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    // Virtual methods
    virtual void displayInfo() const {
        cout << year << " " << make << " " << model << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
    }
    
    virtual double calculateValue() const {
        // Basic depreciation
        int age = 2024 - year;
        return price * pow(0.85, age);  // 15% depreciation per year
    }
};
```

### Derived Class Implementation
```cpp
class Car : public Vehicle {
private:
    int numDoors;
    string fuelType;
    
public:
    // Constructor
    Car(string make, string model, int year, double price,
        int doors, string fuel)
        : Vehicle(make, model, year, price),
          numDoors(doors), fuelType(fuel) {}
    
    // Additional getters
    int getNumDoors() const { return numDoors; }
    string getFuelType() const { return fuelType; }
    
    // Override base class methods
    void displayInfo() const override {
        Vehicle::displayInfo();  // Call base class method
        cout << "Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
    
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();
        // Adjust for fuel type
        if (fuelType == "Electric") {
            baseValue *= 1.1;  // 10% premium for electric
        }
        return baseValue;
    }
};
```

## Inheritance Concepts

### Constructor Chaining
```cpp
class Truck : public Vehicle {
private:
    double cargoCapacity;
    bool hasTrailer;
    
public:
    // Constructor chains to base class
    Truck(string make, string model, int year, double price,
          double capacity, bool trailer)
        : Vehicle(make, model, year, price),  // Base class initialization
          cargoCapacity(capacity),            // Member initialization
          hasTrailer(trailer) {}
    
    // Rest of implementation...
};
```

### Method Overriding
```cpp
class Motorcycle : public Vehicle {
private:
    string type;  // Sport, Cruiser, etc.
    
public:
    Motorcycle(string make, string model, int year, double price,
              string type)
        : Vehicle(make, model, year, price), type(type) {}
    
    // Override with specific behavior
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();
        // Adjust for motorcycle type
        if (type == "Sport") {
            baseValue *= 0.9;  // Sport bikes depreciate faster
        } else if (type == "Classic") {
            baseValue *= 1.1;  // Classic bikes may appreciate
        }
        return baseValue;
    }
};
```

## Practice Exercise

Create a vehicle management system demonstrating inheritance:
1. Base Vehicle class
2. Different vehicle types
3. Value calculations
4. Information display

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    double price;
    
public:
    // Constructor
    Vehicle(string make, string model, int year, double price)
        : make(make), model(model), year(year), price(price) {
        cout << "Creating vehicle: " << year << " " << make << " " << model << endl;
    }
    
    // Virtual destructor
    virtual ~Vehicle() {
        cout << "Destroying vehicle: " << year << " " << make << " " << model << endl;
    }
    
    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    
    // Virtual methods
    virtual void displayInfo() const {
        cout << "\nVehicle Information:" << endl;
        cout << "===================" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Original Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Current Value: $" << calculateValue() << endl;
    }
    
    virtual double calculateValue() const {
        int age = 2024 - year;
        return price * pow(0.85, age);
    }
};

class Car : public Vehicle {
private:
    int numDoors;
    string fuelType;
    
public:
    Car(string make, string model, int year, double price,
        int doors, string fuel)
        : Vehicle(make, model, year, price),
          numDoors(doors), fuelType(fuel) {
        cout << "Creating car with " << doors << " doors" << endl;
    }
    
    ~Car() {
        cout << "Destroying car: " << getMake() << " " << getModel() << endl;
    }
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Type: Car" << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
    
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();
        if (fuelType == "Electric") {
            baseValue *= 1.1;
        } else if (fuelType == "Hybrid") {
            baseValue *= 1.05;
        }
        return baseValue;
    }
};

class Motorcycle : public Vehicle {
private:
    string type;
    bool hasSidecar;
    
public:
    Motorcycle(string make, string model, int year, double price,
               string type, bool sidecar)
        : Vehicle(make, model, year, price),
          type(type), hasSidecar(sidecar) {
        cout << "Creating " << type << " motorcycle" << endl;
    }
    
    ~Motorcycle() {
        cout << "Destroying motorcycle: " << getMake() << " " << getModel() << endl;
    }
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Type: Motorcycle (" << type << ")" << endl;
        cout << "Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
    }
    
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();
        if (type == "Sport") {
            baseValue *= 0.9;
        } else if (type == "Classic") {
            baseValue *= 1.1;
        }
        if (hasSidecar) {
            baseValue *= 1.15;
        }
        return baseValue;
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;
    bool hasTrailer;
    
public:
    Truck(string make, string model, int year, double price,
          double capacity, bool trailer)
        : Vehicle(make, model, year, price),
          cargoCapacity(capacity), hasTrailer(trailer) {
        cout << "Creating truck with " << capacity << " ton capacity" << endl;
    }
    
    ~Truck() {
        cout << "Destroying truck: " << getMake() << " " << getModel() << endl;
    }
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        cout << "Type: Truck" << endl;
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
        cout << "Trailer: " << (hasTrailer ? "Yes" : "No") << endl;
    }
    
    double calculateValue() const override {
        double baseValue = Vehicle::calculateValue();
        // Adjust for capacity and trailer
        baseValue *= (1.0 + (cargoCapacity / 20.0));  // Increase value with capacity
        if (hasTrailer) {
            baseValue *= 1.2;
        }
        return baseValue;
    }
};

class VehicleFleet {
private:
    vector<Vehicle*> vehicles;
    
public:
    // Destructor to clean up vehicles
    ~VehicleFleet() {
        for (Vehicle* vehicle : vehicles) {
            delete vehicle;
        }
    }
    
    // Add vehicle to fleet
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
    
    // Display all vehicles
    void displayFleet() const {
        cout << "\nFleet Information:" << endl;
        cout << string(50, '=') << endl;
        
        for (const Vehicle* vehicle : vehicles) {
            vehicle->displayInfo();
            cout << string(50, '-') << endl;
        }
        
        cout << "\nFleet Summary:" << endl;
        cout << "Total Vehicles: " << vehicles.size() << endl;
        cout << "Total Fleet Value: $" << calculateTotalValue() << endl;
    }
    
    // Calculate total fleet value
    double calculateTotalValue() const {
        double total = 0.0;
        for (const Vehicle* vehicle : vehicles) {
            total += vehicle->calculateValue();
        }
        return total;
    }
};

int main() {
    VehicleFleet fleet;
    
    // Add various vehicles
    fleet.addVehicle(new Car("Toyota", "Camry", 2020, 25000, 4, "Hybrid"));
    fleet.addVehicle(new Car("Tesla", "Model 3", 2022, 45000, 4, "Electric"));
    fleet.addVehicle(new Motorcycle("Harley-Davidson", "Sportster", 2019, 15000, "Classic", false));
    fleet.addVehicle(new Motorcycle("BMW", "R1200", 2021, 18000, "Sport", true));
    fleet.addVehicle(new Truck("Ford", "F-150", 2018, 35000, 2.5, true));
    
    // Display fleet information
    fleet.displayFleet();
    
    return 0;
}
```

## Best Practices

### Base Class Design
1. Use virtual destructors
2. Consider pure virtual methods
3. Protect member access
4. Document inheritance intent
5. Consider final classes

### Derived Class Design
1. Use override keyword
2. Initialize base class properly
3. Follow LSP principles
4. Document overridden behavior
5. Consider composition

### General Guidelines
1. Keep inheritance simple
2. Use meaningful relationships
3. Avoid deep hierarchies
4. Consider alternatives
5. Test thoroughly

## Common Mistakes to Avoid
1. Forgetting virtual destructors
2. Improper initialization
3. Breaking LSP
4. Deep inheritance chains
5. Tight coupling

## Next Steps
- Try the practice exercise
- Experiment with inheritance
- Move on to [Part 2: "is-a" Relationship]({{ site.baseurl }}/tutorials/module7/part2-is-a)
