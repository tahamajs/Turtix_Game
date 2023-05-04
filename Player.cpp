#include "Player.hpp"



player::player(int x, int y ) : velocity(0, 0) , m_gravity(0, Xgravity)
{
    this->position.x = x;
    this->position.y = y;
    this->health = 100;
    rect = IntRect(0, 140 ,140, 140);
    texture = new Texture();
    this->texture->loadFromFile("sprite/2728FC_prev_ui.png", rect);
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->position);
    // this->sprite.setScale(-0.4, 0.4);
    // this->sprite.setOrigin(70, 70);
    initAnimation();
    this->loadTextures();
}

void player::initAnimation()
{
    animation = new Animation(sprite, 5,.1,"sprite/16F884_prev_ui.png",140,140);
}


// void Player::initAnimation(){

// }

void player::initMap(Map *map)
{
    this->map = map;
}

player::~player()
{

}

void player::setcollitionSprites(vector<Sprite*> *collitionSprites)
{
    this->collitionSprites = collitionSprites;
}

void player::checkCollisionWithMap()
{
    //jest for test
    if(!map->isCollisionOnTop(sprite) && map->checkCollision(sprite.getGlobalBounds()) != -1 )
    {
        // cout << "collision on top" << endl;
        velocity.y = JUMP_SPEED/4;
    }

    if (map->checkCollision(sprite.getGlobalBounds()) != -1 && map->isCollisionOnLeft(sprite) )
    {
        canleft = false;
        // cout << "collision on left" << endl;
    }else{
        canleft = true;
    }

    if (map->checkCollision(sprite.getGlobalBounds()) != -1 && map->isCollisionOnRight(sprite) )
    {
        canright = false;
        // cout << "collision on right" << endl;
    }else{
        canright = true;
    }
    


    if (map->checkCollision(sprite.getGlobalBounds()) != -1 && map->isCollisionOnTop(sprite) )
    {
        // this->velocity.y = 0;if 
        // cout << "collection " << endl ;
        Ylimit = map->checkCollision(sprite.getGlobalBounds())-sprite.getGlobalBounds().height;
        // cout << "collision " << map->checkCollision(sprite.getGlobalBounds()) << endl;
    }else
    {
        Ylimit = 500;
    }
}
void player::setTexture(int index)
{
    this->sprite.setTexture(*textures[index]);
}

void player::spriteRectUpdate()
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

void player::loadTextures()
{

    for (int i = 0; i < 5; i++)
    {
        textures.push_back(new Texture());
        textures[i]->loadFromFile("sprite/16F884_prev_ui.png", IntRect(i*135,0, 140, 140));
    }

    
}

void player::updateWindowBoundsCollision()
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

void player::Draw(RenderWindow &window)
{
    // cout << Ylimit << "akjealkwejdhlawkejfl" << endl;
    window.draw(this->sprite);
    this->setgravity();
    // spriteRectUpdate();
    checkCollisionWithMap();
    // animation->update(0.1);
    
    
}

void player::move(Event *ev)
{
    position = this->sprite.getPosition();
    if (Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        if (canleft)
        {
            this->position.x -= STEP_SIZE;
            animation->update(0.1);
        }
        // this->position.x -= STEP_SIZE;
        this->sprite.setScale(1, 1);
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        if (canright)
        {
            this->position.x += STEP_SIZE;
            animation->update(0.1);
        }
        // this->position.x += STEP_SIZE;
        this->sprite.setScale(-1, 1);
        
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        if (!m_isJumping)
        {
            m_isJumping = true;
            jump();
        }
    }
    // cout << "move" << endl;
    // if (ev->key.code == Keyboard::Key::A)
    // {
    //     this->position.x -= STEP_SIZE;
    // }
    // if (ev->key.code == Keyboard::Key::D)
    // {
    //     this->position.x += STEP_SIZE;
        
    // }
    // if (ev->key.code == Keyboard::Key::Space)
    // {
    //     this->jump();
    // }
    



    this->sprite.setPosition(this->position);

    // updateWindowBoundsCollision();
    
}

void player::setgravity()
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




void player::jump() {
    velocity.y = -JUMP_SPEED; // Set upward velocity for jump
}

    