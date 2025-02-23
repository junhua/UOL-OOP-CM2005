#include <iostream>
#include <iomanip>

// Function to print a line separator
void printSeparator() {
    std::cout << "\n----------------------------------------\n";
}

int main() {
    // 1. Calculator Operations
    std::cout << "=== Calculator Operations ===\n";
    
    int a = 15, b = 4;
    std::cout << "Numbers: a = " << a << ", b = " << b << std::endl;
    
    // Basic arithmetic
    std::cout << "\nBasic Arithmetic:" << std::endl;
    std::cout << "Addition: " << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << "Subtraction: " << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << "Multiplication: " << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << "Division: " << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << "Modulus: " << a << " % " << b << " = " << (a % b) << std::endl;

    // Operator precedence
    std::cout << "\nOperator Precedence:" << std::endl;
    int result = a + b * 2 - 3;  // Multiplication before addition
    std::cout << "a + b * 2 - 3 = " << result << std::endl;
    result = (a + b) * 2 - 3;    // Parentheses change precedence
    std::cout << "(a + b) * 2 - 3 = " << result << std::endl;

    printSeparator();

    // 2. Logical Operations
    std::cout << "=== Logical Operations ===\n";
    
    bool p = true, q = false;
    std::cout << std::boolalpha;  // Display true/false instead of 1/0
    
    // Basic logical operations
    std::cout << "\nBasic Logic:" << std::endl;
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << "AND (p && q): " << (p && q) << std::endl;
    std::cout << "OR (p || q): " << (p || q) << std::endl;
    std::cout << "NOT p (!p): " << (!p) << std::endl;

    // Truth table
    std::cout << "\nTruth Table for AND:" << std::endl;
    std::cout << std::setw(6) << "A" << std::setw(6) << "B" << std::setw(8) << "A && B" << std::endl;
    std::cout << std::setw(6) << "true" << std::setw(6) << "true" << std::setw(8) << (true && true) << std::endl;
    std::cout << std::setw(6) << "true" << std::setw(6) << "false" << std::setw(8) << (true && false) << std::endl;
    std::cout << std::setw(6) << "false" << std::setw(6) << "true" << std::setw(8) << (false && true) << std::endl;
    std::cout << std::setw(6) << "false" << std::setw(6) << "false" << std::setw(8) << (false && false) << std::endl;

    // Short-circuit evaluation
    std::cout << "\nShort-circuit Evaluation:" << std::endl;
    bool result1 = false && (std::cout << "This won't print" << std::endl, true);
    bool result2 = true || (std::cout << "This won't print" << std::endl, false);
    std::cout << "false && (...) = " << result1 << std::endl;
    std::cout << "true || (...) = " << result2 << std::endl;

    printSeparator();

    // 3. Increment/Decrement
    std::cout << "=== Increment/Decrement Operations ===\n";
    
    int x = 5;
    std::cout << "\nStarting value: x = " << x << std::endl;

    // Pre-increment
    std::cout << "\nPre-increment (++x):" << std::endl;
    std::cout << "Before: " << x << std::endl;
    std::cout << "During: " << ++x << std::endl;
    std::cout << "After: " << x << std::endl;

    // Post-increment
    x = 5;  // Reset value
    std::cout << "\nPost-increment (x++):" << std::endl;
    std::cout << "Before: " << x << std::endl;
    std::cout << "During: " << x++ << std::endl;
    std::cout << "After: " << x << std::endl;

    // Common usage in loop
    std::cout << "\nIncrement in loop:" << std::endl;
    for(int i = 0; i < 3; ++i) {  // Pre-increment preferred in loops
        std::cout << "Loop iteration: " << i << std::endl;
    }

    return 0;
}
