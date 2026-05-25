/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

void main_menu_buttons(scrnstp_t **screens)
{
    new_screen(screens, 0, "img/main_page.png");
    button_adder(&((*screens)->buttons), &(belm_t){0, 1, "img/new_game.png",
        "snd/main_hov.mp3", {500, 83}, {490, 411}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 2, "img/load_game.png",
        "snd/main_hov.mp3", {500, 83}, {490, 509}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 3, "img/leaderboard.png",
        "snd/main_hov.mp3", {500, 83}, {490, 607}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 4, "img/settings.png",
        "snd/main_hov.mp3", {500, 83}, {490, 705}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 5, "img/credits.png",
        "snd/main_hov.mp3", {500, 83}, {490, 803}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 6, "img/quit.png",
        "snd/main_hov.mp3", {500, 83}, {490, 901}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 7, "img/guide.png",
        "snd/main_hov.mp3", {80, 80}, {1643, 1000}, {1, 1}, {1.1, 1.1}});
    button_adder(&((*screens)->buttons), &(belm_t){0, 8, "img/youtube.png",
        "snd/main_hov.mp3", {80, 80}, {1772, 1000}, {1, 1}, {1.1, 1.1}});
    return;
}

void graphisms_setting(scrnstp_t **tmp)
{
    button_adder(&((*tmp)->buttons), &(belm_t){0, 1, "img/btns/back.png",
        "snd/main_hov.mp3", {58, 58}, {162, 301}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 2, "img/btns/snd.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 601}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 3, "img/btns/ctrls.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 741}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 4, "img/btns/9x5_size.png",
        "snd/main_hov.mp3", {220, 150}, {914, 439}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 5, "img/btns/19x10_size.png",
        "snd/main_hov.mp3", {220, 150}, {1202, 439}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 6, "img/btns/fscrn_size.png",
        "snd/main_hov.mp3", {220, 150}, {1490, 439}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 7, "img/btns/30fps.png",
        "snd/main_hov.mp3", {220, 100}, {804, 658}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 8, "img/btns/60fps.png",
        "snd/main_hov.mp3", {220, 100}, {1092, 658}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 9, "img/btns/100fps.png",
        "snd/main_hov.mp3", {220, 100}, {1380, 658}, {1, 1}, {1, 1}});
    return;
}

void sound_setting(scrnstp_t **tmp)
{
    button_adder(&((*tmp)->buttons), &(belm_t){0, 1, "img/btns/back.png",
        "snd/main_hov.mp3", {58, 58}, {162, 301}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 2, "img/btns/grphsm.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 461}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 3, "img/btns/ctrls.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 741}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 4, "img/btns/minus.png",
        "snd/main_hov.mp3", {40, 40}, {717, 410}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 5, "img/btns/plus.png",
        "snd/main_hov.mp3", {40, 40}, {1561, 410}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 6, "img/btns/minus.png",
        "snd/main_hov.mp3", {40, 40}, {717, 603}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 7, "img/btns/plus.png",
        "snd/main_hov.mp3", {40, 40}, {1561, 603}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){1, 8, "img/btns/off_on.png",
        "snd/main_hov.mp3", {90, 50}, {1584, 716}, {1, 1}, {1, 1}});
    return;
}

void controls_setting(scrnstp_t **tmp)
{
    button_adder(&((*tmp)->buttons), &(belm_t){0, 1, "img/btns/back.png",
        "snd/main_hov.mp3", {58, 58}, {162, 301}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 2, "img/btns/grphsm.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 461}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 3, "img/btns/snd.jpg",
        "snd/main_hov.mp3", {350, 100}, {308, 601}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 4, "img/btns/lhanded.png",
        "snd/main_hov.mp3", {425, 240}, {966, 483}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 5, "img/btns/rhanded.png",
        "snd/main_hov.mp3", {425, 240}, {1483, 483}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 6, "img/btns/x1.0.png",
        "snd/main_hov.mp3", {120, 70}, {960, 765}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 7, "img/btns/x1.5.png",
        "snd/main_hov.mp3", {120, 70}, {1200, 765}, {1, 1}, {1, 1}});
    button_adder(&((*tmp)->buttons), &(belm_t){0, 8, "img/btns/x2.0.png",
        "snd/main_hov.mp3", {120, 70}, {1440, 765}, {1, 1}, {1, 1}});
    return;
}

void settings_buttons(scrnstp_t **screens)
{
    scrnstp_t *tmp = NULL;

    new_screen(screens, 41, "img/bck_grnds/graphisms.jpg");
    change_screen(screens, &tmp, 41);
    graphisms_setting(&tmp);
    button_adder(&(tmp->buttons), &(belm_t){1, 10, "img/btns/off_on.png",
        "snd/main_hov.mp3", {90, 50}, {1092, 761}, {1, 1}, {1, 1}});
    new_screen(screens, 42, "img/bck_grnds/sound.jpg");
    change_screen(screens, &tmp, 42);
    sound_setting(&tmp);
    new_screen(screens, 43, "img/bck_grnds/controls.jpg");
    change_screen(screens, &tmp, 43);
    controls_setting(&tmp);
    return;
}
