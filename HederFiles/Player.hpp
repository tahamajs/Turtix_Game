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



class player
{
private:
    void loadTextures();
    void setTexture(int index);
    void updateWindowBoundsCollision();
    void setgravity();
    void initAnimation();
    void initAudioClips();

    Vector2f position;
    Vector2f velocity;
    int health;
    Sprite sprite;
    IntRect rect;
    Texture *texture ;
    vector<Texture*> textures;
    Vector2f m_gravity;
    bool m_isJumping = false;
    Map *map;
    float Ylimit = DEAD_Y_DIRECTION;
    vector<Sprite*> *collitionSprites;
    bool canleft = true;
    bool canright = true;
    Animation *animation;
    vector<AudioClip*> audioClips;
    Vector2f MainPosition;
    GameState *gameState;
    int time = 0;
    int index = 0;
    


public:
    player(int x, int y  , GameState *gameState);
    ~player();
    bool checkCollisionWithMap();
    // void initAnimation();
    Vector2f getposition() { return this->position; }
    void Draw(RenderWindow &window);
    void setcollitionSprites(vector<Sprite*> *collitionSprites);
    void move(Event *ev);
    void setPosition(Vector2f _position);
    void initMap(Map *map);
    Sprite getSprite() { return this->sprite; }
    void spriteRectUpdate();
    void reset();
    void decreaseHealth(int amount);
    int getHealth();
    void showHelthBar(RenderWindow &window,Vector2f _position);
    void jump();


};

