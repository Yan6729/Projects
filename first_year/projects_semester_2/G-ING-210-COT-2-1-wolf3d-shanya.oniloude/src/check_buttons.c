/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

static int inter_cond(sfVector2i mpos, SFV2F s, SFV2F e)
{
    if ((mpos.x >= s.x && mpos.x <= e.x) && (mpos.y >= s.y && mpos.y <= e.y))
        return (1);
    else
        return (0);
}

static void button_cond2(btn_t *tmp, sfVector2i mpos, SFV2F s, SFV2F e)
{
    if (tmp->idle == 1 && inter_cond(mpos, s, e)) {
        if ((global.current_screen)->id == 0)
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
    SFV2F strt = {pos_sz[0].x + tmp->position.x,
        pos_sz[0].y + tmp->position.y};
    SFV2F end = {strt.x + pos_sz[1].x, strt.y + pos_sz[1].y};

    tmp->selected_hover = 0;
    button_cond2(tmp, mpos, strt, end);
    if (inter_cond(mpos, strt, end) == 0) {
        tmp->idle = 1;
        tmp->hover = 0;
        if (tmp->const_button == 0 && tmp->selected == 1)
            tmp->selected = 0;
    }
    return;
}

static void button_pos_size_filler(btn_t *tmp, SFV2F pos_size[2])
{
    int i = (tmp->hover == 1 && tmp->selected == 0) ? 1 : 0;

    pos_size[1].x = (tmp->button_size.x * tmp->button_scales[i].x);
    pos_size[1].y = (tmp->button_size.y * tmp->button_scales[i].y);
    pos_size[0].x = -(pos_size[1].x / 2);
    pos_size[0].y = -(pos_size[1].y / 2);
    return;
}

static int button_action(btn_t *tmp, scrnstp_t **screens)
{
    if ((global.current_screen)->id == 0)
        return (main_button_action(tmp, screens));
    if ((global.current_screen)->id == 41)
        return (graphism_button_actions(tmp, screens));
    if ((global.current_screen)->id == 42)
        return (audio_button_actions(tmp, screens));
    if ((global.current_screen)->id == 43)
        return (controls_button_actions(tmp, screens));
    if ((global.current_screen)->id == 50)
        return (credits_button_actions(tmp, screens));
    return (0);
}

static int skip_checking(btn_t *btn)
{
    if ((global.current_screen)->id == 41 ||
        (global.current_screen)->id == 43) {
        if (btn->const_button == 0 && btn->selected == 1)
            return (1);
    }
    return (0);
}

void off_switcher(btn_t *btn)
{
    if ((global.current_screen)->id == 41 && btn->button_id == 10 &&
        btn->selected == 0 && global.show_fps == 1)
        global.show_fps = 0;
    if ((global.current_screen)->id == 42 && btn->button_id == 8 &&
        btn->selected == 0 && global.p_spk == 1)
        global.p_spk = 0;
    return;
}

void button_checker(btn_t **buttons, sfRenderWindow *win, scrnstp_t **screens)
{
    btn_t *tmp = *buttons;
    sfVector2i mpos = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos_size[2];
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next) {
        if (skip_checking(tmp))
            continue;
        button_pos_size_filler(tmp, pos_size);
        button_cond(tmp, mpos, pos_size);
        off_switcher(tmp);
        if (tmp->selected == 1)
            i = button_action(tmp, screens);
        if (i == 1)
            break;
    }
    return;
}
