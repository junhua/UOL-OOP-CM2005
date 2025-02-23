#include <iostream>
// TODO: Add iomanip header for formatting numbers

int main() {
    std::cout << "Shopping Cart Calculator\n";
    std::cout << "======================\n\n";

    // TODO: Declare constants
    // 1. Create a constant for tax rate (7% = 0.07)
    // 2. Create a constant for months in year (12)
    // Hint: Use 'const' or 'constexpr'


    // TODO: Declare variables for the calculation
    // 1. Item price (use double for precise decimals)
    // 2. Quantity (use int for whole numbers)
    // 3. Discount percentage (use float)
    // Hint: Initialize with reasonable values


    std::cout << "Purchase Details:\n";
    std::cout << "----------------\n";

    // TODO: Display initial values
    // 1. Show item price
    // 2. Show quantity
    // 3. Show discount percentage
    // Hint: Use std::fixed and std::setprecision for formatting


    // TODO: Calculate subtotal (price * quantity)


    // TODO: Calculate discount amount (subtotal * discount percentage / 100)


    // TODO: Calculate tax (tax rate * (subtotal - discount))


    // TODO: Calculate final total
    // Hint: subtotal - discount + tax


    std::cout << "\nCalculation Results:\n";
    std::cout << "-----------------\n";

    // TODO: Display all calculations
    // 1. Subtotal
    // 2. Discount amount
    // 3. Tax amount
    // 4. Final total
    // Hint: Format all money values to 2 decimal places


    // TODO: Extra Challenge:
    // 1. Calculate monthly payment (total / 12)
    // 2. Show monthly payment amount


    return 0;
}
