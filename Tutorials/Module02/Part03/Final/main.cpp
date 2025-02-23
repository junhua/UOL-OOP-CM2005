#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Module 2 - Part 3: Loops
 * Practice Exercise Solution
 * 
 * This program implements a number guessing game that:
 * 1. Generates a random number between 1 and 100
 * 2. Asks the user to guess the number
 * 3. Tells if the guess is too high or too low
 * 4. Keeps track of number of guesses
 * 5. Continues until the correct number is guessed
 */

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;
    
    // Game loop - continues until correct number is guessed
    do {
        // Get user's guess
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        // Provide feedback
        if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "Congratulations! You guessed it in " 
                 << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}
