#include "game.h"

//window sizes

Game::Game(){

    //window parameters
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(RightWinEdge, BottonWinEdge, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Space Invaders");
    running = true;
    count = 0;
    
    //initialize aliens
    firstAlien = 0;
    lastAlien = initialAlienNum-1;
    alienHitEdge = false;

    //randomizing colors
    redAliens = 0;
    blueAliens = 0;
    int num = rand() % 2;
    string color;
    for(int i = 0; i<initialAlienNum; i++){
        if(num==0 && redAliens!=(initialAlienNum/2)){
            color = "Red";
            redAliens++;
        }else{
            color = "Blue";
            blueAliens++;
        }
        num = rand() % 2;
        aliens[i] = Alien(color, i);
    }

    loop();

}

Game::~Game(){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    delete aliens;
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

        if(count>10){ //after 5 seconds end game
            running = false;
        }
    }
}

void Game::render(){ //update everything **if this is too slow might need to render things individually 
    

    frameCount++;
    int timerFPS= SDL_GetTicks()-lastFrame;
    if(timerFPS<(1000/60)){
        SDL_Delay((1000/60)-timerFPS); //60 frames per second        
    }

    //draw stuff
    if((frameCount%10)==0){
        //make screen black and redraw stuff
        SDL_Rect rect;
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); //just a black rectangle
        rect.x = 0;
        rect.y = 0; 
        rect.w = RightWinEdge;
        rect.h = BottonWinEdge;
        SDL_RenderFillRect(ren, &rect);
        
        //draw everythin else
        draw();
    }

    SDL_RenderPresent(ren);
}

void Game::draw(){

    if(aliens[lastAlien].posX+50 > RightWinEdge || aliens[firstAlien].posX<0){
        alienHitEdge = true;
    }else{
        alienHitEdge = false;   
    }

     //drawing in aliens
     for(int i = 0; i<initialAlienNum; i++){
        aliens[i].drawAlien(ren);
        aliens[i].moveAlien(alienHitEdge);
    }

}