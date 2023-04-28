#include "map.hpp"


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
            if (tile.sprite->getGlobalBounds().intersects(rect) ) {
                // cout << tile.sprite->getGlobalBounds().top << endl;
                return tile.sprite->getGlobalBounds().top;
            }
        }else{
            cout << "Tile is not moveable" << endl;
            cout << "Tile type: " << tiles_.size() << endl;
        }
    }
    return -1;
}

Map::Map(int size) : size_(size) {
    tiles_.resize(size_);
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
            // sprite.setPosition(tile.x, tile.y);
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
            tiles_[i].sprite->setPosition(tiles_[i].x, tiles_[i].y);
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
