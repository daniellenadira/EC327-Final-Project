# EC327-Final-Project
EC327 Final Project Space Invaders


Windows compile command:
g++ -std=c++17 -Wall -O0 -g -Iheaders -Isrc/SDL2 -Lsrc/lib -o game main.cpp game.cpp alien.cpp player.cpp stack.cpp bullet.cpp alienStack.cpp startscreen.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

MAC OS:
  In the terminal run the following commands to install the SDL2 SDL2_image and SDL2_ttf libraries.
    brew install sdl2
    brew install sdl2_image
    brew install sdl2_ttf

  Check that these libraries are installed in the standard system directory by checking the following paths:
    SDL2: /usr/local/include/SDL2
    SDL2_image: /usr/local/include/SDL2/SDL_image.h
    SDL2_ttf: /usr/local/include/SDL2/SDL2_ttf

  Use the provided Makefile. However, ensure that the Makefile matches the paths of the SDL2 libraries on your system. You may need to modify the Makefile accordingly. 
    In the terminal type in: make run
    This should automatically run the executable.

  Alternatively you can run this Compile Command instead of the make file: g++ -std=c++17 -Wall -O0 -g -Iheaders -I./SDL2 -I/usr/local/include/SDL2 - I/usr/local/include/SDL2/SDL_image.h -I/usr/local/include/SDL2/SDL2_ttf alien.cpp alienStack.cpp bullet.cpp game.cpp main.cpp player.cpp stack.cpp startscreen.cpp -o game       L/usr/local/Cellar/sdl2_image/2.8.2_1/lib -lSDL2 -lSDL2_image -lSDL2_ttf

