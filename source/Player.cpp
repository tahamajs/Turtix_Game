#include "../HederFiles/Player.hpp"



player::player(int x, int y  ,GameState *_gameState) : velocity(0, 0) , m_gravity(0, Xgravity)
{
    gameState = _gameState;
    MainPosition.x = x;
    MainPosition.y = y;
    this->position.x = x;
    this->position.y = y;
    this->health = 100;
    rect = IntRect(0, 100 ,100, 100);
    texture = new Texture();
    this->texture->loadFromFile("sprite/2728FC_prev_ui.png", rect);
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->position);
    // this->sprite.setScale(-0.4, 0.4);
    this->sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2);
    initAnimation();
    this->loadTextures();
    initAudioClips();
}

void player::initAnimation()
{
    animation = new Animation(sprite,16 ,5,.1,"sprite/MainPicture.png",96,96);
}


void player::initAudioClips()
{
    AudioClip *audioClip = new AudioClip("Audio/JumpSound.wav");
    audioClips.push_back(audioClip);
}

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

bool player::checkCollisionWithMap()
{

    if(map->isDeadly(sprite.getGlobalBounds()))
    {
        cout << "collision on deadly" << endl;
        // *gameState = GameState::DEAD ;
        this->health -= 10;
        if (this->health < 0)
        {
            // *gameState = GameState::GAME_OVER;
            return true;
        }
        // sprite.setPosition(position.x, position.y-100);
        velocity.y = -JUMP_SPEED/2;
        return false;
    }
    //jest for test
    if(map->GateCollision(this->sprite) != -1)
    {
        cout << "collision on gate" << endl;
        Ylimit= map->GateCollision(this->sprite);
        return false;
    }

    if (map->WiGateCollision(this->sprite))
    {
        cout << "collision on gate" << endl;
        
        *gameState = GameState::WIN ;
        // Ylimit = map->WiGateCollision(this->sprite);
        return false;
    }
    

    if(!map->isCollisionOnTop(sprite) && map->checkCollision(sprite.getGlobalBounds()) != -1 )
    {
        // cout << "collision on top" << endl;
        velocity.y = JUMP_SPEED/4;
    }
    

    if (map->checkCollision(sprite.getGlobalBounds()) != -1 && map->isCollisionOnLeft(sprite) )
    {
        canleft = false;
        cout << "collision on left" << endl;
    }else{
        canleft = true;
    }

    if (map->checkCollision(sprite.getGlobalBounds()) != -1 && map->isCollisionOnRight(sprite) )
    {
        canright = false;
        cout << "collision on right" << endl;
    }else{
        canright = true;
    }
    


    if ((Ylimit = map->checkCollision(sprite.getGlobalBounds())) != -1 && map->isCollisionOnTop(sprite) )
    {
        // this->velocity.y = 0;if 
        // cout << "collection " << endl ;
        Ylimit = map->checkCollision(sprite.getGlobalBounds())-sprite.getGlobalBounds().height/2;
        // cout << "collision " << map->checkCollision(sprite.getGlobalBounds()) << "  " << Ylimit<<  endl;

        // Ylimit = map->checkCollision(sprite.getGlobalBounds());
    }else
    {
        Ylimit = DEAD_Y_DIRECTION;
    }
    return false;
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

void player::decreaseHealth(int amount)
{
    time ++;
    if (time < 100)
    {
        return;
    }
    this->health -= amount;
    if (this->health < 0)
    {
        *gameState = GameState::GAME_OVER;
    }
}

int player::getHealth()
{
    return this->health;
}

void player::Draw(RenderWindow &window)
{
    // cout << Ylimit << "akjealkwejdhlawkejfl" << endl;
    window.draw(this->sprite);
    this->setgravity();
    // spriteRectUpdate();
    // checkCollisionWithMap();
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
            this->sprite.setScale(1, 1);

        }

        // this->position.x -= STEP_SIZE;
        
        // sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().width);

    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        if (canright)
        {
            this->position.x += STEP_SIZE;
            this->sprite.setScale(-1, 1);
            animation->update(0.1);
            if (sprite.getScale()!=Vector2f(-1,1))
            {
                position.x += sprite.getGlobalBounds().width;
            }
            

        }
        // this->position.x += STEP_SIZE;
        

        // sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().width);
        
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        if (!m_isJumping)
        {
            m_isJumping = true;
            audioClips[0]->play();
            jump();
        }
    }




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

void player::showHelthBar(RenderWindow &window, Vector2f _position)
{
    RectangleShape healthBar;
    float healthRatio = static_cast<float>(health) / MAX_HEALTH;
    healthBar.setPosition(_position.x-300, _position.y-280);
    healthBar.setSize(Vector2f(this->health, 10));
    sf::Color healthFillColor(255, 0, 0);
    sf::Color healthOutlineColor(0, 0, 0);
    healthBar.setSize(sf::Vector2f(healthRatio * 200, 20));
    healthBar.setFillColor(healthFillColor);
    healthBar.setOutlineThickness(2);
    healthBar.setOutlineColor(healthOutlineColor);
    window.draw(healthBar);


    // window.draw(healthBar);
}

void player::setPosition(Vector2f _position)
{
    this->position = _position;
    this->sprite.setPosition(this->position);
}

void player::reset()
{
    position = MainPosition;
    this->sprite.setPosition(this->position);
    this->health = 100;

}

