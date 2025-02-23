#include <iostream>
using namespace std;

/**
 * Module 2 - Part 4: Break and Continue Statements
 * Practice Exercise Solution
 * 
 * This program:
 * 1. Asks user for numbers until they enter 0
 * 2. Skips negative numbers (using continue)
 * 3. Exits if sum exceeds 100 (using break)
 * 4. Prints the final sum and count of valid numbers
 */

int main() {
    int number;
    int sum = 0;
    int count = 0;
    
    cout << "Enter numbers (0 to stop):" << endl;
    
    // Main program loop
    while (true) {
        cout << "Enter a number: ";
        cin >> number;
        
        // Exit condition
        if (number == 0) {
            break;  // Exit loop when user enters 0
        }
        
        // Skip negative numbers
        if (number < 0) {
            cout << "Negative number skipped" << endl;
            continue;  // Skip to next iteration
        }
        
        // Add number to sum and increment counter
        sum += number;
        count++;
        
        // Check if sum exceeds 100
        if (sum > 100) {
            cout << "Sum exceeded 100!" << endl;
            break;  // Exit loop if sum > 100
        }
    }
    
    // Print final results
    cout << "Final sum: " << sum << endl;
    cout << "Valid numbers entered: " << count << endl;
    
    return 0;
}
