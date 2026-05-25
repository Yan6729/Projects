/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** recodeArcade
*/

#ifndef RECODEARCADE_HPP_
    #define RECODEARCADE_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    using namespace std;

enum class CellType {
    EMPTY,
    WALL,
    PLAYER,
    ENEMY,
    FOOD,
    SCORE_ZONE
};

struct Cell {
    CellType type;
    char symbol;
    string color;
};

struct GameState {
    size_t width;
    size_t height;
    int score;
    vector<vector<Cell>> grid;
    bool gameOver;
    string message;
};


    GameState createMaze();
void renderText(const GameState& state);
#endif /* !RECODEARCADE_HPP_ */
