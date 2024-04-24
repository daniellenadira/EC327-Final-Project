#include "game.h"

Game::Game(){

    //window parameters
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(RightWinEdge, BottonWinEdge, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Space Invaders");
    running = true;
    count = 0;
    
    //initialize players
    p1 = Player("Red", 100);
    p2 = Player("Blue", 400);

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

    //start looping through the game
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

        update();
        render();

        if(count>10){ //after 10 seconds end game
            running = false;
        }
    }
}

//keyboard event updating
void Game::update(){
    
    SDL_Event event;

   while (SDL_PollEvent(&event)) {
    if (event.type == SDL_KEYDOWN) {
        string name = SDL_GetKeyName(event.key.keysym.sym);
        if(name=="A"){
            p1.moveLeft = true;
        }else if(name =="D"){
            p1.moveRight = true;
        }else if(name == "W"){
            p1.shoot = true;
        }else if(name == "Left"){
            p2.moveLeft = true;
        }else if(name == "Right"){
            p2.moveRight = true;
        }else if(name == "Up"){
            p2.shoot = true;
        }
        
    }else if (event.type == SDL_KEYUP) {
        string name = SDL_GetKeyName(event.key.keysym.sym);
        if(name=="A"){
            p1.moveLeft = false;
        }else if(name =="D"){
            p1.moveRight = false;
        }else if(name == "W"){
            p1.shoot = false;
        }else if(name == "Left"){
            p2.moveLeft = false;
        }else if(name == "Right"){
            p2.moveRight = false;
        }else if(name == "Up"){
            p2.shoot = false;
        }
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
    if((frameCount%10)==0){ //how often to update the image
        //make screen black and redraw stuff
        SDL_Rect rect;
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); //just a black rectangle
        rect.x = 0;
        rect.y = 0; 
        rect.w = RightWinEdge;
        rect.h = BottonWinEdge;
        SDL_RenderFillRect(ren, &rect);
        
        //draw everything else
        draw();
    }

    SDL_RenderPresent(ren);
}

void Game::draw(){

    //players
    if(p1.posX+100 > RightWinEdge){
        p1.hitRightEdge = true;
    }else{ p1.hitRightEdge = false;}
    if(p1.posX<0){
        p1.hitLeftEdge = true;
    }else{ p1.hitLeftEdge = false;}

    p1.movePlayer();
    p1.drawPlayer(ren);

    if(p2.posX+100 > RightWinEdge){
        p2.hitRightEdge = true;
    }else{ p2.hitRightEdge = false;}
    if(p2.posX<0){
        p2.hitLeftEdge = true;
    }else{ p2.hitLeftEdge = false;}

    p2.movePlayer();
    p2.drawPlayer(ren);


    //aliens
    //check if they are at the edge
    if(aliens[lastAlien].posX+50 > RightWinEdge || aliens[firstAlien].posX<0){
        alienHitEdge = true;
    }else{
        alienHitEdge = false;   
    }
     //drawing in aliens
     for(int i = 0; i<(blueAliens+redAliens); i++){
        aliens[i].drawAlien(ren);
        aliens[i].moveAlien(alienHitEdge);
    }

    //bullets
    //player bullets
    if(p1.shoot==true){
        playerBulletStack.append(p1.posX,p1.posY,p1.color);
    }
    if(p2.shoot==true){
        //cout<< p2.posX<< " "<< p2.posY << endl;
        playerBulletStack.append(p2.posX,p2.posY,p2.color);
    }
    playerBulletStack.checkForOffScreen();
    playerBulletStack.moveBullet(playerBulletStack.playerBulletSpeed);
    playerBulletStack.drawBullet(ren);

    //alien bullets
    if(alienBulletStack.timeBetweenBullets >= 10){
        for(int i = 0; i<redAliens+blueAliens; i++){
            alienBulletStack.append(aliens[i].posX, aliens[i].posY, "White");
        }
        alienBulletStack.timeBetweenBullets = 0;
    }
    alienBulletStack.timeBetweenBullets++;
    playerBulletStack.checkForOffScreen();
    alienBulletStack.moveBullet(alienBulletStack.alienBulletSpeed);
    alienBulletStack.drawBullet(ren);
    
}
