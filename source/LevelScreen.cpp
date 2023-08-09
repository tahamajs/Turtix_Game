// #pragma once
#include "../HederFiles/LevelScreen.hpp"


string LevelScreen::getSelectedOption() const {
  return m_options[m_selectedOptionIndex];
}

LevelScreen::LevelScreen(RenderWindow &_window, const sf::Vector2f& position)
  : m_position(position)
  , m_selectedOptionIndex(0)
  , window(&_window)
{
    m_options.push_back("Level 1");
    m_options.push_back("Level 2");
    m_options.push_back("Level 3");
    m_options.push_back("Level 4");
    m_options.push_back("Level 5");
    m_options.push_back("Level 6");
    m_options.push_back("Level 7");
    m_options.push_back("Level 8");
    m_options.push_back("Level 9");
    m_options.push_back("Level 10");

    m_optionTexts.resize(m_options.size());
    m_optionTexts[0].setFillColor(sf::Color::Red);
    m_optionTexts[1].setFillColor(sf::Color::White);
    m_optionTexts[2].setFillColor(sf::Color::White);
    m_optionTexts[3].setFillColor(sf::Color::White);
    m_optionTexts[4].setFillColor(sf::Color::White);
    m_optionTexts[5].setFillColor(sf::Color::White);
    m_optionTexts[6].setFillColor(sf::Color::White);
    m_optionTexts[7].setFillColor(sf::Color::White);
    m_optionTexts[8].setFillColor(sf::Color::White);
    m_optionTexts[9].setFillColor(sf::Color::White);

    m_optionTexts[0].setCharacterSize(60);
    m_optionTexts[0].setString(m_options[0]);
    m_optionTexts[1].setString(m_options[1]);
    m_optionTexts[1].setCharacterSize(60);
    m_optionTexts[2].setString(m_options[2]);
    m_optionTexts[2].setCharacterSize(60);
    m_optionTexts[3].setString(m_options[3]);
    m_optionTexts[3].setCharacterSize(60);
    m_optionTexts[4].setString(m_options[4]);
    m_optionTexts[4].setCharacterSize(60);
    m_optionTexts[5].setString(m_options[5]);
    m_optionTexts[5].setCharacterSize(60);
    m_optionTexts[6].setString(m_options[6]);
    m_optionTexts[6].setCharacterSize(60);
    m_optionTexts[7].setString(m_options[7]);
    m_optionTexts[7].setCharacterSize(60);
    m_optionTexts[8].setString(m_options[8]);
    m_optionTexts[8].setCharacterSize(60);
    m_optionTexts[9].setString(m_options[9]);
    m_optionTexts[9].setCharacterSize(60);


    m_optionTexts[0].setPosition(m_position.x-100, m_position.y);
    m_optionTexts[1].setPosition(m_position.x-100, m_position.y + 50);
    m_optionTexts[2].setPosition(m_position.x-100, m_position.y + 100);
    m_optionTexts[3].setPosition(m_position.x-100, m_position.y + 150);
    m_optionTexts[4].setPosition(m_position.x-100, m_position.y + 200);
    m_optionTexts[5].setPosition(m_position.x-100, m_position.y + 250);
    m_optionTexts[6].setPosition(m_position.x-100, m_position.y + 300);
    m_optionTexts[7].setPosition(m_position.x-100, m_position.y + 350);
    m_optionTexts[8].setPosition(m_position.x-100, m_position.y + 400);
    m_optionTexts[9].setPosition(m_position.x-100, m_position.y + 450);


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
    m_optionTexts[3].setFont(*this->m_font);
    m_optionTexts[4].setFont(*this->m_font);
    m_optionTexts[5].setFont(*this->m_font);
    m_optionTexts[6].setFont(*this->m_font);
    m_optionTexts[7].setFont(*this->m_font);
    m_optionTexts[8].setFont(*this->m_font);
    m_optionTexts[9].setFont(*this->m_font);

}

void LevelScreen::moveUp() {
    m_selectedOptionIndex = (m_selectedOptionIndex + m_options.size() - 1) % m_options.size();
    updateOptionTexts();
}


void LevelScreen::moveDown() {
  m_selectedOptionIndex = (m_selectedOptionIndex + 1) % m_options.size();
  updateOptionTexts();
}

void LevelScreen::render() const {
  window->clear();
  window->draw(*backgroundSprite);
  backgroundSprite->setPosition(m_position.x - 700, m_position.y - 700);
  for (const sf::Text& optionText : m_optionTexts) {
    
    window->draw(optionText);
  }
  window->display();

}

void LevelScreen::update(enum GameState &gameState , Vector2f position) {
    this->m_position = position;
    updateOptionTexts();
    pollEvents(gameState);
    
}

void LevelScreen::updateOptionTexts() {
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

void LevelScreen::pollEvents(enum GameState &gameState) {
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
          case sf::Keyboard::Enter:
            if (getSelectedOption() == "Level 1") {
              cout << "Play" << endl;
              gameState = GameState::PLAYING;
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