/*
** EPITECH PROJECT, 2025
** init_game.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void init_game(game_t *game, const dict_t *dict, int tries)
{
    int index = 0;

    srand(time(NULL));
    index = rand() % dict->count;
    game->dev = strdup(dict->word[index]);
    game->len_dev = strlen(game->dev);
    game->try = tries;
    game->car = 0;
    game->trouv = malloc(game->len_dev + 1);
    if (!game->trouv)
        exit_with_error("Memory error", 84);
    for (int i = 0; i < game->len_dev; i++)
        game->trouv[i] = '*';
    game->trouv[game->len_dev] = '\0';
}
