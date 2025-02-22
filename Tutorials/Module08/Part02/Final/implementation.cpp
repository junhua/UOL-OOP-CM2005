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
    
    // Non-virtual function - will not participate in dynamic dispatch
    void identify() {
        cout << "I am an animal named " << name << endl;
    }
    
    // Virtual function - will participate in dynamic dispatch
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
    
    // Virtual function for movement
    virtual void move() {
        cout << "Moving somehow..." << endl;
    }
    
    // Virtual destructor - important when using polymorphism
    virtual ~Animal() {
        cout << "Animal destructor called for " << name << endl;
    }
};

// Derived class for dogs
class Dog : public Animal {
public:
    Dog(const string& n) : Animal(n) {}
    
    // Override identify (non-virtual function)
    void identify() {
        cout << "I am a dog named " << name << endl;
    }
    
    // Override makeSound (virtual function)
    virtual void makeSound() override {
        cout << name << " says: Woof! Woof!" << endl;
    }
    
    // Override move (virtual function)
    virtual void move() override {
        cout << name << " runs on four legs" << endl;
    }
    
    // Destructor
    virtual ~Dog() {
        cout << "Dog destructor called for " << name << endl;
    }
};

// Derived class for birds
class Bird : public Animal {
public:
    Bird(const string& n) : Animal(n) {}
    
    // Override identify (non-virtual function)
    void identify() {
        cout << "I am a bird named " << name << endl;
    }
    
    // Override makeSound (virtual function)
    virtual void makeSound() override {
        cout << name << " says: Tweet! Tweet!" << endl;
    }
    
    // Override move (virtual function)
    virtual void move() override {
        cout << name << " flies through the air" << endl;
    }
    
    // Destructor
    virtual ~Bird() {
        cout << "Bird destructor called for " << name << endl;
    }
};

int main() {
    // Create some animals
    Dog dog("Buddy");
    Bird bird("Tweety");
    
    cout << "Direct object calls:" << endl;
    cout << "Dog - ";
    dog.identify();  // Calls Dog's identify
    cout << "Bird - ";
    bird.identify();  // Calls Bird's identify
    cout << endl;
    
    // Demonstrate virtual function behavior with base class pointers
    cout << "Using base class pointers:" << endl;
    Animal* animals[] = {&dog, &bird};
    
    for(Animal* animal : animals) {
        animal->identify();   // Calls Animal's identify (non-virtual)
        animal->makeSound();  // Calls derived class makeSound (virtual)
        animal->move();       // Calls derived class move (virtual)
        cout << endl;
    }
    
    // Demonstrate virtual function behavior with base class references
    cout << "Using base class references:" << endl;
    Animal& dogRef = dog;
    Animal& birdRef = bird;
    
    dogRef.identify();   // Calls Animal's identify (non-virtual)
    dogRef.makeSound();  // Calls Dog's makeSound (virtual)
    dogRef.move();       // Calls Dog's move (virtual)
    cout << endl;
    
    birdRef.identify();   // Calls Animal's identify (non-virtual)
    birdRef.makeSound();  // Calls Bird's makeSound (virtual)
    birdRef.move();       // Calls Bird's move (virtual)
    cout << endl;
    
    // Demonstrate proper cleanup with virtual destructors
    cout << "Demonstrating virtual destructors:" << endl;
    Animal* ptr = new Dog("Max");
    delete ptr;  // Calls both Dog and Animal destructors
    
    return 0;
}
