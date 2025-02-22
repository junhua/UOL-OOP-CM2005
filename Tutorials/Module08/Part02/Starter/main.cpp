// This tutorial demonstrates:
// 1. Virtual functions and their importance
// 2. How virtual functions enable runtime polymorphism
// 3. The virtual table (vtable) concept
// 4. The difference between virtual and non-virtual function calls

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class for animals
class Animal {
protected:
    string name;
    
public:
    Animal(const string& n) : name(n) {}
    
        // Non-virtual identify() function
    void identify() {
        cout << "I am an animal named " << name << endl;
    }
    
    // Virtual makeSound() function
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
    
    // Virtual move() function
    virtual void move() {
        cout << "Moving somehow..." << endl;
    }
    
    // Virtual destructor
    virtual ~Animal() {
        cout << "Animal destructor called for " << name << endl;
    }
};

// Dog class that inherits from Animal
class Dog : public Animal {
public:
    // Constructor that takes a name and passes it to Animal constructor
    Dog(const string& n) : Animal(n) {}
    
    // Override identify() (non-virtual)
    void identify() {
        cout << "I am a dog named " << name << endl;
    }
    
    // Override makeSound() (virtual)
    void makeSound() override {
        cout << name << " says: Woof! Woof!" << endl;
    }
    
    // Override move() (virtual)
    void move() override {
        cout << name << " runs on four legs" << endl;
    }
    
    // Virtual destructor
    virtual ~Dog() {
        cout << "Dog destructor called for " << name << endl;
    }
};

// Bird class that inherits from Animal
class Bird : public Animal {
public:
    // Constructor that takes a name and passes it to Animal constructor
    Bird(const string& n) : Animal(n) {}
    
    // Override identify() (non-virtual)
    void identify() {
        cout << "I am a bird named " << name << endl;
    }
    
    // Override makeSound() (virtual)
    void makeSound() override {
        cout << name << " says: Tweet! Tweet!" << endl;
    }
    
    // Override move() (virtual)
    void move() override {
        cout << name << " flies through the air" << endl;
    }
    
    // Virtual destructor
    virtual ~Bird() {
        cout << "Bird destructor called for " << name << endl;
    }
};

int main() {
    // Create instances of Dog and Bird with names
    Dog dog("Buddy");
    Bird bird("Tweety");

    // Demonstrate direct object calls
    cout << "Direct object calls:" << endl;
    dog.identify();
    bird.identify();
    cout << endl;

    // Demonstrate virtual function behavior with base class pointers
    cout << "Using base class pointers:" << endl;
    Animal* animalPtr1 = &dog;
    Animal* animalPtr2 = &bird;
    animalPtr1->identify(); // Calls Animal's identify()
    animalPtr1->makeSound(); // Calls Dog's makeSound()
    animalPtr1->move();      // Calls Dog's move()

    animalPtr2->identify(); // Calls Animal's identify()
    animalPtr2->makeSound(); // Calls Bird's makeSound()
    animalPtr2->move();      // Calls Bird's move()
    cout << endl;

    // Demonstrate virtual function behavior with base class references
    cout << "Using base class references:" << endl;
    Animal& animalRef1 = dog;
    Animal& animalRef2 = bird;
    animalRef1.identify(); // Calls Animal's identify()
    animalRef1.makeSound(); // Calls Dog's makeSound()
    animalRef1.move();      // Calls Dog's move()

    animalRef2.identify(); // Calls Animal's identify()
    animalRef2.makeSound(); // Calls Bird's makeSound()
    animalRef2.move();      // Calls Bird's move()
    cout << endl;

    // Demonstrate proper cleanup with virtual destructors
    cout << "Demonstrating virtual destructors:" << endl;
    Animal* dogPtr = new Dog("Max");
    delete dogPtr; // Calls Dog's destructor, then Animal's

    return 0;
}
