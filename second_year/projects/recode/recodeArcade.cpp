/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** recodeArcade
*/

#include "recodeArcade.hpp"

GameState createMaze()
{
    GameState state;
    state.width = 5;
    state.height = 5;
    state.grid = {
	{{CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}},
        {{CellType::WALL, '#', "wall.png"}, {CellType::PLAYER, 'P', "palyer.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::WALL, '#', "wall.png"}},
	{{CellType::WALL, '#', "wall.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::WALL, '#', "wall.png"}},
	{{CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::WALL, '#', "wall.png"}, {CellType::FOOD, '@', "wall.png"}, {CellType::WALL, '#', "wall.png"}},
	{{CellType::SCORE_ZONE, 's', "score.png"}, {CellType::EMPTY, '#', "empty.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::EMPTY, ' ', "empty.png"}, {CellType::EMPTY, '#', "empty.png"}}
    };
    state.gameOver = false;
    state.message = "Welcome to the game";
    return state;
}

void renderText(const GameState& state)
{
    for (size_t a = 0; a < state.height; a++) {
	for (size_t b = 0; b < state.width; b++) {
	}
    }
}
