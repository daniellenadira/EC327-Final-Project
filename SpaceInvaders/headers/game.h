#ifndef GAME
#define GAME

#include <iostream>
#include <SDL.h>

#include <player.h>
#include <stack.h>
#include <alienStack.h>

using namespace std;

//window params
const int RightWinEdge = 800;
const int BottonWinEdge = 550;

//color codes 
const int REDX = 225; const int REDY = 0; const int REDZ = 0;
const int BLUEX = 0; const int BLUEY = 0; const int BLUEZ = 255;
   

class Game{
    public:
        Game(int r);
        ~Game();

        int round;

        int* loop(); 
        void render(); //for updating screen
        void update(); //for keyboard presses
        void draw(); 
        void move();
        void hit();
        void updateScoreBoard(); //DANI DO THE SCOREBOARD STUFF HERE
        
        //stack for the aliens
        alienStack aliens;
        int initialAlienNum;

        //player stuff
        Player p1;
        Player p2;

        //stack for the bullets
        stack redBulletStack;
        stack blueBulletStack;
        stack alienBulletStack;

        void bulletHitAlien(bullet* b);

        //window params
        SDL_Renderer* ren;
        SDL_Window* win;

    private: 
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;
};

#endif