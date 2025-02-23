#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 6 - Part 2: Access Specifiers
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Different access levels (private, protected, public)
 * 2. Friend classes and functions
 * 3. Inheritance and access control
 * 4. Encapsulation principles
 */

// Forward declaration
class AccountAuditor;

class Account {
private:
    string accountNumber;
    double balance;
    
    // Private helper method
    bool isValidAmount(double amount) const {
        return amount > 0;
    }
    
protected:
    // Protected methods for derived classes
    void updateBalance(double amount) {
        balance += amount;
        cout << "Balance updated: $" << fixed << setprecision(2) << balance << endl;
    }
    
    double getBalance() const {
        return balance;
    }
    
public:
    // Constructor
    Account(string number, double initial = 0.0) 
        : accountNumber(number), balance(initial) {
        cout << "Creating account: " << accountNumber << endl;
    }
    
    // Virtual destructor
    virtual ~Account() {
        cout << "Destroying account: " << accountNumber << endl;
    }
    
    // Public interface
    string getAccountNumber() const {
        return accountNumber;
    }
    
    virtual bool deposit(double amount) {
        if (!isValidAmount(amount)) {
            cout << "Invalid deposit amount: $" << amount << endl;
            return false;
        }
        updateBalance(amount);
        return true;
    }
    
    virtual bool withdraw(double amount) {
        if (!isValidAmount(amount)) {
            cout << "Invalid withdrawal amount: $" << amount << endl;
            return false;
        }
        
        if (amount > balance) {
            cout << "Insufficient funds for withdrawal" << endl;
            return false;
        }
        
        updateBalance(-amount);
        return true;
    }
    
    // Friend declarations
    friend class AccountAuditor;
    friend void displayAccountDetails(const Account& account);
};

class SavingsAccount : public Account {
private:
    double interestRate;
    
protected:
    void addInterest() {
        double interest = getBalance() * interestRate;
        cout << "Adding interest: $" << fixed << setprecision(2) << interest << endl;
        updateBalance(interest);
    }
    
public:
    SavingsAccount(string number, double rate = 0.05)
        : Account(number), interestRate(rate) {
        cout << "Creating savings account with " << (rate * 100) << "% interest rate" << endl;
    }
    
    bool deposit(double amount) override {
        bool success = Account::deposit(amount);
        if (success && getBalance() > 1000) {
            cout << "Balance exceeds $1000, adding interest" << endl;
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
        : Account(number), overdraftLimit(limit) {
        cout << "Creating checking account with $" << limit << " overdraft limit" << endl;
    }
    
    bool withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount: $" << amount << endl;
            return false;
        }
        
        if (amount <= getBalance() + overdraftLimit) {
            updateBalance(-amount);
            if (getBalance() < 0) {
                cout << "Warning: Account is overdrawn" << endl;
            }
            return true;
        }
        
        cout << "Amount exceeds overdraft limit" << endl;
        return false;
    }
};

class AccountAuditor {
public:
    void auditAccount(const Account& account) {
        cout << "\nAUDIT REPORT" << endl;
        cout << string(30, '=') << endl;
        cout << "Account: " << account.accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
        cout << string(30, '=') << endl;
    }
    
    void auditSavings(const SavingsAccount& account) {
        cout << "\nSAVINGS AUDIT" << endl;
        cout << string(30, '=') << endl;
        cout << "Account: " << account.getAccountNumber() << endl;
        cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
        cout << string(30, '=') << endl;
    }
};

void displayAccountDetails(const Account& account) {
    cout << "\nAccount Details:" << endl;
    cout << string(30, '=') << endl;
    cout << "Number: " << account.accountNumber << endl;
    cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
    cout << string(30, '=') << endl;
}

int main() {
    cout << "BANKING SYSTEM DEMO" << endl;
    cout << string(50, '=') << endl;
    
    // Create accounts
    cout << "\nCreating Accounts:" << endl;
    cout << string(30, '-') << endl;
    SavingsAccount savings("SAV001", 0.05);
    CheckingAccount checking("CHK001", 500);
    
    // Test deposits
    cout << "\nTesting Deposits:" << endl;
    cout << string(30, '-') << endl;
    
    cout << "\nSavings Account:" << endl;
    savings.deposit(2000);  // Should add interest
    savings.deposit(-100);  // Should fail
    
    cout << "\nChecking Account:" << endl;
    checking.deposit(1000);
    checking.deposit(-50);  // Should fail
    
    // Test withdrawals
    cout << "\nTesting Withdrawals:" << endl;
    cout << string(30, '-') << endl;
    
    cout << "\nChecking Account:" << endl;
    checking.withdraw(1200);  // Should allow overdraft
    checking.withdraw(1000);  // Should fail (exceeds overdraft)
    
    cout << "\nSavings Account:" << endl;
    savings.withdraw(1000);   // Should succeed
    savings.withdraw(2000);   // Should fail
    
    // Test friend class
    cout << "\nTesting Friend Class Access:" << endl;
    cout << string(30, '-') << endl;
    
    AccountAuditor auditor;
    auditor.auditAccount(checking);
    auditor.auditSavings(savings);
    
    // Test friend function
    cout << "\nTesting Friend Function Access:" << endl;
    cout << string(30, '-') << endl;
    
    displayAccountDetails(savings);
    displayAccountDetails(checking);
    
    cout << "\nEnd of Demo" << endl;
    cout << string(50, '=') << endl;
    
    return 0;
}
