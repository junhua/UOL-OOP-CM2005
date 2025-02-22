#include <iostream>
#include <string>
#include <iomanip>  // For setprecision
using namespace std;

// Print overloads - Same name, different parameter types
void print(int x) {
    cout << "Integer: " << x << endl;
}

void print(double x) {
    cout << "Double: " << fixed << setprecision(2) << x << endl;
}

void print(string x) {
    cout << "String: \"" << x << "\"" << endl;
}

// Max overloads - Same name, different parameter counts
int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);  // Reuse the two-parameter version
}

// FormatText overloads - Same name, different parameter combinations
string formatText(string text) {
    // Convert to uppercase
    string result = text;
    for(char& c : result) {
        c = toupper(c);
    }
    return result;
}

string formatText(string text, int repeat) {
    // Repeat string n times
    string result = "";
    for(int i = 0; i < repeat; i++) {
        result += text;
    }
    return result;
}

string formatText(string text1, string text2) {
    // Concatenate with space
    return text1 + " " + text2;
}

int main() {
    cout << "Learning about function overloading!\n\n";
    
    // Test print with different types
    cout << "Testing print function:\n";
    print(42);
    print(3.14159);
    print("Hello");
    
    // Test max with different numbers of parameters
    cout << "\nTesting max function:\n";
    cout << "Max of 10 and 20: " << max(10, 20) << endl;
    cout << "Max of 10, 20, and 15: " << max(10, 20, 15) << endl;
    
    // Test formatText with different parameters
    cout << "\nTesting formatText function:\n";
    cout << "Uppercase: " << formatText("hello") << endl;
    cout << "Repeated: " << formatText("ha", 3) << endl;
    cout << "Concatenated: " << formatText("hello", "world") << endl;
    
    return 0;
}
