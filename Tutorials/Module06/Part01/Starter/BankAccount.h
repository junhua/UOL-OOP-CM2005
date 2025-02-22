// This tutorial demonstrates:
// 1. Data hiding through private access specifier
// 2. Abstraction by hiding implementation details
// 3. Class organization in header and source files

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
    // TODO: Use appropriate access specifier to hide data members
    // This demonstrates data hiding - a key principle of encapsulation
    std::string accountNumber;
    double balance;
    std::string accountType;
    
    // TODO: Add a private helper method for account number validation
    // This demonstrates abstraction by hiding implementation details
    // Method should be named isValidAccountNumber and take a const string reference
    // Don't forget to make it const as it doesn't modify the object

public:
    // Constructor
    BankAccount(const std::string& number, const std::string& type);
    
    // Public interface methods
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    std::string getAccountDetails() const;
};

#endif // BANK_ACCOUNT_H
