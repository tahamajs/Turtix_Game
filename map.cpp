#include <SFML/Graphics.hpp>

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;
const int TILE_SIZE = 32;

int map[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600,800), "Tutrix");

    sf::Texture wallTexture;
    wallTexture.loadFromFile("tree.png");
    sf::Sprite wallSprite(wallTexture);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Grass_background_1.png");
    sf::Sprite playerSprite(playerTexture);
    int playerX = 1;
    int playerY = 1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left && map[playerX - 1][playerY] == 0)
                {
                    playerX--;
                }
                else if (event.key.code == sf::Keyboard::Right && map[playerX + 1][playerY] == 0)
                {
                    playerX++;
                }
                else if (event.key.code == sf::Keyboard::Up && map[playerX][playerY - 1] == 0)
                {
                    playerY--;
                }
                else if (event.key.code == sf::Keyboard::Down && map[playerX][playerY + 1] == 0)
                {
                    playerY++;
                }
            }
        }

        window.clear();

        for (int x = 0; x < MAP_WIDTH; x++)
        {
            for (int y = 0; y < MAP_HEIGHT; y++)
            {
                if (map[x][y] == 1)
                {
                    wallSprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
                    window.draw(wallSprite);
                }
            }
        }

        playerSprite.setPosition(playerX * TILE_SIZE, playerY * TILE_SIZE);
        window.draw(playerSprite);

        window.display();
    }

    return 0;
}
