---
layout: default
title: Part 5 - Simple Program Examples
nav_order: 5
parent: Module 2 - Control Flow
grand_parent: Tutorials
permalink: /tutorials/module2/part5-examples/
---

# Part 5: Simple Program Examples

## Learning Objectives
- Combine control flow concepts into complete programs
- Master input validation techniques
- Implement robust error handling
- Create user-friendly interfaces
- Practice code organization

## Introduction
This section demonstrates how to combine various control flow concepts into complete, practical programs. Through carefully crafted examples, you'll see how different control structures work together to create robust, user-friendly applications. This part explores several key concepts:

1. **Program Structure**:
   - Proper code organization
   - Clear user interfaces
   - State management
   - Error handling patterns
   - Input validation techniques

2. **Game Development**:
   - Random number generation
   - Score tracking
   - User interaction
   - Progress monitoring
   - Game state management

3. **Data Processing**:
   - Input validation
   - Data transformation
   - Result formatting
   - Statistics calculation
   - Output presentation

Understanding these concepts is essential for building complete, functional programs that provide a good user experience. Through practical examples, you'll learn how to combine different control structures effectively while maintaining code readability and robustness.

## Implementation Guide

You'll find the starter code in `Tutorials/Module02/Part5/examples_starter.cpp` and can compare your implementation with the completed version in `Tutorials/Module02/Part5/Final/examples.cpp`.

### Step 1: Start with the Template
1. Open the starter code file `Tutorials/Module02/Part5/practice_examples_starter.cpp`
2. You'll see the following template:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    // TODO: Initialize word list and categories
    // TODO: Implement word selection and scrambling
    // TODO: Add scoring system
    // TODO: Create game loop with lives
    // TODO: Handle user input and validation
    // TODO: Display results and statistics
    
    return 0;
}
```

### Step 2: Initialize Game Data
Set up the word list and categories:

```cpp
    // Word categories
    vector<pair<string, string>> words = {
        {"COMPUTER", "Technology"},
        {"ALGORITHM", "Programming"},
        {"VARIABLE", "Programming"},
        {"FUNCTION", "Programming"},
        {"DATABASE", "Technology"}
    };
    
    // Game settings
    const int MAX_TRIES = 3;
    const int POINTS_PER_WORD = 10;
    int score = 0;
    int lives = MAX_TRIES;
```

### Step 3: Implement Word Scrambling
Add the word scrambling functionality:

```cpp
    // Initialize random seed
    srand(time(0));
    
    string scrambleWord(string word) {
        string scrambled = word;
        int length = scrambled.length();
        
        for (int i = 0; i < length - 1; i++) {
            int j = i + rand() % (length - i);
            swap(scrambled[i], scrambled[j]);
        }
        
        return scrambled;
    }
```

### Step 4: Create Game Loop
Implement the main game loop:

```cpp
    while (lives > 0 && !words.empty()) {
        // Select random word
        int index = rand() % words.size();
        string word = words[index].first;
        string category = words[index].second;
        
        // Scramble word
        string scrambled = scrambleWord(word);
        
        // Display information
        cout << "\nLives: " << lives << " | Score: " << score << endl;
        cout << "Category: " << category << endl;
        cout << "Scrambled word: " << scrambled << endl;
        
        // Get guess
        string guess;
        cout << "Your guess: ";
        cin >> guess;
        
        // Process guess here
    }
```

### Step 5: Add Input Processing
Implement guess validation and scoring:

```cpp
        // Convert guess to uppercase
        for (char& c : guess) {
            c = toupper(c);
        }
        
        // Check guess
        if (guess == word) {
            cout << "Correct! +" << POINTS_PER_WORD << " points" << endl;
            score += POINTS_PER_WORD;
            words.erase(words.begin() + index);
        } else {
            cout << "Wrong! The word was: " << word << endl;
            lives--;
        }
```

### Step 6: Add Game Over Logic
Implement the end game conditions:

```cpp
    // Display final results
    cout << "\n=== Game Over ===" << endl;
    cout << "Final Score: " << score << endl;
    
    if (lives > 0) {
        cout << "Congratulations! You completed all words!" << endl;
    } else {
        cout << "Out of lives! Better luck next time!" << endl;
    }
