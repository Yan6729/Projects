/*
** EPITECH PROJECT, 2025
** project_iso_point.c
** File description:
** just a file
*/

#include "../include/struct.h"

sfVertexArray *create_quad(sfVector2f point[4], sfTexture *texture)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVector2u tex_size = sfTexture_getSize(texture);
    sfVertex vertex[4] = {
        {.position = point[0], .texCoords = (sfVector2f){0, 0}},
        {.position = point[1], .texCoords = (sfVector2f){tex_size.x, 0}},
        {.position = point[2], .texCoords =
            (sfVector2f){tex_size.x, tex_size.y}},
        {.position = point[3], .texCoords = (sfVector2f){0, tex_size.y}},
    };

    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    for (int i = 0; i < 4; i++) {
        vertex[i].color = sfWhite;
        sfVertexArray_append(vertex_array, vertex[i]);
    }
    return (vertex_array);
}

void cond(int j, int i, sfVector2f point[4], sfRenderWindow *window)
{
    sfVertexArray *array;

    array = create_line(&point[1], &point[2]);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
    array = create_line(&point[2], &point[3]);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
    array = create_line(&point[3], &point[0]);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
    array = create_line(&point[0], &point[1]);
    sfRenderWindow_drawVertexArray(window, array, NULL);
    sfVertexArray_destroy(array);
}

sfVertexArray **draw_2d_map(sfRenderWindow *window,
    sfVector2f **two_d_map, sfTexture *text, int tab[2])
{
    sfVector2f point[4];
    sfVertexArray *arr;
    sfRenderStates states;

    for (int j = 0; j < tab[0] - 1; j++) {
        for (int i = 0; i < tab[1] - 1; i++) {
            point[0] = two_d_map[j][i];
            point[1] = two_d_map[j][i + 1];
            point[2] = two_d_map[j + 1][i + 1];
            point[3] = two_d_map[j + 1][i];
            arr = create_quad(point, text);
            states = (sfRenderStates){.texture = text, .blendMode =
            sfBlendAlpha, .transform = sfTransform_Identity, .shader = NULL};
            sfRenderWindow_drawVertexArray(window, arr, &states);
            cond(i, j, point, window);
            sfVertexArray_destroy(arr);
        }
    }
}

int loop(sfRenderWindow *window, sfEvent event, int ac, char **av)
{
    sfTexture *texture = sfTexture_createFromFile("texture.jpg", NULL);
    double zoom = 110;
    coord_t coord = {10, 10};
    int **map = tab(coord);
    int tab[2] = {coord.y, coord.x};
    sfVector2f **pos;

    while (sfRenderWindow_isOpen(window)) {
        zoom = manage_events(window, event, zoom);
        pos = create_2d_map(map, zoom, coord);
        sfRenderWindow_clear(window, sfBlack);
        draw_2d_map(window, pos, texture, tab);
        sfRenderWindow_display(window);
    }
    sfTexture_destroy(texture);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        menu(ac, av);
    } else if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usage();
    } else {
        my_puts("Invalide usage:\n");
        my_puts("    ./my_world -h -> usage\n");
        my_puts("    ./my_world with no arguments, gmae's window");
        my_puts(" displaying\n");
        return 84;
    }
}
