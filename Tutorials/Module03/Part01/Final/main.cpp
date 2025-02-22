#include <iostream>
using namespace std;

// Function with no parameters and no return value (void)
void sayHello() {
    cout << "Hello! Welcome to the program!\n";
}

// Function that demonstrates code reuse
void printStars() {
    for(int i = 0; i < 20; i++) {
        cout << "*";
    }
    cout << "\n";
}

int main() {
    cout << "Learning about functions!\n\n";
    
    // Calling a basic function
    sayHello();
    
    cout << "\nPrinting a decorative border:\n";
    // Using the same function multiple times shows how functions prevent code duplication
    printStars();
    cout << "This is some text\n";
    printStars();
    
    return 0;
}
