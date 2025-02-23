/**
 * Part 05: Basic Operators - Final Implementation
 * 
 * This program demonstrates:
 * 1. Different types of C++ operators
 * 2. Operator precedence and associativity
 * 3. Common operator usage patterns
 * 4. Potential pitfalls and solutions
 */

#include <iostream>
#include <iomanip>

int main() {
    // Set up output formatting
    std::cout << std::fixed << std::setprecision(2);
    
    std::cout << "C++ Operators Demonstration\n";
    std::cout << "==========================\n\n";

    // 1. Arithmetic Operators
    std::cout << "Arithmetic Operators:\n";
    std::cout << "--------------------\n";
    int a = 10, b = 3;
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "Addition (a + b):       " << a + b << "\n";
    std::cout << "Subtraction (a - b):    " << a - b << "\n";
    std::cout << "Multiplication (a * b): " << a * b << "\n";
    std::cout << "Division (a / b):       " << a / b << "\n";
    std::cout << "Modulus (a % b):        " << a % b << "\n\n";

    // 2. Division and Type Conversion
    std::cout << "Division and Type Conversion:\n";
    std::cout << "----------------------------\n";
    double c = 10.0, d = 3.0;
    std::cout << "Integer division (10 / 3):     " << 10 / 3 << "\n";
    std::cout << "Float division (10.0 / 3.0):   " << 10.0 / 3.0 << "\n";
    std::cout << "Mixed division (10.0 / 3):     " << 10.0 / 3 << "\n\n";

    // 3. Assignment Operators
    std::cout << "Assignment Operators:\n";
    std::cout << "--------------------\n";
    int x = 5;
    std::cout << "Initial x: " << x << "\n";
    x += 3;  // x = x + 3
    std::cout << "After x += 3: " << x << "\n";
    x -= 2;  // x = x - 2
    std::cout << "After x -= 2: " << x << "\n";
    x *= 4;  // x = x * 4
    std::cout << "After x *= 4: " << x << "\n";
    x /= 2;  // x = x / 2
    std::cout << "After x /= 2: " << x << "\n";
    x %= 3;  // x = x % 3
    std::cout << "After x %= 3: " << x << "\n\n";

    // 4. Increment/Decrement Operators
    std::cout << "Increment/Decrement Operators:\n";
    std::cout << "----------------------------\n";
    int i = 5;
    std::cout << "Initial i: " << i << "\n";
    std::cout << "Pre-increment (++i):  " << ++i << " (i is now " << i << ")\n";
    std::cout << "Post-increment (i++): " << i++ << " (i is now " << i << ")\n";
    std::cout << "Pre-decrement (--i):  " << --i << " (i is now " << i << ")\n";
    std::cout << "Post-decrement (i--): " << i-- << " (i is now " << i << ")\n\n";

    // 5. Comparison Operators
    std::cout << "Comparison Operators:\n";
    std::cout << "--------------------\n";
    std::cout << std::boolalpha;  // Display bool as true/false
    int p = 5, q = 10;
    std::cout << "p = " << p << ", q = " << q << "\n";
    std::cout << "p == q: " << (p == q) << "\n";
    std::cout << "p != q: " << (p != q) << "\n";
    std::cout << "p < q:  " << (p < q) << "\n";
    std::cout << "p > q:  " << (p > q) << "\n";
    std::cout << "p <= q: " << (p <= q) << "\n";
    std::cout << "p >= q: " << (p >= q) << "\n\n";

    // 6. Logical Operators
    std::cout << "Logical Operators:\n";
    std::cout << "----------------\n";
    bool condition1 = true, condition2 = false;
    std::cout << "condition1 = " << condition1 << ", condition2 = " << condition2 << "\n";
    std::cout << "AND (condition1 && condition2): " << (condition1 && condition2) << "\n";
    std::cout << "OR (condition1 || condition2):  " << (condition1 || condition2) << "\n";
    std::cout << "NOT (!condition1):              " << (!condition1) << "\n";
    std::cout << "NOT (!condition2):              " << (!condition2) << "\n\n";

    // 7. Operator Precedence
    std::cout << "Operator Precedence:\n";
    std::cout << "-------------------\n";
    int result1 = 5 + 3 * 2;        // Multiplication before addition
    int result2 = (5 + 3) * 2;      // Parentheses override precedence
    std::cout << "5 + 3 * 2 = " << result1 << " (multiplication first)\n";
    std::cout << "(5 + 3) * 2 = " << result2 << " (addition first due to parentheses)\n";
    
    // Complex expression
    int result3 = 10 + 20 / 5 - 3 * 2;  // Division and multiplication before addition/subtraction
    std::cout << "10 + 20 / 5 - 3 * 2 = " << result3 << "\n";
    std::cout << "Evaluation: 10 + 4 - 6 = " << result3 << "\n\n";

    return 0;
}

/*
Key Concepts Demonstrated:

1. Arithmetic Operators
   - Basic arithmetic operations
   - Integer vs floating-point division
   - Modulus operation
   - Type conversion effects

2. Assignment Operators
   - Simple assignment
   - Compound assignment
   - Operation and assignment combination

3. Increment/Decrement
   - Pre vs post increment
   - Pre vs post decrement
   - Side effects in expressions

4. Comparison Operators
   - Equality and inequality
   - Relational operators
   - Boolean results

5. Logical Operators
   - AND, OR, NOT operations
   - Short-circuit evaluation
   - Truth tables

6. Operator Precedence
   - Natural precedence
   - Parentheses usage
   - Complex expression evaluation

Best Practices:
- Use parentheses for clarity
- Be careful with integer division
- Watch for increment/decrement side effects
- Consider type promotion in mixed operations
- Document complex expressions
- Test edge cases
*/
