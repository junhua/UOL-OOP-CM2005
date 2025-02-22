#include "BankAccount.h"
#include <stdexcept>
#include <sstream>

BankAccount::BankAccount(const std::string& number, const std::string& type) 
    : accountNumber(number), balance(0.0), accountType(type) {
    if (!isValidAccountNumber(number)) {
        throw std::invalid_argument("Invalid account number");
    }
}

bool BankAccount::isValidAccountNumber(const std::string& number) const {
    // Simple validation: check if number is 10 digits
    if (number.length() != 10) return false;
    
    // Check if all characters are digits
    for (char c : number) {
        if (!isdigit(c)) return false;
    }
    
    return true;
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive");
    }
    balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive");
    }
    
    if (amount > balance) {
        return false; // Insufficient funds
    }
    
    balance -= amount;
    return true;
}

double BankAccount::getBalance() const {
    return balance;
}

std::string BankAccount::getAccountDetails() const {
    std::stringstream ss;
    ss << "Account Number: " << accountNumber << "\n"
       << "Account Type: " << accountType << "\n"
       << "Current Balance: $" << balance;
    return ss.str();
}
