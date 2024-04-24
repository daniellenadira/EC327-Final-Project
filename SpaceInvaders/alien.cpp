#include "alien.h"

Alien::Alien(string c, Alien * a) {
    static int numAliens = 0;
    numAliens++;
	posX = aWidth+numAliens*100; //can change this spacing
	posY = 100; //can change this spacing too
    next = a;
    color = c;
}


Alien* Alien::getNext()  {
	return next;
}

void Alien::setNext(Alien * n) {
	this->next = n;
}




