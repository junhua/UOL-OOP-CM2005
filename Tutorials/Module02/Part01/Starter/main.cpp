#include <iostream>
using namespace std;

/**
 * Module 2 - Part 1: Conditional Statements
 * Practice Exercise Starter Code
 * 
 * Task: Complete the program to determine what vehicles a person can operate
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
    
    // TODO: Implement the conditional logic here
    // Use if, else if, and else statements to determine
    // what vehicles the person can operate
    
    return 0;
}
