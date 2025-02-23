#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

/**
 * Module 7 - Part 1: Base Classes and Derived Classes
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Base and derived class relationships
 * 2. Virtual methods and overriding
 * 3. Constructor chaining
 * 4. Polymorphic behavior
 */

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
        return price * pow(0.85, age);  // 15% depreciation per year
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
        // Adjust value based on fuel type
        if (fuelType == "Electric") {
            baseValue *= 1.1;  // 10% premium for electric
        } else if (fuelType == "Hybrid") {
            baseValue *= 1.05;  // 5% premium for hybrid
        }
        return baseValue;
    }
};

class Motorcycle : public Vehicle {
private:
    string type;  // Sport, Classic, etc.
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
        // Adjust value based on type and features
        if (type == "Sport") {
            baseValue *= 0.9;  // Sport bikes depreciate faster
        } else if (type == "Classic") {
            baseValue *= 1.1;  // Classic bikes may appreciate
        }
        if (hasSidecar) {
            baseValue *= 1.15;  // 15% premium for sidecar
        }
        return baseValue;
    }
};

class Truck : public Vehicle {
private:
    double cargoCapacity;  // in tons
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
        // Adjust value based on capacity and features
        baseValue *= (1.0 + (cargoCapacity / 20.0));  // Value increases with capacity
        if (hasTrailer) {
            baseValue *= 1.2;  // 20% premium for trailer
        }
        return baseValue;
    }
};

class VehicleFleet {
private:
    vector<Vehicle*> vehicles;
    string fleetName;
    
public:
    VehicleFleet(string name = "Main Fleet") : fleetName(name) {
        cout << "Creating fleet: " << fleetName << endl;
    }
    
    ~VehicleFleet() {
        cout << "Destroying fleet: " << fleetName << endl;
        for (Vehicle* vehicle : vehicles) {
            delete vehicle;
        }
    }
    
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
    
    void displayFleet() const {
        cout << "\nFleet Information: " << fleetName << endl;
        cout << string(50, '=') << endl;
        
        if (vehicles.empty()) {
            cout << "No vehicles in fleet" << endl;
            return;
        }
        
        for (const Vehicle* vehicle : vehicles) {
            vehicle->displayInfo();
            cout << string(50, '-') << endl;
        }
        
        cout << "\nFleet Summary:" << endl;
        cout << "Total Vehicles: " << vehicles.size() << endl;
        cout << "Total Fleet Value: $" << fixed << setprecision(2) 
             << calculateTotalValue() << endl;
    }
    
    double calculateTotalValue() const {
        double total = 0.0;
        for (const Vehicle* vehicle : vehicles) {
            total += vehicle->calculateValue();
        }
        return total;
    }
};

int main() {
    try {
        // Create fleet
        VehicleFleet fleet("Demo Fleet");
        
        // Add various vehicles
        cout << "\nAdding vehicles to fleet:" << endl;
        cout << string(50, '-') << endl;
        
        fleet.addVehicle(new Car("Toyota", "Camry", 2020, 25000, 4, "Hybrid"));
        fleet.addVehicle(new Car("Tesla", "Model 3", 2022, 45000, 4, "Electric"));
        fleet.addVehicle(new Motorcycle("Harley-Davidson", "Sportster", 
                                      2019, 15000, "Classic", false));
        fleet.addVehicle(new Motorcycle("BMW", "R1200", 2021, 18000, 
                                      "Sport", true));
        fleet.addVehicle(new Truck("Ford", "F-150", 2018, 35000, 2.5, true));
        
        // Display fleet information
        fleet.displayFleet();
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
