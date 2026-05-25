/*
** EPITECH PROJECT, 2026
** string.h
** File description:
** save protorypes and structures
*/

#ifndef STRING_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #define STRING_H

typedef struct string_s {
    char *string;

    bool (*empty)(const struct string_s *);
    void (*print)(const struct string_s *);
    size_t (*length)(const struct string_s *);
    char (*at)(const struct string_s *, size_t);
    const char *(*data)(const struct string_s *);
    void (*clear)(struct string_s *);
    void (*assign)(struct string_s *, const char *);
    void (*append)(struct string_s *, const char *);

} string_t;

char *my_strcat(char *dest, char const *src);
int my_strlen(char *str, int start);
void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void print(const string_t *this);
void clear(string_t *this);
bool empty(const string_t *this);
size_t length(const string_t *this);
char the_char_at_the_position(const string_t *this, size_t pos);
const char *data(const string_t *this);
char *my_strdup(char const *src, int lim);
char *my_strndup(char const *src, int lim, int size);
void assign(string_t *this, const char *str);
void append(string_t *this, const char *str);

#endif
