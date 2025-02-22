// Practice Exercise: Welcome Message Generator
// This program demonstrates formatted output in C++

#include <iostream>   // For input/output operations

int main() {
    // Display top border
    std::cout << "******************" << std::endl;
    
    // Display centered welcome message
    std::cout << "* Welcome to C++ *" << std::endl;
    
    // Display bottom border
    std::cout << "******************" << std::endl;
    
    // Add blank line for spacing
    std::cout << std::endl;
    
    // Display creator information
    std::cout << "Created by: John Doe" << std::endl;
    std::cout << "Date: February 22, 2025" << std::endl;
    
    // Add blank line for spacing
    std::cout << std::endl;
    
    // Display motivational message
    std::cout << "Let's start programming!" << std::endl;
    std::cout << "--------------------" << std::endl;
    
    return 0;  // Program completed successfully
}

/*
This program shows:
1. How to create formatted output
2. How to use multiple cout statements
3. How to create visual separators
4. How to add blank lines for spacing

Output Format:
******************
* Welcome to C++ *
******************

Created by: John Doe
Date: February 22, 2025

Let's start programming!
--------------------

Try:
1. Change the border pattern (e.g., ===, ###)
2. Add more information about yourself
3. Add a custom message at the end
4. Try different text alignments
*/
