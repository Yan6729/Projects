/*
** EPITECH PROJECT, 2025
** free_game.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void free_game(game_t *game)
{
    free(game->dev);
    free(game->trouv);
    game->dev = NULL;
    game->trouv = NULL;
}
