/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #include <sys/stat.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <ncurses.h>
    #include <ctype.h>
    #define MY_H

void info(double *prev);
char **my_strwrldarray(char *str);
void print_id(void);
int two_window(void);
void print_up(void);
void my_get_pid(void);
int count_hole(char const *str);
int my_put_nbr(int nbr);
double *my_getloadavg(int nelem);
int convert(char ch[]);
int *time_up(void);
double *convertion(int a, int c);

#endif
