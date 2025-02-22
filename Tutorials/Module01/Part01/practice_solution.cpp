// Practice Exercise Solution
// This program demonstrates how to:
// 1. Print multiple lines of text
// 2. Add blank lines for spacing
// 3. Use comments to explain code
// 4. Follow a structured program format

// Include the input/output library for printing text
#include <iostream>

// Main function - our program starts here
int main() {
    // First message: Welcome the user
    // endl is used to move to the next line (like pressing Enter)
    std::cout << "Welcome to C++" << std::endl;
    
    // Second message: Print the name
    // Each std::cout statement can only print what's between quotes
    // We need a separate statement for each line
    std::cout << "John Doe" << std::endl;
    
    // Add a blank line for better readability
    // Just using endl without any text creates an empty line
    std::cout << std::endl;
    
    // Final message: Print an encouraging message
    // Notice how each piece of output is on its own line
    // because we used endl after each one
    std::cout << "Let's start programming!" << std::endl;
    
    // End the program
    // Return 0 means everything worked correctly
    return 0;
}

/*
Expected output:
Welcome to C++
John Doe

Let's start programming!
*/
