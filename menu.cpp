// #pragma once
#include "menu.hpp"


string Menu::getSelectedOption() const {
  return m_options[m_selectedOptionIndex];
}

Menu::Menu(RenderWindow &_window, const sf::Vector2f& position)
  : m_position(position)
  , m_selectedOptionIndex(0)
  , window(&_window)
{
    m_options.push_back("Play");
    m_options.push_back("Exit");

}

void Menu::moveUp() {
    m_selectedOptionIndex = (m_selectedOptionIndex + m_options.size() - 1) % m_options.size();
    updateOptionTexts();
}


void Menu::moveDown() {
  m_selectedOptionIndex = (m_selectedOptionIndex + 1) % m_options.size();
  updateOptionTexts();
}

void Menu::render() const {
  // Draw the menu to the window
  for (const sf::Text& optionText : m_optionTexts) {
    window->draw(optionText);
  }

}

void Menu::update(enum GameState &gameState) {
    pollEvents(gameState);
    updateOptionTexts();
}

void Menu::updateOptionTexts() {
  // Update the appearance of the menu options based on the selected option
  for (int i = 0; i < m_options.size(); ++i) {
    sf::Text& optionText = m_optionTexts[i];
    optionText.setString(m_options[i]);
    optionText.setFillColor(sf::Color::White);
    optionText.setPosition(m_position.x, m_position.y + i * 40.f);
    if (i == m_selectedOptionIndex) {
      optionText.setStyle(sf::Text::Bold);
    } else {
      optionText.setStyle(sf::Text::Regular);
    }
  }
}

void Menu::pollEvents(enum GameState &gameState) {
  sf::Event event;
  while (window->pollEvent(event)) {
    switch (event.type) {
      case sf::Event::KeyReleased:
        switch (event.key.code) {
          case sf::Keyboard::Up:
            moveUp();
            break;
          case sf::Keyboard::Down:
            moveDown();
            break;
          case sf::Keyboard::Return:
            if (getSelectedOption() == "Play") {
              gameState = GameState::PLAYING;
            } else if (getSelectedOption() == "Exit") {
              window->close();
            }
            
            break;
        }
        break;
      case sf::Event::Closed:
        window->close();
        break;
    }
  }
}