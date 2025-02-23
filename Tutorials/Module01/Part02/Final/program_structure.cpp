/**
 * Part 02: Basic C++ Program Structure - Final Implementation
 * 
 * This program demonstrates:
 * 1. Program structure and components
 * 2. Preprocessor directives
 * 3. Variable scope
 * 4. Command line arguments
 */

// Include necessary headers
#include <iostream>  // For input/output operations
#include <string>   // For string operations

// Define program version using preprocessor directive
#define PROGRAM_VERSION "1.0"

// Main function with command line arguments
// argc: argument count (number of arguments)
// argv: argument vector (array of argument strings)
int main(int argc, char* argv[]) {
    // Print welcome message with version
    std::cout << "Program Structure Demo v" << PROGRAM_VERSION << std::endl;
    
    // Print number of command line arguments
    std::cout << "Number of arguments: " << argc << std::endl;
    
    // Print all command line arguments
    std::cout << "Arguments:" << std::endl;
    for(int i = 0; i < argc; i++) {
        std::cout << "  " << i << ": " << argv[i] << std::endl;
    }
    
    // Demonstrate variable scope
    int outerVar = 10;  // Variable in outer scope
    std::cout << "\nOuter variable: " << outerVar << std::endl;
    
    // Create a new block to demonstrate scope
    {
        int innerVar = 20;  // Variable in inner scope
        std::cout << "Inner variable: " << innerVar << std::endl;
        std::cout << "Outer variable (from inner scope): " << outerVar << std::endl;
        
        // Modify outer variable from inner scope
        outerVar = 30;
        std::cout << "Modified outer variable: " << outerVar << std::endl;
    } // innerVar goes out of scope here
    
    // This line would cause an error if uncommented:
    // std::cout << "Inner variable: " << innerVar << std::endl;
    
    // outerVar is still accessible
    std::cout << "Outer variable (after inner block): " << outerVar << std::endl;
    
    return 0;  // Indicate successful completion
}

/*
Program Structure Explanation:

1. Preprocessor Directives (#include, #define)
   - Processed before compilation
   - Include headers for functionality
   - Define constants and macros

2. Main Function
   - Entry point of the program
   - Can accept command line arguments
   - Returns status code (0 for success)

3. Variable Scope
   - Variables only accessible within their block
   - Outer variables visible to inner blocks
   - Inner variables not visible to outer blocks

4. Code Organization
   - Clear structure with comments
   - Consistent indentation
   - Logical grouping of related code

Try running with different command line arguments:
./program_structure arg1 arg2 "argument 3"
*/
