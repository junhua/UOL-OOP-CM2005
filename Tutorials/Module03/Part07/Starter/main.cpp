#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 7: Introduction to Recursion
 * Practice Exercise Starter Code
 * 
 * Task: Create a program that implements several recursive functions:
 * 1. Calculate sum of digits in a number
 * 2. Count occurrences of a digit in a number
 * 3. Print number in reverse
 * 4. Check if string is palindrome
 */

// TODO: Implement sumDigits function
// Parameter: number - the number to sum digits of
// Returns: sum of all digits in the number
// Example: sumDigits(123) returns 6 (1+2+3)

// TODO: Implement countDigit function
// Parameters: 
// - number: the number to search in
// - digit: the digit to count
// Returns: number of times digit appears
// Example: countDigit(11231, 1) returns 3

// TODO: Implement printReverse function
// Parameter: number - the number to print in reverse
// Example: printReverse(123) prints "321"

// TODO: Implement isPalindrome function
// Parameters:
// - str: string to check
// - start: starting index
// - end: ending index
// Returns: true if str is palindrome, false otherwise
// Example: isPalindrome("racecar", 0, 6) returns true

int main() {
    // Test sum of digits
    int number = 12345;
    cout << "Sum of digits in " << number << ": ";
    // TODO: Call sumDigits
    
    // Test count digit
    int digit = 3;
    cout << "\nOccurrences of " << digit << " in " << number << ": ";
    // TODO: Call countDigit
    
    // Test reverse print
    cout << "\n" << number << " in reverse: ";
    // TODO: Call printReverse
    
    // Test palindrome
    string text = "racecar";
    cout << "\n" << text << " is ";
    // TODO: Call isPalindrome and print result
    
    return 0;
}
