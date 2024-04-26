#include "alien.h"

Alien::Alien(string c, Alien * a, int num) {
    int h = 100;
    while(num>6){
        h+=75;
        num-=6;
    }
	posX = aWidth+num*100; //can change this spacing
	posY = h; //can change this spacing too
    next = a;
    color = c;
    hit = false;
}


Alien* Alien::getNext()  {
	return next;
}

void Alien::setNext(Alien * n) {
	this->next = n;
}



int Alien::getRightPos(){
    return posX+aWidth;
}

int Alien::getTopPos(){
    return posY+aHeight;
}
