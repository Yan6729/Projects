/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

static win_t all_for_window(sfVideoMode winsize, char *win_name)
{
    win_t win;

    if (global.is_fullscreen == 0)
        win.window = RWC(winsize, win_name, sfClose, NULL);
    else
        win.window = RWC(winsize, win_name, sfFullscreen, NULL);
    win.event;
    return (win);
}

static void analyse_events(win_t *win, intro_t *intro, scrnstp_t **screens)
{
    if (((win->event).type == sfEvtClosed) || global.exit == 1)
        sfRenderWindow_close(win->window);
    intro_skipper(win->event, intro);
    if (*screens != NULL && global.i >= 0)
        button_checker(&((global.current_screen)->buttons), win->window,
        screens);
    return;
}

static void elements_freer_destroyer(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfClock_destroy(global.game_clock);
    sfMusic_destroy(global.main_hovered);
    sfRectangleShape_destroy(global.volume_level);
    sfFont_destroy(global.font_1);
    sfText_destroy(global.text);
    return;
}

static void initialize_game_buttons(scrnstp_t **screens)
{
    main_menu_buttons(screens);
    settings_buttons(screens);
    credits_buttons(screens);
    return;
}

static comp_t init_comparers(void)
{
    comp_t box;

    box.previous_fps_limit = 0;
    box.pre_msc = -1;
    box.pre_snd = -1;
    box.pre_win = global.window_i;
    box.pre_ratio = global.ratio.x;
    return (box);
}

void screens_elements_drawing(SFRW window, int *pre_msc, int *pre_snd)
{
    if (global.current_screen != NULL) {
        if (global.i == 0) {
            sfRenderWindow_drawSprite(window,
                (global.current_screen)->back_sprt, NULL);
            buttons_displayer(&((global.current_screen)->buttons), window);
        }
        if ((global.current_screen)->id == 42) {
            volume_sizer(window, global.music_volume, pre_msc,
                ratior(760, 405));
            volume_sizer(window, global.sound_volume, pre_snd,
                ratior(760, 598));
        }
    }
    return;
}

void game_window_displaying(win_t *win, intro_t *intro, scrnstp_t **screens,
    comp_t *comparers)
{
    my_framerate();
    while (sfRenderWindow_pollEvent(win->window, &(win->event)))
        analyse_events(win, intro, screens);
    window_resizer(win, &(comparers->pre_win), screens);
    framerate_limiter(win->window, &(comparers->previous_fps_limit));
    volume_applier(screens, comparers->pre_msc, comparers->pre_snd);
    sfRenderWindow_clear(win->window, sfBlack);
    introductor(win->window, intro);
    first_positionner(screens);
    screens_elements_drawing(win->window, &(comparers->pre_msc),
        &(comparers->pre_snd));
    show_fps(win->window);
    sfRenderWindow_display(win->window);
    return;
}

int game_window(set_t *settings)
{
    win_t win = all_for_window(global.window_size, "Sector42: Genesis");
    intro_t intro = intro_maker();
    scrnstp_t *screens = NULL;
    comp_t comparers = init_comparers();

    initialize_game_buttons(&screens);
    global.current_screen = screens;
    sfClock_restart(global.game_clock);
    while (sfRenderWindow_isOpen(win.window)) {
        if (global.ok_settings == 1)
            affect_settings_to_the_game(&screens, settings);
        game_window_displaying(&win, &intro, &screens, &comparers);
    }
    if (intro.i != -1)
        intro_elements_destroy(&intro);
    buttons_remover(&screens);
    save_settings(settings);
    elements_freer_destroyer(win.window);
    if (global.start_game == 1)
        run_game_loop();
}
