#include <iostream>
#include <string>
using namespace std;

/**
 * Module 7 - Part 4: Types of Inheritance
 * Practice Exercise Solution
 * 
 * This program demonstrates:
 * 1. Different inheritance types
 * 2. Access level changes
 * 3. Inheritance chains
 * 4. Access control
 */

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

// Public inheritance example
class PublicDerived : public Base {
public:
    PublicDerived() : Base("PublicDerived") {
        cout << "Public inheritance example" << endl;
    }
    
    // Demonstrate access levels
    void testAccess() {
        cout << "\nTesting access in PublicDerived:" << endl;
        cout << string(30, '-') << endl;
        
        publicMethod();      // OK: public inherited as public
        protectedMethod();   // OK: protected inherited as protected
        // privateMethod();  // Error: private not accessible
        
        cout << "Name from protected getter: " << getName() << endl;
    }
};

// Protected inheritance example
class ProtectedDerived : protected Base {
public:
    ProtectedDerived() : Base("ProtectedDerived") {
        cout << "Protected inheritance example" << endl;
    }
    
    // Provide controlled access to base methods
    void accessBaseMethod() {
        cout << "\nAccessing base methods in ProtectedDerived:" << endl;
        cout << string(30, '-') << endl;
        
        publicMethod();      // OK: public inherited as protected
        protectedMethod();   // OK: protected inherited as protected
        // privateMethod();  // Error: private not accessible
        
        cout << "Name from protected getter: " << getName() << endl;
    }
};

// Private inheritance example
class PrivateDerived : private Base {
public:
    PrivateDerived() : Base("PrivateDerived") {
        cout << "Private inheritance example" << endl;
    }
    
    // Selectively expose base functionality
    void accessBaseMethod() {
        cout << "\nAccessing base methods in PrivateDerived:" << endl;
        cout << string(30, '-') << endl;
        
        publicMethod();      // OK: public inherited as private
        protectedMethod();   // OK: protected inherited as private
        // privateMethod();  // Error: private not accessible
        
        cout << "Name from protected getter: " << getName() << endl;
    }
    
    // Re-expose some base functionality with different access
    void exposePublicMethod() {
        publicMethod();  // Make accessible through our public interface
    }
};

// Further inheritance from public class
class FurtherDerived : public PublicDerived {
public:
    FurtherDerived() {
        cout << "Further derivation example" << endl;
    }
    
    void testInheritance() {
        cout << "\nTesting inheritance in FurtherDerived:" << endl;
        cout << string(30, '-') << endl;
        
        publicMethod();      // OK: still public
        protectedMethod();   // OK: still protected
        // privateMethod();  // Error: private not accessible
        
        cout << "Name from protected getter: " << getName() << endl;
    }
};

// Demonstrate why private inheritance blocks further inheritance
// Error: Cannot derive from PrivateDerived
/*
class AttemptPrivateDerived : public PrivateDerived {
    void test() {
        // Error: Base members are private in PrivateDerived
        publicMethod();
        protectedMethod();
    }
};
*/

int main() {
    cout << "Testing inheritance types:" << endl;
    cout << string(50, '=') << endl;
    
    // Test public inheritance
    cout << "\nPublic Inheritance:" << endl;
    cout << string(30, '-') << endl;
    PublicDerived pub;
    pub.publicMethod();    // OK: public inherited as public
    pub.testAccess();
    
    // Test protected inheritance
    cout << "\nProtected Inheritance:" << endl;
    cout << string(30, '-') << endl;
    ProtectedDerived prot;
    // prot.publicMethod(); // Error: public inherited as protected
    prot.accessBaseMethod();
    
    // Test private inheritance
    cout << "\nPrivate Inheritance:" << endl;
    cout << string(30, '-') << endl;
    PrivateDerived priv;
    // priv.publicMethod(); // Error: public inherited as private
    priv.accessBaseMethod();
    priv.exposePublicMethod();  // OK: through public interface
    
    // Test further inheritance
    cout << "\nFurther Inheritance:" << endl;
    cout << string(30, '-') << endl;
    FurtherDerived further;
    further.publicMethod();  // OK: inherited as public from PublicDerived
    further.testInheritance();
    
    cout << "\nInheritance demonstration completed" << endl;
    cout << string(50, '=') << endl;
    
    return 0;
}
