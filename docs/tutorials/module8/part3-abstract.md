---
layout: default
title: Part 3 - Abstract Classes and Pure Virtual Functions
nav_order: 3
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part3-abstract/
---

# Part 3: Abstract Classes and Pure Virtual Functions

## Overview
Abstract classes provide a way to define common interfaces that derived classes must implement. They serve as contracts for derived classes and help enforce consistent behavior across class hierarchies.

## Abstract Class Basics

### Pure Virtual Functions
```cpp
class Shape {  // Abstract class
public:
    virtual double getArea() const = 0;     // Pure virtual
    virtual double getPerimeter() const = 0; // Pure virtual
    virtual void draw() const = 0;          // Pure virtual
    virtual ~Shape() {}                     // Virtual destructor
};

// Cannot instantiate abstract class:
// Shape shape;  // Error!
```

### Interface Definition
```cpp
class Drawable {  // Interface (pure abstract class)
public:
    virtual void draw() const = 0;
    virtual void resize(double factor) = 0;
    virtual ~Drawable() = default;
};

class Printable {  // Another interface
public:
    virtual void print() const = 0;
    virtual ~Printable() = default;
};

// Multiple interface implementation
class Circle : public Shape, public Drawable, public Printable {
    // Must implement all pure virtual methods
};
```

### Abstract vs Concrete Classes
```cpp
class AbstractBase {
public:
    virtual void commonMethod() {
        // Default implementation
    }
    
    virtual void pureMethod() = 0;  // Makes class abstract
};

class ConcreteClass : public AbstractBase {
public:
    void pureMethod() override {
        // Must implement this
    }
};
```

## Practice Exercise

Create a device management system using abstract classes:
1. Abstract device interface
2. Different device types
3. Common and specific operations
4. Device management system

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract device interface
class Device {
protected:
    string name;
    bool isOn;
    
public:
    Device(string n) : name(n), isOn(false) {
        cout << "Creating device: " << name << endl;
    }
    
    virtual ~Device() {
        cout << "Destroying device: " << name << endl;
    }
    
    // Pure virtual methods
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void performFunction() = 0;
    
    // Virtual method with default implementation
    virtual void displayStatus() const {
        cout << "\nDevice Status:" << endl;
        cout << "Name: " << name << endl;
        cout << "Power: " << (isOn ? "ON" : "OFF") << endl;
    }
    
    string getName() const { return name; }
    bool isPowered() const { return isOn; }
};

class Printer : public Device {
private:
    int paperLevel;
    int inkLevel;
    
public:
    Printer(string name, int paper = 100, int ink = 100)
        : Device(name), paperLevel(paper), inkLevel(ink) {
        cout << "Initializing printer systems" << endl;
    }
    
    void powerOn() override {
        if (!isOn) {
            cout << name << ": Warming up printer..." << endl;
            isOn = true;
        }
    }
    
    void powerOff() override {
        if (isOn) {
            cout << name << ": Shutting down printer..." << endl;
            isOn = false;
        }
    }
    
    void performFunction() override {
        if (!isOn) {
            cout << name << ": Cannot print - printer is off" << endl;
            return;
        }
        if (paperLevel > 0 && inkLevel > 0) {
            cout << name << ": Printing document..." << endl;
            paperLevel--;
            inkLevel--;
        } else {
            cout << name << ": Cannot print - out of resources" << endl;
        }
    }
    
    void displayStatus() const override {
        Device::displayStatus();
        cout << "Paper Level: " << paperLevel << "%" << endl;
        cout << "Ink Level: " << inkLevel << "%" << endl;
    }
};

class Scanner : public Device {
private:
    string resolution;
    bool documentLoaded;
    
public:
    Scanner(string name, string res = "300dpi")
        : Device(name), resolution(res), documentLoaded(false) {
        cout << "Calibrating scanner" << endl;
    }
    
    void powerOn() override {
        if (!isOn) {
            cout << name << ": Scanner warming up..." << endl;
            isOn = true;
        }
    }
    
    void powerOff() override {
        if (isOn) {
            cout << name << ": Scanner shutting down..." << endl;
            isOn = false;
        }
    }
    
    void performFunction() override {
        if (!isOn) {
            cout << name << ": Cannot scan - scanner is off" << endl;
            return;
        }
        if (documentLoaded) {
            cout << name << ": Scanning at " << resolution << "..." << endl;
            documentLoaded = false;
        } else {
            cout << name << ": Please load a document first" << endl;
        }
    }
    
