##
## EPITECH PROJECT, 2026
## Arcade
## File description:
## Makefile
##

# === COMPILER ===
CXX		=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++20 -fPIC -fno-gnu-unique

# === DIRECTORIES ===
SRC_CORE	=	src/core
SRC_GFX		=	src/graphics
SRC_GAMES	=	src/games
LIB_DIR		=	lib

# === OUTPUT ===
BIN		=	arcade

# === LIBDL ===
LDLIBS		=	-ldl

# === GRAPHICS FLAGS ===
SFML_FLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system
SDL2_FLAGS	=	-lSDL2 -lSDL2_ttf -lSDL2_image
NCURSES_FLAGS	=	-lncurses
ALLEGRO5_FLAGS	=	-lallegro -lallegro_font -lallegro_ttf -lallegro_primitives -lallegro_image
LIBCACA_FLAGS	=	-lcaca


# === SOURCES ===
CORE_SRC	=	$(wildcard $(SRC_CORE)/*.cpp)

SFML_SRC	=	$(wildcard $(SRC_GFX)/sfml/*.cpp)
SDL2_SRC	=	$(wildcard $(SRC_GFX)/sdl2/*.cpp)
NCURSES_SRC	=	$(wildcard $(SRC_GFX)/ncurses/*.cpp)
ALLEGRO5_SRC	=	$(wildcard $(SRC_GFX)/allegro5/*.cpp)
LIBCACA_SRC	=	$(wildcard $(SRC_GFX)/Libcaca/*.cpp)


SNAKE_SRC	=	$(SRC_GAMES)/snakeGame.cpp \
				$(SRC_GAMES)/utilities.cpp	
PACMAN_SRC	=	$(SRC_GAMES)/pacmanGame.cpp	\
				$(SRC_GAMES)/utilities.cpp	\
				$(SRC_GAMES)/mazeGenerator.cpp	\
				$(SRC_GAMES)/pacmanGhost.cpp

NIBBLER_SRC	=	$(SRC_GAMES)/nibblerGame.cpp	\
				$(SRC_GAMES)/utilities.cpp	\
				$(SRC_GAMES)/mazeGenerator.cpp

MARIO_SRC	=	$(SRC_GAMES)/marioGame.cpp	\
				$(SRC_GAMES)/utilities.cpp

# === OBJECTS ===
CORE_OBJ	=	$(CORE_SRC:.cpp=.o)

# === LIBRARIES ===
SFML_LIB	=	$(LIB_DIR)/arcade_sfml.so
SDL2_LIB	=	$(LIB_DIR)/arcade_sdl2.so
NCURSES_LIB	=	$(LIB_DIR)/arcade_ncurses.so
ALLEGRO5_LIB	=	$(LIB_DIR)/arcade_allegro5.so
LIBCACA_LIB	=	$(LIB_DIR)/arcade_libcaca.so


SNAKE_LIB	=	$(LIB_DIR)/arcade_snake.so
PACMAN_LIB	=	$(LIB_DIR)/arcade_pacman.so
NIBBLER_LIB	=	$(LIB_DIR)/arcade_nibbler.so
MARIO_LIB	=	$(LIB_DIR)/arcade_mario.so

# === RULES ===

all: core graphicals games

# === CORE ===
core: $(BIN)

$(BIN): $(CORE_OBJ)
	$(CXX) -o $(BIN) $(CORE_OBJ) $(LDLIBS)

# === GRAPHICAL LIBS ===
graphicals: $(SFML_LIB) $(SDL2_LIB) $(NCURSES_LIB) $(ALLEGRO5_LIB) $(LIBCACA_LIB)


$(SFML_LIB): $(SFML_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(SFML_FLAGS)

$(SDL2_LIB): $(SDL2_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(SDL2_FLAGS)

$(NCURSES_LIB): $(NCURSES_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(NCURSES_FLAGS)

$(ALLEGRO5_LIB): $(ALLEGRO5_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(ALLEGRO5_FLAGS)

$(LIBCACA_LIB): $(LIBCACA_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^ $(LIBCACA_FLAGS)


# === GAMES ===
games: $(SNAKE_LIB) $(PACMAN_LIB) $(NIBBLER_LIB) $(MARIO_LIB)

$(SNAKE_LIB): $(SNAKE_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

$(PACMAN_LIB): $(PACMAN_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

$(NIBBLER_LIB):	$(NIBBLER_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

$(MARIO_LIB):	$(MARIO_SRC)
	mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

# === CLEAN ===
clean:
	rm -f $(CORE_OBJ)

fclean: clean
	rm -f $(BIN)
	rm -rf $(LIB_DIR)

re: fclean all

# === PHONY ===
.PHONY: all core graphicals games clean fclean re
