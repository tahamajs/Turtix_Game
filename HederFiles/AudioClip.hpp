#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class AudioClip
{
public:
    AudioClip(const std::string& _filePath, float volume = 100.f, float pitch = 1.f)
    {
        m_buffer = new sf::SoundBuffer();
        m_sound = new sf::Sound();
        m_volume = volume;
        m_pitch = pitch;
        filePath = _filePath;
        if (!m_buffer->loadFromFile(filePath))
        {
            std::cout << "Error loading sound" << std::endl;
            abort();
        }
        m_sound->setBuffer(*m_buffer);
    }

    void play()
    {
        m_sound->setVolume(m_volume);
        m_sound->setPitch(m_pitch);
        m_sound->play();
    }

    void stop()
    {
        m_sound->stop();
    }

    void pause()
    {
        m_sound->pause();
    }

    void resume()
    {
        m_sound->play();
    }

    void setVolume(float volume)
    {
        m_volume = volume;
    }

    void setPitch(float pitch)
    {
        m_pitch = pitch;
    }

private:
    sf::SoundBuffer *m_buffer;
    sf::Sound *m_sound;
    float m_volume;
    float m_pitch;
    string filePath;
};