#include "star.hpp"


Star::Star()
{
    this->loadTextures();
    this->loadStars();

}

Star::~Star()
{
}

void Star::loadStars()
{
    fstream file;
    file.open("stars.mpp");  
    if (file.is_open())
    {
        cout << "File stars.mpp is open" << endl;
        string line;
        int x, y, type;
        while (file >> line >> type >> x >> y )
        {
            TileStar tile;
            tile.x = x;
            tile.y = y;
            tile.type = type;
            tile.sprite = new Sprite();
            tile.sprite->setTexture(*textures[type]);
            tile.sprite->setPosition(x, y);
            tile.sprite->setScale(0.5, 0.5);
            Stars.push_back(tile);
        }
    }else
    {
        cout << "Can't open file stars.mpp" << endl;
    }
}

void Star::Draw(RenderWindow &window)
{
    for (int i = 0; i < Stars.size(); i++)
    {
        window.draw(*Stars[i].sprite);
    }
}

void Star::loadTextures()
{
    textures.push_back(new Texture());
    textures[0]->loadFromFile("sprite/3B58F1_prev_ui.png", IntRect(0,0, 100, 100));
    
}

bool Star::checkCollisionWithPlayer(FloatRect playerRect)
{
    for (int i = 0; i < Stars.size(); i++)
    {
        if (Stars[i].sprite->getGlobalBounds().intersects(playerRect))
        {
            Stars.erase(Stars.begin() + i);
            return true;
        }
    }
    return false;
}