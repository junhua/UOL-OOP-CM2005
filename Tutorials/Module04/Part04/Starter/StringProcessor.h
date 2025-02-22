#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class StringProcessor {
private:
    std::string text;

public:
    StringProcessor(const std::string& input) : text(input) {}
    
    // Basic operations
    std::string toUpperCase() const {
        // TODO: Convert text to uppercase
        // Hint: Use std::toupper in a loop
        return text;
    }
    
    std::string toLowerCase() const {
        // TODO: Convert text to lowercase
        // Hint: Use std::tolower in a loop
        return text;
    }
    
    // Search operations
    bool contains(const std::string& substr) const {
        // TODO: Check if text contains substr
        // Hint: Use string::find
        return false;
    }
    
    int findFirst(const std::string& substr) const {
        // TODO: Find first occurrence of substr
        // Hint: Use string::find and check for string::npos
        return -1;
    }
    
    int findLast(const std::string& substr) const {
        // TODO: Find last occurrence of substr
        // Hint: Use string::rfind and check for string::npos
        return -1;
    }
    
    // Modification operations
    std::string replace(const std::string& oldStr, 
                       const std::string& newStr) const {
        // TODO: Replace all occurrences of oldStr with newStr
        // Hint: Use string::find in a loop with string::replace
        return text;
    }
    
    std::string trim() const {
        // TODO: Remove leading and trailing whitespace
        // Hint: Use string::find_first_not_of and string::find_last_not_of
        return text;
    }
    
    // Split and join operations
    std::vector<std::string> split(char delimiter) const {
        // TODO: Split text into vector of strings by delimiter
        // Hint: Use string::find and string::substr in a loop
        return std::vector<std::string>();
    }
    
    static std::string join(const std::vector<std::string>& parts, 
                          const std::string& delimiter) {
        // TODO: Join vector of strings with delimiter
        // Hint: Build result string using a loop
        return "";
    }
    
    // Analysis operations
    std::map<char, int> getCharacterFrequency() const {
        // TODO: Count frequency of each character
        // Hint: Use a map to store character counts
        return std::map<char, int>();
    }
    
    bool isPalindrome() const {
        // TODO: Check if text is a palindrome
        // Hint: Compare characters from start and end
        return false;
    }
    
    // Display the processed text
    void display() const {
        std::cout << "Current text: \"" << text << "\"" << std::endl;
    }
};

#endif // STRING_PROCESSOR_H
