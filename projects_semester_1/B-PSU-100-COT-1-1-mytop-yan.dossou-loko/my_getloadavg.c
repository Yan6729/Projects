/*
** EPITECH PROJECT, 2024
** my_getloadavg.c
** File description:
** just a intermediere function
*/
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include "mytop.h"

double *my_getloadavg(int nelem)
{
    double *loadavg = malloc(sizeof(double) * 4);
    int b = 0;
    char buffer[16];
    char stand[6];
    int lire;
    int ouv;

    ouv = open("/proc/loadavg", O_RDONLY);
    lire = read(ouv, buffer, 15);
    buffer[16] = '\0';
    for (nelem = 0; nelem < 3; nelem++) {
        strcpy(stand, buffer);
        loadavg[b] = atof(stand);
        b++;
    }
    close(ouv);
    return loadavg;
}
