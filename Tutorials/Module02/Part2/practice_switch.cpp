#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

/**
 * Module 2 - Part 2: Switch Statements
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * - Switch statement usage
 * - Input validation
 * - String comparison
 * - Currency handling
 * - Transaction processing
 */

int main() {
    // Constants for prices
    const double WATER_PRICE = 1.00;
    const double COLA_PRICE = 1.50;
    const double ENERGY_PRICE = 2.00;
    const double CHIPS_PRICE = 1.25;
    const double CHOCOLATE_PRICE = 1.75;
    const double CANDY_PRICE = 0.75;
    const double MAX_PAYMENT = 20.00;
    
    // Variables
    string itemCode;
    double payment;
    double price = 0.0;
    double change;
    string itemName;
    bool validInput;
    
    // Display menu
    cout << fixed << setprecision(2);
    cout << "=== Vending Machine ===\n\n"
         << "Available Items:\n"
         << "A1. Water     ($" << WATER_PRICE << ")\n"
         << "A2. Cola      ($" << COLA_PRICE << ")\n"
         << "A3. Energy    ($" << ENERGY_PRICE << ")\n"
         << "B1. Chips     ($" << CHIPS_PRICE << ")\n"
         << "B2. Chocolate ($" << CHOCOLATE_PRICE << ")\n"
         << "B3. Candy     ($" << CANDY_PRICE << ")\n\n";
    
    // Get and validate item selection
    do {
        cout << "Enter item code: ";
        validInput = true;
        cin >> itemCode;
        
        // Convert to uppercase for consistency
        for (char& c : itemCode) {
            c = toupper(c);
        }
        
        // Use switch to validate code and set price
        switch (itemCode[0]) {
            case 'A':
                switch (itemCode[1]) {
                    case '1':
                        price = WATER_PRICE;
                        itemName = "Water";
                        break;
                    case '2':
                        price = COLA_PRICE;
                        itemName = "Cola";
                        break;
                    case '3':
                        price = ENERGY_PRICE;
                        itemName = "Energy Drink";
                        break;
                    default:
                        validInput = false;
                }
                break;
                
            case 'B':
                switch (itemCode[1]) {
                    case '1':
                        price = CHIPS_PRICE;
                        itemName = "Chips";
                        break;
                    case '2':
                        price = CHOCOLATE_PRICE;
                        itemName = "Chocolate";
                        break;
                    case '3':
                        price = CANDY_PRICE;
                        itemName = "Candy";
                        break;
                    default:
                        validInput = false;
                }
                break;
                
            default:
                validInput = false;
        }
        
        if (!validInput || itemCode.length() != 2) {
            cout << "Invalid item code. Please use A1-A3 or B1-B3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    // Get and validate payment
    do {
        cout << "\nPrice: $" << price << endl;
        cout << "Enter payment amount: $";
        validInput = (cin >> payment) && 
                    (payment >= 0) && 
                    (payment <= MAX_PAYMENT);
        
        if (!validInput) {
            cout << "Invalid payment. Please enter an amount between $0 and $"
                 << MAX_PAYMENT << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (payment < price) {
            cout << "Insufficient payment. Please enter at least $" 
                 << price << endl;
            validInput = false;
        }
    } while (!validInput);
    
    // Process transaction
    change = payment - price;
    
    // Display transaction summary
    cout << "\n=== Transaction Summary ===\n"
         << "Item: " << itemName << endl
         << "Price: $" << price << endl
         << "Payment: $" << payment << endl
         << "Change: $" << change << endl;
    
    // Dispense item and change
    cout << "\nDispensing " << itemName << "...\n";
    
    if (change > 0) {
        cout << "Returning change: $" << change << endl;
        
        // Break down change into denominations
        int changeCents = static_cast<int>(change * 100);
        
        // Use switch for each denomination
        switch (changeCents / 100) {
            case 5: cout << "5 dollars\n";
                   changeCents %= 100;
                   break;
            case 4: cout << "4 dollars\n";
                   changeCents %= 100;
                   break;
            case 3: cout << "3 dollars\n";
                   changeCents %= 100;
                   break;
            case 2: cout << "2 dollars\n";
                   changeCents %= 100;
                   break;
            case 1: cout << "1 dollar\n";
                   changeCents %= 100;
                   break;
        }
        
        switch (changeCents / 25) {
            case 3: cout << "75 cents\n"; break;
            case 2: cout << "50 cents\n"; break;
            case 1: cout << "25 cents\n"; break;
        }
        changeCents %= 25;
        
        switch (changeCents / 10) {
            case 2: cout << "20 cents\n"; break;
            case 1: cout << "10 cents\n"; break;
        }
        changeCents %= 10;
        
        switch (changeCents / 5) {
            case 1: cout << "5 cents\n"; break;
        }
        changeCents %= 5;
        
        if (changeCents > 0) {
            cout << changeCents << " cents\n";
        }
    }
    
    cout << "\nThank you for your purchase!\n";
    
    return 0;
}
