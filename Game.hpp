#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Score.hpp"
#include "Player.hpp"
#include "GamePause.hpp"
#include "map.hpp"
#include "star.hpp"
#include "menu.hpp"

using namespace std ;
using namespace sf ;



class Game
{
private:
    void initWindow();
    void initVariables();
    void initPlayer();
    void initStar();
    void initScore();
    void initGamePause();
    void initMap();
    void scoreUpdate();
    void initMenu();
    bool isPause = false;

    float x=0;
    float y=0;


    View view;
    Score *score;
    Texture Background;
    Sprite BackgroundSprite;
    GamePause *gamePause;

    VideoMode videoMode;
    RenderWindow *window;
    Event ev;
    player *player1;
    Menu *menu;
    GameState gameState = GameState::MENU;


    //star
    Star *star;







public:
    void update();
    void render();
    bool running();
    void pollEvents();
    void Draw();
    void PauseGame();
    void PlayGame();
    Map *map;


    

    

    Game();
    ~Game();

};
