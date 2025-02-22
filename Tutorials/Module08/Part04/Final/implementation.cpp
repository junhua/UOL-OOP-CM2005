// This tutorial demonstrates:
// 1. "is-a" relationship (inheritance)
// 2. "has-a" relationship (composition)
// 3. When to use inheritance vs composition
// 4. Benefits and limitations of each approach

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Component class for Engine (used in composition)
class Engine {
private:
    string type;
    int horsepower;
    
public:
    Engine(const string& t, int hp) 
        : type(t), horsepower(hp) {}
    
    void start() {
        cout << type << " engine starting... Vroom!" << endl;
    }
    
    void stop() {
        cout << type << " engine stopping..." << endl;
    }
    
    int getHorsepower() const { return horsepower; }
    string getType() const { return type; }
};

// Base class for vehicles
class Vehicle {
protected:
    string brand;
    string model;
    
public:
    Vehicle(const string& b, const string& m) 
        : brand(b), model(m) {}
    
    virtual void displayInfo() const {
        cout << brand << " " << model;
    }
    
    virtual ~Vehicle() {}
};

// Car IS-A Vehicle (inheritance)
// Car HAS-A Engine (composition)
class Car : public Vehicle {
private:
    Engine engine;  // Composition
    int numDoors;
    
public:
    Car(const string& brand, const string& model, 
        const string& engineType, int horsepower, int doors)
        : Vehicle(brand, model),
          engine(engineType, horsepower),
          numDoors(doors) {}
    
    void start() {
        cout << brand << " " << model << " - ";
        engine.start();
    }
    
    void stop() {
        cout << brand << " " << model << " - ";
        engine.stop();
    }
    
    virtual void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " (Car)" << endl;
        cout << "Engine: " << engine.getType() 
             << " (" << engine.getHorsepower() << " hp)" << endl;
        cout << "Doors: " << numDoors << endl;
    }
};

// Motorcycle IS-A Vehicle (inheritance)
// Motorcycle HAS-A Engine (composition)
class Motorcycle : public Vehicle {
private:
    Engine engine;  // Composition
    string style;   // e.g., "Sport", "Cruiser", etc.
    
public:
    Motorcycle(const string& brand, const string& model,
              const string& engineType, int horsepower,
              const string& s)
        : Vehicle(brand, model),
          engine(engineType, horsepower),
          style(s) {}
    
    void start() {
        cout << brand << " " << model << " - ";
        engine.start();
    }
    
    void stop() {
        cout << brand << " " << model << " - ";
        engine.stop();
    }
    
    virtual void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " (Motorcycle)" << endl;
        cout << "Engine: " << engine.getType() 
             << " (" << engine.getHorsepower() << " hp)" << endl;
        cout << "Style: " << style << endl;
    }
};

// Bicycle IS-A Vehicle (inheritance)
// But does NOT have an Engine (no composition)
class Bicycle : public Vehicle {
private:
    int numGears;
    string type;  // e.g., "Mountain", "Road", etc.
    
public:
    Bicycle(const string& brand, const string& model,
           int gears, const string& t)
        : Vehicle(brand, model),
          numGears(gears),
          type(t) {}
    
    virtual void displayInfo() const override {
        Vehicle::displayInfo();
        cout << " (Bicycle)" << endl;
        cout << "Type: " << type << endl;
        cout << "Number of gears: " << numGears << endl;
    }
};

int main() {
    // Create various vehicles
    Car car("Toyota", "Camry", "V6", 300, 4);
    Motorcycle bike("Harley-Davidson", "Sportster", "V-Twin", 150, "Cruiser");
    Bicycle bicycle("Trek", "Mountain 100", 21, "Mountain");
    
    // Demonstrate inheritance ("is-a" relationship)
    cout << "Demonstrating inheritance (is-a relationship):" << endl;
    vector<Vehicle*> vehicles = {&car, &bike, &bicycle};
    
    for(const Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();
        cout << endl;
    }
    
    // Demonstrate composition ("has-a" relationship)
    cout << "\nDemonstrating composition (has-a relationship):" << endl;
    cout << "Starting vehicles with engines:" << endl;
    car.start();
    bike.start();
    // bicycle.start();  // Bicycle doesn't have an engine!
    
    cout << "\nStopping vehicles with engines:" << endl;
    car.stop();
    bike.stop();
    // bicycle.stop();  // Bicycle doesn't have an engine!
    
    return 0;
}
