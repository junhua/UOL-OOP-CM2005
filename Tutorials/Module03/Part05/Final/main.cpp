#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 5: Function Overloading
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Overloaded functions for finding maximum of different types
 * 2. Overloaded functions for printing different array types
 * 3. Overloaded functions for formatting different data types
 */

// Overloaded maximum functions
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

double findMax(double a, double b) {
    return (a > b) ? a : b;
}

char findMax(char a, char b) {
    return (a > b) ? a : b;
}

// Overloaded array print functions
void printArray(int arr[], int size) {
    cout << "Integer array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(double arr[], int size) {
    cout << "Double array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(char arr[], int size) {
    cout << "Character array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Overloaded format functions
string format(int number) {
    return "Number: " + to_string(number);
}

string format(double number, int precision) {
    string result = to_string(number);
    size_t decimal = result.find('.');
    if (decimal != string::npos) {
        result = result.substr(0, decimal + precision + 1);
    }
    return "Value: " + result;
}

string format(string text, bool uppercase) {
    if (uppercase) {
        for (char& c : text) {
            c = toupper(c);
        }
    }
    return "Text: " + text;
}

int main() {
    // Test maximum functions
    cout << "Maximum tests:" << endl;
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 3.14 and 2.72: " << findMax(3.14, 2.72) << endl;
    cout << "Max of 'a' and 'z': " << findMax('a', 'z') << endl;
    
    // Test array print functions
    cout << "\nArray print tests:" << endl;
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    
    printArray(intArr, 5);
    printArray(doubleArr, 5);
    printArray(charArr, 5);
    
    // Test format functions
    cout << "\nFormat tests:" << endl;
    cout << format(42) << endl;
    cout << format(3.14159, 2) << endl;
    cout << format("hello world", true) << endl;
    cout << format("GOODBYE WORLD", false) << endl;
    
    return 0;
}
