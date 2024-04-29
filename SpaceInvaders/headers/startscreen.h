#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class StartingScreen {
public:
    StartingScreen(int s);
    ~StartingScreen();
    int run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool runGame;
    SDL_Texture* playButton;
    SDL_Texture* instructionButton;
    SDL_Texture* quitButton;
    SDL_Texture* instruction2Button;
    SDL_Texture* backButton;
    SDL_Texture* Message;
    bool showInstructions;
    int score;


    void initialize();
    int handleEvents();
    void render();
    void cleanup();
};

#endif
