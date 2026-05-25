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
    global = all_globals();
    game_window();
    return (0);
}
