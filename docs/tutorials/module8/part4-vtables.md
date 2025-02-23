---
layout: default
title: Part 4 - Virtual Tables and Dynamic Dispatch
nav_order: 4
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part4-vtables/
---

# Part 4: Virtual Tables and Dynamic Dispatch

## Overview
Virtual tables (vtables) and dynamic dispatch are the mechanisms that enable runtime polymorphism in C++. Understanding how they work helps in making better design decisions and optimizing performance.

## Virtual Table Mechanism

### Basic Structure
```cpp
// Memory layout with vtable pointer
class Base {
    void* vptr;  // Hidden vtable pointer
    // Other members...
public:
    virtual void method() { }
};

// Vtable structure (conceptual)
struct VTable {
    void (*method1)();
    void (*method2)();
    // Other virtual function pointers...
};
```

### Memory Layout
```cpp
class Shape {
    void* vptr;      // Points to Shape's vtable
    string name;     // Member data
    double area;     // Member data
public:
    virtual void draw() { }
    virtual double getArea() { return area; }
};

class Circle : public Shape {
    void* vptr;      // Points to Circle's vtable
    double radius;   // Additional member data
public:
    void draw() override { }
    double getArea() override { return 3.14159 * radius * radius; }
};
```

### Dynamic Dispatch Flow
```cpp
Shape* shape = new Circle(5);
shape->draw();  // Runtime lookup:
                // 1. Access shape's vptr
                // 2. Find draw() in vtable
                // 3. Call Circle::draw()
```

## Practice Exercise

Create a plugin system demonstrating virtual tables:
1. Plugin interface with virtual methods
2. Different plugin implementations
3. Dynamic plugin loading
4. Method dispatch demonstration

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Plugin interface
class Plugin {
protected:
    string name;
    string version;
    
public:
    Plugin(string n, string v) : name(n), version(v) {
        cout << "Loading plugin: " << name << " v" << version << endl;
    }
    
    virtual ~Plugin() {
        cout << "Unloading plugin: " << name << endl;
    }
    
    // Virtual interface methods
    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual void cleanup() = 0;
    
    // Virtual with default implementation
    virtual void displayInfo() const {
        cout << "\nPlugin Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Version: " << version << endl;
    }
    
    string getName() const { return name; }
    string getVersion() const { return version; }
};

class ImagePlugin : public Plugin {
private:
    string format;
    int maxResolution;
    
public:
    ImagePlugin(string format, int res)
        : Plugin("ImageProcessor", "1.0"),
          format(format), maxResolution(res) {
        cout << "Configuring image processor for " << format << endl;
    }
    
    void initialize() override {
        cout << name << ": Loading image libraries..." << endl;
        cout << "Supported format: " << format << endl;
        cout << "Max resolution: " << maxResolution << "px" << endl;
    }
    
    void execute() override {
        cout << name << ": Processing image in " << format << " format" << endl;
        cout << "Applying filters and optimizations" << endl;
    }
    
    void cleanup() override {
        cout << name << ": Cleaning up temporary files" << endl;
        cout << "Freeing image resources" << endl;
    }
    
    void displayInfo() const override {
        Plugin::displayInfo();
        cout << "Format: " << format << endl;
        cout << "Max Resolution: " << maxResolution << "px" << endl;
    }
};

class AudioPlugin : public Plugin {
private:
    vector<string> supportedFormats;
    int sampleRate;
    
public:
    AudioPlugin(int rate)
        : Plugin("AudioProcessor", "2.1"), sampleRate(rate) {
        supportedFormats = {"MP3", "WAV", "FLAC"};
        cout << "Initializing audio processing engine" << endl;
    }
    
    void initialize() override {
        cout << name << ": Setting up audio pipeline..." << endl;
        cout << "Sample rate: " << sampleRate << "Hz" << endl;
        cout << "Loading audio codecs" << endl;
    }
    
    void execute() override {
        cout << name << ": Processing audio stream" << endl;
        cout << "Applying audio effects" << endl;
    }
    
    void cleanup() override {
        cout << name << ": Closing audio streams" << endl;
        cout << "Releasing audio resources" << endl;
    }
    
    void displayInfo() const override {
        Plugin::displayInfo();
        cout << "Sample Rate: " << sampleRate << "Hz" << endl;
        cout << "Supported Formats: ";
        for (const auto& format : supportedFormats) {
            cout << format << " ";
        }
        cout << endl;
    }
};

class NetworkPlugin : public Plugin {
private:
    string protocol;
    int port;
    bool secure;
    
public:
    NetworkPlugin(string proto, int p, bool s)
        : Plugin("NetworkHandler", "1.5"),
          protocol(proto), port(p), secure(s) {
        cout << "Setting up network handler" << endl;
    }
    
    void initialize() override {
        cout << name << ": Configuring network settings..." << endl;
        cout << "Protocol: " << protocol << endl;
        cout << "Port: " << port << endl;
        cout << "Security: " << (secure ? "Enabled" : "Disabled") << endl;
    }
    
