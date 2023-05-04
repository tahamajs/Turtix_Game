#include "Game.hpp"

Game::Game()
{
    
    initVariables();
    initWindow();
    initPlayer();
    // initBackground();
    initScore();
    initGamePause();
    initMap();
    initStar();
    player1->initMap(map);
    sf::View view(sf::FloatRect(x, y, VIEW_HIGHT, VIEW_WIDTH));
    window->setView(view);

}

Game::~Game()
{
    delete this->window;
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




void Game::update()
{

    pollEvents();
    map->update();
    scoreUpdate();

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
    
    
    this->player1->Draw(*this->window);

    score->Draw(*this->window,view.getCenter());

    star->Draw(*this->window);
    map->draw(*window);
    window->draw(this->BackgroundSprite);
}

void Game::initPlayer()
{
    this->player1 = new player(100, 100);
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
            // if (ev.key.code == Keyboard::Up)
            // {
            //     y-=10;
            //     cout << "jj" << endl;
                
            //     window->setView(View((FloatRect(x, y, 600.f, 600.f))));

            // }
            // if (ev.key.code == Keyboard::Down)
            // {
            //     y+=10;
            //     window->setView(View((FloatRect(x, y, 600.f, 600.f))));

            // }
            // if (ev.key.code == Keyboard::Left)
            // {
            //     x-=10;

                
            //     window->setView(View((FloatRect(x, y, 600.f, 600.f))));

            // }if (ev.key.code == Keyboard::Right)
            // {

            //     x+=10;

                
            //     window->setView(View((FloatRect(x, y, 600.f, 600.f))));

            // }

            if (ev.key.code == Keyboard::Escape)
            {
                isPause = !isPause;
            }
            player1->move(&ev);
            
            
            break;
        }
        
    }
}



void Game::PlayGame()
{
    if(!isPause){
        this->update();
        this->render();
        return;
    }else{
        PauseGame();
    }
}

void Game::initGamePause()
{
    this->gamePause = new GamePause(this->window);
}

void Game::PauseGame()
{
    this->gamePause->update(isPause);
    this->gamePause->render();
}