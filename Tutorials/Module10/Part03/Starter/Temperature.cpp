#include "Temperature.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Temperature::Temperature() : celsius(0.0) {}

// Parameterized constructor with unit conversion
Temperature::Temperature(double temp, char unit) {
    switch (unit) {
        case 'C':
        case 'c':
            celsius = temp;
            break;
        case 'F':
        case 'f':
            celsius = (temp - 32.0) * 5.0 / 9.0;  // Convert Fahrenheit to Celsius
            break;
        case 'K':
        case 'k':
            celsius = temp - 273.15;  // Convert Kelvin to Celsius
            break;
        default:
            throw std::invalid_argument("Invalid temperature unit. Use C, F, or K.");
    }
}

// Getter methods with unit conversion
double Temperature::getCelsius() const {
    return celsius;
}

double Temperature::getFahrenheit() const {
    return (celsius * 9.0 / 5.0) + 32.0;  // Convert Celsius to Fahrenheit
}

double Temperature::getKelvin() const {
    return celsius + 273.15;  // Convert Celsius to Kelvin
}

bool Temperature::operator==(const Temperature& other) const {
    return std::abs(celsius - other.celsius) < 0.0001;
}

bool Temperature::operator!=(const Temperature& other) const {
    return !(*this == other);
}

bool Temperature::operator<(const Temperature& other) const {
    return celsius < other.celsius;
}

bool Temperature::operator>(const Temperature& other) const {
    return other < *this;
}

bool Temperature::operator<=(const Temperature& other) const {
    return !(other < *this);
}

bool Temperature::operator>=(const Temperature& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Temperature& temp) {
    os << fixed << setprecision(2) << temp.getCelsius() << "°C";
    os << " (" << fixed << setprecision(2) << temp.getFahrenheit() << "°F";
    os << ", " << fixed << setprecision(2) << temp.getKelvin() << "K)";
    return os;
}
