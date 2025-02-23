#include <iostream>
#include <string>
using namespace std;

/**
 * Module 4 - Part 3: Strings
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Basic string manipulation
 * 2. String searching and extraction
 * 3. String comparison and conversion
 * 4. Mixed string operations
 */

int main() {
    // Basic string operations
    string text = "Hello, World!";
    cout << "Original text: " << text << endl;
    
    // String manipulation
    text[0] = 'h';                     // Modify character
    text.append(" Welcome");           // Append text
    cout << "Modified text: " << text << endl;
    
    // String information
    cout << "Length: " << text.length() << endl;
    cout << "First char: " << text.front() << endl;
    cout << "Last char: " << text.back() << endl;
    
    // String searching and extraction
    // Substring operations
    string sub = text.substr(0, 5);    // Get "hello"
    cout << "\nSubstring operations:" << endl;
    cout << "First 5 chars: " << sub << endl;
    
    // Find operations
    size_t pos = text.find("World");
    cout << "\nFind operations:" << endl;
    if (pos != string::npos) {
        cout << "Found 'World' at position: " << pos << endl;
    }
    
    // Replace operations
    text.replace(text.find("World"), 5, "Everyone");
    cout << "After replacing 'World' with 'Everyone': " << text << endl;
    
    // String comparison and conversion
    cout << "\nString comparison:" << endl;
    string str1 = "apple";
    string str2 = "banana";
    
    if (str1 < str2) {
        cout << str1 << " comes before " << str2 << endl;
    }
    
    if (str1.compare(str2) < 0) {
        cout << "Using compare(): " << str1 << " comes before " << str2 << endl;
    }
    
    // String conversion
    cout << "\nString conversion:" << endl;
    string numStr = "123";
    try {
        int num = stoi(numStr);            // String to int
        cout << "Converted '" << numStr << "' to int: " << num << endl;
        
        string backToStr = to_string(num);  // Int to string
        cout << "Converted back to string: " << backToStr << endl;
        
        // Try invalid conversion
        string invalid = "12.34";
        int badNum = stoi(invalid);
    } catch (const invalid_argument& e) {
        cout << "Invalid conversion attempted!" << endl;
    }
    
    // String splitting
    cout << "\nString splitting:" << endl;
    string sentence = "This is a test sentence";
    size_t start = 0;
    size_t end = sentence.find(" ");
    
    cout << "Words in sentence:" << endl;
    while (end != string::npos) {
        cout << "- " << sentence.substr(start, end - start) << endl;
        start = end + 1;
        end = sentence.find(" ", start);
    }
    cout << "- " << sentence.substr(start) << endl;
    
    // Additional string operations
    cout << "\nAdditional operations:" << endl;
    
    // Insert
    string msg = "Hello";
    msg.insert(5, " there");
    cout << "After insert: " << msg << endl;
    
    // Erase
    msg.erase(5, 6);  // Erase " there"
    cout << "After erase: " << msg << endl;
    
    // Check if string contains substring
    if (msg.find("Hell") != string::npos) {
        cout << "String contains 'Hell'" << endl;
    }
    
    // Convert to upper case
    for (char& c : msg) {
        c = toupper(c);
    }
    cout << "Uppercase: " << msg << endl;
    
    return 0;
}
