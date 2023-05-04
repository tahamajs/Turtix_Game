#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Const.hpp"


class Enemy
{
private:
    sf::Vector2f position;
    sf::Texture texture;
    sf::Sprite sprite;
    void initTexture();
    void initSprite();
    void initPosition();
    void initVariables();
    void updateWindowBoundsCollision();
public:
    Enemy(float x, float y);
    ~Enemy();
    void Draw(sf::RenderWindow &window);

    void update();

};