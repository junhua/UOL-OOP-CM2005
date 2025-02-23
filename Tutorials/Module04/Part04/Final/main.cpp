#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * Module 4 - Part 4: Common String Operations
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Text analysis functions
 * 2. String transformation
 * 3. Pattern matching
 * 4. Word processing
 */

// Function to count vowels in string
int countVowels(const string& str) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    
    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Function to convert string to title case
string toTitleCase(string str) {
    bool newWord = true;
    
    for (char& c : str) {
        if (isspace(c)) {
            newWord = true;
        } else if (newWord) {
            c = toupper(c);
            newWord = false;
        } else {
            c = tolower(c);
        }
    }
    return str;
}

// Function to find all occurrences of a pattern
void findAllOccurrences(const string& str, const string& pattern) {
    size_t pos = 0;
    while ((pos = str.find(pattern, pos)) != string::npos) {
        cout << "Found at position: " << pos << endl;
        pos++;
    }
}

// Function to process text (remove extra spaces)
string processText(string str) {
    // Trim leading spaces
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start != string::npos) {
        str = str.substr(start);
    }
    
    // Trim trailing spaces
    size_t end = str.find_last_not_of(" \t\n\r");
    if (end != string::npos) {
        str = str.substr(0, end + 1);
    }
    
    // Reduce multiple spaces to single space
    string result;
    bool lastWasSpace = false;
    
    for (char c : str) {
        if (isspace(c)) {
            if (!lastWasSpace) {
                result += ' ';
                lastWasSpace = true;
            }
        } else {
            result += c;
            lastWasSpace = false;
        }
    }
    
    return result;
}

int main() {
    // Text analysis
    string text = "Hello World! This is a test.";
    cout << "Original text: " << text << endl;
    cout << "Number of vowels: " << countVowels(text) << endl;
    cout << "Length: " << text.length() << endl;
    
    // String transformation
    cout << "\nString transformations:" << endl;
    cout << "Title case: " << toTitleCase(text) << endl;
    
    // Convert to upper case
    string upper = text;
    for (char& c : upper) {
        c = toupper(c);
    }
    cout << "Upper case: " << upper << endl;
    
    // Convert to lower case
    string lower = text;
    for (char& c : lower) {
        c = tolower(c);
    }
    cout << "Lower case: " << lower << endl;
    
    // Pattern matching
    cout << "\nPattern matching:" << endl;
    string pattern = "is";
    cout << "Finding all occurrences of '" << pattern << "':" << endl;
    findAllOccurrences(text, pattern);
    
    // Word processing
    cout << "\nWord processing:" << endl;
    string messyText = "   This   has   extra   spaces   ";
    cout << "Original text: \"" << messyText << "\"" << endl;
    
    string cleanText = processText(messyText);
    cout << "Processed text: \"" << cleanText << "\"" << endl;
    
    // Additional string operations
    cout << "\nAdditional operations:" << endl;
    
    // Substring extraction
    string sub = text.substr(0, 5);
    cout << "First 5 characters: " << sub << endl;
    
    // String replacement
    string modified = text;
    size_t replacePos = modified.find("test");
    if (replacePos != string::npos) {
        modified.replace(replacePos, 4, "demo");
    }
    cout << "After replacement: " << modified << endl;
    
    // String insertion
    modified.insert(6, "beautiful ");
    cout << "After insertion: " << modified << endl;
    
    // String erasure
    modified.erase(6, 10);  // Remove "beautiful "
    cout << "After erasure: " << modified << endl;
    
    return 0;
}
