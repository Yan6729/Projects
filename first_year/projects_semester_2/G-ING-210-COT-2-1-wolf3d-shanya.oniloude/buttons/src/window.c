/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

global_t global;

win_t all_for_window(sfVideoMode winsize, char *win_name)
{
    win_t win;

    win.window = RWC(winsize, win_name, sfResize | sfClose, NULL);
    win.event;
    return (win);
}

global_t all_globals(void)
{
    global_t box;

    box.i = 0;
    box.fps_limit = 30;
    box.fps = 30;
    box.window_size = (SFVM){1920, 1080, 32};
    box.main_hovered = SFMCFF("hovered.mp3");
    return (box);
}

void analyse_events(win_t *win, btn_t **buttons)
{
    if ((win->event).type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    button_checker(buttons, win->window);
    return;
}

void elements_freer_destroyer(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfMusic_destroy(global.main_hovered);
    return;
}

/*int game_window(void)
{
    win_t win = all_for_window((sfVideoMode){1920, 1080, 64}, "test (Wolf3D)");
    scrnstp_t test[1];
    /*char *mah[4] = {"yes", "START", "strt.png", "hovered.mp3"};
    SFV2 bof[4] = {{200, 75}, {960, 540}, {1, 1}, {1, 1}};*//*

    global = all_globals();
    test[0].buttons = NULL;
    //button_adder(&(test[0].buttons), mah, bof);
    button_adder(&(test[0].buttons), &(belm_t){0, "start", "duck.png",
        "hovered.mp3", {110, 110}, {960, 540}, {1, 1}, {1, 1}});
    sfRenderWindow_setFramerateLimit(win.window, 30);
    while (sfRenderWindow_isOpen(win.window)) {
        while (sfRenderWindow_pollEvent(win.window, &(win.event)))
            analyse_events(&win, &(test[0].buttons));
        my_framerate();
        sfRenderWindow_clear(win.window, sfBlack);
        buttons_displayer(&(test[0].buttons), win.window);
        sfRenderWindow_display(win.window);
    }
    buttons_remover(test);
    elements_freer_destroyer(win.window);
    return (0);
}*/

int game_window(void)
{
    win_t win = all_for_window((sfVideoMode){1920, 1080, 64}, "test (Wolf3D)");
    scrnstp_t test[1];
    /*char *mah[4] = {"yes", "START", "strt.png", "hovered.mp3"};
    SFV2 bof[4] = {{200, 75}, {960, 540}, {1, 1}, {1, 1}};*/

    global = all_globals();
    test[0].buttons = NULL;
    //button_adder(&(test[0].buttons), mah, bof);
    button_adder(&(test[0].buttons), &(belm_t){0, "start", "duck.png",
        "hovered.mp3", {110, 110}, {960, 540}, {1, 1}, {3, 1}});
    sfRenderWindow_setFramerateLimit(win.window, 30);
    while (sfRenderWindow_isOpen(win.window)) {
        while (sfRenderWindow_pollEvent(win.window, &(win.event)))
            analyse_events(&win, &(test[0].buttons));
        my_framerate();
        sfRenderWindow_clear(win.window, sfBlack);
        buttons_displayer(&(test[0].buttons), win.window);
        sfRenderWindow_display(win.window);
    }
    buttons_remover(test);
    elements_freer_destroyer(win.window);
    return (0);
}
