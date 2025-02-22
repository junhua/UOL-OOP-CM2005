#include <iostream>
#include "StringProcessor.h"

void demonstrateBasicOperations() {
    std::cout << "\n=== Basic String Operations ===\n" << std::endl;
    
    StringProcessor proc("Hello, World! 123");
    proc.display();
    
    // Test case conversion
    std::cout << "\nCase conversion:" << std::endl;
    std::cout << "Uppercase: " << proc.toUpperCase() << std::endl;
    std::cout << "Lowercase: " << proc.toLowerCase() << std::endl;
}

void demonstrateSearchOperations() {
    std::cout << "\n=== Search Operations ===\n" << std::endl;
    
    StringProcessor proc("The quick brown fox jumps over the lazy dog");
    proc.display();
    
    // Test search operations
    std::cout << "\nSearching for 'fox':" << std::endl;
    if (proc.contains("fox")) {
        std::cout << "Found 'fox' at position: " 
             << proc.findFirst("fox") << std::endl;
    }
    
    std::cout << "\nSearching for 'the':" << std::endl;
    std::cout << "First occurrence at: " 
         << proc.findFirst("the") << std::endl;
    std::cout << "Last occurrence at: " 
         << proc.findLast("the") << std::endl;
}

void demonstrateModificationOperations() {
    std::cout << "\n=== Modification Operations ===\n" << std::endl;
    
    StringProcessor proc("   Hello,    World!   ");
    proc.display();
    
    // Test trimming
    std::cout << "\nAfter trimming:" << std::endl;
    std::cout << "\"" << proc.trim() << "\"" << std::endl;
    
    // Test replacement
    std::cout << "\nReplacing 'World' with 'C++':" << std::endl;
    std::cout << proc.replace("World", "C++") << std::endl;
}

void demonstrateSplitJoinOperations() {
    std::cout << "\n=== Split and Join Operations ===\n" << std::endl;
    
    StringProcessor proc("apple,banana,orange,grape");
    proc.display();
    
    // Test split
    std::cout << "\nSplitting by comma:" << std::endl;
    std::vector<std::string> parts = proc.split(',');
    for (const auto& part : parts) {
        std::cout << "- " << part << std::endl;
    }
    
    // Test join
    std::cout << "\nJoining with ' | ':" << std::endl;
    std::cout << StringProcessor::join(parts, " | ") << std::endl;
}

void demonstrateAnalysisOperations() {
    std::cout << "\n=== Analysis Operations ===\n" << std::endl;
    
    // Test character frequency
    StringProcessor proc1("hello");
    proc1.display();
    std::cout << "\nCharacter frequency:" << std::endl;
    auto freq = proc1.getCharacterFrequency();
    for (const auto& [ch, count] : freq) {
        std::cout << "'" << ch << "': " << count << std::endl;
    }
    
    // Test palindrome
    StringProcessor proc2("radar");
    proc2.display();
    std::cout << "\nIs palindrome? " 
         << (proc2.isPalindrome() ? "Yes" : "No") << std::endl;
    
    StringProcessor proc3("hello");
    proc3.display();
    std::cout << "Is palindrome? " 
         << (proc3.isPalindrome() ? "Yes" : "No") << std::endl;
}

int main() {
    std::cout << "String Processing Demo 📝\n" << std::endl;
    
    // Demonstrate all operations
    demonstrateBasicOperations();
    demonstrateSearchOperations();
    demonstrateModificationOperations();
    demonstrateSplitJoinOperations();
    demonstrateAnalysisOperations();
    
    // TODO: Implement each operation in StringProcessor class:
    // 1. Basic operations:
    //    - Convert case using character functions
    //    - Handle each character individually
    
    // 2. Search operations:
    //    - Use string::find and string::rfind
    //    - Check for string::npos
    
    // 3. Modification operations:
    //    - Use string::replace for substitution
    //    - Use string::find_first/last_not_of for trimming
    
    // 4. Split/Join operations:
    //    - Use string::find and string::substr for splitting
    //    - Build result string incrementally for joining
    
    // 5. Analysis operations:
    //    - Use map to count character frequencies
    //    - Compare characters from both ends for palindrome
    
    return 0;
}
