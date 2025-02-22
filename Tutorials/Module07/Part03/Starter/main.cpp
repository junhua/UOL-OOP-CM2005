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
    // Create and populate a map of string to int
    map<string, int> studentGrades;
    
    // Insert elements using different methods
    studentGrades["Alice"] = 95;  // Using operator[]
    studentGrades.insert({"Bob", 87});  // Using insert()
    studentGrades.insert(make_pair("Charlie", 91));  // Using make_pair
    
    // Access and modify elements
    cout << "Initial grades:" << endl;
    for(const auto& pair : studentGrades) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // Update existing value
    studentGrades["Bob"] = 89;
    
    // Check if key exists before access
    string searchName = "David";
    if(studentGrades.count(searchName) > 0) {
        cout << "\nFound " << searchName << "'s grade: " << studentGrades[searchName] << endl;
    } else {
        cout << "\n" << searchName << "'s grade not found" << endl;
    }
    
    // Create map with custom value type
    map<string, GameScore> gameScores;
    
    // Insert scores
    gameScores["Player1"] = GameScore(1000, "2024-02-01");
    gameScores["Player2"] = GameScore(850, "2024-02-02");
    gameScores.insert({"Player3", GameScore(920, "2024-02-03")});
    
    // Display all scores using iterator
    cout << "\nGame Scores:" << endl;
    for(map<string, GameScore>::iterator it = gameScores.begin(); it != gameScores.end(); ++it) {
        cout << it->first << " - ";
        it->second.display();
    }
    
    // Update score if new score is higher
    gameScores["Player2"].updateScore(900);
    gameScores["Player1"].updateScore(950);  // Won't update - lower than current
    
    // Find and erase an element
    auto it = gameScores.find("Player3");
    if(it != gameScores.end()) {
        gameScores.erase(it);
    }
    
    // Final scores
    cout << "\nFinal Scores:" << endl;
    for(const auto& pair : gameScores) {
        cout << pair.first << " - ";
        pair.second.display();
    }
    
    return 0;
}
