#include "Game.hpp"
//need to add Enemys


Game::Game()
{
    
    initVariables();
    initWindow();
    initPlayer();
    initScore();
    initGamePause();
    initMap();
    initStar();
    initMenu();
    initMusicPlayer();
    initEnemys();
    // initAudioClips();
    player1->initMap(map);
    // enemi->initMap(map);
    for(int i = 0 ; i < enemys.size() ; i++)
    {
        enemys[i]->initMap(map);
    }
    // sf::View view(sf::FloatRect(x, y, VIEW_HIGHT, VIEW_WIDTH));
    sf::View view(sf::FloatRect(VIEW_HIGHT/2-500,VIEW_WIDTH/2, VIEW_HIGHT, VIEW_WIDTH));
    window->setView(view);

    // enemi->initPlayer(player1);
    for(int i = 0 ; i < enemys.size() ; i++)
    {
        enemys[i]->initPlayer(player1);
    }

}

void Game::initMenu()
{ 
    // this->menu = new Menu(window,Vector2f(WINDOW_WIDTH/2,WINDOW_HEIGHT/2),Vector2f(300,300));
    // Vector2f Vect = Vector2f(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    this->menu = new Menu(*this->window,view.getCenter());
}

Game::~Game()
{
    delete this->window;
}


void Game::initAudioClips()
{
    // AudioClip *audioClip = new AudioClip("Audio/coin.wav");
    // audioClips.push_back(audioClip);
}

void Game::initMusicPlayer()
{
    musicPlayer = new MusicPlayer("Audio/RunTimePlayingSound.wav");
    musicPlayer->setLoop(true);
}

void Game::ColisionWithEnemy()
{
    // if (enemi->isCollisionWithPlayerNONTOP())
    // {
    //     // gameState = GameState::GAME_OVER;
    //     cout << "GAME OVER" << endl;
    // }
    // if (enemi->isCollisionWithPlayerTop())
    // {
    //     // enemi->reset();
    //     // score->addScore(100);
    //     cout << "ENEMY DEAD" << endl;
    // }
    
}

void Game::initScore()
{
    this->score = new Score();
}

void Game::initMap()
{
    this->map = new Map(226);
}

void Game::initStar()
{
    this->star = new Star();
}

void Game::initEnemys()
{
    ifstream file;
    file.open("enemy.map");
    if (file.is_open())
    {
        int x, y;
        int type ;
        while (file >> type >> x >> y)
        {
            Enemy *enemi = new Enemy(x, y , &gameState);
            enemys.push_back(enemi);
        }
    }

}



void Game::update()
{
    ColisionWithEnemy();
    if (!musicPlayer->isPlaying())
    {
        musicPlayer->play();
    }
    pollEvents();
    map->update();
    scoreUpdate();
    if (player1->getposition().y > DEAD_LIMIT)
    {
        gameState = GameState::GAME_OVER;
    }
    

    

}


void Game::initWindow()
{
    videoMode.height = WINDOW_HEIGHT;
    videoMode.width = WINDOW_WIDTH;
    this->window = new RenderWindow(videoMode, "Taha Game", Style::Titlebar | Style::Close);
    window->setFramerateLimit(60);
    
}



void Game::initVariables()
{
    this->window = nullptr;
}

void Game::render()
{
    this->window->clear(Color(135,206,235));
    this->Draw();
    view = window->getView();
    view.setCenter(player1->getposition());
    window->setView(view);

    this->window->display();
}

bool Game::running()
{   
    return this->window->isOpen() && !score->isMaxScore();
}

void Game::scoreUpdate()
{
    if (star->checkCollisionWithPlayer(player1->getSprite().getGlobalBounds()))
    {
        score->increaseScore(2);
    }
    
}   

void Game::Draw()
{
    map->draw(*window);
    this->player1->Draw(*this->window);
    
    score->Draw(*this->window,view.getCenter());

    star->Draw(*this->window);
    
    window->draw(this->BackgroundSprite);

    for (auto &enemi : enemys)
    {
        enemi->Draw(*window);
    }
}

void Game::initPlayer()
{
    this->player1 = new player(100, 100 , &gameState);
}

void Game::pollEvents()
{

    while (this->window->pollEvent(ev))
    {
        

        switch (ev.type)
        {
        case Event::Closed:
            this->window->close();
            break;
        case Event::KeyPressed:
            if (ev.key.code == Keyboard::Escape)
            {
                // isPause = !isPause;
                // GameState = 2;
                gameState = GameState::PAUSED;
            }
            else if (ev.key.code == Keyboard::J)
            {
                gameState = GameState::MENU;
                musicPlayer->pause();
            }

            player1->move(&ev);
            view = window->getView();
            view.setCenter(player1->getposition());
            window->setView(view);

            
            
            break;
        }
        
    }
}


void Game::PlayGame()
{
    if(gameState == GameState::PLAYING){
        this->update();
        this->render();
        return;
    }
    else if(gameState == GameState::PAUSED){
        PauseGame();
    }
    else if(gameState == GameState::MENU){
        menu->update(gameState, view.getCenter());
        menu->render();
    }
    else if (gameState == GameState::GAME_OVER)
    {
        //need to add game over screen
        Text text;
        Font *font = new Font();
        font->loadFromFile("fonts/MenuFont.otf");
        text.setFont(*font);
        text.setString("Game Over");
        text.setCharacterSize(100);
        text.setFillColor(Color::Red);
        text.setPosition(view.getCenter().x-200,view.getCenter().y-100);
        // this->window->clear(Color(135,206,235));
        this->window->draw(text);
        this->window->draw(this->BackgroundSprite);
        this->window->display();
        sleep(seconds(3));
        // this->window->close();
        resetGame();
    }
    else if (gameState == GameState::RESTART)
    {
        resetGame();
        gameState = GameState::PLAYING;
    }
    else if (gameState == GameState::WIN)
    {
        //need to add win screen
        // this->window->close();
        cout << "You Win" << endl;
        Text text;
        Font *font = new Font();
        font->loadFromFile("fonts/MenuFont.otf");
        text.setFont(*font);
        text.setString("You Win");
        text.setCharacterSize(100);
        text.setFillColor(Color::Red);
        text.setPosition(view.getCenter().x-200,view.getCenter().y-100);
        // this->window->clear(Color(135,206,235));
        this->window->draw(text);
        this->window->draw(this->BackgroundSprite);
        this->window->display();


        sleep(seconds(3));
        this->window->close();
        

    }
}

void Game::initGamePause()
{
    // this->gamePause = new GamePause(this->window,view.getCenter());
    
    this->gamePause = new GamePause(*this->window);

}

void Game::PauseGame()
{
    this->gamePause->update(gameState, view.getCenter());
    this->gamePause->render();

}

void Game::resetGame()
{
    this->player1->reset();
    this->score->reset();
    this->star->reset();
    this->gameState = GameState::PLAYING;
    this->musicPlayer->play();
    // this->enemi->reset();
}