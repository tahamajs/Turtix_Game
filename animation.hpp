#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Const.hpp"



class Animation {
public:
    Animation(sf::Texture& texture, int numFrames, float frameDuration) :
        m_texture(texture),
        m_numFrames(numFrames),
        m_currentFrame(0),
        m_frameDuration(frameDuration),
        m_elapsedTime(0),
        m_frameWidth(texture.getSize().x / numFrames)
    {
        initTexture();
        m_sprite.setTexture(m_texture);

        m_sprite.setTextureRect(sf::IntRect(0, 0, m_frameWidth, m_texture.getSize().y));
    }

    void update(float deltaTime) {
        m_elapsedTime += deltaTime;
        if (m_elapsedTime >= m_frameDuration) {
            m_elapsedTime -= m_frameDuration;
            m_currentFrame = (m_currentFrame + 1) % m_numFrames;
            m_sprite.setTextureRect(sf::IntRect(m_currentFrame * m_frameWidth, 0, m_frameWidth, m_texture.getSize().y));
        }
    }

    void setPosition(float x, float y) {
        m_sprite.setPosition(x, y);
    }

    void initTexture() {
        if (!m_texture.loadFromFile("sprite/16F884_prev_ui.png")) {
            std::cout << "Error::Player::Could not load texture file." << std::endl;
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprite, states);
    }


private:
    sf::Texture& m_texture;
    sf::Sprite m_sprite;
    int m_numFrames;
    int m_currentFrame;
    float m_frameDuration;
    float m_elapsedTime;
    int m_frameWidth;
};