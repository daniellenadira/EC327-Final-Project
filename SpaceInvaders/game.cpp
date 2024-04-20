#include "game.h"

//window sizes
const int WIDTH = 800;
const int HEIGHT = 600;

Game::Game(){

    //window parameters
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Space Invaders");
    running = true;
    count = 0;
    
    //initialize aliens
    for(int i = 0; i<initialAlienNum; i++){
        redAliens[i] = Alien("Red", i);
        blueAliens[i] = Alien("Blue", i);
    }


    loop();

}

Game::~Game(){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop() { //currently have the game just set to ending after 10 seconds but we gotta add end parameters and stuff
    while(running){

        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame>= (lastTime+1000)){ //after a sec update framecount
            lastTime = lastFrame;
            frameCount = 0;
            count++;
        }

        render();
        input();
        update();

        if(count>5){ //after 5 seconds end game
            running = false;
        }
    }
}

void Game::render(){ //update everything **if this is too slow might need to render things individually 

    draw();    

    frameCount++;
    int timerFPS= SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)){
        SDL_Delay((1000/60)-timerFPS); //60 frames per second
    }

    SDL_RenderPresent(ren);
}

void Game::draw(){
/*
     //drawing in aliens
    for(int i = 0; i<initialAlienNum; i++){
        redAliens[i].drawAlien(ren);
        blueAliens[i].drawAlien(ren);
    }
    */

}