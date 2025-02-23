---
layout: default
title: Part 4 - Types of Inheritance
nav_order: 4
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part4-types/
---

# Part 4: Types of Inheritance

## Overview
C++ supports different types of inheritance that control how base class members are inherited in derived classes. Understanding these types helps in designing proper class hierarchies.

## Inheritance Types

### Public Inheritance
```cpp
class Base {
public:
    void publicMethod() { }
protected:
    void protectedMethod() { }
private:
    void privateMethod() { }
};

class Derived : public Base {  // Most common type
    // publicMethod remains public
    // protectedMethod remains protected
    // privateMethod is not accessible
};
```

### Protected Inheritance
```cpp
class Base {
public:
    void publicMethod() { }
protected:
    void protectedMethod() { }
private:
    void privateMethod() { }
};

class Derived : protected Base {
    // publicMethod becomes protected
    // protectedMethod remains protected
    // privateMethod is not accessible
};
```

### Private Inheritance
```cpp
class Base {
public:
    void publicMethod() { }
protected:
    void protectedMethod() { }
private:
    void privateMethod() { }
};

class Derived : private Base {
    // publicMethod becomes private
    // protectedMethod becomes private
    // privateMethod is not accessible
};
```

## Access Control Summary

### Access Table
| Base Member | public Inheritance | protected Inheritance | private Inheritance |
|-------------|-------------------|---------------------|-------------------|
| public      | public           | protected           | private          |
| protected   | protected        | protected           | private          |
| private     | not accessible   | not accessible      | not accessible   |

## Practice Exercise

Create a class hierarchy demonstrating different inheritance types:
1. Base class with different access levels
2. Derived classes with different inheritance types
3. Access level verification
4. Inheritance behavior demonstration

Solution:
```cpp
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    Base(string name) : name(name) {
        cout << "Creating Base: " << name << endl;
    }
    
    void publicMethod() {
        cout << name << ": Public method" << endl;
    }
    
protected:
    void protectedMethod() {
        cout << name << ": Protected method" << endl;
    }
    
    string getName() const { return name; }
    
private:
    string name;
    
    void privateMethod() {
        cout << name << ": Private method" << endl;
    }
};

class PublicDerived : public Base {
public:
    PublicDerived() : Base("PublicDerived") {
        cout << "Public inheritance example" << endl;
    }
    
    // Demonstrate access levels
    void testAccess() {
        publicMethod();      // OK: public inherited as public
        protectedMethod();   // OK: protected inherited as protected
        // privateMethod();  // Error: private not accessible
        
        cout << "Name from protected getter: " << getName() << endl;
    }
};

class ProtectedDerived : protected Base {
public:
    ProtectedDerived() : Base("ProtectedDerived") {
        cout << "Protected inheritance example" << endl;
    }
    
    // Provide controlled access to base methods
    void accessBaseMethod() {
        publicMethod();      // OK: public inherited as protected
        protectedMethod();   // OK: protected inherited as protected
        // privateMethod();  // Error: private not accessible
    }
};

class PrivateDerived : private Base {
public:
    PrivateDerived() : Base("PrivateDerived") {
        cout << "Private inheritance example" << endl;
    }
    
    // Selectively expose base functionality
    void accessBaseMethod() {
        publicMethod();      // OK: public inherited as private
        protectedMethod();   // OK: protected inherited as private
        // privateMethod();  // Error: private not accessible
    }
};

class FurtherDerived : public PublicDerived {
public:
    FurtherDerived() {
        cout << "Further derivation example" << endl;
        publicMethod();      // OK: still public
        protectedMethod();   // OK: still protected
    }
};

// Error: Cannot derive from PrivateDerived
// class AttemptPrivateDerived : public PrivateDerived {
//     // Base members are private in PrivateDerived
//     // Cannot access them here
// };

int main() {
    cout << "Testing inheritance types:" << endl;
    cout << string(50, '=') << endl;
    
    // Public inheritance
    cout << "\nPublic Inheritance:" << endl;
    cout << string(30, '-') << endl;
    PublicDerived pub;
    pub.publicMethod();    // OK: public inherited as public
    pub.testAccess();
    
    // Protected inheritance
    cout << "\nProtected Inheritance:" << endl;
    cout << string(30, '-') << endl;
    ProtectedDerived prot;
    // prot.publicMethod(); // Error: public inherited as protected
    prot.accessBaseMethod();
    
    // Private inheritance
    cout << "\nPrivate Inheritance:" << endl;
    cout << string(30, '-') << endl;
    PrivateDerived priv;
    // priv.publicMethod(); // Error: public inherited as private
    priv.accessBaseMethod();
    
    // Further inheritance
    cout << "\nFurther Inheritance:" << endl;
    cout << string(30, '-') << endl;
    FurtherDerived further;
    further.publicMethod(); // OK: inherited as public from PublicDerived
    
    return 0;
}
```

## Best Practices

### Inheritance Type Selection
1. Use public inheritance for "is-a" relationships
2. Use private inheritance for implementation details
3. Use protected inheritance rarely
4. Document inheritance decisions
5. Consider composition alternatives

### Access Control
1. Keep public interface minimal
2. Use protected for inheritance
3. Keep implementation private
4. Consider friend declarations
5. Document access patterns

### Design Guidelines
1. Follow LSP principles
2. Use inheritance purposefully
3. Consider alternatives
4. Document relationships
5. Test thoroughly

## Common Mistakes to Avoid
1. Wrong inheritance type
2. Access level confusion
3. Inheritance abuse
4. Deep hierarchies
5. Breaking encapsulation

## Next Steps
- Try the practice exercise
- Experiment with inheritance types
- Review Module 7 concepts
- Consider taking [Module 8: Core OOP Concepts - Polymorphism]({{ site.baseurl }}/tutorials/module8)
