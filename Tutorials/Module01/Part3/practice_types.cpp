#include <iostream>
#include <limits>
#include <iomanip>

int main() {
    std::cout << "=== Type Ranges Exercise ===" << std::endl;
    
    // Integer type ranges
    std::cout << "\n1. Integer Type Ranges:" << std::endl;
    std::cout << "short:" << std::endl;
    std::cout << "  Min: " << std::numeric_limits<short>::min() << std::endl;
    std::cout << "  Max: " << std::numeric_limits<short>::max() << std::endl;
    
    std::cout << "\nint:" << std::endl;
    std::cout << "  Min: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "  Max: " << std::numeric_limits<int>::max() << std::endl;
    
    std::cout << "\nlong:" << std::endl;
    std::cout << "  Min: " << std::numeric_limits<long>::min() << std::endl;
    std::cout << "  Max: " << std::numeric_limits<long>::max() << std::endl;

    // Overflow demonstration
    std::cout << "\nOverflow Demonstration:" << std::endl;
    short smallNum = 32767;  // Maximum value for short
    std::cout << "Original value: " << smallNum << std::endl;
    smallNum++;  // Cause overflow
    std::cout << "After increment: " << smallNum << std::endl;

    std::cout << "\n=== Type Conversion Exercise ===" << std::endl;
    
    // Implicit conversion
    std::cout << "\n2. Type Conversion Examples:" << std::endl;
    int intNum = 42;
    double doubleNum = intNum;    // Implicit conversion
    std::cout << "Implicit int to double: " << doubleNum << std::endl;

    // Explicit casting
    double pi = 3.14159;
    int roundedPi = static_cast<int>(pi);  // Explicit conversion
    std::cout << "Explicit double to int: " << roundedPi << std::endl;

    // Precision loss demonstration
    double largeDouble = 12345.6789;
    float smallFloat = static_cast<float>(largeDouble);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Original double: " << largeDouble << std::endl;
    std::cout << "Converted to float: " << smallFloat << std::endl;

    std::cout << "\n=== Size Exploration Exercise ===" << std::endl;
    
    // Size of types
    std::cout << "\n3. Size of Types:" << std::endl;
    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "short: " << sizeof(short) << " bytes" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "bool: " << sizeof(bool) << " bytes" << std::endl;

    // Memory usage patterns
    std::cout << "\nMemory Usage Patterns:" << std::endl;
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Size of int array (5 elements): " << sizeof(intArray) << " bytes" << std::endl;
    std::cout << "Size of each element: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Number of elements: " << sizeof(intArray)/sizeof(int) << std::endl;

    return 0;
}
