---
layout: default
title: Part 3 - Input/Output
---

# Part 3: Input/Output

Welcome to Part 3! Now we'll learn how to make our programs interactive by getting input from users and displaying output. Think of this as having a conversation with your computer!

## Understanding Input/Output

Imagine your program is like a helpful assistant:
- **Output** is how the assistant talks to you (displays information)
- **Input** is how you talk to the assistant (provide information)
- The conversation goes back and forth

## Console Output (Talking to the User)

### Basic Output with cout
`cout` (pronounced "see-out") is like the program's voice:

```cpp
#include <iostream>

int main() {
    std::cout << "Hello!";                  // Prints: Hello!
    std::cout << "How are you?";           // Prints: How are you?
    
    // Both on same line: Hello!How are you?
}
```

### Making Output More Readable

#### 1. Adding New Lines
Two ways to start a new line:
```cpp
// Method 1: Using endl
std::cout << "Line 1" << std::endl;
std::cout << "Line 2" << std::endl;

// Method 2: Using \n
std::cout << "Line 1\n";
std::cout << "Line 2\n";

// Both produce:
// Line 1
// Line 2
```

Think of:
- `endl` as pressing Enter + making sure everything is displayed
- `\n` as just pressing Enter (faster but doesn't flush output)

#### 2. Combining Text and Variables
```cpp
int age = 20;
std::cout << "I am " << age << " years old.\n";
// Prints: I am 20 years old.

double price = 19.99;
std::cout << "The price is $" << price << "\n";
// Prints: The price is $19.99
```

Like putting together pieces of a sentence!

### Making Numbers Look Nice

#### 1. Controlling Decimal Places
```cpp
#include <iostream>
#include <iomanip>  // For formatting tools

double price = 19.99999;

// Set fixed decimal format and precision
std::cout << std::fixed;                    
std::cout << std::setprecision(2);          
std::cout << "Price: $" << price << "\n";   
// Prints: Price: $20.00
```

Think of `setprecision` like setting rules for how many decimal places to show.

#### 2. Creating Neat Columns
```cpp
std::cout << std::setw(10) << "Name";
std::cout << std::setw(8) << "Age" << "\n";
std::cout << std::setw(10) << "John";
std::cout << std::setw(8) << "25" << "\n";

// Prints:
//      Name     Age
//      John      25
```

Like creating a table with evenly spaced columns!

## Console Input (Getting Information from the User)

### Basic Input with cin
`cin` (pronounced "see-in") is like the program's ears:

```cpp
int age;
std::cout << "How old are you? ";
std::cin >> age;
// Waits for user to type a number and press Enter
```

Think of `>>` as pointing into the variable where we want to store the input.

### Getting Different Types of Input

#### 1. Numbers
```cpp
int whole;
double decimal;

std::cout << "Enter a whole number: ";
std::cin >> whole;

std::cout << "Enter a decimal number: ";
std::cin >> decimal;
```

#### 2. Single Characters
```cpp
char answer;
std::cout << "Do you agree? (y/n): ";
std::cin >> answer;
```

#### 3. Text (Words and Lines)
```cpp
// For a single word:
std::string name;
std::cout << "Enter your name: ";
std::cin >> name;

// For a whole line of text:
std::string fullName;
std::cout << "Enter your full name: ";
std::cin.ignore();  // Clear any leftover Enter key
std::getline(std::cin, fullName);
```

### Making Input Safe

#### 1. Checking for Valid Input
```cpp
int number;
std::cout << "Enter a number: ";
while (!(std::cin >> number)) {
    std::cout << "That's not a number! Try again: ";
    std::cin.clear();  // Reset error flags
    std::cin.ignore(10000, '\n');  // Clear bad input
}
```

Like having a bouncer that only lets valid numbers in!

#### 2. Limiting Input Length
```cpp
char name[50];  // Space for 49 characters + null terminator
std::cout << "Enter name (max 49 chars): ";
std::cin.getline(name, 50);
```

### Common Input Problems and Solutions

#### 1. Input Buffer Issues
Problem: Mixing number input with line input
```cpp
int age;
std::string name;

std::cout << "Enter age: ";
std::cin >> age;

std::cout << "Enter name: ";
std::getline(std::cin, name);  // Might get skipped!
```

Solution: Clear the buffer
```cpp
int age;
std::string name;

std::cout << "Enter age: ";
std::cin >> age;
std::cin.ignore(10000, '\n');  // Clear the leftover Enter key

std::cout << "Enter name: ";
std::getline(std::cin, name);  // Now works correctly
```

#### 2. Invalid Input Recovery
```cpp
double price;
bool validInput = false;

while (!validInput) {
    std::cout << "Enter price: $";
    if (std::cin >> price && price >= 0) {
        validInput = true;
    } else {
        std::cout << "Invalid price!\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
```

## Practice Exercise

Create a program that:
1. Asks for a student's information:
   - Name (full name)
   - Age
   - Three test scores
2. Calculates their average score
3. Displays a formatted summary:
   - All information in neat columns
   - Average score with 2 decimal places
   - A "PASSED" message if average ≥ 60

[View Solution]({{ site.baseurl }}/tutorials/module1/part3/solution)

## Best Practices
1. Always prompt for input
   ```cpp
   std::cout << "Enter value: ";  // Good
   std::cin >> value;             // User knows what to do
   ```

2. Validate all input
   ```cpp
   if (age < 0 || age > 120) {
       std::cout << "Invalid age!\n";
   }
   ```

3. Format output for readability
   ```cpp
   std::cout << std::fixed << std::setprecision(2);
   std::cout << "Total: $" << total << "\n";
   ```

4. Clear input buffer when switching input types
   ```cpp
   std::cin >> number;
   std::cin.ignore(10000, '\n');
   std::getline(std::cin, text);
   ```

## Next Steps
1. Complete the practice exercise
2. Experiment with different input types
3. Try creating formatted tables
4. Move on to [Part 4: Operators]({{ site.baseurl }}/tutorials/module1/part4)

## Additional Resources
- [Input/Output Stream Reference]({{ site.baseurl }}/docs/reference/io-streams)
- [String Handling Guide]({{ site.baseurl }}/docs/guides/strings)
- [Input Validation Techniques]({{ site.baseurl }}/docs/guides/input-validation)

Remember: Good input/output makes your programs user-friendly. Take time to handle both correctly!
