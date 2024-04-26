#include "game.h"

Game::Game(int r){
    round = r;
    //window parameters
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(RightWinEdge, BottonWinEdge+50, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Space Invaders");
    running = true;
    count = 0;

    //initialize players
    p1 = Player("Red", 100);
    p2 = Player("Blue", 400);
    
    //initialize aliens
    initialAlienNum = round+1;//each round add an alien
    aliens.numRedAliens = 0;
    aliens.numBlueAliens = 0;
    string color;
    for(int i = 0; i<initialAlienNum*2; i++){
        
        if(i%2==0){
            color = "Red";
        }else{
            color = "Blue";
        }
        aliens.append(color, i+1);
    }
}

Game::~Game(){
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

int* Game::loop() { 
    while(running){
        lastFrame=SDL_GetTicks();
        static int lastTime;
        if(lastFrame>= (lastTime+1000)){
            lastTime = lastFrame;
            frameCount = 0;
        }
        count++;


        //loops through these two to update and then render the game
        update();
        render();


        //game ends after all aliens dead or all people dead
        if((aliens.numBlueAliens+aliens.numRedAliens<=0) || (p1.lives+p2.lives<=0)){
            //returns the players score
            running = false;
        }
    }
    int* ptr = new int[3];
    ptr[0] = initialAlienNum-aliens.numRedAliens;
    ptr[1] = initialAlienNum-aliens.numBlueAliens;
    ptr[2] = (p1.lives)+(p2.lives)+0;
    return ptr;
}

//keyboard event updating
void Game::update(){
    
    SDL_Event event;

    //failsafe bc idk why the keys are starting to move automatically
    if(count<2){
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
        //gameplay area
        SDL_Rect rect;
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); //just a black rectangle
        rect.x = 0;
        rect.y = 0; 
        rect.w = RightWinEdge;
        rect.h = BottonWinEdge;
        SDL_RenderFillRect(ren, &rect);

        //scoreboard area
        SDL_Rect rect2;
        SDL_SetRenderDrawColor(ren, 105, 105, 105, 255); //just a black rectangle
        rect2.x = 0;
        rect2.y = BottonWinEdge; 
        rect2.w = RightWinEdge;
        rect2.h = BottonWinEdge+50;
        SDL_RenderFillRect(ren, &rect2);
        
    
        move(); //moves everything 
        hit(); //checks if anything has hit
        draw(); //draws everthing
        updateScoreBoard(); //DANIS SECTIONNNNNNNNNNNNNNNN
    }

    SDL_RenderPresent(ren);
}


void Game::updateScoreBoard(){
    /* update the scoreboard:
    helpful variables are:
    player one lives is: p1.lives;
    player two lives is: p2.lives;
    number of red aliens left is: aliens.numRedAliens;
    number of blue aliens left is: aliens.numBlueAliens;

    */
}



void Game::draw(){

    //players
    if(p1.lives>0){
        p1.drawPlayer(ren);
        redBulletStack.drawBullet(ren);
    }

    if(p2.lives>0){
        p2.drawPlayer(ren);
        blueBulletStack.drawBullet(ren);
    }
    
    //aliens
    aliens.drawAlien(ren);
    alienBulletStack.drawBullet(ren);
    
}


void Game::move(){

    //p1
    if(p1.lives>0){
        //player
        if(p1.posX+100 > RightWinEdge){
                p1.hitRightEdge = true;
        }else{ p1.hitRightEdge = false;}
        if(p1.posX<0){
            p1.hitLeftEdge = true;
        }else{ p1.hitLeftEdge = false;}

        p1.movePlayer();

        //bullets
        if(p1.shoot==true){
            redBulletStack.append(p1.posX,p1.posY,p1.color);
        }
        redBulletStack.checkForOffScreen();
        redBulletStack.moveBullet(redBulletStack.playerBulletSpeed);

    }

    //p2
    if(p2.lives>0){
        //player
        if(p2.posX+100 > RightWinEdge){
            p2.hitRightEdge = true;
        }else{ p2.hitRightEdge = false;}
        if(p2.posX<0){
            p2.hitLeftEdge = true;
        }else{ p2.hitLeftEdge = false;}

        p2.movePlayer();
        
        //bullets
        if(p2.shoot==true){
            blueBulletStack.append(p2.posX,p2.posY,p2.color);
        }
        blueBulletStack.checkForOffScreen();
        blueBulletStack.moveBullet(blueBulletStack.playerBulletSpeed);
    }

    //aliens
    aliens.moveAlien();
    
    //alien bullets
    if(alienBulletStack.timeBetweenBullets >= 30-round*2){
        Alien* temp = aliens.head;
        for(int i = 0; i<(aliens.numRedAliens+aliens.numBlueAliens); i++){
            alienBulletStack.append(temp->posX, temp->posY, "White");
            temp = temp->getNext();
        }
        alienBulletStack.timeBetweenBullets = 0;
    }
    alienBulletStack.timeBetweenBullets++;

    alienBulletStack.checkForOffScreen();
    alienBulletStack.moveBullet(alienBulletStack.alienBulletSpeed);
}

void Game::hit(){
    //check to see if a red bullet has hit an alien
    bullet* temp = redBulletStack.head;
    while(temp!=nullptr){
        bulletHitAlien(temp);
        temp = temp->getNext();
    }

    //check to see if a blue bullet has hit an alien
    temp = blueBulletStack.head;
    while(temp!=nullptr){
        bulletHitAlien(temp);
        temp = temp->getNext();
    }

    //check to see if alien bullets hit players
    if(p1.lives>0){
        temp = alienBulletStack.head;
        while(temp!=nullptr){
            if((temp->posX >= p1.posX && temp->getRightPos() <= p1.getRightPos()) && (temp->posY >= p1.posY && temp->getTopPos() <= p1.getTopPos())){
                    cout<< "Red Player Hit!"<< endl;
                    p1.minusLives();
                    alienBulletStack.remove(temp->posX, temp->posY);
            }
            temp = temp ->getNext();
        }
    }
    
    if(p2.lives>0){
        temp = alienBulletStack.head;
        while(temp!=nullptr){
            if((temp->posX >= p2.posX && temp->getRightPos() <= p2.getRightPos()) && (temp->posY >= p2.posY && temp->getTopPos() <= p2.getTopPos())){
                    cout<< "Blue Player Hit!"<< endl;
                    p2.minusLives();
                    alienBulletStack.remove(temp->posX, temp->posY);
            }
            temp = temp ->getNext();
        }
    }
}


void Game::bulletHitAlien(bullet* b){
    Alien* temp = aliens.head;
    string c = b->color;
    bool change = false;
    while(temp!=nullptr){
        if(temp->color==c){
            if((temp->posX <= b->posX && temp->getRightPos() >= b->getRightPos()) && (temp->posY <= b->posY && temp->getTopPos() >= b->getTopPos())){
                cout<< c<< " Alien Hit!"<< endl;
                temp->hit = true;
                change = true;
            }
        }
        temp= temp->getNext();
    }
    if(change==true){
        aliens.hit();
    }
}

