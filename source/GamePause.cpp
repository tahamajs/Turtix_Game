#include "../HederFiles/GamePause.hpp"    

GamePause::GamePause(RenderWindow& window )
{
    this->initVariables();
    this->initFont();
    // this->initWindow(*window);
    pause_window = &window;
    this->initBackground();
    this->initButtons();
    this->initText();
}

GamePause::~GamePause()
{
    delete this->pause_window;
    delete this->background;
    delete this->font;
    delete this->text;
    delete this->button;
}

void GamePause::initWindow(RenderWindow *window)
{
    // this->pause_window = window;
}

void GamePause::initVariables()
{
    this->pause_window = nullptr;
    this->background = nullptr;
    this->backgroundSprite = nullptr;
    this->font = nullptr;
    this->text = nullptr;
    this->button = nullptr;
    this->pause_window = nullptr;

}

void GamePause::initBackground()
{
    this->background = new Texture();
    this->background->loadFromFile("bkk.png");
    this->backgroundSprite = new Sprite();
    this->backgroundSprite->setTexture(*this->background);
}

void GamePause::initButtons()
{
    this->button = new RectangleShape(Vector2f(250, 60));
    this->button->setFillColor(Color::Red);
    this->button->setPosition(position);
    this->button2 = new RectangleShape(Vector2f(250, 60));
    this->button2->setFillColor(Color::Red);
    this->button2->setPosition(position.x, position.y + 100);
    this->button3 = new RectangleShape(Vector2f(250, 60));
    this->button3->setFillColor(Color::Red);
    this->button3->setPosition(position.x, position.y + 200);
    
}

void GamePause::initText()
{
    this->text = new Text("RESUME GAME", *this->font,50);
    this->text->setFillColor(Color::Green);
    this->text->setPosition(position);
    // this->text->setScale(1.5, 1.5);
    this->text2 = new Text("MAIN MENU ", *this->font, 50);
    this->text2->setFillColor(Color::Green);
    this->text2->setPosition(position.x, position.y + 100);
    // this->text2->setScale(1.5, 1.5);
    this->text3 = new Text("RESTART GAME ", *this->font, 50);
    this->text3->setFillColor(Color::Green);
    this->text3->setPosition(position.x, position.y + 200);
    // this->text3->setScale(1.5, 1.5);

}

void GamePause::initFont()
{
    this->font = new Font();
    if (!this->font->loadFromFile("fonts/MenuFont.otf"))
    {
        cout << "Error loading font" << endl;
    }
    else
    {
        cout << "Font loaded" << endl;
    }
}

void GamePause::update(enum GameState &gameStat , Vector2f _position)
{
    // this->position = position;
    this->position.x = _position.x - 100;
    this->position.y = _position.y - 100;
    this->button->setPosition(position);
    this->button2->setPosition(position.x, position.y + 100);
    this->button3->setPosition(position.x, position.y + 200);
    this->text->setPosition(position);
    this->text2->setPosition(position.x, position.y + 100);
    this->text3->setPosition(position.x, position.y + 200);

    this->render();
    this->pollEvents(gameStat);
}

void GamePause::render()
{
    this->pause_window->clear();
    // this->pause_window->draw(*this->backgroundSprite);
    this->pause_window->draw(*this->button);
    this->pause_window->draw(*this->button2);
    this->pause_window->draw(*this->button3);
    this->pause_window->draw(*this->text);
    this->pause_window->draw(*this->text2);
    this->pause_window->draw(*this->text3);
    this->pause_window->display();

}

void GamePause::pollEvents(enum GameState &gameStat)
{
    while (this->pause_window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case Event::Closed:
            this->pause_window->close();
            break;
        case Event::KeyPressed:
            if (this->ev.key.code == Keyboard::Escape)
            {
                // this->pause_window->close();
                gameStat = GameState::PLAYING;
            }
            break;
        case Event::MouseButtonPressed:
            if (this->ev.mouseButton.button == Mouse::Left)
            {
                if (this->button->getGlobalBounds().contains(this->pause_window->mapPixelToCoords(Mouse::getPosition(*this->pause_window))))
                {
                    gameStat = GameState::PLAYING;
                }
                if (this->button2->getGlobalBounds().contains(this->pause_window->mapPixelToCoords(Mouse::getPosition(*this->pause_window))))
                {
                    gameStat = GameState::MENU;
                }
                if (this->button3->getGlobalBounds().contains(this->pause_window->mapPixelToCoords(Mouse::getPosition(*this->pause_window))))
                {
                    gameStat = GameState::RESTART;
                }
            }
            break;
        }
    }
}

