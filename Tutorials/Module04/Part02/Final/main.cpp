#include <iostream>
#include <array>
#include <stdexcept>
using namespace std;

// Safe element access
template<typename T, size_t N>
T getElement(const array<T, N>& arr, size_t index) {
    return arr.at(index);  // Uses bounds checking
}

// Sum of elements
template<typename T, size_t N>
T arraySum(const array<T, N>& arr) {
    T sum = T();  // Zero-initialize
    for (const T& element : arr) {
        sum += element;
    }
    return sum;
}

// Print array in reverse
template<typename T, size_t N>
void printReverse(const array<T, N>& arr) {
    for (size_t i = N; i-- > 0; ) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Find element
template<typename T, size_t N>
int findElement(const array<T, N>& arr, const T& value) {
    for (size_t i = 0; i < N; i++) {
        if (arr[i] == value) {
            return static_cast<int>(i);
        }
    }
    return -1;  // Not found
}

int main() {
    // Create and initialize array
    std::array<int, 5> numbers = {10, 20, 30, 40, 50};
    
    // Safe access
    try {
        std::cout << "Element 2: " 
             << getElement(numbers, 2) << std::endl;
        std::cout << "Element 5: " 
             << getElement(numbers, 5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Array operations
    std::cout << "Sum: " << arraySum(numbers) << std::endl;
    
    std::cout << "Reverse order: ";
    printReverse(numbers);
    
    // Finding elements
    int index = findElement(numbers, 30);
    if (index != -1) {
        std::cout << "Found 30 at index " << index << std::endl;
    }
    
    // Modifying elements
    for (size_t i = 0; i < numbers.size(); i++) {
        numbers[i] *= 2;  // Double each element
    }
    
    // Print modified array
    std::cout << "Modified array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
