#include <iostream>
#include <string>
#include "functions.h"

// Function definition for calculating area
int calculateArea(int width, int height) {
    return width * height;
}

// Function definition for printing results
void printResult(std::string message, int value) {
    std::cout << message << ": " << value << std::endl;
}

// Function definition for checking positive numbers
bool isPositive(int number) {
    return number > 0;
}
