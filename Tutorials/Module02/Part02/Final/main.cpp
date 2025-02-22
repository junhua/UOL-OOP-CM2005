#include <iostream>

class MagicSystem {
private:
    int mana;
    bool hasSpellbook;
    
public:
    MagicSystem() : mana(100), hasSpellbook(true) {
        std::cout << "✨ Magic system ready!" << std::endl;
    }
    
    void castSpell(char spellType) {
        if (!hasSpellbook) {
            std::cout << "❌ Need spellbook to cast!" << std::endl;
            return;
        }
        
        std::cout << "\n🎮 Casting spell..." << std::endl;
        
        switch (spellType) {
            case 'F':
            case 'f':
                if (mana >= 30) {
                    std::cout << "🔥 FIREBALL!" << std::endl;
                    std::cout << "💥 Deals fire damage!" << std::endl;
                    mana -= 30;
                } else {
                    std::cout << "❌ Not enough mana!" << std::endl;
                }
                break;
                
            case 'I':
            case 'i':
                if (mana >= 25) {
                    std::cout << "❄️ ICE BLAST!" << std::endl;
                    std::cout << "❄️ Freezes enemies!" << std::endl;
                    mana -= 25;
                } else {
                    std::cout << "❌ Not enough mana!" << std::endl;
                }
                break;
                
            case 'L':
            case 'l':
                if (mana >= 40) {
                    std::cout << "⚡ LIGHTNING STRIKE!" << std::endl;
                    std::cout << "⚡ Chain damage!" << std::endl;
                    mana -= 40;
                } else {
                    std::cout << "❌ Not enough mana!" << std::endl;
                }
                break;
                
            case 'W':
            case 'w':
                if (mana >= 20) {
                    std::cout << "🌪️ WIND GUST!" << std::endl;
                    std::cout << "💨 Pushes enemies!" << std::endl;
                    mana -= 20;
                } else {
                    std::cout << "❌ Not enough mana!" << std::endl;
                }
                break;
                
            default:
                std::cout << "❌ Unknown spell!" << std::endl;
                std::cout << "Try F/I/L/W" << std::endl;
        }
        
        // Show mana status
        std::cout << "\n✨ Mana: " << mana << "/100" << std::endl;
    }
};
