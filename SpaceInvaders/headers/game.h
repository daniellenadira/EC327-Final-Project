#ifndef GAME
#define GAME

#include <iostream>
#include <alien.h>
#include <test.h>
#include <SDL.h>

using namespace std;

const int initialAlienNum = 7;
const int initialAlienSpacing = 50;

//window params
const int RightWinEdge = 800;
const int BottonWinEdge = 600;


class Game{
    public:
        Game();
        ~Game();

        void loop();
        void update() {}
        void input() {}
        void render();
        void draw();
        
        Alien* aliens = new Alien[initialAlienNum];
        int redAliens;
        int blueAliens;
        int firstAlien;
        int lastAlien;
        bool alienHitEdge;

        SDL_Renderer* ren;
        SDL_Window* win;

    private: 
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;

};

#endif