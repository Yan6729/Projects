/*
** EPITECH PROJECT, 2025
** exit_with_error.c
** File description:
** just a file
*/

#include "../include/stumper.h"

void exit_with_error(const char *message, int code)
{
    fprintf(stderr, "%s", message);
    exit(code);
}
