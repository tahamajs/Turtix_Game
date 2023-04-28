#include "Player.hpp"

player::player(int x, int y) : velocity(0, 0) , m_gravity(0, 9)
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

player::~player()
{

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
        textures[i]->loadFromFile("sprite/2728FC_prev_ui.png", IntRect(i*100,0, 100, 100));
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
    window.draw(this->sprite);
    this-> update(0.1f);
    this->setgravity();
    spriteRectUpdate();
    
    
}

void player::move(Event *ev)
{
    cout << "move" << endl;
    if (ev->key.code == Keyboard::Key::A)
    {
        this->position.x -= STEP_SIZE;
    }
    if (ev->key.code == Keyboard::Key::D)
    {
        this->position.x += STEP_SIZE;
        
    }
    if (ev->key.code == Keyboard::Key::Space)
    {
        this->jump();
    }
    



    this->sprite.setPosition(this->position);

    // updateWindowBoundsCollision();
    
}

void player::setgravity()
{
    velocity.y += Ygravity;
    position.y += velocity.y;
    if (position.y > 500)
    {
        velocity.y = 0;
        position.y = 500;
    }
}





void player::update(float deltaTime) {
    // Apply gravity
    velocity += m_gravity * deltaTime;

    // Update position
    velocity += m_gravity * deltaTime;
    if (position.y > 600) { // Prevent player from falling through the floor
        position.y = 600;
        velocity.y = 0;
    }
}

void player::jump() {
    velocity.y = -400; // Set upward velocity for jump
}

    