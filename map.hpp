#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include "Const.hpp"


class Map {
public:
    struct Tile {
        int x;
        int y;
        int type;
        Sprite* sprite;
        bool moveable = true;
        bool deadly = false;
    };



    Map(int size);
    ~Map();
    void draw(RenderWindow& window);
    void update();
    Vector2f getSize();
    void loadTextures(const std::string& path);
    void loadTiles(const std::string& path);
    float checkCollision(FloatRect rect);


    

private:
    std::vector<Tile> tiles_;
    std::vector<Texture*> textures_;
    int size_;
};



























































