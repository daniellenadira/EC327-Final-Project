#include "alien.h"

Alien::Alien(){
    color = "";
    num = 0;
}

Alien::Alien(string team, int num){
    color = team;
    this->num = num; //which alien it is in the array

    moveSpeed = 30;

    posX = 50+num*100; //this spacing will have to change when we upload the image
    posY = 100;

}

Alien::~Alien(){
    //put destructors here
}

void Alien::drawAlien(SDL_Renderer* ren){
    
    //example rectangle
    if(color=="Red"){ //red or blue rectangle
        SDL_SetRenderDrawColor(ren, 225, 0, 0, 255);
    } else{
        SDL_SetRenderDrawColor(ren, 0, 0, 225, 255);
    }
    image.x = posX;
    image.y = posY; 
    image.w = 50;
    image.h = 50;
    SDL_RenderFillRect(ren, &image);
    
}

void Alien::moveAlien(bool edge){

    if(edge){
        moveSpeed = moveSpeed*(-1);
    }
    posX+= moveSpeed;
    //posY+= 25;
    
}
