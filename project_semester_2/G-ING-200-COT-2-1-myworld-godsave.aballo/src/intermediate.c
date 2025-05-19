/*
** EPITECH PROJECT, 2025
** intermediate.c
** File description:
** just a file who contain other function
*/

#include "../include/struct.h"

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfBlue};
    sfVertex vertex2 = {.position = *point2, .color = sfRed};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int **tab(coord_t coord)
{
    int **tab = malloc(sizeof(int *) * coord.y);

    for (int a = 0; a < coord.y; a++)
        tab[a] = malloc(sizeof(int) * coord.x);
    for (int c = 0; c < coord.x; c++) {
        for (int d = 0; d < coord.x; d++) {
            tab[c][d] = 0;
        }
    }
    return tab;
}
