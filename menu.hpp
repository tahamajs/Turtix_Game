#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"





class Menu {
public:
    Menu(RenderWindow &_window, const sf::Vector2f& position);

  void moveUp();
  void moveDown();
  std::string getSelectedOption() const;
  void render() const;
  void update(enum GameState &gameState, Vector2f position);
  

private:
  sf::Vector2f m_position;
  std::vector<std::string> m_options;
  std::vector<sf::Text> m_optionTexts;
  int m_selectedOptionIndex;
  RenderWindow *window;
  Font *m_font;

  void updateOptionTexts();
  void pollEvents(enum GameState &gameState);

};

