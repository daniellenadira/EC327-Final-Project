#ifndef ALIEN
#define ALIEN

#include <iostream>
#include <string>
using namespace std;

#include <SDL.h>

const int aWidth = 50;
const int aHeight = 50;


class Alien{
    private:
		Alien * next;

    public:
		int posX;
		int posY;
		string color;
        bool hit;
        
		Alien(string color, Alien * a);
		Alien* getNext();
		void setNext(Alien * n);
        int getRightPos();
        int getTopPos();

    	SDL_Rect image; //upload alien image
};

#endif 