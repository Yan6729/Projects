/*
** EPITECH PROJECT, 2025
** display_game_state.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void display_game_state(const game_t *game)
{
    printf("%s\n", game->trouv);
    printf("Tries: %d\n\n", game->try);
}
