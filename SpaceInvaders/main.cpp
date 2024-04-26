#include "game.h"
#include "startscreen.h"


int main(int argc, char* args[] ){

    //make an initial screen here and button that when they press will then close that window and bring up the game screen
    //StartingScreen s;

    //the game
    Game g;
    int score = g.loop();

    //score to put on leaderboard
    cout<<"Score:"<<score<<endl;


    //make an ending screen with leaderboard and ability to play again?
    

    return 0;
}

