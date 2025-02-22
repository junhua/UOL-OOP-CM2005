[
    {
        category: 'Tutorial',
        sections: [
            {
                title: 'Module 1: Introduction to Programming and C++',
                items: [
                    { title: 'Part 01: Welcome to C++ and Object-Oriented Programming' },
                    { title: 'Part 02: Basic C++ Program Structure' },
                    { title: 'Part 03: Variables and Data Types' },
                    { title: 'Part 04: Input and output (cin, cout)' },
                    { title: 'Part 05: Basic operators (arithmetic, assignment, comparison, logical)' },
                    { title: 'Part 06: Comments and code readability' }
                ]
            },
            {
                title: 'Module 2: Control Flow',
                items: [
                    { title: 'Part 01: Conditional statements (if, else if, else)' },
                    { title: 'Part 02: Switch statements' },
                    { title: 'Part 03: Loops (for, while, do-while)' },
                    { title: 'Part 04: Break and continue statements' },
                    { title: 'Part 05: Simple program examples using control flow' }
                ]
            },
            {
                title: 'Module 3: Functions',
                items: [
                    { title: 'Part 01: What are functions?' },
                    { title: 'Part 02: Function declaration and definition' },
                    { title: 'Part 03: Function parameters and return values' },
                    { title: 'Part 04: Call by value and call by reference' },
                    { title: 'Part 05: Function overloading' },
                    { title: 'Part 06: Scope of variables (local and global)' },
                    { title: 'Part 07: Introduction to recursion (basic examples)' }
                ]
            },
            {
                title: 'Module 4: Collections and Strings',
                items: [
                    { title: 'Part 01: Vector, Set and Map' },
                    { title: 'Part 02: Accessing array elements' },
                    { title: 'Part 03: Strings (C-style strings and std::string)' },
                    { title: 'Part 04: Common string operations' }
                ]
            },
            {
                title: 'Module 5: Classes and Objects',
                items: [
                    { title: 'Part 01: Defining classes (attributes/members and methods/functions)' },
                    { title: 'Part 02: Constructors and destructors' },
                    { title: 'Part 03: Creating and using objects' }
                ]
            },
            {
                title: 'Module 6: Core OOP Concepts - Encapsulation',
                items: [
                    { title: 'Part 01: Data hiding and abstraction' },
                    { title: 'Part 02: Access specifiers (public, private, protected)' },
                    { title: 'Part 03: Getter and setter methods' }
                ]
            },
            {
                title: 'Module 7: Core OOP Concepts - Inheritance',
                items: [
                    { title: 'Part 01: Base classes and derived classes' },
                    { title: 'Part 02: "is-a" relationship' },
                    { title: 'Part 03: Overriding methods' },
                    { title: 'Part 04: Types of inheritance' }
                ]
            },
            {
                title: 'Module 8: Core OOP Concepts - Polymorphism',
                items: [
                    { title: 'Part 01: Function overriding (runtime polymorphism)' },
                    { title: 'Part 02: Virtual functions' },
                    { title: 'Part 03: Abstract classes and pure virtual functions' },
                    { title: 'Part 04: "has-a" relationship vs "is-a" relationship' }
                ]
            },
            {
                title: 'Module 9: Pointers and Dynamic Memory',
                items: [
                    { title: 'Part 01: Introduction to pointers' },
                    { title: 'Part 02: Pointer arithmetic' },
                    { title: 'Part 03: Dynamic memory allocation (new and delete)' },
                    { title: 'Part 04: Memory leaks and how to avoid them' },
                    { title: 'Part 05: Pointers and arrays' },
                    { title: 'Part 06: Pointers to objects' },
                    { title: 'Part 07: Function pointers' }
                ]
            }
        ]
    },
    {
        category: 'Lab',
        sections: [
            {
                title: 'Topic 1: Setting Up Merkelerex',
                items: [
                    { title: 'Part 01: Setup the console user interface' },
                    { title: 'Part 02: Setup the functions' },
                ]
            },
            {
                title: 'Topic 2: Modelling the Data Using Classes and Variables',
                items: [
                    { title: 'Part 01: OrderBookEntry class: representing a data entry' }, // Create .h and .cpp files, test in main
                    { title: 'Part 02: Creating a vector of entries' },
                    { title: 'Part 03: MerkelMain class: representing the app`s features' },
                    { title: 'Part 04: Loading the data into the app' }
                ]
            },
            {
                title: 'Topic 3: Algorithms, File I/O and Exceptions Handling',
                items: [
                    { title: 'Part 01: Implementing the Tokenise algorithm' },
                    { title: 'Part 02: Loading and processing the csv file content' },
                    { title: 'Part 03: Handling exceptions' }
                ]
            },
            {
                title: 'Topic 4: More Classes and Algorithms',
                items: [
                    { title: 'Part 01: Creating the OrderBook class' },
                    { title: 'Part 02: Working with time' },
                    { title: 'Part 03: Allowing user to place orders' },
                    { title: 'Part 04: Implementing the matching algorithm' }
                ]
            },
            {
                title: 'Topic 5: Object Interactions',
                items: [
                    { title: 'Part 01: Creating the Wallet class' },
                    { title: 'Part 02: Checking if the order can be fulfilled' },
                    { title: 'Part 03: Recording the trades' }
                ]
            }
        ]
    },
    {
        category: 'Project: Weather Prediction App',
        sections: [
            {
                title: 'Task 1: Compute candlestick data',
                items: [
                    { title: 'Part 01: Create CSVReader class to read weather data' },
                    { title: 'Part 02: Implement WeatherRecord struct/class to store temperature records' },
                    { title: 'Part 03: Create Candlestick class with OHLC attributes' },
                    { title: 'Part 04: Write algorithm to compute candlesticks from hourly data' },
                    { title: 'Part 05: Implement error handling for data processing' }
                ]
            },
            {
                title: 'Task 2: Create a text-based plot of the candlestick data',
                items: [
                    { title: 'Part 01: Design TextPlot class for ASCII visualization' },
                    { title: 'Part 02: Implement temperature scaling algorithm' },
                    { title: 'Part 03: Create vertical axis labels for temperature' },
                    { title: 'Part 04: Draw candlestick bodies using ASCII characters' },
                    { title: 'Part 05: Add time labels on horizontal axis' }
                ]
            },
            {
                title: 'Task 3: Filter Data and Plotting using text',
                items: [
                    { title: 'Part 01: Implement date range filtering functionality' },
                    { title: 'Part 02: Create DataFilter class for processing data subsets' },
                    { title: 'Part 03: Add user input handling for date ranges' },
                    { title: 'Part 04: Integrate filtering with plotting system' },
                    { title: 'Part 05: Handle edge cases and invalid date inputs' }
                ]
            },
            {
                title: 'Task 4: Predicting Data and Plotting',
                items: [
                    { title: 'Part 01: Develop simple moving average prediction model' },
                    { title: 'Part 02: Implement WeatherPredictor class' },
                    { title: 'Part 03: Calculate prediction confidence intervals' },
                    { title: 'Part 04: Extend plotting system to show predictions' },
                    { title: 'Part 05: Add visual distinction between actual and predicted data' },
                    { title: 'Part 06: Implement evaluation metrics for predictions' }
                ]
            },
            {
                title: 'Tips To Avoiding Plagiarism',
                items: [
                    { title: 'Part 01: Understanding what constitutes plagiarism in code' },
                    { title: 'Part 02: Documenting your design decisions and thought process' },
                    { title: 'Part 03: Writing original comments and documentation' },
                    { title: 'Part 04: Customizing and personalizing generated code' },
                    { title: 'Part 05: Implementing unique class and variable names' },
                    { title: 'Part 06: Testing and debugging your own code' },
                    { title: 'Part 07: Creating original helper functions and utilities' }
                ]
            }
        ]
    }
]