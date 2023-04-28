#include "Enemi.hpp"


enemie::enemie(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
    this->health = 100;
    this->texture.loadFromFile("donkey.png", IntRect(0, 0, 2000, 2000));
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position);

}

enemie::~enemie()
{
}

void enemie::updateWindowBoundsCollision()
{
    if (this->position.x < 0)
    {
        this->position.x = 0;
    }
    if (this->position.x + this->sprite.getGlobalBounds().width > WINDOW_WIDTH)
    {
        this->position.x = WINDOW_WIDTH - this->sprite.getGlobalBounds().width;
    }
    if (this->position.y < 0)
    {
        this->position.y = 0;
    }
    if (this->position.y + this->sprite.getGlobalBounds().height > WINDOW_HEIGHT)
    {
        this->position.y = WINDOW_HEIGHT - this->sprite.getGlobalBounds().height;
    }
}

void enemie::Draw(RenderWindow &window)
{
    window.draw(this->sprite);
}

void enemie::move(Event *ev)
{
    //random move
    int random = rand() % 4;    
    if (random == 0)
    {
        this->position.x -= STEP_SIZE;
    }
    if (random == 1)
    {
        this->position.x += STEP_SIZE;
    }
    if (random == 2)
    {
        this->position.y -= STEP_SIZE;
    }
    if (random == 3)
    {
        this->position.y += STEP_SIZE;
    }
    this->sprite.setPosition(this->position);
    this->updateWindowBoundsCollision();
}
