#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    cout << "Learning about function declarations and definitions!\n\n";
    
    // Calculate and store the area
    int area = calculateArea(5, 3);
    cout << "Direct output - Area: " << area << endl;
    
    // Use the printResult function to display the calculation
    printResult("The area is", area);
    
    // Test isPositive with different numbers
    int numbers[] = {5, -3, 0, 10};
    for(int num : numbers) {
        if(isPositive(num)) {
            cout << num << " is positive" << endl;
        } else {
            cout << num << " is not positive" << endl;
        }
    }
    
    return 0;
}
