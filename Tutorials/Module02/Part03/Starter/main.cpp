#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Module 2 - Part 3: Loops
 * Practice Exercise Starter Code
 * 
 * Task: Create a number guessing game that:
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
    
    // TODO: Implement the game loop
    // Remember to:
    // - Get user's guess
    // - Increment attempts counter
    // - Tell user if guess is too high or too low
    // - Continue until correct number is guessed
    // - Display number of attempts when game is won
    
    return 0;
}
