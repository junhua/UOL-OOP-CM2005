#ifndef STRING_DEMO_H
#define STRING_DEMO_H

#include <iostream>
#include <cstring>
#include <string>

class StringDemo {
public:
    // C-style string operations
    static void demonstrateCString() {
        std::cout << "\n=== C-style String Operations ===\n" << std::endl;
        
        // TODO: Create a C-style string (char array)
        // Hint: Remember to include space for null terminator
        char str1[50];
        
        // TODO: Copy a string literal safely
        // Hint: Use strncpy and ensure null termination
        
        // TODO: Get string length
        // Hint: Use strlen
        
        // TODO: String concatenation
        // Hint: Use strncat with size limit
        
        // TODO: String comparison
        // Hint: Use strcmp
        
        // TODO: Find character in string
        // Hint: Use strchr
        
        // TODO: Find substring
        // Hint: Use strstr
    }
    
    // Modern string operations
    static void demonstrateStdString() {
        std::cout << "\n=== std::string Operations ===\n" << std::endl;
        
        // TODO: Create and initialize std::string
        std::string str1;
        
        // TODO: String concatenation using +
        
        // TODO: String comparison using ==
        
        // TODO: Substring operations
        // Hint: Use substr
        
        // TODO: Find operations
        // Hint: Use find
        
        // TODO: Insert and erase
        
        // TODO: Convert between C-style and std::string
        // Hint: Use c_str() and string constructor
    }
    
    // Demonstrate string input/output
    static void demonstrateIO() {
        std::cout << "\n=== String Input/Output ===\n" << std::endl;
        
        // TODO: Read line of text
        // Hint: Use std::getline
        
        // TODO: Parse string into words
        // Hint: Use string stream
        
        // TODO: Convert string to number
        // Hint: Use std::stoi or std::stod
        
        // TODO: Convert number to string
        // Hint: Use std::to_string
    }
};

#endif // STRING_DEMO_H
