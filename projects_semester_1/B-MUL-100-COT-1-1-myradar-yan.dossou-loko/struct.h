/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** function that contain my structure
*/

#ifndef MY_H
   #include <SFML/Graphics.h>
   #include <sys/stat.h>
   #include <string.h>
   #include <fcntl.h>
   #include <unistd.h>
   #include <stdlib.h>
   #include <stdio.h>
   #include <stdbool.h>
   #include <math.h>
   #define MY_H

typedef struct plane {
    double Xi;
    double Yi;
    double X;
    double Y;
    double vit;
    double delay;
    int id;
    struct plane *next;
} plane_t;

typedef struct tower {
    double Xt;
    double Yt;
    double rad;
    struct tower *next;
} tower_t;

typedef struct file {
    sfClock *clock;
    sfTime time;
    sfCircleShape *circ;
    sfCircleShape *circ_2;
    sfRectangleShape *rec;
    sfVideoMode mode;
    sfUint32 sf;
    float seconds;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *plane;
    sfTexture *textp;
    sfVector2f pos_p;
    sfSprite *tower;
    sfTexture *text;
    sfVector2f pos_t;
    sfSprite *backg;
    sfTexture *textg;
    sfVector2f pos_g;
} file_t;
sfSprite *map(char const *filepath);
int manage_events(file_t cmp);
file_t structure(void);
void destroy(file_t cmp);
void tow_draw(tower_t *temp_1, tower_t *tow, file_t cmp);
void my_putchar(char c);
int my_putstr(char const *str);
int usage(int ac, char **av);
int game_loop(file_t cmp, int ac, char **av);
int draw(file_t cmp);
int *coordonnée(int a, int b, int c);
void cond_1(plane_t *tmp_2, file_t cmp);
void cond_2(plane_t *tmp_2, file_t cmp);
int aircraft_detection(plane_t *box1, plane_t *box2);
int convert(char const *ch);
sfCircleShape *circle(double a, double b, double d);
sfCircleShape *circle_2(double a, double b, double d);
plane_t *list(int ac, char **av);
tower_t *my_list(int ac, char **av);
sfSprite *my_plane(file_t cmp);
sfSprite *my_tower(file_t cmp);
void destroy_1(void);
void destroy_2(void);
int my_strlen(char *str);
int count_1(int ac, char **av);
int count_2(int ac, char **av);
int my_cmpworld(char *str);
char **my_malloc(int ac, char **av);
int draw_plane(sfRenderWindow *window, int ac, char **av);
int draw_tower(sfRenderWindow *window, int ac, char **av);
char **map_stocked(char **map, int c, int ac, char **av);
char *read_file(int ac, char **av);
int my_strcmp(char *str1, char *str2);
void rectangle(sfRenderWindow *window, sfEvent event);
sfSprite *my_target(sfRenderWindow *window, char *filepath,
    double a, double b);
sfRectangleShape **left(sfRenderWindow *window, sfEvent event);
sfRectangleShape **right(sfRenderWindow *window, sfEvent event);
sfRectangleShape **middle_r(sfRenderWindow *window, sfEvent event);
sfRectangleShape **middle_l(sfRenderWindow *window, sfEvent event);
void des_rec(sfRenderWindow *window, sfEvent event);
int disp(int ac, char **av);
sfRectangleShape *rect(int a, int b);
int menu(int ac, char **av);
sfRectangleShape *rect_1(file_t cmp, sfColor color);
void timer_init(char timer[6]);

#endif
