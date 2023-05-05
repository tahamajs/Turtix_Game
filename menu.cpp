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
    m_optionTexts.resize(m_options.size());
    m_optionTexts[0].setFillColor(sf::Color::Red);
    m_optionTexts[1].setFillColor(sf::Color::White);
    m_optionTexts[0].setString(m_options[0]);
    m_optionTexts[1].setString(m_options[1]);
    m_optionTexts[0].setPosition(m_position.x, m_position.y);
    m_optionTexts[1].setPosition(m_position.x, m_position.y + 50);

    this->m_font = new Font();
    if (!this->m_font->loadFromFile("fonts/MenuFont.otf")) {
      cout << "Error loading font" << endl;
    }else{
      cout << "Font loaded" << endl;
    }
    m_optionTexts[0].setFont(*this->m_font);
    m_optionTexts[1].setFont(*this->m_font);


    // cout << "Menu constructor" << endl;

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
  window->clear();
  // cout << "Menu render" << endl;
  for (const sf::Text& optionText : m_optionTexts) {
    
    window->draw(optionText);
  }
  window->display();

}

void Menu::update(enum GameState &gameState) {
    updateOptionTexts();
    pollEvents(gameState);
    
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
            cout << "Up" << endl;
            moveUp();
            break;
          case sf::Keyboard::Down:
            cout << "Down" << endl;
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