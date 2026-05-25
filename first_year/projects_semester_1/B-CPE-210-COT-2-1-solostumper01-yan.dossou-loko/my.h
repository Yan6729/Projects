/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_T
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #define HASHTABLE_H
int my_strcmp(char *str1, char *str2);
int my_cmpword(char *str);
char **my_strwrdarray(char *str);
int my_strlen(char const *str);
char **my_malloc(char *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
void limit_breaker(void);
int convert(char *ch);

#endif /* HASHTABLE_H */
