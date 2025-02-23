#include <iostream>
#include <string>
using namespace std;

// Text entry system with input validation using break and continue
int main() {
    const int MAX_ENTRIES = 5;
    const int MIN_LENGTH = 3;
    const string EXIT = "quit";
    
    string entries[MAX_ENTRIES];
    int count = 0;
    
    cout << "Enter up to " << MAX_ENTRIES << " text entries" << endl;
    cout << "Rules:" << endl;
    cout << "- Minimum " << MIN_LENGTH << " characters" << endl;
    cout << "- No spaces allowed" << endl;
    cout << "- Enter '" << EXIT << "' to stop" << endl;
    
    while (count < MAX_ENTRIES) {
        string input;
        cout << "\nEntry " << count + 1 << ": ";
        cin >> input;
        
        if (input == EXIT) {
            break;
        }
        
        if (input.length() < MIN_LENGTH) {
            cout << "Too short! Must be at least " << MIN_LENGTH << " characters" << endl;
            continue;
        }
        
        if (input.find(' ') != string::npos) {
            cout << "Spaces not allowed!" << endl;
            continue;
        }
        
        entries[count++] = input;
        cout << "Entry accepted" << endl;
    }
    
    cout << "\nValid entries collected: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ": " << entries[i] << endl;
    }
    
    return 0;
}
