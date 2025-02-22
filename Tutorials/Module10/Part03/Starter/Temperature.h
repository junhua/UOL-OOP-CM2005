#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>

class Temperature {
private:
    double celsius;  // Store temperature in Celsius internally

public:
    // Constructors
    Temperature();
    Temperature(double temp, char unit = 'C');  // Default unit is Celsius

    // Getter methods with unit conversion
    double getCelsius() const;
    double getFahrenheit() const;
    double getKelvin() const;

    // TODO: Declare comparison operators
    // 1. operator== to check if two temperatures are equal
    // 2. operator!= to check if two temperatures are not equal
    // 3. operator< to check if this temperature is less than other
    // 4. operator> to check if this temperature is greater than other
    // 5. operator<= to check if this temperature is less than or equal to other
    // 6. operator>= to check if this temperature is greater than or equal to other
    // Hint: All operators should be const member functions taking const Temperature reference
    bool operator==(const Temperature& other) const;
    bool operator!=(const Temperature& other) const;
    bool operator<(const Temperature& other) const;
    bool operator>(const Temperature& other) const;
    bool operator<=(const Temperature& other) const;
    bool operator>=(const Temperature& other) const;

    // TODO: Declare the friend operator<< for output stream
    // Hint: Should display temperature in all three units (C, F, K)
    friend std::ostream& operator<<(std::ostream& os, const Temperature& temp);
};

#endif // TEMPERATURE_H
