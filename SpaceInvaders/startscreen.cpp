#include "startscreen.h"


StartingScreen::StartingScreen() { //will initialize everything thats involved in the starting screen

    window = NULL;

    renderer = NULL;

    font = NULL;

    runGame = true;

    playButton = NULL;

    instructionButton = NULL;

    quitButton = NULL;

    initialize();

}

StartingScreen::~StartingScreen() { //closes or destroys everything in the starting screen (I'm assuming this could be when the user presses a button or quits)

    cleanup();
}

void StartingScreen::run() { //function that activates the starting screen

    if(runGame) {

        handleEvents();
        
        update();

        render();
    }
}

void StartingScreen::initialize() { //creates window, and loads font and images for starting screen

    SDL_Init(SDL_INIT_VIDEO);

    TTF_INIT();

    window = SDL_CreateWindow("C++ Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERED_ACCELERATED);

    font = TTF_OpenFont("Font/Raleway.ttf", 64);
    if(!font) {

        cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << endl;
        return;
    }

    SDL_Surface* playSurface = IMG_Load("Graphics/play_button.png");
    if(!playSurface) {

        cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << endl;
        return;
    }

    playButton = SDL_CreateTextureFromSurface(renderer, playSurface);
    SDL_FreeSurface(playSurface);

    SDL_Surface* instructionSurface = IMG_Load("Graphics/instruction_button.png");
    if(!instructionSurface) {

        cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << endl;
        return;
    }

    instructionButton = SDL_CreateTextureFromSurface(renderer, instructionSurface);
    SDL_FreeSurface(instructionSurface);

    SDL_Surface* quitSurface = IMG_Load("Graphics/quit_button.png");
    if(!quitSurface) {

        cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << endl;
        return;
    }

    quitButton = SDL_CreateTextureFromSurface(renderer, quitSurface);
    SDL_FreeSurface(quitSurface);
}

void StartingScreen::handleEvents() { //function handles mouse clicks and the even that the user wants to quit the game

    SDL_Event event;

    while(SDL_PollEvent(&event)) {

        switch(event.type) {

            case SDL_QUIT:

                runGame = false;

                break;
                
            case SDL_MOUSEBUTTONDOWN:

                int x;

                int y;

                SDL_GetMouseState(&x, &y);

                if(x >= 100 && x <= 300 && y >= 200 && y <= 300) {

                    cout << "Starting the game..." << endl;

                    //Code to start game

                    runGame = false; //Change later
                }

                else if(x >= 100 && x <= 300 && y >= 350 && y <= 450) {

                    cout << "Showing instruction..." << endl;

                    //Insert game instructions
                }

                else if(x >= 100 && x <= 300 && y >= 500 && y <= 600) {

                    cout << "Quitting the game..." << endl;

                    runGame = false;
                }

                break;

            default:

                break;
        }
    }
}

void StartingScreen::update() { //I'm not sure I need anything here since it's just the starting screen

    //What should I add here?
}

void StartingScreen::render() { //draws the buttons with fonts onto the screen 

    SDL_RenderClear(renderer);

    SDL_Rect playRect = {100, 100, 200, 100};
    SDL_RenderCopy(renderer, playButton, nullptr, &playRect);

    SDL_Rect instructionRect = {100, 350, 200, 100};
    SDL_RenderCopy(renderer, instructionButton, nullptr, &instructionRect);

    SDL_Rect quitRect = {100, 500, 200, 100};
    SDL_RenderCopy(renderer, quitButton, nullptr, &quitRect);

    renderText("Play", 150, 230, {255, 255, 255, 255});

    renderText("Instructions", 120, 380, {255, 255, 255, 255});

    renderText("Quit", 160, 530, {255, 255, 255, 255});
    
    SDL_RenderPresent(renderer);
}

void StartingScreen::cleanup() { //releases all resources initialized properly

    SDL_DestroyTexture(playButton);
    SDL_DestroyTexture(instructionButton);
    SDL_DestroyTexture(quitButton);

    SDL_DetroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void StartingScreen::renderText(const string& text, int x, int y, const SDL_Color& color) { //renders text onto the screen at a given position, font and color

    SDL_Surface* textSurface = TTF_RenderText_Blender(font, text.c_str(), color);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {x, y, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}