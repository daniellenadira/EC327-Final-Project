//the stack that holds all of the bullets
#include "bullet.h"


class stack{
public:
    stack();
    ~stack();

	void append(int x, int y, string c); //add to the beginning
	void remove(int x, int y); //remove at an x/y position

    int numBullets;
    bullet* head;

	void drawBullet(SDL_Renderer* ren);
	void moveBullet();
    void checkForOffScreen();

};