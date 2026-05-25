/*
** EPITECH PROJECT, 2025
** is_game_won.c
** File description:
** just a file
*/

#include "../include/stumper.h"

int is_game_won(const game_t *game)
{
    return (game != NULL) && (game->car == game->len_dev);
}
