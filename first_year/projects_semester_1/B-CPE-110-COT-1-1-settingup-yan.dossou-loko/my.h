/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** file that contain my functions prototype
*/

#ifndef MY_H
    #define MY_H

typedef struct open_s {
    char *buff;
    int size;
}open_t;

int draw_square(int x, int y);
int my_put_nbr(int nbr);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_read(int ac, char **av);
int my_atoi(char *str);
int my_strlen(char *str);
char **generator(int ac, char **av);
char **my_open_file(int ac, char **av);
int my_cmpworld(char *str);
char **my_malloc(char *src, int ac, char **av);
#endif
