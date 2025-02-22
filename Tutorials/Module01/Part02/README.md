# Module 1 - Part 2: Variables and Types

Welcome to Part 2! Here we'll learn about the different types of "containers" (variables) that C++ uses to store information, just like how we use different types of containers in real life!

## Understanding the Files

### data_types.cpp - Your Guide to C++ Data Types
Think of this program as a tour through C++'s storage system:
- Different boxes for whole numbers (int, short, long)
- Special containers for decimal numbers (float, double)
- Tiny slots for single characters (char)
- Simple switches for yes/no values (bool)

To run this program:
1. Open your terminal
2. Compile the program:
   ```bash
   g++ data_types.cpp -o data_types
   ```
3. Run it:
   ```bash
   # On Windows:
   data_types.exe
   
   # On macOS/Linux:
   ./data_types
   ```

### practice_solution.cpp - Shopping Cart Calculator
A real-world example showing how to:
- Store prices and quantities
- Calculate discounts and taxes
- Handle money calculations
- Format the output like a receipt

To run this program:
1. Compile it:
   ```bash
   g++ practice_solution.cpp -o practice
   ```
2. Run it:
   ```bash
   # On Windows:
   practice.exe
   
   # On macOS/Linux:
   ./practice
   ```

## Real-World Analogies

### Data Types are Like Containers
- `int` (integer): Like a box for counting whole things (apples, people)
- `double`: Like a measuring cup for precise amounts (price, weight)
- `char`: Like a single letter slot in a form
- `bool`: Like a light switch (on/off, yes/no)

### Variables are Like Labeled Boxes
```cpp
int age = 20;        // Box labeled "age" containing 20
double price = 9.99; // Box labeled "price" containing 9.99
char grade = 'A';    // Slot labeled "grade" containing 'A'
```

### Constants are Like Rules
```cpp
const double TAX_RATE = 0.07;  // Tax rate that never changes
const int MAX_SCORE = 100;     // Maximum possible score
```

## Common Mistakes and Solutions

### 1. Putting Decimals in Integer Boxes
```cpp
// Wrong: Trying to put 3.14 in an integer box
int pi = 3.14;  // Will only store 3!

// Right: Use a double for decimal numbers
double pi = 3.14;
```

### 2. Integer Division Surprises
```cpp
// Wrong: Integer division drops decimals
int result = 5 / 2;  // Gets 2, not 2.5

// Right: Use decimals for accurate division
double result = 5.0 / 2.0;  // Gets 2.5
```

### 3. Overflow Problems
```cpp
// Wrong: Number too big for the box
short small = 40000;  // short can't hold numbers this big!

// Right: Use appropriate size
int regular = 40000;  // int is big enough
```

## Practice Ideas

### 1. Modify the Shopping Cart
- Change prices and quantities
- Add more items
- Calculate different discounts
- Add a loyalty points system

### 2. Create Your Own Calculator
- Add temperature conversion
- Calculate areas and volumes
- Convert between different units
- Handle currency exchange

### 3. Experiment with Types
- Try different size numbers
- Mix integers and decimals
- Format output in different ways
- Test the limits of each type

## Step-by-Step Learning

1. Start with data_types.cpp:
   - Run it and observe the output
   - Change some values and see what happens
   - Try to predict the results

2. Move to practice_solution.cpp:
   - Understand each calculation
   - Modify the values
   - Add your own features

3. Try these challenges:
   - Create a grade calculator
   - Build a simple bank account
   - Make a temperature converter

## Getting Help

If you see errors like:
```
error: invalid conversion from 'double' to 'int'
```
This means you're trying to put a decimal number in an integer box!

Remember:
- Integers (int) are for whole numbers
- Doubles are for decimal numbers
- Use type conversion when needed
- Always initialize your variables

## Next Steps
1. Make sure you understand all the data types
2. Complete the practice exercises
3. Create your own programs using different types
4. Move on to Part 3 when ready

Remember: Just like you choose different containers in real life (boxes, bags, bottles), in programming we choose different data types based on what we need to store!
