#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 8 - Part 4: Virtual Tables and Dynamic Dispatch
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Virtual table implementation
 * 2. Dynamic dispatch mechanism
 * 3. Plugin architecture
 * 4. Resource management
 */

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
    vector<Plugin*> plugins;
    string managerName;
    
public:
    PluginManager(string name = "Plugin System") : managerName(name) {
        cout << "Starting " << managerName << endl;
    }
    
    ~PluginManager() {
        cout << "\nShutting down plugin manager..." << endl;
        for (Plugin* plugin : plugins) {
            delete plugin;
        }
    }
    
    void loadPlugin(Plugin* plugin) {
        cout << "\nLoading plugin: " << plugin->getName() << endl;
        plugins.push_back(plugin);
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
        
        manager.loadPlugin(new ImagePlugin("PNG", 4096));
        manager.loadPlugin(new AudioPlugin(44100));
        manager.loadPlugin(new NetworkPlugin("HTTPS", 443, true));
        
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
