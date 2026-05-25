/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** checks buttons
*/

#include "../include/wolf3d.h"

int inter_cond(sfVector2i mpos, SFV2F s, SFV2F e)
{
    if ((mpos.x >= s.x && mpos.x <= e.x) && (mpos.y >= s.y && mpos.y <= e.y))
        return (1);
    else
        return (0);
}

void button_cond2(btn_t *tmp, sfVector2i mpos, SFV2F s, SFV2F e)
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
    SFV2F strt = {pos_sz[0].x + tmp->position.x, pos_sz[0].y + tmp->position.y};
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

void button_pos_size_filler(btn_t *tmp, SFV2F pos_size[2])
{
    int i = (tmp->hover == 1 && tmp->selected == 0) ? 1 : 0;

    pos_size[1].x = (tmp->button_size.x * tmp->button_scales[i].x);
    pos_size[1].y = (tmp->button_size.y * tmp->button_scales[i].y);
    pos_size[0].x = -(pos_size[1].x / 2);
    pos_size[0].y = -(pos_size[1].y / 2);
    return;
}

void buttons_desactivater(btn_t **buttons, int id_1, int id_2)
{
    for (btn_t *tmp = *buttons; tmp != NULL; tmp = tmp->next) {
        if (tmp->button_id == id_1)
            reset_button(tmp);
        if (tmp->button_id == id_2) {
            reset_button(tmp);
            break;
        }
    }
    return;
}

int button_action(btn_t *tmp, scrnstp_t **screens)
{
    int i = 0;

    if ((global.current_screen)->id == 0) {
        if (tmp->button_id == 4) {
            screen_switching(tmp, screens, 41);
            return (1);
        }
        if (tmp->button_id == 5) {
            screen_switching(tmp, screens, 50);
            return (1);
        }
        if (tmp->button_id == 6)
            global.exit = 1;
        if (tmp->button_id == 7)
            system("open https://github.com/YannAnge-NextGen/ShayanX-Sector42_Genesis 2> .errors");
        if (tmp->button_id == 8)
            system("open https://www.youtube.com/ 2> .errors");
    }
    if ((global.current_screen)->id == 41) {
        i = change_settings_option(screens, tmp, 42, 43);
        if (i == 1)
            return (1);
        if (tmp->button_id == 4) {
            buttons_desactivater(&((global.current_screen)->buttons), 5, 6);
            global.window_i = 1;
            global.window_size = (SFVM){960, 540, 32};
            global.is_fullscreen = 0;
            global.ratio = (SFV2F){0.5, 0.5};
        }
        if (tmp->button_id == 5) {
            buttons_desactivater(&((global.current_screen)->buttons), 4, 6);
            global.window_i = 2;
            global.window_size = (SFVM){1920, 1080, 32};
            global.is_fullscreen = 0;
            global.ratio = (SFV2F){1, 1};
        }
        if (tmp->button_id == 6) {
            buttons_desactivater(&((global.current_screen)->buttons), 4, 5);
            global.window_i = 3;
            global.window_size = (SFVM){1920, 1080, 32};
            global.is_fullscreen = 1;
            global.ratio = (SFV2F){1, 1};
        }
        if (tmp->button_id == 7) {
            buttons_desactivater(&((global.current_screen)->buttons), 8, 9);
            global.fps_limit = 30;
        }
        if (tmp->button_id == 8) {
            buttons_desactivater(&((global.current_screen)->buttons), 7, 9);
            global.fps_limit = 60;
        }
        if (tmp->button_id == 9) {
            buttons_desactivater(&((global.current_screen)->buttons), 7, 8);
            global.fps_limit = 100;
        }
        if (tmp->button_id == 10)
            global.show_fps = 1;
    }
    if ((global.current_screen)->id == 42) {
        i = change_settings_option(screens, tmp, 41, 43);
        if (i == 1)
            return (1);
        if (tmp->button_id == 4)
            global.music_volume -= (global.music_volume > 0) ? 5 : 0;
        if (tmp->button_id == 5)
            global.music_volume += (global.music_volume < 100) ? 5 : 0;
        if (tmp->button_id == 6)
            global.sound_volume -= (global.sound_volume > 0) ? 5 : 0;
        if (tmp->button_id == 7)
            global.sound_volume += (global.sound_volume < 100) ? 5 : 0;
    }
    if ((global.current_screen)->id == 43) {
        i = change_settings_option(screens, tmp, 41, 42);
        if (i == 1)
            return (1);
        if (tmp->button_id == 4)
            buttons_desactivater(&((global.current_screen)->buttons), 5, 5);
        if (tmp->button_id == 5)
            buttons_desactivater(&((global.current_screen)->buttons), 4, 4);
        if (tmp->button_id == 6)
            buttons_desactivater(&((global.current_screen)->buttons), 7, 8);
        if (tmp->button_id == 7)
            buttons_desactivater(&((global.current_screen)->buttons), 6, 8);
        if (tmp->button_id == 8)
            buttons_desactivater(&((global.current_screen)->buttons), 6, 7);
    }
    if ((global.current_screen)->id == 50) {
        if (back_button_clicked(screens, tmp, 0))
            return (1);
    }
    return (0);
}

int skip_checking(btn_t *btn)
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
