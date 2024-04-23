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
}

Player::Player(string color, int startPos){
    this->color = color;
    posX = startPos;
    posY = 500;
}

void Player::drawPlayer(SDL_Renderer* ren){
    //example rectangle
    if(color=="Red"){ //red or blue rectangle
        SDL_SetRenderDrawColor(ren, 225, 0, 0, 255);
    } else{
        SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
    }
    image.x = posX;
    image.y = posY; 
    image.w = 50;
    image.h = 25;
    SDL_RenderFillRect(ren, &image);
}
    
void Player::movePlayer(){

    if(moveLeft==true && hitLeftEdge==false){
        posX+= moveSpeed*(-1);
    }else if(moveRight==true && hitRightEdge ==false){
        posX+= moveSpeed;
    }


}
