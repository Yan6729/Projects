/*
** EPITECH PROJECT, 2025
** handle_regular_guess.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int handle_regular_guess(game_t *game, int i, char guess)
{
    if (game->dev[i] == guess && game->trouv[i] == '*') {
        game->trouv[i] = game->dev[i];
        game->car++;
        return 0;
    }
    return 84;
}
