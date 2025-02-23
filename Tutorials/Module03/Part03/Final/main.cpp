#include <iostream>
using namespace std;

/**
 * Module 3 - Part 3: Function Parameters and Return Values
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Using reference parameters to modify multiple values
 * 2. Functions with default parameters
 * 3. Functions that return different values based on conditions
 */

// Function to calculate statistics using reference parameters
void getStats(const int* numbers, int size, int& min, int& max, double& avg) {
    if (size == 0) {
        min = max = 0;
        avg = 0.0;
        return;
    }
    
    min = max = numbers[0];
    int sum = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) min = numbers[i];
        if (numbers[i] > max) max = numbers[i];
        sum += numbers[i];
    }
    
    avg = static_cast<double>(sum) / size;
}

// Function with default parameters
void printLine(int length = 20, char symbol = '-', bool newline = true) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    if (newline) cout << endl;
}

// Function returning different values based on conditions
string getGrade(int score) {
    if (score >= 90) return "A";
    if (score >= 80) return "B";
    if (score >= 70) return "C";
    if (score >= 60) return "D";
    return "F";
}

int main() {
    // Test getStats
    int numbers[] = {4, 7, 2, 8, 1, 9, 3};
    int min, max;
    double avg;
    
    getStats(numbers, 7, min, max, avg);
    cout << "Array statistics:" << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Average: " << avg << endl;
    
    // Test printLine with different parameter combinations
    cout << "\nTesting printLine function:" << endl;
    printLine();                  // Default values
    printLine(10);               // Custom length
    printLine(15, '*');         // Custom symbol
    printLine(5, '#', false);   // No newline
    cout << endl;
    
    // Test getGrade with different scores
    cout << "\nTesting getGrade function:" << endl;
    cout << "Score 95: " << getGrade(95) << endl;
    cout << "Score 83: " << getGrade(83) << endl;
    cout << "Score 75: " << getGrade(75) << endl;
    cout << "Score 68: " << getGrade(68) << endl;
    cout << "Score 55: " << getGrade(55) << endl;
    
    return 0;
}
