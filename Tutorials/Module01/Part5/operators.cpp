#include <iostream>
#include <iomanip>

int main() {
    // Arithmetic Operators
    std::cout << "--- Arithmetic Operators ---\n";
    int a = 10, b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Addition: a + b = " << a + b << std::endl;
    std::cout << "Subtraction: a - b = " << a - b << std::endl;
    std::cout << "Multiplication: a * b = " << a * b << std::endl;
    std::cout << "Division: a / b = " << a / b << std::endl;
    std::cout << "Modulus: a % b = " << a % b << std::endl;

    // Assignment Operators
    std::cout << "\n--- Assignment Operators ---\n";
    int x = 5;
    std::cout << "Initial x = " << x << std::endl;
    x += 3;  // x = x + 3
    std::cout << "After x += 3: x = " << x << std::endl;
    x -= 2;  // x = x - 2
    std::cout << "After x -= 2: x = " << x << std::endl;
    x *= 4;  // x = x * 4
    std::cout << "After x *= 4: x = " << x << std::endl;
    x /= 2;  // x = x / 2
    std::cout << "After x /= 2: x = " << x << std::endl;
    x %= 3;  // x = x % 3
    std::cout << "After x %= 3: x = " << x << std::endl;

    // Comparison Operators
    std::cout << "\n--- Comparison Operators ---\n";
    int p = 5, q = 10;
    std::cout << "p = " << p << ", q = " << q << std::endl;
    std::cout << std::boolalpha;  // Print bool as true/false instead of 1/0
    std::cout << "p == q: " << (p == q) << std::endl;
    std::cout << "p != q: " << (p != q) << std::endl;
    std::cout << "p > q: " << (p > q) << std::endl;
    std::cout << "p < q: " << (p < q) << std::endl;
    std::cout << "p >= q: " << (p >= q) << std::endl;
    std::cout << "p <= q: " << (p <= q) << std::endl;

    // Logical Operators
    std::cout << "\n--- Logical Operators ---\n";
    bool condition1 = true, condition2 = false;
    std::cout << "condition1 = " << condition1 << ", condition2 = " << condition2 << std::endl;
    std::cout << "AND (&&): " << (condition1 && condition2) << std::endl;
    std::cout << "OR (||): " << (condition1 || condition2) << std::endl;
    std::cout << "NOT (!): " << (!condition1) << std::endl;

    // Increment/Decrement Operators
    std::cout << "\n--- Increment/Decrement Operators ---\n";
    int i = 5, j;
    std::cout << "Initial i = " << i << std::endl;
    
    // Pre-increment
    j = ++i;  // i is incremented first, then j gets the new value
    std::cout << "After j = ++i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-increment
    j = i++;  // j gets the original value, then i is incremented
    std::cout << "After j = i++: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Pre-decrement
    j = --i;  // i is decremented first, then j gets the new value
    std::cout << "After j = --i: i = " << i << ", j = " << j << std::endl;
    
    i = 5;  // Reset i
    // Post-decrement
    j = i--;  // j gets the original value, then i is decremented
    std::cout << "After j = i--: i = " << i << ", j = " << j << std::endl;

    return 0;
}
