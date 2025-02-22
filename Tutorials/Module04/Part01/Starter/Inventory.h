#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <set>
#include <map>
#include <string>
#include "GameItem.h"

class Inventory {
private:
    // TODO: Create three different containers:
    // 1. vector<GameItem> for storing items in order
    std::vector<GameItem> items;
    
    // 2. set<GameItem> for storing unique items
    // Hint: This is why we need operator< in GameItem
    // TODO: Declare a set to store unique items
    
    // 3. map<string, int> for counting item quantities
    // Hint: Use item name as key, quantity as value
    // TODO: Declare a map to store item quantities
    
public:
    // Vector operations
    void addItem(const GameItem& item);
    const GameItem* getItem(size_t slot) const;
    void removeLastItem();
    
    // TODO: Set operations
    // Hint: These should prevent duplicate items
    // void addUniqueItem(const GameItem& item);
    // bool hasItem(const GameItem& item) const;
    // void removeUniqueItem(const GameItem& item);
    
    // TODO: Map operations
    // Hint: These should track item quantities
    // void incrementQuantity(const std::string& itemName);
    // void decrementQuantity(const std::string& itemName);
    // int getQuantity(const std::string& itemName) const;
    
    // Display functions
    void showInventory() const;
    // TODO: Add functions to show unique items and quantities
    // void showUniqueItems() const;
    // void showQuantities() const;
};

#endif // INVENTORY_H
