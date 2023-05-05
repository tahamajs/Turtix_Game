using namespace std ;
using namespace sf ;

enum GameState {
  MENU,
  PLAYING,
  PAUSED,
  GAME_OVER,
  EXIT,
  WIN,
  RESTART
};


#pragma once
const int STEP_SIZE = 15 ;
const int WINDOW_WIDTH = 1000 ;
const int WINDOW_HEIGHT = 600 ;
const int DEFAULT_HEALTH = 100 ;
const int SCORE_SI = 1 ;
const int MAX_SCORE = 1000 ;
const float Xgravity = 5 ;
const float Ygravity = 30 ;
const int VIEW_HIGHT = 1000; 
const int VIEW_WIDTH = 600;
const int JUMP_SPEED = 50;
const int DEAD_Y_DIRECTION = 3000;
const int DEAD_LIMIT = 2500;
const int RADIOS_OF_MOVEMENT = 100;
const int ENEMY_SPEED = 2;
const int ENEMY_YLIMIT = 3000;
const int MAX_HEALTH = 100;