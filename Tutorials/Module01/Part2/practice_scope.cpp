#include <iostream>

// Global constant accessible throughout the program
const int MAX_VALUE = 100;

int main() {
    // Main scope variable
    int mainVar = 10;
    std::cout << "Main scope - mainVar: " << mainVar << std::endl;
    std::cout << "Main scope - MAX_VALUE: " << MAX_VALUE << std::endl;

    {
        // First nested block
        int blockVar1 = 20;
        std::cout << "\nFirst block scope:" << std::endl;
        std::cout << "mainVar: " << mainVar << std::endl;
        std::cout << "blockVar1: " << blockVar1 << std::endl;
        std::cout << "MAX_VALUE: " << MAX_VALUE << std::endl;

        {
            // Second nested block
            int blockVar2 = 30;
            std::cout << "\nSecond block scope:" << std::endl;
            std::cout << "mainVar: " << mainVar << std::endl;
            std::cout << "blockVar1: " << blockVar1 << std::endl;
            std::cout << "blockVar2: " << blockVar2 << std::endl;
            std::cout << "MAX_VALUE: " << MAX_VALUE << std::endl;
        } // blockVar2 goes out of scope

        std::cout << "\nBack to first block scope:" << std::endl;
        std::cout << "mainVar: " << mainVar << std::endl;
        std::cout << "blockVar1: " << blockVar1 << std::endl;
        // blockVar2 is not accessible here
    } // blockVar1 goes out of scope

    std::cout << "\nBack to main scope:" << std::endl;
    std::cout << "mainVar: " << mainVar << std::endl;
    // blockVar1 and blockVar2 are not accessible here

    return 0;
}
