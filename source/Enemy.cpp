#include "../HederFiles/Enemy.hpp"



Enemy::Enemy(int x, int y  ,GameState *_gameState) : velocity(10, 0) , m_gravity(0, Xgravity)
{
    gameState = _gameState;
    MainPosition.x = x;
    MainPosition.y = y;
    xRightMove = x+RADIOS_OF_MOVEMENT;
    xLeftMove = x-RADIOS_OF_MOVEMENT;
    this->position.x = x;
    this->position.y = y;
    this->velocity.x = 2;
    this->health = 100;
    rect = IntRect(0, 0 ,83, 83);
    texture = new Texture();
    this->texture->loadFromFile("sprite/Enemy_1.png", rect);
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->position);
    this->sprite.setScale(1.2, 1.2);
    this->sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    initAnimation();
    
    this->loadTextures();
}

void Enemy::initAnimation()
{
    animation = new Animation(sprite,36 ,6,.2,"sprite/Enemy_1.png",83,83);
}



void Enemy::initMap(Map *map)
{
    this->map = map;
}

Enemy::~Enemy()
{

}

bool Enemy::isCollisionWithPlayerNONTOP()
{
    if (sprite.getGlobalBounds().intersects(Player->getSprite().getGlobalBounds()))
    {
        if (Player->getSprite().getGlobalBounds().top + Player->getSprite().getGlobalBounds().height < sprite.getGlobalBounds().top + sprite.getGlobalBounds().height/2)
        {
            return true;
        }
    }
    return false;
}

bool Enemy::isCollisionWithPlayerTop()
{
    if (sprite.getGlobalBounds().intersects(Player->getSprite().getGlobalBounds()))
    {
        if (Player->getSprite().getGlobalBounds().top + Player->getSprite().getGlobalBounds().height > sprite.getGlobalBounds().top + sprite.getGlobalBounds().height/2)
        {
            return true;  
        }
    }
    return false;
}

void Enemy::checkCollisionWithMap()
{
    if ((Ylimit = map->checkCollision(sprite.getGlobalBounds())) != -1 && map->isCollisionOnTop(sprite) )
    {
        Ylimit = map->checkCollision(sprite.getGlobalBounds()) - sprite.getGlobalBounds().height/4;
    }else
    {
        Ylimit = ENEMY_YLIMIT;
    }
}
void Enemy::setTexture(int index)
{
    this->sprite.setTexture(*textures[index]);
}

void Enemy::spriteRectUpdate()
{
    if (index == textures.size() - 1)
    {
        index = 0;
    }
    else
    {
        index++;
    }
    setTexture(index);
    
    
}


void Enemy::initPlayer(player *_player)
{
    Player = _player;
}

void Enemy::loadTextures()
{


    for (int i = 0; i < 5; i++)
    {
        textures.push_back(new Texture());
        textures[i]->loadFromFile("sprite/16F884_prev_ui.png", IntRect(i*135,0, 140, 140));
    }

    
}

void Enemy::updateWindowBoundsCollision()
{
    if (this->position.x < 0)
    {
        this->position.x = 0;
    }
    if (this->position.x + this->sprite.getGlobalBounds().width > WINDOW_WIDTH)
    {
        this->position.x = WINDOW_WIDTH - this->sprite.getGlobalBounds().width;
    }

}

void Enemy::Draw(RenderWindow &window)
{
    window.draw(this->sprite);
    this->setgravity();
    checkCollisionWithMap();
    animation->update(0.1);
    this->move();
    
    
}

void Enemy::move()
{
    if (position.x < xLeftMove)
    {
        position.x = xLeftMove;
        velocity.x = -velocity.x;
        this->sprite.setScale(-1, 1);
    }
    else if (position.x + sprite.getGlobalBounds().width > xRightMove)
    {
        position.x = xRightMove - sprite.getGlobalBounds().width;
        velocity.x = -velocity.x;
        this->sprite.setScale(1, 1);
    }
    position.x += velocity.x;
    sprite.setPosition(position);
    
}

void Enemy::setgravity()
{
    position = sprite.getPosition();
    velocity.y += m_gravity.y;
    position.y += velocity.y;
    if (position.y > Ylimit)
    {
        position.y = Ylimit;
        velocity.y = 0;
        m_isJumping = false;
    }
    sprite.setPosition(position);
}


void Enemy::reset()
{
    position = MainPosition;
    this->sprite.setPosition(this->position);
}