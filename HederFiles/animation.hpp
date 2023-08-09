#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Const.hpp"
#include <vector>





class Animation {
public:
    Animation(sf::Sprite& _sp , int numFrames,int _colNums , float frameDuration , string _path , int _frameWidth , int _frameHight) :
        m_sprite(&_sp),
        m_numFrames(numFrames),
        m_currentFrame(0),
        m_frameDuration(frameDuration),
        m_elapsedTime(0),
        m_frameWidth(_frameWidth),
        m_frameHight(_frameHight),
        path(_path),
        colNums(_colNums)
    {
        initTexture();
        m_sprite->setTexture(*textures[index]);
    }

    void update(float deltaTime) {
        m_elapsedTime += deltaTime;
        
        if (m_elapsedTime >= m_frameDuration) {
            // cout << "Frame duration: " << index << endl;
            m_elapsedTime -= m_frameDuration;
            m_currentFrame = (m_currentFrame + 1) % m_numFrames;
            m_sprite->setTexture(*textures[index]);
            index ++;
            if (index == m_numFrames)
            {
                index = 0;
            }
        }

    } 


    void initTexture() {
        loadTextures();
    }


    void loadTextures()
    {
        int j_ = 0;
        int i_ = 0;
        for (int i = 0; i < m_numFrames; i++)
        {
            Texture *texture = new Texture();
            textures.push_back(texture);
            if (i_ ==  colNums-1)
            {
                i_=0;
                j_++;
            }
            else
            {
                i_++;
            }

            
        }
    }

private:
    
    sf::Sprite *m_sprite;
    int m_numFrames;
    int m_currentFrame;
    float m_frameDuration;
    float m_elapsedTime;
    int m_frameWidth;
    int m_frameHight ;
    int index = 0;
    int colNums = 0;
    vector<Texture*> textures;

    string path;

};