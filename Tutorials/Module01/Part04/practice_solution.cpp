// Operator Practice Solution
// This program shows how operators work together, just like
// following a recipe where the order of steps matters!

#include <iostream>   // For input/output
#include <iomanip>    // For formatting
#include <bitset>     // For showing binary numbers

// Helper function to show numbers in binary
// Like having a special calculator that shows all the 1s and 0s
void printBinary(int n) {
    std::cout << std::bitset<8>(n) << " (which is " << n << " in decimal)\n";
}

// Function to check if division is safe
// Like checking if you have enough cookies to share equally
bool isDivisionSafe(int numerator, int denominator) {
    // First check if we can divide at all (avoid dividing by zero)
    // Then check if the result would be non-negative
    return (denominator != 0 && numerator/denominator >= 0);
}

int main() {
    // PART 1: OPERATOR PRECEDENCE (Order of Operations)
    // =============================================
    std::cout << "Operator Precedence (Like PEMDAS in Math!)\n";
    std::cout << "=======================================\n";
    
    // Just like in math: multiplication before addition
    int result1 = 2 + 3 * 4;     // Like solving: 2 + (3 × 4)
    int result2 = (2 + 3) * 4;   // Parentheses change the order
    int result3 = 10 - 2 + 3;    // Same level: go left to right
    
    std::cout << "Let's see how order matters:\n";
    std::cout << "2 + 3 * 4 = " << result1 << " (multiply first)\n";
    std::cout << "(2 + 3) * 4 = " << result2 << " (add first because of ())\n";
    std::cout << "10 - 2 + 3 = " << result3 << " (left to right)\n\n";

    // PART 2: SHORT-CIRCUIT EVALUATION (Smart Checking)
    // ============================================
    std::cout << "Short-Circuit Evaluation (Being Smart!)\n";
    std::cout << "===================================\n";
    
    // Like checking if you have both a ticket AND correct age for a ride
    int x = 10, y = 0;
    std::cout << "We have: x = " << x << " and y = " << y << "\n";
    
    // Safe division check (like checking requirements before doing something)
    if (y != 0 && x/y > 2) {  // First check if division is possible
        std::cout << "We can divide safely!\n";
    } else {
        std::cout << "Oops! Can't divide by zero (good thing we checked!)\n";
    }
    
    // Using our safety function
    std::cout << "Is division safe? " 
              << std::boolalpha << isDivisionSafe(x, y) << "\n\n";

    // PART 3: BIT MANIPULATION (Working with Binary Numbers)
    // ===============================================
    std::cout << "Bit Calculator (Playing with Binary Numbers)\n";
    std::cout << "========================================\n";
    
    // Our numbers in decimal (normal) and binary
    int num1 = 12;  // In binary: 00001100
    int num2 = 5;   // In binary: 00000101
    
    std::cout << "Let's look at our numbers in binary:\n";
    std::cout << "Number 1 (12) is: ";
    printBinary(num1);
    std::cout << "Number 2 (5) is:  ";
    printBinary(num2);
    
    // Bitwise operations (like mixing colors)
    std::cout << "\nLet's combine them in different ways:\n";
    std::cout << "AND (both must be 1): ";
    printBinary(num1 & num2);
    std::cout << "OR (either can be 1):  ";
    printBinary(num1 | num2);
    std::cout << "XOR (must be different): ";
    printBinary(num1 ^ num2);
    
    // Bit shifting (like sliding numbers left or right)
    std::cout << "\nLet's slide the bits around:\n";
    std::cout << "Slide left (multiply by 2):  ";
    printBinary(num1 << 1);
    std::cout << "Slide right (divide by 2): ";
    printBinary(num1 >> 1);
    
    // Complex bit operations (like a recipe with multiple steps)
    std::cout << "\nLet's try something more complex:\n";
    int compound = ((num1 & num2) << 1) | (num1 ^ num2);
    std::cout << "A fancy combination: ";
    printBinary(compound);

    // PART 4: MIXING DIFFERENT OPERATORS (Putting It All Together)
    // ===================================================
    std::cout << "\nMixing Different Operators (The Grand Finale!)\n";
    std::cout << "=========================================\n";
    
    bool hasTicket = true, isStudent = false;
    int value = 5;
    
    // Using multiple operators together
    // Like checking multiple conditions for a special deal
    int mixedResult = (hasTicket && !isStudent) ? value * 2 : value / 2;
    std::cout << "Special deal result: " << mixedResult << "\n";
    
    // A complex expression (like a complicated recipe)
    int complexResult = (value + 3) * 2 & ~(value - 1);
    std::cout << "Complex recipe result: " << complexResult << "\n";
    std::cout << "In binary it looks like: ";
    printBinary(complexResult);

    return 0;
}

/*
This program shows:
1. How operators follow a specific order (like PEMDAS in math)
2. How to check conditions safely (like checking requirements)
3. How to work with binary numbers (like a special calculator)
4. How to combine different operators (like following a recipe)

Try:
1. Change the values of num1 and num2
2. Try different combinations of operations
3. Add more complex expressions
4. Predict the results before running
*/
