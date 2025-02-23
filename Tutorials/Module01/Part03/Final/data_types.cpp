/**
 * Part 03: Variables and Data Types - Final Implementation
 * 
 * This program demonstrates:
 * 1. Different data types and their properties
 * 2. Variable declaration and initialization
 * 3. Type sizes and ranges
 * 4. Type conversion and potential issues
 */

#include <iostream>
#include <limits>
#include <iomanip>  // For formatting output

int main() {
    // Set up output formatting
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << "Exploring C++ Data Types\n";
    std::cout << "========================\n\n";

    // 1. Variable Declaration and Initialization
    int age = 25;                  // Integer type
    double price = 19.99;          // Double precision floating point
    char grade = 'A';              // Character type
    bool isEnrolled = true;        // Boolean type
    float temperature = 98.6f;     // Single precision floating point
    short smallNumber = 100;       // Short integer
    long bigNumber = 1234567890L;  // Long integer

    // Display variable values
    std::cout << "Variable Values:\n";
    std::cout << "---------------\n";
    std::cout << "Age: " << age << " years\n";
    std::cout << "Price: $" << price << "\n";
    std::cout << "Grade: " << grade << "\n";
    std::cout << "Enrolled: " << std::boolalpha << isEnrolled << "\n";
    std::cout << "Temperature: " << temperature << "°F\n";
    std::cout << "Small Number: " << smallNumber << "\n";
    std::cout << "Big Number: " << bigNumber << "\n\n";

    // 2. Size of Data Types
    std::cout << "Size of Data Types:\n";
    std::cout << "-------------------\n";
    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "char: " << sizeof(char) << " bytes\n";
    std::cout << "bool: " << sizeof(bool) << " bytes\n";
    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "short: " << sizeof(short) << " bytes\n";
    std::cout << "long: " << sizeof(long) << " bytes\n\n";

    // 3. Data Type Ranges
    std::cout << "Data Type Ranges:\n";
    std::cout << "----------------\n";
    std::cout << "int: " << std::numeric_limits<int>::min() 
              << " to " << std::numeric_limits<int>::max() << "\n";
    std::cout << "short: " << std::numeric_limits<short>::min() 
              << " to " << std::numeric_limits<short>::max() << "\n";
    std::cout << "long: " << std::numeric_limits<long>::min() 
              << " to " << std::numeric_limits<long>::max() << "\n\n";

    // 4. Type Conversion Examples
    std::cout << "Type Conversion Examples:\n";
    std::cout << "-----------------------\n";
    
    // Implicit conversion (safe)
    int number = 42;
    double decimal = number;    // int to double
    std::cout << "Int to Double: " << number << " -> " << decimal << "\n";

    // Explicit conversion (potential data loss)
    double pi = 3.14159;
    int wholePi = static_cast<int>(pi);  // double to int
    std::cout << "Double to Int: " << pi << " -> " << wholePi << "\n";

    // Character conversion
    char letter = 'A';
    int ascii = static_cast<int>(letter);  // char to int
    std::cout << "Char to Int: '" << letter << "' -> " << ascii << "\n\n";

    // 5. Precision Loss Example
    std::cout << "Precision Loss Examples:\n";
    std::cout << "----------------------\n";
    double precise = 9.99999;
    int imprecise = static_cast<int>(precise);
    std::cout << "Double to Int: " << precise << " -> " << imprecise << "\n\n";

    // 6. Overflow Example
    std::cout << "Overflow Examples:\n";
    std::cout << "-----------------\n";
    short smallMax = 32767;  // Maximum value for short
    std::cout << "Short Max: " << smallMax << "\n";
    std::cout << "Short Max + 1: " << static_cast<short>(smallMax + 1) << "\n";
    
    return 0;
}

/*
Key Concepts Demonstrated:

1. Data Types
   - Integer types (short, int, long)
   - Floating point types (float, double)
   - Character type (char)
   - Boolean type (bool)

2. Variable Properties
   - Size in memory
   - Value ranges
   - Precision characteristics

3. Type Conversion
   - Implicit conversion (automatic)
   - Explicit conversion (casting)
   - Potential data loss

4. Common Issues
   - Integer overflow
   - Precision loss
   - Type conversion problems

Best Practices:
- Initialize variables when declared
- Use appropriate types for data
- Be explicit about type conversions
- Watch for potential overflow
- Consider precision requirements
- Format output for readability
*/
