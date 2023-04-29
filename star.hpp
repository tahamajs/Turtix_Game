#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"

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

    // void updateWindowBoundsCollision();
    void loadTextures();
    void loadStars();
    
    
public:
    void Draw(sf::RenderWindow &window);
    Star();
    ~Star();
    
    void update();
    bool checkCollisionWithPlayer(FloatRect playerRect);


};