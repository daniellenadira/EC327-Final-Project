#include "bullet.h"

bullet::bullet(int x, int y, string c, bullet * b) {
	posX = x;
	posY = y;
    next = b;
    hitEdge = false;
    color = c;
}


bullet* bullet::getNext()  {
	return next;
}

void bullet::setNext(bullet * n) {
	this->next = n;
}

