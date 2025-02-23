---
layout: default
title: Part 1 - Defining Classes
nav_order: 1
parent: Module 5 - Classes and Objects
grand_parent: Tutorials
permalink: /tutorials/module5/part1-classes/
---

# Part 1: Defining Classes

## Overview
Classes are the fundamental building blocks of object-oriented programming in C++. They allow you to create custom data types that combine data and functions into a single unit.

## Class Basics

### Class Definition
```cpp
class Student {
private:
    // Data members (attributes)
    string name;
    int age;
    double gpa;
    
public:
    // Member functions (methods)
    void setName(string n) {
        name = n;
    }
    
    string getName() {
        return name;
    }
    
    void setAge(int a) {
        age = a;
    }
    
    int getAge() {
        return age;
    }
};
```

### Access Specifiers
- `private`: Members only accessible within class
- `public`: Members accessible from outside class
- `protected`: Members accessible in derived classes

## Class Members

### Data Members
```cpp
class Rectangle {
private:
    double width;   // Data member
    double height;  // Data member
    
public:
    // Member functions
};
```

### Member Functions
```cpp
class Rectangle {
private:
    double width;
    double height;
    
public:
    // Setter methods
    void setWidth(double w) {
        width = w;
    }
    
    void setHeight(double h) {
        height = h;
    }
    
    // Getter methods
    double getWidth() {
        return width;
    }
    
    double getHeight() {
        return height;
    }
    
    // Other methods
    double getArea() {
        return width * height;
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
};
```

## Class Implementation

### Separate Declaration and Definition
```cpp
// Rectangle.h
class Rectangle {
private:
    double width;
    double height;
    
public:
    void setWidth(double w);
    void setHeight(double h);
    double getWidth();
    double getHeight();
    double getArea();
    double getPerimeter();
};

// Rectangle.cpp
void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setHeight(double h) {
    height = h;
}

double Rectangle::getWidth() {
    return width;
}

double Rectangle::getHeight() {
    return height;
}

double Rectangle::getArea() {
    return width * height;
}

double Rectangle::getPerimeter() {
    return 2 * (width + height);
}
```

## Practice Exercise

Create a class to represent a bank account:
1. Data members for account number, holder name, and balance
2. Methods for deposit, withdrawal, and balance inquiry
3. Proper access control
4. Input validation

Solution:
```cpp
class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    
    // Validate amount is positive
    bool isValidAmount(double amount) {
        return amount > 0;
    }
    
public:
    // Constructor
    BankAccount(string accNum, string name) {
        accountNumber = accNum;
        holderName = name;
        balance = 0.0;
    }
    
    // Getter methods
    string getAccountNumber() {
        return accountNumber;
    }
    
    string getHolderName() {
        return holderName;
    }
    
    double getBalance() {
        return balance;
    }
    
    // Transaction methods
    bool deposit(double amount) {
        if (!isValidAmount(amount)) {
            return false;
        }
        
        balance += amount;
        return true;
    }
    
    bool withdraw(double amount) {
        if (!isValidAmount(amount)) {
            return false;
        }
        
        if (amount > balance) {
            return false;
        }
        
        balance -= amount;
        return true;
    }
    
    // Display account information
    void displayInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    // Create account
    BankAccount account("1234567890", "John Doe");
    
    // Test deposit
    if (account.deposit(1000)) {
        cout << "Deposit successful" << endl;
    }
    
    // Test withdrawal
    if (account.withdraw(500)) {
        cout << "Withdrawal successful" << endl;
    }
    
    // Test invalid withdrawal
    if (!account.withdraw(1000)) {
        cout << "Insufficient funds" << endl;
    }
    
    // Display account information
    account.displayInfo();
    
    return 0;
}
```

## Best Practices

### Class Design
1. Keep classes focused (Single Responsibility)
2. Use appropriate access control
3. Validate input data
4. Provide clear interface
5. Document class behavior

### Data Members
1. Use meaningful names
2. Initialize all members
3. Keep data private
4. Use appropriate types
5. Consider const members

### Member Functions
1. Use clear naming
2. Keep methods focused
3. Validate parameters
4. Consider const methods
5. Document behavior

## Common Mistakes to Avoid
1. Public data members
2. No input validation
3. Poor encapsulation
4. Inconsistent interface
5. Missing documentation

## Next Steps
- Try the practice exercise
- Experiment with class design
- Move on to [Part 2: Constructors and Destructors]({{ site.baseurl }}/tutorials/module5/part2-constructors)
