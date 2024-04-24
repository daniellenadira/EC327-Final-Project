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
        //randomizing colors
    aliens.numRedAliens = 0;
    aliens.numBlueAliens = 0;
    int num = rand() % 2;
    string color;
    for(int i = 0; i<initialAlienNum; i++){
        
        if(num==0 && aliens.numRedAliens!=(initialAlienNum/2)){
            color = "Red";
        }else{
            color = "Blue";
        }
        num = rand() % 2;
        aliens.append(color);
    }

    //start looping through the game
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
        if(lastFrame>= (lastTime+1000)){
            lastTime = lastFrame;
            frameCount = 0;
        }
        
        count++;

        update();
        render();

        if(count>1000){ //after 10 seconds end game
            running = false;
        }
    }
}

//keyboard event updating
void Game::update(){
    
    SDL_Event event;

    //failsafe bc idk why the keys are starting to move automatically
    if(count<5){
        p1.moveLeft = false;
        p1.moveRight = false;
        p1.shoot = false;
        p2.moveLeft = false;
        p2.moveRight = false;
        p2.shoot = false;
    }

   while (SDL_PollEvent(&event)&&count>100) {
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
     //drawing in aliens
    aliens.moveAlien();
    aliens.drawAlien(ren);

    //bullets
    //player bullets
    if(p1.shoot==true){
        redBulletStack.append(p1.posX,p1.posY,p1.color);
    }
    if(p2.shoot==true){
        blueBulletStack.append(p2.posX,p2.posY,p2.color);
    }
    redBulletStack.checkForOffScreen();
    redBulletStack.moveBullet(redBulletStack.playerBulletSpeed);
    redBulletStack.drawBullet(ren);

    blueBulletStack.checkForOffScreen();
    blueBulletStack.moveBullet(blueBulletStack.playerBulletSpeed);
    blueBulletStack.drawBullet(ren);

    //alien bullets
    if(alienBulletStack.timeBetweenBullets >= 10){
        Alien* temp = aliens.head;
        for(int i = 0; i<(aliens.numRedAliens+aliens.numBlueAliens); i++){
            alienBulletStack.append(temp->posX, temp->posY, "White");
            temp = temp->getNext();
        }
        alienBulletStack.timeBetweenBullets = 0;
    }
    alienBulletStack.timeBetweenBullets++;

    //alienBulletStack.checkForOffScreen();
    //alienBulletStack.moveBullet(alienBulletStack.alienBulletSpeed);
    //alienBulletStack.drawBullet(ren);
    
    
}
