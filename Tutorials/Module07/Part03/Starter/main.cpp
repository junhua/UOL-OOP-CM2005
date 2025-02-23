#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * Module 7 - Part 3: Overriding Methods
 * Practice Exercise Starter Code
 * 
 * Task: Create a media player system with:
 * 1. Abstract Media base class
 * 2. Different media types
 * 3. Common and specific operations
 * 4. Polymorphic behavior
 */

// TODO: Create Media abstract base class with:
// - Protected members for title, artist, duration, playing status
// - Constructor to initialize members
// - Virtual destructor
// - Common virtual methods:
//   * play()
//   * stop()
//   * pause()
// - Pure virtual methods:
//   * displayInfo()
//   * getType()
// - Getters for properties
// - Protected helper for time formatting

// TODO: Create Song class that:
// - Inherits from Media
// - Adds album and genre
// - Overrides play with music-specific behavior
// - Implements required virtual methods

// TODO: Create Video class that:
// - Inherits from Media
// - Adds resolution and subtitles flag
// - Overrides play with video-specific behavior
// - Implements required virtual methods

// TODO: Create Podcast class that:
// - Inherits from Media
// - Adds episode and category
// - Overrides play with podcast-specific behavior
// - Implements required virtual methods

// TODO: Create MediaPlayer class to:
// - Manage playlist of media items
// - Add media to playlist
// - Play all media
// - Display playlist information

int main() {
    try {
        // TODO: Create media player
        
        // TODO: Add different types of media
        // - Song with album and genre
        // - Video with resolution and subtitles
        // - Podcast with episode and category
        
        // TODO: Display playlist
        
        // TODO: Play all media
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
