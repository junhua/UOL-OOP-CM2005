// This tutorial demonstrates:
// 1. "is-a" relationship (inheritance)
// 2. "has-a" relationship (composition)
// 3. When to use inheritance vs composition
// 4. Benefits and limitations of each approach

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Engine class to demonstrate composition
class Engine {
private:
    string type;
    int horsepower;

public:
    Engine(const string& t, int hp) : type(t), horsepower(hp) {}

    void start() {
        cout << type << " engine starting... Vroom!" << endl;
    }

    void stop() {
        cout << type << " engine stopping..." << endl;
    }

    int getHorsepower() const {
        return horsepower;
    }

    string getType() const {
        return type;
    }
};

// Vehicle base class to demonstrate inheritance
class Vehicle {
protected:
    string brand;
    string model;

public:
    Vehicle(const string& br, const string& md) : brand(br), model(md) {}

    virtual void displayInfo() {
        cout << brand << " " << model << endl;
    }

    virtual ~Vehicle() = default;
};

// Car class that inherits from Vehicle
class Car : public Vehicle {
private:
    Engine engine; // Composition: Car "has-a" Engine
    int numDoors;

public:
    Car(const string& br, const string& md, const string& engineType, int hp, int doors)
        : Vehicle(br, md), engine(engineType, hp), numDoors(doors) {}

    void start() {
        cout << brand << " " << model << " - ";
        engine.start();
    }

    void stop() {
        cout << brand << " " << model << " - ";
        engine.stop();
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Engine: " << engine.getType() << " (" << engine.getHorsepower() << " hp)" << endl;
        cout << "Doors: " << numDoors << endl;
    }
};

// Motorcycle class that inherits from Vehicle
class Motorcycle : public Vehicle {
private:
    Engine engine; // Composition: Motorcycle "has-a" Engine
    string style;

public:
    Motorcycle(const string& br, const string& md, const string& engineType, int hp, const string& style)
        : Vehicle(br, md), engine(engineType, hp), style(style) {}

    void start() {
        cout << brand << " " << model << " - ";
        engine.start();
    }

    void stop() {
        cout << brand << " " << model << " - ";
        engine.stop();
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Engine: " << engine.getType() << " (" << engine.getHorsepower() << " hp)" << endl;
        cout << "Style: " << style << endl;
    }
};

// Bicycle class that inherits from Vehicle
class Bicycle : public Vehicle {
private:
    int numGears;
    string type;

public:
    Bicycle(const string& br, const string& md, int gears, const string& type)
        : Vehicle(br, md), numGears(gears), type(type) {}

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Type: " << type << endl;
        cout << "Number of gears: " << numGears << endl;
    }
};

int main() {
    // Create instances of each vehicle type
    Car car("Toyota", "Camry", "V6", 300, 4);
    Motorcycle motorcycle("Harley-Davidson", "Sportster", "V-Twin", 150, "Cruiser");
    Bicycle bicycle("Trek", "Mountain 100", 21, "Mountain");

    // Demonstrate inheritance ("is-a" relationship)
    cout << "Demonstrating inheritance (is-a relationship):" << endl;
    vector<Vehicle*> vehicles;
    vehicles.push_back(&car);
    vehicles.push_back(&motorcycle);
    vehicles.push_back(&bicycle);

    for (Vehicle* v : vehicles) {
        v->displayInfo();
        cout << endl;
    }

    // Demonstrate composition ("has-a" relationship)
    cout << "Demonstrating composition (has-a relationship):" << endl;
    cout << "Starting vehicles with engines:" << endl;
    car.start();
    motorcycle.start();
    cout << endl;

    cout << "Stopping vehicles with engines:" << endl;
    car.stop();
    motorcycle.stop();
    cout << endl;

    return 0;
}
