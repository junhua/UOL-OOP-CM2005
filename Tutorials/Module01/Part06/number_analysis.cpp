// Number Analysis Program
// Think of this program like a data analyst that examines a set of numbers
// and provides useful information about them - like a detective investigating numbers!

#include <iostream>   // For input/output
#include <vector>     // For storing lists of numbers
#include <limits>     // For numeric limits
#include <iomanip>    // For formatting output
#include <cassert>    // For testing

// Structure to hold our analysis results
// Like a report form with different sections
struct NumberStats {
    int min;              // Smallest number found
    int max;              // Largest number found
    double average;       // Average of all numbers
    bool hasNegatives;    // Are there any negative numbers?
    int positiveCount;    // How many positive numbers
    int negativeCount;    // How many negative numbers
    int zeroCount;        // How many zeros
};

// First, declare all the functions we'll need
// Like listing the tools we'll use for our investigation
std::vector<int> getNumbers();                          // Get numbers from user
NumberStats analyzeNumbers(const std::vector<int>& numbers);  // Analyze the numbers
void displayResults(const NumberStats& stats);          // Show the results
void runTests();                                        // Test our analysis
void clearInputBuffer();                               // Clean up input

int main() {
    // First, run our tests to make sure everything works
    // Like checking our tools before starting work
    std::cout << "Running tests...\n";
    runTests();
    std::cout << "All tests passed!\n\n";

    // Welcome message
    std::cout << "Number Analysis Program\n";
    std::cout << "=====================\n\n";

    // Get numbers from the user
    // Like collecting data for analysis
    std::vector<int> numbers = getNumbers();

    // Analyze the numbers
    // Like examining the collected data
    NumberStats stats = analyzeNumbers(numbers);

    // Show what we found
    // Like presenting a report
    displayResults(stats);

    return 0;
}

// Function to get numbers from the user
// Like gathering data for our investigation
std::vector<int> getNumbers() {
    std::vector<int> numbers;  // List to store our numbers
    int number;
    
    std::cout << "Enter numbers (enter any letter to finish):\n";
    
    // Keep reading numbers until user enters something else
    while (std::cin >> number) {
        numbers.push_back(number);  // Add number to our list
    }

    clearInputBuffer();  // Clean up any leftover input
    return numbers;
}

// Function to analyze the numbers
// Like a detective examining evidence
NumberStats analyzeNumbers(const std::vector<int>& numbers) {
    NumberStats stats;  // Our analysis report
    
    // Handle empty list (no numbers entered)
    if (numbers.empty()) {
        stats = {0, 0, 0.0, false, 0, 0, 0};  // Initialize everything to zero
        return stats;
    }

    // Start with the first number
    // Like establishing our initial findings
    stats.min = numbers[0];
    stats.max = numbers[0];
    int sum = numbers[0];  // For calculating average
    stats.hasNegatives = (numbers[0] < 0);
    stats.positiveCount = (numbers[0] > 0) ? 1 : 0;
    stats.negativeCount = (numbers[0] < 0) ? 1 : 0;
    stats.zeroCount = (numbers[0] == 0) ? 1 : 0;

    // Look at all other numbers
    // Like examining each piece of evidence
    for (size_t i = 1; i < numbers.size(); ++i) {
        // Update minimum and maximum
        if (numbers[i] < stats.min) stats.min = numbers[i];
        if (numbers[i] > stats.max) stats.max = numbers[i];

        // Add to sum for average
        sum += numbers[i];

        // Count different types of numbers
        if (numbers[i] > 0) stats.positiveCount++;
        else if (numbers[i] < 0) {
            stats.negativeCount++;
            stats.hasNegatives = true;
        }
        else stats.zeroCount++;
    }

    // Calculate the average
    // Like finding the typical value
    stats.average = static_cast<double>(sum) / numbers.size();

    return stats;
}

// Function to display the results
// Like presenting our findings in a report
void displayResults(const NumberStats& stats) {
    std::cout << "\nAnalysis Results\n";
    std::cout << "===============\n";
    std::cout << std::fixed << std::setprecision(2);  // Show 2 decimal places
    
    // Show all our findings
    std::cout << "Minimum value: " << stats.min << "\n";
    std::cout << "Maximum value: " << stats.max << "\n";
    std::cout << "Average: " << stats.average << "\n";
    std::cout << "Contains negative numbers: " 
              << (stats.hasNegatives ? "Yes" : "No") << "\n";
    
    std::cout << "\nCounts:\n";
    std::cout << "Positive numbers: " << stats.positiveCount << "\n";
    std::cout << "Negative numbers: " << stats.negativeCount << "\n";
    std::cout << "Zeros: " << stats.zeroCount << "\n";
}

// Function to test our analysis
// Like quality control checking our tools
void runTests() {
    // Test 1: Empty list of numbers
    std::vector<int> empty;
    NumberStats emptyStats = analyzeNumbers(empty);
    assert(emptyStats.min == 0);
    assert(emptyStats.max == 0);
    assert(emptyStats.average == 0.0);
    assert(!emptyStats.hasNegatives);
    assert(emptyStats.positiveCount == 0);
    assert(emptyStats.negativeCount == 0);
    assert(emptyStats.zeroCount == 0);

    // Test 2: Single number
    std::vector<int> single = {5};
    NumberStats singleStats = analyzeNumbers(single);
    assert(singleStats.min == 5);
    assert(singleStats.max == 5);
    assert(singleStats.average == 5.0);
    assert(!singleStats.hasNegatives);
    assert(singleStats.positiveCount == 1);
    assert(singleStats.negativeCount == 0);
    assert(singleStats.zeroCount == 0);

    // Test 3: Multiple numbers
    std::vector<int> multiple = {-1, 0, 1, 2, -2};
    NumberStats multipleStats = analyzeNumbers(multiple);
    assert(multipleStats.min == -2);
    assert(multipleStats.max == 2);
    assert(multipleStats.hasNegatives);
    assert(multipleStats.positiveCount == 2);
    assert(multipleStats.negativeCount == 2);
    assert(multipleStats.zeroCount == 1);
}

// Function to clean up input buffer
// Like cleaning our workspace
void clearInputBuffer() {
    std::cin.clear();  // Reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear buffer
}

/*
This program shows:
1. How to analyze a set of numbers
2. How to organize data in a structure
3. How to test our code
4. How to handle different cases
5. How to present results clearly

Try:
1. Enter a mix of positive and negative numbers
2. Enter all positive numbers
3. Enter all negative numbers
4. Enter some zeros
5. Enter just one number
6. Enter no numbers (just a letter)
*/
