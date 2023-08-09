#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"
#include "Score.hpp"

class Star
{
private:
    struct TileStar
    {
        int x;
        int y;
        int type;
        Sprite* sprite;
        int score= 10;

    };

    sf::Vector2f position;
    sf::Texture texture;
    vector<sf::Texture*> textures;
    vector<TileStar> Stars;
    void loadTextures();
    void loadStars();   
    
public:
    void Draw(sf::RenderWindow &window);
    Star();
    ~Star();
    void reset();
    void update();
    int checkCollisionWithPlayer(FloatRect playerRect , Score &_score);


};