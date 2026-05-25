/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

sfVector2f ratior(float x, float y)
{
    return ((SFV2F){(x * global.ratio.x), (y * global.ratio.y)});
}

win_t all_for_window(sfVideoMode winsize, char *win_name)
{
    win_t win;

    if (global.is_fullscreen == 0)
        win.window = RWC(winsize, win_name, sfClose, NULL);
    else
        win.window = RWC(winsize, win_name, sfFullscreen, NULL);
    win.event;
    return (win);
}

void analyse_events(win_t *win, intro_t *intro, scrnstp_t **screens)
{
    if (((win->event).type == sfEvtClosed) || global.exit == 1)
        sfRenderWindow_close(win->window);
    intro_skipper(win->event, intro);
    if (*screens != NULL && global.i >= 0)
        button_checker(&((global.current_screen)->buttons), win->window,
        screens);
    return;
}

void elements_freer_destroyer(sfRenderWindow *window)
{
    sfRenderWindow_destroy(window);
    sfClock_destroy(global.game_clock);
    sfMusic_destroy(global.main_hovered);
    sfRectangleShape_destroy(global.volume_level);
    sfFont_destroy(global.font_1);
    sfText_destroy(global.text);
    return;
}

void add_screen_to_list(scrnstp_t **screens, scrnstp_t *new_screen)
{
    scrnstp_t *tmp = *screens;

    if (*screens == NULL)
        *screens = new_screen;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new_screen;
    }
    return;
}

