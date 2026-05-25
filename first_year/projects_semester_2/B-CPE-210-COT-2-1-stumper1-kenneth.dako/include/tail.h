/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** all prototypes of funtion
*/

#ifndef TAIL_H
    #define TAIL_H

    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #define TAIL_H
typedef struct node {
    char *type;
    char *name;
    int id;
    struct node *next;
} Node_t;
typedef struct {
    Node_t *head;
    int next_id;
} List_t;

typedef struct index_s {

    int i;
    int j;
    int k;
    int lig;
}index_t;

int tail(int a, char *filepath);
int my_getnbr(char const *str);
int count_line(char *str);
char *read_file(char *filepath);
int my_status(int a);
int my_putnbr(int nb);
void my_putchar(char c);
void my_exec(char **cmd);
void array_free(char **tab);
int my_strlen(char const *str);
int my_putstr(const char *str);
char *my_strdup(char const *src, int lim);
char *my_strndup(char const *src, int lim, int size);
char *my_getenv(const char *search);
char **my_split(char *str, const char *delim);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int size);
int my_strcmp(const char *str1, const char *str2);
int my_strncmp(const char *str1, const char *str2, size_t n);

#endif
