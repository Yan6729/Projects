/*
** EPITECH PROJECT, 2025
** divi
** File description:
** de
*/

#include "../include/wolf3d_2.h"

bool is_too_small(room_t r)
{
    return r.w <= 6 || r.h <= 6;
}

void handle_leaf(room_t r)
{
    if (is_too_small(r))
        return;
    if (r.w <= 6 || r.h <= 6)
        return;
    if (r.w - 6 <= 0 || r.h - 6 <= 0)
        return;
    create_room(r);
}

void divide(room_t r, int depth)
{
    int split = 0;

    if (depth == 0 || r.w <= 12 || r.h <= 12) {
        handle_leaf(r);
        return;
    }
    if (r.w > r.h) {
        if (r.w / 3 == 0)
            return;
            split = r.x + r.w / 3 + rand() % (r.w / 3);
        divide((room_t){r.x, r.y, split - r.x, r.h}, depth - 1);
        divide((room_t){split, r.y, r.x + r.w - split, r.h}, depth - 1);
    } else {
        if (r.h / 3 == 0)
            return;
            split = r.y + r.h / 3 + rand() % (r.h / 3);
        divide((room_t){r.x, r.y, r.w, split - r.y}, depth - 1);
        divide((room_t){r.x, split, r.w, r.y + r.h - split}, depth - 1);
    }
}
