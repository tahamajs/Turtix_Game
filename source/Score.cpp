
#include "../HederFiles/Score.hpp"


Score::Score()
{
    this->score = 0 ;
    this->initFont();
    this->initText();
}

Score::~Score()
{

}

void Score::initFont()
{
    if(!this->font.loadFromFile("fonts/BrunoAceSC-Regular.ttf"))
    {
        cout << "ERROR::GAME::INITFONT::Could not load font" << endl ;
    }
}  

void Score::initText()
{
    this->text.setFont(this->font);
    this->text.setCharacterSize(30);
    this->text.setFillColor(Color::White);
    this->text.setString("Score: " + to_string(this->score));
}

void Score::updateScore()
{
    this->score += SCORE_SI ;
    this->text.setString("Score: " + to_string(this->score));
}

void Score::increaseScore(int score)
{
    this->score += score ;
    this->text.setString("Score: " + to_string(this->score));
}

void Score::Draw(RenderTarget &target , Vector2f position)
{
    this->text.setPosition(position.x -500, position.y -300);
    target.draw(this->text);
}


void Score::reset()
{
    this->score = 0 ;
    this->text.setString("Score: " + to_string(this->score));
}