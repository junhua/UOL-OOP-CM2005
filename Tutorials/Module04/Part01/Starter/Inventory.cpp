#include "Inventory.h"
#include <iostream>

void Inventory::addItem(const GameItem& item) {
    items.push_back(item);
    std::cout << "🎒 Added " << item.getName() 
         << " to inventory!" << std::endl;
    
    // TODO: When implementing map operations
    // Don't forget to increment the quantity here
}

const GameItem* Inventory::getItem(size_t slot) const {
    try {
        return &items.at(slot);  // Safe access with bounds checking
    } catch (const std::out_of_range& e) {
        std::cout << "❌ Invalid slot!" << std::endl;
        return nullptr;
    }
}

void Inventory::removeLastItem() {
    if (!items.empty()) {
        std::cout << "💨 Removed " << items.back().getName() 
             << std::endl;
        items.pop_back();
        
        // TODO: When implementing map operations
        // Don't forget to decrement the quantity here
    }
}

void Inventory::showInventory() const {
    std::cout << "\n📊 Inventory (" << items.size() 
         << "/" << items.capacity() << "):" << std::endl;
    
    for (size_t i = 0; i < items.size(); i++) {
        std::cout << i << ": " << items[i].getName() 
             << " (Power: " << items[i].getPower() 
             << ")" << std::endl;
    }
    
    // TODO: Implement showUniqueItems() to display the set contents
    // Hint: Iterate through the set using a range-based for loop
    
    // TODO: Implement showQuantities() to display the map contents
    // Hint: Iterate through the map using a range-based for loop
    // showing each item's name and quantity
}
