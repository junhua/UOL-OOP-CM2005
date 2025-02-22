// This tutorial demonstrates:
// 1. STL Sequence Containers
// 2. Container Operations
// 3. Iterators
// 4. Algorithms

#include <iostream>
#include <vector>   // Dynamic array
#include <list>     // Doubly linked list
#include <deque>    // Double-ended queue
#include <algorithm>
#include <string>

// Task structure to demonstrate container usage
struct Task {
    int id;                // Unique identifier
    std::string description;  // Task description
    int priority;          // Task priority (lower number = higher priority)
    
    // Constructor initializes all members
    Task(int i, std::string desc, int prio) 
        : id(i), description(desc), priority(prio) {}
        
    // Comparison operator for sorting
    // Used by std::sort and list::sort
    bool operator<(const Task& other) const {
        return priority < other.priority;  // Sort by priority
    }
};

// Template function to print any container of tasks
// Shows how to write generic functions that work with any container
template<typename Container>
void printTasks(const std::string& label, const Container& tasks) {
    std::cout << "\n" << label << ":" << std::endl;
    // Range-based for loop works with any container
    for(const auto& task : tasks) {
        std::cout << "ID: " << task.id 
                 << ", Priority: " << task.priority
                 << ", Description: " << task.description << std::endl;
    }
}

int main() {
    // Vector demonstration
    // - Fast random access (O(1))
    // - Fast insertion/deletion at end (O(1) amortized)
    // - Contiguous memory storage
    std::vector<Task> taskVector;
    
    // Add tasks to vector using push_back
    taskVector.push_back(Task(1, "Complete report", 3));
    taskVector.push_back(Task(2, "Review code", 1));
    taskVector.push_back(Task(3, "Fix bugs", 2));
    
    printTasks("Vector Tasks", taskVector);
    
    // Sort vector using std::sort (requires random access iterators)
    std::sort(taskVector.begin(), taskVector.end());
    printTasks("Sorted Vector Tasks", taskVector);
    
    // List demonstration
    // - Fast insertion/deletion anywhere (O(1))
    // - Bidirectional iteration
    // - Non-contiguous storage
    std::list<Task> taskList;
    
    // List supports efficient insertion at both ends
    taskList.push_front(Task(4, "Update documentation", 2));
    taskList.push_back(Task(5, "Write tests", 1));
    taskList.push_back(Task(6, "Deploy application", 3));
    
    printTasks("List Tasks", taskList);
    
    // List provides its own sort method
    // More efficient than std::sort for lists
    taskList.sort();
    printTasks("Sorted List Tasks", taskList);
    
    // Deque (double-ended queue) demonstration
    // - Fast insertion/deletion at both ends (O(1))
    // - Fast random access (O(1))
    // - Non-contiguous storage
    std::deque<Task> taskDeque;
    
    // Deque supports efficient insertion at both ends
    taskDeque.push_front(Task(7, "Plan meeting", 1));
    taskDeque.push_back(Task(8, "Send emails", 2));
    taskDeque.push_front(Task(9, "Check notifications", 3));
    
    printTasks("Deque Tasks", taskDeque);
    
    // Deque supports random access, so we can use std::sort
    std::sort(taskDeque.begin(), taskDeque.end());
    printTasks("Sorted Deque Tasks", taskDeque);
    
    // Demonstrate common container operations
    
    // Vector operations
    std::cout << "\nVector Operations:" << std::endl;
    std::cout << "Size: " << taskVector.size() << std::endl;
    std::cout << "First task: " << taskVector.front().description << std::endl;
    std::cout << "Last task: " << taskVector.back().description << std::endl;
    
    // Insert in middle of vector using iterator arithmetic
    auto vectorIt = taskVector.begin() + taskVector.size()/2;
    taskVector.insert(vectorIt, Task(10, "New vector task", 2));
    
    // List operations
    std::cout << "\nList Operations:" << std::endl;
    std::cout << "Size: " << taskList.size() << std::endl;
    std::cout << "First task: " << taskList.front().description << std::endl;
    std::cout << "Last task: " << taskList.back().description << std::endl;
    
    // Remove tasks with priority 2 using lambda predicate
    taskList.remove_if([](const Task& task) { return task.priority == 2; });
    
    // Deque operations
    std::cout << "\nDeque Operations:" << std::endl;
    std::cout << "Size: " << taskDeque.size() << std::endl;
    std::cout << "First task: " << taskDeque.front().description << std::endl;
    std::cout << "Last task: " << taskDeque.back().description << std::endl;
    
    // Random access in deque
    if(!taskDeque.empty()) {
        size_t middle = taskDeque.size() / 2;
        std::cout << "Middle task: " << taskDeque[middle].description << std::endl;
    }
    
    // Display final state of all containers
    printTasks("Final Vector Tasks", taskVector);
    printTasks("Final List Tasks", taskList);
    printTasks("Final Deque Tasks", taskDeque);
    
    // Container selection guidelines:
    // Use vector when:
    // - You need fast random access
    // - Most insertions/deletions are at the end
    // - You need contiguous memory storage
    
    // Use list when:
    // - You need frequent insertions/deletions anywhere in the container
    // - You don't need random access
    // - Memory locality is not important
    
    // Use deque when:
    // - You need fast insertions/deletions at both ends
    // - You need random access
    // - Contiguous memory storage is not required
    
    return 0;
}
