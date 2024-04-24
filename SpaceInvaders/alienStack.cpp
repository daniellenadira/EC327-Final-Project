#include "alienStack.h"

alienStack::alienStack(){
	numRedAliens = 0;
    numBlueAliens = 0;
	head = nullptr;
    moveSpeed = 25;
}


alienStack::~alienStack(){
	for(int i = 0; i<(numRedAliens+numBlueAliens);i++){
		Alien* temp = head;
		head = temp->getNext();
		delete temp;
	}
}

void alienStack::append( string c){
    Alien* temp = this->head;
	this->head = new Alien(c, temp);
    if(c=="Red"){
        this->numRedAliens++;
    }else{ this->numBlueAliens++;}
}

void alienStack::remove(int x, int y){
    //if its the first one
    Alien* temp = this->head;
    if(x==temp->posX && y==temp->posY){
        head = temp->getNext();
        if(temp->color=="Red"){
            this->numRedAliens++;
        }else{ this->numBlueAliens++;}
        delete temp;

        cout << "first one being removed" <<endl;
        printStack();

        return;
    }

    temp = temp->getNext(); //should be pointing to 2
    Alien* before = this->head; //pointing to 1

    for(int i= 0; i<(numRedAliens+numBlueAliens);i++){
        if(x==temp->posX&&y==temp->posY){
            if(i=(numRedAliens+numBlueAliens)-1){//means its the last one
                //cout<< "last one being removed i:"<< i<< " tot:"<< numBullets<< endl; 
                before->setNext(nullptr);
            }else{
                before->setNext(temp->getNext());
            }
            cout<<"removed at x:"<< temp->posX<<" and y:"<< temp->posY<<endl;
            if(temp->color=="Red"){
                this->numRedAliens++;
            }else{ this->numBlueAliens++;}
            delete temp;
            printStack();
            return;
        }
        temp = temp->getNext();
        before = before->getNext();
    }

    cout<< "Error there was nothing to remove"<<endl;
}


void alienStack::drawAlien(SDL_Renderer* ren){
    Alien* temp = head;
    for(int i = 0; i<(numRedAliens+numBlueAliens); i++){
        //example rectangle
        if(temp->color=="Red"){ //red or blue rectangle
            SDL_SetRenderDrawColor(ren, 225, 0, 0, 255);
        } else{
            SDL_SetRenderDrawColor(ren, 0, 0, 225, 255);
        }
        temp->image.x = temp->posX;
        temp->image.y = temp->posY; 
        temp->image.w = aWidth;
        temp->image.h = aHeight;
        SDL_RenderFillRect(ren, &temp->image);
        temp = temp->getNext();
    }
    
}

void alienStack::moveAlien(){
    Alien* temp = head;
    //check to see if at edge of screen
    if(temp->posX+aWidth>800){ //check for left side
        moveSpeed = moveSpeed*(-1);
    }else{ //check for right size
        while(temp->getNext()!=nullptr){
            temp = temp->getNext();
        }  
        if(temp->posX<0){
            moveSpeed = moveSpeed*(-1);
        }
    }
    temp = head;
    for(int i = 0; i< (numRedAliens+numBlueAliens); i++){
        temp->posX+= moveSpeed;
        temp = temp->getNext();
    }    
}


void alienStack::printStack(){
    Alien* temp = head;
    for(int i = 0; i<(numRedAliens+numBlueAliens); i++){
        cout<<" i:"<<i<<" num:"<<(numRedAliens+numBlueAliens)<<endl;
        cout<< "Alien #"<< i << " xpos:"<< temp->posX << " ypos:"<< temp->posY <<endl;
        temp = temp->getNext();
    }
    cout<< endl;
}