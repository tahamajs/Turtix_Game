#include "Player.hpp"



player::player(int x, int y ) : velocity(0, 0) , m_gravity(0, 500)
{
    this->position.x = x;
    this->position.y = y;
    this->health = 100;
    rect = IntRect(0, 100 ,100, 100);
    texture = new Texture();
    this->texture->loadFromFile("sprite/2728FC_prev_ui.png", rect);
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->position);
    this->sprite.setScale(0.5, 0.5);
    this->loadTextures();

}

void player::initMap(Map *map)
{
    this->map = map;
}

player::~player()
{

}

void player::checkCollisionWithMap()
{
    if (map->checkCollision(sprite.getGlobalBounds()) != -1 )
    {
        // this->velocity.y = 0;
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
    // Clock clock;
    // if(clock.getElapsedTime().asMilliseconds() >= 50)
    // {
        for (int i = 0; i < 5; i++)
        {
            textures.push_back(new Texture());
            textures[i]->loadFromFile("sprite/2728FC_prev_ui.png", IntRect(i*100,0, 100, 100));
        }
        // clock.restart();
        
    // }
    
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
    window.draw(this->sprite);
    this-> update(0.001f);
    this->setgravity();
    spriteRectUpdate();
    checkCollisionWithMap();
    
    
}

void player::move(Event *ev)
{
    if (Keyboard::isKeyPressed(Keyboard::Key::A))
    {
        this->position.x -= STEP_SIZE;
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::D))
    {
        this->position.x += STEP_SIZE;
        
    }
    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
    {
        this->jump();
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
    velocity.y += Ygravity;
    position.y += velocity.y;
    if (position.y > Ylimit)
    {
        velocity.y = 0;
        position.y = Ylimit;
    }
}



void player::update(float deltaTime)
{
    // Update the player's velocity and position
    velocity += m_gravity * deltaTime;
    position += velocity * deltaTime;
    sprite.setPosition(position);

    // Check if the player has landed after a jump
    if (position.y >= Ylimit)
    {
        position.y = Ylimit;
        velocity.y = 0.0f;
        m_isJumping = false;
    }
}



// void player::update(float deltaTime) {
//     // Apply gravity
//     velocity += m_gravity * deltaTime;

//     // Update position

//     velocity += m_gravity * deltaTime;
//     if (position.y > 600) { // Prevent player from falling through the floor
//         position.y = 1000;
//         velocity.y = 0;
//     }
// }

void player::jump() {
    velocity.y = -100; // Set upward velocity for jump
}

    