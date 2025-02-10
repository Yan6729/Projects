/*
** EPITECH PROJECT, 2024
** step02.c
** File description:
** step02.c
*/

#include "struct.h"

void cond(plane_t *tmp_2, file_t cmp)
{
    if ((tmp_2->X - tmp_2->Xi >= -15)
        && (tmp_2->X - tmp_2->Xi <= 15)) {
    } else {
        cond_1(tmp_2, cmp);
        cond_2(tmp_2, cmp);
    }
}

void si_cond(plane_t *tmp_2, file_t cmp)
{
    if (cmp.seconds > tmp_2->delay) {
        cond(tmp_2, cmp);
    }
}

void plan_draw(plane_t *temp_2, plane_t *tmp_2, file_t cmp, sfClock *clock)
{
    for (tmp_2 = temp_2; tmp_2 != NULL; tmp_2 = tmp_2->next) {
        cmp.time = sfClock_getElapsedTime(clock);
        cmp.seconds = cmp.time.microseconds / 1000000.0;
        si_cond(tmp_2, cmp);
    }
}

int game_loop(file_t cmp, int ac, char **av)
{
    tower_t *temp_1 = my_list(ac, av);
    plane_t *temp_2 = list(ac, av);
    plane_t *tmp_2;
    tower_t *tow;
    sfClock *clock = sfClock_create();

    cmp = structure();
    while (sfRenderWindow_isOpen(cmp.window)) {
        manage_events(cmp);
        sfRenderWindow_clear(cmp.window, sfBlack);
        sfRenderWindow_drawSprite(cmp.window, cmp.backg, NULL);
        tow_draw(temp_1, tow, cmp);
        plan_draw(temp_2, tmp_2, cmp, clock);
        sfRenderWindow_setFramerateLimit(cmp.window, 50);
        sfRenderWindow_display(cmp.window);
    }
    free(temp_1);
    free(temp_2);
    destroy(cmp);
}

int main(int ac, char **av)
{
    file_t cmp;

    if (ac == 1 || ac >= 3) {
        return 84;
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage(ac, av);
    } else {
        game_loop(cmp, ac, av);
    }
}
