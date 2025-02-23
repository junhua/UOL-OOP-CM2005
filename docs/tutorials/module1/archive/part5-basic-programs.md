---
layout: default
title: Part 5 - Basic Programs
nav_order: 5
parent: Module 1 - Introduction to Programming and C++
grand_parent: Tutorials
permalink: /tutorials/module1/part5-basic-programs/
---

# Part 5: Basic Programs

Think of a program like a recipe - it's a set of instructions that tells the computer exactly what to do, step by step. Just as a recipe has ingredients (variables), instructions (statements), and produces a final dish (output), a program combines the concepts we've learned to create something useful.

## Program Structure

### Program Flow Visualization
```mermaid
flowchart TD
    Start([Start]) --> Headers[Include Headers]
    Headers --> MainFunc[Define main Function]
    MainFunc --> DeclareVars[Declare Variables]
    DeclareVars --> ProcessInput[Process Input]
    ProcessInput --> ValidInput{Valid Input?}
    ValidInput -->|No| ShowError[Show Error Message]
    ShowError --> ProcessInput
    ValidInput -->|Yes| ProcessData[Process Data]
    ProcessData --> DisplayOutput[Display Output]
    DisplayOutput --> More{More to do?}
    More -->|Yes| ProcessInput
    More -->|No| End([End])
```

