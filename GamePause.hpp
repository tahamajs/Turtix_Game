#include <SFML/Graphics.hpp>
#include <iostream>
#include "Const.hpp"

class GamePause
{
private:
    RenderWindow *pause_window;
    Event ev;
    VideoMode videoMode;

    void initWindow(RenderWindow *window);
    void initVariables();
    void initBackground();
    void initButtons();
    void initText();
    void initFont();


    Texture *background;
    Sprite *backgroundSprite;
    Font *font;
    Text *text;
    RectangleShape *button;


public:
    GamePause(RenderWindow *window);
    ~GamePause();
    void update(enum GameState &gameState);
    void render();
    void pollEvents(enum GameState &gameState);
};