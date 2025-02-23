#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

int main() {
    // Declare variables
    std::string name;
    int age;
    double height;

    // Get name using getline
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Get age with input validation
    while (true) {
        std::cout << "Enter your age: ";
        if (std::cin >> age && age > 0 && age < 150) {
            break;
        }
        std::cout << "Invalid age. Please enter a number between 1 and 150.\n";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    }

    // Clear the newline from the input buffer after reading age
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Get height with input validation
    while (true) {
        std::cout << "Enter your height in meters: ";
        if (std::cin >> height && height > 0 && height < 3) {
            break;
        }
        std::cout << "Invalid height. Please enter a number between 0 and 3.\n";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    }

    // Format and display the information
    std::cout << "\n--- Personal Information ---\n";
    std::cout << std::left << std::setw(15) << "Name:" << name << std::endl;
    std::cout << std::left << std::setw(15) << "Age:" << age << " years" << std::endl;
    std::cout << std::left << std::setw(15) << "Height:" 
              << std::fixed << std::setprecision(2) << height << " meters" << std::endl;

    // Calculate and display height in centimeters
    int heightCm = static_cast<int>(height * 100);
    std::cout << std::left << std::setw(15) << "Height (cm):" << heightCm << " cm" << std::endl;

    return 0;
}
