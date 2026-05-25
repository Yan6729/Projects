/*
** EPITECH PROJECT, 2025
** test wolf3d
** File description:
** window
*/

#include "../include/wolf3d.h"

static int create_folders(void)
{
    if (access(".saves/", F_OK) != 0) {
        if (mkdir(".saves/", 0777) != 0)
            return (84);
    }
    if (access(".saves/games/", F_OK) != 0) {
        if (mkdir(".saves/games/", 0777) != 0)
            return (84);
    }
    if (access(".saves/settings/", F_OK) != 0) {
        if (mkdir(".saves/settings/", 0777) != 0)
            return (84);
    }
    return (0);
}

static void initialize_settings_content(set_t *settings)
{
    settings->window_size = (SFVM){1920, 1080, 32};
    settings->ratio = (SFV2F){1, 1};
    settings->window_i = 2;
    settings->fps_limit = 60;
    settings->show_fps = 0;
    settings->music_volume = 50;
    settings->sound_volume = 50;
    settings->prs_spk = 0;
    settings->l_hnd = 1;
    settings->rot_sblt = 1.0;
    return;
}

set_t load_settings(void)
{
    FILE *settings_file;
    set_t settings = {.ratio.x = -1};

    if (create_folders() == 84)
        return (settings);
    settings_file = fopen(".saves/settings/parameters.sttngs", "r");
    if (settings_file == NULL) {
        settings_file = fopen(".saves/settings/parameters.sttngs", "w+");
        initialize_settings_content(&settings);
        fclose(settings_file);
        return (settings);
    }
    fread(&settings, sizeof(set_t), 1, settings_file);
    fclose(settings_file);
    return (settings);
}

static void graphisms_select(scrnstp_t **screens, btn_t **buttons,
    set_t *settings)
{
    btn_t *btn = *buttons;

    for (; btn != NULL; btn = btn->next) {
        if (btn->button_id == 4 && settings->window_i == 1)
            btn->selected = 1;
        if (btn->button_id == 5 && settings->window_i == 2)
            btn->selected = 1;
        if (btn->button_id == 6 && settings->window_i == 3)
            btn->selected = 1;
        if (btn->button_id == 7 && settings->fps_limit == 30)
            btn->selected = 1;
        if (btn->button_id == 8 && settings->fps_limit == 60)
            btn->selected = 1;
        if (btn->button_id == 9 && settings->fps_limit == 100)
            btn->selected = 1;
        if (btn->button_id == 10 && settings->show_fps == 1)
            btn->selected = 1;
    }
    return;
}

static void audio_select(scrnstp_t **screens, btn_t **buttons, set_t *settings)
{
    btn_t *btn = *buttons;

    for (; btn != NULL; btn = btn->next) {
        if (btn->button_id == 8 && settings->prs_spk == 1)
            btn->selected = 1;
    }
    return;
}

void controls_select(scrnstp_t **screens, btn_t **buttons, set_t *settings)
{
    btn_t *btn = *buttons;

    for (btn = *buttons; btn != NULL; btn = btn->next) {
        if (btn->button_id == 4 && settings->l_hnd == 1)
            btn->selected = 1;
        if (btn->button_id == 5 && settings->l_hnd == 0)
            btn->selected = 1;
        if (btn->button_id == 6 && settings->rot_sblt == 1.0)
            btn->selected = 1;
        if (btn->button_id == 7 && settings->rot_sblt == 1.5)
            btn->selected = 1;
        if (btn->button_id == 8 && settings->rot_sblt == 2.0)
            btn->selected = 1;
    }
    return;
}

void affect_settings_to_the_game(scrnstp_t **screens, set_t *settings)
{
    scrnstp_t *tmp = NULL;
    btn_t **buttons = NULL;
    btn_t *btn = NULL;

    change_screen(screens, &tmp, 41);
    graphisms_select(screens, &(tmp->buttons), settings);
    change_screen(screens, &tmp, 42);
    audio_select(screens, &(tmp->buttons), settings);
    change_screen(screens, &tmp, 43);
    controls_select(screens, &(tmp->buttons), settings);
    global.fps_limit = settings->fps_limit;
    global.show_fps = settings->show_fps;
    global.music_volume = settings->music_volume;
    global.sound_volume = settings->sound_volume;
    global.p_spk = settings->prs_spk;
    global.l_hnd = settings->l_hnd;
    global.rot_sblt = settings->rot_sblt;
    global.ok_settings = 0;
    return;
}

void save_settings(set_t *settings)
{
    FILE *settings_file;

    if (create_folders() == 84)
        return;
    settings_file = fopen(".saves/settings/parameters.sttngs", "w");
    if (settings_file == NULL)
        settings_file = fopen(".saves/settings/parameters.sttngs", "w+");
    settings->window_size = global.window_size;
    settings->ratio = global.ratio;
    settings->window_i = (global.window_i == 3) ? 2 : global.window_i;
    settings->fps_limit = global.fps_limit;
    settings->show_fps = global.show_fps;
    settings->music_volume = global.music_volume;
    settings->sound_volume = global.sound_volume;
    settings->prs_spk = global.p_spk;
    settings->l_hnd = global.l_hnd;
    settings->rot_sblt = global.rot_sblt;
    fwrite(settings, sizeof(struct settings), 1, settings_file);
    fclose(settings_file);
    return;
}
