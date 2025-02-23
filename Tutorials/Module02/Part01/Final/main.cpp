#include <iostream>
using namespace std;

/**
 * Module 2 - Part 1: Conditional Statements
 * Practice Exercise Solution
 * 
 * This program determines what vehicles a person can operate
 * based on their age and license status.
 * 
 * Rules:
 * - Under 16: Can ride a bicycle
 * - 16-17 with license: Can drive a car with supervision
 * - 18+ with license: Can drive a car
 * - Any age without license: Can only ride a bicycle
 */

int main() {
    int age;
    char hasLicense;
    
    // Get user input
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Do you have a license? (y/n): ";
    cin >> hasLicense;
    
    // Determine what vehicles the person can operate
    if (age >= 18) {
        if (hasLicense == 'y') {
            cout << "You can drive a car" << endl;
        } else {
            cout << "You can only ride a bicycle" << endl;
        }
    } else if (age >= 16) {
        if (hasLicense == 'y') {
            cout << "You can drive a car with supervision" << endl;
        } else {
            cout << "You can only ride a bicycle" << endl;
        }
    } else {
        cout << "You can only ride a bicycle" << endl;
    }
    
    return 0;
}
