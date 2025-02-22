#include <iostream>
#include <string>

int main() {
    std::string message = "Hello, world!";

    // Accessing characters
    std::cout << "First character: " << message[0] << std::endl;
    std::cout << "Last character: " << message.back() << std::endl;

    // String length
    std::cout << "Length: " << message.length() << std::endl;

    // Concatenation
    std::string greeting = message + " Welcome!";
    std::cout << greeting << std::endl;

    return 0;
}
