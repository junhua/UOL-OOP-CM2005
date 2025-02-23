#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

/**
 * Module 2 - Part 5: Simple Program Examples
 * Practice Exercise Solution
 * 
 * This program implements a pattern memory game that:
 * 1. Generates a random pattern of characters (R, B, G for Red, Blue, Green)
 * 2. Asks the player to repeat the pattern
 * 3. Keeps track of score
 * 4. Increases pattern length after each successful attempt
 * 5. Ends game on wrong pattern or when player chooses to quit
 */

int main() {
    // Initialize random seed
    srand(time(0));
    
    // Variables for game
    string pattern;
    string playerInput;
    int score = 0;
    int patternLength = 3;  // Start with length 3
    char colors[] = {'R', 'B', 'G'};
    char playAgain;
    
    cout << "Welcome to Pattern Memory Game!" << endl;
    cout << "Try to repeat the pattern of R (Red), B (Blue), G (Green)" << endl;
    
    do {
        // Generate random pattern
        pattern = "";
        for (int i = 0; i < patternLength; i++) {
            pattern += colors[rand() % 3];
        }
        
        // Show pattern
        cout << "\nMemorize this pattern: " << pattern << endl;
        
        // Wait 2 seconds
        this_thread::sleep_for(chrono::seconds(2));
        
        // Clear screen (print newlines)
        for (int i = 0; i < 50; i++) {
            cout << endl;
        }
        
        // Get player's input
        cout << "Enter the pattern: ";
        cin >> playerInput;
        
        // Check if pattern matches
        if (playerInput == pattern) {
            cout << "Correct!" << endl;
            score++;
            patternLength++;  // Increase difficulty
            cout << "Score: " << score << endl;
        } else {
            cout << "Wrong! The pattern was: " << pattern << endl;
            cout << "Final score: " << score << endl;
            
            // Ask to play again
            cout << "Play again? (y/n): ";
            cin >> playAgain;
            
            if (playAgain == 'y' || playAgain == 'Y') {
                // Reset game
                score = 0;
                patternLength = 3;
                continue;
            } else {
                break;
            }
        }
        
        // Ask if player wants to continue
        cout << "Continue to next pattern? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "\nThanks for playing!" << endl;
    cout << "Final score: " << score << endl;
    
    return 0;
}
