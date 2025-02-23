#include <iostream>
using namespace std;

// Determine what vehicles a person can operate based on age and license status
int main() {
    int age;
    char hasLicense;
    
    cout << "Enter your age: ";
    cin >> age;
    
    cout << "Do you have a license? (y/n): ";
    cin >> hasLicense;
    
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
