#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class TreasureHunt {
private:
    std::vector<std::vector<char>> map;
    int playerX, playerY;
    int score;
    const int WIDTH = 10;
    const int HEIGHT = 5;
    
public:
    TreasureHunt() : playerX(0), playerY(0), score(0) {
        // Initialize map
        map = std::vector<std::vector<char>>(HEIGHT, 
             std::vector<char>(WIDTH, '.'));
        
        // Seed random number generator
        std::srand(std::time(0));
        
        // Hide treasures
        for (int i = 0; i < 5; i++) {
            int x = std::rand() % WIDTH;
            int y = std::rand() % HEIGHT;
            map[y][x] = '💎';
        }
        
        std::cout << "🎮 Treasure hunt ready!" << std::endl;
    }
    
    void playGame() {
        bool isPlaying = true;
        
        do {
            // Show map
            std::cout << "\n=== TREASURE MAP ===\n";
            for (int y = 0; y < HEIGHT; y++) {
                for (int x = 0; x < WIDTH; x++) {
                    if (x == playerX && y == playerY) {
                        std::cout << "🎮";  // Player
                    } else {
                        std::cout << map[y][x];
                    }
                }
                std::cout << std::endl;
            }
            
            // Show status
            std::cout << "\n💰 Score: " << score << std::endl;
            
            // Get move
            char move;
            std::cout << "\nMove (W/A/S/D): ";
            std::cin >> move;
            
            // Handle movement
            switch (move) {
                case 'W':
                case 'w':
                    if (playerY > 0) playerY--;
                    break;
                case 'S':
                case 's':
                    if (playerY < HEIGHT-1) playerY++;
                    break;
                case 'A':
                case 'a':
                    if (playerX > 0) playerX--;
                    break;
                case 'D':
                case 'd':
                    if (playerX < WIDTH-1) playerX++;
                    break;
                case 'Q':
                case 'q':
                    isPlaying = false;
                    break;
            }
            
            // Check for treasure
            if (map[playerY][playerX] == '💎') {
                std::cout << "\n✨ Found treasure!" << std::endl;
                score += 100;
                map[playerY][playerX] = '.';
            }
            
        } while (isPlaying && score < 500);
        
        // Game over
        std::cout << "\n🎮 GAME OVER!" << std::endl;
        std::cout << "💰 Final score: " << score << std::endl;
    }
};
