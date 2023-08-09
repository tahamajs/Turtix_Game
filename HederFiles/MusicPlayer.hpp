#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class MusicPlayer {
public:
    MusicPlayer();
    MusicPlayer(string _filePath, float volume = 100, float pitch= 1);
    void setVolume(float volume);
    void setPitch(float pitch);
    void setLoop(bool loop);
    void play();
    void pause();
    void stop();
    bool isPlaying() const;
    void loadSound();
    
private:
    sf::Sound *m_sound;
    sf::SoundBuffer *m_buffer;
    bool m_loop;
    string filePath;
};