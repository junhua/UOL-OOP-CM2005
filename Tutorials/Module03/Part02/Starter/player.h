#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name;
    int health;
    int mana;

public:
    // Basic attack function
    void attack(std::string target);

    // Healing function
    void heal(int amount);

    // Magic attack function
    bool castSpell(std::string spellName, int manaCost);
};

#endif
