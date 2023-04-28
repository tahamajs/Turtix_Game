#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using namespace sf;

class Map {
public:
    struct Tile {
        int x;
        int y;
        int type;
        Sprite* sprite;
        bool moveable = true;
        bool deadly = false;
    };



    Map(int size);
    ~Map();
    void draw(RenderWindow& window);
    void update();
    Vector2f getSize();
    void loadTextures(const std::string& path);
    void loadTiles(const std::string& path);
    int checkCollision(FloatRect rect);
    
    

private:
    std::vector<Tile> tiles_;
    std::vector<Texture*> textures_;
    int size_;
};


void Map::update() {
    for (Tile& tile : tiles_) {
        if (tile.type == 0) {
            tile.moveable = true;
        }
        if (tile.type == 1) {
            tile.deadly = true;
        }
        
    }
    

}

// int Map::checkCollision(FloatRect rect) {
//     for()
// }


Map::Map(int size) : size_(size) {
    tiles_.resize(size_ * size_);
    loadTextures("./");
    loadTiles("./");
    cout << "Map loaded" << endl;
}




Map::~Map() {
    for (Texture* texture : textures_) {
        delete texture;
    }
}

void Map::draw(RenderWindow& window) {
    for (Tile& tile : tiles_) {
        if (tile.sprite != nullptr) {  // Check if sprite pointer is null
            Sprite sprite(*tile.sprite);
            sprite.setPosition(tile.x, tile.y);
            window.draw(sprite);

        }
    }
}

void Map::loadTextures(const std::string& path) {
    textures_.resize(5);
    textures_[0] = new Texture;
    textures_[1] = new Texture;
    textures_[2] = new Texture;
    textures_[3] = new Texture;
    textures_[4] = new Texture;
    if (!textures_[0] -> loadFromFile(path + "tilesheet.png", IntRect(0, 0, 32, 32)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    if (!textures_[1] -> loadFromFile(path + "tilesheet.png", IntRect(32, 0, 32, 32)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    if (!textures_[2] -> loadFromFile(path + "tilesheet.png", IntRect(64, 0, 32, 32)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    if (!textures_[3] -> loadFromFile(path + "tilesheet.png", IntRect(96, 0, 32, 32)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    if(!textures_[4] -> loadFromFile(path + "tilesheet.png", IntRect(128, 0, 32, 32)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    
    
    

    


}


void Map::loadTiles(const std::string& path) {
    fstream file;
    file.open(path + "map.map");
    string type_info;
    
    if(file.is_open()) {
        cout << "File opened" << endl;
    } else {
        cout << "Error opening file" << endl;
        abort();
    }
    int x = 100;
    int y = 100;
    int type = 0;
    int i = 0;
    while (file >> type_info >> type >> x >> y) {
        tiles_[i].x = x * 32;
        tiles_[i].y = y * 32;
        tiles_[i].type = type;
        if (textures_[type] != nullptr) {  // Check if texture pointer is null
            tiles_[i].sprite = new Sprite(*textures_[type]);
            cout << "Tile " << i << " loaded" << endl;
        } else {
            tiles_[i].sprite = nullptr;
            cout << "Tile " << i << " not loaded" << endl;
        }
        i++;
        // x += 32;
        // if (x >= 640) {
        //     x = 0;
        //     y += 32;
        // }
    }
    file.close();

}

int main()
{
    // create a window
    sf::RenderWindow window(sf::VideoMode(1200, 600), "SFML Jump Example");
    Map map(20);
    float yLimit = 550.f;


    // game variables
    float gravity = 1600.f; // in pixels per second squared
    float gravity2 = 500.f; // in pixels per second squared
    sf::Clock clock;
    sf::Vector2f velocity(0.f, 0.f);
    sf::Vector2f position(300.f, 100.f);
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Red);

    // game loop
    while (window.isOpen())
    {
        
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // window closed
                window.close();
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            {
                // apply jump velocity
                if (position.y >= yLimit) // make sure the player can't jump while already in the air
                    velocity.y = -500.f;

            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
                if(velocity.x >= -400.f)
                    velocity.x -= 100.f;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
                if(velocity.x <= 400.f)
                    velocity.x += 100.f;
            }
        }

        // update the game state
        float deltaTime = clock.restart().asSeconds();

        // apply gravity to the player
        velocity.y += gravity * deltaTime;
        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;

        

        // make sure the player doesn't fall below the ground
        if (position.y > yLimit)
        {
            position.y = yLimit;
            velocity.y = 0.f;
        }

        if (velocity.x >= 0)
        {
            velocity.x -= gravity2 * deltaTime;
        }
        if (velocity.x <= 0)
        {
            velocity.x += gravity2 * deltaTime;
        }
        

        player.setPosition(position);

        map.update();
        // clear the window
        window.clear();

        // draw game objects here
        window.draw(player);
        map.draw(window);

        // display the window
        window.display();


        // if(map.checkCollision(player.getGlobalBounds()) != -1){
        //     yLimit = map.checkCollision(player.getLocalBounds());
        //     // cout << "Collision" << endl;
        // } else {
        //     yLimit = 550.f;
        //     // cout << "No collision" << endl;
        // }
    }

    return 0;
}