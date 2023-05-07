#include "../HederFiles/TurtleChile.hpp"




TurtleChile::TurtleChile(int x, int y  ,GameState *_gameState) : velocity(10, 2) , m_gravity(0, Xgravity)
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
    rect = IntRect(0, 0 ,140, 140);
    texture = new Texture();
    this->texture->loadFromFile("sprite/Chile.png", rect);
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->position);
    this->sprite.setScale(-.8, .8);
    this->sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    initAnimation();
    
    this->loadTextures();
}

void TurtleChile::initAnimation()
{
    animationFree = new Animation(sprite,16 ,6,.2,"sprite/chileFree.png",100,100);
    animation = new Animation(sprite,10 ,5,.2,"sprite/Chile.png",140,140);

}



void TurtleChile::initMap(Map *map)
{
    this->map = map;
}

TurtleChile::~TurtleChile()
{

}

bool TurtleChile::isCollisionWithPlayerNONTOP()
{
    if (sprite.getGlobalBounds().intersects(Player->getSprite().getGlobalBounds()))
    {
        if (Player->getSprite().getGlobalBounds().top + Player->getSprite().getGlobalBounds().height < sprite.getGlobalBounds().top + sprite.getGlobalBounds().height/2)
        {
            isColisionWithPlayer = true;
            cout << "isColisionWithPlayer" << endl;
            sprite.setTextureRect(IntRect(0, 0, 100, 100));
            return true;

        }
    }
    return false;
}

bool TurtleChile::isCollisionWithPlayerTop()
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

void TurtleChile::checkCollisionWithMap()
{
    if ((Ylimit = map->checkCollision(sprite.getGlobalBounds())) != -1 && map->isCollisionOnTop(sprite) )
    {
        Ylimit = map->checkCollision(sprite.getGlobalBounds()) - sprite.getGlobalBounds().height/4;
    }else
    {
        Ylimit = 7000;
    }
}
void TurtleChile::setTexture(int index)
{
    this->sprite.setTexture(*textures[index]);
}

void TurtleChile::spriteRectUpdate()
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


void TurtleChile::initPlayer(player *_player)
{
    Player = _player;
}

void TurtleChile::loadTextures()
{


    for (int i = 0; i < 5; i++)
    {
        textures.push_back(new Texture());
        textures[i]->loadFromFile("sprite/16F884_prev_ui.png", IntRect(i*135,0, 140, 140));
    }
}

void TurtleChile::updateWindowBoundsCollision()
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

void TurtleChile::Draw(RenderWindow &window)
{
    window.draw(this->sprite);
    this->setgravity();
    // spriteRectUpdate();
    checkCollisionWithMap();
    if(isColisionWithPlayer){
        animationFree->update(0.1);
        this->move();
    }else{
        animation->update(0.1);
        isCollisionWithPlayerNONTOP();
    }
    
    
    
    
    
    
}

bool TurtleChile::isCollitionOnGate()
{
    if (map->WiGateCollision(sprite))
    {
        return true;
    }
    return false;
}

void TurtleChile::move()
{

    // velocity.x = ;
    position.x += velocity.x;
    sprite.setPosition(position);
    
}

void TurtleChile::setgravity()
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




void TurtleChile::reset()
{
    position = MainPosition;
    this->sprite.setPosition(this->position);
}