#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/**
 * Module 2 - Part 4: Break and Continue Statements
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * - Break statement usage
 * - Continue statement usage
 * - Input validation
 * - Statistics tracking
 * - Error handling
 */

int main() {
    // Constants
    const int MAX_VALUE = 100;
    const int SENTINEL = -1;
    const int MAX_SUM = 1000;
    const int MAX_INVALID_INPUTS = 3;
    const int DIVISIBLE_BY = 5;
    
    // Variables
    int number;
    int sum = 0;
    int validCount = 0;
    int skippedCount = 0;
    int invalidCount = 0;
    string exitReason;
    bool validInput;
    
    // Display instructions
    cout << "=== Number Processing Program ===\n\n"
         << "Rules:\n"
         << "- Enter positive numbers up to " << MAX_VALUE << endl
         << "- Numbers must be divisible by " << DIVISIBLE_BY << endl
         << "- Enter " << SENTINEL << " to finish\n"
         << "- Program will stop if sum exceeds " << MAX_SUM << endl
         << "- " << MAX_INVALID_INPUTS << " invalid inputs will terminate program\n\n";
    
    // Main processing loop
    while (true) {
        // Get and validate input
        cout << "\nEnter a number: ";
        cin >> number;
        
        if (cin.fail()) {
            invalidCount++;
            cout << "Invalid input! Numbers only. (" << invalidCount 
                 << "/" << MAX_INVALID_INPUTS << " invalid attempts)\n";
            
            if (invalidCount >= MAX_INVALID_INPUTS) {
                exitReason = "maximum invalid inputs reached";
                break;
            }
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Check for sentinel value
        if (number == SENTINEL) {
            exitReason = "sentinel value entered";
            break;
        }
        
        // Apply processing rules
        if (number < 0) {
            cout << "Skipping negative number\n";
            skippedCount++;
            continue;
        }
        
        if (number > MAX_VALUE) {
            cout << "Skipping number above " << MAX_VALUE << endl;
            skippedCount++;
            continue;
        }
        
        if (number % DIVISIBLE_BY != 0) {
            cout << "Skipping number not divisible by " << DIVISIBLE_BY << endl;
            skippedCount++;
            continue;
        }
        
        // Process valid number
        sum += number;
        validCount++;
        
        // Display progress
        cout << "Number accepted. Current sum: " << sum << endl;
        
        // Check sum limit
        if (sum > MAX_SUM) {
            exitReason = "sum exceeded maximum";
            break;
        }
    }
    
    // Display results
    cout << "\n=== Processing Results ===\n";
    
    if (validCount > 0) {
        cout << fixed << setprecision(2);
        cout << "Numbers processed: " << (validCount + skippedCount) << endl
             << "Valid numbers: " << validCount << endl
             << "Skipped numbers: " << skippedCount << endl
             << "Final sum: " << sum << endl
             << "Average of valid numbers: " 
             << (static_cast<double>(sum) / validCount) << endl;
    } else {
        cout << "No valid numbers were processed.\n";
    }
    
    // Display termination reason
    cout << "\nProgram terminated: " << exitReason << endl;
    
    // Display processing statistics
    if (validCount + skippedCount > 0) {
        cout << "\n=== Processing Statistics ===\n"
             << "Acceptance rate: " << fixed << setprecision(1)
             << (validCount * 100.0 / (validCount + skippedCount)) << "%\n"
             << "Invalid inputs: " << invalidCount << endl;
    }
    
    // Provide feedback based on results
    cout << "\nFeedback:\n";
    if (invalidCount > 0) {
        cout << "- Work on entering valid numeric input\n";
    }
    if (skippedCount > validCount && (validCount + skippedCount > 0)) {
        cout << "- Many numbers were skipped. Review the rules.\n";
    }
    if (sum > MAX_SUM) {
        cout << "- Sum grew too large. Try smaller numbers.\n";
    }
    if (validCount == 0) {
        cout << "- No valid numbers processed. Try again!\n";
    }
    
    return 0;
}
