#include <iostream>
#include <iomanip>    // For formatting decimal numbers

int main() {
    std::cout << "Shopping Cart Calculator\n";
    std::cout << "======================\n\n";

    // Constants (values that won't change)
    const double TAX_RATE = 0.07;        // 7% sales tax
    constexpr int MONTHS_IN_YEAR = 12;   // Always 12 months

    // Variables for the calculation
    double itemPrice = 29.99;            // Price with cents
    int quantity = 3;                    // Whole number of items
    float discountPercent = 10.5f;       // Percentage with f suffix

    // Display initial values with proper formatting
    std::cout << "Purchase Details:\n";
    std::cout << "----------------\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Item Price: $" << itemPrice << "\n";
    std::cout << "Quantity: " << quantity << "\n";
    std::cout << "Discount: " << discountPercent << "%\n\n";

    // Calculate subtotal (price * quantity)
    double subtotal = itemPrice * quantity;

    // Calculate discount amount
    double discount = subtotal * (discountPercent / 100.0);

    // Calculate tax on discounted amount
    double tax = TAX_RATE * (subtotal - discount);

    // Calculate final total
    double total = subtotal - discount + tax;

    // Display all calculations
    std::cout << "Calculation Results:\n";
    std::cout << "-----------------\n";
    std::cout << "Subtotal: $" << subtotal << "\n";
    std::cout << "Discount: -$" << discount << "\n";
    std::cout << "Tax: $" << tax << "\n";
    std::cout << "Total: $" << total << "\n\n";

    // Calculate and display monthly payment
    double monthlyPayment = total / MONTHS_IN_YEAR;
    std::cout << "Monthly Payment (12 months): $" << monthlyPayment << "\n";

    return 0;
}
