#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

using namespace std ;
using namespace sf ;

int main(){
    Game game;
    Clock clock;
    Time time;
    while (game.running())
    {
        if(clock.getElapsedTime().asMilliseconds() >= 40)
        {
            
            float time = clock.restart().asMilliseconds();
            game.PlayGame() ;
            clock.restart();
            // cout << time << endl;
            
        }
        
        
        

        
    }
    
}