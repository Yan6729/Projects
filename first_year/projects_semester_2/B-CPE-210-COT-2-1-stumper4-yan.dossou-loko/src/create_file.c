/*
** EPITECH PROJECT, 2025
** create_file.c
** File description:
** just a file
*/

#include "../include/my.h"

void create_file(char *filename)
{
    FILE *file = fopen(filename, "w+");

    fprintf(file, "tomato = 50\n");
    fprintf(file, "dough = 50\n");
    fprintf(file, "onion = 50\n");
    fprintf(file, "pasta = 50\n");
    fprintf(file, "olive = 50\n");
    fprintf(file, "pepper = 50\n");
    fprintf(file, "ham = 50\n");
    fprintf(file, "cheese = 50\n");
    fclose(file);
}
