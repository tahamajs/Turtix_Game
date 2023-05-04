#include "Enemi.hpp"

Enemi::Enemi(float x, float y)
{
    position.x = x;
    position.y = y;
    this->initEnemi();
}

Enemi::~Enemi()
{
    Sprite.clear();


}

void Enemi::initEnemi()
{
    this->initTexture();
    this->initSprite();
    this->initPosition();
    this->initVariables();
}

void Enemi::initTexture()
{
    if (!texture.loadFromFile("Textures/Enemy.png"))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << std::endl;
    }
}

void Enemi::initSprite()
{
    sprite.setTexture(texture);
    sprite.scale(0.5f, 0.5f);
}

void Enemi::initPosition()
{
    sprite.setPosition(position);
}

void Enemi::initVariables()
{
    this->velocity.x = 0.f;
    this->velocity.y = 0.f;
    this->maxVelocity = 15.f;
    this->acceleration = 1.f;
    this->deceleration = 0.5f;
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
}

