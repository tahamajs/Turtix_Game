#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Const.hpp"




class enemie
{
private:
    Vector2f position;
    int health = DEFAULT_HEALTH;
    Texture texture;
    Sprite sprite;
    void updateWindowBoundsCollision();


public:
    enemie(int x, int y);
    ~enemie();
    void Draw(RenderWindow &window);
    void move(Event *ev);
    void minusHealth(int damage) { this->health -= damage; }
    bool isAlive() { return this->health > 0; }
    Sprite getSprite() { return this->sprite; }
};

