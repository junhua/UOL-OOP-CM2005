// TODO: Add program-level documentation comment
// Hint: Use this format:
/**
 * Program: [program name]
 * Purpose: [what the program does]
 * Features:
 * - [feature 1]
 * - [feature 2]
 * - [etc.]
 */

#include <iostream>

// TODO: Add function documentation comment
// Hint: Document parameters and return value using @param and @return
// Example:
/**
 * [function description]
 * @param a [description of parameter a]
 * @param b [description of parameter b]
 * @return [description of return value]
 */
int add(int a, int b) {
    return a + b;  // TODO: Add inline comment explaining the operation
}

// TODO: Add function documentation comment
// Hint: Follow the same format as the add function above
int subtract(int a, int b) {
    return a - b;  // TODO: Add inline comment explaining the operation
}

int main() {
    // TODO: Add section comment explaining the program header
    // Hint: Describe what this section does (displays title/welcome message)
    std::cout << "=== Simple Calculator ===\n\n";
    
    // TODO: Add comments explaining the input process
    // Hint: Describe what each input is for and how it's obtained
    int num1;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    
    int num2;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    
    /* TODO: Add a multi-line comment explaining this section
     * Hint: Describe:
     * - What operations are being performed
     * - Why these calculations are needed
     * - What the results represent
     */
    int sum = add(num1, num2);
    int difference = subtract(num1, num2);
    
    // TODO: Add comments explaining the output formatting
    // Hint: Describe how the results are displayed and why this format was chosen
    std::cout << "\nResults:\n";
    std::cout << num1 << " + " << num2 << " = " << sum << "\n";
    std::cout << num1 << " - " << num2 << " = " << difference << "\n";
    
    return 0;  // TODO: Add comment explaining the return value
}
