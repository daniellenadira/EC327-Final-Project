#ifndef GAME
#define GAME

#include <iostream>
#include <map>
#include <SDL.h>

#include <alien.h>
#include <player.h>
#include <stack.h>

using namespace std;

//initial alien params
const int initialAlienNum = 7;
const int initialAlienSpacing = 50;

//window params
const int RightWinEdge = 800;
const int BottonWinEdge = 600;

//color codes 
const int REDX = 225; const int REDY = 0; const int REDZ = 0;
const int BLUEX = 0; const int BLUEY = 0; const int BLUEZ = 255;
   

class Game{
    public:
        Game();
        ~Game();

        void loop(); 
        void render(); //for updating screen
        void update(); //for keyboard presses
        void draw(); 
        
        //alien stuff
        Alien* aliens = new Alien[initialAlienNum];
        int redAliens;
        int blueAliens;
        int firstAlien;
        int lastAlien;
        bool alienHitEdge;

        //player stuff
        Player p1;
        Player p2;

        //stack for the bullets
        stack bulletStack;

        //window params
        SDL_Renderer* ren;
        SDL_Window* win;

    private: 
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;

};

#endif