void new_screen(scrnstp_t **screens, int id, char *txtr_path)
{
    scrnstp_t *new_screen = malloc(sizeof(scrnstp_t));
    scrnstp_t *tmp = NULL;

    new_screen->id = id;
    new_screen->back_txtr = sfTexture_createFromFile(txtr_path, NULL);
    new_screen->back_sprt = sprt_create(new_screen->back_txtr, (SFV2F){0, 0});
    new_screen->buttons = NULL;
    new_screen->next = NULL;
    add_screen_to_list(screens, new_screen);
    return;
}

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
    button_adder(&((*tmp)->buttons), &(belm_t){0, 4, "img/btns/12x7_size.png",
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
    button_adder(&((*tmp)->buttons), &(belm_t){1, 10, "img/btns/off_on.png",
        "snd/main_hov.mp3", {90, 50}, {1092, 761}, {1, 1}, {1, 1}});
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
    new_screen(screens, 42, "img/bck_grnds/sound.jpg");
    change_screen(screens, &tmp, 42);
    sound_setting(&tmp);
    new_screen(screens, 43, "img/bck_grnds/controls.jpg");
    change_screen(screens, &tmp, 43);
    controls_setting(&tmp);
    return;
}

void credits_buttons(scrnstp_t **screens)
{
    scrnstp_t *tmp = NULL;

    new_screen(screens, 50, "img/bck_grnds/credits.jpg");
    change_screen(screens, &tmp, 50);
    button_adder(&(tmp->buttons), &(belm_t){0, 1, "img/btns/back.png",
        "snd/main_hov.mp3", {58, 58}, {298, 170}, {1, 1}, {1, 1}});
    return;
}

void set_text(const char *str, sfFont *font, int size, sfColor col)
{
    sfText_setString(global.text, str);
    sfText_setFont(global.text, font);
    sfText_setColor(global.text, col);
    sfText_setCharacterSize(global.text, size);
    return;
}

void volume_sizer(SFRW window, int volume, int pre_vol, SFV2F pos)
{
    sfRectangleShape_setSize(global.volume_level,
        ratior((757 * volume) / 100, 12));
    sfRectangleShape_setPosition(global.volume_level, pos);
    sfRenderWindow_drawRectangleShape(window, global.volume_level, NULL);
    if (pre_vol != volume) {
        sprintf(global.text_cont, "%d", volume);
        set_text(global.text_cont, global.font_1,
            (50 * global.ratio.x), sfBlack);
        pre_vol = volume;
    }
    sfText_setPosition(global.text,
        (SFV2F){(1620 * global.ratio.x), (pos.y - (25 * global.ratio.x))});
    sfRenderWindow_drawText(window, global.text, NULL);
    return;
}

void buttons_new_values(btn_t **buttons, float ratio)
{
    for (btn_t *tmp = *buttons; tmp != NULL; tmp = tmp->next) {
        (tmp->button_scales[0]).x *= ratio;
        (tmp->button_scales[0]).y *= ratio;
        (tmp->button_scales[1]).x *= ratio;
        (tmp->button_scales[1]).y *= ratio;
        (tmp->position).x *= ratio;
        (tmp->position).y *= ratio;
        sfSprite_setPosition(tmp->button_sprite, tmp->position);
    }
    return;
}

void buttons_repositioner(scrnstp_t **screens, int previous_window)
{
    if ((previous_window == 2 || previous_window == 3) && global.window_i == 1) {
        for (scrnstp_t *tmp = *screens; tmp != NULL; tmp = tmp->next) {
            sfSprite_setScale(tmp->back_sprt, global.ratio);
            buttons_new_values(&(tmp->buttons), 0.5);
        }
    }
    if (previous_window == 1 && (global.window_i == 3 || global.window_i == 2)) {
        for (scrnstp_t *tmp = *screens; tmp != NULL; tmp = tmp->next) {
            sfSprite_setScale(tmp->back_sprt, global.ratio);
            buttons_new_values(&(tmp->buttons), 2);
        }
    }
    return;
}

void window_resizer(win_t *win, int *previous_window, scrnstp_t **screens)
{
    if (*previous_window != global.window_i) {
        sfRenderWindow_destroy(win->window);
        if (global.window_i == 3)
            win->window = RWC(global.window_size, "Sector42: Genesis",
                sfFullscreen, NULL);
        else
            win->window = RWC(global.window_size, "Sector42: Genesis",
                sfClose, NULL);
        sfRenderWindow_setFramerateLimit(win->window, global.fps_limit);
        buttons_repositioner(screens, *previous_window);
        *previous_window = global.window_i;
    }
    return;
}

void show_fps(sfRenderWindow *window)
{
    if (global.i >= 0 && global.show_fps == 1) {
            sprintf(global.text_cont, "FPS : %d", global.fps);
            set_text(global.text_cont, global.font_1, 20, sfWhite);
            sfText_setPosition(global.text, (SFV2F){10, 10});
            sfRenderWindow_drawText(window, global.text, NULL);
        }
    return;
}

int game_window(void)
{
    win_t win = all_for_window(global.window_size, "Sector42: Genesis");
    intro_t intro = intro_maker();
    scrnstp_t *screens = NULL;
    int previous_fps_limit = 0;
    int pre_msc = -1;
    int pre_snd = -1;
    int pre_win = global.window_i;
    int pre_ratio = global.ratio.x;

    main_menu_buttons(&screens);
    settings_buttons(&screens);
    credits_buttons(&screens);

    global.current_screen = screens;
    sfClock_restart(global.game_clock);

    //global.i = 0;


    while (sfRenderWindow_isOpen(win.window)) {
        framerate_limiter(win.window, &previous_fps_limit);
        my_framerate();
        while (sfRenderWindow_pollEvent(win.window, &(win.event)))
            analyse_events(&win, &intro, &screens);
        window_resizer(&win, &pre_win, &screens);
        sfRenderWindow_clear(win.window, sfBlack);
        introductor(win.window, &intro);
        if (global.current_screen != NULL && global.i >= 0) {
            sfRenderWindow_drawSprite(win.window, (global.current_screen)->back_sprt, NULL);
            buttons_displayer(&((global.current_screen)->buttons), win.window);
        }
        if ((global.current_screen)->id == 42) {
            volume_sizer(win.window, global.music_volume, pre_msc, ratior(760, 405));
            volume_sizer(win.window, global.sound_volume, pre_snd, ratior(760, 598));
        }
        show_fps(win.window);
        sfRenderWindow_display(win.window);
    }
    if (intro.i != -1)
        intro_elements_destroy(&intro);
    buttons_remover(&screens);
    elements_freer_destroyer(win.window);
    return (0);
}
