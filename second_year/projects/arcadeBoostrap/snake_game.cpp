/*
** EPITECH PROJECT, 2026
** snd_year_projects
** File description:
** snake_game
*/

#include <iostream>
using namespace std;
#include <caca.h>

int main(int ac, char *av[])
{
    caca_display_t *disp;
    caca_canvas_t *canv;

    canv = caca_create_canvas(0, 0);
    disp = caca_create_display(canv);

    caca_put_str(canv, 10, 10, "HEllo World !");
    caca_event_t event;
    while (true) { 
        caca_get_event(disp, CACA_EVENT_KEY_PRESS, &event, -1);
        int key = caca_get_event_key_ch(&event);
        if (key == 'q' || key == EOF) {
            break;
        }
        if (key == 's') {
            caca_put_str(canv, 0, 1, "UP");
        }
        caca_refresh_display(disp);
    }
    caca_free_display(disp);
    caca_free_canvas(canv);
}
