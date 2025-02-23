#include <iostream>   // For input/output
#include <limits>     // For finding limits of data types
#include <iomanip>    // For formatting output

int main() {
    std::cout << "Understanding C++ Data Types\n";
    std::cout << "===========================\n\n";

    // Integer types demonstration
    int integer = 42;              // Most common type
    short smallNumber = 123;       // For small numbers
    long largeNumber = 123456789L; // For very large numbers
    unsigned positiveOnly = 100;   // Only positive numbers

    std::cout << "Integer Types Example:\n";
    std::cout << "int value: " << integer << "\n";
    std::cout << "short value: " << smallNumber << "\n";
    std::cout << "long value: " << largeNumber << "\n";
    std::cout << "unsigned value: " << positiveOnly << "\n\n";

    // Floating-point types demonstration
    float decimal = 3.14159f;       // 7 digits precision
    double precise = 3.14159265359; // 15-16 digits precision

    std::cout << "Floating-point Types Example:\n";
    std::cout << std::fixed << std::setprecision(7);
    std::cout << "float value: " << decimal << "\n";
    std::cout << std::setprecision(15);
    std::cout << "double value: " << precise << "\n\n";

    // Character and boolean types demonstration
    char letter = 'A';             // Single character
    char digit = '5';              // Number as character
    char symbol = '$';             // Special symbol
    bool isTrue = true;            // Boolean true
    bool isFalse = false;          // Boolean false

    std::cout << "Character and Boolean Types Example:\n";
    std::cout << "letter: " << letter << "\n";
    std::cout << "digit: " << digit << "\n";
    std::cout << "symbol: " << symbol << "\n";
    std::cout << "isTrue: " << std::boolalpha << isTrue << "\n";
    std::cout << "isFalse: " << isFalse << "\n\n";

    std::cout << "Memory Sizes of Data Types\n";
    std::cout << "=========================\n";
    std::cout << "int: " << sizeof(int) 
              << " bytes (typically 4 bytes on most systems)\n";
    std::cout << "short: " << sizeof(short)
              << " bytes (typically 2 bytes, good for small numbers)\n";
    std::cout << "long: " << sizeof(long)
              << " bytes (typically 8 bytes for large numbers)\n";
    std::cout << "float: " << sizeof(float)
              << " bytes (typically 4 bytes for basic decimal numbers)\n";
    std::cout << "double: " << sizeof(double)
              << " bytes (typically 8 bytes for precise calculations)\n";
    std::cout << "char: " << sizeof(char)
              << " byte (always 1 byte for single characters)\n";
    std::cout << "bool: " << sizeof(bool)
              << " byte (typically 1 byte despite only needing 1 bit)\n\n";

    std::cout << "Value Ranges of Data Types\n";
    std::cout << "=========================\n";
    std::cout << "int range: " 
              << std::numeric_limits<int>::min() << " to " 
              << std::numeric_limits<int>::max() << "\n";
    std::cout << "unsigned int range: 0 to "
              << std::numeric_limits<unsigned int>::max() << "\n";
    std::cout << "short range: "
              << std::numeric_limits<short>::min() << " to "
              << std::numeric_limits<short>::max() << "\n";
    std::cout << "long range: "
              << std::numeric_limits<long>::min() << " to "
              << std::numeric_limits<long>::max() << "\n";
    std::cout << "float precision: " 
              << std::numeric_limits<float>::digits10 << " digits\n";
    std::cout << "double precision: "
              << std::numeric_limits<double>::digits10 << " digits\n\n";

    std::cout << "Calculations Example\n";
    std::cout << "===================\n";
    // Integer calculations
    int a = 5, b = 2;
    std::cout << "Integer division (5/2): " << a / b 
              << " (notice decimal is truncated)\n";
    
    // Floating-point calculations
    double c = 5.0, d = 2.0;
    std::cout << "Floating-point division (5.0/2.0): " << c / d 
              << " (keeps decimal part)\n";
    
    // Mixed calculations
    std::cout << "Mixed division (5/2.0): " << a / d 
              << " (converts to floating-point)\n";

    return 0;
}
