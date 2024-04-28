//the stack that holds all of the aleins
#include "alien.h"
#include "SDL_image.h"


class alienStack{
public:
    alienStack();
    ~alienStack();

	void append(string c, int num); //add to the beginning
	void remove(int x, int y); //remove at an x/y position

    int moveSpeed;

    int numRedAliens;
    int numBlueAliens;
    
    Alien* head;

    void drawAlien(SDL_Renderer* ren);
    void moveAlien();
    void hitEdge();

    void hit();

    void printStack();

};