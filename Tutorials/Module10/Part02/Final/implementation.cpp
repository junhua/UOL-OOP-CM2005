// This tutorial demonstrates:
// 1. STL Associative Containers
// 2. Ordered vs Unordered Containers
// 3. Key-Value Pairs
// 4. Container Adaptors

#include <iostream>
#include <string>
#include <set>           // For ordered set
#include <map>          // For ordered map
#include <unordered_set>  // For hash-based set
#include <unordered_map>  // For hash-based map

// Student structure for demonstrating custom types in containers
struct Student {
    int id;                // Unique identifier
    std::string name;      // Student name
    
    // Constructor for easy object creation
    Student(int i, std::string n) : id(i), name(n) {}
    
    // Less-than operator for ordered containers (set, map)
    // Required for ordering elements in set
    bool operator<(const Student& other) const {
        return id < other.id;  // Order by ID
    }
    
    // Equality operator for unordered containers
    // Required for hash table lookup
    bool operator==(const Student& other) const {
        return id == other.id;  // Compare by ID
    }
};

// Hash function for Student class
// Required for unordered_set to compute hash table index
namespace std {
    template<>
    struct hash<Student> {
        // Hash function should return size_t
        size_t operator()(const Student& s) const {
            // Use existing hash function for int
            return hash<int>()(s.id);  // Hash based on ID
        }
    };
}

// Generic print function for containers of Student objects
template<typename Container>
void printContainer(const std::string& label, const Container& container) {
    std::cout << "\n" << label << ":" << std::endl;
    // Range-based for loop works with any container
    for(const auto& element : container) {
        std::cout << element.id << ": " << element.name << std::endl;
    }
}

// Generic print function for map containers
template<typename Map>
void printMap(const std::string& label, const Map& map) {
    std::cout << "\n" << label << ":" << std::endl;
    // Structured binding for easy key-value access
    for(const auto& [key, value] : map) {
        std::cout << key << " -> " << value << std::endl;
    }
}

int main() {
    // Set demonstration
    // Properties:
    // - Elements are ordered (requires operator<)
    // - Elements are unique
    // - Logarithmic time operations O(log n)
    std::set<Student> studentSet;
    
    // Insert elements into set
    studentSet.insert(Student(101, "Alice"));
    studentSet.insert(Student(103, "Charlie"));
    studentSet.insert(Student(102, "Bob"));
    // Duplicate will be ignored
    studentSet.insert(Student(101, "Alice"));  
    
    printContainer("Student Set (Ordered)", studentSet);
    
    // Find element in set
    // Only need ID for comparison due to operator==
    auto setIt = studentSet.find(Student(102, ""));
    if(setIt != studentSet.end()) {
        std::cout << "\nFound student: " << setIt->name << std::endl;
    }
    
    // Unordered Set demonstration
    // Properties:
    // - Elements are not ordered
    // - Elements are unique
    // - Constant time operations O(1) average
    std::unordered_set<Student> studentUnorderedSet;
    
    // Insert elements into unordered_set
    studentUnorderedSet.insert(Student(201, "David"));
    studentUnorderedSet.insert(Student(203, "Frank"));
    studentUnorderedSet.insert(Student(202, "Eve"));
    // Duplicate will be ignored
    studentUnorderedSet.insert(Student(201, "David"));
    
    printContainer("Student Unordered Set", studentUnorderedSet);
    
    // Map demonstration
    // Properties:
    // - Key-value pairs
    // - Keys are unique and ordered
    // - Logarithmic time operations O(log n)
    std::map<int, std::string> studentMap;
    
    // Insert elements using operator[]
    studentMap[301] = "Grace";
    studentMap[303] = "Ivy";
    studentMap[302] = "Henry";
    // Existing key will be updated
    studentMap[301] = "Grace2";
    
    printMap("Student Map (Ordered)", studentMap);
    
    // Find value in map
    auto mapIt = studentMap.find(302);
    if(mapIt != studentMap.end()) {
        std::cout << "\nFound student with ID 302: " << mapIt->second << std::endl;
    }
    
    // Unordered Map demonstration
    // Properties:
    // - Key-value pairs
    // - Keys are unique but not ordered
    // - Constant time operations O(1) average
    std::unordered_map<int, std::string> studentUnorderedMap;
    
    // Insert elements using operator[]
    studentUnorderedMap[401] = "Jack";
    studentUnorderedMap[403] = "Linda";
    studentUnorderedMap[402] = "Kelly";
    // Existing key will be updated
    studentUnorderedMap[401] = "Jack2";
    
    printMap("Student Unordered Map", studentUnorderedMap);
    
    // Advanced container operations
    
    // Set operations
    std::cout << "\nSet Operations:" << std::endl;
    std::cout << "Set size: " << studentSet.size() << std::endl;
    
    // Insert with hint (iterator to position)
    // More efficient if position is correct
    auto hint = studentSet.end();
    studentSet.insert(hint, Student(104, "Diana"));
    
    // Erase element by value
    studentSet.erase(Student(101, ""));  // Only need ID
    
    // Map operations
    std::cout << "\nMap Operations:" << std::endl;
    std::cout << "Map size: " << studentMap.size() << std::endl;
    
    // Check if key exists
    if(studentMap.count(301) > 0) {
        std::cout << "Student 301 exists in map" << std::endl;
    }
    
    // Insert using emplace (constructs in-place)
    studentMap.emplace(304, "Mike");
    
    // Erase by key
    studentMap.erase(301);
    
    // Final state
    printContainer("Final Set", studentSet);
    printMap("Final Map", studentMap);
    
    // Container selection guidelines:
    // Use set/map when:
    // - Elements must be ordered
    // - You need logarithmic time operations
    // - Memory overhead for ordering is acceptable
    
    // Use unordered_set/unordered_map when:
    // - Element order doesn't matter
    // - You need fastest possible lookups
    // - Memory overhead for hash table is acceptable
    
    return 0;
}
