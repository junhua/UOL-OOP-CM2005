#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Module 6 - Part 2: Access Specifiers
 * Practice Exercise Starter Code
 * 
 * Task: Create a banking system demonstrating:
 * 1. Account class with different access levels
 * 2. Derived account types
 * 3. Friend functions for auditing
 * 4. Proper encapsulation
 */

// TODO: Forward declare AccountAuditor class

// TODO: Create Account base class with:
// - Private: account number, balance
// - Protected: balance update method
// - Public: constructor, deposit, withdraw
// - Friend: AccountAuditor class and display function

// TODO: Create SavingsAccount class that:
// - Inherits from Account
// - Adds interest rate
// - Overrides deposit to add interest
// - Uses protected members from base class

// TODO: Create CheckingAccount class that:
// - Inherits from Account
// - Adds overdraft limit
// - Overrides withdraw to allow overdraft
// - Uses protected members from base class

// TODO: Create AccountAuditor class that:
// - Can access private Account members
// - Provides audit methods for different account types

// TODO: Create friend function to display account details

int main() {
    // TODO: Create different account types
    
    // TODO: Test deposits
    // - Regular deposits
    // - Deposits with interest
    
    // TODO: Test withdrawals
    // - Regular withdrawals
    // - Overdraft withdrawals
    // - Failed withdrawals
    
    // TODO: Test friend class
    // - Audit different accounts
    
    // TODO: Test friend function
    // - Display account details
    
    return 0;
}
