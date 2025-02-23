#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Number guessing game using loops
int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 7;
    
    cout << "Guess the number between 1 and 100" << endl;
    cout << "You have " << MAX_ATTEMPTS << " attempts" << endl;
    
    while (attempts < MAX_ATTEMPTS) {
        cout << "\nAttempt " << attempts + 1 << ": ";
        cin >> guess;
        attempts++;
        
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed it in " << attempts << " attempts!" << endl;
            return 0;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Too high!" << endl;
        }
        
        if (attempts < MAX_ATTEMPTS) {
            cout << "Attempts remaining: " << MAX_ATTEMPTS - attempts << endl;
        }
    }
    
    cout << "\nGame Over! The number was: " << secretNumber << endl;
    cout << "You used all " << MAX_ATTEMPTS << " attempts" << endl;
    
    return 0;
}
