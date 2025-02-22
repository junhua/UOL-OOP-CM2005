// This tutorial demonstrates:
// 1. Class templates
// 2. Template member functions
// 3. Template type constraints
// 4. Default template parameters

#include <iostream>
#include <string>
using namespace std;

// Generic Stack class template with a type parameter and a size parameter
// MaxSize has a default value of 100 if not specified
template<typename T, int MaxSize = 100>
class Stack {
private:
    T items[MaxSize];    // Array to store items of type T
    int top;            // Index of top element
    
public:
    // Constructor initializes empty stack
    Stack() : top(-1) {}
    
    // Push item onto stack if not full
    bool push(const T& item) {
        if (top >= MaxSize - 1) return false;  // Stack is full
        items[++top] = item;                   // Increment top and add item
        return true;
    }
    
    // Pop item from stack if not empty
    bool pop(T& item) {
        if (top < 0) return false;     // Stack is empty
        item = items[top--];           // Get item and decrement top
        return true;
    }
    
    // Peek at top item without removing it
    bool peek(T& item) const {
        if (top < 0) return false;     // Stack is empty
        item = items[top];             // Get top item
        return true;
    }
    
    // Check if stack is empty
    bool isEmpty() const {
        return top < 0;
    }
    
    // Check if stack is full
    bool isFull() const {
        return top >= MaxSize - 1;
    }
};

// Pair class template with two type parameters
// Demonstrates using multiple type parameters in a template
template<typename T, typename U>
class Pair {
private:
    T first;     // First value of type T
    U second;    // Second value of type U
    
public:
    // Constructor takes initial values for both members
    Pair(const T& f, const U& s) : first(f), second(s) {}
    
    // Setter methods
    void setFirst(const T& f) { first = f; }
    void setSecond(const U& s) { second = s; }
    
    // Getter methods
    T getFirst() const { return first; }
    U getSecond() const { return second; }
    
    // Display method to print the pair
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
