#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Const.hpp"
#include <vector>
#include "map.hpp"
#include "animation.hpp"
#include "AudioClip.hpp"
#include <random>
#include "Player.hpp"


class TurtleChile
{
private:

    Vector2f position;
    Vector2f velocity;
    int health;
    Sprite sprite;
    IntRect rect;
    Texture *texture ;
    vector<Texture*> textures;
    void loadTextures();
    void setTexture(int index);
    void updateWindowBoundsCollision();
    void setgravity();
    void initAnimation();


    Vector2f m_gravity;
    bool m_isJumping = false;
    Map *map;
    float Ylimit = 7000;
    vector<Sprite*> *collitionSprites;
    bool canleft = true;
    bool canright = true;
    Animation *animation;
    vector<AudioClip*> audioClips;
    Vector2f MainPosition;
    GameState *gameState;
    int xRightMove = 0;
    int xLeftMove = 100;
    player *Player;
    Animation *animationFree;
    bool isColisionWithPlayer = false;
    int index = 0;
    

public:
    TurtleChile(int x, int y  , GameState *gameState);
    ~TurtleChile();
    void checkCollisionWithMap();
    // void initAnimation();
    Vector2f getposition() { return this->position; }
    void Draw(RenderWindow &window);
    void move();
    void initMap(Map *map);
    Sprite getSprite() { return this->sprite; }
    void spriteRectUpdate();
    void reset();
    void initPlayer(player *player);
    bool isCollisionWithPlayerNONTOP();
    bool isCollisionWithPlayerTop();
    bool isCollitionOnGate();



};

