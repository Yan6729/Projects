/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** all for intro
*/

#include "../include/wolf3d.h"

sfRectangleShape *rect_hider_create(void)
{
    sfRectangleShape *rect_hider = sfRectangleShape_create();

    sfRectangleShape_setSize(rect_hider, (SFV2F){700, 300});
    sfRectangleShape_setFillColor(rect_hider, sfBlack);
    sfRectangleShape_setPosition(rect_hider, (SFV2F){610, 636});
    return (rect_hider);
}

sfSprite *sprt_create(sfTexture *txtr, SFV2F pos)
{
    sfSprite *sprt = sfSprite_create();

    sfSprite_setTexture(sprt, txtr, sfTrue);
    sfSprite_setPosition(sprt, pos);
    return (sprt);
}

intro_t intro_maker(void)
{
    intro_t intro;

    intro.rect_hider = rect_hider_create();
    intro.epi_txtr = sfTexture_createFromFile("epitech.png", NULL);
    intro.epi_sprt = sprt_create(intro.epi_txtr, (SFV2F){655, 750});
    intro.epi_msc = sfMusic_createFromFile("epi_intro.mp3");
    intro.shayanx_txtr = sfTexture_createFromFile("shayanx.png", NULL);
    intro.shayanx_sprt = sprt_create(intro.shayanx_txtr, (SFV2F){415, 353});
    intro.shayanx_msc = sfMusic_createFromFile("shayanx_intro.mp3");
    intro.shayanx_shoot = sfMusic_createFromFile("intro_shoot.mp3");
    intro.chaos_txtr = sfTexture_createFromFile("chaos.png", NULL);
    intro.chaos_sprt = sprt_create(intro.chaos_txtr, (SFV2F){1080, 470});
    intro.loading_txtr = sfTexture_createFromFile("loading.png", NULL);
    intro.loading_sprt = sprt_create(intro.loading_txtr, (SFV2F){1832, 966});
    intro.color = (sfColor){.r = 255, .b = 255, .g = 255, .a = 0};
    intro.i = 0;
    sfSprite_setScale(intro.loading_sprt, (sfVector2f){0.1, 0.1});
    sfSprite_setOrigin(intro.loading_sprt, (SFV2F){240, 240});
    sfMusic_setVolume(intro.shayanx_msc, 30);
    sfMusic_setVolume(intro.shayanx_shoot, 30);
    sfSprite_setColor(intro.shayanx_sprt, intro.color);
    return (intro);
}

void intro_elements_destroy(intro_t *intro)
{
    sfRectangleShape_destroy(intro->rect_hider);
    sfTexture_destroy(intro->epi_txtr);
    sfSprite_destroy(intro->epi_sprt);
    sfMusic_destroy(intro->epi_msc);
    sfTexture_destroy(intro->shayanx_txtr);
    sfSprite_destroy(intro->shayanx_sprt);
    sfMusic_destroy(intro->shayanx_msc);
    sfMusic_destroy(intro->shayanx_shoot);
    sfTexture_destroy(intro->chaos_txtr);
    sfSprite_destroy(intro->chaos_sprt);
    sfTexture_destroy(intro->loading_txtr);
    sfSprite_destroy(intro->loading_sprt);
    return;
}
