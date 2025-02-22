// This tutorial demonstrates:
// 1. STL Container Adaptors
// 2. Stack (LIFO)
// 3. Queue (FIFO)
// 4. Priority Queue

#include <iostream>
#include <string>
#include <stack>    // For stack container adaptor
#include <queue>    // For queue and priority_queue adaptors
#include <vector>   // For custom container base

// Task structure for demonstrating container adaptors
struct Task {
    int id;                // Unique identifier
    std::string description;  // Task description
    int priority;          // Priority level (lower number = higher priority)
    
    // Constructor for easy object creation
    Task(int i, std::string desc, int prio) 
        : id(i), description(desc), priority(prio) {}
    
    // Comparison operator for priority queue
    // Note: priority_queue puts largest elements first
    // So we reverse comparison to get highest priority (lowest number) first
    bool operator<(const Task& other) const {
        return priority > other.priority;
    }
};

// Helper function to print task details
void printTask(const Task& task) {
    std::cout << "Task " << task.id 
              << " (Priority: " << task.priority 
              << "): " << task.description << std::endl;
}

int main() {
    // Stack demonstration (LIFO - Last In First Out)
    // Properties:
    // - Elements are added/removed from one end only
    // - Only top element is accessible
    // - Useful for tracking history or undo operations
    std::cout << "Stack Demonstration:" << std::endl;
    std::stack<Task> taskStack;
    
    // Push adds element to top of stack
    taskStack.push(Task(1, "Review code", 2));
    taskStack.push(Task(2, "Write documentation", 3));
    taskStack.push(Task(3, "Fix bug", 1));
    
    std::cout << "\nProcessing stack (LIFO order):" << std::endl;
    while(!taskStack.empty()) {
        const Task& currentTask = taskStack.top();  // View top element
        printTask(currentTask);
        taskStack.pop();  // Remove top element
    }
    
    // Queue demonstration (FIFO - First In First Out)
    // Properties:
    // - Elements are added at back, removed from front
    // - Only front element is accessible
    // - Useful for processing tasks in order they arrive
    std::cout << "\nQueue Demonstration:" << std::endl;
    std::queue<Task> taskQueue;
    
    // Push adds element to back of queue
    taskQueue.push(Task(4, "Send email", 2));
    taskQueue.push(Task(5, "Attend meeting", 1));
    taskQueue.push(Task(6, "Update status", 3));
    
    std::cout << "\nProcessing queue (FIFO order):" << std::endl;
    while(!taskQueue.empty()) {
        const Task& currentTask = taskQueue.front();  // View front element
        printTask(currentTask);
        taskQueue.pop();  // Remove front element
    }
    
    // Priority Queue demonstration
    // Properties:
    // - Elements are sorted automatically
    // - Highest priority element always at top
    // - Useful for task scheduling
    std::cout << "\nPriority Queue Demonstration:" << std::endl;
    std::priority_queue<Task> taskPriorityQueue;
    
    // Push automatically sorts elements
    taskPriorityQueue.push(Task(7, "Normal task", 2));
    taskPriorityQueue.push(Task(8, "Critical bug", 1));
    taskPriorityQueue.push(Task(9, "Low priority task", 3));
    taskPriorityQueue.push(Task(10, "Another critical task", 1));
    
    std::cout << "\nProcessing priority queue (by priority):" << std::endl;
    while(!taskPriorityQueue.empty()) {
        const Task& currentTask = taskPriorityQueue.top();  // View highest priority
        printTask(currentTask);
        taskPriorityQueue.pop();  // Remove highest priority
    }
    
    // Advanced usage demonstration
    
    // Stack with custom underlying container
    // Default container is deque, but we can use vector
    std::stack<Task, std::vector<Task>> vectorStack;
    vectorStack.push(Task(11, "Task in vector-based stack", 1));
    
    std::cout << "\nVector-based stack processing:" << std::endl;
    while(!vectorStack.empty()) {
        printTask(vectorStack.top());
        vectorStack.pop();
    }
    
    // Priority queue with custom comparison
    // Lambda function for different priority ordering
    auto compare = [](const Task& a, const Task& b) {
        // Direct comparison: smaller number = higher priority
        return a.priority < b.priority;
    };
    
    // Priority queue with custom comparison and vector container
    std::priority_queue<
        Task,                     // Element type
        std::vector<Task>,        // Container type
        decltype(compare)         // Comparison type
    > customPriorityQueue(compare);
    
    customPriorityQueue.push(Task(12, "High priority", 1));
    customPriorityQueue.push(Task(13, "Medium priority", 2));
    customPriorityQueue.push(Task(14, "Low priority", 3));
    
    std::cout << "\nCustom priority queue processing:" << std::endl;
    while(!customPriorityQueue.empty()) {
        printTask(customPriorityQueue.top());
        customPriorityQueue.pop();
    }
    
    // Container adaptor selection guidelines:
    
    // Use stack when:
    // - You need LIFO (Last In First Out) behavior
    // - You only need access to most recently added element
    // - You need to track history or implement undo functionality
    // Example: Browser back button history
    
    // Use queue when:
    // - You need FIFO (First In First Out) behavior
    // - Elements must be processed in order they were added
    // - You need to manage requests or tasks sequentially
    // Example: Print job queue
    
    // Use priority_queue when:
    // - Elements have different priorities
    // - Highest priority element should always be processed first
    // - You need automatic sorting of elements
    // Example: Task scheduler, event system
    
    return 0;
}
