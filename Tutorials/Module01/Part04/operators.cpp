// File: operators.cpp
// Description: Demonstrates different types of operators in C++ with real-world examples

#include <iostream>
#include <iomanip>  // For output formatting

int main() {
    std::cout << "C++ Operators in Action\n";
    std::cout << "======================\n\n";

    // Arithmetic Operators - Shopping Cart Example
    std::cout << "Shopping Cart Example:\n";
    std::cout << "------------------\n";
    
    double itemPrice = 29.99;
    int quantity = 3;
    double totalBeforeTax = itemPrice * quantity;  // Multiplication
    double taxRate = 0.08;  // 8% tax
    double taxAmount = totalBeforeTax * taxRate;
    double finalTotal = totalBeforeTax + taxAmount;  // Addition
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Item price: $" << itemPrice << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Total before tax: $" << totalBeforeTax << "\n";
    std::cout << "Tax amount: $" << taxAmount << "\n";
    std::cout << "Final total: $" << finalTotal << "\n\n";

    // Assignment Operators - Score Tracking Example
    std::cout << "Score Tracking Example:\n";
    std::cout << "---------------------\n";
    
    int score = 0;  // Initial score
    std::cout << "Initial score: " << score << "\n";
    
    score += 100;  // Player completes a level
    std::cout << "After completing level: " << score << "\n";
    
    score *= 2;   // Double points bonus
    std::cout << "After double bonus: " << score << "\n";
    
    score -= 50;  // Player takes damage
    std::cout << "After taking damage: " << score << "\n\n";

    // Comparison Operators - Price Comparison Example
    std::cout << "Price Comparison Example:\n";
    std::cout << "-----------------------\n";
    
    double oldPrice = 99.99;
    double salePrice = 79.99;
    double premiumThreshold = 100.00;
    
    bool isDiscounted = (salePrice < oldPrice);
    bool isPremium = (salePrice >= premiumThreshold);
    
    std::cout << "Original price: $" << oldPrice << "\n";
    std::cout << "Sale price: $" << salePrice << "\n";
    std::cout << "Is item discounted? " << std::boolalpha << isDiscounted << "\n";
    std::cout << "Is premium item? " << isPremium << "\n\n";

    // Logical Operators - Discount Eligibility Example
    std::cout << "Discount Eligibility Example:\n";
    std::cout << "---------------------------\n";
    
    bool isMember = true;
    bool spentOver100 = false;
    bool isStudent = true;
    
    // Check various discount conditions
    bool getsDiscount = isMember && spentOver100;  // AND operator
    bool qualifiesForFreeShipping = isStudent || spentOver100;  // OR operator
    bool notEligible = !getsDiscount;  // NOT operator
    
    std::cout << "Customer is a member: " << isMember << "\n";
    std::cout << "Spent over $100: " << spentOver100 << "\n";
    std::cout << "Is a student: " << isStudent << "\n";
    std::cout << "Gets member discount? " << getsDiscount << "\n";
    std::cout << "Gets free shipping? " << qualifiesForFreeShipping << "\n";
    std::cout << "Not eligible for discount? " << notEligible << "\n\n";

    // Operator Precedence - Price Calculation Example
    std::cout << "Price Calculation Example:\n";
    std::cout << "------------------------\n";
    
    int basePrice = 100;
    int discount = 20;
    int taxPercent = 8;
    
    // Different results based on operator precedence
    int total1 = basePrice - discount * taxPercent;  // Multiplication before subtraction
    int total2 = (basePrice - discount) * taxPercent;  // Parentheses control precedence
    
    std::cout << "Base price: $" << basePrice << "\n";
    std::cout << "Discount: $" << discount << "\n";
    std::cout << "Tax percent: " << taxPercent << "%\n";
    std::cout << "Total1 (tax on discount): $" << total1 << "\n";
    std::cout << "Total2 (tax after discount): $" << total2 << "\n";

    return 0;
}
