// This tutorial demonstrates:
// 1. Map container basics
// 2. Key-value pair operations
// 3. Map element access
// 4. Map iterators and algorithms

#include <iostream>
#include <map>
#include <string>
using namespace std;

// Custom class for map values
class GameScore {
private:
    int score;
    string date;
    
public:
    GameScore(int s = 0, string d = "") : score(s), date(d) {}
    
    int getScore() const { return score; }
    string getDate() const { return date; }
    
    void updateScore(int newScore) {
        if(newScore > score) {
            score = newScore;
            date = "Updated";
        }
    }
    
    void display() const {
        cout << "Score: " << score << " (Date: " << date << ")" << endl;
    }
};

int main() {
    // Create a map of string to int
    // map<Key, Value> maintains key-value pairs in sorted order by key
    map<string, int> studentGrades;
    
    // Insert elements using different methods
    studentGrades["Alice"] = 95;  // operator[] creates or updates element
    studentGrades.insert({"Bob", 87});  // insert() with initializer list
    studentGrades.insert(make_pair("Charlie", 91));  // insert() with make_pair
    
    // Range-based for loop provides easy access to key-value pairs
    // Each element is a pair<const Key, Value>
    cout << "Initial grades:" << endl;
    for(const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Update existing value using operator[]
    // If key exists, value is updated; if not, new element is created
    studentGrades["Bob"] = 89;
    
    // Safe way to check for existence before access
    // count() returns 1 if key exists, 0 if not
    string searchName = "David";
    if(studentGrades.count(searchName) > 0) {
        cout << "\nFound " << searchName << "'s grade: " << studentGrades[searchName] << endl;
    } else {
        cout << "\n" << searchName << "'s grade not found" << endl;
    }
    
    // Create map with custom value type
    // Key type must support operator<
    map<string, GameScore> gameScores;
    
    // Insert elements using different methods
    // Each element is a key-value pair
    gameScores["Player1"] = GameScore(1000, "2024-02-01");  // Using operator[]
    gameScores["Player2"] = GameScore(850, "2024-02-02");   // Using operator[]
    gameScores.insert({"Player3", GameScore(920, "2024-02-03")});  // Using insert
    
    // Iterator provides access to key-value pairs
    // Use -> to access members through iterator
    cout << "\nGame Scores:" << endl;
    for(map<string, GameScore>::iterator it = gameScores.begin(); it != gameScores.end(); ++it) {
        cout << it->first << " - ";  // Access key
        it->second.display();        // Access value
    }
    
    // Update values through map access
    // Changes are reflected in stored objects
    gameScores["Player2"].updateScore(900);  // Will update (900 > 850)
    gameScores["Player1"].updateScore(950);  // Won't update (950 < 1000)
    
    // Find and erase element
    // find() returns iterator to element or end() if not found
    auto it = gameScores.find("Player3");
    if(it != gameScores.end()) {
        gameScores.erase(it);  // Erase using iterator
    }
    
    // Final state after modifications
    // Range-based for loop works with any container
    cout << "\nFinal Scores:" << endl;
    for(const auto& pair : gameScores) {
        cout << pair.first << " - ";
        pair.second.display();
    }
    
    return 0;
}
