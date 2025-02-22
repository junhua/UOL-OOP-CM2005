// Shopping Cart Calculator
// This program demonstrates how to use different types of variables
// to calculate prices, discounts, and payment plans - just like
// a real shopping cart system!

#include <iostream>   // For input/output
#include <iomanip>    // For formatting numbers

int main() {
    // Constants (values that never change)
    // Like store policies that stay the same
    const double TAX_RATE = 0.07;        // 7% sales tax
    constexpr int MONTHS_IN_YEAR = 12;   // Always 12 months in a year

    // Variables (values that can change)
    // Like items in your shopping cart
    double itemPrice = 29.99;            // Price with cents (needs decimal)
    int quantity = 3;                    // Whole number of items
    float discountPercent = 10.5f;       // Discount percentage (f means float)
    
    // Calculations
    // Step 1: Calculate subtotal (price × quantity)
    // Like multiplying item price by how many you're buying
    double subtotal = itemPrice * quantity;
    
    // Step 2: Calculate discount amount
    // Convert percentage to decimal (10.5% → 0.105)
    // Then multiply by subtotal
    double discount = subtotal * (discountPercent / 100.0);
    
    // Step 3: Calculate amount subject to tax
    // Subtract discount from subtotal
    double taxableAmount = subtotal - discount;
    
    // Step 4: Calculate sales tax
    // Multiply taxable amount by tax rate
    double salesTax = taxableAmount * TAX_RATE;
    
    // Step 5: Calculate final total
    // Add taxable amount and sales tax
    double totalCost = taxableAmount + salesTax;
    
    // Step 6: Calculate monthly payment
    // Divide total by 12 months and round to whole dollars
    // static_cast<int> removes the decimal part
    int monthlyPayment = static_cast<int>(totalCost / MONTHS_IN_YEAR);
    
    // Display results in a neat format
    // Like a receipt from the store
    std::cout << "Shopping Cart Calculator\n";
    std::cout << "======================\n\n";
    
    // Original prices and quantities
    std::cout << "Purchase Details:\n";
    std::cout << "----------------\n";
    std::cout << "Item Price: $" << std::fixed << std::setprecision(2) << itemPrice << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Discount: " << discountPercent << "%\n\n";
    
    // All calculations
    std::cout << "Calculation Breakdown:\n";
    std::cout << "--------------------\n";
    std::cout << "1. Subtotal: $" << subtotal 
              << " (price × quantity)\n";
    std::cout << "2. Discount: $" << discount 
              << " (" << discountPercent << "% off)\n";
    std::cout << "3. After Discount: $" << taxableAmount 
              << " (subtotal - discount)\n";
    std::cout << "4. Sales Tax: $" << salesTax 
              << " (" << (TAX_RATE * 100) << "% tax)\n";
    std::cout << "5. Total Cost: $" << totalCost 
              << " (after tax)\n\n";
    
    // Payment plan
    std::cout << "Monthly Payment Plan:\n";
    std::cout << "-------------------\n";
    std::cout << "Monthly Payment: $" << monthlyPayment 
              << " (total ÷ " << MONTHS_IN_YEAR 
              << " months, rounded down)\n";
    
    return 0;
}

/*
This program demonstrates:
1. Using different variable types (int, double, float)
2. Working with constants (const, constexpr)
3. Performing calculations with different types
4. Converting between types (type casting)
5. Formatting output to look nice

Try changing the values of:
- itemPrice
- quantity
- discountPercent
and see how it affects the calculations!

Also try:
1. Adding more items with different prices
2. Calculating different payment plans
3. Adding more discount types
4. Improving the receipt format
*/
