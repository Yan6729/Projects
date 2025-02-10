/*
** EPITECH PROJECT, 2025
** cond.c
** File description:
** function that contain all of my fly condition
*/

#include "struct.h"

int draw(file_t cmp)
{
    cmp.rec = rect_1(cmp, sfRed);
    sfRenderWindow_drawRectangleShape(cmp.window, cmp.rec, NULL);
    sfSprite_setPosition(cmp.plane, cmp.pos_p);
    sfRenderWindow_drawSprite(cmp.window, cmp.plane, NULL);
}

void cond_2(plane_t *tmp_2, file_t cmp)
{
    if ((tmp_2->Xi > (tmp_2->X - 10)) && (tmp_2->Yi < (tmp_2->Y - 10))) {
        tmp_2->Xi -= (tmp_2->vit / 100);
        tmp_2->Yi += (tmp_2->vit / 100);
        cmp.pos_p = (sfVector2f){tmp_2->Xi, tmp_2->Yi};
        draw(cmp);
    } else if ((tmp_2->Xi > (tmp_2->X - 10))
        && (tmp_2->Yi > (tmp_2->Y - 10))) {
        tmp_2->Xi -= (tmp_2->vit / 100);
        tmp_2->Yi -= (tmp_2->vit / 100);
        cmp.pos_p = (sfVector2f){tmp_2->Xi, tmp_2->Yi};
        draw(cmp);
    }
    return;
}

void cond_1(plane_t *tmp_2, file_t cmp)
{
    if ((tmp_2->Xi < (tmp_2->X - 10)) && (tmp_2->Yi < (tmp_2->Y - 10))) {
        tmp_2->Xi += (tmp_2->vit / 100);
        tmp_2->Yi += (tmp_2->vit / 100);
        cmp.pos_p = (sfVector2f){tmp_2->Xi, tmp_2->Yi};
        draw(cmp);
    } else if ((tmp_2->Xi < (tmp_2->X - 10))
        && (tmp_2->Yi > (tmp_2->Y - 10))) {
        tmp_2->Xi += (tmp_2->vit / 100);
        tmp_2->Yi -= (tmp_2->vit / 100);
        cmp.pos_p = (sfVector2f){tmp_2->Xi, tmp_2->Yi};
        draw(cmp);
    }
    return;
}
