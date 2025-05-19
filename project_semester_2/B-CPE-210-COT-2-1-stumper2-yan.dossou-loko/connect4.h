/*
** EPITECH PROJECT, 2025
** dataframe.h
** File description:
** just the ".h" file of cuddle
*/

#ifndef CONNECT4_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <limits.h>
    #define CONNECT4_H
    #define LAG 7
    #define LON 6
    #define P1 'X'
    #define P2 'O'
    #define REF '#'

typedef struct data_s {
    int wight;
    int height;
    char p1;
    char p2;
    char ref;
} data_t;

char **game(char **tab, data_t);
int affiche(int lag, int log, char **tab);

#endif
