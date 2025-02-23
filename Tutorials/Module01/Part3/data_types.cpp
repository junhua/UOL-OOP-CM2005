#include <iostream>
#include <limits>

int main() {
    // Fundamental data types
    int age = 25;                    // Integer
    double price = 19.99;            // Double precision floating-point
    char grade = 'A';                // Character
    bool isStudent = true;           // Boolean

    // Print values
    std::cout << "Integer (age): " << age << std::endl;
    std::cout << "Double (price): " << price << std::endl;
    std::cout << "Character (grade): " << grade << std::endl;
    std::cout << "Boolean (isStudent): " << isStudent << std::endl;

    // Type conversion examples
    double height = 1.85;            // meters
    int heightCm = (int)(height * 100);  // Explicit conversion
    std::cout << "\nHeight conversion:" << std::endl;
    std::cout << "Height in meters: " << height << std::endl;
    std::cout << "Height in centimeters: " << heightCm << std::endl;

    // Size of different types
    std::cout << "\nSize of data types:" << std::endl;
    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;

    // Range of integer type
    std::cout << "\nRange of integer type:" << std::endl;
    std::cout << "Minimum int value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum int value: " << std::numeric_limits<int>::max() << std::endl;

    return 0;
}
