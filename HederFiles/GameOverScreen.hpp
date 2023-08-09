#pragma once    
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"
#include "AudioClip.hpp"


class GameOverScreen {
public:
    GameOverScreen(sf::RenderWindow& window, int score) :
        m_window(window),
        m_score(score)
    {
        m_font.loadFromFile("arial.ttf");
        m_gameOverText.setFont(m_font);
        m_gameOverText.setString("Game Over!");
        m_gameOverText.setCharacterSize(50);
        m_gameOverText.setPosition(100, 100);

        m_scoreText.setFont(m_font);
        m_scoreText.setString("Score: " + std::to_string(m_score));
        m_scoreText.setCharacterSize(30);
        m_scoreText.setPosition(150, 200);

        m_restartText.setFont(m_font);
        m_restartText.setString("Press R to restart");
        m_restartText.setCharacterSize(20);
        m_restartText.setPosition(200, 300);
    }

    void display() {
        m_window.draw(m_gameOverText);
        m_window.draw(m_scoreText);
        m_window.draw(m_restartText);
    }

    bool handleInput(sf::Event event) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
            return true;
        }
        return false;
    }

private:
    sf::RenderWindow& m_window;
    int m_score;
    sf::Font m_font;
    sf::Text m_gameOverText;
    sf::Text m_scoreText;
    sf::Text m_restartText;
};