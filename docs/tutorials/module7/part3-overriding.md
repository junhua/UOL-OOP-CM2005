---
layout: default
title: Part 3 - Overriding Methods
nav_order: 3
parent: Module 7 - Core OOP Concepts - Inheritance
grand_parent: Tutorials
permalink: /tutorials/module7/part3-overriding/
---

# Part 3: Overriding Methods

## Overview
Method overriding allows derived classes to provide specific implementations of methods defined in their base class. This enables polymorphic behavior and customization of inherited functionality.

## Method Overriding Basics

### Virtual Methods
```cpp
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
    
    virtual void move() {
        cout << "Animal moves" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
    
    void move() override {
        cout << "Dog runs on four legs" << endl;
    }
};
```

### Pure Virtual Methods
```cpp
class Shape {
public:
    virtual double getArea() const = 0;     // Pure virtual
    virtual double getPerimeter() const = 0; // Pure virtual
    
    virtual void draw() const {             // Virtual with default
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
    
    void draw() const override {
        cout << "Drawing circle with radius " << radius << endl;
    }
};
```

### Override Keyword
```cpp
class Base {
public:
    virtual void method1() const { }
    virtual void method2() { }
};

class Derived : public Base {
public:
    void method1() const override { }  // Correct
    void method2() override { }        // Correct
    // void method3() override { }     // Error: no base method
    // void method1() override { }     // Error: missing const
};
```

## Practice Exercise

Create a media player system with different types of media:
1. Abstract Media base class
2. Different media types
3. Common and specific operations
4. Polymorphic behavior

Solution:
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Media {
protected:
    string title;
    string artist;
    int duration;  // in seconds
    bool isPlaying;
    
public:
    Media(string title, string artist, int duration)
        : title(title), artist(artist), duration(duration), isPlaying(false) {
        cout << "Creating media: " << title << endl;
    }
    
    virtual ~Media() {
        cout << "Destroying media: " << title << endl;
    }
    
    // Common methods with default implementation
    virtual void play() {
        if (!isPlaying) {
            isPlaying = true;
            cout << "Playing: " << title << endl;
        }
    }
    
    virtual void stop() {
        if (isPlaying) {
            isPlaying = false;
            cout << "Stopped: " << title << endl;
        }
    }
    
    virtual void pause() {
        if (isPlaying) {
            isPlaying = false;
            cout << "Paused: " << title << endl;
        }
    }
    
    // Pure virtual methods
    virtual void displayInfo() const = 0;
    virtual string getType() const = 0;
    
    // Getters
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    int getDuration() const { return duration; }
    bool getIsPlaying() const { return isPlaying; }
    
protected:
    // Helper method for time formatting
    string formatDuration() const {
        int minutes = duration / 60;
        int seconds = duration % 60;
        return to_string(minutes) + ":" + 
               (seconds < 10 ? "0" : "") + to_string(seconds);
    }
};

class Song : public Media {
private:
    string album;
    string genre;
    
public:
    Song(string title, string artist, int duration,
         string album, string genre)
        : Media(title, artist, duration),
          album(album), genre(genre) {}
    
    void play() override {
        Media::play();
        if (isPlaying) {
            cout << "♪ Playing music: " << title << " - " << artist << endl;
        }
    }
    
    string getType() const override {
        return "Song";
    }
    
    void displayInfo() const override {
        cout << "\nSong Information:" << endl;
        cout << "================" << endl;
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Album: " << album << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
};

class Video : public Media {
private:
    string resolution;
    bool hasSubtitles;
    
public:
    Video(string title, string artist, int duration,
          string resolution, bool subtitles)
        : Media(title, artist, duration),
          resolution(resolution), hasSubtitles(subtitles) {}
    
    void play() override {
        Media::play();
        if (isPlaying) {
            cout << "▶ Playing video: " << title << " (" << resolution << ")" << endl;
            if (hasSubtitles) {
                cout << "Subtitles enabled" << endl;
            }
        }
    }
    
    string getType() const override {
        return "Video";
    }
    
