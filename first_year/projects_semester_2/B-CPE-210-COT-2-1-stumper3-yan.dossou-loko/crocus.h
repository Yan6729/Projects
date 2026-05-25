/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** all prototypes of funtion
*/

#ifndef CROCUS_H
    #define CROCUS_H
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #define TAIL_H
typedef struct index_s {
    int i;
    int j;
    int k;
    int lig;
}index_t;

void zero_t(int row, int col, char **tab, char c);
void un_t(int row, int col, char **tab, char c);
void deux_t(int row, int col, char **tab, char c);
void trois_t(int row, int col, char **tab, char c);
void quatre_t(int row, int col, char **tab, char c);
void cinq_t(int row, int col, char **tab, char c);
void six_t(int row, int col, char **tab, char c);
void sept_t(int row, int col, char **tab, char c);
void huit_t(int row, int col, char **tab, char c);
void neuf_t(int row, int col, char **tab, char c);
void condition(char d, char c, int row, int col, char **tab);
char **create_tab(char c, char d);
#endif
