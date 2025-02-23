#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 8 - Part 3: Abstract Classes and Pure Virtual Functions
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Abstract class implementation
 * 2. Pure virtual methods
 * 3. Interface design
 * 4. Resource management
 */

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
