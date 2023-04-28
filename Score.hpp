#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Const.hpp"


class Score
{
private:
    int score ;
    Text text ;
    Font font ;
    void initText();
    void initFont();
public:
    Score();
    ~Score();
    void updateScore();
    void Draw(RenderTarget &target);
    bool isMaxScore() { return this->score >= MAX_SCORE; }

};
