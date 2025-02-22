#include <iostream>
#include <vector>
#include <string>

class GameItem {
private:
    std::string name;
    int power;
    
public:
    GameItem(std::string n, int p) : name(n), power(p) {
        std::cout << "✨ Created " << name << "!" << std::endl;
    }
    
    std::string getName() const { return name; }
    int getPower() const { return power; }
};

class Inventory {
private:
    std::vector<GameItem> items;  // Dynamic collection!
    
public:
    // Add item
    void addItem(const GameItem& item) {
        items.push_back(item);
        std::cout << "🎒 Added " << item.getName() 
             << " to inventory!" << std::endl;
    }
    
    // Get item safely
    const GameItem* getItem(size_t slot) const {
        try {
            return &items.at(slot);  // Safe access!
        } catch (const std::out_of_range& e) {
            std::cout << "❌ Invalid slot!" << std::endl;
            return nullptr;
        }
    }
    
    // Remove last item
    void removeLastItem() {
        if (!items.empty()) {
            std::cout << "💨 Removed " << items.back().getName() 
                 << std::endl;
            items.pop_back();
        }
    }
    
    // Show inventory
    void showInventory() const {
        std::cout << "\n📊 Inventory (" << items.size() 
             << "/" << items.capacity() << "):" << std::endl;
        for (size_t i = 0; i < items.size(); i++) {
            std::cout << i << ": " << items[i].getName() 
                 << " (Power: " << items[i].getPower() 
                 << ")" << std::endl;
        }
    }
};

int main() {
    std::cout << "Starting game! 🎮\n" << std::endl;
    
    // Create inventory
    Inventory backpack;
    
    // Add some items
    backpack.addItem(GameItem("Magic Sword", 50));
    backpack.addItem(GameItem("Health Potion", 30));
    backpack.addItem(GameItem("Shield", 40));
    
    // Show inventory
    backpack.showInventory();
    
    // Try to get items
    if (const GameItem* item = backpack.getItem(0)) {
        std::cout << "\n⚔️ Using " << item->getName() << std::endl;
    }
    backpack.getItem(99);  // Safe: shows error message
    
    // Remove last item
    backpack.removeLastItem();
    backpack.showInventory();
    
    return 0;
}
