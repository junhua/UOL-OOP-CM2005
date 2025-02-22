#include <iostream>
#include <vector>

class TreasureHunt {
private:
    std::vector<char> rooms;
    int score;
    bool hasSword;
    
public:
    TreasureHunt() : score(0), hasSword(false) {
        // Set up dungeon
        rooms = {'T', 'G', '.', 'S', '.',
                'P', 'D', 'T', '.', 'C'};
        std::cout << "🎮 Dungeon ready!" << std::endl;
    }
    
    void huntTreasure() {
        std::cout << "\n🗺️ Starting treasure hunt!" << std::endl;
        
        for (int i = 0; i < rooms.size(); i++) {
            std::cout << "\nRoom " << (i + 1) << ": ";
            
            // Skip empty rooms
            if (rooms[i] == '.') {
                std::cout << "Empty room, moving on..." << std::endl;
                continue;
            }
            
            // Handle room content
            switch (rooms[i]) {
                case '💎':
                    std::cout << "Found treasure!" << std::endl;
                    score += 100;
                    std::cout << "💰 Score: " << score << std::endl;
                    break;
                    
                case '👻':
                    if (!hasSword) {
                        std::cout << "Ghost! Can't fight!" << std::endl;
                        continue;  // Skip room
                    }
                    std::cout << "Defeated ghost!" << std::endl;
                    score += 50;
                    break;
                    
                case '⚔️':
                    std::cout << "Found sword!" << std::endl;
                    hasSword = true;
                    break;
                    
                case '🧪':
                    std::cout << "Found potion!" << std::endl;
                    score += 25;
                    break;
                    
                case '🐉':
                    std::cout << "DRAGON!" << std::endl;
                    if (!hasSword) {
                        std::cout << "Need sword first!" << std::endl;
                        return;  // Exit dungeon!
                    }
                    std::cout << "Defeated dragon!" << std::endl;
                    score += 500;
                    break;
                    
                case '👑':
                    std::cout << "Found the crown!" << std::endl;
                    score += 1000;
                    std::cout << "\n🎉 DUNGEON COMPLETE!" << std::endl;
                    std::cout << "💰 Final score: " << score << std::endl;
                    return;  // Victory!
            }
        }
        
        std::cout << "\n🎮 Dungeon explored!" << std::endl;
        std::cout << "💰 Final score: " << score << std::endl;
    }
};