```

### Final Code
Here's the complete implementation:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    // Word categories
    vector<pair<string, string>> words = {
        {"COMPUTER", "Technology"},
        {"ALGORITHM", "Programming"},
        {"VARIABLE", "Programming"},
        {"FUNCTION", "Programming"},
        {"DATABASE", "Technology"}
    };
    
    // Game settings
    const int MAX_TRIES = 3;
    const int POINTS_PER_WORD = 10;
    int score = 0;
    int lives = MAX_TRIES;
    
    // Initialize random seed
    srand(time(0));
    
    // Word scrambling function
    auto scrambleWord = [](string word) {
        string scrambled = word;
        int length = scrambled.length();
        
        for (int i = 0; i < length - 1; i++) {
            int j = i + rand() % (length - i);
            swap(scrambled[i], scrambled[j]);
        }
        
        return scrambled;
    };
    
    // Game loop
    while (lives > 0 && !words.empty()) {
        // Select random word
        int index = rand() % words.size();
        string word = words[index].first;
        string category = words[index].second;
        
        // Scramble word
        string scrambled = scrambleWord(word);
        
        // Display information
        cout << "\nLives: " << lives << " | Score: " << score << endl;
        cout << "Category: " << category << endl;
        cout << "Scrambled word: " << scrambled << endl;
        
        // Get guess
        string guess;
        cout << "Your guess: ";
        cin >> guess;
        
        // Convert guess to uppercase
        for (char& c : guess) {
            c = toupper(c);
        }
        
        // Check guess
        if (guess == word) {
            cout << "Correct! +" << POINTS_PER_WORD << " points" << endl;
            score += POINTS_PER_WORD;
            words.erase(words.begin() + index);
        } else {
            cout << "Wrong! The word was: " << word << endl;
            lives--;
        }
    }
    
    // Display final results
    cout << "\n=== Game Over ===" << endl;
    cout << "Final Score: " << score << endl;
    
    if (lives > 0) {
        cout << "Congratulations! You completed all words!" << endl;
    } else {
        cout << "Out of lives! Better luck next time!" << endl;
    }
    
    return 0;
}
```

### Test Cases

1. Correct Guess:
```
Input: COMPUTER
Expected Output:
Correct! +10 points
Score increases
Word removed from list
```

2. Incorrect Guess:
```
Input: WRONG
Expected Output:
Wrong! The word was: COMPUTER
Lives decrease
```

3. Game Completion:
```
Input: All words guessed correctly
Expected Output:
Game Over
Final Score displayed
Congratulations message
```

4. Game Over:
```
Input: Three wrong guesses
Expected Output:
Game Over
Final Score displayed
Out of lives message
```

## Practice Exercises

### Exercise 1: Quiz Game
Create a program that:
1. Stores questions and answers
2. Tracks score and lives
3. Provides hints
4. Validates input
5. Shows statistics

### Exercise 2: Number Game
Implement a system that:
1. Generates random numbers
2. Handles user guesses
3. Provides feedback
4. Tracks attempts
5. Shows high scores

### Exercise 3: Word Counter
Build a program that:
1. Processes text input
2. Counts words and characters
3. Identifies patterns
4. Generates statistics
5. Formats output

You can compare your solutions with the completed examples in `Tutorials/Module02/Part5/practice_examples.cpp`.

## Best Practices
1. User Interface
   - Clear instructions
   - Consistent formatting
   - Helpful feedback
   - Error messages
   - Progress tracking

2. Input Validation
   - Check all inputs
   - Handle invalid data
   - Provide retry options
   - Clear error states
   - Buffer management

3. Game Logic
   - Clear rules
   - Fair scoring
   - Proper difficulty
   - Random elements
   - Progress tracking

4. Code Organization
   - Logical structure
   - Clear comments
   - Consistent style
   - Error handling
   - State management

## Next Steps
1. Complete all practice exercises
2. Test with various inputs
3. Add new features
4. Improve user interface
5. Move on to [Module 3: Functions]({{ site.baseurl }}/tutorials/module3)

Remember that well-structured programs combine proper input handling, clear user feedback, and robust error management to create an engaging user experience.
