// Data Types in C++
// This program shows the different types of "boxes" we can use
// to store different kinds of information in our programs.

// Include necessary libraries
#include <iostream>   // For input/output
#include <limits>    // For finding limits of data types

int main() {
    // Integer types (whole numbers)
    // Think of these like different size boxes for counting things
    int integer = 42;              // Regular box (e.g., counting people)
    short smallNumber = 123;       // Small box (e.g., age)
    long largeNumber = 123456789L; // Big box (e.g., population)
    unsigned positiveOnly = 100;   // Box for positive numbers only

    // Floating-point types (decimal numbers)
    // Like boxes for measuring things
    float decimal = 3.14f;         // Regular measuring box (e.g., height)
    double precise = 3.14159265359;// Precise measuring box (e.g., scientific data)

    // Character type
    // Like a tiny box that fits exactly one character
    char letter = 'A';             // Single character box (e.g., grades)

    // Boolean type
    // Like a light switch - can only be true or false
    bool isTrue = true;            // Switch box (e.g., yes/no questions)

    // Let's see how big each type of box is
    std::cout << "Data Type Sizes (in bytes):\n";
    std::cout << "-------------------------\n";
    std::cout << "int: " << sizeof(int) 
              << " bytes (like a regular storage box)\n";
    std::cout << "short: " << sizeof(short) 
              << " bytes (like a small storage box)\n";
    std::cout << "long: " << sizeof(long) 
              << " bytes (like a large storage box)\n";
    std::cout << "float: " << sizeof(float) 
              << " bytes (like a measuring cup)\n";
    std::cout << "double: " << sizeof(double) 
              << " bytes (like a precise measuring tool)\n";
    std::cout << "char: " << sizeof(char) 
              << " byte (like a single letter slot)\n";
    std::cout << "bool: " << sizeof(bool) 
              << " byte (like a simple switch)\n\n";

    // Let's see what's the biggest and smallest number each box can hold
    std::cout << "Number Ranges (how much can each box hold):\n";
    std::cout << "----------------------------------------\n";
    std::cout << "int: " << std::numeric_limits<int>::min() 
              << " to " << std::numeric_limits<int>::max() << "\n";
    std::cout << "unsigned int: 0 to " 
              << std::numeric_limits<unsigned int>::max() 
              << " (positive numbers only)\n\n";

    // Let's look at some example values
    std::cout << "Example Values (what's in our boxes):\n";
    std::cout << "--------------------------------\n";
    std::cout << "integer: " << integer 
              << " (a whole number)\n";
    std::cout << "decimal: " << decimal 
              << " (a number with decimal point)\n";
    std::cout << "letter: " << letter << " (ASCII number: " 
              << static_cast<int>(letter) << ")\n";
    std::cout << "isTrue: " << std::boolalpha << isTrue 
              << " (a yes/no value)\n\n";

    // Demonstrate some interesting facts
    std::cout << "Fun Facts:\n";
    std::cout << "---------\n";
    std::cout << "1. Characters are actually stored as numbers!\n";
    std::cout << "   'A' is stored as: " << static_cast<int>('A') << "\n";
    std::cout << "   'B' is stored as: " << static_cast<int>('B') << "\n";
    std::cout << "2. Booleans use a whole byte even though they only need 1 bit!\n";
    std::cout << "3. The size of each type might be different on different computers!\n";

    return 0;
}

/*
This program helps you understand:
1. Different types of data in C++
2. How much space each type uses
3. What kinds of values each type can store
4. How to display different types of data

Try modifying the values and see what happens!
*/
