// File: practice_solution.cpp
// Description: Complete solutions for operator practice exercises

#include <iostream>
#include <iomanip>

int main() {
    std::cout << "Operator Practice Solutions\n";
    std::cout << "=========================\n\n";

    // Exercise 1: Shopping Cart Calculator
    std::cout << "Exercise 1: Shopping Cart Calculator\n";
    std::cout << "--------------------------------\n";
    
    // Initialize prices and quantities
    double item1Price = 24.99, item2Price = 19.99;
    int item1Quantity = 2, item2Quantity = 3;
    double discountPercent = 15.0;  // 15% discount
    double taxRate = 0.08;          // 8% tax
    
    // Calculate subtotal
    double subtotal = (item1Price * item1Quantity) + (item2Price * item2Quantity);
    
    // Calculate discount
    double discountAmount = subtotal * (discountPercent / 100.0);
    double afterDiscount = subtotal - discountAmount;
    
    // Calculate tax
    double taxAmount = afterDiscount * taxRate;
    
    // Calculate final total
    double finalTotal = afterDiscount + taxAmount;
    
    // Display results with proper formatting
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Item 1 (" << item1Quantity << " x $" << item1Price << "): $" 
              << (item1Price * item1Quantity) << "\n";
    std::cout << "Item 2 (" << item2Quantity << " x $" << item2Price << "): $" 
              << (item2Price * item2Quantity) << "\n";
    std::cout << "Subtotal: $" << subtotal << "\n";
    std::cout << "Discount (" << discountPercent << "%): -$" << discountAmount << "\n";
    std::cout << "After Discount: $" << afterDiscount << "\n";
    std::cout << "Tax (8%): $" << taxAmount << "\n";
    std::cout << "Final Total: $" << finalTotal << "\n\n";

    // Exercise 2: Grade Calculator
    std::cout << "Exercise 2: Grade Calculator\n";
    std::cout << "--------------------------\n";
    
    // Assignment scores and weights
    double homework = 95.0, hwWeight = 0.3;    // 30% weight
    double midterm = 88.0, mtWeight = 0.3;     // 30% weight
    double final = 92.0, finalWeight = 0.4;    // 40% weight
    
    // Calculate weighted average
    double finalGrade = (homework * hwWeight) + 
                       (midterm * mtWeight) + 
                       (final * finalWeight);
    
    // Determine pass/fail (passing grade is 70)
    bool passed = finalGrade >= 70.0;
    
    // Display results
    std::cout << "Homework (30%): " << homework << "\n";
    std::cout << "Midterm (30%): " << midterm << "\n";
    std::cout << "Final (40%): " << final << "\n";
    std::cout << "Final Grade: " << finalGrade << "\n";
    std::cout << "Status: " << (passed ? "Passed" : "Failed") << "\n\n";

    // Exercise 3: Temperature Converter
    std::cout << "Exercise 3: Temperature Converter\n";
    std::cout << "------------------------------\n";
    
    // Test temperatures
    double celsius = 25.0;
    double fahrenheit = 98.6;
    
    // Convert Celsius to Fahrenheit: (C × 9/5) + 32
    double celsiusToFahr = (celsius * 9.0/5.0) + 32;
    
    // Convert Fahrenheit to Celsius: (F - 32) × 5/9
    double fahrToCelsius = (fahrenheit - 32) * 5.0/9.0;
    
    // Validate temperature ranges (-50°C to 50°C is reasonable)
    bool celsiusInRange = celsius >= -50 && celsius <= 50;
    bool fahrInRange = fahrToCelsius >= -50 && fahrToCelsius <= 50;
    
    // Display results
    std::cout << std::setprecision(1);
    std::cout << celsius << "°C = " << celsiusToFahr << "°F";
    std::cout << " (Valid: " << std::boolalpha << celsiusInRange << ")\n";
    std::cout << fahrenheit << "°F = " << fahrToCelsius << "°C";
    std::cout << " (Valid: " << fahrInRange << ")\n\n";

    // Exercise 4: Game Score Tracker
    std::cout << "Exercise 4: Game Score Tracker\n";
    std::cout << "---------------------------\n";
    
    // Initialize game variables
    int score = 0;
    int highScore = 1000;
    double multiplier = 1.0;
    bool bonusRoundActive = false;
    
    // Simulate game events
    score += 100;  // Basic points
    std::cout << "Basic points earned: " << score << "\n";
    
    multiplier = 2.0;  // Enter bonus round
    bonusRoundActive = true;
    score *= multiplier;  // Double points
    std::cout << "After bonus multiplier (x" << multiplier << "): " << score << "\n";
    
    score += 150;  // More points during bonus round
    std::cout << "Additional bonus round points: " << score << "\n";
    
    // Check various game conditions
    bool beatHighScore = score > highScore;
    bool bonusAndHighScore = bonusRoundActive && beatHighScore;
    bool extraLife = score >= 500 || bonusRoundActive;
    
    // Display game status
    std::cout << "Final Score: " << score << "\n";
    std::cout << "High Score: " << highScore << "\n";
    std::cout << "Beat high score? " << beatHighScore << "\n";
    std::cout << "Bonus round active? " << bonusRoundActive << "\n";
    std::cout << "Earned bonus and beat high score? " << bonusAndHighScore << "\n";
    std::cout << "Earned extra life? " << extraLife << "\n";

    return 0;
}
