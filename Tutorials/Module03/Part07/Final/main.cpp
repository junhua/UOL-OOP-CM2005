#include <iostream>
#include <string>
using namespace std;

/**
 * Module 3 - Part 7: Introduction to Recursion
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Recursive sum of digits
 * 2. Recursive digit counting
 * 3. Recursive number reversal
 * 4. Recursive palindrome check
 */

// Calculate sum of digits recursively
int sumDigits(int number) {
    // Base case: single digit
    if (number < 10) {
        return number;
    }
    
    // Recursive case: add last digit to sum of remaining digits
    return (number % 10) + sumDigits(number / 10);
}

// Count occurrences of a digit recursively
int countDigit(int number, int digit) {
    // Base case: no more digits
    if (number == 0) {
        return 0;
    }
    
    // Check last digit and recurse with remaining digits
    int lastDigit = number % 10;
    return (lastDigit == digit ? 1 : 0) + countDigit(number / 10, digit);
}

// Print number in reverse recursively
void printReverse(int number) {
    // Base case: single digit
    if (number < 10) {
        cout << number;
        return;
    }
    
    // Print last digit and recurse with remaining digits
    cout << number % 10;
    printReverse(number / 10);
}

// Check if string is palindrome recursively
bool isPalindrome(string str, int start, int end) {
    // Base case: empty string or single character
    if (start >= end) {
        return true;
    }
    
    // If characters don't match, not a palindrome
    if (str[start] != str[end]) {
        return false;
    }
    
    // Check remaining characters
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    // Test sum of digits
    int number = 12345;
    cout << "Sum of digits in " << number << ": " 
         << sumDigits(number) << endl;
    
    // Test count digit
    int digit = 3;
    cout << "Occurrences of " << digit << " in " << number << ": " 
         << countDigit(number, digit) << endl;
    
    // Test reverse print
    cout << number << " in reverse: ";
    printReverse(number);
    cout << endl;
    
    // Test palindrome with different strings
    string text1 = "racecar";
    string text2 = "hello";
    
    cout << text1 << " is " 
         << (isPalindrome(text1, 0, text1.length() - 1) ? "" : "not ")
         << "a palindrome" << endl;
         
    cout << text2 << " is " 
         << (isPalindrome(text2, 0, text2.length() - 1) ? "" : "not ")
         << "a palindrome" << endl;
    
    return 0;
}
