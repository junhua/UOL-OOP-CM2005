---
layout: default
title: Part 2 - Virtual Functions
nav_order: 2
parent: Module 8 - Core OOP Concepts - Polymorphism
grand_parent: Tutorials
permalink: /tutorials/module8/part2-virtual/
---

# Part 2: Virtual Functions

## Overview
Virtual functions are a key mechanism in C++ that enables runtime polymorphism. They allow derived classes to override base class methods and ensure that the correct method is called based on the actual object type.

## Virtual Function Basics

### Virtual Keyword
```cpp
class Base {
public:
    virtual void method() {
        cout << "Base method" << endl;
    }
    
    // Pure virtual method (abstract)
    virtual void pureMethod() = 0;
};

class Derived : public Base {
public:
    void method() override {  // override keyword is optional but recommended
        cout << "Derived method" << endl;
    }
    
    void pureMethod() override {
        cout << "Implemented pure virtual method" << endl;
    }
};
```

### Virtual Destructors
```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;  // Calls both destructors correctly
}
```

### Late Binding
```cpp
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

void playSound(Animal* animal) {
    animal->makeSound();  // Calls correct version at runtime
}
```

## Practice Exercise

Create a game character system demonstrating virtual functions:
1. Base character class with virtual methods
2. Different character types
3. Common and specific behaviors
4. Runtime method selection

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base character class
class Character {
protected:
    string name;
    int health;
    int power;
    
public:
    Character(string n, int h, int p)
        : name(n), health(h), power(p) {
        cout << "Creating character: " << name << endl;
    }
    
    virtual ~Character() {
        cout << "Destroying character: " << name << endl;
    }
    
    // Virtual methods with default implementation
    virtual void attack() const {
        cout << name << " performs a basic attack" << endl;
    }
    
    virtual void defend() const {
        cout << name << " takes a defensive stance" << endl;
    }
    
    virtual void specialMove() const = 0;  // Pure virtual
    
    virtual void displayStats() const {
        cout << "\nCharacter Stats:" << endl;
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Power: " << power << endl;
    }
    
    // Non-virtual methods
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getPower() const { return power; }
};

class Warrior : public Character {
private:
    string weaponType;
    
public:
    Warrior(string name, string weapon)
        : Character(name, 100, 80), weaponType(weapon) {
        cout << "Equipping warrior with " << weaponType << endl;
    }
    
    void attack() const override {
        cout << name << " swings " << weaponType << " with force!" << endl;
    }
    
    void defend() const override {
        cout << name << " raises shield and takes defensive stance" << endl;
    }
    
    void specialMove() const override {
        cout << name << " performs WHIRLWIND ATTACK with " << weaponType << "!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Weapon: " << weaponType << endl;
    }
};

class Mage : public Character {
private:
    vector<string> spells;
    
public:
    Mage(string name)
        : Character(name, 70, 100) {
        spells = {"Fireball", "Ice Shard", "Lightning Bolt"};
        cout << "Preparing mage spellbook" << endl;
    }
    
    void attack() const override {
        cout << name << " casts a magic missile!" << endl;
    }
    
    void defend() const override {
        cout << name << " creates a magical barrier" << endl;
    }
    
    void specialMove() const override {
        cout << name << " unleashes ARCANE BARRAGE!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Spells: ";
        for (const auto& spell : spells) {
            cout << spell << " ";
        }
        cout << endl;
    }
};

class Rogue : public Character {
private:
    int stealthLevel;
    
public:
    Rogue(string name, int stealth)
        : Character(name, 80, 90), stealthLevel(stealth) {
        cout << "Sharpening rogue daggers" << endl;
    }
    
    void attack() const override {
        cout << name << " strikes from the shadows!" << endl;
    }
    
    void defend() const override {
        cout << name << " dodges and rolls away" << endl;
    }
    
    void specialMove() const override {
        cout << name << " performs ASSASSINATE from stealth!" << endl;
    }
    
    void displayStats() const override {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
    }
};

class BattleSystem {
private:
    vector<Character*> characters;
    
public:
    ~BattleSystem() {
        for (Character* character : characters) {
            delete character;
        }
    }
    
    void addCharacter(Character* character) {
        characters.push_back(character);
        cout << "Added " << character->getName() << " to battle" << endl;
    }
    
    void simulateBattle() const {
        cout << "\nBattle Simulation:" << endl;
        cout << string(50, '=') << endl;
        
        for (const Character* character : characters) {
            cout << "\n" << character->getName() << "'s turn:" << endl;
            cout << string(20, '-') << endl;
            
            character->displayStats();
            character->attack();
            character->defend();
            character->specialMove();
        }
    }
};

int main() {
    try {
        BattleSystem battle;
        
        // Create different character types
        battle.addCharacter(new Warrior("Conan", "Greatsword"));
        battle.addCharacter(new Mage("Gandalf"));
        battle.addCharacter(new Rogue("Ezio", 95));
        
        // Simulate battle
        battle.simulateBattle();
        
        cout << "\nBattle completed successfully" << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Best Practices

### Virtual Function Design
1. Use virtual destructors
2. Override keyword
3. Consider pure virtual
4. Document behavior
5. Base class defaults

### Method Selection
1. Virtual for polymorphic
2. Non-virtual for invariant
3. Pure virtual for interface
4. Override carefully
5. Test thoroughly

### Performance Considerations
1. Virtual table overhead
2. Memory implications
3. Call indirection
4. Cache effects
5. Design tradeoffs

## Common Mistakes to Avoid
1. Missing virtual destructor
2. Forgetting override
3. Slicing objects
4. Breaking LSP
5. Virtual in constructors

## Next Steps
- Try the practice exercise
- Experiment with virtual functions
- Move on to [Part 3: Abstract Classes]({{ site.baseurl }}/tutorials/module8/part3-abstract)
