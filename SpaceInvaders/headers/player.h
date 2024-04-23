#ifndef PLAYER
#define PLAYER 

#include <iostream>
#include <string>
#include <SDL.h>
using namespace std;


const int moveSpeed = 25;

class Player{
public:
    Player();
    Player(string color, int startPos);
    //~Player();

    void drawPlayer(SDL_Renderer* ren);
    void movePlayer();
    SDL_Rect image; //exmple image for player (just a rectangle rn)

    string color; //what team they are on
    int posX;
    int posY;


    bool hitLeftEdge;
    bool hitRightEdge;
    bool moveRight;
    bool moveLeft;
    bool shoot;

private:

};

#endif