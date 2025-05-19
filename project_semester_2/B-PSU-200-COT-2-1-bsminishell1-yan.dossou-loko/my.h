/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #include <sys/wait.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #define MY_H

int my_put_nbr(int nbr);
char **my_strwrldarray(char *str);
void step1(int ac, char **av, char **env);
void step2(int ac, char **av, char **env);
void my_putchar(char c);
void my_puts(char *str);

#endif
