#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * Module 5 - Part 1: Defining Classes
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Class definition with proper access control
 * 2. Constructor and member functions
 * 3. Input validation
 * 4. Transaction handling
 */

class BankAccount {
private:
    string accountNumber;
    string holderName;
    double balance;
    
    // Validate amount is positive
    bool isValidAmount(double amount) const {
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
    string getAccountNumber() const {
        return accountNumber;
    }
    
    string getHolderName() const {
        return holderName;
    }
    
    double getBalance() const {
        return balance;
    }
    
    // Transaction methods
    bool deposit(double amount) {
        // Validate deposit amount
        if (!isValidAmount(amount)) {
            cout << "Error: Invalid deposit amount" << endl;
            return false;
        }
        
        balance += amount;
        cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        return true;
    }
    
    bool withdraw(double amount) {
        // Validate withdrawal amount
        if (!isValidAmount(amount)) {
            cout << "Error: Invalid withdrawal amount" << endl;
            return false;
        }
        
        // Check sufficient funds
        if (amount > balance) {
            cout << "Error: Insufficient funds" << endl;
            return false;
        }
        
        balance -= amount;
        cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
        return true;
    }
    
    // Display account information
    void displayInfo() const {
        cout << "\nAccount Information:" << endl;
        cout << "===================" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "===================" << endl;
    }
};

int main() {
    // Create a bank account
    BankAccount account("1234567890", "John Doe");
    cout << "Created account for " << account.getHolderName() << endl;
    
    // Test deposit functionality
    cout << "\nTesting deposits:" << endl;
    cout << "----------------" << endl;
    
    // Valid deposit
    account.deposit(1000.50);
    
    // Invalid deposit (negative amount)
    account.deposit(-100);
    
    // Test withdrawal functionality
    cout << "\nTesting withdrawals:" << endl;
    cout << "-------------------" << endl;
    
    // Valid withdrawal
    account.withdraw(500.25);
    
    // Withdrawal with insufficient funds
    account.withdraw(1000);
    
    // Invalid withdrawal (negative amount)
    account.withdraw(-50);
    
    // Small withdrawal
    account.withdraw(0.25);
    
    // Display final account state
    account.displayInfo();
    
    // Additional test cases
    cout << "\nAdditional tests:" << endl;
    cout << "----------------" << endl;
    
    // Zero amount deposit
    account.deposit(0);
    
    // Very large deposit
    account.deposit(1000000);
    
    // Very small withdrawal
    account.withdraw(0.01);
    
    // Final account state
    account.displayInfo();
    
    return 0;
}
