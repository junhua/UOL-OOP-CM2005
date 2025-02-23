#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 6 - Part 1: Data Hiding and Abstraction
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Data hiding through private members
 * 2. Abstraction through public interfaces
 * 3. Encapsulation of implementation details
 * 4. Validation and error handling
 */

class Book {
private:
    string isbn;
    string title;
    string author;
    bool isCheckedOut;
    
    // Private helper method for validation
    bool validateIsbn(const string& isbn) const {
        // Check length
        if (isbn.length() != 13) {
            return false;
        }
        
        // Check if all characters are digits
        for (char c : isbn) {
            if (!isdigit(c)) {
                return false;
            }
        }
        
        return true;
    }
    
public:
    // Constructor with validation
    Book(string isbn, string title, string author) {
        if (!validateIsbn(isbn)) {
            throw invalid_argument("Invalid ISBN - must be 13 digits");
        }
        
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->isCheckedOut = false;
        
        cout << "Created book: " << title << endl;
    }
    
    // Public interface methods
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getIsbn() const { return isbn; }
    bool isAvailable() const { return !isCheckedOut; }
    
    bool checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            return true;
        }
        return false;
    }
    
    void returnBook() {
        isCheckedOut = false;
    }
    
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }
};

class Library {
private:
    vector<Book> books;
    string libraryName;
    
    // Private helper method to find books
    Book* findBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
    
public:
    // Constructor
    Library(const string& name = "Main Library") : libraryName(name) {
        cout << "Created library: " << libraryName << endl;
    }
    
    // Public interface methods
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Added to library: " << book.getTitle() << endl;
    }
    
    bool checkOutBook(const string& title) {
        Book* book = findBook(title);
        if (book && book->isAvailable()) {
            if (book->checkOut()) {
                cout << "Checked out: " << title << endl;
                return true;
            }
        }
        cout << "Could not check out: " << title << endl;
        return false;
    }
    
    void returnBook(const string& title) {
        Book* book = findBook(title);
        if (book) {
            book->returnBook();
            cout << "Returned: " << title << endl;
        } else {
            cout << "Book not found: " << title << endl;
        }
    }
    
    void listAvailableBooks() const {
        cout << "\nAvailable Books at " << libraryName << ":" << endl;
        cout << string(40, '=') << endl;
        bool hasAvailable = false;
        
        for (const auto& book : books) {
            if (book.isAvailable()) {
                hasAvailable = true;
                cout << "Title: " << left << setw(30) << book.getTitle();
                cout << "Author: " << book.getAuthor() << endl;
            }
        }
        
        if (!hasAvailable) {
            cout << "No books currently available" << endl;
        }
        cout << string(40, '=') << endl;
    }
    
    void displayLibraryStats() const {
        int totalBooks = books.size();
        int availableBooks = 0;
        
        for (const auto& book : books) {
            if (book.isAvailable()) {
                availableBooks++;
            }
        }
        
        cout << "\nLibrary Statistics:" << endl;
        cout << "==================" << endl;
        cout << "Total books: " << totalBooks << endl;
        cout << "Available: " << availableBooks << endl;
        cout << "Checked out: " << (totalBooks - availableBooks) << endl;
    }
};

int main() {
    try {
        // Create library
        Library library("Community Library");
        
        // Add books with valid ISBNs
        library.addBook(Book("1234567890123", "The C++ Programming Language", "Bjarne Stroustrup"));
        library.addBook(Book("1234567890124", "Effective C++", "Scott Meyers"));
        library.addBook(Book("1234567890125", "Design Patterns", "Gang of Four"));
        
        // Show initial state
        library.listAvailableBooks();
        library.displayLibraryStats();
        
        // Test checkout operations
        cout << "\nTesting checkout operations:" << endl;
        cout << "==========================" << endl;
        
        // Successful checkout
        library.checkOutBook("Effective C++");
        
        // Try to checkout same book again
        library.checkOutBook("Effective C++");
        
        // Try to checkout non-existent book
        library.checkOutBook("Invalid Book");
        
        // Show state after checkouts
        library.listAvailableBooks();
        library.displayLibraryStats();
        
        // Test return operations
        cout << "\nTesting return operations:" << endl;
        cout << "=========================" << endl;
        
        // Return book
        library.returnBook("Effective C++");
        
        // Try to return non-existent book
        library.returnBook("Invalid Book");
        
        // Show final state
        library.listAvailableBooks();
        library.displayLibraryStats();
        
        // Test invalid ISBN
        cout << "\nTesting invalid ISBN:" << endl;
        cout << "====================" << endl;
        library.addBook(Book("123", "Invalid Book", "Test Author"));  // Should throw exception
        
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
