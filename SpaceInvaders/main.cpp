#include "game.h"
#include "startscreen.h"


int main(int argc, char* args[] ){

    //make an initial screen here and button that when they press will then close that window and bring up the game screen
    StartingScreen s(0);
    int next = s.run();
    s.~StartingScreen();
    
    //the game
    int round = 0;
    int score = 0;
    int oldScore = 0;
    int* ptr;
    bool go = true;
    int p1Lives = 3;
    int p2Lives = 3;

    while(next == 1){
        do{
            round++;
            Game* g = new Game(round, score, p1Lives, p2Lives);
            ptr = g->loop();
            delete g;
            score = ptr[0];
            p1Lives = ptr[1];
            p2Lives = ptr[2];
            if((ptr[1]+ptr[2])<=0){
                go = false;
            }
        }while(go);

        //score to put on leaderboard
        cout<< "Total aliens killed: "<<score<<endl;
        if(score>oldScore){
            oldScore = score;
        }
        StartingScreen s(oldScore);
        next = s.run();
        s.~StartingScreen();
        round = 0;
        score = 0;
        p1Lives = 3;
        p2Lives = 3;
        go = true;

    }
    //make an ending screen with leaderboard and ability to play again?
    

    return 0;
}
