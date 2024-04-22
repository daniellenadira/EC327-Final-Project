#include "alien.h"

Alien::Alien(){
    color = "Red"; //defalut to red idk
    num = 0;
    //cout << " default alien created"<< endl;
}

Alien::Alien(string team, int num){
    color = team;
    this->num = num; //which alien it is in the array

    moveSpeed = 30;

    posX = 50+num*100;
    posY = 100;

}

Alien::~Alien(){
    //put destructors here
}

void Alien::drawAlien(SDL_Renderer* ren){
    
    //example rectangle
    //make a color to delete it before you move it
    if(color=="Red"){ //red or blue rectangle
        SDL_SetRenderDrawColor(ren, REDX, REDY, REDZ, 255);
    } else{
        SDL_SetRenderDrawColor(ren, BLUEX, BLUEY, BLUEZ, 255);
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