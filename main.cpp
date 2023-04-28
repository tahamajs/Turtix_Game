#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace std ;
using namespace sf ;

int main(){
    Game game;
    Clock clock;
    while (game.running())
    {
        if(clock.getElapsedTime().asMilliseconds() >= 50)
        {
            game.PlayGame();
            clock.restart();
            
        }
        
        
        

        
    }
    
}