/*
** EPITECH PROJECT, 2024
** my_plane.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfSprite *my_plane(file_t cmp)
{
    sfVector2f scale = {0.07, 0.07};

    cmp.plane = sfSprite_create();
    sfSprite_setScale(cmp.plane, scale);
    sfSprite_setTexture(cmp.plane, cmp.textp, sfTrue);
    return cmp.plane;
}

void add(plane_t *data, char *s, char *r, char *t)
{
    data->Xi = convert(s);
    data->Yi = convert(r);
    data->X = convert(t);
}

void part_2(plane_t *data, char *s, char *r, char *t)
{
    data->Y = convert(s);
    data->vit = convert(r);
    data->delay = convert(t);
}

plane_t *list(int ac, char **av)
{
    plane_t *list;
    int a = 0;
    plane_t *data = NULL;
    static int id = 0;
    char **dat = map_stocked(dat, a, ac, av);

    for (list = NULL; dat[a] != NULL; a += 7) {
        if (my_strcmp(dat[a], "A") == 0) {
            data = malloc(sizeof(*data));
            add(data, dat[a + 1], dat[a + 2], dat[a + 3]);
            part_2(data, dat[a + 4], dat[a + 5], dat[a + 6]);
            data->id = id;
            id++;
            data->next = list;
            list = data;
        } else
            break;
    }
    return data;
}
