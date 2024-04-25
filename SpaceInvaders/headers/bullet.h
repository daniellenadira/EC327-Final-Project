//each bullet to then go into a stack

#include <iostream>
#include <string>
#include <SDL.h>
using namespace std;

const int bWidth = 5;
const int bHeight = 5;

class bullet{
    private:
		bullet * next;
	public:
		int posX;
		int posY;
		bullet(int x, int y, string color, bullet * b);
		bullet* getNext();
		void setNext(bullet * b);
        int getRightPos();
        int getTopPos();

		
    	SDL_Rect image; //upload bullet image
		string color;
		bool hitEdge;
};

