#include <iostream>
#include <string>
#include "player.h"

// Basic attack function
void Player::attack(std::string target) {
    std::cout << "\n⚔️ " << name << " attacks " << target
        << "!" << std::endl;
}

// Healing function
void Player::heal(int amount) {
    health += amount;
    std::cout << "\n✨ " << name << " heals " << amount
        << " HP!" << std::endl;
    std::cout << "❤️ Health: " << health << std::endl;
}

// Magic attack function
bool Player::castSpell(std::string spellName, int manaCost) {
    if (mana >= manaCost) {
        std::cout << "\n🔮 " << name << " casts "
            << spellName << "!" << std::endl;
        mana -= manaCost;
        std::cout << "✨ Mana: " << mana << std::endl;
        return true;
    }
    else {
        std::cout << "\n❌ Not enough mana!" << std::endl;
        return false;
    }
}