    void loadDocument() {
        documentLoaded = true;
        cout << name << ": Document loaded" << endl;
    }
    
    void displayStatus() const override {
        Device::displayStatus();
        cout << "Resolution: " << resolution << endl;
        cout << "Document Loaded: " << (documentLoaded ? "Yes" : "No") << endl;
    }
};

class Monitor : public Device {
private:
    string resolution;
    int brightness;
    
public:
    Monitor(string name, string res = "1920x1080", int bright = 50)
        : Device(name), resolution(res), brightness(bright) {
        cout << "Configuring display settings" << endl;
    }
    
    void powerOn() override {
        if (!isOn) {
            cout << name << ": Display powering on..." << endl;
            isOn = true;
        }
    }
    
    void powerOff() override {
        if (isOn) {
            cout << name << ": Display shutting down..." << endl;
            isOn = false;
        }
    }
    
    void performFunction() override {
        if (!isOn) {
            cout << name << ": Cannot display - monitor is off" << endl;
            return;
        }
        cout << name << ": Displaying content at " << resolution << endl;
        cout << "Brightness: " << brightness << "%" << endl;
    }
    
    void adjustBrightness(int level) {
        if (level >= 0 && level <= 100) {
            brightness = level;
            cout << name << ": Brightness adjusted to " << brightness << "%" << endl;
        }
    }
    
    void displayStatus() const override {
        Device::displayStatus();
        cout << "Resolution: " << resolution << endl;
        cout << "Brightness: " << brightness << "%" << endl;
    }
};

class DeviceManager {
private:
    vector<Device*> devices;
    
public:
    ~DeviceManager() {
        cout << "\nShutting down device manager..." << endl;
        for (Device* device : devices) {
            device->powerOff();
            delete device;
        }
    }
    
    void addDevice(Device* device) {
        devices.push_back(device);
        cout << "Added " << device->getName() << " to device manager" << endl;
    }
    
    void powerOnAll() {
        cout << "\nPowering on all devices:" << endl;
        cout << string(30, '-') << endl;
        for (Device* device : devices) {
            device->powerOn();
        }
    }
    
    void powerOffAll() {
        cout << "\nPowering off all devices:" << endl;
        cout << string(30, '-') << endl;
        for (Device* device : devices) {
            device->powerOff();
        }
    }
    
    void testAllDevices() {
        cout << "\nTesting all devices:" << endl;
        cout << string(50, '=') << endl;
        
        for (Device* device : devices) {
            cout << "\nTesting " << device->getName() << ":" << endl;
            cout << string(20, '-') << endl;
            
            device->displayStatus();
            device->powerOn();
            device->performFunction();
            device->powerOff();
        }
    }
};

int main() {
    try {
        DeviceManager manager;
        
        // Create and add devices
        cout << "Initializing devices:" << endl;
        cout << string(50, '-') << endl;
        
        Printer* printer = new Printer("HP LaserJet");
        Scanner* scanner = new Scanner("Epson V39");
        Monitor* monitor = new Monitor("Dell UltraSharp");
        
        manager.addDevice(printer);
        manager.addDevice(scanner);
        manager.addDevice(monitor);
        
        // Test specific device features
        scanner->loadDocument();
        monitor->adjustBrightness(75);
        
        // Test all devices
        manager.testAllDevices();
        
        cout << "\nDevice management completed successfully" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Best Practices

### Abstract Class Design
1. Pure virtual methods
2. Virtual destructor
3. Protected members
4. Common functionality
5. Clear interfaces

### Implementation Guidelines
1. Override all pure virtuals
2. Document overrides
3. Base class calls
4. Error handling
5. Resource management

### Design Considerations
1. Interface segregation
2. Single responsibility
3. Dependency inversion
4. Liskov substitution
5. Open-closed principle

## Common Mistakes to Avoid
1. Missing implementations
2. Forgetting destructors
3. Interface bloat
4. Deep hierarchies
5. Tight coupling

## Next Steps
- Try the practice exercise
- Experiment with abstract classes
- Move on to [Part 4: Virtual Tables and Dynamic Dispatch]({{ site.baseurl }}/tutorials/module8/part4-vtables)
