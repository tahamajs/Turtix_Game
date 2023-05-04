#include "Enemys.hpp"

Enemys::Enemys(float x, float y)
{
    position.x = x;
    position.y = y;
    this->initEnemys();
}

Enemys::~Enemys()
{
    for (size_t i = 0; i < this->enemys.size(); i++)
    {
        delete this->enemys[i];
    }
}

void Enemys::initEnemys()
{
    // this->enemys.push_back(new Player(this->position.x, this->position.y));
}