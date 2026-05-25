/*
** EPITECH PROJECT, 2025
** my_world.c
** File description:
** just a function who stock the other function
*/

#include "../include/struct.h"

int intermed(sfRenderWindow *window, sfEvent event, int zoom)
{
    if (event.mouseWheelScroll.delta > 0 && zoom < 1400) {
        zoom += 4.4f;
    } else if (event.mouseWheelScroll.delta < 0 && zoom > 20) {
        zoom -= 4.4f;
    }
    return zoom;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f two_point;
    sfVector3f three_point = {x, y, z};
    double angle_x = (25) * M_PI / 180;
    double angle_y = (15) * M_PI / 180;

    two_point.x = cos(angle_x) * three_point.x - cos(angle_x) * three_point.y;
    two_point.y = sin(angle_y) * three_point.y + sin(angle_y)
        * three_point.x - three_point.z;
    return two_point;
}

sfVector2f **create_2d_map(int **tab, int zoom, coord_t coord)
{
    int d = 0;
    int c = 0;
    sfVector2f **vector = malloc(sizeof(sfVector2f *) * (coord.y + 1));

    for (int a = 0; a < coord.y; a++) {
        vector[a] = malloc(sizeof(sfVector2f) * (coord.x + 1));
        for (int b = 0; b < coord.x; b++) {
            vector[a][b] = project_iso_point(b * zoom,
                a * zoom, tab[a][b] * 50);
            vector[a][b].x += 940;
            vector[a][b].y += 310;
        }
    }
    return vector;
}

int manage_events(sfRenderWindow *window, sfEvent event, int zoom)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseWheelScrolled) {
            zoom = intermed(window, event, zoom);
        }
    }
    return zoom;
}
