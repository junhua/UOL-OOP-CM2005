#include <iostream>
#include <sstream>
#include "StringDemo.h"

int main() {
    std::cout << "String Operations Demo 📝\n" << std::endl;
    
    // Demonstrate C-style strings
    StringDemo::demonstrateCString();
    
    // Demonstrate std::string
    StringDemo::demonstrateStdString();
    
    // Demonstrate string I/O
    StringDemo::demonstrateIO();
    
    // TODO: Compare C-style strings vs std::string:
    // 1. Memory management:
    //    - C-style: Manual buffer size management, risk of buffer overflow
    //    - std::string: Automatic memory management, safe resizing
    
    // 2. String operations:
    //    - C-style: Manual null termination, unsafe functions like strcpy
    //    - std::string: Safe operations, operator overloading (+, ==, etc.)
    
    // 3. Length and capacity:
    //    - C-style: strlen() doesn't include null terminator
    //    - std::string: size() gives actual length, capacity() for allocated space
    
    // 4. Modern features:
    //    - C-style: Limited functionality
    //    - std::string: Rich set of member functions (find, substr, etc.)
    
    // 5. Type safety:
    //    - C-style: Decays to char*, easy to make mistakes
    //    - std::string: Type-safe, prevents common errors
    
    return 0;
}
