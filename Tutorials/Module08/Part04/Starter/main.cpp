#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/**
 * Module 8 - Part 4: Virtual Tables and Dynamic Dispatch
 * Practice Exercise Starter Code
 * 
 * Task: Create a plugin system demonstrating:
 * 1. Plugin interface with virtual methods
 * 2. Different plugin implementations
 * 3. Dynamic plugin loading
 * 4. Method dispatch demonstration
 */

// TODO: Create Plugin abstract base class with:
// - Protected members for name and version
// - Constructor and virtual destructor
// - Pure virtual methods:
//   * initialize()
//   * execute()
//   * cleanup()
// - Virtual displayInfo() with default implementation
// - Non-virtual getters

// TODO: Create ImagePlugin class that:
// - Inherits from Plugin
// - Adds format and resolution settings
// - Implements all pure virtual methods
// - Overrides displayInfo()

// TODO: Create AudioPlugin class that:
// - Inherits from Plugin
// - Adds supported formats and sample rate
// - Implements all pure virtual methods
// - Overrides displayInfo()

// TODO: Create NetworkPlugin class that:
// - Inherits from Plugin
// - Adds protocol, port, and security settings
// - Implements all pure virtual methods
// - Overrides displayInfo()

// TODO: Create PluginManager class to:
// - Manage collection of plugins
// - Load plugins into system
// - Initialize and execute plugins
// - Clean up resources

int main() {
    try {
        // TODO: Create plugin manager
        
        // TODO: Create and load plugins
        // - Image plugin with format/resolution
        // - Audio plugin with sample rate
        // - Network plugin with protocol/port
        
        // TODO: Test plugin system
        // - Display plugin info
        // - Initialize plugins
        // - Execute plugins
        // - Clean up plugins
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
