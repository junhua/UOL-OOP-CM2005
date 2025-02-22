#include "Vector2D.h"
#include <iostream>

using namespace std;

int main() {
    // Create Vector2D objects
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    // Test addition
    Vector2D sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl; // Expected output: (4, 6)

    // Test subtraction
    Vector2D diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl; // Expected output: (-2, -2)

    // Test scalar multiplication
    Vector2D scaled = v1 * 3.0;
    cout << "v1 * 3.0 = " << scaled << endl; // Expected output: (3, 6)

    // Test scalar division
    Vector2D divided = v2 / 2.0;
    cout << "v2 / 2.0 = " << divided << endl; // Expected output: (1.5, 2)

    // Test non-member scalar multiplication
    Vector2D scaled2 = 2.0 * v1;
    cout << "2.0 * v1 = " << scaled2 << endl; // Expected output: (2, 4)

    // Test exception handling for division by zero
    try {
        Vector2D result = v1 / 0.0;
    } catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl; // Expected output: Division by zero!
    }

    return 0;
}
