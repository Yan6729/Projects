/*
** EPITECH PROJECT, 2025
** value
** File description:
** room
*/
#include "../include/wolf3d_2.h"

room_t rooms[128];
int room_count;

void create_room(room_t r)
{
    int rw = 6 + rand() % (r.w - 6);
    int rh = 6 + rand() % (r.h - 6);
    int rx = r.x + rand() % (r.w - rw);
    int ry = r.y + rand() % (r.h - rh);
    room_t room;

    if (rx + rw >= MAP_WIDTH)
        rw = MAP_WIDTH - rx - 1;
    if (ry + rh >= MAP_HEIGHT)
        rh = MAP_HEIGHT - ry - 1;
    room = (room_t){rx, ry, rw, rh};
    carve_room(room);
    if (room_count < 128) {
        rooms[room_count] = room;
        room_count++;
    }
}

void connect_rooms_with_doors(void)
{
    room_t a;
    room_t b;
    int ax = 0;
    int ay = 0;
    int bx = 0;
    int by = 0;

    for (int i = 1; i < room_count; i++) {
        a = rooms[i - 1];
        b = rooms[i];
        ax = a.x + a.w / 2;
        ay = a.y + a.h / 2;
        bx = b.x + b.w / 2;
        by = b.y + b.h / 2;
        carve_corridor_with_door(ax, bx, ay, true);
        carve_corridor_with_door(ay, by, bx, false);
    }
}
