/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "../include/wolf3d.h"

global_t global;

int main(int argc, char **argv)
{
    /*char **map = NULL;
    char *file_content;
    player_t player = init_player(3.5, 3.5, 0.0);*/

    global = all_globals();
    game_window();
    /*file_content = open_file(argv[1]);
    if (!file_content || strlen(file_content) == 0)
        exit(84);
    map = parsing(file_content, "\n");*/
    return (0);
}
