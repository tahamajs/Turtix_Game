#include "map.hpp"
const int HEIGHT_ = 100 ;
const int WIDTH_ = 50 ;

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


float Map::checkCollision(FloatRect rect) {
    for (int i = 0; i < tiles_.size(); i++) {
        Tile& tile = tiles_[i];
        if (tile.moveable && tile.sprite != nullptr) {
            if (tile.sprite->getGlobalBounds().intersects(rect)) {
                return tile.sprite->getGlobalBounds().top+2;
            }
        }else{
            if (tile.sprite == nullptr)
            {
                cout << "Tile sprite is null" << endl;
            }
            
            // cout << "Tile is not moveable" << endl;
        }
    }
    return -1;
}

Map::Map(int size) : size_(size) {
    // tiles_.resize(size_);
    loadTextures("sprite/");
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
    if (!textures_[0] -> loadFromFile(path + "Shadows.png", IntRect(0, 650,HEIGHT_, WIDTH_)))
    {
        cout << "Error loading texture" << endl;
        abort();
    }
    // if (!textures_[1] -> loadFromFile(path + "tilesheet.png", IntRect(HIGHT_WIDTH, 0, HIGHT_WIDTH, HIGHT_WIDTH)))
    // {
    //     cout << "Error loading texture" << endl;
    //     abort();
    // }
    // if (!textures_[2] -> loadFromFile(path + "tilesheet.png", IntRect(64, 0, HIGHT_WIDTH, HIGHT_WIDTH)))
    // {
    //     cout << "Error loading texture" << endl;
    //     abort();
    // }
    // if (!textures_[3] -> loadFromFile(path + "tilesheet.png", IntRect(96, 0, HIGHT_WIDTH, HIGHT_WIDTH)))
    // {
    //     cout << "Error loading texture" << endl;
    //     abort();
    // }
    // if(!textures_[4] -> loadFromFile(path + "tilesheet.png", IntRect(128, 0, HIGHT_WIDTH, HIGHT_WIDTH)))
    // {
    //     cout << "Error loading texture" << endl;
    //     abort();
    // }

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
    Tile tile;

    int x = 100;
    int y = 100;
    int type = 0;
    int i = 0;

    while (file >> type_info >> type >> x >> y) {
        tile.x = x * HEIGHT_;
        tile.y = y * WIDTH_;
        tile.type = type;
        if (textures_[type] != nullptr) {  // Check if texture pointer is null
            tile.sprite = new Sprite(*textures_[type]);
            tile.sprite->setPosition(tile.x, tile.y);
            cout << "Tile " << i << " loaded" << endl;
        } else {
            tile.sprite = nullptr;
            cout << "Tile " << i << " not loaded" << endl;
        }
        tiles_.push_back(tile);
        i++;
        
    }

}

// need to check leter if it works
bool Map::isCollisionOnTop( const sf::Sprite& player) {
    sf::FloatRect bounds = player.getGlobalBounds();
    for(int i = 0; i < tiles_.size(); i++) {
        Tile& tile = tiles_[i];
        if (tile.sprite != nullptr) {
            sf::FloatRect tileBounds = tile.sprite->getGlobalBounds();
            if (bounds.intersects(tileBounds)) {
                // cout << "Collision detected" << endl;
                float bottom = bounds.top ;
                float top = tileBounds.top;
                if (bottom  <= top) {
                    // cout << bottom << " " << top << endl;
                    // cout << top << endl;
                    cout << "Collision on top" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Map::isCollisionOnLeft(const sf::Sprite& player) {
    sf::FloatRect bounds = player.getGlobalBounds();
    for(int i = 0; i < tiles_.size(); i++) {
        Tile& tile = tiles_[i];
        if (tile.sprite != nullptr) {
            sf::FloatRect tileBounds = tile.sprite->getGlobalBounds();
            if (bounds.intersects(tileBounds)) {
                // cout << "Collision detected" << endl;
                float right = bounds.left;
                float left = tileBounds.left;
                if (right >= left && bounds.top  > tileBounds.top - tileBounds.height) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Map::isCollisionOnRight(const sf::Sprite& player) {
    sf::FloatRect bounds = player.getGlobalBounds();
    for(int i = 0; i < tiles_.size(); i++) {
        Tile& tile = tiles_[i];
        if (tile.sprite != nullptr) {
            sf::FloatRect tileBounds = tile.sprite->getGlobalBounds();
            if (bounds.intersects(tileBounds)) {
                // cout << "Collision detected" << endl;
                float left = bounds.left;
                float right = tileBounds.left ;
                if (left <= right && bounds.top  > tileBounds.top - tileBounds.height) {
                    return true;
                }
            }
        }
    }
    return false;
}