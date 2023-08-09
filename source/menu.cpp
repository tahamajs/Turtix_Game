// #pragma once
#include "../HederFiles/menu.hpp"


string Menu::getSelectedOption() const {
  return m_options[m_selectedOptionIndex];
}

Menu::Menu(RenderWindow &_window, const sf::Vector2f& position)
  : m_position(position)
  , m_selectedOptionIndex(0)
  , window(&_window)
{
    m_options.push_back("Start New Game");
    m_options.push_back("Exit");
    m_options.push_back("Levels");
    m_optionTexts.resize(m_options.size());
    m_optionTexts[0].setFillColor(sf::Color::Red);
    m_optionTexts[1].setFillColor(sf::Color::White);
    m_optionTexts[2].setFillColor(sf::Color::White);

    m_optionTexts[0].setCharacterSize(60);
    m_optionTexts[0].setString(m_options[0]);
    m_optionTexts[1].setString(m_options[1]);
    m_optionTexts[1].setCharacterSize(60);
    m_optionTexts[2].setString(m_options[2]);
    m_optionTexts[2].setCharacterSize(60);
    m_optionTexts[0].setPosition(m_position.x-100, m_position.y);
    m_optionTexts[1].setPosition(m_position.x-100, m_position.y + 50);
    m_optionTexts[2].setPosition(m_position.x-100, m_position.y + 100);

    Bacground = new Texture();
    Bacground->loadFromFile("sprite/BA.png", IntRect(0, 0, 1200, 2000));
    backgroundSprite = new Sprite(*Bacground);
    this->m_font = new Font();
    if (!this->m_font->loadFromFile("fonts/MenuFont.otf")) {
      cout << "Error loading font" << endl;
    }else{
      cout << "Font loaded" << endl;
    }
    m_optionTexts[0].setFont(*this->m_font);
    m_optionTexts[1].setFont(*this->m_font);
    m_optionTexts[2].setFont(*this->m_font);

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
  window->draw(*backgroundSprite);
  backgroundSprite->setPosition(m_position.x - 700, m_position.y - 700);
  for (const sf::Text& optionText : m_optionTexts) {
    
    window->draw(optionText);
  }
  window->display();

}

void Menu::update(enum GameState &gameState , Vector2f position) {
    this->m_position = position;
    updateOptionTexts();
    pollEvents(gameState);
    
}

void Menu::updateOptionTexts() {
  // Update the appearance of the menu options based on the selected option
  for (int i = 0; i < m_options.size(); ++i) {
    sf::Text& optionText = m_optionTexts[i];
    optionText.setString(m_options[i]);
    optionText.setFillColor(sf::Color::White);
    optionText.setPosition(m_position.x-100, m_position.y + i * 60.f - 100);
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
            // cout << "Up" << endl;
            moveUp();
            break;
          case sf::Keyboard::Down:
            // cout << "Down" << endl;
            moveDown();
            break;
          case sf::Keyboard::Enter:
            if (getSelectedOption() == "Start New Game") {
              cout << "Play" << endl;
              gameState = GameState::RESTART;
            } else if (getSelectedOption() == "Exit") {
              window->close();
            } else if (getSelectedOption() == "Levels") {
              cout << "Levels" << endl;
              gameState = GameState::LEVELS;
            }
            
            break;
        }
        break;
      case sf::Event::Closed:
        window->close();
        break;
      case sf::Event::MouseMoved:
        if (event.mouseMove.x > m_position.x && event.mouseMove.x < m_position.x + 100 && event.mouseMove.y > m_position.y && event.mouseMove.y < m_position.y + 50)
        {
          m_selectedOptionIndex = 0;
          updateOptionTexts();
        }
        
        break;
    }
  }
}