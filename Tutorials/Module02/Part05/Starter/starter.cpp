#include <iostream>
#include <string>

class InventorySystem {
private:
    const int MAX_ITEMS = 10;
    std::string items[10];
    int quantities[10];
    int itemCount = 0;
    int gold = 100;
    
public:
    void run() {
        char choice;
        
        do {
            // Show menu
            std::cout << "\n🎒 INVENTORY MENU\n";
            std::cout << "💰 Gold: " << gold << std::endl;
            std::cout << "1. 📦 View Items\n";
            std::cout << "2. ➕ Add Item\n";
            std::cout << "3. ➖ Use Item\n";
            std::cout << "4. 💰 Shop\n";
            std::cout << "5. ❌ Exit\n";
            std::cout << "Choice (1-5): ";
            std::cin >> choice;
            
            switch (choice) {
                case '1': { // View items
                    if (itemCount == 0) {
                        std::cout << "❌ No items!" << std::endl;
                    } else {
                        std::cout << "\n📦 YOUR ITEMS:\n";
                        for (int i = 0; i < itemCount; i++) {
                            std::cout << (i + 1) << ". ";
                            std::cout << items[i] << " x";
                            std::cout << quantities[i] << std::endl;
                        }
                    }
                    break;
                }
                case '2': { // Add item
                    if (itemCount < MAX_ITEMS) {
                        std::string newItem;
                        std::cout << "Item name: ";
                        std::cin.ignore();
                        std::getline(std::cin, newItem);
                        
                        // Check if item exists
                        bool found = false;
                        for (int i = 0; i < itemCount; i++) {
                            if (items[i] == newItem) {
                                quantities[i]++;
                                found = true;
                                std::cout << "✨ Added to stack!" << std::endl;
                                break;
                            }
                        }
                        
                        // New item
                        if (!found) {
                            items[itemCount] = newItem;
                            quantities[itemCount] = 1;
                            itemCount++;
                            std::cout << "✨ New item added!" << std::endl;
                        }
                    } else {
                        std::cout << "❌ Inventory full!" << std::endl;
                    }
                    break;
                }    
                case '3': { // Use item
                    if (itemCount == 0) {
                        std::cout << "❌ No items!" << std::endl;
                    } else {
                        int index;
                        std::cout << "Use which item? (1-" 
                             << itemCount << "): ";
                        std::cin >> index;
                        index--;  // Convert to 0-based
                        
                        if (index >= 0 && index < itemCount) {
                            std::cout << "Used " << items[index] 
                                 << "!" << std::endl;
                            
                            // Remove one from stack
                            quantities[index]--;
                            
                            // Remove item if none left
                            if (quantities[index] == 0) {
                                for (int i = index; 
                                     i < itemCount - 1; i++) {
                                    items[i] = items[i + 1];
                                    quantities[i] = 
                                        quantities[i + 1];
                                }
                                itemCount--;
                            }
                            
                            std::cout << "✨ Item used!" << std::endl;
                        } else {
                            std::cout << "❌ Invalid item!" << std::endl;
                        }
                    }
                    break;
                }
                case '4': { // Shop
                    std::cout << "\n💰 SHOP:\n";
                    std::cout << "1. Health Potion (50g)\n";
                    std::cout << "2. Magic Scroll (75g)\n";
                    std::cout << "3. Power Ring (100g)\n";
                    
                    int shopChoice;
                    std::cout << "Buy what? (1-3): ";
                    std::cin >> shopChoice;
                    
                    std::string itemName;
                    int cost;
                    
                    switch (shopChoice) {
                        case 1:
                            itemName = "Health Potion";
                            cost = 50;
                            break;
                        case 2:
                            itemName = "Magic Scroll";
                            cost = 75;
                            break;
                        case 3:
                            itemName = "Power Ring";
                            cost = 100;
                            break;
                        default:
                            std::cout << "❌ Invalid choice!" << std::endl;
                            continue;
                    }
                    
                    if (gold >= cost) {
                        gold -= cost;
                        
                        // Add to inventory
                        bool found = false;
                        for (int i = 0; i < itemCount; i++) {
                            if (items[i] == itemName) {
                                quantities[i]++;
                                found = true;
                                break;
                            }
                        }
                        
                        if (!found && itemCount < MAX_ITEMS) {
                            items[itemCount] = itemName;
                            quantities[itemCount] = 1;
                            itemCount++;
                        }
                        
                        std::cout << "✨ Bought " << itemName << "!";
                        std::cout << std::endl;
                    } else {
                        std::cout << "❌ Not enough gold!" << std::endl;
                    }
                    break;
                }    
                case '5': { // Exit
                    std::cout << "👋 Goodbye!" << std::endl;
                    break;
                }    
                default: {
                    std::cout << "❌ Invalid choice!" << std::endl;
                }
            }
            
        } while (choice != '5');
    }
};
