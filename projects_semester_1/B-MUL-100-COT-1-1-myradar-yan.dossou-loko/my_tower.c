/*
** EPITECH PROJECT, 2024
** my_tower.c
** File description:
** an intermediar function
*/

#include "struct.h"

sfSprite *my_tower(file_t cmp)
{
    sfVector2f scale = {0.05, 0.05};

    cmp.tower = sfSprite_create();
    sfSprite_setScale(cmp.tower, scale);
    sfSprite_setTexture(cmp.tower, cmp.text, sfTrue);
    return cmp.tower;
}

void part(tower_t *data, char *s, char *r, char *t)
{
    data->Xt = convert(s);
    data->Yt = convert(r);
    data->rad = convert(t);
}

tower_t *my_list(int ac, char **av)
{
    tower_t *list;
    int a = 0;
    tower_t *data = NULL;
    char **dat = map_stocked(dat, a, ac, av);

    for (list = NULL; dat[a] != NULL; a++) {
        if (my_strcmp(dat[a], "T") == 0) {
            data = malloc(sizeof(*data));
            part(data, dat[a + 1], dat[a + 2], dat[a + 3]);
            data->next = list;
            list = data;
            a += 3;
        } else
            continue;
    }
    for (a = 0; dat[a] != NULL; a++)
        free(dat[a]);
    free(dat);
    return data;
}
