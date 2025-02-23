#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 6 - Part 1: Data Hiding and Abstraction
 * Practice Exercise Starter Code
 * 
 * Task: Create a library management system demonstrating:
 * 1. Book class with hidden details
 * 2. Library class managing books
 * 3. Public interface for operations
 * 4. Private implementation details
 */

// TODO: Create Book class with:
// - Private members for ISBN, title, author, checkout status
// - Private validation method for ISBN
// - Public interface for:
//   * Constructor with validation
//   * Getters for title and author
//   * Methods for checking availability
//   * Methods for checkout and return

// TODO: Create Library class with:
// - Private collection of books
// - Private helper method to find books
// - Public interface for:
//   * Adding books
//   * Checking out books
//   * Returning books
//   * Listing available books

int main() {
    try {
        // TODO: Create library object
        
        // TODO: Add several books
        // - Use valid and invalid ISBNs
        // - Add different authors and titles
        
        // TODO: Test library operations
        // - List available books
        // - Check out some books
        // - Try to check out unavailable books
        // - Return books
        // - List available books again
        
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
