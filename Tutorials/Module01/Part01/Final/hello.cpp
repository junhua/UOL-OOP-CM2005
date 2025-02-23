/**
 * Part 01: Welcome to C++ - Final Implementation
 * 
 * This program demonstrates the basic structure of a C++ program
 * and how to output text to the console.
 * 
 * Key Concepts Demonstrated:
 * 1. Header inclusion
 * 2. Main function structure
 * 3. Standard output
 * 4. Program return values
 */

// Include the input/output stream library
// This gives us access to std::cout for output
#include <iostream>

// The main function - the entry point of every C++ program
// When you run the program, it starts executing from here
int main() {
    // Use the standard output stream (cout) to print a message
    // The << operator is used to send data to cout
    std::cout << "Welcome to C++!" << std::endl;
    
    // endl adds a newline and flushes the output buffer
    // Alternative: could use '\n' for just a newline
    
    // Return 0 to indicate the program completed successfully
    // Non-zero values typically indicate errors
    return 0;
}

/*
Program Explanation:
1. #include <iostream>
   - Brings in the input/output library
   - Required for using std::cout

2. int main()
   - The main function that C++ looks for to start the program
   - Returns an integer (int) to indicate program status

3. std::cout << "Welcome to C++!" << std::endl;
   - std::cout is the standard output stream
   - << is the stream insertion operator
   - std::endl adds a newline and flushes output

4. return 0;
   - Indicates successful program completion
   - Operating system uses this value

Try:
1. Change the welcome message
2. Add more cout statements
3. Use '\n' instead of std::endl
4. Add more text using multiple << operators
*/
