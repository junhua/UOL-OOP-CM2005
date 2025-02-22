// This tutorial demonstrates:
// 1. Smart pointers (unique_ptr, shared_ptr, weak_ptr)
// 2. Memory management with smart pointers
// 3. Ownership semantics
// 4. Circular references

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// Forward declarations
class Player;
class Buff;

class Buff {
private:
    string name;
    int duration;
    weak_ptr<Player> target;  // Weak reference to avoid circular dependency
    
public:
    Buff(string n, int d) : name(n), duration(d) {
        cout << "✨ Created buff: " << name << endl;
    }
    
    ~Buff() {
        cout << "💨 Buff expired: " << name << endl;
    }
    
    void setTarget(shared_ptr<Player> p) {
        target = p;  // Store weak reference
    }
    
    void apply();  // Defined after Player class
};

class Player : public enable_shared_from_this<Player> {
private:
    string name;
    vector<shared_ptr<Buff>> buffs;  // Player shares ownership of buffs
    
public:
    Player(string n) : name(n) {
        cout << "👤 Created player: " << name << endl;
    }
    
    ~Player() {
        cout << "👋 Player left: " << name << endl;
    }
    
    void addBuff(shared_ptr<Buff> buff) {
        buffs.push_back(buff);
        buff->setTarget(shared_from_this());  // Safe way to get shared_ptr to this
    }
    
    string getName() const { return name; }
    
    void showBuffs() const {
        cout << "\n" << name << "'s buffs:" << endl;
        for(const auto& buff : buffs) {
            cout << "- " << buff.use_count() << " references to buff" << endl;
        }
    }
};

// Now we can define Buff::apply
void Buff::apply() {
    if(auto p = target.lock()) {  // Convert weak_ptr to shared_ptr
        cout << "✨ Applied " << name << " to " << p->getName() << endl;
    } else {
        cout << "❌ Target no longer exists!" << endl;
    }
}

int main() {
    // Create a scope to demonstrate cleanup
    {
        // Create player using smart pointer
        auto player = make_shared<Player>("Hero");
        
        // Create and add some buffs
        auto speedBuff = make_shared<Buff>("Speed Boost", 10);
        auto strengthBuff = make_shared<Buff>("Strength Boost", 15);
        
        player->addBuff(speedBuff);
        player->addBuff(strengthBuff);
        
        // Apply buffs
        speedBuff->apply();
        strengthBuff->apply();
        
        // Show buff reference counts
        player->showBuffs();
        
        cout << "\nLeaving scope..." << endl;
    }
    // Smart pointers automatically clean up here
    
    cout << "\nReturning from main..." << endl;
    return 0;
}
