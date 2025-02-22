#include "BankAccount.h"
#include <stdexcept>
#include <sstream>

// TODO: Implement the constructor
// 1. Initialize all member variables using the initialization list
// 2. Call isValidAccountNumber to validate the account number
// 3. Throw std::invalid_argument if the account number is invalid
BankAccount::BankAccount(const std::string& number, const std::string& type) {
    // Your implementation here
}

// TODO: Implement account number validation
// 1. Check if the number is exactly 10 digits long
// 2. Verify that all characters are digits
// Return true only if both conditions are met
bool BankAccount::isValidAccountNumber(const std::string& number) const {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement the deposit method
// 1. Validate that the amount is positive
// 2. If amount is not positive, throw std::invalid_argument
// 3. Add the amount to the balance
void BankAccount::deposit(double amount) {
    // Your implementation here
}

// TODO: Implement the withdraw method
// 1. Validate that the amount is positive
// 2. Check if there are sufficient funds
// 3. If amount is not positive, throw std::invalid_argument
// 4. If insufficient funds, return false
// 5. If successful, subtract amount from balance and return true
bool BankAccount::withdraw(double amount) {
    // Your implementation here
    return false; // Placeholder return
}

// TODO: Implement the balance getter
// Return the current balance
double BankAccount::getBalance() const {
    // Your implementation here
    return 0.0; // Placeholder return
}

// TODO: Implement the account details getter
// Return a string containing:
// - Account Number
// - Account Type
// - Current Balance
// Use stringstream for string formatting
std::string BankAccount::getAccountDetails() const {
    // Your implementation here
    return ""; // Placeholder return
}
