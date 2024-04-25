#include "stack.h"

stack::stack(){
	numBullets = 0;
	head = nullptr;
    timeBetweenBullets = 0;
}


stack::~stack(){
	for(int i = 0; i<numBullets;i++){
		bullet* temp = head;
		head = temp->getNext();
		delete temp;
	}
}

void stack::append(int x, int y, string c){
    bullet* temp = this->head;
	this->head = new bullet(x, y, c, temp);
	this->numBullets++;
}

void stack::remove(int x, int y){
    //if its the first one
    bullet* temp = this->head;
    if(x==temp->posX&&y==temp->posY){
        head = temp->getNext();
        delete temp;
        numBullets--;
        return;
    }

    temp = temp->getNext(); //should be pointing to 2
    bullet* before = this->head; //pointing to 1

    for(int i= 0; i<numBullets;i++){
        if(x==temp->posX&&y==temp->posY){
            if(i==numBullets-1){//means its the last one
                before->setNext(nullptr);
            }else{
                before->setNext(temp->getNext());
            }
            delete temp;
            numBullets--;
            return;
        }
        temp = temp->getNext();
        before = before->getNext();
    }

    cout<< "Error there was nothing to remove"<<endl;
}


void stack::drawBullet(SDL_Renderer* ren){
    bullet* temp = head;
    for(int i = 0; i<numBullets; i++){
        //example rectangle
        if(temp->color=="Red"){ //red or blue rectangle
            SDL_SetRenderDrawColor(ren, 225, 0, 0, 255);
        } else if (temp->color == "Blue"){
            SDL_SetRenderDrawColor(ren, 0, 0, 225, 255);
        }else{
            SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        }
        temp->image.x = temp->posX;
        temp->image.y = temp->posY; 
        temp->image.w = bWidth;
        temp->image.h = bHeight;
        SDL_RenderFillRect(ren, &temp->image);
        temp = temp->getNext();
    }
}

void stack::moveBullet(int speed){
    bullet* temp = head;

    for(int i = 0; i< numBullets; i++){
        temp->posY += speed;
        temp = temp->getNext();
    }
}

void stack::checkForOffScreen(){
    bullet* temp = head;
    while(temp!=nullptr){
        if(temp->posY+bHeight<0 || temp->posY>600){
            //cout<<"debug remove x:"<<temp->posX<< " y:"<<temp->posY << " numB:" <<numBullets<<endl;
            remove(temp->posX, temp->posY);
        }
        temp = temp->getNext();
    }
}



void stack::printStack(){
    bullet* temp = head;
    for(int i = 0; i<numBullets; i++){
        cout<< "bullet #"<< i << " xpos:"<< temp->posX << " ypos:"<< temp->posY <<endl;
        temp = temp->getNext();
    }
    cout<< endl;
}