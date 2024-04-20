#include "alien.h"
#include "game.h"

Alien::Alien(){
    color = "Red"; //defalut to red idk
    num = 0;
}

Alien::Alien(string team, int num){
    color = team;
    this->num = num; //which alien it is in the array
}

Alien::~Alien(){
    //put destructors here
}

void Alien::drawAlien(SDL_Renderer* ren){
    //example rectangle
    SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x = rect.y= 0+(num*10); // just moving the spots over
    cout <<"pos: "<< rect.x << endl;
    rect.w=50;
    rect.h = 50;
    SDL_RenderFillRect(ren, &rect);
}