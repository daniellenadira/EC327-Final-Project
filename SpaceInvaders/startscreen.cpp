#include "startscreen.h"

StartingScreen::StartingScreen(int s) {
    static int first = 0;//first time there is no score but after its technechly the end screen so show score
    first++;
    window = nullptr;
    renderer = nullptr;
    runGame = true;
    playButton = nullptr;
    instructionButton = nullptr;
    quitButton = nullptr;
    showInstructions = false;
    score = s;
    initialize();
}

StartingScreen::~StartingScreen() {
    cleanup();
}

int StartingScreen::run() {
    int next = 0;
    while(runGame) {
        next = handleEvents();
        render();
    }
    return next;
}

void StartingScreen::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
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
    
    SDL_Surface* instruction2Surface = IMG_Load("Graphics/InstructionsP2.png");
    if (!instruction2Surface) {
        std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    instruction2Button = SDL_CreateTextureFromSurface(renderer, instruction2Surface);
    SDL_FreeSurface(instruction2Surface);

    SDL_Surface* backSurface = IMG_Load("Graphics/Back.png");
    if (!backSurface) {
        std::cerr << "Failed to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        return;
    }
    backButton = SDL_CreateTextureFromSurface(renderer, backSurface);
    SDL_FreeSurface(backSurface);

    
    TTF_Font* Sans = TTF_OpenFont("Graphics/Sans.ttf", 300);
    SDL_Color White = {255, 255, 255};
    string text = "High Score: " + to_string(score);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White); 
    if (!surfaceMessage) {
        std::cerr << "Failed to load text! TTF Error: " << TTF_GetError() << std::endl;
        return;
    }
    TTF_CloseFont(Sans);
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    
}

int StartingScreen::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                runGame = false;
                return -1;
            case SDL_MOUSEBUTTONDOWN:
                int x, y;
                SDL_GetMouseState(&x, &y);

                if(showInstructions==false){
                    if (x >= 200 && x <= 400 && y >= 200 && y <= 300) {
                        std::cout << "Starting the game..." << std::endl;
                        runGame = false; 
                        return 1;
                    } else if (x >= 150 && x <= 550 && y >= 400 && y <= 500) {
                        std::cout << "Showing instruction..." << std::endl;
                        showInstructions = true;
                        return 0;
                    } else if (x >= 200 && x <= 400 && y >= 600 && y <= 700) {
                        std::cout << "Quitting the game..." << std::endl;
                        runGame = false;
                        return -1;
                    }
                }else{
                    if (x >= 25 && x <= 225 && y >= 25 && y <= 125) {
                        std::cout << "Going Back..." << std::endl;
                        showInstructions = false;
                        return 0;
                    }
                }
            default:
                return -1;
        }
    }
    return 0;
}

void StartingScreen::render() {
    if(showInstructions){

    SDL_RenderClear(renderer);
    SDL_Rect backRect = {25, 25, 200, 100};
    SDL_RenderCopy(renderer, backButton, nullptr, &backRect);
    SDL_Rect instruction2Rect = {100, 200, 600, 500};
    SDL_RenderCopy(renderer, instruction2Button, nullptr, &instruction2Rect);
    SDL_RenderPresent(renderer);

    }else{
    SDL_RenderClear(renderer);
    SDL_Rect playRect = {200, 200, 200, 100};
    SDL_RenderCopy(renderer, playButton, nullptr, &playRect);
    SDL_Rect instructionRect = {150, 400, 400, 100};
    SDL_RenderCopy(renderer, instructionButton, nullptr, &instructionRect);
    SDL_Rect quitRect = {200, 600, 200, 100};
    SDL_RenderCopy(renderer, quitButton, nullptr, &quitRect);


    SDL_Rect Message_rect; //create a rect
    Message_rect.x = 200;  //controls the rect's x coordinate 
    Message_rect.y = 25; // controls the rect's y coordinte
    Message_rect.w = 400; // controls the width of the rect
    Message_rect.h = 100; // controls the height of the rect

    SDL_RenderCopy(renderer, Message, nullptr, &Message_rect);

    SDL_RenderPresent(renderer);
    }
}

void StartingScreen::cleanup() {
    SDL_DestroyTexture(playButton);
    SDL_DestroyTexture(instructionButton);
    SDL_DestroyTexture(quitButton);
    SDL_DestroyTexture(instruction2Button);
    SDL_DestroyTexture(backButton);
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

