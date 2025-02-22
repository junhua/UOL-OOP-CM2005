#include <iostream>
#include <string>

class GameItem {
private:
    std::string name;
    int power;
    
public:
    GameItem() : name("Empty"), power(0) {}
    
    GameItem(std::string n, int p) : name(n), power(p) {
        std::cout << "✨ Created " << name << "!" << std::endl;
    }
    
    void use() const {
        if (name == "Empty") {
            std::cout << "❌ Empty slot!" << std::endl;
        } else {
            std::cout << "⚡ Using " << name 
                 << " (Power: " << power << ")" << std::endl;
        }
    }
    
    std::string getName() const { return name; }
    bool isEmpty() const { return name == "Empty"; }
};

class Inventory {
private:
    static const int SLOTS = 5;  // Fixed size array
    GameItem items[SLOTS];  // Array of items
    
public:
    Inventory() {
        std::cout << "🎒 Created inventory with " 
             << SLOTS << " slots!" << std::endl;
    }
    
    // Add item to specific slot
    bool addItem(int slot, const GameItem& item) {
        if (slot >= 0 && slot < SLOTS) {
            if (items[slot].isEmpty()) {
                items[slot] = item;
                std::cout << "✨ Added " << item.getName() 
                     << " to slot " << slot << std::endl;
                return true;
            } else {
                std::cout << "❌ Slot " << slot 
                     << " is occupied!" << std::endl;
            }
        } else {
            std::cout << "❌ Invalid slot number!" << std::endl;
        }
        return false;
    }
    
    // Use item in slot
    void useItem(int slot) {
        if (slot >= 0 && slot < SLOTS) {
            std::cout << "\n🎯 Using slot " << slot << ":" << std::endl;
            items[slot].use();
        } else {
            std::cout << "❌ Invalid slot number!" << std::endl;
        }
    }
    
    // Show inventory
    void showInventory() const {
        std::cout << "\n📊 Inventory Status:" << std::endl;
        for (int i = 0; i < SLOTS; i++) {
            std::cout << i << ": " << items[i].getName() << std::endl;
        }
    }
};

int main() {
    std::cout << "Starting game! 🎮\n" << std::endl;

    // Create inventory
    Inventory backpack;

    // Add some items
    backpack.addItem(0, GameItem("Magic Sword", 50));
    backpack.addItem(2, GameItem("Health Potion", 30));
    backpack.addItem(2, GameItem("Shield", 40));  // Occupied!
    backpack.addItem(9, GameItem("Bow", 35));     // Invalid!

    // Show inventory
    backpack.showInventory();

    // Use some items
    backpack.useItem(0);  // Magic Sword
    backpack.useItem(1);  // Empty slot
    backpack.useItem(2);  // Health Potion

    return 0;
}
