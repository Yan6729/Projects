##
## EPITECH PROJECT, 2026
## Arcade
## File description:
## CMakeLists.txt
##

cmake_minimum_required(VERSION 3.10)
project(Arcade)

# === COMPILER & FLAGS ===
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -fPIC -fno-gnu-unique")

# === DIRECTORIES ===
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/src)

# === DEPENDENCIES (LIBRARIES) ===

# SFML
find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

# SDL2
find_package(SDL2 REQUIRED)
find_library(SDL2_IMAGE_LIB NAMES SDL2_image REQUIRED)
find_path(SDL2_IMAGE_INCLUDE_DIR NAMES SDL_image.h PATH_SUFFIXES SDL2)
find_library(SDL2_TTF_LIB NAMES SDL2_ttf REQUIRED)
find_path(SDL2_TTF_INCLUDE_DIR NAMES SDL_ttf.h PATH_SUFFIXES SDL2)

# NCurses
find_package(Curses REQUIRED)

# Allegro5
find_library(ALLEGRO_LIB         NAMES allegro)
find_library(ALLEGRO_FONT_LIB    NAMES allegro_font)
find_library(ALLEGRO_TTF_LIB     NAMES allegro_ttf)
find_library(ALLEGRO_PRIM_LIB    NAMES allegro_primitives)
find_library(ALLEGRO_IMAGE_LIB   NAMES allegro_image)  # FIX: manquant

# Libcaca
find_library(CACA_LIB NAMES caca REQUIRED)


# === CORE ===
file(GLOB CORE_SOURCES CONFIGURE_DEPENDS "src/core/*.cpp")

add_executable(arcade ${CORE_SOURCES})
target_link_libraries(arcade PRIVATE dl)

# === GRAPHICAL LIBRARIES ===

# --- SFML ---
file(GLOB SFML_SOURCES CONFIGURE_DEPENDS "src/graphics/sfml/*.cpp")
add_library(arcade_sfml SHARED ${SFML_SOURCES})
target_link_libraries(arcade_sfml sfml-graphics sfml-window sfml-system)
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

# --- SDL2 ---
file(GLOB SDL2_SOURCES CONFIGURE_DEPENDS "src/graphics/sdl2/*.cpp")
add_library(arcade_sdl2 SHARED ${SDL2_SOURCES})
target_include_directories(arcade_sdl2 PRIVATE ${SDL2_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(arcade_sdl2 PRIVATE SDL2::SDL2 ${SDL2_IMAGE_LIB} ${SDL2_TTF_LIB})
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

# --- NCurses ---
file(GLOB NCURSES_SOURCES CONFIGURE_DEPENDS "src/graphics/ncurses/*.cpp")
add_library(arcade_ncurses SHARED ${NCURSES_SOURCES})
target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})
set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

# --- Allegro5 ---
file(GLOB ALLEGRO5_SOURCES CONFIGURE_DEPENDS "src/graphics/allegro5/*.cpp")
add_library(arcade_allegro5 SHARED ${ALLEGRO5_SOURCES})
target_link_libraries(arcade_allegro5
    ${ALLEGRO_LIB}
    ${ALLEGRO_FONT_LIB}
    ${ALLEGRO_TTF_LIB}
    ${ALLEGRO_PRIM_LIB}
    ${ALLEGRO_IMAGE_LIB}  # FIX: manquant
)
set_target_properties(arcade_allegro5 PROPERTIES PREFIX "")

# --- Libcaca ---
file(GLOB LIBCACA_SOURCES CONFIGURE_DEPENDS "src/graphics/Libcaca/*.cpp")
add_library(arcade_libcaca SHARED ${LIBCACA_SOURCES})
target_link_libraries(arcade_libcaca ${CACA_LIB})
set_target_properties(arcade_libcaca PROPERTIES PREFIX "")


# === GAMES LIBRARIES ===

# --- Snake ---
set(SNAKE_SOURCES
    "src/games/snakeGame.cpp"
    "src/games/utilities.cpp"
)
add_library(arcade_snake SHARED ${SNAKE_SOURCES})
set_target_properties(arcade_snake PROPERTIES PREFIX "")

# --- Pacman ---
set(PACMAN_SOURCES
    "src/games/pacmanGame.cpp"
    "src/games/utilities.cpp"
    "src/games/mazeGenerator.cpp"
    "src/games/pacmanGhost.cpp"
)
add_library(arcade_pacman SHARED ${PACMAN_SOURCES})
set_target_properties(arcade_pacman PROPERTIES PREFIX "")

# --- Nibbler ---
set(NIBBLER_SOURCES
    "src/games/nibblerGame.cpp"
    "src/games/utilities.cpp"
    "src/games/mazeGenerator.cpp"
)
add_library(arcade_nibbler SHARED ${NIBBLER_SOURCES})
set_target_properties(arcade_nibbler PROPERTIES PREFIX "")