### Real-world Analogy
Think of a program's structure like organizing a restaurant:
- Header files (#include) are like getting your ingredients and tools ready
- The main() function is like the kitchen where everything happens
- Variables are like your ingredients
- Statements are like the cooking steps
- Return value is like the final quality check

### Basic Structure
```cpp
// Get our tools ready
#include <iostream>
#include <iomanip>

// This is where our program starts
int main() {
    // Declare variables (prepare ingredients)
    // Write statements (follow recipe steps)
    // Return success/failure status
    return 0;
}
```

### Common Mistakes
- Forgetting to include necessary headers
- Missing return statement in main()
- Not initializing variables before use

## Functions

### Function Flow Visualization
```mermaid
flowchart TD
    Main[Main Program] --> Input[Input Function]
    Main --> Process[Processing Function]
    Main --> Output[Output Function]
    
    subgraph Input Operations
        Input --> Validate[Validate Input]
        Validate -->|Invalid| ShowError[Show Error]
        ShowError --> Input
        Validate -->|Valid| ReturnInput[Return Value]
    end
    
    subgraph Processing
        Process --> Calculate[Calculate Result]
        Calculate --> ValidateResult[Validate Result]
        ValidateResult --> ReturnResult[Return Result]
    end
    
    subgraph Output Operations
        Output --> Format[Format Data]
        Format --> Display[Display Result]
    end
```

### Real-world Analogy
Think of functions like different stations in a kitchen:
- Each station has a specific task (function)
- They take ingredients (parameters)
- They produce a result (return value)
- They can work independently (modular)

### Function Example
```cpp
// Calculate total cost including tax
double calculateTotal(double price, int quantity, double taxRate) {
    double subtotal = price * quantity;
    double tax = subtotal * taxRate;
    return subtotal + tax;
}

// Format currency for display
std::string formatCurrency(double amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << "$" << amount;
    return ss.str();
}

int main() {
    double itemPrice = 9.99;
    int quantity = 3;
    double taxRate = 0.08;  // 8% tax
    
    double total = calculateTotal(itemPrice, quantity, taxRate);
    std::cout << "Total cost: " << formatCurrency(total) << "\n";
    
    return 0;
}
```

## Error Handling

### Error Handling Flow
```mermaid
flowchart TD
    Start([Start]) --> GetInput[Get User Input]
    GetInput --> ValidFormat{Valid Format?}
    ValidFormat -->|No| ShowFormatError[Show Format Error]
    ShowFormatError --> ClearInput[Clear Input Buffer]
    ClearInput --> GetInput
    ValidFormat -->|Yes| ValidRange{Valid Range?}
    ValidRange -->|No| ShowRangeError[Show Range Error]
    ShowRangeError --> GetInput
    ValidRange -->|Yes| Process[Process Input]
    Process --> End([End])
```

### Real-world Analogy
Think of error handling like dealing with problems in a restaurant:
- Input validation is like checking if an order is valid
- Error messages are like explaining problems to customers
- Recovery steps are like fixing mistakes in orders

### Input Validation Example
```cpp
#include <iostream>
#include <limits>

int getValidQuantity() {
    int quantity;
    bool validInput = false;
    
    do {
        std::cout << "Enter quantity (1-100): ";
        
        if (std::cin >> quantity) {
            if (quantity >= 1 && quantity <= 100) {
                validInput = true;
            } else {
                std::cout << "Error: Quantity must be between 1 and 100.\n";
            }
        } else {
            std::cout << "Error: Please enter a valid number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!validInput);
    
    return quantity;
}
```

## Practice Exercises

### Restaurant Order System Flow
```mermaid
flowchart TD
    Start([Start]) --> DisplayMenu[Display Menu]
    DisplayMenu --> GetChoice[Get Item Choice]
    GetChoice --> ValidChoice{Valid Choice?}
    ValidChoice -->|No| ShowError1[Show Error]
    ShowError1 --> GetChoice
    ValidChoice -->|Yes| GetQuantity[Get Quantity]
    GetQuantity --> ValidQuantity{Valid Quantity?}
    ValidQuantity -->|No| ShowError2[Show Error]
    ShowError2 --> GetQuantity
    ValidQuantity -->|Yes| UpdateOrder[Update Order]
    UpdateOrder --> More{More Items?}
    More -->|Yes| DisplayMenu
    More -->|No| Calculate[Calculate Total]
    Calculate --> Display[Display Receipt]
    Display --> End([End])
```

### Bank Account Manager Flow
```mermaid
flowchart TD
    Start([Start]) --> ShowBalance[Show Balance]
    ShowBalance --> DisplayMenu[Display Menu]
    DisplayMenu --> GetChoice[Get Operation Choice]
    GetChoice --> Choice{Choice?}
    Choice -->|Deposit| GetAmount1[Get Amount]
    Choice -->|Withdraw| GetAmount2[Get Amount]
    Choice -->|History| ShowHistory[Show History]
    Choice -->|Exit| End([End])
    GetAmount1 --> ValidAmount1{Valid Amount?}
    GetAmount2 --> ValidAmount2{Valid Amount?}
    ValidAmount1 -->|No| ShowError1[Show Error]
    ValidAmount2 -->|No| ShowError2[Show Error]
    ShowError1 --> GetAmount1
    ShowError2 --> GetAmount2
    ValidAmount1 -->|Yes| UpdateBalance1[Update Balance]
    ValidAmount2 -->|Yes| UpdateBalance2[Update Balance]
    UpdateBalance1 --> ShowBalance
    UpdateBalance2 --> ShowBalance
    ShowHistory --> ShowBalance
```

### Temperature Monitoring Flow
```mermaid
flowchart TD
    Start([Start]) --> InitSystem[Initialize System]
    InitSystem --> GetReading[Get Temperature Reading]
    GetReading --> ValidReading{Valid Reading?}
    ValidReading -->|No| ShowError[Show Error]
    ShowError --> GetReading
    ValidReading -->|Yes| CheckLimits{Check Limits}
    CheckLimits -->|High| HighAlert[Trigger High Alert]
    CheckLimits -->|Low| LowAlert[Trigger Low Alert]
    CheckLimits -->|Normal| StoreData[Store Reading]
    HighAlert --> StoreData
    LowAlert --> StoreData
    StoreData --> More{More Readings?}
    More -->|Yes| GetReading
    More -->|No| Calculate[Calculate Statistics]
    Calculate --> Display[Display Report]
    Display --> End([End])
```

### Grade Calculator Flow
```mermaid
flowchart TD
    Start([Start]) --> GetGrades[Get Assignment Grades]
    GetGrades --> ValidGrade{Valid Grade?}
    ValidGrade -->|No| ShowError[Show Error]
    ShowError --> GetGrades
    ValidGrade -->|Yes| More{More Grades?}
    More -->|Yes| GetGrades
    More -->|No| Calculate[Calculate Weighted Average]
    Calculate --> DetermineGrade[Determine Letter Grade]
    DetermineGrade --> GenerateReport[Generate Grade Report]
    GenerateReport --> End([End])
```

1. Restaurant Order System
   - Take customer orders with validation
   - Calculate total with tax and discounts
   - Display formatted receipt
   - Handle multiple orders

2. Bank Account Manager
   - Check balance
   - Make deposits and withdrawals
   - Validate transactions
   - Display transaction history

3. Temperature Monitoring System
   - Record temperatures over time
   - Calculate average, high, and low
   - Alert for extreme temperatures
   - Display temperature trends

4. Student Grade Calculator
   - Input multiple grades
   - Calculate weighted averages
   - Generate grade reports
   - Validate input grades

### Tips for Success
- Plan your program structure before coding
- Test with different input values
- Handle invalid input gracefully
- Use functions to organize code
- Add helpful user prompts
- Format output for readability

## Next Steps
Move on to [Part 6: Problem Solving]({{ site.baseurl }}/tutorials/module1/part6-problem-solving) to learn how to approach and solve programming problems systematically.
