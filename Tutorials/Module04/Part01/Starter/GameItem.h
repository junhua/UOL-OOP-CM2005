#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <string>
#include <iostream>

class GameItem {
private:
    std::string name;
    int power;
    
public:
    GameItem(std::string n, int p);
    
    std::string getName() const;
    int getPower() const;
    
    // TODO: Implement operator< for use with std::set
    // Hint: Compare items based on their names
    bool operator<(const GameItem& other) const;
};

#endif // GAME_ITEM_H
