#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class StartingScreen {
public:
    StartingScreen();
    ~StartingScreen();
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool runGame;
    SDL_Texture* playButton;
    SDL_Texture* instructionButton;
    SDL_Texture* quitButton;

    void initialize();
    void handleEvents();
    void render();
    void cleanup();
};

#endif