    void execute() override {
        cout << name << ": Processing network requests" << endl;
        cout << "Handling " << protocol << " traffic on port " << port << endl;
    }
    
    void cleanup() override {
        cout << name << ": Closing network connections" << endl;
        cout << "Cleaning up network resources" << endl;
    }
    
    void displayInfo() const override {
        Plugin::displayInfo();
        cout << "Protocol: " << protocol << endl;
        cout << "Port: " << port << endl;
        cout << "Security: " << (secure ? "Enabled" : "Disabled") << endl;
    }
};

class PluginManager {
private:
    vector<unique_ptr<Plugin>> plugins;
    string managerName;
    
public:
    PluginManager(string name = "Plugin System") : managerName(name) {
        cout << "Starting " << managerName << endl;
    }
    
    void loadPlugin(unique_ptr<Plugin> plugin) {
        cout << "\nLoading plugin: " << plugin->getName() << endl;
        plugins.push_back(move(plugin));
    }
    
    void initializeAll() {
        cout << "\nInitializing all plugins:" << endl;
        cout << string(50, '=') << endl;
        
        for (const auto& plugin : plugins) {
            cout << "\nInitializing " << plugin->getName() << ":" << endl;
            cout << string(20, '-') << endl;
            plugin->initialize();
        }
    }
    
    void executeAll() {
        cout << "\nExecuting all plugins:" << endl;
        cout << string(50, '=') << endl;
        
        for (const auto& plugin : plugins) {
            cout << "\nExecuting " << plugin->getName() << ":" << endl;
            cout << string(20, '-') << endl;
            plugin->execute();
        }
    }
    
    void cleanupAll() {
        cout << "\nCleaning up all plugins:" << endl;
        cout << string(50, '=') << endl;
        
        for (const auto& plugin : plugins) {
            cout << "\nCleaning up " << plugin->getName() << ":" << endl;
            cout << string(20, '-') << endl;
            plugin->cleanup();
        }
    }
    
    void displayAllInfo() const {
        cout << "\nPlugin System Status:" << endl;
        cout << string(50, '=') << endl;
        cout << "Manager: " << managerName << endl;
        cout << "Loaded Plugins: " << plugins.size() << endl;
        
        for (const auto& plugin : plugins) {
            plugin->displayInfo();
        }
    }
};

int main() {
    try {
        PluginManager manager("Advanced Plugin System");
        
        // Load plugins
        cout << "\nLoading plugins:" << endl;
        cout << string(50, '-') << endl;
        
        manager.loadPlugin(make_unique<ImagePlugin>("PNG", 4096));
        manager.loadPlugin(make_unique<AudioPlugin>(44100));
        manager.loadPlugin(make_unique<NetworkPlugin>("HTTPS", 443, true));
        
        // Initialize and run plugins
        manager.displayAllInfo();
        manager.initializeAll();
        manager.executeAll();
        manager.cleanupAll();
        
        cout << "\nPlugin system shutting down" << endl;
        cout << string(50, '=') << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Memory Layout Details

### Object Structure
```
Base Object Layout:
+----------------+
| vptr           | --> Base vtable
+----------------+
| member data    |
+----------------+

Derived Object Layout:
+----------------+
| vptr           | --> Derived vtable
+----------------+
| base members   |
+----------------+
| derived members|
+----------------+
```

### Vtable Structure
```
Base Vtable:
+----------------+
| type_info      | --> Type information
+----------------+
| Base::method1  | --> Function pointer
+----------------+
| Base::method2  | --> Function pointer
+----------------+

Derived Vtable:
+----------------+
| type_info      | --> Type information
+----------------+
| Derived::method1| --> Overridden
+----------------+
| Base::method2  | --> Inherited
+----------------+
```

## Performance Considerations

### Virtual Call Overhead
1. Memory access for vptr
2. Vtable lookup
3. Function pointer dereferencing
4. Cache implications

### Memory Usage
1. Extra pointer per object
2. Vtable storage
3. Type information
4. Alignment requirements

### Optimization Tips
1. Use inline when possible
2. Consider final methods
3. Profile virtual calls
4. Cache hot methods
5. Minimize virtual depth

## Best Practices

### Design Guidelines
1. Virtual when needed
2. Consider alternatives
3. Plan inheritance
4. Document virtuals
5. Test performance

### Implementation Tips
1. Virtual destructors
2. Override keyword
3. Final when done
4. Base class calls
5. Smart pointers

## Common Mistakes to Avoid
1. Unnecessary virtuals
2. Missing overrides
3. Deep hierarchies
4. Virtual in constructors
5. Object slicing

## Next Steps
- Try the practice exercise
- Experiment with vtables
- Review Module 8 concepts
- Consider taking [Module 9: Pointers and Dynamic Memory]({{ site.baseurl }}/tutorials/module9)
