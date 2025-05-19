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
  #include <stdarg.h>
  #define MY_H

typedef struct occur_s {
    char car;
    int occ;
    struct occur_s *next;
} occur_t;

occur_t *split(occur_t *data);
occur_t *merge_2(occur_t *first, occur_t *second);
occur_t *mergesort_id(occur_t **head);
int sort(occur_t **list);
int verif_car(occur_t *data, char car);
int print(char *std, const char *format, ...);
int add(occur_t **data, int occ, char c);
int add_in(occur_t **data, int occ, char c);
void print_list(occur_t **data);
void print_r(occur_t **data);
void create_file(char *filename);
void my_putchar(char c, int fd);
void my_puts(char *str, int fd);
char *open_file(char *name);
char *format_cmd(char *cmd);
char **tab_list(char *buf, int size, char *sep);
int tab_len(char **tab);
void free_tab(char **tab);
int good_ignr(char *ing);
char **str_array(char const *str, char sep);

#endif /*MY_H*/
