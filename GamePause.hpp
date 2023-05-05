#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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
    Text *text2;
    Text *text3;

    RectangleShape *button;
    RectangleShape *button2;
    RectangleShape *button3;
    Vector2f position;


public:
    GamePause(RenderWindow& window );
    ~GamePause();
    void update(enum GameState &gameStat , Vector2f position);
    void render();
    void pollEvents(enum GameState &gameState);

};