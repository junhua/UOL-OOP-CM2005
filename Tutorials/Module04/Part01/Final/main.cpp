#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm> // Required for set_difference, find_if

class GameItem {
public:
    std::string name;
    int power;

    GameItem(std::string n, int p) : name(n), power(p) {
        std::cout << "✨ Created " << name << "!" << std::endl;
    }

    // Comparison operator for set (required for custom types)
    bool operator<(const GameItem& other) const {
        return name < other.name;
    }
};

class Achievement {
public:
    std::string name;
    std::string description;
    int points;

    Achievement(std::string n, std::string d, int p)
        : name(n), description(d), points(p) {}

    // Comparison operator for set (required for custom types)
    bool operator<(const Achievement& other) const {
        return name < other.name;
    }

    std::string getName() const { return name; }
    std::string getDesc() const { return description; }
    int getPoints() const { return points; }
};

class AchievementSystem {
private:
    std::set<Achievement> unlockedAchievements;
    std::set<Achievement> availableAchievements;

public:
    AchievementSystem() {
        // Initialize available achievements
        availableAchievements = {
            Achievement("First Kill", "Defeat your first enemy", 10),
            Achievement("Collector", "Collect 10 items", 20),
            Achievement("Survivor", "Survive 5 minutes", 30),
            Achievement("Champion", "Win the game", 50)
        };
        std::cout << "🏆 Achievement system ready!" << std::endl;
    }

    // Try to unlock achievement
    void unlock(const std::string& name) {
        // Find achievement
        auto it = std::find_if(
            availableAchievements.begin(),
            availableAchievements.end(),
            [&name](const Achievement& a) {
                return a.getName() == name;
            }
        );

        if (it != availableAchievements.end()) {
            // Try to add to unlocked (will fail if already unlocked)
            auto [_, success] = unlockedAchievements.insert(*it);
            if (success) {
                std::cout << "🌟 Achievement Unlocked: "
                     << it->getName() << "!" << std::endl;
                std::cout << "📜 " << it->getDesc() << std::endl;
                std::cout << "✨ +" << it->getPoints()
                     << " points!" << std::endl;
            } else {
                std::cout << "❌ Already unlocked!" << std::endl;
            }
        }
    }

    // Show achievements
    void showAchievements() const {
        std::cout << "\n🏆 Achievements ("
             << unlockedAchievements.size() << "/"
             << availableAchievements.size()
             << "):" << std::endl;

        // Calculate total points
        int totalPoints = 0;
        for (const auto& a : unlockedAchievements) {
            totalPoints += a.getPoints();
        }

        // Show unlocked
        std::cout << "\n✨ Unlocked:" << std::endl;
        for (const auto& a : unlockedAchievements) {
            std::cout << "- " << a.getName()
                 << " (" << a.getPoints()
                 << " points)" << std::endl;
        }

        // Show locked
        std::cout << "\n🔒 Locked:" << std::endl;
        std::set<Achievement> locked;
        std::set_difference(
            availableAchievements.begin(),
            availableAchievements.end(),
            unlockedAchievements.begin(),
            unlockedAchievements.end(),
            std::inserter(locked, locked.begin())
        );

        for (const auto& a : locked) {
            std::cout << "- " << a.getName() << std::endl;
        }

        std::cout << "\n📊 Total Points: "
             << totalPoints << std::endl;
    }
};

int main(){
    std::cout << "Starting game! 🎮\n" << std::endl;

    AchievementSystem achievements;

    // Try to unlock achievements
    achievements.unlock("First Kill");
    achievements.unlock("First Kill");  // Already unlocked!
    achievements.unlock("Collector");

    // Show progress
    achievements.showAchievements();

    return 0;
}
