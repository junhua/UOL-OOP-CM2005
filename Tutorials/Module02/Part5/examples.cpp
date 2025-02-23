#include <iostream>
#include <string>
using namespace std;

// Quiz game combining conditionals, switch, loops, and break/continue
int main() {
    const int NUM_QUESTIONS = 3;
    const int POINTS_PER_QUESTION = 10;
    const int PASSING_SCORE = 20;
    const string EXIT = "quit";
    
    string questions[NUM_QUESTIONS] = {
        "What is 2 + 2?",
        "What is 5 * 3?",
        "What is 10 / 2?"
    };
    
    int answers[NUM_QUESTIONS] = {4, 15, 5};
    int score = 0;
    
    cout << "Math Quiz (enter '" << EXIT << "' to end)" << endl;
    cout << "Each correct answer is worth " << POINTS_PER_QUESTION << " points" << endl;
    cout << "Passing score is " << PASSING_SCORE << " points" << endl;
    
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        string input;
        cout << "\nQuestion " << (i + 1) << ": " << questions[i] << endl;
        cout << "Your answer: ";
        cin >> input;
        
        if (input == EXIT) {
            break;
        }
        
        try {
            int answer = stoi(input);
            if (answer == answers[i]) {
                cout << "Correct! +" << POINTS_PER_QUESTION << " points" << endl;
                score += POINTS_PER_QUESTION;
            } else {
                cout << "Wrong. The answer was " << answers[i] << endl;
            }
        } catch (...) {
            cout << "Invalid input. Skipping question." << endl;
            continue;
        }
        
        cout << "Current score: " << score << endl;
    }
    
    cout << "\n=== Final Results ===" << endl;
    cout << "Total score: " << score << " out of " << (NUM_QUESTIONS * POINTS_PER_QUESTION) << endl;
    
    if (score >= PASSING_SCORE) {
        cout << "Congratulations! You passed!" << endl;
    } else {
        cout << "Sorry, you didn't pass. Keep practicing!" << endl;
    }
    
    switch (score / POINTS_PER_QUESTION) {
        case 3: cout << "Perfect score!"; break;
        case 2: cout << "Good job!"; break;
        case 1: cout << "Not bad!"; break;
        default: cout << "Better luck next time!";
    }
    cout << endl;
    
    return 0;
}