    void displayInfo() const override {
        cout << "\nVideo Information:" << endl;
        cout << "================" << endl;
        cout << "Title: " << title << endl;
        cout << "Creator: " << artist << endl;
        cout << "Resolution: " << resolution << endl;
        cout << "Subtitles: " << (hasSubtitles ? "Yes" : "No") << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
};

class Podcast : public Media {
private:
    string episode;
    string category;
    
public:
    Podcast(string title, string artist, int duration,
            string episode, string category)
        : Media(title, artist, duration),
          episode(episode), category(category) {}
    
    void play() override {
        Media::play();
        if (isPlaying) {
            cout << "🎙 Playing podcast: " << title << " - " << episode << endl;
        }
    }
    
    string getType() const override {
        return "Podcast";
    }
    
    void displayInfo() const override {
        cout << "\nPodcast Information:" << endl;
        cout << "===================" << endl;
        cout << "Title: " << title << endl;
        cout << "Host: " << artist << endl;
        cout << "Episode: " << episode << endl;
        cout << "Category: " << category << endl;
        cout << "Duration: " << formatDuration() << endl;
        cout << "Status: " << (isPlaying ? "Playing" : "Stopped") << endl;
    }
};

class MediaPlayer {
private:
    vector<Media*> playlist;
    string playerName;
    
public:
    MediaPlayer(string name = "My Media Player") : playerName(name) {
        cout << "Starting " << playerName << endl;
    }
    
    ~MediaPlayer() {
        cout << "Shutting down " << playerName << endl;
        for (Media* media : playlist) {
            delete media;
        }
    }
    
    void addMedia(Media* media) {
        playlist.push_back(media);
        cout << "Added " << media->getType() << ": " << media->getTitle() << endl;
    }
    
    void playAll() {
        cout << "\nPlaying all media:" << endl;
        cout << string(50, '=') << endl;
        
        for (Media* media : playlist) {
            media->play();
            media->displayInfo();
            media->stop();
            cout << string(50, '-') << endl;
        }
    }
    
    void displayPlaylist() const {
        cout << "\nPlaylist: " << playerName << endl;
        cout << string(50, '=') << endl;
        
        if (playlist.empty()) {
            cout << "Playlist is empty" << endl;
            return;
        }
        
        for (const Media* media : playlist) {
            cout << media->getType() << ": " << media->getTitle()
                 << " (" << media->formatDuration() << ")" << endl;
        }
        
        cout << "\nTotal items: " << playlist.size() << endl;
    }
};

int main() {
    try {
        // Create media player
        MediaPlayer player("Advanced Media Player");
        
        // Add different types of media
        player.addMedia(new Song("Bohemian Rhapsody", "Queen", 354,
                               "A Night at the Opera", "Rock"));
        
        player.addMedia(new Video("C++ Tutorial", "CodeMaster", 600,
                                "1080p", true));
        
        player.addMedia(new Podcast("Tech Talk", "John Doe", 1800,
                                  "Episode 42", "Technology"));
        
        // Display playlist
        player.displayPlaylist();
        
        // Play all media
        player.playAll();
        
        cout << "\nProgram completed successfully" << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
```

## Best Practices

### Override Implementation
1. Use override keyword
2. Match base signature exactly
3. Consider const correctness
4. Call base implementation when needed
5. Document behavior changes

### Virtual Methods
1. Make destructors virtual
2. Use pure virtual for interfaces
3. Provide default implementations
4. Consider final methods
5. Document virtual behavior

### Design Guidelines
1. Keep inheritance simple
2. Override purposefully
3. Maintain LSP
4. Consider alternatives
5. Test thoroughly

## Common Mistakes to Avoid
1. Missing override keyword
2. Signature mismatches
3. Hiding base methods
4. Breaking LSP
5. Forgetting virtual destructors

## Next Steps
- Try the practice exercise
- Experiment with overriding
- Move on to [Part 4: Types of Inheritance]({{ site.baseurl }}/tutorials/module7/part4-types)
