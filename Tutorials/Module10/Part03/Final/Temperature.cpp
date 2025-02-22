#include "Temperature.h"
#include <stdexcept>
#include <iomanip>

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
            celsius = (temp - 32.0) * 5.0 / 9.0;
            break;
        case 'K':
        case 'k':
            celsius = temp - 273.15;
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
    return (celsius * 9.0 / 5.0) + 32.0;
}

double Temperature::getKelvin() const {
    return celsius + 273.15;
}

// Comparison operators
bool Temperature::operator==(const Temperature& other) const {
    // Compare with small epsilon for floating-point comparison
    const double epsilon = 0.0001;
    return std::abs(celsius - other.celsius) < epsilon;
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

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Temperature& temp) {
    os << std::fixed << std::setprecision(2)
       << temp.celsius << "°C ("
       << temp.getFahrenheit() << "°F, "
       << temp.getKelvin() << "K)";
    return os;
}
