// This tutorial demonstrates:
// 1. Class templates
// 2. Template member functions
// 3. Template type constraints
// 4. Default template parameters

#include <iostream>
#include <string>
using namespace std;

// Generic Stack class template
template<typename T, int MaxSize = 100>
class Stack {
private:
    T items[MaxSize];
    int top;
    
public:
    Stack() : top(-1) {}
    
    bool push(const T& item) {
        if (top >= MaxSize - 1) return false;
        items[++top] = item;
        return true;
    }
    
    bool pop(T& item) {
        if (top < 0) return false;
        item = items[top--];
        return true;
    }
    
    bool peek(T& item) const {
        if (top < 0) return false;
        item = items[top];
        return true;
    }
    
    bool isEmpty() const {
        return top < 0;
    }
    
    bool isFull() const {
        return top >= MaxSize - 1;
    }
};

// Pair class template with type constraints
template<typename T, typename U>
class Pair {
private:
    T first;
    U second;
    
public:
    Pair(const T& f, const U& s) : first(f), second(s) {}
    
    void setFirst(const T& f) { first = f; }
    void setSecond(const U& s) { second = s; }
    
    T getFirst() const { return first; }
    U getSecond() const { return second; }
    
    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

int main() {
    // Test Stack with integers
    Stack<int, 3> intStack;
    cout << "Pushing integers onto stack:" << endl;
    for (int i = 1; i <= 4; i++) {
        if (intStack.push(i)) {
            cout << "Pushed " << i << endl;
        } else {
            cout << "Stack full, couldn't push " << i << endl;
        }
    }
    
    // Test Stack with strings
    Stack<string> stringStack;  // Uses default size of 100
    stringStack.push("Hello");
    stringStack.push("World");
    
    string word;
    while (stringStack.pop(word)) {
        cout << "Popped: " << word << endl;
    }
    
    // Test Pair with different types
    Pair<int, string> score(95, "High Score");
    Pair<string, double> measurement("Temperature", 23.5);
    
    score.display();
    measurement.display();
    
    return 0;
}
