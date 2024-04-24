//the stack that holds all of the bullets
#include "bullet.h"



class stack{
public:
    stack();
    ~stack();

	void append(int x, int y, string c); //add to the beginning
	void remove(int x, int y); //remove at an x/y position

    const int playerBulletSpeed = -45;
    const int alienBulletSpeed = 15;
    int timeBetweenBullets;

    int numBullets;
    bullet* head;

	void drawBullet(SDL_Renderer* ren);
	void moveBullet(int speed);
    void checkForOffScreen();
    void checkAlienHit();
    void printStack();

};