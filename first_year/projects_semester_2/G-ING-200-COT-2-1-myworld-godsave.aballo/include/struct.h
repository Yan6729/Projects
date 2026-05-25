/*
** EPITECH PROJECT, 2025
** struct.h
** File description:
** just a contain file
*/

#ifndef STRUCT_H
   #include <SFML/Graphics.h>
   #include <sys/stat.h>
   #include <string.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <math.h>
   #define STRUCT_H
   #define MAX_X 10
   #define MAX_Y 10
   #define SCALE 80

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct event_s {
    sfVector2f **pos;
    int zoom;
} event_t;

typedef struct {
    double x;
    double y;
    double z;
} vex3d_t;

int loop(sfRenderWindow *window, sfEvent event, int ac, char **av);
int menu(int ac, char **av);
int analyse_events(sfRenderWindow *window, sfEvent event, int ac, char **av);
sfSprite *create_background(char *filepath);
sfSprite *start_button(char *filepath);
void if_click(sfRenderWindow *window, sfEvent event, int ac, char **av);
void draw_2(sfRenderWindow *window, sfSprite *background_1,
    sfSprite *start);
void destroy_1(sfSprite *background_1, sfSprite *start);
int **tab(coord_t coord);
sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2);
void usage(void);
int my_put_nbr(int nbr);
void my_putchar(char c);
void my_putchar_2(char c);
void my_puts(char *str);
void my_puts_2(char *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, size_t lim);
char *my_strcpy(char *dest, char const *src);
int manage_events(sfRenderWindow *window, sfEvent event, int zoom);
sfVector2f **create_2d_map(int **tab, int zoom, coord_t coord);
sfVector2f project_iso_point(int x, int y, int z);
sfVector3f project_point(int posx, int posy);
char *my_strncpy(char *dest, char const *src, int size);
int my_strlen(char const *str);
char *my_strdup(char const *src, int lim);
char *my_strndup(char const *src, int lim, int size);

#endif
