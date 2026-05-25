/*
** EPITECH PROJECT, 2024
** my_gettime.c
** File description:
** just an intermediere function
*/

#include "mytop.h"
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

int *time_up(void)
{
    char *buffer = malloc(sizeof(char) * (19 + 1));
    int lire;
    int ouv;
    int *time = malloc(sizeof(int) * 4);

    ouv = open("/proc/driver/rtc", O_RDONLY);
    lire = read(ouv, buffer, 19);
    close(lire);
    time[0] = atoi(&buffer[11]);
    time[1] = atoi(&buffer[14]);
    time[2] = atoi(&buffer[17]);
    free(buffer);
    return time;
}
