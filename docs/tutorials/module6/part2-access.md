---
layout: default
title: Part 2 - Access Specifiers
nav_order: 2
parent: Module 6 - Core OOP Concepts - Encapsulation
grand_parent: Tutorials
permalink: /tutorials/module6/part2-access/
---

# Part 2: Access Specifiers

## Overview
Access specifiers in C++ control the visibility and accessibility of class members. They are fundamental to implementing encapsulation and data hiding.

## Access Levels

### Private Access
```cpp
class BankAccount {
private:
    double balance;      // Only accessible within class
    string accountId;    // Only accessible within class
    
    void updateBalance() {  // Private helper method
        // Implementation
    }
};
```

### Public Access
```cpp
class BankAccount {
public:
    void deposit(double amount) {    // Accessible everywhere
        // Implementation
    }
    
    double getBalance() const {      // Accessible everywhere
        return balance;
    }
};
```

### Protected Access
```cpp
class Account {
protected:
    double balance;    // Accessible in derived classes
    string accountId;  // Accessible in derived classes
};

class SavingsAccount : public Account {
public:
    void addInterest() {
        balance *= 1.05;  // Can access protected member
    }
};
```

## Access Control

### Friend Functions
```cpp
class BankAccount {
private:
    double balance;
    
public:
    // Declare friend function
    friend void auditAccount(const BankAccount& account);
};

// Friend function can access private members
void auditAccount(const BankAccount& account) {
    cout << "Balance: " << account.balance << endl;
}
```

### Friend Classes
```cpp
class BankAccount {
private:
    double balance;
    
    // Declare friend class
    friend class AccountAuditor;
};

class AccountAuditor {
public:
    void audit(const BankAccount& account) {
        cout << "Balance: " << account.balance << endl;
    }
};
```

## Practice Exercise

Create a banking system demonstrating access control:
1. Account class with different access levels
2. Derived account types
3. Friend functions for auditing
4. Proper encapsulation

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Forward declaration
class AccountAuditor;

class Account {
private:
    string accountNumber;
    double balance;
    
    // Private helper methods
    bool isValidAmount(double amount) const {
        return amount > 0;
    }
    
protected:
    // Protected members for derived classes
    void updateBalance(double amount) {
        balance += amount;
    }
    
    double getBalance() const {
        return balance;
    }
    
public:
    // Constructor
    Account(string number, double initial = 0.0) 
        : accountNumber(number), balance(initial) {}
    
    // Public interface
    string getAccountNumber() const {
        return accountNumber;
    }
    
    virtual bool deposit(double amount) {
        if (!isValidAmount(amount)) {
            return false;
        }
        updateBalance(amount);
        return true;
    }
    
    virtual bool withdraw(double amount) {
        if (!isValidAmount(amount) || amount > balance) {
            return false;
        }
        updateBalance(-amount);
        return true;
    }
    
    // Friend declaration
    friend class AccountAuditor;
    friend void displayAccountDetails(const Account& account);
};

class SavingsAccount : public Account {
private:
    double interestRate;
    
protected:
    void addInterest() {
        double interest = getBalance() * interestRate;
        updateBalance(interest);
    }
    
public:
    SavingsAccount(string number, double rate = 0.05)
        : Account(number), interestRate(rate) {}
    
    bool deposit(double amount) override {
        bool success = Account::deposit(amount);
        if (success && getBalance() > 1000) {
            addInterest();
        }
        return success;
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;
    
public:
    CheckingAccount(string number, double limit = 100)
        : Account(number), overdraftLimit(limit) {}
    
    bool withdraw(double amount) override {
        if (amount <= 0) {
            return false;
        }
        
        if (amount <= getBalance() + overdraftLimit) {
            updateBalance(-amount);
            return true;
        }
        return false;
    }
};

// Friend class implementation
class AccountAuditor {
public:
    void auditAccount(const Account& account) {
        cout << "\nAUDIT REPORT" << endl;
        cout << "============" << endl;
        cout << "Account: " << account.accountNumber << endl;
        cout << "Balance: $" << account.balance << endl;
    }
    
    void auditSavings(const SavingsAccount& account) {
        cout << "\nSAVINGS AUDIT" << endl;
        cout << "=============" << endl;
        cout << "Account: " << account.getAccountNumber() << endl;
        cout << "Balance: $" << account.getBalance() << endl;
    }
};

// Friend function implementation
void displayAccountDetails(const Account& account) {
    cout << "Account Details:" << endl;
    cout << "Number: " << account.accountNumber << endl;
    cout << "Balance: $" << account.balance << endl;
}

int main() {
    // Create accounts
    SavingsAccount savings("SAV001", 0.05);
    CheckingAccount checking("CHK001", 500);
    
    // Test deposits
    cout << "Testing deposits:" << endl;
    cout << "================" << endl;
    
    savings.deposit(2000);  // Should add interest
    checking.deposit(1000);
    
    // Test withdrawals
    cout << "\nTesting withdrawals:" << endl;
    cout << "===================" << endl;
    
    checking.withdraw(1200);  // Should allow overdraft
    savings.withdraw(3000);   // Should fail
    
    // Test friend class
    AccountAuditor auditor;
    auditor.auditAccount(checking);
    auditor.auditSavings(savings);
    
    // Test friend function
    cout << "\nAccount Details:" << endl;
    cout << "===============" << endl;
    displayAccountDetails(savings);
    displayAccountDetails(checking);
    
    return 0;
}
```

## Best Practices

### Access Control
1. Make data members private
2. Use protected for inheritance
3. Minimize friend declarations
4. Document access patterns
5. Consider const correctness

### Friend Usage
1. Use sparingly
2. Document relationships
3. Consider alternatives
4. Group related friends
5. Maintain encapsulation

### Implementation
1. Validate input data
2. Use helper methods
3. Consider inheritance
4. Handle errors appropriately
5. Document assumptions

## Common Mistakes to Avoid
1. Public data members
2. Excessive friend usage
3. Poor encapsulation
4. Inconsistent access
5. Broken inheritance

## Next Steps
- Try the practice exercise
- Experiment with access control
- Move on to [Part 3: Getter and Setter Methods]({{ site.baseurl }}/tutorials/module6/part3-getters-setters)
