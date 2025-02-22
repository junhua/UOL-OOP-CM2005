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

    // Comparison operators
    bool operator==(const Temperature& other) const;
    bool operator!=(const Temperature& other) const;
    bool operator<(const Temperature& other) const;
    bool operator>(const Temperature& other) const;
    bool operator<=(const Temperature& other) const;
    bool operator>=(const Temperature& other) const;

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Temperature& temp);
};

#endif // TEMPERATURE_H
