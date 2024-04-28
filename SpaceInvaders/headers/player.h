#ifndef PLAYER
#define PLAYER 

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;


const int moveSpeed = 45;
const int pWidth = 50;
const int pHeight = 25;

class Player{
public:
    Player();
    Player(string color, int startPos);
    //~Player();

    void drawPlayer(SDL_Renderer* ren);
    void movePlayer();
    int getRightPos();
    int getTopPos();
    void minusLives();
    //void setPWidth();

    SDL_Rect image; //exmple image for player (just a rectangle rn)

    string color; //what team they are on

    int posX;
    int posY;
    int lives;


    bool hitLeftEdge;
    bool hitRightEdge;
    bool moveRight;
    bool moveLeft;
    bool shoot;

private:

};

#endif