/*
** EPITECH PROJECT, 2025
** rvt
** File description:
** ff'
*/

#ifndef MY_H
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <string.h>
  #include <unistd.h>
  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>
  #define MY_H

typedef struct ingredients {
    char *name;
    int qut;
} ign_t;

void create_file(char *filename);
void disp_frigide(ign_t *frigide);
void my_putchar(char c, int fd);
void my_puts(char *str, int fd);
ign_t *make_pasta(ign_t *frigide);
ign_t *make_pizza(ign_t *frigide);
ign_t *addtofridge(ign_t *frigide, char *cmp);
void save(ign_t *list);
char *open_file(char *name);
char *format_cmd(char *cmd);
char **tab_list(char *buf, int size, char *sep);
int tab_len(char **tab);
void free_tab(char **tab);
ign_t *create_list(ign_t *list);
int good_ignr(char *ing);
ign_t *fridge(ign_t *list, char *cmd);
char **str_array(char const *str, char sep);

#endif /*MY_H*/
