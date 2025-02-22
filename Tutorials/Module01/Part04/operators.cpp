// C++ Operators Guide
// Think of operators as the basic tools in your programming toolbox.
// Just like math has +, -, ×, ÷, programming has these and more!

#include <iostream>   // For input/output
#include <iomanip>    // For formatting output
#include <bitset>     // For showing binary numbers

// Helper function to show binary numbers
// This makes it easier to see how bitwise operators work
void printBinary(int n, const std::string& label) {
    std::cout << std::setw(20) << label << ": " 
              << std::bitset<8>(n) << " (" << n << ")\n";
}

int main() {
    // PART 1: ARITHMETIC OPERATORS (Like Basic Math)
    // ============================================
    std::cout << "Arithmetic Operators (Basic Math)\n";
    std::cout << "===============================\n";
    
    int a = 10, b = 3;
    std::cout << "If we have: a = " << a << " and b = " << b << "\n\n";
    
    // Just like regular math operations
    std::cout << "Addition (like adding apples):\n";
    std::cout << a << " + " << b << " = " << (a + b) << "\n\n";
    
    std::cout << "Subtraction (like removing items):\n";
    std::cout << a << " - " << b << " = " << (a - b) << "\n\n";
    
    std::cout << "Multiplication (like repeated addition):\n";
    std::cout << a << " * " << b << " = " << (a * b) << "\n\n";
    
    std::cout << "Division (like sharing equally):\n";
    std::cout << a << " / " << b << " = " << (a / b) 
              << " (with remainder " << (a % b) << ")\n\n";

    // PART 2: INCREMENT/DECREMENT (Counting Up and Down)
    // ===============================================
    std::cout << "Increment/Decrement (Counting)\n";
    std::cout << "============================\n";
    
    int x = 5;
    std::cout << "Start with x = " << x << "\n\n";
    
    // Like counting: "use it, then add one"
    std::cout << "Post-increment (x++): use " << x++ 
              << ", then add 1 to get " << x << "\n";
    
    // Like counting: "add one, then use it"
    std::cout << "Pre-increment (++x): first add 1 to get " 
              << ++x << "\n\n";

    // PART 3: ASSIGNMENT OPERATORS (Storing Values)
    // =========================================
    std::cout << "Assignment Operators (Storing Values)\n";
    std::cout << "==================================\n";
    
    int y = 10;  // Like putting 10 in a box labeled 'y'
    std::cout << "Start with y = " << y << "\n";
    
    // Compound assignments (shortcuts)
    y += 5;      // Like saying "add 5 to what's in y"
    std::cout << "After y += 5: " << y << "\n";
    
    y -= 3;      // Like saying "subtract 3 from y"
    std::cout << "After y -= 3: " << y << "\n";
    
    y *= 2;      // Like saying "double what's in y"
    std::cout << "After y *= 2: " << y << "\n\n";

    // PART 4: COMPARISON OPERATORS (Checking Values)
    // =========================================
    std::cout << "Comparison Operators (Checking Values)\n";
    std::cout << "===================================\n";
    
    // Make true/false print as words instead of 1/0
    std::cout << std::boolalpha;
    
    // Like asking questions about numbers
    std::cout << "Is 5 equal to 5? " << (5 == 5) << "\n";
    std::cout << "Is 5 not equal to 5? " << (5 != 5) << "\n";
    std::cout << "Is 5 greater than 3? " << (5 > 3) << "\n";
    std::cout << "Is 5 less than 3? " << (5 < 3) << "\n\n";

    // PART 5: LOGICAL OPERATORS (Making Decisions)
    // ========================================
    std::cout << "Logical Operators (Making Decisions)\n";
    std::cout << "=================================\n";
    
    bool hasTicket = true, isStudent = false;
    
    // Like real-world logic:
    std::cout << "If you have a ticket AND you're a student: " 
              << (hasTicket && isStudent) << "\n";
    std::cout << "If you have a ticket OR you're a student: " 
              << (hasTicket || isStudent) << "\n";
    std::cout << "If you do NOT have a ticket: " 
              << (!hasTicket) << "\n\n";

    // PART 6: BITWISE OPERATORS (Working with Binary)
    // ==========================================
    std::cout << "Bitwise Operators (Binary Numbers)\n";
    std::cout << "================================\n";
    
    // Think of these as working with binary digits (bits)
    int num1 = 5;  // In binary: 00000101
    int num2 = 3;  // In binary: 00000011
    
    std::cout << "Working with binary numbers:\n";
    printBinary(num1, "First number");
    printBinary(num2, "Second number");
    printBinary(num1 & num2, "AND (both 1)");
    printBinary(num1 | num2, "OR (either 1)");
    printBinary(num1 ^ num2, "XOR (different)");
    printBinary(~num1, "NOT (flip bits)");
    printBinary(num1 << 1, "Shift left (×2)");
    printBinary(num1 >> 1, "Shift right (÷2)");

    return 0;
}

/*
This program shows:
1. Basic math operators (+, -, *, /, %)
2. Ways to count up and down (++, --)
3. Different ways to assign values (=, +=, -=, etc.)
4. How to compare values (==, !=, >, <, etc.)
5. How to make logical decisions (&&, ||, !)
6. How to work with binary numbers

Try:
1. Change the values of a and b
2. Add more comparisons
3. Try different logical combinations
4. Experiment with binary numbers
*/
