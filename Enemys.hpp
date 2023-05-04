#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include "player.hpp"
#include <vector>   
#include <string>


class Enemys
{
private:
    
    void initText();
    void initFont();
    Vector2f position;
    vector<Player*> enemys;

public:
    Enemys(float x, float y);
    ~Enemys();
    void initEnemys();

    void Draw(RenderTarget &target);

};