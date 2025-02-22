#include "GameItem.h"

GameItem::GameItem(std::string n, int p) : name(n), power(p) {
    std::cout << "✨ Created " << name << "!" << std::endl;
}

std::string GameItem::getName() const { 
    return name; 
}

int GameItem::getPower() const { 
    return power; 
}

// TODO: Implement the operator< function here
// This is needed for storing GameItems in a std::set
bool GameItem::operator<(const GameItem& other) const {
    // Your code here
    return false; // Placeholder return
}
