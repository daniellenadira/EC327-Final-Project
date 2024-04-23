#ifndef ALIEN
#define ALIEN

#include <iostream>
#include <string>
using namespace std;

#include <SDL.h>


class Alien{
public:
    Alien();
    Alien(string team, int num); //team Red or Blue
    ~Alien();
    void drawAlien(SDL_Renderer* ren);
    void moveAlien(bool edge);

    int posX;
    int posY;
    int moveSpeed;

    SDL_Rect image; //the alien image, rn its just a rectangle 

private:
    string color;
    int num; //which alien it is in the array of all of them


};

#endif 