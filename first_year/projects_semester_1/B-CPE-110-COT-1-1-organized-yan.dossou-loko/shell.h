/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #include <string.h>
    #include <stdio.h>
    #define SHELL_H

int error(char *str, char *src);
int error_two(char *str);
int my_strcmp(char *str1, char *str2);
int my_strcmp2(char *str1, char *str2);
int mini_printf(const char *format, ...);
int my_getnbr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
void my_putchar(char c);
int disp(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);

typedef enum type_t {
    ACTUATOR,
    DEVICE,
    SENSOR,
    PROCESSOR,
    WIRE,
} type_t;

typedef struct s_list {
    char *TYPE;
    char *NAME;
    int ID;
    struct s_list *next;
} s_list_t;

s_list_t *split(s_list_t *head);
s_list_t *mergesort_id(s_list_t *head);
s_list_t *mergesort_type(s_list_t *head);
s_list_t *mergesort_name(s_list_t *head);

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
