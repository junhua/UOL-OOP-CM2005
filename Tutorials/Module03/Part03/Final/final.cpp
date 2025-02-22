#include <iostream>
#include <string>
using namespace std;

// Calculate total cost including tax
double calculateTotal(double price, int quantity, double taxRate) {
    double subtotal = price * quantity;
    return subtotal + (subtotal * taxRate);
}

// Convert numeric grade to letter grade
char gradeToLetter(int score) {
    if (score >= 90) return 'A';
    if (score >= 80) return 'B';
    if (score >= 70) return 'C';
    if (score >= 60) return 'D';
    return 'F';
}

// Validate username length
bool isValidUsername(string username) {
    return username.length() >= 5;
}

// Print order details
void printOrderSummary(string item, double total, bool expressShipping) {
    cout << "\n📦 ORDER SUMMARY" << endl;
    cout << "Item: " << item << endl;
    cout << "Total: $" << total << endl;
    cout << "Shipping: " << (expressShipping ? "Express" : "Standard") << endl;
}

int main() {
    cout << "Learning about function parameters and return values!\n\n";
    
    // Test calculateTotal
    double total = calculateTotal(10.99, 2, 0.08);
    cout << "Total cost with tax: $" << total << endl;
    
    // Test gradeToLetter with different scores
    int scores[] = {95, 85, 75, 65, 55};
    for(int score : scores) {
        char grade = gradeToLetter(score);
        cout << "Score " << score << " = Grade " << grade << endl;
    }
    
    // Test isValidUsername
    string usernames[] = {"user", "validuser", "ab"};
    for(string name : usernames) {
        if(isValidUsername(name)) {
            cout << name << " is valid" << endl;
        } else {
            cout << name << " is not valid" << endl;
        }
    }
    
    // Test printOrderSummary
    printOrderSummary("Book", 25.99, true);
    
    return 0;
}
