#ifndef STARTSCREEN
#define STARTSCREEN

#include <iostream> 
#include <string>

using namespace std;

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class StartingScreen {

    public:

        StartingScreen();
        ~StartingScreen();
        void run();

    private:

    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    bool runGame;
    SDL_Texture* playButton;
    SDL_Texture* instructionButton;
    SDL_Texture* quitButton;
    void intialize();
    void handleEvents();
    void update();
    void render();
    void cleanup();
    void renderText(const string& text, int x, int y, const SDL_Color& color);
};

#endif