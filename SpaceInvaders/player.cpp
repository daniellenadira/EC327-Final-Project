#include "player.h"

Player::Player(){
    color = "";
    posX = 0;
    posY = 0;
    moveLeft = false;
    moveRight = false;
    shoot = false;
    hitLeftEdge = false;
    hitRightEdge = false;
    lives = 0;
}

Player::Player(string color, int startPos, int l){
    this->color = color;
    posX = startPos;
    posY = 500;
    lives = l;
}

void Player::drawPlayer(SDL_Renderer* ren){
    //example rectangle
    IMG_Init(IMG_INIT_JPG| IMG_INIT_PNG);
    SDL_Surface* playerSurface;

    if(color== "Red"){ 
        playerSurface = IMG_Load("Images/redPlayer.png");
        //SDL_SetRenderDrawColor(ren, 225, 0, 0, 255);
    } else{
        playerSurface = IMG_Load("Images/bluePlayer.png");
        //SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
    }
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(ren, playerSurface);
    SDL_FreeSurface(playerSurface); 
    
    //SDL_QueryTexture(playerTexture, NULL, NULL, &pWidth, &pHeight);
    //setPWidth();
    image.x = posX;
    image.y = posY; 
    image.w = 50;
    image.h = 50;
    SDL_RenderCopy(ren, playerTexture, NULL, &image);
    //SDL_RenderFillRect(ren, &image);
}
    
void Player::movePlayer(){

    if(moveLeft==true && hitLeftEdge==false){
        posX+= moveSpeed*(-1);
    }else if(moveRight==true && hitRightEdge ==false){
        posX+= moveSpeed;
    }
}

/*void Player::setPWidth(){

    SDL_Surface* playerSurface;
    IMG_Init(IMG_INIT_JPG| IMG_INIT_PNG);
    playerSurface = IMG_Load("Images/bluePlayer.png");
    SDL_Renderer * ren = nullptr;
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(ren, playerSurface);
    SDL_FreeSurface(playerSurface); 
    SDL_QueryTexture(playerTexture, NULL, NULL, &pWidth, &pHeight);
}
*/



int Player::getRightPos(){
    return posX+pWidth;
}


int Player::getTopPos(){
    return posY+pHeight;
}


void Player::minusLives(){
    lives--;
}