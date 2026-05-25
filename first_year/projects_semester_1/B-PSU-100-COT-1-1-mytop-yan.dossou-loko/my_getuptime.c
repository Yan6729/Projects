/*
** EPITECH PROJECT, 2024
** my_getuptime.c
** File description:
** just an intermediere function
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/stat.h>

double my_getuptime(void)
{
    int b = 10000;
    char *buffer;
    double uptime;
    int lire;
    int fd;

    buffer = malloc(sizeof(char) * (b + 1));
    buffer[b] = '\0';
    fd = open("/proc/uptime", O_RDONLY);
    lire = read(fd, buffer, b);
    uptime = atof(&buffer[0]);
    close(fd);
    free(buffer);
    return uptime;
}

int *convert_day(void)
{
    int *time = malloc(sizeof(int) * 4);
    double uptime;
    double res;
    double res_2;

    uptime = my_getuptime();
    time[0] = uptime / 86400;
    res = (uptime / 86400) - time[0];
    time[1] = res * 24;
    res_2 = (res * 24) - time[1];
    time[2] = res_2 * 60;
    return time;
}

int print_up(void)
{
    int *time = convert_day();

    if (time[0] > 0)
        printw("%d days, %d:%d,", time[0], time[1], time[2]);
    if (time[0] == 0 && time[1] > 0)
        printw(" %d:%d,", time[1], time[2]);
    if (time[0] == 0 && time[1] == 0 && time[2] >= 0)
        printw(" %dmin,", time[2]);
    else
        return 0;
    free(time);
}
