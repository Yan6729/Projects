/*
** EPITECH PROJECT, 2024
** my_get_pid.c
** File description:
** an other intermediate function
*/

#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <ncurses.h>

void my_get_pid(void)
{
    struct dirent *d;
    DIR *rep;
    char *str;
    int a = 0;

    rep = opendir("/proc");
    d = readdir(rep);
    while (d != NULL) {
        if (isdigit(d->d_name[0])) {
            a++;
        }
        d = readdir(rep);
    }
    printw("\nTasks: %d total,", a);
}

void print_id(void)
{
    struct dirent *d;
    DIR *rep;
    char *str;
    int a = 0;

    rep = opendir("/proc");
    d = readdir(rep);
    while (d != NULL) {
        if (isdigit(d->d_name[0])) {
            str = d->d_name;
            printw("%s", str);
        }
        d = readdir(rep);
    }
}
