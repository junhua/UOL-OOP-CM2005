#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * Module 2 - Part 5: Simple Program Examples
 * Practice Exercise Starter Code
 * 
 * Task: Create a pattern memory game that:
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
    
    // TODO: Implement the main game loop
    // Remember to:
    // - Generate random pattern
    // - Display pattern to player
    // - Get player's input
    // - Check if pattern matches
    // - Update score and pattern length
    // - Ask if player wants to continue
    
    return 0;
}
