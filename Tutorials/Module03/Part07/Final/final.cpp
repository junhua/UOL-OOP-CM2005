#include <iostream>
using namespace std;

// Simple recursion example: counting down
void countDown(int n) {
    // Base case: stop when we reach 0
    if (n <= 0) {
        cout << "Blast off!" << endl;
        return;
    }
    
    // Print current number
    cout << n << "... ";
    
    // Recursive case: count down by calling with n-1
    countDown(n - 1);
    
    // This line shows the "unwinding" of recursion
    cout << "Finished counting " << n << endl;
}

// Calculate power using recursion
int calculatePower(int base, int exponent) {
    // Base cases
    if (exponent == 0) return 1;  // anything^0 = 1
    if (exponent == 1) return base;  // anything^1 = itself
    
    // Recursive case: break down into smaller power
    // Example: 2^4 = 2 * 2^3
    cout << "Calculating " << base << "^" << exponent 
         << " = " << base << " * " << base << "^" 
         << (exponent-1) << endl;
         
    return base * calculatePower(base, exponent - 1);
}

// Calculate factorial using recursion
int factorial(int n) {
    // Base cases
    if (n <= 1) return 1;  // 0! and 1! are both 1
    
    // Recursive case: n! = n * (n-1)!
    cout << "Calculating " << n << "! = " << n << " * " 
         << (n-1) << "!" << endl;
         
    return n * factorial(n - 1);
}

// Calculate Fibonacci number using recursion
int fibonacci(int n) {
    // Base cases
    if (n <= 1) return n;  // F(0) = 0, F(1) = 1
    
    // Recursive case: F(n) = F(n-1) + F(n-2)
    cout << "F(" << n << ") = F(" << (n-1) << ") + F(" 
         << (n-2) << ")" << endl;
         
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Learning about recursion!\n\n";
    
    // Test countdown
    cout << "Counting down from 5:\n";
    countDown(5);
    
    // Test power calculation
    cout << "\nTesting power calculation:\n";
    cout << "2^3 = " << calculatePower(2, 3) << endl;
    cout << "3^2 = " << calculatePower(3, 2) << endl;
    
    // Test factorial
    cout << "\nTesting factorial:\n";
    cout << "5! = " << factorial(5) << endl;
    
    // Test Fibonacci
    cout << "\nFirst 6 Fibonacci numbers:\n";
    for (int i = 0; i < 6; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }
    
    return 0;
}
