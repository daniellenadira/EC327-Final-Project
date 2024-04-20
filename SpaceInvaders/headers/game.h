#ifndef GAME
#define GAME

#include <iostream>
#include <alien.h>
#include <SDL.h>

using namespace std;

const int initialAlienNum = 3;


class Game{
    public:
        Game();
        ~Game();

        void loop();
        void update() {}
        void input() {}
        void render();
        void draw();
        
        

        //this part isn't compiling rn and idk whyyyyyyyy
        Alien* redAliens = new Alien[initialAlienNum]; //array of Red aliens;
        Alien* blueAliens = new Alien[initialAlienNum]; //array of Blue aliens;

        SDL_Renderer* ren;
        SDL_Window* win;

    private: 
        bool running;
        int count;
        int frameCount, timerFPS, lastFrame;

};


//*/
#endif