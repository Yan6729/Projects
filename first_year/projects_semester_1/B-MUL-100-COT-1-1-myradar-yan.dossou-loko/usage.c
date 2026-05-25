/*
** EPITECH PROJECT, 2025
** usage.c
** File description:
** an intermediar function
*/

#include "struct.h"

int usage(int ac, char **av)
{
    my_putstr("Air traffic simulation panel\n");
    my_putstr("Usage\n\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script\tThe path to the script file.\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h\tprint the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t`L' key\tenable/disable hitboxes and areas.\n");
    my_putstr("\t`S' key\tenable/disable sprites.\n");
}
