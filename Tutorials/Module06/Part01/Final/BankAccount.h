// This tutorial demonstrates:
// 1. Data hiding through private access specifier
// 2. Abstraction by hiding implementation details
// 3. Class organization in header and source files

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
private:
    // Data members are private to demonstrate data hiding
    std::string accountNumber;
    double balance;
    std::string accountType;
    
    // Private helper method to demonstrate abstraction
    // Implementation details hidden from the user
    bool isValidAccountNumber(const std::string& number) const;

public:
    // Constructor
    BankAccount(const std::string& number, const std::string& type);
    
    // Public methods provide a clean interface
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
    std::string getAccountDetails() const;
};

#endif // BANK_ACCOUNT_H
