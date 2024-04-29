#ifndef GAME
#define GAME

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

#include <player.h>
#include <stack.h>
#include <alienStack.h>

using namespace std;

//window params
const int RightWinEdge = 800;
const int BottonWinEdge = 550;
   

class Game{
    public:
        Game(int r, int s, int p1Lives, int p2Lives);
        ~Game();
        bool quit;

        int round;
        int runningScore;

        int* loop(); 
        void render(); //for updating screen
        void update(); //for keyboard presses
        void draw(); 
        void move();
        void hit();
        void updateScoreBoard(); 
        SDL_Texture* score;
        SDL_Texture* sbText;
        
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