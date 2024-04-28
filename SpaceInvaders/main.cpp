#include "game.h"
#include "startscreen.h"


int main(int argc, char* args[] ){

    //make an initial screen here and button that when they press will then close that window and bring up the game screen
    //StartingScreen s;

    //the game
    int round = 0;
    int score = 0;
    int* ptr;
   do{
        round++;
        Game g(round);
        ptr = g.loop();
        score += ptr[0]+ptr[1];
        cout<<"Red score:"<<ptr[0]<< " Blue Score:" << ptr[1]<<endl;
    }while(ptr[2]>0);
    //score to put on leaderboard
    cout<< "Total aliens killed: "<<score<<endl;

    //make an ending screen with leaderboard and ability to play again?
    

    return 0;
}
