/*
** EPITECH PROJECT, 2025
** bfdn
** File description:
** bfdn
*/

#ifndef PATHFINDING_H
   #include <SFML/Graphics.h>
   #include <SFML/Audio.h>
   #include <sys/stat.h>
   #include <string.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <math.h>
   #define PATHFINDING_H
#pragma once

typedef struct {
    int x, y;
} vec2i_t;

vec2i_t find_next_step(int **map, int width, int height,
                       int start_x, int start_y,
                       int target_x, int target_y);
#endif