#include "GamePause.hpp"    

GamePause::GamePause(RenderWindow *window)
{
    this->initVariables();
    this->initFont();
    this->initWindow(window);
    // this->initBackground();
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
    this->pause_window = window;
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
    this->button = new RectangleShape(Vector2f(200, 50));
    this->button->setFillColor(Color::Red);
    this->button->setPosition(WINDOW_WIDTH / 2 - this->button->getGlobalBounds().width / 2, WINDOW_HEIGHT / 2 - this->button->getGlobalBounds().height / 2);
    
}

void GamePause::initText()
{
    this->text = new Text("RESUME ", *this->font, 50);
    this->text->setFillColor(Color::Green);
    this->text->setPosition(this->button->getPosition().x + this->button->getGlobalBounds().width / 2 - this->text->getGlobalBounds().width / 2, this->button->getPosition().y + this->button->getGlobalBounds().height / 2 - this->text->getGlobalBounds().height / 2);
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

void GamePause::update(enum GameState &gameStat)
{
    this->pollEvents(gameStat);
}

void GamePause::render()
{
    this->pause_window->clear();
    // this->pause_window->draw(*this->backgroundSprite);
    this->pause_window->draw(*this->button);
    this->pause_window->draw(*this->text);
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
            }
            break;
        }
    }
}

