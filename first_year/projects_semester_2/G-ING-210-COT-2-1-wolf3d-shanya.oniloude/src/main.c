/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** main
*/

#include "../include/wolf3d.h"

global_t global;

/*char **map = NULL;
    char *file_content;
    player_t player = init_player(3.5, 3.5, 0.0);*/
    /*file_content = open_file(argv[1]);
    if (!file_content || strlen(file_content) == 0)
        exit(84);
    map = parsing(file_content, "\n");
*/

int main(int argc, char **argv)
{
    set_t settings = load_settings();

    if (settings.ratio.x == -1)
        return (84);
    global = all_globals(&settings);
    game_window(&settings);
    return (0);
}
