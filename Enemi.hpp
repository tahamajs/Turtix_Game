#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Const.hpp"
#include "player.hpp"




class enemie : public Player
{
private:
    
        Vector2f position;
        Vector2f velocity;
        int health;
        // Texture *texture;
        Sprite sprite;
        IntRect rect;
        Texture *texture ;
        vector<Texture*> textures;
        void loadTextures();
        void setTexture(int index);
        void updateWindowBoundsCollision();
        void jump();
        void setgravity();
        Vector2f m_gravity;
        bool m_isJumping = false;
        Map *map;
        float Ylimit = 600;
        vector<Sprite*> *collitionSprites;
        bool canleft = true;
        bool canright = true;
        // Animation animation;
    
        
        int index = 0;
        
    
        void checkCollisionWithMap();
        // void initAnimation();
        Vector2f getposition() { return this->position; }
        void Draw(RenderWindow &window);
        void setcollitionSprites(vector<Sprite*> *collitionSprites);
        void move(Event *ev);
        void initMap(Map *map);
        Sprite getSprite() { return this->sprite; }
        void spriteRectUpdate();
public:

};

