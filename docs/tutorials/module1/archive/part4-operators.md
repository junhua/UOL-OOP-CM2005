---
layout: default
title: Part 4 - Operators
nav_order: 4
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part4-operators/
---

# Part 4: Operators

Think of operators as the basic tools in your programming toolbox. Just like how you use different tools for different tasks in real life (a hammer for nails, a screwdriver for screws), we use different operators in programming to perform various operations on our data.

## Arithmetic Operators

### Real-world Analogy
Think of arithmetic operators like basic calculator buttons. Each button performs a specific mathematical operation:
- Addition (+) is like combining items in your shopping cart
- Subtraction (-) is like calculating change from a purchase
- Multiplication (*) is like calculating the total cost of multiple identical items
- Division (/) is like splitting a bill among friends
- Modulus (%) is like checking how many items remain when packing them in boxes of a fixed size

### Basic Operations
```cpp
// Shopping cart example
int itemPrice = 10, quantity = 3;
int totalCost = itemPrice * quantity;    // Multiplication: Total for 3 items at $10 each
int moneyPaid = 50;
int change = moneyPaid - totalCost;      // Subtraction: Calculate change
int itemsPerBox = 4;
int remainingItems = quantity % itemsPerBox;  // Modulus: Items that don't fill a complete box
```

### Common Pitfalls
- Integer division truncates decimals: `5 / 2` gives `2`, not `2.5`
- Use floating-point numbers for precise division: `5.0 / 2.0` gives `2.5`
- Remember that modulus (%) works only with integers

## Assignment Operators

### Real-world Analogy
Think of assignment operators like updating a scoreboard:
- Basic assignment (=) is like setting an initial score
- Compound assignments (+=, -=, etc.) are like updating the score

### Simple Assignment
```cpp
// Score tracking example
int score = 0;              // Start with zero points
score += 10;                // Player earned 10 points (score = score + 10)
score -= 5;                 // Player lost 5 points (score = score - 5)
score *= 2;                 // Double points bonus! (score = score * 2)
```

## Comparison Operators

### Real-world Analogy
Think of comparison operators like comparing prices or ages:
- Equal to (==) is like checking if two prices match
- Not equal (!=) is like verifying if prices differ
- Greater than (>) is like finding items above a price threshold

### Common Comparisons
```cpp
// Price comparison example
double oldPrice = 99.99;
double newPrice = 79.99;
bool isDiscounted = (newPrice < oldPrice);   // Check if price decreased
bool isPremium = (newPrice >= 100.0);        // Check if it's a premium price
bool isUnchanged = (newPrice == oldPrice);   // Check if price stayed the same
```

### Common Mistakes
- Using = (assignment) instead of == (comparison)
- Comparing floating-point numbers directly for equality

## Logical Operators

### Real-world Analogy
Think of logical operators like making decisions:
- AND ( && ) is like checking multiple conditions for a discount (must be a member AND spend over $100)
- OR ( \|\| ) is like qualifying for a service (must be a student OR senior citizen)
- NOT ( ! ) is like checking if something is unavailable

### Boolean Logic
```cpp
// Online shopping example
bool isMember = true;
bool spentOver100 = false;
bool isStudent = true;

// Check discount eligibility
bool getsDiscount = isMember && spentOver100;  // Must satisfy BOTH conditions
bool qualifiesForFreeShipping = isStudent || spentOver100;  // Must satisfy EITHER condition
bool isOutOfStock = !true;  // Opposite of in stock
```

## Operator Precedence

### Real-world Analogy
Think of operator precedence like the order of operations in math (PEMDAS):
- Parentheses first
- Then multiplication/division
- Then addition/subtraction

### Order of Operations
```cpp
// Price calculation example
int basePrice = 100;
int discount = 20;
int tax = 8;

// Different results based on order:
int total1 = basePrice - discount * tax;     // Applies tax to discount first
int total2 = (basePrice - discount) * tax;   // Applies discount first, then tax
```

## Practice Exercises

1. Shopping Cart Calculator
   - Calculate total cost with tax and discounts
   - Handle multiple items with different quantities
   - Apply percentage-based discounts

2. Grade Calculator
   - Calculate final grade from multiple assignments
   - Apply different weights to different components
   - Determine pass/fail status based on thresholds

3. Temperature Converter
   - Convert between Celsius and Fahrenheit
   - Handle negative temperatures
   - Validate input ranges

4. Game Score Tracker
   - Track points earned/lost
   - Apply multipliers for bonus rounds
   - Check high score conditions

### Practical Tips
- Test your calculations with simple numbers first
- Use parentheses when in doubt about precedence
- Comment your code to explain the logic
- Consider edge cases (negative numbers, zero, large values)

## Next Steps
Continue to [Part 5: Basic Programs]({{ site.baseurl }}/tutorials/module1/part5-basic-programs) to learn how to put these concepts together in complete programs.
