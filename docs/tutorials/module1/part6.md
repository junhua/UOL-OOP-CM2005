---
layout: default
title: Part 6 - Problem Solving
---

# Part 6: Problem Solving

Welcome to Part 6! Now we'll learn how to solve programming problems systematically. Think of it like solving a puzzle - we need a strategy and the right approach!

## Understanding Problem Solving

### The Detective Analogy
Think of yourself as a detective:
- The problem is your case
- The requirements are your clues
- The solution is solving the case
- Testing is verifying your solution
- Debugging is following leads

## The Problem-Solving Process

### 1. Understanding the Problem
Like a detective gathering information:

```cpp
/*
Example Problem: Calculate student grades

What we know:
- Need student scores
- Need to calculate average
- Need to assign letter grades
- Need to show results

What we need to figure out:
- How to store scores
- How to handle invalid input
- How to format output
*/
```

### 2. Breaking Down the Problem
Like creating a case file:

```cpp
// Main problem: Student Grade Calculator
struct Student {
    string name;
    vector<int> scores;
    double average;
    char grade;
};

// Break into smaller tasks:
void getStudentInfo();     // Get name and scores
void calculateAverage();   // Find average score
void assignGrade();        // Determine letter grade
void displayResults();     // Show all information
```

### 3. Planning the Solution
Like creating an investigation plan:

```cpp
/*
Step 1: Get Student Information
- Ask for name
- Get scores (handle invalid input)
- Store in Student structure

Step 2: Calculate Average
- Add all scores
- Divide by number of scores
- Handle empty score list

Step 3: Assign Grade
- A: 90-100
- B: 80-89
- C: 70-79
- D: 60-69
- F: Below 60

Step 4: Display Results
- Show name
- Show all scores
- Show average
- Show grade
*/
```

## Testing Strategies

### 1. Start with Simple Cases
Like testing your basic theory:

```cpp
void testBasicCase() {
    vector<int> scores = {85, 90, 95};
    double average = calculateAverage(scores);
    assert(average == 90.0);  // Should pass
}
```

### 2. Test Edge Cases
Like checking unusual situations:

```cpp
void testEdgeCases() {
    // Empty score list
    vector<int> empty;
    assert(calculateAverage(empty) == 0.0);

    // Single score
    vector<int> single = {100};
    assert(calculateAverage(single) == 100.0);

    // All same scores
    vector<int> same = {70, 70, 70};
    assert(calculateAverage(same) == 70.0);
}
```

### 3. Test Error Cases
Like investigating what could go wrong:

```cpp
void testErrorCases() {
    // Invalid scores
    assert(!isValidScore(-10));
    assert(!isValidScore(110));

    // Invalid name
    assert(!isValidName(""));  // Empty name
    assert(!isValidName("A")); // Too short
}
```

## Debugging Techniques

### 1. Print Debugging
Like leaving breadcrumbs in your investigation:

```cpp
void calculateGrade(Student& student) {
    cout << "Calculating grade for: " << student.name << "\n";
    cout << "Scores: ";
    for (int score : student.scores) {
        cout << score << " ";
    }
    cout << "\n";
    
    student.average = calculateAverage(student.scores);
    cout << "Average: " << student.average << "\n";
    
    student.grade = assignGrade(student.average);
    cout << "Assigned grade: " << student.grade << "\n";
}
```

### 2. Using Assertions
Like checking your assumptions:

```cpp
void processScore(int score) {
    // Check our assumptions
    assert(score >= 0 && "Score cannot be negative");
    assert(score <= 100 && "Score cannot exceed 100");
    
    // Process the score
    totalScore += score;
    scoreCount++;
}
```

## Practice Exercise: Student Record System

Create a program that:
1. Manages student records:
   - Name, ID, and scores
   - Calculate average and grade
   - Show performance summary
2. Includes error handling:
   - Invalid scores
   - Duplicate IDs
   - Missing information
3. Provides a menu system:
   - Add new student
   - View student details
   - List all students
   - Update scores
   - Exit program

Example output:
```
=== Student Record System ===
1. Add New Student
2. View Student Details
3. List All Students
4. Update Scores
5. Exit

Choice: 1
Enter student name: John Doe
Enter student ID: 12345
Enter scores (enter -1 to finish):
Score 1: 85
Score 2: 90
Score 3: 95
Score 4: -1

Student added successfully!
Average: 90.00
Grade: A

Continue? (y/n):
```

[View Solution]({{ site.baseurl }}/tutorials/module1/part6/solution)

## Problem-Solving Tips

### 1. Start Simple
- Begin with a basic working solution
- Add features one at a time
- Test each addition thoroughly

### 2. Use Helper Functions
```cpp
// Break complex tasks into helper functions
bool isValidScore(int score) {
    return score >= 0 && score <= 100;
}

bool isValidName(const string& name) {
    return !name.empty() && name.length() >= 2;
}

bool isValidID(int id) {
    return id > 0 && !isDuplicate(id);
}
```

### 3. Handle Edge Cases
```cpp
double calculateAverage(const vector<int>& scores) {
    // Handle empty vector
    if (scores.empty()) {
        return 0.0;
    }
    
    // Calculate sum
    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    
    // Calculate average
    return static_cast<double>(sum) / scores.size();
}
```

### 4. Document Your Process
```cpp
/*
Problem: Student Grade Calculator
Author: [Your Name]
Date: [Current Date]

Steps:
1. Input Validation
   - Check score range (0-100)
   - Verify student ID format
   - Validate name (non-empty)

2. Calculations
   - Average = sum of scores / number of scores
   - Grade based on average score
   
3. Output Formatting
   - Display in neat columns
   - Show 2 decimal places for average
   - Include timestamp
*/
```

## Next Steps
1. Complete the practice exercise
2. Try solving it different ways
3. Add more features to your solution
4. Start working on lab exercises
5. Begin [Module 2: Control Flow]({{ site.baseurl }}/tutorials/module2)

## Additional Resources
- [Problem-Solving Strategies]({{ site.baseurl }}/docs/guides/problem-solving)
- [Debugging Techniques]({{ site.baseurl }}/docs/guides/debugging)
- [Testing Best Practices]({{ site.baseurl }}/docs/guides/testing)

Remember: Every programmer started by solving simple problems. Take your time, be systematic, and learn from each challenge!
