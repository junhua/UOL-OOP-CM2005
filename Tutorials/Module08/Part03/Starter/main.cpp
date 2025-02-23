#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 8 - Part 3: Abstract Classes and Pure Virtual Functions
 * Practice Exercise Starter Code
 * 
 * Task: Create a device management system demonstrating:
 * 1. Abstract device interface
 * 2. Different device types
 * 3. Common and specific operations
 * 4. Device management system
 */

// TODO: Create Device abstract base class with:
// - Protected members for name and power status
// - Constructor and virtual destructor
// - Pure virtual methods:
//   * powerOn()
//   * powerOff()
//   * performFunction()
// - Virtual displayStatus() with default implementation
// - Non-virtual getters

// TODO: Create Printer class that:
// - Inherits from Device
// - Adds paper and ink level tracking
// - Implements all pure virtual methods
// - Overrides displayStatus()

// TODO: Create Scanner class that:
// - Inherits from Device
// - Adds resolution and document status
// - Implements all pure virtual methods
// - Adds document loading functionality
// - Overrides displayStatus()

// TODO: Create Monitor class that:
// - Inherits from Device
// - Adds resolution and brightness
// - Implements all pure virtual methods
// - Adds brightness adjustment
// - Overrides displayStatus()

// TODO: Create DeviceManager class to:
// - Manage collection of devices
// - Add devices to system
// - Power control operations
// - Test device functionality

int main() {
    try {
        // TODO: Create device manager
        
        // TODO: Create and add devices
        // - Printer with paper/ink levels
        // - Scanner with resolution
        // - Monitor with brightness
        
        // TODO: Test specific features
        // - Load document in scanner
        // - Adjust monitor brightness
        
        // TODO: Test all devices
        // - Show status
        // - Power on/off
        // - Perform functions
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
