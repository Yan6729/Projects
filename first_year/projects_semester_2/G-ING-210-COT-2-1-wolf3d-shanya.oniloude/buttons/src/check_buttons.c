/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int inter_cond(sfVector2i mpos, SFV2 s, SFV2 e)
{
    if ((mpos.x >= s.x && mpos.x <= e.x) && (mpos.y >= s.y && mpos.y <= e.y))
        return (1);
    else
        return (0);
}

void button_cond2(btn_t *tmp, sfVector2i mpos, SFV2 s, SFV2 e)
{
    if (tmp->idle == 1 && inter_cond(mpos, s, e)) {
        if (global.i == 0)
            sfMusic_play(global.main_hovered);
        tmp->hover = 1;
        tmp->idle = 0;
    }
    if (tmp->hover == 1 && tmp->selected == 0 && inter_cond(mpos, s, e)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfMusic_play(tmp->clicked_music);
            tmp->selected = 1;
        }
        return;
    }
    if (tmp->selected == 1 && inter_cond(mpos, s, e)) {
        tmp->selected_hover = 1;
        if (tmp->const_button == 1 && sfMouse_isButtonPressed(sfMouseLeft))
            tmp->selected = 0;
        if (tmp->const_button == 0)
            tmp->selected = 0;
    }
}

void button_cond(btn_t *tmp, sfVector2i mpos, sfVector2f pos_sz[2])
{
    SFV2 strt = {pos_sz[0].x + tmp->position.x, pos_sz[0].y + tmp->position.y};
    SFV2 end = {strt.x + pos_sz[1].x, strt.y + pos_sz[1].y};

    tmp->selected_hover = 0;
    button_cond2(tmp, mpos, strt, end);
    if (tmp->hover == 1 && inter_cond(mpos, strt, end) == 0) {
        tmp->idle = 1;
        tmp->hover = 0;
    }
    return;
}

void button_pos_size_filler(btn_t *tmp, SFV2 pos_size[2])
{
    int i = (tmp->hover == 1 && tmp->selected == 0) ? 1 : 0;

    pos_size[1].x = (tmp->button_size.x * tmp->button_scales[i].x);
    pos_size[1].y = (tmp->button_size.y * tmp->button_scales[i].y);
    pos_size[0].x = -(pos_size[1].x / 2);
    pos_size[0].y = -(pos_size[1].y / 2);
    return;
}

void button_checker(btn_t **buttons, sfRenderWindow *window)
{
    btn_t *tmp = *buttons;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos_size[2];

    for (; tmp != NULL; tmp = tmp->next) {
        button_pos_size_filler(tmp, pos_size);
        button_cond(tmp, mpos, pos_size);
    }
    return;
}
