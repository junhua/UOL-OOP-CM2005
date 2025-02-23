---
layout: default
title: Part 1 - Data Hiding and Abstraction
nav_order: 1
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part1-data-hiding/
---

# Part 1: Data Hiding and Abstraction

## Overview
Data hiding and abstraction are fundamental principles of encapsulation in object-oriented programming. They help create more maintainable and secure code by controlling access to class members.

## Data Hiding

### Basic Concept
```cpp
class BankAccount {
private:
    double balance;    // Hidden from outside world
    string accountId;  // Hidden from outside world
    
public:
    // Controlled access through methods
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    double getBalance() {
        return balance;
    }
};
```

### Benefits
1. Protection of data integrity
2. Implementation flexibility
3. Reduced complexity
4. Better maintainability
5. Enhanced security

## Abstraction

### Interface vs Implementation
```cpp
class Shape {
private:
    // Implementation details hidden
    double x, y;
    string color;
    
public:
    // Public interface exposed
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void draw() = 0;
    
    void moveTo(double newX, double newY) {
        x = newX;
        y = newY;
    }
};
```

### Implementation Example
```cpp
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double getArea() override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() override {
        // Drawing implementation
    }
};
```

## Practice Exercise

Create a library management system demonstrating data hiding and abstraction:
1. Book class with hidden details
2. Library class managing books
3. Public interface for operations
4. Private implementation details

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string isbn;
    string title;
    string author;
    bool isCheckedOut;
    
    // Private helper method
    bool validateIsbn(const string& isbn) {
        return isbn.length() == 13;  // Simplified validation
    }
    
public:
    // Constructor with validation
    Book(string isbn, string title, string author) {
        if (validateIsbn(isbn)) {
            this->isbn = isbn;
            this->title = title;
            this->author = author;
            this->isCheckedOut = false;
        } else {
            throw invalid_argument("Invalid ISBN");
        }
    }
    
    // Public interface
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
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
};

class Library {
private:
    vector<Book> books;
    
    // Private helper methods
    Book* findBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
    
public:
    // Public interface
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Added: " << book.getTitle() << endl;
    }
    
    bool checkOutBook(const string& title) {
        Book* book = findBook(title);
        if (book && book->isAvailable()) {
            return book->checkOut();
        }
        return false;
    }
    
    void returnBook(const string& title) {
        Book* book = findBook(title);
        if (book) {
            book->returnBook();
            cout << "Returned: " << title << endl;
        }
    }
    
    void listAvailableBooks() const {
        cout << "\nAvailable Books:" << endl;
        cout << "================" << endl;
        for (const auto& book : books) {
            if (book.isAvailable()) {
                cout << book.getTitle() << " by " << book.getAuthor() << endl;
            }
        }
    }
};

int main() {
    try {
        // Create library
        Library library;
        
        // Add books
        library.addBook(Book("1234567890123", "The C++ Programming Language", "Bjarne Stroustrup"));
        library.addBook(Book("1234567890124", "Effective C++", "Scott Meyers"));
        library.addBook(Book("1234567890125", "Design Patterns", "Gang of Four"));
        
        // Show initial state
        library.listAvailableBooks();
        
        // Check out a book
        cout << "\nChecking out books:" << endl;
        if (library.checkOutBook("Effective C++")) {
            cout << "Checked out: Effective C++" << endl;
        }
        
        // Show updated state
        library.listAvailableBooks();
        
        // Return book
        cout << "\nReturning books:" << endl;
        library.returnBook("Effective C++");
        
        // Show final state
        library.listAvailableBooks();
        
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Best Practices

### Data Hiding
1. Make data members private
2. Provide controlled access
3. Validate input data
4. Use const when appropriate
5. Document access patterns

### Abstraction
1. Define clear interfaces
2. Hide implementation details
3. Use meaningful names
4. Keep interfaces simple
5. Separate concerns

### Implementation
1. Use helper methods
2. Handle errors appropriately
3. Maintain encapsulation
4. Document assumptions
5. Consider future changes

## Common Mistakes to Avoid
1. Public data members
2. Exposing implementation
3. Poor validation
4. Inconsistent interfaces
5. Tight coupling

## Next Steps
- Try the practice exercise
- Experiment with encapsulation
- Move on to [Part 2: Access Specifiers]({{ site.baseurl }}/tutorials/module6/part2-access)
