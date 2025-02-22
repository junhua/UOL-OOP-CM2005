#include <iostream>
using namespace std;

// Global variable - accessible from all functions
double programVersion = 1.0;

// Function using static local variable
void countCalls() {
    // Static variables retain their value between function calls
    static int count = 0;
    count++;
    cout << "Function has been called " << count << " times\n";
}

// Demonstrating variable shadowing
void demonstrateScope(int value) {  // Parameter shadows global programVersion
    cout << "Parameter value: " << value << endl;
    cout << "Global programVersion: " << programVersion << endl;
    
    // Local variable shadows parameter
    int value = 100;  // This hides the parameter
    cout << "Local value: " << value << endl;
}

// Modifying global variable
void modifyGlobal() {
    double programVersion = 2.0;  // Local variable shadows global
    cout << "Local programVersion: " << programVersion << endl;
    
    // Use :: to access global variable when shadowed
    ::programVersion = 3.0;
    cout << "Modified global programVersion: " << ::programVersion << endl;
}

int main() {
    cout << "Learning about variable scope!\n\n";
    
    // Access global variable
    cout << "Program version (global): " << programVersion << endl;
    
    // Test static local variable
    cout << "\nTesting static local variable:\n";
    countCalls();
    countCalls();
    countCalls();
    
    // Test variable shadowing
    cout << "\nTesting variable shadowing:\n";
    demonstrateScope(50);
    
    // Test global variable modification
    cout << "\nTesting global variable modification:\n";
    cout << "Before modifyGlobal: " << programVersion << endl;
    modifyGlobal();
    cout << "After modifyGlobal: " << programVersion << endl;
    
    // Demonstrate block scope
    cout << "\nDemonstrating block scope:\n";
    int x = 1;
    cout << "Outer x: " << x << endl;
    {
        int x = 2;  // Shadows outer x
        cout << "Inner block - x: " << x << endl;
        {
            int x = 3;  // Shadows both outer variables
            cout << "Innermost block - x: " << x << endl;
        }
        cout << "Back to inner block - x: " << x << endl;
    }
    cout << "Back to outer block - x: " << x << endl;
    
    return 0;
}
