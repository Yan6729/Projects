/*
** EPITECH PROJECT, 2025
** hdjk
** File description:
** fjdkl
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <time.h>
    #include <dirent.h>
    #define INF 2147483647
    #include <signal.h>

typedef struct {
    int index;
    int dist;
    int visited;
} item_t;

typedef struct room_s {
    char *name;
    int x;
    int y;
    int index;
    int is_start;
    int is_end;
    struct room_s **neighbors;
    int nb_neighbors;
} room_t;

#endif
