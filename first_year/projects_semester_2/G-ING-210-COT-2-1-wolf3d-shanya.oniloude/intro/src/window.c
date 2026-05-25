/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

win_t all_for_window(sfVideoMode winsize, char *win_name)
{
    win_t win;

    win.window = RWC(winsize, win_name, sfClose, NULL);
    win.event;
    return (win);
}

void analyse_events(win_t *win, intro_t *intro)
{
    if ((win->event).type == sfEvtClosed)
        sfRenderWindow_close(win->window);

    intro_skipper(win->event, intro);
    return;
}

void elements_freer_destroyer(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfClock_destroy(global.game_clock);
    return;
}

int game_window(void)
{
    win_t win = all_for_window(global.window_size, "Wolf3D");


    intro_t intro = intro_maker();

    sfRenderWindow_setFramerateLimit(win.window, global.fps_limit);
    sfClock_restart(global.game_clock);
    while (sfRenderWindow_isOpen(win.window)) {
        my_framerate();
        while (sfRenderWindow_pollEvent(win.window, &(win.event)))
            analyse_events(&win, &intro);
        sfRenderWindow_clear(win.window, sfBlack);

        introductor(win.window, &intro);
        
        sfRenderWindow_display(win.window);
    }

    if (intro.i != -1)
        intro_elements_destroy(&intro);

    
    elements_freer_destroyer(win.window);
    return (0);
}
