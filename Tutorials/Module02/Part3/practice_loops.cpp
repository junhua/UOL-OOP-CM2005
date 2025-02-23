#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Module 2 - Part 3: Loops
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * - Different types of loops (for, while, do-while)
 * - Input validation patterns
 * - Game state management
 * - Statistics tracking
 * - Score calculation
 */

int main() {
    // Constants
    const int EASY_MAX = 50;
    const int MEDIUM_MAX = 100;
    const int HARD_MAX = 200;
    const int MAX_ATTEMPTS = 10;
    const double EASY_MULTIPLIER = 1.0;
    const double MEDIUM_MULTIPLIER = 1.5;
    const double HARD_MULTIPLIER = 2.0;
    
    // Game variables
    int secretNumber;
    int guess;
    int attempts;
    int maxRange;
    double scoreMultiplier;
    char difficulty;
    char playAgain;
    bool validInput;
    
    // Statistics
    int gamesPlayed = 0;
    int gamesWon = 0;
    int totalAttempts = 0;
    int bestScore = MAX_ATTEMPTS;
    
    // Seed random number generator
    srand(time(0));
    
    // Display welcome message
    cout << "=== Number Guessing Game ===\n\n"
         << "Difficulty Levels:\n"
         << "E - Easy   (1-" << EASY_MAX << ")\n"
         << "M - Medium (1-" << MEDIUM_MAX << ")\n"
         << "H - Hard   (1-" << HARD_MAX << ")\n\n";
    
    // Main game loop
    do {
        // Get difficulty level
        do {
            cout << "Select difficulty (E/M/H): ";
            cin >> difficulty;
            difficulty = toupper(difficulty);
            
            if (cin.fail() || (difficulty != 'E' && 
                              difficulty != 'M' && 
                              difficulty != 'H')) {
                cout << "Invalid choice. Please enter E, M, or H.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = false;
            } else {
                validInput = true;
            }
        } while (!validInput);
        
        // Set difficulty parameters
        switch (difficulty) {
            case 'E':
                maxRange = EASY_MAX;
                scoreMultiplier = EASY_MULTIPLIER;
                break;
            case 'H':
                maxRange = HARD_MAX;
                scoreMultiplier = HARD_MULTIPLIER;
                break;
            default:
                maxRange = MEDIUM_MAX;
                scoreMultiplier = MEDIUM_MULTIPLIER;
        }
        
        // Generate random number
        secretNumber = rand() % maxRange + 1;
        attempts = 0;
        gamesPlayed++;
        
        cout << "\nGame " << gamesPlayed << " started!\n"
             << "I'm thinking of a number between 1 and " << maxRange << "\n"
             << "You have " << MAX_ATTEMPTS << " attempts.\n\n";
        
        // Game round loop
        for (attempts = 1; attempts <= MAX_ATTEMPTS; attempts++) {
            // Get and validate guess
            do {
                cout << "Attempt " << attempts << "/" << MAX_ATTEMPTS 
                     << "\nEnter your guess: ";
                cin >> guess;
                
                if (cin.fail() || guess < 1 || guess > maxRange) {
                    cout << "Invalid guess. Enter a number between 1 and " 
                         << maxRange << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    validInput = false;
                } else {
                    validInput = true;
                }
            } while (!validInput);
            
            // Clear buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            // Check guess
            if (guess == secretNumber) {
                cout << "\nCongratulations! You guessed it!\n";
                gamesWon++;
                
                // Update statistics
                totalAttempts += attempts;
                if (attempts < bestScore) {
                    bestScore = attempts;
                    cout << "New best score!\n";
                }
                
                // Calculate round score
                int roundScore = static_cast<int>((MAX_ATTEMPTS - attempts + 1) * 
                                                 scoreMultiplier * 100);
                cout << "Round score: " << roundScore << endl;
                break;
            } else {
                cout << "Too " << (guess < secretNumber ? "low" : "high") << "!\n";
                
                if (attempts == MAX_ATTEMPTS) {
                    cout << "\nGame Over! The number was: " << secretNumber << endl;
                    totalAttempts += attempts;
                }
            }
        }
        
        // Display current statistics
        cout << "\n=== Current Statistics ===\n"
             << "Games played: " << gamesPlayed << endl
             << "Games won: " << gamesWon << endl
             << "Win rate: " << fixed << setprecision(1)
             << (gamesWon * 100.0 / gamesPlayed) << "%\n"
             << "Average attempts: " 
             << (static_cast<double>(totalAttempts) / gamesPlayed) << endl
             << "Best score: " << bestScore << endl;
        
        // Ask to play again
        do {
            cout << "\nPlay again? (y/n): ";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            
            if (cin.fail() || (playAgain != 'Y' && playAgain != 'N')) {
                cout << "Invalid input. Please enter y or n.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = false;
            } else {
                validInput = true;
            }
        } while (!validInput);
        
        // Clear buffer before next game
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "\n";
        
    } while (playAgain == 'Y');
    
    // Display final statistics
    cout << "\n=== Final Statistics ===\n"
         << "Total games played: " << gamesPlayed << endl
         << "Games won: " << gamesWon << endl
         << "Final win rate: " << fixed << setprecision(1)
         << (gamesWon * 100.0 / gamesPlayed) << "%\n"
         << "Overall average attempts: " 
         << (static_cast<double>(totalAttempts) / gamesPlayed) << endl
         << "Best score achieved: " << bestScore << endl
         << "\nThanks for playing!\n";
    
    return 0;
}
