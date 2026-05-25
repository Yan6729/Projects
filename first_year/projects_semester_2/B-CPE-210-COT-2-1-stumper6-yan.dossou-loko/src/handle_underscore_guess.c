/*
** EPITECH PROJECT, 2025
** handle_underscore_guess.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int handle_underscore_guess(game_t *game, int i, char guess)
{
    if (game->dev[i] == '_' && guess == '_' && game->trouv[i] == '*') {
        game->trouv[i] = '_';
        game->car++;
        return 0;
    }
    return 84;
}
