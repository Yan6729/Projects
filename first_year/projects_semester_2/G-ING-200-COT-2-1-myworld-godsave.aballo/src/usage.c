/*
** EPITECH PROJECT, 2025
** usage.c
** File description:
** just a file for the usage
*/

#include "../include/struct.h"

void usage(void)
{
    my_puts("\033[1;37m");
    my_puts("    A procedural terrain engine with ingame terraforming\n");
    my_puts("inspired by the great tycoon-games of old. Handles up\n");
    my_puts("to 512x512 tile terrains with reasonable efficiency. At\n");
    my_puts("larger sizes it's the terraforming that is the bottleneck\n");
    my_puts("(due to an unfortunate design error of Unity's own terrain\n");
    my_puts("engine I might add...) so for simple map generation much\n");
    my_puts("larger sizes could be handled.\n");
    my_puts("\033[0;37m");
}
