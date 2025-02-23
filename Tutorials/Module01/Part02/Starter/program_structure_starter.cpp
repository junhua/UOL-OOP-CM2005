/**
 * Part 02: Basic C++ Program Structure - Starter Code
 * 
 * This program demonstrates the basic structure of C++ programs
 * and introduces the concept of scope.
 * 
 * Learning Objectives:
 * 1. Understand program components
 * 2. Learn about preprocessor directives
 * 3. Practice with blocks and scope
 * 4. Write properly structured code
 */

// TODO: Include the necessary header for input/output
// Hint: We need <iostream> for cout

// TODO: Include the header for string operations
// Hint: We need <string> for std::string

// TODO: Define a constant using preprocessor directive
// Hint: Use #define to create a program version number
// Example: #define PROGRAM_VERSION "1.0"

// TODO: Write the main function with command line arguments
// Hint: Use int main(int argc, char* argv[])
int main(int argc, char* argv[]) {
    // TODO: Print a welcome message using the version number
    // Hint: Use std::cout and the PROGRAM_VERSION constant
    
    // TODO: Create a variable in the outer scope
    // Hint: Declare an integer variable
    
    {
        // TODO: Create a variable in the inner scope
        // Hint: Declare another integer variable
        
        // TODO: Print both variables to demonstrate scope
        // Hint: Use std::cout to show both values
        
    } // End of inner scope
    
    // TODO: Try to print the inner scope variable (this should cause an error)
    // Hint: This will demonstrate variable scope
    
    // TODO: Print the outer scope variable (this should work)
    // Hint: The outer variable is still in scope
    
    // TODO: Return success status
    // Hint: Return 0 for successful execution
}

/*
Instructions:
1. Add necessary include directives
2. Define PROGRAM_VERSION as "1.0"
3. Implement main() with argc/argv parameters
4. Create and use variables in different scopes
5. Print values to demonstrate scope rules
6. Add appropriate comments
7. Use consistent indentation

Tips:
- Pay attention to scope boundaries
- Use meaningful variable names
- Add comments explaining the code
- Follow proper indentation
- Remember semicolons after statements
*/
