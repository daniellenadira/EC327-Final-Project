#include "startscreen.h"

StartingScreen::StartingScreen() {
    window = nullptr;
    renderer = nullptr;
    runGame = true;
    playButton = nullptr;
    instructionButton = nullptr;
    quitButton = nullptr;
    initialize();
}

StartingScreen::~StartingScreen() {
    cleanup();
}

void StartingScreen::run() {
    if (runGame) {
        handleEvents();
        render();
    }
}

void StartingScreen::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("C++ Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* playSurface = IMG_Load("Graphics/play_button.png");
    if (!playSurface) {
        std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    playButton = SDL_CreateTextureFromSurface(renderer, playSurface);
    SDL_FreeSurface(playSurface);
    SDL_Surface* instructionSurface = IMG_Load("Graphics/instruction_button.png");
    if (!instructionSurface) {
        std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    instructionButton = SDL_CreateTextureFromSurface(renderer, instructionSurface);
    SDL_FreeSurface(instructionSurface);
    SDL_Surface* quitSurface = IMG_Load("Graphics/quit_button.png");
    if (!quitSurface) {
        std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    quitButton = SDL_CreateTextureFromSurface(renderer, quitSurface);
    SDL_FreeSurface(quitSurface);
}

void StartingScreen::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                runGame = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= 100 && x <= 300 && y >= 200 && y <= 300) {
                    std::cout << "Starting the game..." << std::endl;
                    runGame = false; // Temporary, replace with actual game starting logic
                } else if (x >= 100 && x <= 300 && y >= 350 && y <= 450) {
                    std::cout << "Showing instruction..." << std::endl;
                    // Insert code to show instructions
                } else if (x >= 100 && x <= 300 && y >= 500 && y <= 600) {
                    std::cout << "Quitting the game..." << std::endl;
                    runGame = false;
                }
                break;
            default:
                break;
        }
    }
}

void StartingScreen::render() {
    SDL_RenderClear(renderer);
    SDL_Rect playRect = {100, 100, 200, 100};
    SDL_RenderCopy(renderer, playButton, nullptr, &playRect);
    SDL_Rect instructionRect = {100, 350, 200, 100};
    SDL_RenderCopy(renderer, instructionButton, nullptr, &instructionRect);
    SDL_Rect quitRect = {100, 500, 200, 100};
    SDL_RenderCopy(renderer, quitButton, nullptr, &quitRect);
    SDL_RenderPresent(renderer);
}

void StartingScreen::cleanup() {
    SDL_DestroyTexture(playButton);
    SDL_DestroyTexture(instructionButton);
    SDL_DestroyTexture(quitButton);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
