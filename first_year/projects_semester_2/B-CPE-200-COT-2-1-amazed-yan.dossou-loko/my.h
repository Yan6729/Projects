/*
** EPITECH PROJECT, 2025
** boostrap
** File description:
** prototypes
*/

#ifndef MY_H
    #define MY_H

typedef struct rooms {
    char *name;
    int x;
    int y;
    int room_count;
} room_t;

typedef struct tunnel {
    int begin;
    int end;
} tunnel_t;

char **recup_tab(char *file);
tunnel_t *recup_tunnel(char *filepath, room_t *all_room);
int error_tunnel(char **tab, int i);
int read_stdin(void);
room_t *rooms(char *filepath);
int display2(char **recup, int i);
int display1(char **recup, char *filepath);
int display_error(char *filepath, char **recup);
int verif_data(char **recup, int i, int nb);
int count_tab_line(char **tab);
int is_int(char **tab, int i);
void my_putchar(char c);
void my_putstr(char *str);
int line(char **tab, int nb);
int remove_comment(char **line, int i);
int remove_comment2(char *line);
int count_l(char **str, char c);
int my_getnbr(char *str);
int clean_str(char *str);
int separt(int i, char *str);
char **tab_alloc(char *str, char car);
int count(char **env);
int my_strcmp(char const *s1, char const *s2);
char *concat_strings(char *dest, char const *src);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *str);
void my_putchar(char c);
char **my_str_to_word_array(char *str, char car);
void my_putstr(char *str);
int my_putnbr(int nb);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *src);
int count_line(char *str, char c);
int count_col(char *str);
#endif
