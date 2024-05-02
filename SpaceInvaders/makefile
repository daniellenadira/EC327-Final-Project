# Define project directories
SRC_DIR = .
HEADER_DIR = headers
BUILD_DIR = build/debug

# Define compiler and linker
CC = g++
# Define compiler flags
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g

# Define header include paths
SDL_INCLUDE_PATH = /usr/local/include/SDL2  # Path to SDL2 headers
SDL_IMAGE_INCLUDE_PATH = /usr/local/include/SDL2/SDL_image.h
SDL_TTF_INCLUDE_PATH = /usr/local/include/SDL2/SDL2_ttf

INCLUDE_PATHS = -I$(HEADER_DIR) -I$(SRC_DIR)/SDL2 -I$(SDL_INCLUDE_PATH) -I$(SDL_IMAGE_INCLUDE_PATH) -I$(SDL_TTF_INCLUDE_PATH)

# Define library linking flags for SDL2_image
LINKER_FLAGS = -lsdl2 -lSDL2_image -lSDL2_ttf

# Define library search path for SDL2_image
SDL_IMAGE_PATH = /usr/local/Cellar/sdl2_image/2.8.2_1/lib 
SDL_TTF_PATH = /usr/local/Cellar/SDL2_ttf/2.8.2_1/lib 
LIBRARY_PATHS = -L$(SDL_IMAGE_PATH) -L$(SDL_TTF_PATH)

# Define source code files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HEADER_FILES = $(wildcard $(HEADER_DIR)/*.h)

# Define object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Target rule (default rule when you run make)
all: $(BUILD_DIR)/SpaceInvaders

# Define rule to create the build directory
$(BUILD_DIR):
	mkdir -p $@

# Define rule to compile each source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_FILES) | $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) -c $< -o $@

# Define rule to link all object files into the final executable
$(BUILD_DIR)/SpaceInvaders: $(OBJ_FILES) | $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(LIBRARY_PATHS) $(LINKER_FLAGS) $(OBJ_FILES) -o $@

# Rule to clean up object files
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)

# Target to run the executable
run: $(BUILD_DIR)/SpaceInvaders
	./$(BUILD_DIR)/SpaceInvaders

.PHONY: all clean run
